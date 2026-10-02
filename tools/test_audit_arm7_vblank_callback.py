"""Tests for reference-backed ARM7 VBlank callback inventory."""

import json
from pathlib import Path
import struct
import unittest

from audit_arm7_vblank_callback import CALLBACK, audit_callback, inspect_callback
from disassemble_arm7 import address_to_payload, load_original

ROOT = Path(__file__).resolve().parent.parent
ROM = ROOT / "extract/baserom_dqix_usa.nds"
CALLBACK_BYTES = bytes.fromhex(
    "08402de9 14009fe5 000090e5 000050e3 0000000a a83700eb "
    "0840bde8 1eff2fe1 6cb78003")


class CallbackBoundaryTests(unittest.TestCase):
    def test_both_paths_return_before_literal(self):
        result = inspect_callback(CALLBACK_BYTES)
        self.assertEqual(result["reachable_instructions"], list(range(CALLBACK, CALLBACK + 32, 4)))
        self.assertEqual(result["literal_address"], CALLBACK + 32)
        self.assertEqual(result["literal_value"], 0x0380B76C)
        self.assertEqual(result["external_call"], 0x038063AC)

    def test_rejects_branch_into_literal(self):
        changed = bytearray(CALLBACK_BYTES)
        struct.pack_into("<I", changed, 16, 0x0A000002)
        with self.assertRaisesRegex(ValueError, "branch or literal"):
            inspect_callback(changed)

    def test_rejects_nonreturning_exit(self):
        changed = bytearray(CALLBACK_BYTES)
        struct.pack_into("<I", changed, 28, 0xE12FFF10)
        with self.assertRaisesRegex(ValueError, "register/return"):
            inspect_callback(changed)

    def test_rejects_call_into_literal_pool(self):
        changed = bytearray(CALLBACK_BYTES)
        struct.pack_into("<I", changed, 20, 0xEB000001)
        with self.assertRaisesRegex(ValueError, "external ARM routine"):
            inspect_callback(changed)

    def test_rejects_wrong_extent_or_mode_alignment(self):
        for data, address in ((CALLBACK_BYTES[:32], CALLBACK), (CALLBACK_BYTES, CALLBACK + 2)):
            with self.assertRaisesRegex(ValueError, "36 bytes"):
                inspect_callback(data, address)


@unittest.skipUnless(ROM.exists(), "original USA ROM input is not installed")
class VerifiedReferenceTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.payload, cls.baseline, cls.config = load_original(
            ROM, ROOT / "config/usa/arm7/baseline.json",
            ROOT / "config/usa/arm7/source_units.json")

    def test_rom_reference_chain_agrees_with_sidecar(self):
        result = audit_callback(self.payload, self.baseline, self.config)
        sidecar = json.loads((ROOT / "config/usa/arm7/inventory_ranges.json").read_text())
        scope = next(s for s in sidecar["scopes"] if s["name"] == "wram_startup_vblank_callback")
        self.assertEqual(int(scope["runtime_address"], 16), result["address"])
        self.assertEqual(int(scope["payload_offset"], 16), result["payload_offset"])
        self.assertEqual(int(scope["size"], 16), 36)
        self.assertEqual(scope["totals"], {"instruction": 32, "literal_pool": 4, "initialized_data": 0})
        self.assertEqual(result["callback_storage"], 0x03808E9C)

    def test_rejects_changed_incoming_pointer_or_irq_mask(self):
        for address in (0x037F8498, 0x037F83EC):
            changed = bytearray(self.payload)
            mapped = address_to_payload(address, address + 4, self.baseline, self.config)
            changed[mapped.payload_start] ^= 2
            with self.assertRaisesRegex(ValueError, "reference instruction/word"):
                audit_callback(changed, self.baseline, self.config)

    def test_rejects_disconnected_callback_storage(self):
        changed = bytearray(self.payload)
        mapped = address_to_payload(0x037FB884, 0x037FB888, self.baseline, self.config)
        struct.pack_into("<I", changed, mapped.payload_start, 0x03808E98)
        with self.assertRaisesRegex(ValueError, "callback storage"):
            audit_callback(changed, self.baseline, self.config)


if __name__ == "__main__":
    unittest.main()
