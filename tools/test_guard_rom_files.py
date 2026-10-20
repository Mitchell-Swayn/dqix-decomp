import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

from guard_rom_files import check_paths


class RomIsolationTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.source = self.root / "input.nds"
        self.output = self.root / "output.nds"
        self.source.write_bytes(b"original")

    def test_independent_existing_and_new_outputs(self):
        self.output.write_bytes(b"original")
        check_paths([self.source], [self.output, self.root / "new.nds"])

    def test_same_path_rejected(self):
        with self.assertRaises(ValueError):
            check_paths([self.source], [self.source])

    def test_hardlink_to_input_rejected(self):
        os.link(self.source, self.output)
        with self.assertRaises(ValueError):
            check_paths([self.source], [self.output])

    def test_hardlink_to_unlisted_other_worktree_file_rejected(self):
        other = self.root / "other-worktree.nds"
        other.write_bytes(b"generated")
        os.link(other, self.output)
        with self.assertRaises(ValueError):
            check_paths([self.source], [self.output])

    def test_duplicate_future_outputs_rejected(self):
        with self.assertRaises(ValueError):
            check_paths([self.source], [self.output, self.output])

    def invoke(self):
        return subprocess.run([
            sys.executable, str(Path(__file__).with_name("guard_rom_files.py")),
            "--input", str(self.source), "--output", str(self.output), "--",
            sys.executable, "-c",
            "import pathlib,sys; pathlib.Path(sys.argv[1]).write_bytes(b'written')",
            str(self.output),
        ], capture_output=True, text=True)

    def test_bad_alias_blocks_writer_and_preserves_original(self):
        os.link(self.source, self.output)
        result = self.invoke()
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(self.source.read_bytes(), b"original")

    def test_valid_writer_runs(self):
        result = self.invoke()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.output.read_bytes(), b"written")
        self.assertEqual(self.source.read_bytes(), b"original")


if __name__ == "__main__":
    unittest.main()
