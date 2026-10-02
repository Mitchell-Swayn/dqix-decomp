"""Run fleet lifecycle tests with local Python children, never the real backend."""
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import time
import unittest

import factory_fleet as fleet


FAKE_BACKEND = '''import json,pathlib,sys,time
prompt=sys.stdin.read()
final=pathlib.Path(sys.argv[1])
print(json.dumps({"type":"thread.started","thread_id":"fixture"}),flush=True)
if "WAIT" in prompt: time.sleep(0.35)
if "RATEFAIL" in prompt:
    print(json.dumps({"type":"turn.failed","error":{"message":"rate limit exceeded 429"}}),flush=True)
    sys.exit(0)
if "EMPTYFAIL" in prompt: sys.exit(7)
if "MISSINGFINAL" not in prompt:
    final.write_text("Fixture handoff. Preserve accumulated experiments.",encoding="utf-8")
if "NOCOMPLETION" not in prompt:
    print(json.dumps({"type":"turn.completed","usage":{"input_tokens":11,"cached_input_tokens":2,"output_tokens":3}}),flush=True)
'''


class FakeDB:
    def close(self):
        pass


class FakeFactory:
    def __init__(self):
        self.beats = []

    def connect(self, root):
        return FakeDB()

    def heartbeat(self, db, *values):
        self.beats.append(values)


class FleetTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name).resolve() / "main"
        self.root.mkdir()
        self.backend = self.root / "fake_backend.py"
        self.backend.write_text(FAKE_BACKEND, encoding="utf-8")
        self.factory = FakeFactory()
        self.launched = []
        self.supervisors = []
        self.addCleanup(self.cleanup_children)

    def cleanup_children(self):
        for supervisor in self.supervisors:
            for process, handles, folder in supervisor.running.values():
                if process.poll() is None:
                    process.terminate()
                    process.wait(timeout=5)
                for handle in handles:
                    handle.close()

    def config(self, count=2, prompt="Bounded fixture family.", **overrides):
        workers = []
        for index in range(count):
            tree = self.root.parent / f"worker-{index}"
            tree.mkdir(exist_ok=True)
            path = self.root / f"prompt-{index}.txt"
            path.write_text(prompt, encoding="utf-8")
            workers.append({"id": f"lane-{index}", "worktree": str(tree), "prompt_file": str(path)})
        return {"workers": workers, "backend": sys.executable, "model": "gpt-6.1-sol", "max_concurrent": 24, **overrides}

    def launch_fake(self, argv, **kwargs):
        self.launched.append((argv, {key: value for key, value in kwargs.items() if key not in ("stdin", "stdout", "stderr")}))
        final = argv[argv.index("-o") + 1]
        return subprocess.Popen([sys.executable, str(self.backend), final], **kwargs)

    def supervisor(self, config):
        supervisor = fleet.Supervisor(self.root, config, self.factory, popen=self.launch_fake)
        self.supervisors.append(supervisor)
        return supervisor

    def drain(self, supervisor):
        deadline = time.monotonic() + 5
        while supervisor.step():
            if time.monotonic() > deadline:
                self.fail("fake backend failed to finish")
            time.sleep(0.01)

    def until(self, supervisor, condition):
        deadline = time.monotonic() + 5
        while not condition():
            supervisor.step()
            self.assertLess(time.monotonic(), deadline)
            time.sleep(0.01)

    def test_bounded_jobs_hidden_command_and_review(self):
        supervisor = self.supervisor(self.config())
        self.drain(supervisor)
        state = json.loads(supervisor.state_path.read_text())
        self.assertEqual(state["counts"]["review"], 2)
        self.assertEqual(state["counts"]["running"], 0)
        self.assertEqual(len(self.launched), 2)
        for worker, (argv, kwargs) in zip(supervisor.workers, self.launched):
            self.assertEqual(argv[1:4], ["exec", "--model", "gpt-6.1-sol"])
            self.assertIn("model_reasoning_effort=high", argv)
            self.assertIn("approval_policy=never", argv)
            self.assertIn("features.multi_agent=false", argv)
            self.assertEqual(argv[-1], "-")
            self.assertFalse(kwargs["shell"])
            if os.name == "nt":
                self.assertEqual(kwargs["creationflags"], subprocess.CREATE_NO_WINDOW)
            result = json.loads((Path(worker["artifacts"]) / "result.json").read_text())
            self.assertFalse(result["accepted"])
            self.assertEqual(result["status"], "review")
            self.assertIn("turn.completed", (Path(worker["artifacts"]) / "events.jsonl").read_text())
            self.assertTrue(Path(worker["final_path"]).is_file())
            self.assertTrue(Path(worker["artifacts"]).is_relative_to(self.root / "build/factory"))

    def test_concurrency_cap_and_stop_preserve_running_child(self):
        supervisor = self.supervisor(self.config(count=3, prompt="WAIT", max_concurrent=1))
        self.assertTrue(supervisor.step())
        self.assertEqual(len(supervisor.running), 1)
        process = next(iter(supervisor.running.values()))[0]
        self.assertTrue(fleet.pid_alive(process.pid))
        supervisor.stop_path.write_text("stop new jobs", encoding="utf-8")
        self.assertTrue(supervisor.step())
        self.assertIsNone(process.poll())
        self.drain(supervisor)
        self.assertEqual(len(self.launched), 1)
        self.assertEqual(supervisor.snapshot()["counts"]["pending"], 2)
        self.assertTrue(supervisor.snapshot()["stopping"])

    def test_initial_stop_file_prevents_all_launches(self):
        supervisor = self.supervisor(self.config())
        supervisor.stop_path.parent.mkdir(parents=True, exist_ok=True)
        supervisor.stop_path.write_text("stop", encoding="utf-8")
        self.assertFalse(supervisor.step())
        self.assertEqual(self.launched, [])

    def test_rate_error_exit_zero_blocks_without_hot_retry(self):
        supervisor = self.supervisor(self.config(count=1, prompt="RATEFAIL", repeat=True))
        self.drain(supervisor)
        worker = supervisor.workers[0]
        self.assertEqual(worker["status"], "blocked")
        self.assertEqual(worker["blocking_error"]["category"], "rate-limit")
        self.assertEqual(len(self.launched), 1)
        self.assertFalse(supervisor.step())

    def test_repeat_preserves_handoff_and_per_lane_override(self):
        config = self.config(repeat=True)
        config["workers"][0]["repeat"] = False
        supervisor = self.supervisor(config)
        supervisor.step()
        deadline = time.monotonic() + 5
        while supervisor.workers[1]["batches_started"] < 2:
            supervisor.step()
            self.assertLess(time.monotonic(), deadline)
            time.sleep(0.01)
        worker = supervisor.workers[1]
        first = worker["history"][0]
        self.assertEqual(first["status"], "review")
        self.assertNotEqual(first["final_path"], worker["final_path"])
        self.assertTrue(Path(first["final_path"]).is_file())
        prompt = (Path(worker["artifacts"]) / "prompt.txt").read_text()
        self.assertIn("Do not reset the ten-unproductive-variant count", prompt)
        self.assertIn("Fixture handoff", prompt)
        self.assertIn("Do not spawn sub-agents", prompt)
        supervisor.stop_path.write_text("stop", encoding="utf-8")
        self.drain(supervisor)
        self.assertEqual(supervisor.workers[0]["batches_started"], 1)
        self.assertEqual(worker["batches_started"], 2)

    def test_ten_second_heartbeat_and_real_pids(self):
        supervisor = self.supervisor(self.config(count=1, prompt="WAIT"))
        supervisor.step(now=0)
        state = json.loads(supervisor.state_path.read_text())
        self.assertEqual(state["workers"][0]["pid"], next(iter(supervisor.running.values()))[0].pid)
        count = len(self.factory.beats)
        supervisor.publish(9.9)
        self.assertEqual(len(self.factory.beats), count)
        supervisor.publish(10)
        self.assertEqual(len(self.factory.beats), count + 1)
        supervisor.request_stop()
        self.drain(supervisor)

    def test_lock_released_and_duplicate_supervisor_rejected(self):
        with fleet.FleetLock(self.root):
            with self.assertRaisesRegex(ValueError, "lock unavailable"):
                with fleet.FleetLock(self.root):
                    pass
        with fleet.FleetLock(self.root):
            pass

    def test_live_old_child_rejects_restart_and_preserves_state(self):
        path = self.root / "build/factory/fleet.json"
        old = {"workers": [{"id": "previous", "status": "running", "pid": os.getpid()}]}
        fleet.atomic_json(path, old)
        before = path.read_bytes()
        with self.assertRaisesRegex(ValueError, "still live"):
            self.supervisor(self.config())
        self.assertEqual(path.read_bytes(), before)

    def test_configuration_validates_independence_bounds_and_empty_prompt(self):
        for overrides in ({"max_concurrent": 25}, {"max_concurrent": True}, {"repeat": "true"},
                          {"max_unreviewed_batches": 0}, {"max_unreviewed_batches": True},
                          {"backend": "missing-native-executable"}):
            with self.subTest(overrides=overrides), self.assertRaises(ValueError):
                fleet.validate_config(self.root, self.config(**overrides))
        config = self.config()
        config["workers"][1]["worktree"] = config["workers"][0]["worktree"]
        with self.assertRaises(ValueError):
            fleet.validate_config(self.root, config)
        config = self.config()
        config["workers"][0]["worktree"] = str(self.root)
        with self.assertRaises(ValueError):
            fleet.validate_config(self.root, config)
        with self.assertRaises(ValueError):
            fleet.validate_config(self.root, self.config(prompt=""))

    def test_error_detection_ignores_assistant_mentions(self):
        ordinary = json.dumps({"type": "item.completed", "item": {"text": "Investigate rate limit model authentication examples"}})
        self.assertIsNone(fleet.blocking_error(ordinary, "", 0))
        for message, category in (("Authentication failed 401", "authentication"),
                                  ("model gpt-6.1-sol is not supported", "model"),
                                  ("backend encountered an unknown error", "backend-error")):
            with self.subTest(message=message):
                event = json.dumps({"type": "turn.failed", "error": {"message": message}})
                self.assertEqual(fleet.blocking_error(event, "", 0)["category"], category)

    def test_launch_failure_blocks_and_does_not_retry(self):
        supervisor = self.supervisor(self.config(count=1, repeat=True))
        def fail(*args, **kwargs):
            raise OSError("fixture executable cannot start")
        supervisor.popen = fail
        self.assertFalse(supervisor.step())
        self.assertEqual(supervisor.workers[0]["status"], "blocked")
        self.assertFalse(supervisor.step())
        self.assertEqual(supervisor.workers[0]["batches_started"], 1)

    def test_factory_import_is_explicit_main_module(self):
        path = self.root / "tools/factory.py"
        path.parent.mkdir()
        path.write_text("def connect(root): return root\ndef heartbeat(*args): pass\n", encoding="utf-8")
        module = fleet.load_factory(self.root)
        self.assertEqual(module.connect("fixture"), "fixture")

    def test_backpressure_waits_at_two_and_acknowledgment_resumes(self):
        supervisor = self.supervisor(self.config(count=1, repeat=True))
        worker = supervisor.workers[0]
        self.until(supervisor, lambda: worker["completed_batches"] == 2)
        self.assertEqual(worker["batches_started"], 2)
        self.assertEqual(worker["status"], "review")
        self.assertTrue(worker["backpressured"])
        self.assertEqual(worker["unreviewed_batches"], 2)
        for _ in range(3):
            self.assertTrue(supervisor.step())  # Stays alive, waiting for review.
        self.assertEqual(len(self.launched), 2)
        fleet.atomic_json(supervisor.ack_path, {worker["id"]: 1})
        self.assertTrue(supervisor.step())
        self.assertEqual(worker["reviewed_batches"], 1)
        self.assertEqual(worker["batches_started"], 3)
        self.until(supervisor, lambda: worker["completed_batches"] == 3)
        self.assertTrue(worker["backpressured"])
        self.assertEqual(worker["unreviewed_batches"], 2)
        self.assertEqual(worker["history"][0]["status"], "review")
        self.assertFalse(worker["history"][0]["accepted"])
        self.assertEqual(supervisor.snapshot()["backpressured_workers"], 1)
        supervisor.stop_path.write_text("stop", encoding="utf-8")
        self.assertFalse(supervisor.step())

    def test_invalid_acknowledgments_do_not_release_or_decrease_counts(self):
        supervisor = self.supervisor(self.config(count=1, repeat=True, max_unreviewed_batches=1))
        worker = supervisor.workers[0]
        self.until(supervisor, lambda: worker["completed_batches"] == 1)
        for acknowledgements in ({worker["id"]: -1}, {worker["id"]: True}, {worker["id"]: 2},
                                  {"unknown": 0}, [], {worker["id"]: 1, "unknown": 0}):
            with self.subTest(acknowledgements=acknowledgements):
                fleet.atomic_json(supervisor.ack_path, acknowledgements)
                supervisor.step()
                self.assertEqual(worker["reviewed_batches"], 0)
                self.assertEqual(worker["batches_started"], 1)
                self.assertIsNotNone(supervisor.acknowledgement_error)
        fleet.atomic_json(supervisor.ack_path, {worker["id"]: 1})
        supervisor.step()
        self.assertIsNone(supervisor.acknowledgement_error)
        self.assertEqual(worker["reviewed_batches"], 1)
        fleet.atomic_json(supervisor.ack_path, {worker["id"]: 0})
        supervisor.step()
        self.assertEqual(worker["reviewed_batches"], 1)
        self.assertIn("cannot decrease", supervisor.acknowledgement_error)
        supervisor.request_stop()
        self.drain(supervisor)

    def test_nonzero_empty_stderr_and_incomplete_success_are_blocked(self):
        for prompt, category in (("EMPTYFAIL", "backend-error"), ("MISSINGFINAL", "protocol-incomplete"),
                                  ("NOCOMPLETION", "protocol-incomplete")):
            with self.subTest(prompt=prompt):
                supervisor = self.supervisor(self.config(count=1, repeat=True, prompt=prompt))
                self.drain(supervisor)
                self.assertEqual(supervisor.workers[0]["status"], "blocked")
                self.assertEqual(supervisor.workers[0]["blocking_error"]["category"], category)
                self.assertEqual(supervisor.workers[0]["batches_started"], 1)


if __name__ == "__main__":
    unittest.main()
