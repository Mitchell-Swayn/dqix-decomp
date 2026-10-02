"""Tests for tools/disassemble_arm7.py."""

import copy
import json
from pathlib import Path
import unittest

from disassemble_arm7 import (address_to_payload, disassemble_bytes, exact_source_unit,
                              manifest_range_lines)


ROOT = Path(__file__).resolve().parent.parent


class Arm7AddressMappingTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.baseline = json.loads((ROOT / "config/usa/arm7/baseline.json").read_text())
        cls.config = json.loads((ROOT / "config/usa/arm7/source_units.json").read_text())

    def test_startup_maps_from_rom_payload_offset_zero(self):
        start = self.baseline["load_address"]
        mapped = address_to_payload(start, start + 8, self.baseline, self.config)
        self.assertEqual((mapped.module, mapped.payload_start, mapped.payload_end),
                         ("startup", 0, 8))

    def test_wram_autoload_accounts_for_540_byte_startup_prefix(self):
        wram = next(module for module in self.config["autoloads"] if module["name"] == "wram")
        mapped = address_to_payload(wram["runtime_address"], wram["runtime_address"] + 8,
                                     self.baseline, self.config)
        self.assertEqual((mapped.payload_start, mapped.payload_end), (540, 548))

    def test_mainram_autoload_uses_manifest_payload_offset(self):
        mainram = next(module for module in self.config["autoloads"] if module["name"] == "mainram")
        mapped = address_to_payload(mainram["runtime_address"], mainram["runtime_address"] + 4,
                                     self.baseline, self.config)
        self.assertEqual((mapped.module, mapped.payload_start, mapped.payload_end),
                         ("mainram", 69712, 69716))

    def test_end_exclusive_autoload_boundary_is_accepted(self):
        wram = next(module for module in self.config["autoloads"] if module["name"] == "wram")
        end = wram["runtime_address"] + wram["size"]
        mapped = address_to_payload(end - 4, end, self.baseline, self.config)
        self.assertEqual(mapped.payload_end, wram["payload_offset"] + wram["size"])
        with self.assertRaisesRegex(ValueError, "unmapped"):
            address_to_payload(end, end + 4, self.baseline, self.config)

    def test_ranges_crossing_mapping_boundaries_are_rejected(self):
        wram = next(module for module in self.config["autoloads"] if module["name"] == "wram")
        end = wram["runtime_address"] + wram["size"]
        with self.assertRaisesRegex(ValueError, "crosses"):
            address_to_payload(end - 4, end + 4, self.baseline, self.config)

    def test_reversed_empty_and_unmapped_ranges_are_rejected(self):
        start = self.baseline["load_address"]
        with self.assertRaisesRegex(ValueError, "nonempty"):
            address_to_payload(start + 8, start + 8, self.baseline, self.config)
        with self.assertRaisesRegex(ValueError, "nonempty"):
            address_to_payload(start + 8, start, self.baseline, self.config)
        with self.assertRaisesRegex(ValueError, "unmapped"):
            address_to_payload(0x03000000, 0x03000004, self.baseline, self.config)

    def test_truncated_autoload_mapping_is_rejected(self):
        config = copy.deepcopy(self.config)
        config["autoloads"][0]["payload_offset"] = self.baseline["size"] - 4
        with self.assertRaisesRegex(ValueError, "exceeds ARM7 payload"):
            address_to_payload(self.baseline["load_address"], self.baseline["load_address"] + 4,
                               self.baseline, config)

    def test_manifest_partition_annotation_requires_exact_unit_match(self):
        config = {"units": [{"name": "known", "source": "known.c",
                             "runtime_address": 0x038056ac, "size": 36,
                             "code_bytes": 32, "literal_pool_bytes": 4}]}
        self.assertEqual(exact_source_unit(0x038056ac, 0x038056d0, config)["literal_pool_bytes"], 4)
        self.assertIsNone(exact_source_unit(0x038056ac, 0x038056cc, config))

    def test_manifest_literal_pool_is_not_decoded_as_an_instruction(self):
        unit = {"code_bytes": 4, "literal_pool_bytes": 4, "data_bytes": 0,
                "reviewed_assembly_bytes": 0}
        data = bytes.fromhex("00 00 a0 e1 c2 01 00 04")
        lines = manifest_range_lines(data, 0x038056ac, "arm", unit)
        self.assertIn("mov", lines[0])
        self.assertIn(".literal", lines[1])
        self.assertNotIn("streq", lines[1])

    def test_unannotated_range_remains_raw_disassembly(self):
        lines = manifest_range_lines(bytes.fromhex("c2 01 00 04"), 0x038056ac, "arm", None)
        self.assertIn("streq", lines[0])

    def test_arm_and_thumb_modes_decode_explicitly(self):
        arm = disassemble_bytes(bytes.fromhex("00 00 a0 e1"), 0x02000000, "arm")
        thumb = disassemble_bytes(bytes.fromhex("00 bf"), 0x02000000, "thumb")
        self.assertIn("mov", arm[0])
        self.assertIn("nop", thumb[0])

    def test_unaligned_mode_range_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "aligned"):
            disassemble_bytes(bytes.fromhex("00 00 a0 e1"), 0x02000002, "arm")


if __name__ == "__main__":
    unittest.main()
