"""Review safety tests: local Git and mocked native commands; no paid model calls."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import time
import unittest
from unittest.mock import MagicMock, patch

import factory_review as review


class ReviewTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.git("init", "-q")
        (self.root / ".gitignore").write_text("build/\n.venv/\n*.exe\nextract/\ntools/mwccarm/\n", encoding="utf-8")
        (self.root / "source.c").write_text("int answer(void) { return 1; }\n", encoding="utf-8")
        self.git("add", ".gitignore", "source.c")
        self.git("-c", "user.name=Review test", "-c", "user.email=test@example.invalid", "commit", "-qm", "base")
        base = self.git("rev-parse", "HEAD")
        (self.root / "source.c").write_text("int answer(void) { return 2; }\n", encoding="utf-8")
        self.git("add", "source.c")
        self.git("-c", "user.name=Review test", "-c", "user.email=test@example.invalid", "commit", "-qm", "candidate")
        tip = self.git("rev-parse", "HEAD")
        self.submission = {"id": "submission-1", "lane": "runtime", "module": "arm9",
                           "base_revision": base, "source_tip": tip, "commits": [tip]}
        self.verdict = {"verdict": "approved", "source_tip": tip, "base_revision": base,
                        "findings": [], "evidence": ["Inspected source and object comparisons"]}

    def git(self, *args):
        return subprocess.check_output(["git", *args], cwd=self.root, text=True, stderr=subprocess.DEVNULL).strip()

    def events(self, verdict=None, extra=None, completed=True):
        verdict = self.verdict if verdict is None else verdict
        events = [{"type": "thread.started", "thread_id": "mock"},
                  {"type": "item.completed", "item": {"type": "agent_message", "text": json.dumps(verdict)}}]
        if extra:
            events.append(extra)
        if completed:
            events.append({"type": "turn.completed", "usage": {"input_tokens": 1, "output_tokens": 1}})
        path = self.root / "events.jsonl"
        final = self.root / "final.json"
        path.write_text("\n".join(json.dumps(event) for event in events) + "\n", encoding="utf-8")
        final.write_text(json.dumps(verdict), encoding="utf-8")
        return path, final

    def test_immutable_commit_validation(self):
        self.assertEqual(review.validate_submission(self.root, self.submission), self.submission)
        for key in ("base_revision", "source_tip"):
            for invalid in ("HEAD", self.submission[key][:8], "a" * 40, self.submission[key].upper()):
                with self.subTest(key=key, invalid=invalid), self.assertRaises(ValueError):
                    review.validate_submission(self.root, dict(self.submission, **{key: invalid}))

    def test_exact_commit_range_rejects_omissions_duplicates_and_reordering(self):
        for commits in ([], [self.submission["base_revision"]], [self.submission["source_tip"]] * 2,
                        [self.submission["source_tip"], self.submission["base_revision"]]):
            with self.subTest(commits=commits), self.assertRaises(ValueError):
                review.validate_submission(self.root, dict(self.submission, commits=commits))

    def test_native_output_accepted_only_with_completion_and_same_file(self):
        events, final = self.events()
        self.assertEqual(review.read_model_verdict(events, final, self.submission), self.verdict)
        final.write_text(json.dumps(dict(self.verdict, verdict="deferred")), encoding="utf-8")
        with self.assertRaisesRegex(ValueError, "differs"):
            review.read_model_verdict(events, final, self.submission)

    def test_native_failure_and_incomplete_turn_block_approval(self):
        errors = [{"type": "error", "message": "failed"}, {"type": "turn.failed"},
                  {"type": "item.completed", "item": {"type": "error", "message": "failed"}}]
        for error in errors:
            with self.subTest(error=error):
                events, final = self.events(extra=error)
                with self.assertRaisesRegex(ValueError, "error"):
                    review.read_model_verdict(events, final, self.submission)
        events, final = self.events(completed=False)
        with self.assertRaisesRegex(ValueError, "completed turn"):
            review.read_model_verdict(events, final, self.submission)

    def test_exploratory_nonzero_commands_are_retained_not_blanket_rejected(self):
        events, final = self.events(extra={"type": "item.completed", "item": {
            "type": "command_execution", "exit_code": 1, "command": "rg absent source.c", "status": "failed"}})
        verdict = review.read_model_verdict(events, final, self.submission)
        self.assertEqual(verdict["verdict"], "approved")
        self.assertIn("Exploratory command exit 1: rg absent source.c", verdict["evidence"])
        events, final = self.events(extra={"type": "turn.completed"})
        with self.assertRaisesRegex(ValueError, "completed turn"):
            review.read_model_verdict(events, final, self.submission)

    def test_malformed_schema_and_wrong_bindings_block_approval(self):
        bad = [dict(self.verdict, source_tip=self.submission["base_revision"]),
               dict(self.verdict, base_revision="HEAD"), dict(self.verdict, verdict="approve"),
               dict(self.verdict, findings=["blocking issue"]), dict(self.verdict, evidence=[]),
               dict(self.verdict, evidence=[1]), dict(self.verdict, findings="none"),
               dict(self.verdict, extra=True), {key: value for key, value in self.verdict.items() if key != "evidence"}]
        for verdict in bad:
            with self.subTest(verdict=verdict), self.assertRaises(ValueError):
                review.validate_verdict(verdict, self.submission)

    def test_strict_json_rejects_duplicate_keys_nan_and_nonjson(self):
        for text in ('{"verdict":"deferred","verdict":"approved"}', '{"x":NaN}', "not JSON"):
            with self.subTest(text=text), self.assertRaises(ValueError):
                review._strict_json(text)
        events, final = self.events()
        events.write_text(events.read_text() + "garbled event\n", encoding="utf-8")
        with self.assertRaises(ValueError):
            review.read_model_verdict(events, final, self.submission)

    def test_rom_copy_is_independent_and_rejects_wrong_input(self):
        source = self.root / "original.nds"
        target = self.root / "copy.nds"
        source.write_bytes(b"verified original")
        expected = hashlib.sha1(source.read_bytes()).hexdigest()
        self.assertEqual(review._copy_file(source, target, expected, "sha1"), expected)
        self.assertFalse(target.samefile(source))
        self.assertEqual(target.stat().st_nlink, 1)
        target.write_bytes(b"output changed")
        self.assertEqual(source.read_bytes(), b"verified original")
        with self.assertRaisesRegex(ValueError, "hash mismatch"):
            review._copy_file(source, self.root / "wrong.nds", "a" * 40, "sha1")

    def test_native_backend_rejects_shell_wrappers(self):
        for suffix in (".cmd", ".bat", ".ps1", ".js"):
            wrapper = self.root / ("codex" + suffix)
            wrapper.write_text("not native", encoding="utf-8")
            with self.assertRaises(ValueError):
                review._native_backend(str(wrapper))

    def test_prepare_does_not_call_model_and_pins_command(self):
        runtime = self.root / "runtime.exe"
        runtime.write_bytes(b"mock runtime")
        with patch.object(review, "_native_backend", return_value=runtime), \
                patch.object(review, "_runtime", return_value=(runtime, runtime)), \
                patch.object(review, "_populate"), patch.object(review, "_readonly"):
            first = review.prepare_review(self.root, self.submission, str(runtime))
            second = review.prepare_review(self.root, self.submission, str(runtime))
        self.assertNotEqual(first["worktree"], second["worktree"])
        self.assertEqual(self.git("rev-parse", "HEAD"), self.submission["source_tip"])
        self.assertEqual(review._git(first["worktree"], "rev-parse", "HEAD"), self.submission["source_tip"])
        self.assertEqual(first["command"][first["command"].index("--model") + 1], review.MODEL)
        self.assertIn("--json", first["command"])
        self.assertIn("--output-schema", first["command"])
        self.assertIn("approval_policy=\"never\"", first["command"])
        self.assertEqual([command["label"] for command in first["commands"]], ["reviewer-worktree"])

    def context(self):
        directory = self.root / "build/run"
        directory.mkdir(parents=True, exist_ok=True)
        source = directory / "reviewer"
        source.mkdir(exist_ok=True)
        events, final = self.events()
        return {"root": self.root, "directory": directory, "worktree": source, "submission": self.submission,
                "deadline": time.monotonic() + 1800, "commands": [], "runtime_hashes": {}, "inventory": {},
                "started_at": "2026-10-03T00:00:00+00:00", "final_path": final, "command": ["native-mock"],
                "prompt": "mock", "python": Path("mock-python"), "ninja": Path("mock-ninja")}, events

    def mocked_run(self, verifier=None, integrity=None, verdict=None, native_error=None):
        context, events = self.context()
        if verdict is not None:
            events, final = self.events(verdict)
            context["final_path"] = final
        def command(ctx, label, args, cwd, prompt=None):
            if label == "codex" and native_error:
                raise native_error
            return events
        with patch.object(review, "prepare_review", return_value=context), \
                patch.object(review, "_log_command", side_effect=command), \
                patch.object(review, "_check_integrity", side_effect=integrity), \
                patch.object(review, "_check_runtime"), \
                patch.object(review, "_verify", side_effect=verifier or (lambda ctx: {"rom_sha1": review.USA_SHA1})) as verify:
            result = review.run_review(self.root, self.submission, "native-mock", self.root / "build")
        return result, verify.call_count

    def test_approval_requires_independent_script_gate(self):
        result, calls = self.mocked_run()
        self.assertEqual(result["verdict"], "approved")
        self.assertEqual(calls, 1)
        record = json.loads((self.root / "build/run/review-result.json").read_text())
        self.assertEqual(record["verification"]["rom_sha1"], review.USA_SHA1)
        result, calls = self.mocked_run(verifier=lambda ctx: (_ for _ in ()).throw(ValueError("ROM checks failed")))
        self.assertEqual(result["verdict"], "infrastructure_blocked")
        self.assertEqual(calls, 1)
        self.assertIn("ROM checks failed", result["findings"])

    def test_dirty_source_and_native_nonzero_block_even_model_approval(self):
        result, calls = self.mocked_run(integrity=ValueError("Reviewer changed tracked source"))
        self.assertEqual(result["verdict"], "infrastructure_blocked")
        self.assertEqual(calls, 0)
        result, calls = self.mocked_run(native_error=ValueError("codex exited 1"))
        self.assertEqual(result["verdict"], "infrastructure_blocked")
        self.assertEqual(calls, 0)

    def test_model_rejection_does_not_run_acceptance(self):
        result, calls = self.mocked_run(verdict=dict(self.verdict, verdict="changes_requested", findings=["Unreadable source"]))
        self.assertEqual(result["verdict"], "changes_requested")
        self.assertEqual(calls, 0)

    def test_timeout_kills_native_tree(self):
        process = MagicMock()
        process.communicate.side_effect = [subprocess.TimeoutExpired(["native-mock"], 1), None]
        with patch.object(review.subprocess, "Popen", return_value=process), patch.object(review, "_kill_tree") as kill:
            with self.assertRaises(TimeoutError):
                review._process(["native-mock"], self.root, time.monotonic() + 1, None, None)
            kill.assert_called_once_with(process)
        with patch.object(review.subprocess, "Popen") as spawn:
            with self.assertRaises(TimeoutError):
                review._process(["native-mock"], self.root, time.monotonic() - 1, None, None)
            spawn.assert_not_called()

    def test_native_children_disable_python_cache_writes(self):
        process = MagicMock()
        process.returncode = 0
        with patch.object(review.subprocess, "Popen", return_value=process) as spawn:
            review._process(["native-mock"], self.root, time.monotonic()+10, None, None)
        self.assertEqual(spawn.call_args.kwargs["env"]["PYTHONDONTWRITEBYTECODE"], "1")

    def test_real_python_import_leaves_protected_inventory_unchanged(self):
        source = self.root / "python-import-fixture"
        source.mkdir()
        (source / "helper.py").write_text("answer = 42\n")
        before = review._inventory(source)
        self.assertEqual(review._process([sys.executable, "-c", "import helper; assert helper.answer == 42"],
                         source, time.monotonic()+10, subprocess.DEVNULL, subprocess.DEVNULL), 0)
        self.assertEqual(review._inventory(source), before)
        self.assertFalse((source / "__pycache__").exists())

    def test_pinned_objdiff_replaces_only_its_download_edge(self):
        tool = "objdiff-cli.exe" if review.os.name == "nt" else "objdiff-cli"
        (self.root / tool).write_bytes(b"pinned executable")
        expected = review._digest(self.root / tool)
        path = self.root / "build.ninja"
        path.write_text("build ./"+tool+": download_tool\n  tool = objdiff\nbuild other: download_tool\n")
        review.pin_preinstalled_objdiff(self.root, expected)
        self.assertIn("build ./"+tool+": phony", path.read_text())
        self.assertIn("build other: download_tool", path.read_text())
        (self.root / tool).write_bytes(b"tampered")
        with self.assertRaisesRegex(ValueError, "hash mismatch"):
            review.pin_preinstalled_objdiff(self.root, expected)

    def test_inventory_detects_source_tools_and_nonbuild_writes(self):
        source = self.root / "checkout"
        source.mkdir()
        (source / "source.c").write_text("immutable", encoding="utf-8")
        (source / ".git").write_text("gitdir: original", encoding="utf-8")
        inventory = review._inventory(source)
        (source / "build").mkdir()
        (source / "build/object.o").write_bytes(b"allowed output")
        self.assertEqual(review._inventory(source), inventory)
        (source / "source.c").write_text("modified", encoding="utf-8")
        self.assertNotEqual(review._inventory(source), inventory)
        (source / "source.c").write_text("immutable", encoding="utf-8")
        (source / "unexpected.txt").write_text("outside build", encoding="utf-8")
        self.assertNotEqual(review._inventory(source), inventory)

    def test_fresh_gate_runs_full_targets_and_independently_checks_output_hash(self):
        context, _ = self.context()
        source = context["directory"] / "verification"
        source.mkdir()
        original = b"verified tiny original"
        expected = hashlib.sha1(original).hexdigest()
        measures = {"total_code": "10", "matched_code": "2", "total_data": "10", "matched_data": "1",
                    "total_functions": 3, "matched_functions": 1}
        arm7 = {key: 0 for key in ("source_code_bytes", "source_literal_pool_bytes", "source_data_bytes",
                                  "source_bss_bytes", "source_functions", "binary_fallback_bytes",
                                  "reviewed_assembly_bytes", "payload_bytes")}
        arm7.update(module_check_passed=True, source_symbol_checks_passed=True)
        def populate(ctx, path):
            (path / "extract").mkdir(exist_ok=True)
            (path / "extract/baserom_dqix_usa.nds").write_bytes(original)
        def command(ctx, label, arguments, cwd, prompt=None):
            if label == "verification-ninja":
                self.assertEqual(arguments[1:], ["rom", "check", "report", "sha1"])
                (source / "dqix_usa.nds").write_bytes(original)
                output = source / "build/usa/arm7"
                output.mkdir(parents=True, exist_ok=True)
                (output.parent / "report.json").write_text(json.dumps({"measures": measures}), encoding="utf-8")
                (output / "report.json").write_text(json.dumps(arm7), encoding="utf-8")
        with patch.object(review, "USA_SHA1", expected), \
                patch.object(review, "_new_worktree", return_value=source) as fresh, \
                patch.object(review, "_populate", side_effect=populate), \
                patch.object(review, "_readonly"), patch.object(review, "_check_integrity"), \
                patch.object(review, "_log_command", side_effect=command):
            result = review._verify(context)
            fresh.assert_called_once_with(context, "verification")
            self.assertTrue(result["fresh_source_and_objects"])
            self.assertEqual(result["rom_sha1"], expected)
        # A model claim or exit-zero command cannot compensate for wrong actual bytes.
        (source / "dqix_usa.nds").write_bytes(b"wrong output")
        with patch.object(review, "USA_SHA1", expected), patch.object(review, "_new_worktree", return_value=source), \
                patch.object(review, "_populate"), patch.object(review, "_readonly"), \
                patch.object(review, "_check_integrity"), patch.object(review, "_log_command"):
            with self.assertRaisesRegex(ValueError, "SHA-1"):
                review._verify(context)


if __name__ == "__main__":
    unittest.main()
