"""Real lightweight Git staging/FF tests with synthetic acceptance snapshots, no ROM builds."""
import copy
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest
from unittest.mock import patch

import factory_integrate as gate

ROM = b"synthetic independent ROM fixture, not a proprietary input"
ROM_SHA1 = hashlib.sha1(ROM).hexdigest()
TOOL = b"synthetic non-executable tool fixture"
TOOL_HASH = hashlib.sha256(TOOL).hexdigest()


def git(root, *args):
    result = subprocess.run(["git", "-c", "user.name=Fixture", "-c", "user.email=fixture@example.invalid",
                             "-c", "core.hooksPath=", *args], cwd=root, capture_output=True, check=True)
    return result.stdout.decode("utf-8").strip()


def snapshot(revision, candidate=False):
    return {"utc": "2026-10-03T00:00:00+00:00", "revision": revision, "dirty": False,
            "rom_sha1": ROM_SHA1, "report_sha256": "fixture-arm9", "arm7_report_sha256": "fixture-arm7",
            "token_usage": None,
            "arm9": {"total_code": 1000, "total_data": 100, "total_functions": 10,
                     "matched_code": 110 if candidate else 100, "matched_data": 10,
                     "matched_functions": 2 if candidate else 1},
            "arm7": {"payload_bytes": 200, "source_functions": 1, "source_code_bytes": 10,
                     "source_literal_pool_bytes": 0, "source_data_bytes": 0, "source_bss_bytes": 0,
                     "reviewed_assembly_bytes": 0, "binary_fallback_bytes": 190}}


@unittest.skipUnless(shutil.which("git"), "Git unavailable")
class IntegrationTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name).resolve() / "main"
        self.root.mkdir()
        self.workspace = self.root.parent / "stages"
        git(self.root, "init", "-b", "main")
        self.write(".gitignore", "build/\nextract/\n*.nds\n/dsd\n/dsd.exe\n/objdiff-cli\n/objdiff-cli.exe\n")
        self.write("src/Overlay/Family.cpp", "int Family() { return 1; }\n")
        git(self.root, "add", ".")
        git(self.root, "commit", "-m", "fixture baseline")
        self.base = git(self.root, "rev-parse", "HEAD")
        self.initial = self.base
        self.suffix = ".exe" if os.name == "nt" else ""
        self.tools = {"python": "fixture-python", "ninja": "fixture-ninja", "compiler": "fixture-compiler",
                      "hashes": {"dsd" + self.suffix: TOOL_HASH, "objdiff-cli" + self.suffix: TOOL_HASH}}
        self.write("extract/baserom_dqix_usa.nds", ROM)
        for name in self.tools["hashes"]:
            self.write(name, TOOL)
        git(self.root, "checkout", "-b", "worker")
        self.write("src/Overlay/Family.cpp", "int Family() { return 2; }\n")
        git(self.root, "add", "src/Overlay/Family.cpp")
        git(self.root, "commit", "-m", "fixture candidate")
        self.tip = git(self.root, "rev-parse", "HEAD")
        git(self.root, "checkout", "main")
        self.submission = {"id": "submission-1", "lane": "overlay-000", "module": "ov000",
                           "base_revision": self.base, "source_tip": self.tip, "commits": [self.tip]}
        self.review = {"verdict": "approved", "source_tip": self.tip, "base_revision": self.base, "findings": []}
        self.builds = []

    def write(self, relative, content):
        path = self.root / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(content) if isinstance(content, bytes) else path.write_text(content, encoding="utf-8")
        return path

    def prepare(self, root, stage):
        destination = stage / "extract/baserom_dqix_usa.nds"
        destination.parent.mkdir()
        shutil.copy2(root / "extract/baserom_dqix_usa.nds", destination)
        for name in self.tools["hashes"]:
            shutil.copy2(root / name, stage / name)
        return copy.deepcopy(self.tools)

    def build(self, runner, stage, tools, label):
        # Assertion proves neither baseline nor candidate acceptance advances main.
        self.assertEqual(git(self.root, "rev-parse", "HEAD"), self.initial)
        self.builds.append((label, str(stage)))
        (stage / "dqix_usa.nds").write_bytes(ROM)
        return snapshot(git(stage, "rev-parse", "HEAD"), label == "candidate")

    def integrate(self, builder=None):
        with patch.object(gate, "USA_SHA1", ROM_SHA1), patch.object(gate, "prepare_stage", side_effect=self.prepare), \
                patch.object(gate, "tools_state", return_value=copy.deepcopy(self.tools)), \
                patch.object(gate, "build_stage", side_effect=builder or self.build):
            return gate.integrate(self.root, self.submission, self.review, self.workspace)

    def test_real_git_ff_only_after_both_checks_and_immutable_manifest(self):
        result = self.integrate()
        self.assertEqual(result["status"], "accepted", result.get("error"))
        self.assertTrue(result["accepted"])
        self.assertEqual([item[0] for item in self.builds], ["baseline", "candidate"])
        self.assertEqual(git(self.root, "rev-parse", "HEAD"), result["stage_revision"])
        self.assertEqual(result["snapshot"]["revision"], result["accepted_revision"])
        self.assertEqual(result["before"]["revision"], self.base)
        self.assertEqual(result["delta"]["arm9"]["matched_code"], 10)
        self.assertEqual((self.root / "src/Overlay/Family.cpp").read_text(), "int Family() { return 2; }\n")
        manifest = Path(result["manifest_path"])
        self.assertEqual(json.loads(manifest.read_text())["accepted_revision"], result["stage_revision"])
        with self.assertRaises(FileExistsError):
            manifest.open("x")
        self.assertFalse(git(self.root, "status", "--porcelain"))

    def test_failed_candidate_checks_never_advance_main(self):
        def fail(runner, stage, tools, label):
            if label == "candidate":
                raise ValueError("fixture full check failure")
            return self.build(runner, stage, tools, label)
        result = self.integrate(fail)
        self.assertEqual(result["status"], "needs_changes")
        self.assertIn("full check failure", result["error"])
        self.assertEqual(git(self.root, "rev-parse", "HEAD"), self.base)
        self.assertTrue(Path(result["stage"]).is_dir())

    def test_denominator_reduction_and_regression_rejected(self):
        for field, value in (("total_code", 999), ("matched_code", 99)):
            def invalid(runner, stage, tools, label):
                record = self.build(runner, stage, tools, label)
                if label == "candidate":
                    record["arm9"][field] = value
                return record
            with self.subTest(field=field):
                result = self.integrate(invalid)
                self.assertFalse(result["accepted"])
                self.assertEqual(git(self.root, "rev-parse", "HEAD"), self.base)

    def test_stale_main_head_is_preserved_without_ff(self):
        advanced = []
        def changed(runner, stage, tools, label):
            record = self.build(runner, stage, tools, label)
            if label == "candidate":
                self.write("docs/workflow/external.md", "A separately committed main change.\n")
                git(self.root, "add", "docs/workflow/external.md")
                git(self.root, "commit", "-m", "external advancement")
                advanced.append(git(self.root, "rev-parse", "HEAD"))
            return record
        result = self.integrate(changed)
        self.assertFalse(result["accepted"])
        self.assertIn("main HEAD changed", result["error"])
        self.assertEqual(git(self.root, "rev-parse", "HEAD"), advanced[0])
        self.assertEqual((self.root / "src/Overlay/Family.cpp").read_text(), "int Family() { return 1; }\n")

    def test_dirty_main_user_changes_are_preserved(self):
        self.write("src/Overlay/Family.cpp", "User change must survive.\n")
        result = self.integrate()
        self.assertFalse(result["accepted"])
        self.assertEqual((self.root / "src/Overlay/Family.cpp").read_text(), "User change must survive.\n")
        self.assertNotIn("stage", result)

    def test_exact_review_and_commit_chain_required(self):
        for change in ({"source_tip": self.base}, {"verdict": "changes_requested"}, {"findings": ["unresolved"]}, {"extra": "metadata"}):
            old = copy.deepcopy(self.review)
            self.review.update(change)
            result = self.integrate()
            self.assertFalse(result["accepted"])
            self.assertNotIn("stage", result)
            self.review = old
        self.submission["commits"] = [self.base, self.tip]
        result = self.integrate()
        self.assertFalse(result["accepted"])
        self.assertIn("linear chain", result["error"])

    def test_disallowed_pipeline_and_binary_source_commits_rejected(self):
        for path, content in (("tools/not_allowed.py", "pass\n"), ("docs/workflow/queue.json", "{}\n"),
                              ("src/Overlay/Bytes.cpp", b"int x;\0binary")):
            git(self.root, "checkout", "worker")
            self.write(path, content)
            git(self.root, "add", "--", path)
            git(self.root, "commit", "-m", "disallowed fixture")
            tip = git(self.root, "rev-parse", "HEAD")
            commits = git(self.root, "rev-list", "--reverse", self.base + ".." + tip).splitlines()
            git(self.root, "checkout", "main")
            self.submission.update(source_tip=tip, commits=commits)
            self.review["source_tip"] = tip
            result = self.integrate()
            self.assertFalse(result["accepted"])
            self.assertNotIn("stage", result)

    def test_conflict_preserves_stage_and_main(self):
        self.write("src/Overlay/Family.cpp", "int Family() { return 3; }\n")
        git(self.root, "add", "src/Overlay/Family.cpp")
        git(self.root, "commit", "-m", "main conflicting change")
        self.initial = git(self.root, "rev-parse", "HEAD")
        result = self.integrate()
        self.assertFalse(result["accepted"])
        self.assertEqual(git(self.root, "rev-parse", "HEAD"), self.initial)
        self.assertIn("<<<<<<<", (Path(result["stage"]) / "src/Overlay/Family.cpp").read_text())
        self.assertEqual([item[0] for item in self.builds], ["baseline"])

    def test_snapshot_revision_must_describe_stage_head(self):
        def wrong(runner, stage, tools, label):
            record = self.build(runner, stage, tools, label)
            if label == "candidate":
                record["revision"] = self.base
            return record
        result = self.integrate(wrong)
        self.assertFalse(result["accepted"])
        self.assertIn("snapshot does not describe", result["error"])
        self.assertEqual(git(self.root, "rev-parse", "HEAD"), self.base)

    def test_allowlist_is_module_specific_and_rejects_path_escape(self):
        for path in ("src/Family.cpp", "include/Family.h", "config/usa/arm9/overlays/ov000/delinks.txt", "docs/workflow/note.md"):
            self.assertTrue(gate.allowed_path(path, "ov000"), path)
        for path in ("AGENTS.md", "GOALS.md", "tools/factory.py", "src/../../tools/f.py", "src/Family.bin",
                     "config/usa/arm9/overlays/ov001/symbols.txt", "config/usa/arm9/overlays/ov000/relocs.txt",
                     "docs/workflow/QUEUE.JSON"):
            self.assertFalse(gate.allowed_path(path, "ov000"), path)

    def test_integration_socket_lock_exclusive_and_released(self):
        with gate.IntegrationLock(self.root):
            with self.assertRaises(ValueError):
                with gate.IntegrationLock(self.root):
                    pass
        with gate.IntegrationLock(self.root):
            pass

    def test_prepare_stage_copies_verified_input_and_tools_without_aliases(self):
        stage = self.root.parent / "copy-stage"
        stage.mkdir()
        with patch.object(gate, "USA_SHA1", ROM_SHA1), patch.object(gate, "tools_state", return_value=self.tools):
            state = gate.prepare_stage(self.root, stage)
        original, copied = self.root / "extract/baserom_dqix_usa.nds", stage / "extract/baserom_dqix_usa.nds"
        self.assertEqual(copied.read_bytes(), ROM)
        self.assertFalse(original.samefile(copied))
        self.assertEqual(copied.stat().st_nlink, 1)
        for name, expected in state["hashes"].items():
            self.assertEqual(gate.digest(stage / name), expected)
            self.assertFalse((self.root / name).samefile(stage / name))

    def test_wrong_input_sha_rejected_before_stage_copy(self):
        stage = self.root.parent / "invalid-copy-stage"
        stage.mkdir()
        with patch.object(gate, "tools_state", return_value=self.tools):
            with self.assertRaisesRegex(ValueError, "input SHA1"):
                gate.prepare_stage(self.root, stage)
        self.assertFalse((stage / "extract").exists())

    def test_exact_full_acceptance_commands_and_snapshot_guards(self):
        calls = []
        class Recorder:
            def run(self, argv, cwd, **kwargs):
                calls.append((argv, cwd, kwargs))
        stage = self.root.parent / "command-stage"
        with patch.object(gate, "USA_SHA1", ROM_SHA1), \
                patch.object(gate.work_batch, "capture", return_value=snapshot(self.base)):
            gate.build_stage(Recorder(), stage, self.tools, "baseline")
        self.assertEqual(calls[0][0][:4], ["fixture-python", "tools/configure.py", "usa", "--compiler"])
        self.assertEqual(calls[1][0], ["fixture-ninja", "-j", "2", "rom", "check", "report", "sha1"])
        self.assertEqual(calls[0][2]["env"]["PYTHONDONTWRITEBYTECODE"], "1")
        wrong = snapshot(self.base)
        wrong["dirty"] = True
        with patch.object(gate.work_batch, "capture", return_value=wrong):
            with self.assertRaises(ValueError):
                gate.build_stage(Recorder(), stage, self.tools, "candidate")


if __name__ == "__main__":
    unittest.main()
