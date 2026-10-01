import json
import tempfile
import unittest
from pathlib import Path

from generate_lcf import apply_absolute_symbols


class AbsoluteSymbolsTest(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.lcf = self.root / "arm9.lcf"
        self.config = self.root / "linker_symbols.json"
        self.original = "MEMORY {}\nSECTIONS {\n    .text : {}\n}\n"
        self.lcf.write_text(self.original)

    def test_optional_config_preserves_lcf(self):
        apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), self.original)

    def test_absolute_values_add_no_sections(self):
        self.config.write_text(json.dumps({"SDK_SYS_STACKSIZE": "0x0", "SDK_IRQ_STACKSIZE": "0x400"}))
        apply_absolute_symbols(self.lcf, self.config)
        expected = self.original.replace("SECTIONS {", "SECTIONS {\n    SDK_SYS_STACKSIZE = 0x0;\n    SDK_IRQ_STACKSIZE = 0x400;")
        self.assertEqual(self.lcf.read_text(), expected)
        with self.assertRaises(ValueError):
            apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), expected)

    def test_invalid_config_does_not_modify_lcf(self):
        for config in [{"BAD;": "0x0"}, {"GOOD": "0x100000000"}, {"GOOD": 1}, []]:
            with self.subTest(config=config):
                self.config.write_text(json.dumps(config))
                with self.assertRaises(ValueError):
                    apply_absolute_symbols(self.lcf, self.config)
                self.assertEqual(self.lcf.read_text(), self.original)

    def test_missing_sections_is_rejected(self):
        self.config.write_text('{"GOOD": "0x0"}')
        self.lcf.write_text("unexpected LCF layout")
        with self.assertRaises(ValueError):
            apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), "unexpected LCF layout")


if __name__ == "__main__":
    unittest.main()
