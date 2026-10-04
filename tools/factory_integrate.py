#!/usr/bin/env python3
"""Advance main only after reviewed immutable commits pass independent stage acceptance."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
from rom_inputs import input_rom, compiler_root, validate as validate_inputs
import re
import shutil
import socket
import subprocess
import sys
import time
import uuid

import work_batch

USA_SHA1 = "c7c3014c237900c8281289b8bc76a781969b6278"
HASH = re.compile(r"[0-9a-f]{40}")
IDENTITY = ["-c", "user.name=Codex", "-c", "user.email=codex@openai.com", "-c", "core.hooksPath=", "-c", "core.editor=true"]


class InfrastructureError(ValueError):
    """Operator/pipeline state failure; candidate source repair is not warranted."""


class CandidateConflict(ValueError):
    """Explicit cherry-pick left unmerged source paths for repair."""


def utc():
    return datetime.now(timezone.utc).isoformat()


def digest(path, algorithm="sha256"):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, algorithm).hexdigest()


class IntegrationLock:
    def __init__(self, root):
        key = (os.path.normcase(str(Path(root).resolve())) + ":factory-integration").encode()
        self.port = 20000 + int.from_bytes(hashlib.sha256(key).digest()[:4], "big") % 10000
        self.socket = None

    def __enter__(self):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        if os.name == "nt":
            self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
        try:
            self.socket.bind(("127.0.0.1", self.port))
            self.socket.listen(1)
        except OSError:
            self.socket.close()
            raise ValueError("integration lock unavailable; another integration or socket collision") from None
        return self

    def __exit__(self, *args):
        self.socket.close()


class Runner:
    def __init__(self, directory):
        self.directory = directory
        self.number = 0
        self.commands = []

    def run(self, command, cwd, check=True, env=None):
        self.number += 1
        prefix = self.directory / f"{self.number:04d}"
        started = time.monotonic()
        with prefix.with_suffix(".stdout.log").open("wb") as out, prefix.with_suffix(".stderr.log").open("wb") as err:
            try:
                result = subprocess.run(command, cwd=cwd, stdout=out, stderr=err, stdin=subprocess.DEVNULL,
                                        shell=False, env=env, check=False)
            except OSError as error:
                raise InfrastructureError(f"cannot launch local build/Git tool: {error}") from error
        self.commands.append({"argv": command, "cwd": str(cwd), "exit_code": result.returncode,
                              "elapsed_seconds": round(time.monotonic() - started, 6), "log_prefix": str(prefix)})
        if check and result.returncode:
            raise ValueError(f"command exited {result.returncode}; see {prefix}")
        return result.returncode, prefix.with_suffix(".stdout.log").read_bytes()

    def git(self, root, *args, check=True):
        return self.run(["git", *IDENTITY, *args], root, check=check)

    def output(self, root, *args):
        return self.git(root, *args)[1].decode("utf-8").strip()


def require_clean(runner, root):
    if runner.output(root, "status", "--porcelain", "--untracked-files=all"):
        raise ValueError("main/stage worktree and index must be clean, including untracked files")
    for marker in ("CHERRY_PICK_HEAD", "MERGE_HEAD", "REVERT_HEAD", "rebase-merge", "rebase-apply", "sequencer"):
        path = Path(runner.output(root, "rev-parse", "--git-path", marker))
        if not path.is_absolute():
            path = root / path
        if path.exists():
            raise ValueError(f"existing Git operation: {marker}")


def allowed_path(path, module):
    value = PurePosixPath(path)
    if value.is_absolute() or ".." in value.parts or "\\" in path:
        return False
    if value.parts and value.parts[0] in ("src", "include"):
        return value.suffix.lower() in (".c", ".cp", ".cpp", ".cxx", ".h", ".hpp", ".hxx")
    if path.startswith(f"config/usa/arm9/overlays/{module}/"):
        return path in {f"config/usa/arm9/overlays/{module}/{name}" for name in
                        ("delinks.txt", "symbols.txt", "linker_symbols.json")}
    if module in ('arm9/main','arm9/itcm','arm9/dtcm') or module.startswith('arm9/ov'):
        from factory_tasks import module_config
        folder=module_config(module)
        if path in {folder+'/'+name for name in ('delinks.txt','symbols.txt','linker_symbols.json')}:
            return True
    if path.startswith("docs/workflow/"):
        return path.casefold() != "docs/workflow/queue.json" and value.suffix.lower() in (".md", ".json", ".txt", ".csv")
    return False


def validate_submission(runner, root, submission, review):
    if not isinstance(submission, dict) or not isinstance(review, dict):
        raise ValueError("submission and review must be objects")
    for key in ("id", "lane"):
        if not isinstance(submission.get(key), str) or not submission[key]:
            raise ValueError(f"submission needs {key}")
    module = submission.get("module")
    if submission.get('function_id'):
        from factory_tasks import module_config
        module_config(module)
        f=submission.get('function',{})
        if f.get('id')!=submission['function_id'] or f.get('module_id')!=module:
            raise ValueError('Function submission must bind assigned function/module')
        from contextlib import closing
        from factory import connect
        with closing(connect(root)) as db:
            row=db.execute('SELECT id,owner,status,payload FROM function_tasks WHERE job_id=?',(submission.get('job_id'),)).fetchone()
        if not row or row['id']!=submission['function_id'] or row['owner']!=submission['lane'] or row['status']!='review':
            raise ValueError('Function submission has no matching review claim in the integrator queue')
        original=json.loads(row['payload'])
        for key in ('id','module_id','name','address','size','mode','original_sha256'):
            if f.get(key)!=original.get(key):raise ValueError('Assigned function metadata changed: '+key)
    elif not isinstance(module, str) or not re.fullmatch(r"ov\d{3}", module) or int(module[2:]) > 34:
        raise ValueError("submission needs an assigned USA overlay module ov000..ov034")
    for key in ("base_revision", "source_tip"):
        value = submission.get(key)
        if not isinstance(value, str) or not HASH.fullmatch(value):
            raise ValueError(f"submission {key} needs a full lowercase commit hash")
        if runner.output(root, "rev-parse", "--verify", value + "^{commit}") != value:
            raise ValueError(f"submission {key} is not an immutable local commit")
    if (review.get("verdict") != "approved" or review.get("findings") != [] or
            review.get("source_tip") != submission["source_tip"] or review.get("base_revision") != submission["base_revision"]):
        raise ValueError("review must approve this exact base/tip with no findings")
    commits = submission.get("commits")
    if not isinstance(commits, list) or not commits or len(commits) != len(set(commits)) or any(
            not isinstance(commit, str) or not HASH.fullmatch(commit) for commit in commits):
        raise ValueError("commits must be a unique nonempty list of full immutable hashes")
    if commits[-1] != submission["source_tip"]:
        raise ValueError("source_tip must be the last explicit commit")
    parent = submission["base_revision"]
    changed_paths = set()
    for commit in commits:
        ancestry = runner.output(root, "rev-list", "--parents", "-n", "1", commit).split()
        if ancestry != [commit, parent]:
            raise ValueError("explicit commits must form an exact linear chain from reviewed base to tip")
        paths = runner.git(root, "diff", "--name-only", "--no-renames", "-z", parent, commit)[1].split(b"\0")
        for raw in paths:
            if not raw:
                continue
            path = raw.decode("utf-8")
            if not allowed_path(path, module):
                raise ValueError(f"disallowed integration path: {path}")
            # Check both sides, including deletions: only normal text blobs are permitted.
            for revision in (parent, commit):
                entry = runner.output(root, "ls-tree", revision, "--", path)
                if not entry:
                    continue
                metadata = entry.split("\t", 1)[0].split()
                if metadata[0] not in ("100644", "100755") or metadata[1] != "blob":
                    raise ValueError(f"non-regular file/submodule rejected: {path}")
                blob = runner.git(root, "cat-file", "blob", metadata[2])[1]
                if b"\0" in blob:
                    raise ValueError(f"binary blob rejected: {path}")
                blob.decode("utf-8")
            changed_paths.add(path)
        parent = commit
    return sorted(changed_paths)


def tools_state(root):
    suffix = ".exe" if os.name == "nt" else ""
    python = root / (".venv/Scripts/python.exe" if os.name == "nt" else ".venv/bin/python")
    ninja = root / (".venv/Scripts/ninja.exe" if os.name == "nt" else ".venv/bin/ninja")
    compiler = compiler_root(root)
    files = {"python": python, "ninja": ninja, "dsd" + suffix: root / ("dsd" + suffix),
             "objdiff-cli" + suffix: root / ("objdiff-cli" + suffix)}
    for path in sorted((compiler / "2.0/sp2p2").rglob("*")):
        if path.is_file():
            files['tools/mwccarm/' + path.relative_to(compiler).as_posix()] = path
    for name in ("mwccarm.exe", "mwldarm.exe"):
        if not (compiler / "2.0/sp2p2" / name).is_file():
            raise ValueError(f"pinned matching compiler missing: {name}")
    if os.name != "nt":
        files["wibo"] = root / "wibo"
    if any(not path.is_file() for path in files.values()):
        raise ValueError("pinned local build tool missing; no tools will be downloaded")
    return {"python": str(python), "ninja": str(ninja), "compiler": str(compiler),
            "hashes": {name: digest(path) for name, path in files.items()}}


def resolve_function_delinks(runner,stage,module):
    """Merge only disjoint source blocks in the assigned module's delink map."""
    from factory_tasks import module_config
    from integrate_batch import merge_delinks
    path=module_config(module)+'/delinks.txt'
    entries=[]
    for entry in runner.git(stage,'ls-files','--unmerged','-z')[1].split(b'\0'):
        if entry:
            metadata,name=entry.split(b'\t',1)
            mode,_,number=metadata.decode().split()
            entries.append((name.decode(),mode,int(number)))
    if set(entries)!={(path,'100644',i) for i in (1,2,3)}:
        raise CandidateConflict('Only regular three-stage assigned delink conflicts can be merged automatically')
    try:
        texts=[runner.git(stage,'show',f':{i}:{path}')[1].decode('utf-8') for i in (1,2,3)]
        merged=merge_delinks(*texts)
    except Exception as error:raise CandidateConflict('Delink ranges conflict: '+str(error)) from error
    output=stage/path
    if output.is_symlink() or not output.resolve().is_relative_to(stage):
        raise CandidateConflict('Delink output must remain inside stage')
    output.write_text(merged,encoding='utf-8',newline='\n')
    runner.git(stage,'add','--',path);runner.git(stage,'cherry-pick','--continue')


def validate_function_snapshot(root,path,submission):
    from contextlib import closing
    import sqlite3
    def verified(database):
        with closing(sqlite3.connect(Path(database).resolve().as_uri()+'?mode=ro',uri=True)) as db:
            return {row[0] for row in db.execute("SELECT id FROM functions WHERE completion_status='completed' AND decompiled_c IS NOT NULL AND decompiled_c<>''")}
    before=verified(root/'build/call-graph/functions.sqlite')
    after=verified(path)
    if before-after or after-before!={submission['function_id']}:
        raise CandidateConflict('Accepted C coverage must add only the assigned function, without losing other verified source')


def prepare_stage(root, stage):
    state = tools_state(root)
    from rom_inputs import input_rom, provision, compiler_root
    original = input_rom(root)
    if digest(original, "sha1") != USA_SHA1:
        raise ValueError("original ROM input SHA1 does not match USA acceptance")
    provision(root, stage)
    state['compiler'] = str(compiler_root(stage)) if (stage / 'build/factory/inputs.json').exists() else state['compiler']
    suffix = ".exe" if os.name == "nt" else ""
    for name in ("dsd" + suffix, "objdiff-cli" + suffix):
        shutil.copy2(root / name, stage / name)
        if digest(stage / name) != state["hashes"][name]:
            raise ValueError("copied build tool hash changed")
    if os.name != "nt":
        shutil.copy2(root / "wibo", stage / "wibo")
    return state


def build_stage(runner, stage, tools, label):
    env = os.environ.copy()
    env["PYTHONDONTWRITEBYTECODE"] = "1"
    suffix = ".exe" if os.name == "nt" else ""
    # Relative CLI path avoids unquoted paths with spaces in existing extraction rules.
    runner.run([tools["python"], "tools/configure.py", "usa", "--compiler", tools["compiler"],
                "--dsd", "tools/../dsd" + suffix], stage, env=env)
    try:
        from factory_review import pin_preinstalled_objdiff
        pin_preinstalled_objdiff(stage, tools["hashes"]["objdiff-cli" + suffix])
    except Exception as error:
        raise InfrastructureError(f"pinned objdiff setup failed: {error}") from error
    runner.run([tools["ninja"], "-j", "2", "rom", "check", "report", "sha1"], stage, env=env)
    try:
        snapshot = work_batch.capture(stage)
    except Exception as error:
        raise InfrastructureError(f"{label} acceptance snapshot unavailable: {error}") from error
    if snapshot["dirty"]:
        raise InfrastructureError(f"{label} stage changed during acceptance; snapshot must be clean")
    if snapshot["rom_sha1"] != USA_SHA1:
        raise ValueError(f"{label} ROM SHA1 does not match exact USA acceptance")
    return snapshot


def integrate(root, submission, review, workspace):
    root, workspace = Path(root).resolve(), Path(workspace).resolve()
    started = time.monotonic()
    result = {"schema_version": 1, "status": "infrastructure_blocked", "accepted": False, "started_utc": utc(),
              "submission": submission, "review": review, "runtime_tests": "not_run"}
    directory = root / "build/factory/integrations" / uuid.uuid4().hex
    directory.mkdir(parents=True, exist_ok=False)
    runner = Runner(directory)
    result["manifest_path"] = str(directory / "manifest.json")
    phase = "preflight"
    try:
        with IntegrationLock(root):
            require_clean(runner, root)
            result["main_before"] = runner.output(root, "rev-parse", "HEAD")
            phase = "submission"
            result["changed_paths"] = validate_submission(runner, root, submission, review)
            phase = "stage_setup"
            workspace.mkdir(parents=True, exist_ok=True)
            stage = workspace / ("integration-" + uuid.uuid4().hex)
            result["stage"] = str(stage)
            runner.git(root, "worktree", "add", "--detach", str(stage), result["main_before"])
            tools = prepare_stage(root, stage)
            result["tools"] = tools["hashes"]
            result["input_rom_sha1"] = USA_SHA1
            phase = "baseline"
            result["baseline"] = build_stage(runner, stage, tools, "baseline")
            if result["baseline"]["revision"] != result["main_before"]:
                raise ValueError("baseline snapshot revision changed")
            phase = "apply_commits"
            for commit in submission["commits"]:
                try:
                    runner.git(stage, "cherry-pick", "--", commit)
                except Exception as error:
                    if runner.git(stage, "ls-files", "--unmerged", "-z")[1]:
                        if submission.get('function_id'):
                            resolve_function_delinks(runner,stage,submission['module'])
                            continue
                        raise CandidateConflict(f"cherry-pick source conflict: {error}") from error
                    raise InfrastructureError(f"cherry-pick failed without source conflicts: {error}") from error
            result["stage_revision"] = runner.output(stage, "rev-parse", "HEAD")
            phase = "candidate"
            result["candidate"] = build_stage(runner, stage, tools, "candidate")
            if result["candidate"]["revision"] != result["stage_revision"]:
                raise InfrastructureError("candidate snapshot does not describe verified stage HEAD")
            phase = "coverage"
            result["delta"] = work_batch.delta(result["baseline"], result["candidate"])
            if submission.get('function_id'):
                from factory_tasks import refresh_snapshot
                phase='function_acceptance'
                if (result['delta']['arm9']['matched_functions']!=1 or
                    result['delta']['arm9']['matched_code']!=submission['function']['size']):
                    raise CandidateConflict('Single-function submission changed coverage outside its exact extent')
                snapshot=refresh_snapshot(stage,runner)
                validate_function_snapshot(root,snapshot,submission)
                result['staged_function_snapshot']=str(snapshot)
            phase = "final_integrity"
            if tools_state(root)["hashes"] != tools["hashes"]:
                raise ValueError("shared tool hashes changed during acceptance")
            if digest(input_rom(root), "sha1") != USA_SHA1:
                raise ValueError("original input changed during acceptance")
            stage_input, stage_output = input_rom(stage), stage / "dqix_usa.nds"
            if (digest(stage_input, "sha1") != USA_SHA1 or stage_input.stat().st_nlink != 1 or
                    stage_output.stat().st_nlink != 1 or stage_input.samefile(stage_output)):
                raise ValueError("stage input/output must remain independent files with verified original input")
            suffix = ".exe" if os.name == "nt" else ""
            for name in ("dsd" + suffix, "objdiff-cli" + suffix):
                if digest(stage / name) != tools["hashes"][name]:
                    raise ValueError("stage tool hash changed during acceptance")
            require_clean(runner, stage)
            require_clean(runner, root)
            if runner.output(root, "rev-parse", "HEAD") != result["main_before"]:
                raise ValueError("main HEAD changed during staging; do not advance stale acceptance")
            if runner.output(stage, "rev-parse", "HEAD") != result["stage_revision"]:
                raise ValueError("stage HEAD changed after acceptance")
            phase = "advance"
            runner.git(root, "merge", "--ff-only", "--no-edit", result["stage_revision"])
            result["main_after"] = runner.output(root, "rev-parse", "HEAD")
            if result["main_after"] != result["stage_revision"]:
                raise ValueError("main advancement did not reach verified stage revision")
            require_clean(runner, root)
            result.update(status="accepted", accepted=True,
                          before=result["baseline"], snapshot=result["candidate"],
                          accepted_revision=result["stage_revision"], main_revision=result["main_after"],
                          acceptance="independent full ROM/module/symbol/report/SHA1 checks; strict coverage delta; reviewed source tip")
            if submission.get('function_id'):
                folder=root/'build/call-graph';folder.mkdir(parents=True,exist_ok=True)
                for name in ('functions.sqlite','graph.json','index.html','decompilation-order.csv'):
                    original=stage/'build/call-graph'/name
                    temporary=folder/(name+'.'+uuid.uuid4().hex+'.tmp')
                    shutil.copy2(original,temporary);os.replace(temporary,folder/name)
                result['function_snapshot']=str(folder/'functions.sqlite')
    except Exception as error:
        result["error"] = str(error)
        if isinstance(error, InfrastructureError):
            result["status"] = "infrastructure_blocked"
        elif isinstance(error, CandidateConflict) or (phase in ("candidate", "coverage") and isinstance(error, ValueError)):
            result["status"] = "needs_changes"
        elif phase == "submission":
            result["status"] = "rejected"
        else:
            result["status"] = "infrastructure_blocked"
    finally:
        result["phase"] = phase
        result["finished_utc"] = utc()
        result["elapsed_seconds"] = round(time.monotonic() - started, 6)
        result["commands"] = runner.commands
        # Write once. Existing accepted evidence is never amended or replaced.
        with (directory / "manifest.json").open("x", encoding="utf-8") as stream:
            json.dump(result, stream, indent=2)
            stream.write("\n")
    return result


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", required=True, type=Path)
    parser.add_argument("--submission", required=True, type=Path)
    parser.add_argument("--review", required=True, type=Path)
    parser.add_argument("--workspace", required=True, type=Path)
    args = parser.parse_args(argv)
    result = integrate(args.root, json.loads(args.submission.read_text(encoding="utf-8-sig")),
                       json.loads(args.review.read_text(encoding="utf-8-sig")), args.workspace)
    print(json.dumps({key: result.get(key) for key in ("status", "accepted", "stage_revision", "manifest_path", "error")}))
    return 0 if result["accepted"] else 2


if __name__ == "__main__":
    sys.exit(main())
