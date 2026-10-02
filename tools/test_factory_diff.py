"""Objdiff schema fixtures verify useful heuristics and conservative unknowns."""
import copy
import json
from pathlib import Path
import tempfile
import unittest

import factory_diff as diff


def document(left="mov r1, #0x4", right="mov r2, #0x8", kind="DIFF_ARG_MISMATCH"):
    return {"left": {"sections": [{"name": ".text", "symbols": [{
        "symbol": {"name": "Func", "size": "4", "flags": 1}, "match_percent": 50,
        "target": {}, "instructions": [{"diff_kind": kind, "instruction": {"formatted": left}}]}]}]},
        "right": {"sections": [{"name": ".text", "symbols": [{
            "symbol": {"name": "Func", "size": "4", "flags": 1}, "match_percent": 50,
            "target": {}, "instructions": [{"diff_kind": kind, "instruction": {"formatted": right}}]}]}]}}


class DiffTests(unittest.TestCase):
    def test_register_and_immediate_observations(self):
        result = diff.classify(document())
        self.assertEqual(result["mismatched_symbols"], 1)
        self.assertEqual(result["symbols"][0]["categories"], ["register", "immediate"])
        self.assertEqual(result["symbols"][0]["evidence"][0]["counterpart"], "mov r2, #0x8")
        self.assertIn("no semantic proof", result["notice"])

    def test_stack_and_branch_categories(self):
        cases = [("sub sp, sp, #0x10", "sub sp, sp, #0x20", "stack"),
                 ("push {r4, lr}", "push {r5, lr}", "stack"),
                 ("bne #0x8", "beq #0x8", "control-flow"),
                 ("blx r1", "blx r2", "control-flow"),
                 ("bic r0, r0, #0x8", "bic r0, r0, #0x4", "immediate")]
        for left, right, category in cases:
            with self.subTest(left=left):
                labels = diff.classify(document(left, right))["symbols"][0]["categories"]
                self.assertIn(category, labels)
                if left.startswith("bic"):
                    self.assertNotIn("control-flow", labels)

    def test_changed_relocation_and_unchanged_relocation(self):
        value = document("bl #0x0", "bl #0x0")
        a = value["left"]["sections"][0]["symbols"][0]["instructions"][0]["instruction"]
        b = value["right"]["sections"][0]["symbols"][0]["instructions"][0]["instruction"]
        a["relocation"] = {"type": 1, "target": {"symbol": {"name": "A"}, "addend": "-8"}}
        b["relocation"] = {"type": 1, "target": {"symbol": {"name": "B"}, "addend": "-8"}}
        result = diff.classify(value)
        self.assertIn("relocation", result["symbols"][0]["categories"])
        b["relocation"] = copy.deepcopy(a["relocation"])
        self.assertNotIn("relocation", diff.classify(value)["symbols"][0]["categories"])

    def test_inserted_row_and_no_instruction_evidence(self):
        value = document("", "mov r0, r1", "DIFF_INSERT")
        value["left"]["sections"][0]["symbols"][0]["instructions"][0].pop("instruction")
        result = diff.classify(value)
        self.assertEqual(result["symbols"][0]["categories"], ["unknown"])
        value["left"]["sections"][0]["symbols"][0]["instructions"] = []
        result = diff.classify(value)
        self.assertEqual(result["symbols"][0]["categories"], ["unknown"])

    def test_matched_symbols_skipped_and_defaults_supported(self):
        value = document(kind="DIFF_NONE")
        for side in ("left", "right"):
            value[side]["sections"][0]["symbols"][0]["match_percent"] = 100
            value[side]["sections"][0]["symbols"][0]["instructions"][0].pop("diff_kind")
        result = diff.classify(value)
        self.assertEqual(result["mismatched_symbols"], 0)
        self.assertEqual(result["category_counts"]["unknown"], 0)

    def test_unpaired_candidate_and_section_marker(self):
        value = document(kind=0)
        for side in ("left", "right"):
            value[side]["sections"][0]["symbols"][0]["match_percent"] = 100
        value["right"]["sections"][0]["symbols"].extend([
            {"symbol": {"name": ".text", "flags": 2}},
            {"symbol": {"name": "Extra", "size": "4"}}])
        result = diff.classify(value)
        self.assertEqual(result["mismatched_symbols"], 1)
        self.assertEqual(result["symbols"][0]["side"], "candidate")
        self.assertEqual(result["symbols"][0]["symbol"], "Extra")

    def test_invalid_schema_and_target(self):
        for value in (None, {}, {"left": {}, "right": {}}):
            with self.assertRaises(ValueError):
                diff.classify(value)
        for target in ({"section_index": -1}, {"symbol_index": 99}):
            value = document()
            value["left"]["sections"][0]["symbols"][0]["target"] = target
            with self.assertRaises(ValueError):
                diff.classify(value)
        for percent in (True, -1, 101, "50"):
            value = document()
            value["left"]["sections"][0]["symbols"][0]["match_percent"] = percent
            with self.assertRaises(ValueError):
                diff.classify(value)

    def test_cli_json_and_input_preservation(self):
        with tempfile.TemporaryDirectory() as directory:
            source, output = Path(directory) / "diff.json", Path(directory) / "classified.json"
            source.write_text(json.dumps(document()), encoding="utf-8")
            before = source.read_bytes()
            self.assertEqual(diff.main([str(source), "--output", str(output)]), 0)
            self.assertEqual(json.loads(output.read_text())["mismatched_symbols"], 1)
            self.assertEqual(diff.main([str(source), "--output", str(source)]), 2)
            self.assertEqual(source.read_bytes(), before)


if __name__ == "__main__":
    unittest.main()
