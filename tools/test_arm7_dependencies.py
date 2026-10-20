"""Dependency parser, provenance, and real MWCC/Ninja include-graph checks."""

import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

from arm7_dependencies import dependency_records, has_assembly, native_dependency_name, parse_depfile, write_depfile


ROOT = Path(__file__).resolve().parent.parent


class DependencyTests(unittest.TestCase):
    def test_mwcc_windows_paths_continuations_and_escaped_spaces(self):
        self.assertEqual(parse_depfile("out\\unit.o: ..\\unit.c \\\r\n\tC:\\source\\space\\ dir\\nested.h \r\n"),
                         ["..\\unit.c", "C:\\source\\space dir\\nested.h"])

    def test_drive_letter_on_target_and_duplicate_inputs(self):
        self.assertEqual(parse_depfile("C:\\obj\\a.o: a.c a.c"), ["a.c", "a.c"])

    def test_wine_and_wsl_drive_mapping(self):
        self.assertEqual(native_dependency_name(r"Z:\home\user\nested.h", host="posix"), "/home/user/nested.h")
        self.assertEqual(native_dependency_name(r"C:\repo\nested.h", host="posix", wsl=True), "/mnt/c/repo/nested.h")
        self.assertEqual(Path(native_dependency_name(r"D:\repo\nested.h", host="posix", wsl=False, wineprefix="prefix")),
                         Path("prefix/dosdevices/d:/repo/nested.h"))
        self.assertEqual(native_dependency_name(r"C:\repo\nested.h", host="nt"), "C:/repo/nested.h")
        self.assertEqual(native_dependency_name(r"..\nested.h", host="posix"), "../nested.h")

    def test_malformed_or_multiple_rules_fail(self):
        for text in ["", "a.o a.c", "a.o:", "a.o: a.c\nb.o: b.c"]:
            with self.subTest(text=text), self.assertRaises(ValueError):
                parse_depfile(text)

    def fixture(self, root):
        (root / "unit.c").write_text('#include "outer.h"\nint value;\n')
        (root / "outer.h").write_text('#include "nested.h"\n')
        (root / "nested.h").write_text('#define VALUE 1\n')
        dep = root / "unit.d"
        dep.write_text("unit.o: unit.c outer.h nested.h nested.h\n")
        return dep, root / "unit.c"

    def test_transitive_hash_changes_without_source_change(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            dep, source = self.fixture(root)
            before = dependency_records(dep, root, root, source)
            self.assertEqual(len(before), 3)
            (root / "nested.h").write_text('#define VALUE 2\n')
            after = dependency_records(dep, root, root, source)
            changed = [a["path"] for a, b in zip(before, after) if a != b]
            self.assertEqual(changed, ["nested.h"])

    def test_missing_outside_or_omitted_source_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            dep, source = self.fixture(root)
            for inputs in ["unit.c absent.h", "nested.h", "unit.c ../outside.h"]:
                dep.write_text("unit.o: " + inputs)
                with self.subTest(inputs=inputs), self.assertRaises(ValueError):
                    dependency_records(dep, root, root, source)

    def test_header_assembly_not_covered_by_source_exception(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            dep, source = self.fixture(root)
            (root / "nested.h").write_text('#define BODY __asm { bx lr }\n')
            for reviewed in [False, True]:
                with self.assertRaisesRegex(ValueError, "header assembly"):
                    dependency_records(dep, root, root, source, reviewed)

    def test_reviewed_source_assembly_retained(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            dep, source = self.fixture(root)
            source.write_text('asm void entry() { bx lr }\n')
            with self.assertRaisesRegex(ValueError, "reviewed source"):
                dependency_records(dep, root, root, source)
            self.assertEqual(len(dependency_records(dep, root, root, source, True)), 3)

    def test_comments_strings_and_assembly_forms(self):
        self.assertFalse(has_assembly('/* asm { } */ "__asm" // asm()\nint value;'))
        for text in ['asm void entry() {}', '__asm { nop }', '__asm__("nop")']:
            self.assertTrue(has_assembly(text))

    def test_ninja_escaping(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "deps.d"
            write_depfile(path, "build/out file", ["include/a #$h.h", "include/a #$h.h"])
            self.assertEqual(path.read_text(), "build/out\\ file: include/a\\ \\#$$h.h\n")
            with self.assertRaises(ValueError):
                write_depfile(path, "bad\nname", [])

    @unittest.skipUnless(os.name == "nt" and (ROOT / "tools/mwccarm/2.0/sp2p2/mwccarm.exe").is_file()
                         and (ROOT / ".venv/Scripts/ninja.exe").is_file(), "requires pinned Windows MWCC and Ninja")
    def test_real_compiler_and_ninja_follow_nested_header_change(self):
        with tempfile.TemporaryDirectory(prefix="arm7 deps ") as directory:
            root = Path(directory)
            (root / "space dir").mkdir()
            (root / "unit.c").write_text('#include "outer.h"\nint value(void) { return VALUE; }\n')
            (root / "outer.h").write_text('#include "space dir/nested.h"\n')
            nested = root / "space dir/nested.h"
            nested.write_text('#define VALUE 1\n')
            script = '''import json, pathlib, subprocess, sys
sys.path.insert(0, TOOLS)
from arm7_dependencies import dependency_records, write_depfile
root = pathlib.Path.cwd()
subprocess.run([COMPILER, '-O2', '-proc', 'arm7tdmi', '-lang=c', '-gccinc', '-nolink', '-MD', '-c', 'unit.c', '-o', 'unit.o'], check=True)
records = dependency_records(root/'unit.d', root, root, root/'unit.c')
(root/'provenance.json').write_text(json.dumps(records))
write_depfile(root/'ninja.d', 'unit.o', [r['path'] for r in records])
with (root/'runs').open('a') as stream: stream.write('1')
'''.replace("TOOLS", repr(str(ROOT / "tools"))).replace("COMPILER", repr(str(ROOT / "tools/mwccarm/2.0/sp2p2/mwccarm.exe")))
            (root / "compile.py").write_text(script)
            (root / "build.ninja").write_text(f'rule compile\n  command = "{sys.executable}" compile.py\n  depfile = ninja.d\nbuild unit.o: compile unit.c\n')
            ninja = str(ROOT / ".venv/Scripts/ninja.exe")
            def run():
                return subprocess.run([ninja], cwd=root, check=True, capture_output=True, text=True)
            run()
            before = json.loads((root / "provenance.json").read_text())
            self.assertEqual(len(before), 3)
            run()
            self.assertEqual((root / "runs").read_text(), "1")
            nested.write_text('#define VALUE 2\n')
            future = (root / "unit.o").stat().st_mtime + 2
            os.utime(nested, (future, future))
            run()
            after = json.loads((root / "provenance.json").read_text())
            self.assertEqual((root / "runs").read_text(), "11")
            self.assertEqual([a['path'] for a, b in zip(before, after) if a != b], ["space dir/nested.h"])


if __name__ == "__main__":
    unittest.main()
