import importlib.util
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import hashlib

SPEC = importlib.util.spec_from_file_location("audit_data_layout", Path(__file__).parents[1] / "audit_data_layout.py")
module = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(module)


class DataLayoutTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.original = Path(self.temp.name) / "original.bin"
        self.generated = Path(self.temp.name) / "generated.bin"
        self.original.write_bytes(b"name\0")
        self.generated.write_bytes(b"name\0")
        self.rows = [dict(name="name", address=0x2000000, size=5, section=".data", sha256=hashlib.sha256(b"name\0").hexdigest())]

    def audit(self, layout=None):
        with patch.object(module, "symbols", return_value=(0x2000000, layout or {"name": (0x2000000, 5)})):
            return module.audit("unused", self.rows, "ARM9", self.original, self.generated)

    def test_exact_extent(self):
        self.assertTrue(self.audit()["match"])

    def test_shifted_symbol_and_changed_size(self):
        self.assertFalse(self.audit({"name": (0x2000001, 4)})["match"])

    def test_changed_data(self):
        self.generated.write_bytes(b"NAME\0")
        self.assertFalse(self.audit()["match"])

    def test_wrong_provenance_hash(self):
        self.rows[0]["sha256"] = "0" * 64
        self.assertFalse(self.audit()["match"])

    def test_overlap_rejected(self):
        self.rows += self.rows
        with self.assertRaises(ValueError):
            self.audit()

    def test_hardlinked_input_rejected(self):
        self.generated.unlink()
        self.generated.hardlink_to(self.original)
        with self.assertRaises(ValueError):
            self.audit()

    def test_out_of_range_rejected(self):
        self.rows[0]["size"] = 6
        with self.assertRaises(ValueError):
            self.audit()


if __name__ == "__main__":
    unittest.main()
