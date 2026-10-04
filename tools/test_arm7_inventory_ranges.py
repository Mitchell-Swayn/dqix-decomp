"""Regression tests for explicit ARM7 inventory partitions."""

import copy
import json
from pathlib import Path
import unittest

from arm7_inventory_ranges import validate_inventory

ROOT = Path(__file__).resolve().parent.parent


class Arm7InventoryRangeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.inventory = json.loads((ROOT / "config/usa/arm7/inventory_ranges.json").read_text())
        cls.baseline = json.loads((ROOT / "config/usa/arm7/baseline.json").read_text())
        cls.config = json.loads((ROOT / "config/usa/arm7/source_units.json").read_text())

    def test_confirmed_startup_and_entry_scopes_reconcile(self):
        self.assertTrue(validate_inventory(self.inventory, self.baseline, self.config))

    def test_gap_or_overlap_in_scope_is_rejected(self):
        inventory = copy.deepcopy(self.inventory)
        inventory["scopes"][1]["ranges"][1]["payload_offset"] = "0x695"
        with self.assertRaisesRegex(ValueError, "contiguous"):
            validate_inventory(inventory, self.baseline, self.config)

    def test_legitimate_reconstructed_source_overlap_is_accepted(self):
        config = copy.deepcopy(self.config)
        config["units"].append({
            "name": "ReconstructedEntryHead", "autoload": "wram",
            "payload_offset": 0x21c, "runtime_address": 0x037f8000, "size": 4,
            "code_bytes": 4, "literal_pool_bytes": 0, "data_bytes": 0,
        })
        self.assertTrue(validate_inventory(self.inventory, self.baseline, config))

    def test_inventory_scopes_remain_disjoint(self):
        inventory = copy.deepcopy(self.inventory)
        duplicate = copy.deepcopy(inventory["scopes"][0])
        duplicate["name"] = "duplicate_startup_evidence"
        inventory["scopes"].append(duplicate)
        with self.assertRaisesRegex(ValueError, "inventory scopes overlap"):
            validate_inventory(inventory, self.baseline, self.config)

    def test_missing_sha1_values_are_rejected_even_when_both_are_missing(self):
        inventory = copy.deepcopy(self.inventory)
        baseline = copy.deepcopy(self.baseline)
        inventory["source_rom_sha1"] = None
        baseline["source_rom_sha1"] = None
        with self.assertRaisesRegex(ValueError, "40-character SHA-1"):
            validate_inventory(inventory, baseline, self.config)
        inventory = copy.deepcopy(self.inventory)
        baseline = copy.deepcopy(self.baseline)
        inventory["payload_sha1"] = None
        baseline["payload_sha1"] = None
        with self.assertRaisesRegex(ValueError, "40-character SHA-1"):
            validate_inventory(inventory, baseline, self.config)

    def test_classification_accounting_must_match_byte_ranges(self):
        inventory = copy.deepcopy(self.inventory)
        inventory["scopes"][0]["totals"]["instruction"] += 4
        with self.assertRaisesRegex(ValueError, "totals"):
            validate_inventory(inventory, self.baseline, self.config)

    def test_scope_cannot_exceed_its_autoload(self):
        inventory = copy.deepcopy(self.inventory)
        inventory["scopes"][1]["size"] = "0x11000"
        with self.assertRaisesRegex(ValueError, "outside its configured"):
            validate_inventory(inventory, self.baseline, self.config)

    def test_unknown_bytes_cannot_be_labeled_with_fake_class(self):
        inventory = copy.deepcopy(self.inventory)
        inventory["scopes"][0]["ranges"][0]["classification"] = "unknown-is-code"
        with self.assertRaisesRegex(ValueError, "unknown classification"):
            validate_inventory(inventory, self.baseline, self.config)


if __name__ == "__main__":
    unittest.main()


