"""Regression checks for the independent cartridge ARM7 baseline verifier."""

import contextlib
import hashlib
import io
import json
from pathlib import Path
import struct
import tempfile
from types import SimpleNamespace
import unittest

from check_arm7 import read_arm7, verify


class Arm7BaselineTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        root = Path(self.temporary.name)
        self.args = SimpleNamespace(**{
            name: root / name for name in ("baserom", "rom", "extracted", "baseline", "output")
        })
        self.payload = bytes(range(32))
        header = bytearray(512)
        struct.pack_into("<4I", header, 0x30, 512, 0x2380000, 0x2380000, len(self.payload))
        rom = header + self.payload
        self.args.baserom.write_bytes(rom)
        self.args.rom.write_bytes(rom)
        self.args.extracted.write_bytes(self.payload)
        baseline = json.loads((Path(__file__).parent.parent / "config/usa/arm7/baseline.json").read_text())
        baseline.update(read_arm7(self.args.baserom)[0])
        baseline["source_rom_sha1"] = hashlib.sha1(rom).hexdigest()
        self.args.baseline.write_text(json.dumps(baseline))

    def test_exact_binary_preservation_does_not_claim_source_coverage(self):
        with contextlib.redirect_stdout(io.StringIO()):
            verify(self.args)
        report = json.loads(self.args.output.read_text())
        self.assertNotIn("source_code_bytes", report)
        self.assertEqual(report["preserved_payload_bytes"], len(self.payload))
        self.assertIsNone(report["function_count"])

    def test_rebuilt_byte_corruption_is_rejected(self):
        rom = bytearray(self.args.rom.read_bytes())
        rom[-1] ^= 1
        self.args.rom.write_bytes(rom)
        with self.assertRaisesRegex(ValueError, "payload_sha1"):
            verify(self.args)

    def test_extraction_corruption_is_rejected(self):
        self.args.extracted.write_bytes(b"wrong")
        with self.assertRaisesRegex(ValueError, "Extracted ARM7"):
            verify(self.args)

    def test_changed_entry_is_rejected(self):
        rom = bytearray(self.args.rom.read_bytes())
        struct.pack_into("<I", rom, 0x34, 0x2380004)
        self.args.rom.write_bytes(rom)
        with self.assertRaisesRegex(ValueError, "entry_address"):
            verify(self.args)

    def test_truncated_payload_is_rejected(self):
        self.args.rom.write_bytes(self.args.rom.read_bytes()[:-1])
        with self.assertRaisesRegex(ValueError, "payload extent"):
            verify(self.args)

    def test_source_input_change_is_rejected(self):
        self.args.baserom.write_bytes(b"wrong")
        with self.assertRaisesRegex(ValueError, "Base ROM SHA-1"):
            verify(self.args)


if __name__ == "__main__":
    unittest.main()
