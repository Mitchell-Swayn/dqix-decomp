"""Failure-path tests for batch preparation, inspection identity, and verification."""
import contextlib
import copy
import io
import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch

import compile_verify_batch as batch
import audit_link_layout as layout
import elf_function_bytes as elf
import inspect_functions as inspection
import prepare_candidates as preparation
import select_candidates as selection
from test_match_unit import MATCHED, UNIT


def tiny_elf(code=b'\x1e\xff\x2f\xe1', relocation=False):
    # ELF32 with null, code, strings, symbols, and optional code relocation.
    data = bytearray(52)
    data[:6] = b'\x7fELF\x01\x01'
    sections = [(0,) * 10]
    for kind, payload, link, info, entsize in (
        (1, code, 0, 0, 0), (3, b'\0function\0', 0, 0, 0),
        (2, bytes(16) + struct.pack('<IIIBBH', 1, 0, len(code), 18, 0, 1), 2, 0, 16)):
        offset = len(data)
        data.extend(payload)
        sections.append((0, kind, 0, 0, offset, len(payload), link, info, 4, entsize))
    if relocation:
        offset = len(data)
        data.extend(bytes(8))
        sections.append((0, 9, 0, 0, offset, 8, 3, 1, 4, 8))
    offset = len(data)
    for section in sections:
        data.extend(struct.pack('<10I', *section))
    struct.pack_into('<I', data, 32, offset)
    struct.pack_into('<HH', data, 46, 40, len(sections))
    return bytes(data)


class PreparationTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        config = self.root / 'config/usa/arm9'
        config.mkdir(parents=True)
        (config / 'delinks.txt').write_text('    .text start:0x02000000 end:0x02001000 kind:code align:4\n')
        (config / 'symbols.txt').write_text('function kind:function(arm,size=0x4) addr:0x02000000\n')
        self.rows = [{'name': 'function', 'address': '02000000', 'size': 4}]

    def test_scaffold_cannot_silently_build(self):
        config, text, files, result = preparation.plan(self.root, self.rows, 'config/usa/arm9/delinks.txt', 'src/Batch')
        self.assertIn('#error Reconstruct', next(iter(files.values())))
        self.assertEqual(result['units'], ['src/Batch/function'])
        self.assertEqual(text.count('.text start:0x02000000 end:0x02000004'), 1)
        self.assertFalse((self.root / 'src').exists())

    def test_selection_excludes_source_owned_and_wrong_size(self):
        report = {'units': [
            {'name': 'main_1', 'metadata': {'auto_generated': True},
             'functions': [{'name': 'function', 'size': '4'}]},
            {'name': 'src/Complete', 'metadata': {'auto_generated': False},
             'functions': [{'name': 'function', 'size': '4'}]}]}
        rows = selection.select(self.root, report, 'main', 10, 4, 8)
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]['address'], '02000000')
        self.assertEqual(selection.select(self.root, report, 'main', 10, 8, 24), [])

    def test_duplicate_overlap_and_wrong_original_range(self):
        for rows in (self.rows * 2, [{**self.rows[0], 'size': 8}]):
            with self.assertRaises(ValueError):
                preparation.plan(self.root, rows, 'config/usa/arm9/delinks.txt', 'src/Batch')
        config = self.root / 'config/usa/arm9/delinks.txt'
        config.write_text(config.read_text() + '\nsrc/Existing.cpp:\n    .text start:0x02000000 end:0x02000004\n')
        with self.assertRaises(ValueError):
            preparation.plan(self.root, self.rows, 'config/usa/arm9/delinks.txt', 'src/Batch')

    def test_existing_source_and_missing_candidate_preserve_config(self):
        source = self.root / 'src/Batch/function.cpp'
        source.parent.mkdir(parents=True)
        source.write_text('user source')
        before = (self.root / 'config/usa/arm9/delinks.txt').read_bytes()
        with self.assertRaises(ValueError):
            preparation.plan(self.root, self.rows, 'config/usa/arm9/delinks.txt', 'src/Batch')
        source.unlink()
        with self.assertRaises(OSError):
            preparation.plan(self.root, self.rows, 'config/usa/arm9/delinks.txt', 'src/Batch', self.root / 'missing')
        self.assertEqual(before, (self.root / 'config/usa/arm9/delinks.txt').read_bytes())


class InspectionTests(unittest.TestCase):
    def test_identity_change_rejects_evidence(self):
        with patch.object(inspection, 'fingerprint', side_effect=['before', 'after']), patch.object(inspection, 'request', return_value='valid'):
            with self.assertRaisesRegex(ValueError, 'changed'):
                inspection.inspect('server', [{'address': '02000000'}])

    def test_expected_identity_and_shared_epilogue(self):
        with patch.object(inspection, 'fingerprint', return_value='actual'):
            with self.assertRaises(ValueError):
                inspection.inspect('server', [], 'expected')
        def request(server, endpoint, **params):
            return '02000000: add sp,sp,#0x10\n02000004: ldmia sp!,{r4,pc}' if endpoint == 'disassemble_function' else 'valid'
        with patch.object(inspection, 'fingerprint', return_value='identity'), patch.object(inspection, 'request', request):
            rows = inspection.inspect('server', [{'address': '02000000'}])['functions']
            self.assertIn('possible_shared_epilogue', rows[0]['review_flags'])


class RawBytesTests(unittest.TestCase):
    def test_missing_and_shifted_linked_functions(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'linked.o'
            path.write_bytes(tiny_elf())
            result = layout.audit(path, [{'name': 'function', 'address': '02000000', 'size': 4},
                                         {'name': 'missing', 'address': '02000004', 'size': 4}])
            self.assertFalse(result['match'])
            self.assertEqual([row['issue'] for row in result['differences']], ['layout', 'missing'])
            data = bytearray(tiny_elf())
            section_offset = struct.unpack_from('<I', data, 32)[0]
            struct.pack_into('<I', data, section_offset + 40 + 20, 0)
            path.write_bytes(data)
            self.assertTrue(layout.audit(path, [{'name': 'function', 'address': '00000000', 'size': 4}])['match'])

    def test_bytes_differ_and_relocations_are_not_exact_proof(self):
        with tempfile.TemporaryDirectory() as directory:
            a, b = Path(directory) / 'a.o', Path(directory) / 'b.o'
            a.write_bytes(tiny_elf())
            b.write_bytes(tiny_elf())
            self.assertTrue(elf.compare(a, b)['raw_match'])
            b.write_bytes(tiny_elf(b'xxxx'))
            self.assertFalse(elf.compare(a, b)['raw_match'])
            b.write_bytes(tiny_elf(relocation=True))
            self.assertIsNone(elf.compare(a, b)['raw_match'])
            b.write_bytes(b'not elf')
            with self.assertRaises(ValueError):
                elf.compare(a, b)


class BatchTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'objdiff.json').write_text(json.dumps({'units': [UNIT]}))
        for relative in (UNIT['target_path'], UNIT['base_path']):
            path = self.root / relative
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(tiny_elf())

    def fake_run(self, command, root, attempt, label):
        if label == 'objdiff':
            (attempt / 'diff.json').write_text(json.dumps(MATCHED))

    def test_build_failure_never_compares_stale_object(self):
        with patch.object(batch, 'run_logged', side_effect=ValueError('ninja exited 1')) as run:
            code, result = batch.run(self.root, [UNIT['name']], ninja='ninja')
        self.assertEqual(code, 2)
        self.assertFalse(result['match'])
        self.assertEqual(run.call_count, 1)

    def test_one_build_and_raw_comparison(self):
        with patch.object(batch, 'run_logged', side_effect=self.fake_run) as run:
            code, result = batch.run(self.root, [UNIT['name']], ninja='ninja', raw_required=True)
        self.assertEqual(code, 0)
        self.assertEqual(result['matched'], 1)
        self.assertEqual([call.args[3] for call in run.call_args_list], ['ninja', 'objdiff'])
        self.assertFalse(result['rom_acceptance'])

    def test_changed_original_is_rejected(self):
        def run(command, root, attempt, label):
            if label == 'ninja':
                (root / UNIT['target_path']).write_bytes(tiny_elf(b'xxxx'))
            else:
                self.fake_run(command, root, attempt, label)
        with patch.object(batch, 'run_logged', run):
            code, result = batch.run(self.root, [UNIT['name']], ninja='ninja')
        self.assertEqual(code, 2)
        self.assertIn('Original target changed', result['differences'][0]['error'])

    def test_mismatch_exit_and_duplicate_selection(self):
        different = copy.deepcopy(MATCHED)
        different['left']['sections'][0]['symbols'][1]['match_percent'] = 90.0
        def run(command, root, attempt, label):
            if label == 'objdiff':
                (attempt / 'diff.json').write_text(json.dumps(different))
        with patch.object(batch, 'run_logged', run):
            code, result = batch.run(self.root, [UNIT['name']], no_build=True)
        self.assertEqual(code, 1)
        self.assertEqual(result['mismatched'], 1)
        with self.assertRaises(ValueError):
            batch.run(self.root, [UNIT['name']] * 2)


if __name__ == '__main__':
    unittest.main()
