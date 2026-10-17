"""Driver transaction tests for an SDK runtime append with a deliberately mocked compiler/ROM validator.
They prove policy/source/map ownership, rollback and assembly-vs-C accounting, not ROM acceptance.
"""
import contextlib
import hashlib
import io
import json
from pathlib import Path
import runpy
import subprocess
import sys
import unittest
from unittest.mock import patch

import test_runtime_support as fixtures


ALIASES = [('src/RuntimeSupport/_fdiv.cpp', '.L_0200c274', 256), ('src/RuntimeSupport/_ddiv.cpp', '.L_0200d484', 256),
           ('src/RuntimeSupport/_u32_div_f.cpp', '.L_0200d158', 500)]
DELINKS = Path('config/usa/arm9/delinks.txt')
HEADER = '    .text start:0x02000000 end:0x02000200 kind:code align:4\n'


class AppendDriverTests(unittest.TestCase):
    def setUp(self):
        case = fixtures.SdkAppendTests('test_capture_never_writes_main')
        case.setUp()
        self.addCleanup(case.temp.cleanup)
        self.case, self.main, self.worker, self.manifest = case, case.main, case.worker, case.manifest
        self.source = case.row()['source']
        self.label = 'append'
        self.receipts = self.main / 'build/run'
        self.receipts.mkdir(parents=True)
        # An accepted compiler helper whose bytes/source the audit can re-verify.
        data = bytearray(0x200)
        data[0x40:0x60] = case.ORIGINAL
        old = case.old
        old_source = self.main / old['source']
        old_source.parent.mkdir(parents=True, exist_ok=True)
        old_source.write_text('// Compiler runtime support: _fmul\nextern "C" asm void _fmul() { bx lr }\n')
        old.update(source_sha256=hashlib.sha256(old_source.read_bytes()).hexdigest(),
                   original_sha256=hashlib.sha256(data[0x100:0x110]).hexdigest())
        case.policy_document['report_aliases'] = [dict(source=s, name=n, size=z) for s, n, z in ALIASES]
        case.policy.write_text(json.dumps(case.policy_document, indent=2) + '\n')
        self.policy_before = case.policy.read_bytes()
        for source, _, _ in ALIASES:
            alias = self.main / source
            alias.write_text('// Compiler runtime support\nextern "C" asm void x() { bx lr }\n')
        self.module = bytes(data)
        self.before = {'total_functions': 10, 'total_code': '100', 'total_data': '16',
                       'matched_functions': 5, 'matched_code': '60', 'matched_data': '0'}
        self.after = {**self.before, 'matched_functions': 6, 'matched_code': '92'}
        (self.main / DELINKS).parent.mkdir(parents=True, exist_ok=True)
        self.delinks_before = HEADER
        (self.main / DELINKS).write_text(HEADER)
        (self.worker / DELINKS).parent.mkdir(parents=True, exist_ok=True)
        (self.worker / DELINKS).write_text(HEADER + '\n' + self.source + ':\n    complete\n    .text start:0x02000040 end:0x02000060\n')
        self.symbols = self.main / 'config/usa/arm9/symbols.txt'
        self.symbols.write_text('Fill kind:function(arm,size=0x20) addr:0x02000040\n')
        self.symbols_before = self.symbols.read_bytes()
        self.manifest.update(module='main')
        self.manifest['source_hashes'] = {self.source: case.row()['source_sha256']}
        self.manifest['units'] = [self.source[:-4]]
        (self.worker / 'manifest.json').write_text(json.dumps(self.manifest))
        self.write_report(self.before, accepted=False)
        self.progress = self.main / 'build/progress'
        self.progress.mkdir(parents=True)
        self.workflow = self.main / 'build/workflow' / self.label
        self.commands = []

    def write_report(self, measures, accepted):
        units = [{'name': s[:-4], 'metadata': {'auto_generated': False, 'source_path': s}, 'measures': {},
                  'functions': [{'name': n, 'size': z, 'fuzzy_match_percent': 100}]} for s, n, z in ALIASES]
        units.append({'name': 'src/RuntimeSupport/_fmul', 'metadata': {'auto_generated': False, 'source_path': 'src/RuntimeSupport/_fmul.cpp'},
                      'measures': {'total_code': 16, 'matched_code': 16}, 'functions': [{'name': '_fmul', 'size': 16, 'fuzzy_match_percent': 100}]})
        if accepted:
            units.append({'name': 'src/RuntimeSupport/Fill', 'metadata': {'auto_generated': False, 'source_path': self.source},
                          'measures': {'total_code': 32, 'matched_code': 32},
                          'functions': [{'name': 'Fill', 'size': 32, 'fuzzy_match_percent': 100}]})
        for unit in units:
            unit['measures'] = {'total_code': 0, 'matched_code': 0, 'total_functions': 0, 'matched_functions': 0, **unit['measures']}
            if unit['measures']['total_code']:
                unit['measures'].update(total_functions=1, matched_functions=1)
        rest = {k: int(v) for k, v in measures.items()}
        for unit in units:
            for key, value in unit['measures'].items():
                rest[key] -= value
        units.append({'name': 'main_0', 'metadata': {'auto_generated': True}, 'measures': rest})
        path = self.main / 'build/usa/report.json'
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps({'measures': measures, 'units': units}))
        (self.main / 'build/usa/build').mkdir(parents=True, exist_ok=True)
        (self.main / 'build/usa/build/arm9.bin').write_bytes(self.module)

    def run_gate(self, fail_validation=False):
        def command(argv, **kwargs):
            self.assertTrue((self.progress / 'integration.lock').exists(), argv)
            self.commands.append(argv)
            if argv[0] == 'sudo':
                if 'rollback' in Path(kwargs['stdout'].name).name:
                    self.write_report(self.before, accepted=False)
                elif fail_validation:
                    raise subprocess.CalledProcessError(1, argv)
                else:
                    self.assertTrue((self.main / self.source).exists())
                    self.assertEqual(len(json.loads(fixtures_policy().read_text())['functions']), 2)
                    self.write_report(self.after, accepted=True)
            elif argv[:2] == ['python3', 'tools/work_batch.py']:
                self.workflow.mkdir(parents=True, exist_ok=True)
                (self.workflow / (argv[2] + '.json')).write_text(argv[2])
            else:
                raise AssertionError('Unexpected external command: ' + str(argv))
        fixtures_policy = lambda: self.case.policy

        def render(root, report, arm7, output):
            output.write_bytes(b'page')
            (output.parent / 'snapshots/new.json').write_text('{}')
        argv = ['gate', '--project', str(self.main), '--worker', str(self.worker), '--manifest', 'manifest.json',
                '--receipts', str(self.receipts), '--label', self.label]
        script = Path(__file__).with_name('integrate_verified_subset.py')
        with patch.object(sys, 'argv', argv), patch('subprocess.run', side_effect=command), \
             patch('progress_dashboard.generate', side_effect=render), contextlib.redirect_stdout(io.StringIO()):
            runpy.run_path(str(script), run_name='__main__')

    def test_append_counts_assembly_separately_and_never_as_c(self):
        self.run_gate()
        folder = self.receipts / self.label
        policy = json.loads(self.case.policy.read_text())
        self.assertEqual(policy['functions'][0], self.case.old)
        self.assertEqual([r['name'] for r in policy['functions']], ['_fmul', 'Fill'])
        self.assertEqual(policy['report_aliases'], self.case.policy_document['report_aliases'])
        receipt = json.loads((folder / 'receipt.json').read_text())
        self.assertEqual((receipt['functions'], receipt['code_bytes']), (0, 0))
        self.assertEqual((receipt['runtime_assembly_functions'], receipt['runtime_assembly_bytes']), (1, 32))
        self.assertEqual(receipt['c_instruction_credit'], 0)
        ledger = json.loads((self.receipts / 'checkpoint.json').read_text())
        self.assertEqual((ledger['new_functions'], ledger['new_code_bytes']), (0, 0))
        finish = next(c for c in self.commands if c[:2] == ['python3', 'tools/work_batch.py'] and c[2] == 'finish' or c[:3] == ['python3', 'tools/work_batch.py', 'finish'])
        self.assertEqual(finish[finish.index('--runtime-assembly-functions') + 1], '1')
        self.assertEqual(finish[finish.index('--runtime-assembly-bytes') + 1], '32')
        audit = json.loads((folder / 'assembly-audit.json').read_text())
        self.assertEqual(audit['runtime_support']['sdk_reconstruction_bytes'], 32)
        self.assertEqual(audit['runtime_support']['c_instruction_credit'], 0)
        self.assertEqual((self.main / self.source).read_bytes(), (self.worker / self.source).read_bytes())
        self.assertEqual(self.symbols.read_bytes(), self.symbols_before)

    def test_failed_validation_restores_policy_source_delinks_and_maps(self):
        with self.assertRaises(subprocess.CalledProcessError):
            self.run_gate(fail_validation=True)
        self.assertEqual(self.case.policy.read_bytes(), self.policy_before)
        self.assertFalse((self.main / self.source).exists())
        self.assertEqual((self.main / DELINKS).read_text(), self.delinks_before)
        self.assertEqual(self.symbols.read_bytes(), self.symbols_before)
        self.assertEqual(json.loads((self.main / 'build/usa/report.json').read_text())['measures'], self.before)
        self.assertFalse((self.progress / 'integration.lock').exists())
        self.assertFalse(json.loads((self.receipts / self.label / 'failure.json').read_text())['accepted'])

    def test_invalid_append_changes_nothing_in_main(self):
        manifest = json.loads((self.worker / 'manifest.json').read_text())
        manifest['runtime_append']['functions'][0]['source_sha256'] = '0' * 64
        manifest['source_hashes'][self.source] = '0' * 64
        (self.worker / 'manifest.json').write_text(json.dumps(manifest))
        with self.assertRaises(ValueError):
            self.run_gate()
        self.assertEqual(self.case.policy.read_bytes(), self.policy_before)
        self.assertFalse((self.main / self.source).exists())
        self.assertEqual((self.main / DELINKS).read_text(), self.delinks_before)
        self.assertEqual([c for c in self.commands if c[0] == 'sudo'], [])


if __name__ == '__main__':
    unittest.main()
