"""Run with python -m unittest discover -s tools -p arm7_test.py."""

import copy
import json
from pathlib import Path
import struct
import tempfile
import unittest

from arm7_build import validate_layout, write_rom_config


class Arm7PipelineTests(unittest.TestCase):
    def setUp(self):
        root = Path(__file__).resolve().parent.parent
        self.baseline = json.loads((root / "config/usa/arm7/baseline.json").read_text())
        self.config = json.loads((root / "config/usa/arm7/source_units.json").read_text())
        self.payload = bytearray(self.baseline["size"])
        base = self.baseline["load_address"]
        start = base + self.config["startup_size"]
        struct.pack_into("<6I", self.payload, self.config["autoload_parameters_offset"],
                         base + self.config["autoload_table_offset"], base + len(self.payload),
                         start, start, start, 0)
        for index, module in enumerate(self.config["autoloads"]):
            struct.pack_into("<3I", self.payload, self.config["autoload_table_offset"] + 12 * index,
                             module["runtime_address"], module["size"], module["bss_size"])

    def test_startup_copy_table_matches_inventory(self):
        validate_layout(self.payload, self.baseline, self.config)

    def test_changed_copy_destination_is_rejected(self):
        self.payload[self.config["autoload_table_offset"]] ^= 4
        with self.assertRaisesRegex(ValueError, "descriptor differs"):
            validate_layout(self.payload, self.baseline, self.config)

    def test_wrong_runtime_address_is_rejected(self):
        self.config["units"][0]["runtime_address"] += 4
        with self.assertRaisesRegex(ValueError, "runtime mapping differs"):
            validate_layout(self.payload, self.baseline, self.config)

    def test_double_counting_source_slice_is_rejected(self):
        self.config["units"].append(copy.deepcopy(self.config["units"][0]))
        with self.assertRaisesRegex(ValueError, "overlaps"):
            validate_layout(self.payload, self.baseline, self.config)

    def test_rom_config_preserves_other_paths_and_selects_linked_arm7(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / "original.yaml"
            output = root / "linked.yaml"
            source.write_text("arm9_bin: arm9.bin\narm7_bin: original.bin\nfiles_dir: ../../../extract/files\n")
            write_rom_config(source, output, root / "arm7.bin")
            self.assertEqual(output.read_text().splitlines(), [
                "arm9_bin: arm9.bin", "arm7_bin: " + json.dumps((root / "arm7.bin").resolve().as_posix()),
                "files_dir: ../../../extract/files"])
            with self.assertRaisesRegex(ValueError, "beside"):
                write_rom_config(source, root / "different/output.yaml", root / "arm7.bin")


if __name__ == "__main__":
    unittest.main()
