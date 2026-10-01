"""Structural rejection tests for the cartridge inventory (no proprietary inputs)."""
import struct
import tempfile
import unittest
from pathlib import Path
import json
import hashlib

from inventory import arm7_components, bounded, cartridge, delinks


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

    def arm7_fixture(self, root, with_report=False):
        config = dict(startup_size=24, autoload_parameters_offset=0, autoload_table_offset=32,
            autoloads=[dict(name='wram', payload_offset=24, runtime_address=0x3000, size=8, bss_size=4)],
            units=[dict(name='f', source='f.c', autoload='wram', runtime_address=0x3000,
                        payload_offset=24, size=4, code_bytes=4, literal_pool_bytes=0)])
        payload = struct.pack('<6I', 0x1020, 0x102c, 0x1018, 0x1018, 0x1018, 0)
        payload += b'codeDATA' + struct.pack('<3I', 0x3000, 8, 4)
        path = root / 'config/usa/arm7/source_units.json'
        path.parent.mkdir(parents=True)
        path.write_text(json.dumps(config))
        (root / 'f.c').write_bytes(b'source')
        if with_report:
            unit = dict(config['units'][0], source_sha1=hashlib.sha1(b'source').hexdigest(),
                        linked_sha1=hashlib.sha1(b'code').hexdigest(), module_check_passed=True,
                        symbol_check_passed=True)
            report = dict(payload_bytes=44, payload_sha1=hashlib.sha1(payload).hexdigest(),
                module_check_passed=True, source_symbol_checks_passed=True,
                autoloads=config['autoloads'], units=[unit], source_code_bytes=4,
                source_literal_pool_bytes=0, source_data_bytes=0, reviewed_assembly_bytes=0,
                binary_fallback_bytes=40, source_functions=1, function_count=None,
                code_data_partition='unknown', compiler_sha1='test', linker_sha1='test')
            report_path = root / 'build/usa/arm7/report.json'
            report_path.parent.mkdir(parents=True)
            report_path.write_text(json.dumps(report))
        return payload

    def test_arm7_partition_without_report_gets_no_measured_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            result = arm7_components(root, self.arm7_fixture(root), 0x1000)
            self.assertIsNone(result['source_build_report'])
            self.assertEqual(sum(p['initialized_size'] for p in result['subcomponents']), 44)

    def test_arm7_report_reconciles_without_counting_autoloads_twice(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            result = arm7_components(root, self.arm7_fixture(root, True), 0x1000)
            self.assertEqual(sum(p['binary_fallback_bytes'] for p in result['subcomponents']), 40)
            self.assertIsNone(result['source_build_report']['measures']['function_count'])

    def test_arm7_stale_source_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            payload = self.arm7_fixture(root, True)
            (root / 'f.c').write_bytes(b'changed')
            with self.assertRaisesRegex(ValueError, 'source changed'):
                arm7_components(root, payload, 0x1000)

    def test_arm7_descriptor_disagreement_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            payload = bytearray(self.arm7_fixture(root))
            struct.pack_into('<I', payload, 32, 0x4000)
            with self.assertRaisesRegex(ValueError, 'descriptor differs'):
                arm7_components(root, payload, 0x1000)


if __name__ == "__main__":
    unittest.main()
