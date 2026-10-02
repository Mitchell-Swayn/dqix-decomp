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

    def test_source_unit_overlap_is_rejected(self):
        inventory = copy.deepcopy(self.inventory)
        scope = inventory["scopes"][1]
        scope["size"] = "0x4bc"
        scope["ranges"][-1]["size"] = "0x8"
        scope["totals"]["literal_pool"] += 4
        with self.assertRaisesRegex(ValueError, "overlaps source unit"):
            validate_inventory(inventory, self.baseline, self.config)

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


