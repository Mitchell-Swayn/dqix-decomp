"""Structural rejection tests for the cartridge inventory (no proprietary inputs)."""
import struct
import tempfile
import unittest
from pathlib import Path

from inventory import bounded, cartridge, delinks


class InventoryTests(unittest.TestCase):
    def fixture(self):
        rom = bytearray(0x400)
        rom[12:16] = b"YDQE"
        struct.pack_into("<4I", rom, 0x20, 0x200, 0x2000000, 0x2000000, 16)
        struct.pack_into("<4I", rom, 0x30, 0x220, 0x2380000, 0x2380000, 16)
        struct.pack_into("<2I", rom, 0x48, 0x280, 8)
        struct.pack_into("<2I", rom, 0x50, 0x300, 32)
        struct.pack_into("<2I", rom, 0x280, 0x380, 0x390)
        struct.pack_into("<8I", rom, 0x300, 7, 0x2100000, 16, 8, 0, 0, 0, 0)
        return rom

    def test_overlay_and_arm7_are_not_silently_dropped(self):
        result = cartridge(self.fixture())
        self.assertEqual(result["overlays"]["arm9"][0]["id"], 7)
        self.assertEqual(result["overlays"]["arm9"][0]["bss_size"], 8)
        self.assertEqual(result["overlays"]["arm7"], [])
        self.assertEqual(result["processors"]["arm7"]["stored_size"], 16)

    def test_malformed_overlay_table_rejected(self):
        rom = self.fixture()
        struct.pack_into("<I", rom, 0x54, 31)
        with self.assertRaisesRegex(ValueError, "overlay table size"):
            cartridge(rom)

    def test_invalid_fat_reference_rejected(self):
        rom = self.fixture()
        struct.pack_into("<I", rom, 0x318, 1)
        with self.assertRaisesRegex(ValueError, "invalid FAT"):
            cartridge(rom)

    def test_truncated_payload_rejected(self):
        with self.assertRaises(ValueError):
            bounded(b"1234", 3, 2)
        with self.assertRaises(ValueError):
            bounded(b"1234", 3, -1)

    def test_source_range_must_fit_module_section(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "delinks.txt"
            path.write_text(".text start:0x1000 end:0x1020 kind:code align:4\n"
                            "src/example.cpp:\ncomplete\n.text start:0x1000 end:0x1040\n")
            with self.assertRaisesRegex(ValueError, "outside section"):
                delinks(path)


if __name__ == "__main__":
    unittest.main()
