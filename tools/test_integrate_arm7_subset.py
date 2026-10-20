import copy
import hashlib
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

import integrate_arm7_subset as gate


def unit(name='SoundTest'):
    return dict(name=name, source='config/usa/arm7/src/' + name + '.c', autoload='wram',
                runtime_address=0x3800100, payload_offset=0x100, size=8, code_bytes=4,
                literal_pool_bytes=4, symbols={'ARM7_Test': 0x3800100}, externals={}, entry='ARM7_Test')


def measures():
    return dict(payload_bytes=100, total_bss_bytes=20, function_count=None, payload_sha1='original',
                reviewed_assembly_bytes=0, reviewed_assembly_functions=0, source_code_bytes=4,
                source_literal_pool_bytes=0, source_data_bytes=0, source_bss_bytes=0,
                source_functions=1, binary_fallback_bytes=96, unreconstructed_bss_bytes=20,
                module_check_passed=True, source_symbol_checks_passed=True, units=[])


class Arm7GateTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root, self.worker = Path(self.temp.name)/'main', Path(self.temp.name)/'worker'
        for directory in (self.root, self.worker):
            (directory/'config/usa/arm7/src').mkdir(parents=True)
        self.source = unit()['source']
        self.content = b'void ARM7_Test(void) {}\n'
        (self.worker/self.source).write_bytes(self.content)
        self.manifest = {'unit_names': ['SoundTest'], 'files': [{'path': self.source,
                        'sha256': hashlib.sha256(self.content).hexdigest()}]}
        self.current = {'schema_version': 1, 'units': []}
        self.candidate = {**self.current, 'units': [unit()]}

    def test_merge_existing_units_cannot_mutate_or_disappear(self):
        old = unit('Existing')
        current = {'schema_version': 1, 'units': [old]}
        worker = {'schema_version': 1, 'units': [old, unit()]}
        merged, added = gate.merge_units(current, worker, ['SoundTest'])
        self.assertEqual(merged['units'][0], old)
        for bad in ({**worker, 'schema_version': 2}, {**worker, 'units': [unit()]},
                    {**worker, 'units': [{**old, 'size': 12}, unit()]},
                    {**worker, 'units': [old, unit(), unit()]}):
            with self.assertRaises(ValueError):
                gate.merge_units(current, bad, ['SoundTest'])
        with self.assertRaises(ValueError):
            gate.merge_units({**current, 'units': [old, old]}, worker, ['SoundTest'])

    def test_no_existing_names_or_assembly_credit(self):
        for names in ([], ['SoundTest', 'SoundTest'], ['Missing']):
            with self.assertRaises(ValueError):
                gate.merge_units(self.current, self.candidate, names)
        for fields in ({'reviewed_assembly_bytes': 8}, {'assembly_exception': 'exception.json'}):
            with self.assertRaises(ValueError):
                gate.merge_units(self.current, {**self.candidate, 'units': [{**unit(), **fields}]}, ['SoundTest'])

    def test_snapshot_hash_existing_file_and_path_safety(self):
        declared, snapshots = gate.capture_snapshots(self.root, self.worker, self.manifest, [unit()])
        self.assertEqual(snapshots[self.source], self.content)
        for source in ('config/usa/arm7/src/../src/SoundTest.c',
                       'config/usa/arm7/src/./SoundTest.c', self.source.replace('/', '//')):
            manifest = copy.deepcopy(self.manifest)
            manifest['files'][0]['path'] = source
            with self.assertRaises(ValueError):
                gate.capture_snapshots(self.root, self.worker, manifest, [{**unit(), 'source': source}])
        (self.root/self.source).write_bytes(self.content)
        with self.assertRaisesRegex(ValueError, 'cannot be overwritten'):
            gate.capture_snapshots(self.root, self.worker, self.manifest, [unit()])
        (self.root/self.source).unlink()
        (self.worker/self.source).write_bytes(self.content + b'changed')
        with self.assertRaisesRegex(ValueError, 'snapshot changed'):
            gate.capture_snapshots(self.root, self.worker, self.manifest, [unit()])

    def test_symlink_escape_and_assembly_are_rejected(self):
        path = self.worker/self.source
        path.unlink()
        outside = self.worker/'outside.c';outside.write_bytes(self.content)
        path.symlink_to(outside)
        with self.assertRaisesRegex(ValueError, 'escaped'):
            gate.capture_snapshots(self.root, self.worker, self.manifest, [unit()])
        path.unlink();content = b'__asm { bx lr }'
        path.write_bytes(content)
        self.manifest['files'][0]['sha256'] = hashlib.sha256(content).hexdigest()
        with self.assertRaisesRegex(ValueError, 'assembly'):
            gate.capture_snapshots(self.root, self.worker, self.manifest, [unit()])

    def test_dangling_target_symlink_cannot_leak_generated_source(self):
        target = self.root/self.source
        target.symlink_to(target.with_name('unowned.c'))
        with self.assertRaisesRegex(ValueError, 'symlink'):
            gate.capture_snapshots(self.root, self.worker, self.manifest, [unit()])
        self.assertFalse(target.with_name('unowned.c').exists())

    def test_exact_classification_and_arm9_invariance(self):
        before = measures();after = {**before, 'source_code_bytes': 8, 'source_literal_pool_bytes': 4,
                                    'source_functions': 2, 'binary_fallback_bytes': 88}
        gate.verify_deltas({'matched': 1}, {'matched': 1}, before, after, [unit()])
        for key in ('source_code_bytes', 'source_literal_pool_bytes', 'source_data_bytes',
                    'source_bss_bytes', 'source_functions', 'binary_fallback_bytes',
                    'unreconstructed_bss_bytes', 'payload_bytes', 'total_bss_bytes'):
            with self.assertRaises(ValueError):
                gate.verify_deltas({}, {}, before, {**after, key: after[key] + 1}, [unit()])
        with self.assertRaisesRegex(ValueError, 'ARM9'):
            gate.verify_deltas({'matched': 1}, {'matched': 2}, before, after, [unit()])

    def test_builder_provenance_is_bound_to_snapshot_not_current_source(self):
        (self.root/self.source).write_bytes(self.content)
        (self.root/gate.CONFIG).write_text(json.dumps(self.candidate))
        report = {'units': [{**unit(), 'source_sha1': hashlib.sha1(self.content).hexdigest()}]}
        gate.verify_snapshots(self.root, {self.source: self.content}, self.candidate, report, [unit()])
        changed = self.content + b'/* changed source */'
        (self.root/self.source).write_bytes(changed)
        report['units'][0]['source_sha1'] = hashlib.sha1(changed).hexdigest()
        with self.assertRaisesRegex(ValueError, 'snapshot changed'):
            gate.verify_snapshots(self.root, {self.source: self.content}, self.candidate, report, [unit()])
        (self.root/self.source).write_bytes(self.content)
        with self.assertRaisesRegex(ValueError, 'Builder source snapshot'):
            gate.verify_snapshots(self.root, {self.source: self.content}, self.candidate, report, [unit()])
        (self.root/gate.CONFIG).write_text(json.dumps({**self.candidate, 'schema_version': 2}))
        with self.assertRaisesRegex(ValueError, 'configuration changed'):
            gate.verify_snapshots(self.root, {self.source: self.content}, self.candidate, report, [unit()])

    def test_real_inventory_rejects_range_overlap_and_wrong_runtime(self):
        project = Path(__file__).resolve().parents[1]
        from arm7_build import validate_layout
        from check_arm7 import read_arm7
        original_path = gate.original_rom_path(project)
        if not original_path.exists():
            self.skipTest('Original ROM unavailable')
        _, payload = read_arm7(original_path)
        baseline = json.loads((project/'config/usa/arm7/baseline.json').read_text())
        config = json.loads((project/gate.CONFIG).read_text())
        validate_layout(payload, baseline, config)
        old = config['units'][0]
        new = {**unit(), 'autoload': old['autoload'], 'payload_offset': old['payload_offset'],
               'runtime_address': old['runtime_address']}
        with self.assertRaisesRegex(ValueError, 'overlaps'):
            validate_layout(payload, baseline, {**config, 'units': config['units'] + [new]})
        changed = copy.deepcopy(config)
        changed['units'][0]['runtime_address'] += 4
        with self.assertRaisesRegex(ValueError, 'runtime mapping'):
            validate_layout(payload, baseline, changed)

    def test_original_rom_mount_translation_and_explicit_override(self):
        link = self.root/'original-link.nds'
        link.symlink_to('/inputs/original.nds')
        with patch('rom_inputs.input_rom', return_value=link):
            self.assertEqual(gate.original_rom_path(self.root), gate.INPUTS/'original.nds')
            self.assertEqual(gate.original_rom_path(self.root, self.root/'explicit.nds'), self.root/'explicit.nds')
        other = self.root/'missing.nds'
        with patch('rom_inputs.input_rom', return_value=other):
            self.assertEqual(gate.original_rom_path(self.root), other)

    def test_post_build_rejection_restores_sources_config_reports_and_gate(self):
        self.run_rejection()

    def test_mutated_source_during_validation_is_rolled_back(self):
        self.run_rejection(source_changed=True)

    def test_failed_rollback_retains_publication_gate(self):
        self.run_rejection(rollback_failed=True)

    def run_rejection(self, source_changed=False, rollback_failed=False):
        for path, document in ((gate.CONFIG, self.current), (Path('config/usa/arm7/baseline.json'), {'source_rom_sha1': hashlib.sha1(b'original').hexdigest(), 'payload_sha1': 'payload'}),
                               (Path('build/usa/report.json'), {'measures': {'matched': 1}}),
                               (Path('build/usa/arm7/report.json'), measures())):
            (self.root/path).parent.mkdir(parents=True, exist_ok=True)
            (self.root/path).write_text(json.dumps(document))
        (self.root/'original.nds').write_bytes(b'original')
        (self.worker/gate.CONFIG).write_text(json.dumps(self.candidate))
        (self.worker/'manifest.json').write_text(json.dumps(self.manifest))
        calls = []
        def build(command, **kwargs):
            calls.append(command)
            if len(calls) == 1:
                self.assertTrue((self.root/'build/progress/integration.lock').exists())
                after = {**measures(), 'source_code_bytes': 8, 'source_literal_pool_bytes': 4,
                         'source_functions': 2, 'binary_fallback_bytes': 88}
                if source_changed:
                    (self.root/self.source).write_bytes(self.content + b'/* changed */')
                else:
                    after['source_code_bytes'] += 1  # Wrong classification delta.
                after['units'] = [{**unit(), 'source_sha1': hashlib.sha1((self.root/self.source).read_bytes()).hexdigest()}]
                (self.root/'build/usa/arm7/report.json').write_text(json.dumps(after))
            elif rollback_failed:
                self.assertTrue((self.root/'build/progress/integration.lock').exists())
                raise RuntimeError('Recovery build failed')
            return None
        argv = ['gate', '--project', str(self.root), '--worker', str(self.worker),
                '--manifest', 'manifest.json', '--receipts', str(self.root/'build/receipts'), '--label', 'rejected']
        with patch.object(sys, 'argv', argv), patch.object(gate, 'validate_layout'), \
             patch('check_arm7.read_arm7', return_value=({'payload_sha1': 'payload'}, b'original')), \
             patch('rom_inputs.input_rom', return_value=self.root/'original.nds'), \
             patch.object(gate.subprocess, 'run', side_effect=build):
            expected_error = RuntimeError if rollback_failed else ValueError
            expected_message = 'Recovery build failed' if rollback_failed else 'snapshot changed' if source_changed else 'coverage delta'
            with self.assertRaisesRegex(expected_error, expected_message):
                gate.main()
        self.assertEqual(len(calls), 2)  # Validation then rollback validation, both under the lock.
        self.assertFalse((self.root/self.source).exists())
        self.assertEqual(json.loads((self.root/gate.CONFIG).read_text()), self.current)
        self.assertEqual(json.loads((self.root/'build/usa/arm7/report.json').read_text()), measures())
        self.assertEqual((self.root/'build/progress/integration.lock').exists(), rollback_failed)
        if not rollback_failed:
            self.assertTrue(json.loads((self.root/'build/receipts/rejected/failure.json').read_text())['rollback_verified'])


if __name__ == '__main__':
    unittest.main()
