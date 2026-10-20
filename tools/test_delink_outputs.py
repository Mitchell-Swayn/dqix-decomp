import argparse
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

import delink_outputs as helper


class OutputValidationTests(unittest.TestCase):
    def test_output_inventory_rejects_escape_duplicate_and_empty(self):
        with tempfile.TemporaryDirectory():
            directory = Path.cwd() / "build/test-delink"
            for paths in ([], ["elsewhere.o"], [str(directory / "a.o")] * 2,
                          [str(directory / "not-an-object.txt")],
                          [str(directory / "../../escaped.o")]):
                with self.subTest(paths=paths), self.assertRaises(ValueError):
                    helper.output_paths({"units": [{"target_path": p} for p in paths]}, directory)

    def test_ninja_and_depfile_escaping(self):
        self.assertEqual(helper.ninja_path("C:/a b/$x.o"), "C$:/a$ b/$$x.o")
        self.assertEqual(helper.depfile_path("C:/a b/#x.o"), "C\\:/a\\ b/\\#x.o")


class NinjaOutputTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.ninja = shutil.which("ninja") or str(Path(sys.executable).with_name("ninja.exe" if os.name == "nt" else "ninja"))
        if not Path(cls.ninja).is_file():
            raise unittest.SkipTest("Ninja is required for build-graph integration tests")

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix="delink test ")
        self.root = Path(self.temp.name)
        self.addCleanup(self.temp.cleanup)
        for directory in ("extract/arm9", "extract/arm9_overlays", "generated"):
            (self.root / directory).mkdir(parents=True, exist_ok=True)
        for name in ("extract/config.yaml", "extract/arm9/arm9.bin", "extract/arm9/arm9.yaml",
                     "extract/arm9_overlays/ov000.bin", "config.txt", "tool", "candidate.cpp"):
            (self.root / name).write_text("fixture")
        self.write_units(["generated/source.o", "generated/fallback.o"])
        self.helper = Path(helper.__file__).resolve()
        # Substitute only the external executable. Inventory, verification,
        # completion publication and Ninja's dynamic-output graph are real.
        (self.root / "produce.py").write_text('''
import argparse, json, pathlib, subprocess, sys
from unittest.mock import patch
sys.path.insert(0, sys.argv[1])
import delink_outputs as helper
def dsd(command, check):
    mode = pathlib.Path('config.txt').read_text()
    with open('calls', 'a') as log: log.write('delink\\n')
    if mode == 'fail': raise subprocess.CalledProcessError(1, command)
    paths = json.loads(pathlib.Path('generated/outputs.json').read_text())['outputs']
    for name in paths:
        if mode == 'partial' and 'fallback' in name: continue
        path = pathlib.Path(name); path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(b'bad object' if mode == 'invalid' else b'\\x7fELFfixture')
args = argparse.Namespace(plan=pathlib.Path('generated/outputs.json'),
    directory=pathlib.Path('generated'), completion=pathlib.Path('generated/completion.json'),
    dsd=pathlib.Path('tool'), config=pathlib.Path('config.txt'))
with patch.object(helper.subprocess, 'run', dsd): helper.run(args)
''', encoding="utf-8")
        python = '"' + sys.executable + '"'
        h = '"' + str(self.helper) + '"'
        self.root.joinpath("build.ninja").write_text(f'''rule plan
  command = {python} {h} plan --objdiff objdiff.json --extract extract --directory generated --plan generated/outputs.json --completion generated/completion.json --dyndep generated/outputs.dd --depfile generated/outputs.dd.d
  depfile = generated/outputs.dd.d
rule delink
  command = {python} produce.py "{self.helper.parent}"
rule compile
  command = {python} -c "from pathlib import Path; Path('candidate.o').write_text('compiled')"
rule consume
  command = {python} -c "from pathlib import Path; Path('linked').write_text('linked')"
build generated/outputs.dd generated/outputs.json: plan objdiff.json extract/config.yaml
build generated/completion.json: delink config.txt tool generated/outputs.json || generated/outputs.dd
  dyndep = generated/outputs.dd
build candidate.o: compile candidate.cpp
build linked: consume generated/completion.json candidate.o
default linked
''', encoding="utf-8")

    def write_units(self, paths):
        (self.root / "objdiff.json").write_text(json.dumps({"units": [{"target_path": p} for p in paths]}))

    def ninja_run(self, success=True):
        result = subprocess.run([self.ninja], cwd=self.root, capture_output=True, text=True)
        self.assertEqual(result.returncode == 0, success, result.stdout + result.stderr)
        return result.stdout + result.stderr

    def calls(self):
        return (self.root / "calls").read_text().count("delink")

    def test_noop_and_deleted_source_target_fallback_and_candidate(self):
        self.ninja_run()
        self.assertIn("no work", self.ninja_run())
        for name in ("generated/source.o", "generated/fallback.o"):
            (self.root / name).unlink()
            before = self.calls()
            self.ninja_run()
            self.assertTrue((self.root / name).is_file())
            self.assertEqual(self.calls(), before + 1)
            self.assertIn("no work", self.ninja_run())
        (self.root / "candidate.o").unlink()
        before = self.calls()
        self.ninja_run()
        self.assertTrue((self.root / "candidate.o").is_file())
        self.assertEqual(self.calls(), before)

    def test_config_tool_extracted_file_and_inventory_changes(self):
        self.ninja_run()
        for name in ("config.txt", "tool", "extract/arm9/arm9.bin", "extract/arm9_overlays/ov000.bin"):
            before = self.calls()
            (self.root / name).write_text("changed")
            self.ninja_run()
            self.assertEqual(self.calls(), before + 1)
            self.assertIn("no work", self.ninja_run())
        self.write_units(["generated/new.o", "generated/source.o", "generated/fallback.o"])
        self.ninja_run()
        self.assertTrue((self.root / "generated/new.o").is_file())
        self.assertIn("no work", self.ninja_run())
        (self.root / "extract/arm9/new.bin").write_text("new module input")
        # Extraction updates metadata when introducing a new module. Windows
        # directory mtimes alone are not guaranteed to change synchronously.
        (self.root / "extract/config.yaml").write_text("new extraction inventory")
        before = self.calls()
        self.ninja_run()
        self.assertEqual(self.calls(), before + 1)

    def test_failed_and_partial_delink_do_not_publish_completion(self):
        self.ninja_run()
        for mode in ("fail", "partial", "invalid"):
            (self.root / "config.txt").write_text(mode)
            self.ninja_run(success=False)
            self.assertFalse((self.root / "generated/completion.json").exists())
            (self.root / "config.txt").write_text("recover")
            self.ninja_run()
            self.assertIn("no work", self.ninja_run())


if __name__ == "__main__":
    unittest.main()
