import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch
from short_link import run, rewrite_lcf, short_alias, short_name


@unittest.skipUnless(os.name == 'posix', 'short paths target POSIX Wibo')
class ShortLinkTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.tmp = self.root / 'tmp'
        self.tmp.mkdir()
        self.patch = patch('short_link.tempfile.gettempdir', return_value=str(self.tmp))
        self.patch.start()
        self.addCleanup(self.patch.stop)
        self.inputs = self.root / 'inputs'
        self.inputs.mkdir()
        self.paths = [self.inputs / 'Second.o', self.inputs / 'First.o']
        for index, p in enumerate(self.paths):
            p.write_bytes(b'original\0object' + bytes([index]))
        self.objects = self.root / 'objects.txt'
        self.objects.write_text(''.join('"' + str(p) + '"\n' for p in self.paths))
        self.lcf = self.root / 'original.lcf'
        self.text = ('SECTIONS {\n .arm9 : {\n  ALIGNALL(1);\n  First.o(.text)\n'
                     '  ALIGNALL(4);\n  Second.o(.text)\n  Keep = base + 0x4;\n }\n}\n')
        self.lcf.write_text(self.text)
        self.workspace = self.root / 'build/short_link'
        self.command = ['linker', '-force_active', 'Keep', '@' + str(self.objects), str(self.lcf), '-o', 'out.o']

    def test_copies_selectors_order_symbols_and_command_preserved(self):
        before = [p.read_bytes() for p in self.paths]
        def linker(command, check):
            self.assertTrue(check)
            self.assertEqual(command[:3], self.command[:3])
            self.assertEqual(command[-2:], self.command[-2:])
            objects = Path(command[3][1:]).read_text().splitlines()
            actual = [Path(p.strip('"')).read_bytes() for p in objects]
            self.assertEqual(actual, before)
            self.assertEqual(Path(command[4]).read_text(), self.text.replace('First.o', 'b.o').replace('Second.o', 'a.o'))
        with patch('short_link.subprocess.run', side_effect=linker):
            report = run(self.objects, self.lcf, self.workspace, self.command)
        self.assertEqual([p.read_bytes() for p in self.paths], before)
        self.assertEqual(self.lcf.read_text(), self.text)
        self.assertEqual(list(self.tmp.iterdir()), [])
        for record, expected in zip(report['objects'], before):
            self.assertEqual(Path(record['copy']).read_bytes(), expected)
            self.assertEqual(record['sha256'], hashlib.sha256(expected).hexdigest())
            self.assertEqual(Path(record['copy']).stat().st_nlink, 1)
        self.assertEqual(json.loads((self.workspace/'report.json').read_text())['objects'], report['objects'])

    def test_failure_cleans_alias_and_leaves_stable_copies(self):
        with patch('short_link.subprocess.run', side_effect=subprocess.CalledProcessError(1, 'linker')):
            with self.assertRaises(subprocess.CalledProcessError):
                run(self.objects, self.lcf, self.workspace, self.command)
        self.assertEqual(list(self.tmp.iterdir()), [])
        self.assertTrue((self.workspace / 'report.json').exists())
        for line in (self.workspace/'objects.txt').read_text().splitlines():
            self.assertTrue(Path(line.strip('"')).is_file())

    def test_collision_never_reuses_or_deletes_existing_path(self):
        occupied = self.tmp / 'a'
        occupied.mkdir()
        with short_alias(self.inputs) as alias:
            self.assertNotEqual(alias, occupied)
            self.assertEqual(alias.resolve(), self.inputs)
        self.assertTrue(occupied.is_dir())

    def test_replaced_alias_is_not_deleted(self):
        with short_alias(self.inputs) as alias:
            alias.unlink()
            alias.mkdir()
        self.assertTrue(alias.is_dir())

    def test_missing_selector_rejected(self):
        with self.assertRaisesRegex(ValueError, 'missing'):
            rewrite_lcf(self.text, {'First.o': 'a.o'})

    def test_duplicate_basenames_rejected_before_link(self):
        self.objects.write_text(str(self.paths[0])+'\n'+str(self.paths[0])+'\n')
        with patch('short_link.subprocess.run') as linker, self.assertRaisesRegex(ValueError, 'unique'):
            run(self.objects, self.lcf, self.workspace, self.command)
        linker.assert_not_called()

    def test_command_must_select_original_response_and_lcf_once(self):
        for command in [self.command+[str(self.lcf)], self.command[:3]+self.command[4:]]:
            with self.assertRaisesRegex(ValueError, 'one response'):
                run(self.objects, self.lcf, self.workspace, command)

    def test_linked_outputs_are_rejected_without_modifying_inputs(self):
        for filename, source, symlink in [('a.o', self.paths[0], True),
                                          ('a.o', self.paths[0], False),
                                          ('script.lcf', self.lcf, False)]:
            with self.subTest(filename=filename, symlink=symlink):
                workspace = self.root / ('case' + str(symlink) + filename) / 'link'
                workspace.mkdir(parents=True)
                target = workspace / filename
                before = source.read_bytes()
                if symlink:
                    target.symlink_to(source)
                else:
                    os.link(source, target)
                with patch('short_link.subprocess.run') as linker:
                    with self.assertRaisesRegex(ValueError, 'independent'):
                        run(self.objects, self.lcf, workspace, self.command)
                linker.assert_not_called()
                self.assertEqual(source.read_bytes(), before)
                target.unlink()

    def test_concurrent_alias_claims_are_independent(self):
        with short_alias(self.inputs) as first:
            with short_alias(self.inputs) as second:
                self.assertNotEqual(first, second)
                self.assertTrue(first.is_symlink())
            self.assertTrue(first.is_symlink())
        self.assertEqual(list(self.tmp.iterdir()), [])

    def test_short_names_unique_under_case_insensitive_matching(self):
        names = [short_name(i).casefold() for i in range(10000)]
        self.assertEqual(len(set(names)), len(names))


if __name__ == '__main__':
    unittest.main()
