#!/usr/bin/env python3
"""Cherry-pick explicit commits, resolving only disjoint ARM9 delink blocks.

Stops on uncertainty and leaves Git's in-progress state for inspection. This
integrates commits; it does not run or replace ROM acceptance checks.
"""
import argparse
from dataclasses import dataclass
from datetime import datetime, timezone
import json
from pathlib import Path
import posixpath
import re
import subprocess
import sys
import time
import uuid


ROOT = Path(__file__).resolve().parents[1]
DELINKS = "config/usa/arm9/delinks.txt"
IDENTITY = ["-c", "user.name=Codex", "-c", "user.email=codex@openai.com",
            "-c", "core.editor=true"]
RANGE = re.compile(r"^\s*(\.[\w.]+)\s+start:(0x[0-9a-fA-F]+)\s+end:(0x[0-9a-fA-F]+)(?:\s+.*)?$")


class IntegrationError(ValueError):
    pass


@dataclass
class Delinks:
    header: str
    blocks: dict


def parse_delinks(text):
    """Keep complete source blocks, including comments and metadata, as units."""
    header, blocks, current, lines = [], {}, None, []
    filenames = set()
    for line in text.splitlines():
        if line.startswith(("<<<<<<<", "=======", ">>>>>>>", "|||||||")):
            raise IntegrationError("conflict markers in delinks input")
        stripped = line.strip()
        comment = stripped.startswith(("//", "#"))
        if stripped and not line[0].isspace() and not comment:
            if not line.rstrip().endswith(":"):
                raise IntegrationError(f"invalid delinks source header: {line!r}")
            if current is not None:
                blocks[current] = "\n".join(lines).rstrip()
            current = line.rstrip()[:-1]
            canonical = posixpath.normpath(current.replace("\\", "/")).casefold()
            if canonical in filenames:
                raise IntegrationError(f"duplicate source block: {current}")
            filenames.add(canonical)
            lines = [line]
        elif current is None:
            header.append(line)
        else:
            lines.append(line)
    if current is not None:
        blocks[current] = "\n".join(lines).rstrip()
    result = Delinks("\n".join(header).rstrip(), blocks)
    validate_ranges(result)
    return result


def validate_ranges(document):
    sections = {}
    for line in document.header.splitlines():
        if not line.strip() or line.strip().startswith(("//", "#")):
            continue
        match = RANGE.fullmatch(line)
        if not match:
            raise IntegrationError(f"invalid top section definition: {line!r}")
        name, start, end = match.groups()
        if name in sections:
            raise IntegrationError(f"duplicate top section: {name}")
        start, end = int(start, 16), int(end, 16)
        if start >= end:
            raise IntegrationError(f"empty or reversed top section: {name}")
        sections[name] = (start, end)
    if not sections:
        raise IntegrationError("delinks has no top section definitions")
    allocated = []
    for filename, block in document.blocks.items():
        for line in block.splitlines()[1:]:
            stripped = line.strip()
            if not stripped or stripped.startswith(("//", "#")):
                continue
            # Retain metadata without interpreting it, but never overlook a range.
            if not stripped.startswith(".") and "start:" not in stripped and "end:" not in stripped:
                continue
            match = RANGE.fullmatch(line)
            if not match:
                raise IntegrationError(f"invalid range in {filename}: {line!r}")
            section, start, end = match.groups()
            start, end = int(start, 16), int(end, 16)
            bounds = sections.get(section)
            if not bounds or not bounds[0] <= start < end <= bounds[1]:
                raise IntegrationError(f"range outside top section in {filename}: {line.strip()}")
            allocated.append((start, end, filename, section))
    allocated.sort()
    for previous, current in zip(allocated, allocated[1:]):
        if current[0] < previous[1]:
            raise IntegrationError(f"range collision: {previous[2]} {previous[3]} and "
                                   f"{current[2]} {current[3]}")


def merge_delinks(base_text, ours_text, theirs_text):
    base, ours, theirs = map(parse_delinks, (base_text, ours_text, theirs_text))
    if not base.header == ours.header == theirs.header:
        raise IntegrationError("top section definitions changed; manual resolution required")
    merged = {}
    # Keep the current ordering; append incoming-only blocks in their source order.
    for name in dict.fromkeys([*ours.blocks, *theirs.blocks, *base.blocks]):
        before, left, right = (document.blocks.get(name) for document in (base, ours, theirs))
        if before is not None and (left is None or right is None):
            raise IntegrationError(f"deleted source block requires manual resolution: {name}")
        if left == right:
            merged[name] = left
        elif left == before:
            merged[name] = right
        elif right == before:
            merged[name] = left
        else:
            raise IntegrationError(f"divergent source block: {name}")
    document = Delinks(ours.header, merged)
    validate_ranges(document)
    return document.header + "\n\n" + "\n\n".join(merged.values()) + "\n"


class Git:
    def __init__(self, root):
        self.root = root
        self.log_dir = None
        self.number = 0

    def run(self, *args, check=True):
        command = ["git", *IDENTITY, *args]
        start = time.monotonic()
        result = subprocess.run(command, cwd=self.root, capture_output=True, check=False)
        if self.log_dir is not None:
            self.number += 1
            prefix = f"{self.number:03d}"
            (self.log_dir / f"{prefix}.stdout.log").write_bytes(result.stdout)
            (self.log_dir / f"{prefix}.stderr.log").write_bytes(result.stderr)
            with (self.log_dir / "commands.jsonl").open("a", encoding="utf-8") as stream:
                stream.write(json.dumps({"command": command, "returncode": result.returncode,
                                         "elapsed_seconds": round(time.monotonic() - start, 6),
                                         "output_prefix": prefix}) + "\n")
        if check and result.returncode:
            error = result.stderr.decode("utf-8", errors="replace").strip()
            raise IntegrationError(f"git {args[0]} failed ({result.returncode}): {error[:300]}")
        return result

    def output(self, *args):
        return self.run(*args).stdout.decode("utf-8").strip()


def require_clean(git):
    if git.output("status", "--porcelain", "--untracked-files=no"):
        raise IntegrationError("tracked worktree/index must be clean before integration")
    for marker in ("CHERRY_PICK_HEAD", "MERGE_HEAD", "REVERT_HEAD", "rebase-merge", "rebase-apply", "sequencer"):
        path = Path(git.output("rev-parse", "--git-path", marker))
        if not path.is_absolute():
            path = git.root / path
        if path.exists():
            raise IntegrationError(f"existing Git operation: {marker}")


def resolve_only_delinks(git):
    unmerged = git.run("ls-files", "--unmerged", "-z").stdout
    entries = []
    for entry in unmerged.split(b"\0"):
        if entry:
            metadata, path = entry.split(b"\t", 1)
            mode, _, stage = metadata.decode("ascii").split()
            entries.append((path.decode("utf-8"), mode, int(stage)))
    if {entry[0] for entry in entries} != {DELINKS}:
        names = ", ".join(sorted({entry[0] for entry in entries})) or "no unmerged files"
        raise IntegrationError(f"cherry-pick stopped; manual resolution required ({names})")
    if {(mode, stage) for _, mode, stage in entries} != {
            ("100644", 1), ("100644", 2), ("100644", 3)}:
        raise IntegrationError("delinks needs three regular-file stages; manual resolution required")
    stages = []
    for stage in (1, 2, 3):
        content = git.run("show", f":{stage}:{DELINKS}").stdout
        (git.log_dir / f"stage-{git.number}-{stage}.txt").write_bytes(content)
        stages.append(content.decode("utf-8"))
    merged = merge_delinks(*stages)
    output = git.root / DELINKS
    if output.is_symlink() or not output.resolve().is_relative_to(git.root):
        raise IntegrationError("delinks output must be a regular path inside the repository")
    (git.log_dir / f"conflicted-{git.number}.txt").write_bytes(output.read_bytes())
    output.write_text(merged, encoding="utf-8", newline="\n")
    git.run("add", "--", DELINKS)
    git.run("cherry-pick", "--continue")


def integrate(root, commits):
    if not commits or any(not re.fullmatch(r"[0-9a-fA-F]{7,40}", commit) for commit in commits):
        raise IntegrationError("provide explicit 7-to-40-character commit hashes only")
    git = Git(root.resolve())
    git.root = Path(git.output("rev-parse", "--show-toplevel")).resolve()
    require_clean(git)
    parse_delinks((git.root / DELINKS).read_text(encoding="utf-8"))
    hashes = []
    for commit in commits:
        full = git.output("rev-parse", "--verify", f"{commit}^{{commit}}")
        if not full.lower().startswith(commit.lower()):
            raise IntegrationError(f"hash does not name a commit directly: {commit}")
        if len(git.output("show", "-s", "--format=%P", full).split()) > 1:
            raise IntegrationError(f"merge commit needs manual mainline selection: {commit}")
        if full in hashes:
            raise IntegrationError(f"duplicate requested commit: {commit}")
        hashes.append(full)
    logs = (git.root / "build/integration").resolve()
    if not logs.is_relative_to(git.root):
        raise IntegrationError("integration logs must stay inside the repository")
    if git.run("check-ignore", "-q", "--", "build/integration/probe", check=False).returncode:
        raise IntegrationError("build/integration must be ignored before integration")
    git.log_dir = logs / (datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%S") + "-" + uuid.uuid4().hex)
    git.log_dir.mkdir(parents=True)
    record = {"requested": hashes, "before": git.output("rev-parse", "HEAD"), "applied": [],
              "status": "running", "rom_acceptance": False}
    started = time.monotonic()
    try:
        for commit in hashes:
            require_clean(git)
            result = git.run("cherry-pick", commit, check=False)
            if result.returncode:
                resolve_only_delinks(git)
            record["applied"].append({"source": commit, "result": git.output("rev-parse", "HEAD")})
            # A clean textual pick can also introduce duplicate ownership.
            parse_delinks((git.root / DELINKS).read_text(encoding="utf-8"))
        require_clean(git)
        record["status"] = "integrated"
    except (IntegrationError, OSError, UnicodeError) as error:
        record.update(status="stopped", error=str(error))
        raise IntegrationError(f"{error}\nGit state retained. Logs: {git.log_dir}") from error
    finally:
        record["elapsed_seconds"] = round(time.monotonic() - started, 6)
        (git.log_dir / "result.json").write_text(json.dumps(record, indent=2) + "\n", encoding="utf-8")
    return record, git.log_dir


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("commits", nargs="+", help="explicit commit hashes, in integration order")
    parser.add_argument("--repo", type=Path, default=ROOT, help="repository (default: this workspace)")
    args = parser.parse_args(argv)
    try:
        record, logs = integrate(args.repo, args.commits)
    except (IntegrationError, OSError, UnicodeError) as error:
        print(f"integrate_batch: {error}", file=sys.stderr)
        return 2
    print(f"Integrated {len(record['applied'])} commit(s). Acceptance checks still required.")
    print(f"Logs: {logs}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
