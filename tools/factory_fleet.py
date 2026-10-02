#!/usr/bin/env python3
"""Supervise independent native Codex jobs; completed work always needs review."""
import argparse
from collections import Counter
from datetime import datetime, timezone
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import signal
import socket
import subprocess
import sys
import time
import uuid

HEARTBEAT_SECONDS = 10
ERROR_LIMIT = 64 * 1024


def utc():
    return datetime.now(timezone.utc).isoformat()


def atomic_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_name(path.name + "." + uuid.uuid4().hex + ".tmp")
    try:
        temporary.write_text(json.dumps(value, indent=2) + "\n", encoding="utf-8")
        os.replace(temporary, path)
    finally:
        temporary.unlink(missing_ok=True)


class FleetLock:
    """An OS-owned loopback socket releases on exit without stale PID lock files."""
    def __init__(self, root):
        identity = os.path.normcase(str(Path(root).resolve())).encode("utf-8")
        self.port = 32000 + int.from_bytes(hashlib.sha256(identity).digest()[:4], "big") % 20000
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
            self.socket = None
            raise ValueError(f"fleet supervisor lock unavailable on loopback port {self.port}; another supervisor or port collision") from None
        return self

    def __exit__(self, *args):
        if self.socket:
            self.socket.close()
            self.socket = None


def pid_alive(pid):
    if not isinstance(pid, int) or pid <= 0:
        return False
    if os.name == "nt":
        import ctypes
        from ctypes import wintypes
        kernel = ctypes.WinDLL("kernel32", use_last_error=True)
        kernel.OpenProcess.argtypes = (wintypes.DWORD, wintypes.BOOL, wintypes.DWORD)
        kernel.OpenProcess.restype = wintypes.HANDLE
        kernel.GetExitCodeProcess.argtypes = (wintypes.HANDLE, ctypes.POINTER(wintypes.DWORD))
        kernel.CloseHandle.argtypes = (wintypes.HANDLE,)
        handle = kernel.OpenProcess(0x1000, False, pid)
        if not handle:
            return ctypes.get_last_error() == 5  # Access denied: conservatively assume live.
        try:
            code = wintypes.DWORD()
            return not kernel.GetExitCodeProcess(handle, ctypes.byref(code)) or code.value == 259
        finally:
            kernel.CloseHandle(handle)
    try:
        os.kill(pid, 0)
        return True
    except ProcessLookupError:
        return False
    except PermissionError:
        return True


def read_tail(path):
    if not path.is_file():
        return ""
    with path.open("rb") as stream:
        stream.seek(max(0, path.stat().st_size - ERROR_LIMIT))
        return stream.read(ERROR_LIMIT).decode("utf-8", errors="replace")


def blocking_error(stdout, stderr, exit_code):
    """Inspect backend error events, never ordinary assistant text for failure words."""
    errors = []
    for line in stdout.splitlines():
        try:
            event = json.loads(line)
        except ValueError:
            continue
        if isinstance(event, dict) and event.get("type") in ("error", "turn.failed"):
            errors.append(json.dumps(event))
    if exit_code:
        errors.append(stderr)
    text = "\n".join(errors)
    patterns = (
        ("rate-limit", r"rate.?limit|too many requests|usage limit|quota|\b429\b"),
        ("authentication", r"unauthori[sz]ed|authentication|not (?:logged|signed) in|invalid (?:api.?key|token)|\b401\b|\b403\b|login required"),
        ("model", r"model.{0,120}(?:not found|not supported|unsupported|not available|does not exist|access)|unsupported.{0,40}model"),
    )
    for category, expression in patterns:
        match = re.search(expression, text, re.I | re.S)
        if match:
            return {"category": category, "evidence": match.group(0)[:300],
                    "policy": "blocked; operator intervention required; no automatic retry"}
    if errors and any(error for error in errors):
        return {"category": "backend-error", "evidence": text[-300:],
                "policy": "blocked; backend error event requires review; no automatic retry"}
    if exit_code:
        return {"category": "backend-error", "evidence": f"backend exit code {exit_code}; no diagnostic text",
                "policy": "blocked; unsuccessful backend exit requires review; no automatic retry"}
    return None


def completed_event(stdout):
    for line in stdout.splitlines():
        try:
            event = json.loads(line)
        except ValueError:
            continue
        if isinstance(event, dict) and event.get("type") == "turn.completed":
            return True
    return False


def validate_config(root, config):
    if not isinstance(config, dict) or not isinstance(config.get("workers"), list) or not config["workers"]:
        raise ValueError("config needs a nonempty workers array")
    concurrent = config.get("max_concurrent", 24)
    if isinstance(concurrent, bool) or not isinstance(concurrent, int) or not 1 <= concurrent <= 24:
        raise ValueError("max_concurrent must be an integer from 1 to 24")
    if not isinstance(config.get("repeat", False), bool):
        raise ValueError("repeat must be boolean")
    backlog = config.get("max_unreviewed_batches", 2)
    if isinstance(backlog, bool) or not isinstance(backlog, int) or backlog < 1:
        raise ValueError("max_unreviewed_batches must be a positive integer")
    model = config.get("model", "gpt-6.1-sol")
    if not isinstance(model, str) or not model.strip():
        raise ValueError("model must be a nonempty string")
    backend = config.get("backend")
    if not isinstance(backend, str) or not backend.strip():
        raise ValueError("backend must name the native Codex executable")
    executable = shutil.which(backend)
    if executable is None:
        candidate = Path(backend).expanduser()
        if not candidate.is_absolute():
            candidate = root / candidate
        if not candidate.is_file():
            raise ValueError("backend executable not found")
        executable = str(candidate.resolve())
    workers, ids, trees = [], set(), set()
    for worker in config["workers"]:
        if not isinstance(worker, dict) or not re.fullmatch(r"[A-Za-z0-9][A-Za-z0-9_-]{0,79}", worker.get("id", "")):
            raise ValueError("worker id must be a safe, nonempty unique identifier")
        if not isinstance(worker.get("worktree"), str) or not isinstance(worker.get("prompt_file"), str):
            raise ValueError("worker needs worktree and prompt_file paths")
        if not isinstance(worker.get("repeat", config.get("repeat", False)), bool):
            raise ValueError("per-worker repeat must be boolean")
        tree, prompt = Path(worker["worktree"]), Path(worker["prompt_file"])
        tree = (root / tree).resolve() if not tree.is_absolute() else tree.resolve()
        prompt = (root / prompt).resolve() if not prompt.is_absolute() else prompt.resolve()
        key = os.path.normcase(str(tree))
        if worker["id"] in ids or key in trees or tree == root:
            raise ValueError("each lane needs a unique id and independent worktree distinct from main")
        if not tree.is_dir() or not prompt.is_file():
            raise ValueError("worker worktree/prompt missing")
        if prompt.stat().st_size > 1024 * 1024:
            raise ValueError("worker prompt exceeds 1 MiB")
        text = prompt.read_text(encoding="utf-8-sig")
        if not text.strip():
            raise ValueError("worker prompt is empty")
        ids.add(worker["id"])
        trees.add(key)
        workers.append({"id": worker["id"], "worktree": str(tree), "prompt_file": str(prompt), "prompt": text,
                        "repeat": worker.get("repeat", config.get("repeat", False))})
    return {"backend": executable, "model": model, "max_concurrent": concurrent,
            "repeat": config.get("repeat", False), "max_unreviewed_batches": backlog, "workers": workers}


def load_factory(root):
    path = root / "tools/factory.py"
    spec = importlib.util.spec_from_file_location("fleet_main_factory", path)
    if spec is None or spec.loader is None:
        raise ValueError("main factory module unavailable")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    if not callable(getattr(module, "connect", None)) or not callable(getattr(module, "heartbeat", None)):
        raise ValueError("main factory module needs connect and heartbeat")
    return module


class Supervisor:
    def __init__(self, root, config, factory, popen=None):
        self.root = Path(root).resolve()
        self.config = validate_config(self.root, config)
        self.factory = factory
        self.popen = popen or subprocess.Popen
        self.directory = self.root / "build/factory"
        self.state_path = self.directory / "fleet.json"
        self.stop_path = self.directory / "STOP"
        self.ack_path = self.directory / "fleet-acks.json"
        self.acknowledgement_error = None
        self.stopping = False
        self.fleet_id = uuid.uuid4().hex
        self.started = utc()
        self.running = {}
        self.workers = [{**worker, "status": "pending", "pid": None, "batches_started": 0,
                         "completed_batches": 0, "reviewed_batches": 0, "unreviewed_batches": 0,
                         "backpressured": False, "history": []} for worker in self.config["workers"]]
        self.last_heartbeat = -float("inf")
        self.diagnostics = []
        if self.state_path.exists():
            old = json.loads(self.state_path.read_text(encoding="utf-8"))
            live = [worker for worker in old.get("workers", []) if worker.get("status") == "running" and pid_alive(worker.get("pid"))]
            if live:
                raise ValueError("previous fleet child processes still live; preserve their worktrees and inspect before restarting: " +
                                 ", ".join(str(worker.get("pid")) for worker in live))
            # Archive the previous supervisor record before starting a fresh session.
            archive = self.directory / "fleet-history" / (str(time.time_ns()) + ".json")
            atomic_json(archive, old)

    def request_stop(self, *args):
        self.stopping = True

    def snapshot(self):
        counts = Counter(worker["status"] for worker in self.workers)
        return {"schema_version": 1, "fleet_id": self.fleet_id, "supervisor_pid": os.getpid(),
                "started_utc": self.started, "heartbeat_utc": utc(), "stopping": self.stopping,
                "stop_file": str(self.stop_path), "model": self.config["model"],
                "max_concurrent": self.config["max_concurrent"], "repeat": self.config["repeat"],
                "max_unreviewed_batches": self.config["max_unreviewed_batches"],
                "acknowledgements_path": str(self.ack_path), "acknowledgement_error": self.acknowledgement_error,
                "backpressured_workers": sum(worker["backpressured"] for worker in self.workers),
                "counts": {key: counts[key] for key in ("pending", "running", "review", "blocked")},
                "workers": [{key: value for key, value in worker.items() if key != "prompt"} for worker in self.workers],
                "diagnostics": self.diagnostics[-20:], "notice": "Worker exit requires review; no automatic source acceptance or integration."}

    def reload_acknowledgements(self):
        if not self.ack_path.exists():
            return False
        try:
            if self.ack_path.stat().st_size > 1024 * 1024:
                raise ValueError("acknowledgment file exceeds 1 MiB")
            acknowledgements = json.loads(self.ack_path.read_text(encoding="utf-8-sig"))
            if not isinstance(acknowledgements, dict):
                raise ValueError("acknowledgments must be an object mapping lane id to reviewed batch count")
            workers = {worker["id"]: worker for worker in self.workers}
            # Validate the entire document before releasing any lane.
            for lane, count in acknowledgements.items():
                if lane not in workers:
                    raise ValueError(f"unknown acknowledgment lane {lane!r}")
                worker = workers[lane]
                if isinstance(count, bool) or not isinstance(count, int) or count < 0 or count > worker["completed_batches"]:
                    raise ValueError(f"acknowledgment count for {lane} must be between 0 and completed_batches")
                if count < worker["reviewed_batches"]:
                    raise ValueError(f"acknowledgment count for {lane} cannot decrease")
            changed = self.acknowledgement_error is not None
            self.acknowledgement_error = None
            for lane, count in acknowledgements.items():
                worker = workers[lane]
                changed = changed or worker["reviewed_batches"] != count
                worker["reviewed_batches"] = count
            return changed
        except (OSError, ValueError) as error:
            message = str(error)
            changed = message != self.acknowledgement_error
            if changed:
                self.diagnostics.append({"utc": utc(), "error": f"acknowledgments: {message}"})
            self.acknowledgement_error = message
            return changed

    def release_reviewed_lanes(self):
        changed = False
        for worker in self.workers:
            worker["unreviewed_batches"] = worker["completed_batches"] - worker["reviewed_batches"]
            backpressured = (worker["repeat"] and worker["status"] == "review" and worker.get("exit_code") == 0
                             and worker["unreviewed_batches"] >= self.config["max_unreviewed_batches"])
            changed = changed or worker["backpressured"] != backpressured
            worker["backpressured"] = backpressured
            if (worker["repeat"] and worker["status"] == "review" and worker.get("exit_code") == 0
                    and not backpressured and not self.stopping):
                worker["status"] = "pending"
                changed = True
        return changed

    def publish(self, now, force=False):
        if not force and now - self.last_heartbeat < HEARTBEAT_SECONDS:
            return
        self.last_heartbeat = now
        for worker in self.workers:
            if worker.get("artifacts"):
                paths = [Path(worker["artifacts"]) / "events.jsonl", Path(worker["artifacts"]) / "stderr.log"]
                modified = [path.stat().st_mtime for path in paths if path.is_file() and path.stat().st_size]
                if modified:
                    worker["activity_utc"] = datetime.fromtimestamp(max(modified), timezone.utc).isoformat()
        try:
            db = self.factory.connect(self.root)
            try:
                for worker in self.workers:
                    self.factory.heartbeat(db, worker["id"], self.config["model"], worker["status"],
                                           worker.get("job_id"), worker["worktree"])
            finally:
                db.close()
        except Exception as error:
            self.diagnostics.append({"utc": utc(), "error": f"heartbeat: {error}"})
        atomic_json(self.state_path, self.snapshot())

    def launch(self, worker):
        worker["batches_started"] += 1
        number = worker["batches_started"]
        job_id = f"{self.fleet_id}-{worker['id']}-{number:04d}"
        folder = self.directory / "fleet" / self.fleet_id / worker["id"] / f"{number:04d}"
        folder.mkdir(parents=True, exist_ok=False)
        final_folder = Path(worker["worktree"]) / "build/factory/fleet" / self.fleet_id / f"{number:04d}"
        final_folder.mkdir(parents=True, exist_ok=False)
        final = final_folder / "final.txt"
        prompt = worker["prompt"] + (
            "\n\nFleet execution constraints: Do not spawn sub-agents or delegate to other agents. "
            "Use absolute paths for edits and keep edits inside your assigned worktree: " + worker["worktree"] +
            ". Do not edit main, other worktrees, or the integrator-owned queue. "
            "Complete one bounded assigned job, preserving existing user changes and variant-count evidence, then provide a compact review handoff.")
        if number > 1:
            previous = worker["history"][-1]
            prompt += ("\n\nContinuation of this same scoped worker lane. Inspect your existing worktree, previous experiments and handoff before editing. "
                       "Preserve existing work. Continue only an unowned family within your assigned subsystem; coordinate through local factory/queue evidence. "
                       "Do not reset the ten-unproductive-variant count across batches. Previously deferred functions remain required. "
                       "No automatic acceptance or integration has occurred. Produce another bounded job and compact review handoff.\n"
                       f"Previous archived result: {previous['final_path']}\nPrevious final handoff (tail, capped 64 KiB):\n" +
                       read_tail(Path(previous["final_path"])))
        prompt_path = folder / "prompt.txt"
        prompt_path.write_text(prompt, encoding="utf-8")
        command = [self.config["backend"], "exec", "--model", self.config["model"],
                   "-c", "model_reasoning_effort=high", "-c", "approval_policy=never",
                   "-c", "features.multi_agent=false",
                   "-s", "danger-full-access", "--json", "-C", worker["worktree"], "-o", str(final), "-"]
        handles = []
        try:
            stdin = prompt_path.open("rb")
            handles.append(stdin)
            stdout = (folder / "events.jsonl").open("wb")
            handles.append(stdout)
            stderr = (folder / "stderr.log").open("wb")
            handles.append(stderr)
            kwargs = {"cwd": worker["worktree"], "stdin": stdin, "stdout": stdout, "stderr": stderr, "shell": False}
            if os.name == "nt":
                kwargs["creationflags"] = subprocess.CREATE_NO_WINDOW
            process = self.popen(command, **kwargs)
            worker.update(status="running", pid=process.pid, job_id=job_id,
                          started_utc=utc(), command=command, artifacts=str(folder), final_path=str(final))
            self.running[worker["id"]] = (process, handles, folder)
        except Exception as error:
            for handle in handles:
                handle.close()
            worker.update(status="blocked", pid=None, job_id=job_id, error=f"launch failed: {error}")
            atomic_json(folder / "result.json", {"job_id": job_id, "status": "blocked", "error": str(error), "utc": utc()})

    def reap(self):
        changed = False
        for worker in self.workers:
            active = self.running.get(worker["id"])
            if not active or active[0].poll() is None:
                continue
            process, handles, folder = active
            for handle in handles:
                handle.close()
            events = read_tail(folder / "events.jsonl")
            block = blocking_error(events, read_tail(folder / "stderr.log"), process.returncode)
            if block is None and (not completed_event(events) or not Path(worker["final_path"]).is_file()):
                block = {"category": "protocol-incomplete", "evidence":
                         "zero backend exit without both turn.completed event and final handoff file",
                         "policy": "blocked; incomplete backend protocol requires review; no automatic retry"}
            result = {"job_id": worker["job_id"], "status": "blocked" if block else "review",
                      "pid": process.pid, "exit_code": process.returncode, "started_utc": worker["started_utc"],
                      "finished_utc": utc(), "final_path": worker["final_path"], "artifacts": str(folder),
                      "blocking_error": block, "accepted": False}
            atomic_json(folder / "result.json", result)
            worker["history"].append(result)
            worker.update(status=result["status"], pid=None, last_pid=process.pid, exit_code=process.returncode,
                          finished_utc=result["finished_utc"], blocking_error=block)
            worker["completed_batches"] += 1
            del self.running[worker["id"]]
            changed = True
        return changed

    def step(self, now=None):
        now = time.monotonic() if now is None else now
        if self.stop_path.exists():
            self.stopping = True
        changed = self.reap()
        changed = self.reload_acknowledgements() or changed
        changed = self.release_reviewed_lanes() or changed
        if not self.stopping:
            for worker in sorted(self.workers, key=lambda item: item["batches_started"]):
                # Recheck the stop file before every individual launch.
                if self.stop_path.exists():
                    self.stopping = True
                    break
                if len(self.running) >= self.config["max_concurrent"]:
                    break
                if worker["status"] == "pending":
                    self.launch(worker)
                    changed = True
        # Native backends can finish while other lanes are being launched.
        changed = self.reap() or changed
        changed = self.release_reviewed_lanes() or changed
        self.publish(now, force=changed)
        return bool(self.running) or (not self.stopping and any(
            worker["status"] == "pending" or worker["backpressured"] for worker in self.workers))

    def run(self):
        while self.step():
            time.sleep(0.5)
        self.publish(time.monotonic(), force=True)
        return 2 if any(worker["status"] == "blocked" for worker in self.workers) else 0


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", required=True, type=Path, help="integrator/main worktree")
    parser.add_argument("--config", required=True, type=Path)
    args = parser.parse_args(argv)
    previous = {}
    try:
        root = args.root.resolve()
        config = json.loads(args.config.read_text(encoding="utf-8-sig"))
        with FleetLock(root):
            supervisor = Supervisor(root, config, load_factory(root))
            for signum in (signal.SIGINT, signal.SIGTERM):
                previous[signum] = signal.signal(signum, supervisor.request_stop)
            return supervisor.run()
    except (OSError, ValueError, TypeError, AttributeError) as error:
        print(f"factory_fleet: {error}", file=sys.stderr)
        return 2
    finally:
        for signum, handler in previous.items():
            signal.signal(signum, handler)


if __name__ == "__main__":
    sys.exit(main())
