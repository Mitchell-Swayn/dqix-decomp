"""Tests for ARM7 BIOS-call veneer target recognition."""

import json
from pathlib import Path
import unittest

from audit_arm7_bios_stubs import inspect_thumb_swi_stub, load_verified

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "extract/baserom_dqix_usa.nds"


class ThumbSwiStubTests(unittest.TestCase):
    def test_divide_swi_stub(self):
        result = inspect_thumb_swi_stub(bytes.fromhex("06 df 70 47"), 0x03803ebe)
        self.assertEqual((result["swi"], result["size"]), (6, 4))

    def test_swi_14_stub(self):
        result = inspect_thumb_swi_stub(bytes.fromhex("0e df 70 47"), 0x03803ef0)
        self.assertEqual((result["swi"], result["size"]), (14, 4))

    def test_rejects_nonreturning_or_longer_code(self):
        with self.assertRaisesRegex(ValueError, "bx lr"):
            inspect_thumb_swi_stub(bytes.fromhex("06 df 00 46"), 0x03803ebe)
        with self.assertRaisesRegex(ValueError, "exactly four"):
            inspect_thumb_swi_stub(bytes.fromhex("06 df 70 47 00 00"), 0x03803ebe)

    def test_rejects_odd_thumb_pointer_value_as_start_address(self):
        with self.assertRaisesRegex(ValueError, "halfword-aligned"):
            inspect_thumb_swi_stub(bytes.fromhex("06 df 70 47"), 0x03803ebf)


@unittest.skipUnless(ROM.exists(), "original USA ROM input is not installed")
class VerifiedRomSwiReferenceTests(unittest.TestCase):
    def test_veneers_resolve_to_expected_thumb_swi_stubs(self):
        results = load_verified(
            ROM, ROOT / "config/usa/arm7/baseline.json",
            ROOT / "config/usa/arm7/source_units.json")
        self.assertEqual([item["literal_value"] for item in results],
                         [0x03803ef1, 0x03803ebf])
        self.assertEqual([item["stub"]["swi"] for item in results], [14, 6])
        self.assertEqual([item["call_sites"] for item in results],
                         [[0x037f80b4, 0x037f80e0, 0x037f8180], [0x037f8450]])
        sidecar = json.loads((ROOT / "config/usa/arm7/inventory_ranges.json").read_text())
        scopes = {scope["name"]: scope for scope in sidecar["scopes"]}
        for scope_name, target in (("wram_bios_swi_14_stub", results[0]),
                                   ("wram_bios_swi_6_stub", results[1])):
            scope = scopes[scope_name]
            self.assertEqual(int(scope["runtime_address"], 16), target["stub"]["address"])
            self.assertEqual(int(scope["payload_offset"], 16), target["payload_offset"])
            self.assertEqual(int(scope["size"], 16), target["stub"]["size"])


if __name__ == "__main__":
    unittest.main()
