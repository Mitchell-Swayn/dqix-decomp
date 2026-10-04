"""Focused CLI tests; schema examples reduced from local objdiff-cli 2.7.1 output."""
import copy
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

import match_unit


UNIT = {"name": "src/System/RuntimeRandom",
        "target_path": "build/usa/delinks/src/System/RuntimeRandom.o",
        "base_path": "build/usa/src/System/RuntimeRandom.o",
        "scratch": {"platform": "nds_arm9"}}

# Protobuf JSON omits default indices and DIFF_NONE, and encodes sizes as strings.
MATCHED = {"left": {"sections": [{"name": ".text", "symbols": [
    {"symbol": {"name": ".text", "flags": 2}},
    {"symbol": {"name": "rand", "size": "52", "flags": 1},
     "instructions": [{"instruction": {"size": 4, "formatted": "ldr r2, [pc, #0x20]"},
                       "arg_diff": [{}, {}, {}]}],
     "match_percent": 100.0, "target": {"section_index": 0, "symbol_index": 0}}]}]},
    "right": {"sections": [{"name": ".text", "symbols": [
        {"symbol": {"name": "rand", "size": "52", "flags": 1},
         "match_percent": 100.0, "target": {"section_index": 0, "symbol_index": 1}}]}]}}


class SelectionTests(unittest.TestCase):
    def test_exact_selection(self):
        config = {"units": [UNIT]}
        self.assertEqual(match_unit.select_unit(config, UNIT["name"]), UNIT)
        for name in ("RuntimeRandom", "src/System/runtimerandom", "../src/System/RuntimeRandom"):
            with self.assertRaises(ValueError):
                match_unit.select_unit(config, name)

    def test_missing_duplicate_and_non_candidate(self):
        for config in ({}, {"units": None}, {"units": [UNIT, UNIT]},
                       {"units": [{"name": UNIT["name"]}]},
                       {"units": [{**UNIT, "scratch": {"platform": "nds_arm7"}}]}):
            with self.assertRaises(ValueError):
                match_unit.select_unit(config, UNIT["name"])


class PathTests(unittest.TestCase):
    def test_escape_and_non_object_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for candidate in ("../outside.o", "build/../../outside.o", "build/usa/main.nds",
                              "build/usa/delinks/original.o", "build/usa/arm9.o"):
                with self.assertRaises(ValueError):
                    match_unit.object_paths(root, {**UNIT, "base_path": candidate})
            with self.assertRaises(ValueError):
                match_unit.object_paths(root, {**UNIT, "target_path": UNIT["base_path"]})

    def test_unique_attempts_under_build(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            first, second = match_unit.new_attempt(root), match_unit.new_attempt(root)
            self.assertNotEqual(first, second)
            self.assertEqual(first.parent, root / "build" / "matching")
            self.assertTrue(first.is_dir())


class SummaryTests(unittest.TestCase):
    def test_matched_schema_and_omitted_defaults(self):
        rows = match_unit.summarize(MATCHED)
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]["match_percent"], 100)
        self.assertEqual(rows[0]["differences"], [])

    def test_instruction_and_unpaired_schema(self):
        document = copy.deepcopy(MATCHED)
        symbol = document["left"]["sections"][0]["symbols"][1]
        symbol["match_percent"] = 24.5
        symbol["instructions"] = [
            {"diff_kind": "DIFF_REPLACE", "instruction": {
                "size": 4, "formatted": "stmdb sp!, {r4, r5, r6, r7, r8, r9, r10, lr}"}},
            {"diff_kind": "DIFF_ARG_MISMATCH", "instruction": {
                "address": "16", "formatted": "mov r4, r1"}, "arg_diff": [{}, {"diff_index": 0}]}]
        document["right"]["sections"][0]["symbols"].append(
            {"symbol": {"name": "extra", "size": "4", "flags": 1}})
        rows = match_unit.summarize(document, 1)
        self.assertEqual(len(rows), 2)
        self.assertTrue(rows[0]["differences"][0].startswith("DIFF_REPLACE @0x0"))
        self.assertFalse(rows[1]["paired"])
        self.assertEqual(rows[1]["match_percent"], 0)

    def test_malformed_output(self):
        for document in (None, {}, {"left": {}, "right": {}},
                         {"left": {"sections": []}, "right": {"sections": []}}):
            with self.assertRaises(ValueError):
                match_unit.summarize(document)
        for percent in (-1, 101, "100", float("nan"), True):
            document = copy.deepcopy(MATCHED)
            document["left"]["sections"][0]["symbols"][1]["match_percent"] = percent
            with self.assertRaises(ValueError):
                match_unit.summarize(document)


class WorkflowTests(unittest.TestCase):
    def test_missing_candidate_is_recorded_without_build(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "objdiff.json").write_text(json.dumps({"units": [UNIT]}))
            target = root / UNIT["target_path"]
            target.parent.mkdir(parents=True)
            target.write_bytes(b"original")
            with patch.object(match_unit, "ROOT", root), patch.object(match_unit, "run_logged") as run:
                self.assertEqual(match_unit.main([UNIT["name"], "--no-build"]), 2)
                run.assert_not_called()
            record = json.loads((root / "build/matching/attempts.jsonl").read_text())
            self.assertEqual(record["status"], "error")
            self.assertIn("candidate object missing", record["error"])
            self.assertEqual(target.read_bytes(), b"original")

    def test_malformed_configuration_does_not_run_commands(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "objdiff.json").write_text("{broken")
            with patch.object(match_unit, "ROOT", root), patch.object(match_unit, "run_logged") as run:
                self.assertEqual(match_unit.main([UNIT["name"]]), 2)
                run.assert_not_called()

    def test_only_candidate_build_and_record(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "objdiff.json").write_text(json.dumps({"units": [UNIT]}))
            for filename in (UNIT["target_path"], UNIT["base_path"],
                             ".venv/Scripts/ninja.exe", ".venv/bin/ninja"):
                path = root / filename
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(b"object")
            commands = []

            def run(command, cwd, attempt, label):
                commands.append(command)
                if label == "objdiff":
                    (attempt / "diff.json").write_text(json.dumps(MATCHED))

            with patch.object(match_unit, "ROOT", root), patch.object(match_unit, "run_logged", run):
                self.assertEqual(match_unit.main([UNIT["name"]]), 0)
                self.assertEqual(commands[0][1:], [UNIT["base_path"]])
                self.assertEqual(commands[1][1], "diff")
                commands.clear()
                self.assertEqual(match_unit.main([UNIT["name"], "--no-build"]), 0)
                self.assertEqual(len(commands), 1)
            records = [json.loads(line) for line in (root / "build/matching/attempts.jsonl").read_text().splitlines()]
            self.assertEqual(len(records), 2)
            self.assertFalse(records[0]["rom_acceptance"])
            self.assertEqual(records[0]["target_sha256_before"], records[0]["target_sha256_after"])
            self.assertGreaterEqual(records[0]["elapsed_seconds"], 0)


if __name__ == "__main__":
    unittest.main()
