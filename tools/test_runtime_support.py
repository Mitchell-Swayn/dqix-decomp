import json
import hashlib
from pathlib import Path
import tempfile
import unittest

from dependency_rank import current_completion
from runtime_support import capture, excluded, install, report_aliases, restore, summarize, verify, validate_sdk_row
from select_candidates import select


class RuntimePolicyTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        config = self.root / 'config/usa/arm9'
        config.mkdir(parents=True)
        self.policy = config / 'runtime_support.json'
        self.row = dict(module='arm9/main', address='0x02000000', name='_fmul', size=16,
                        classification='runtime_assembly', source='src/Runtime/_fmul.s')
        self.policy.write_text(json.dumps(dict(schema_version=1, functions=[self.row])))

    def test_fallback_selection_excludes_runtime_even_before_source_integration(self):
        config = self.policy.parent
        (config / 'symbols.txt').write_text('_fmul kind:function(arm,size=0x10) addr:0x02000000\n'
                                          'Game kind:function(arm,size=0x10) addr:0x02000010\n')
        report = {'units': [dict(name='main_0', metadata=dict(auto_generated=True),
                                functions=[dict(name='_fmul', size=16), dict(name='Game', size=16)])]}
        self.assertEqual([r['name'] for r in select(self.root, report, 'main', 20, 8, 100)], ['Game'])

    def test_duplicate_runtime_identities_are_rejected(self):
        self.policy.write_text(json.dumps(dict(schema_version=1, functions=[self.row, self.row])))
        with self.assertRaises(ValueError):
            excluded(self.root)

    def test_matched_assembly_satisfies_caller_readiness(self):
        (self.root / 'src/Runtime').mkdir(parents=True)
        (self.root / self.row['source']).write_text('// Compiler runtime support\n_fmul: bx lr\n')
        (self.policy.parent / 'delinks.txt').write_text('src/Runtime/_fmul.s:\n'
                                                     '    .text start:0x02000000 end:0x02000010\n')
        report = {'units': [dict(metadata=dict(source_path=self.row['source'], auto_generated=False),
                                functions=[dict(name='_fmul', size=16, fuzzy_match_percent=100)])]}
        nodes = [dict(id='fmul', module='arm9/main', address=0x02000000, name='_fmul', size=16)]
        self.assertEqual(current_completion(self.root, report, nodes), {'fmul'})

    def test_policy_rollback_restores_absence(self):
        self.policy.unlink()
        snapshot = {'before': None, 'after': b'{"schema_version":1,"functions":[]}\n'}
        install(self.root, snapshot)
        self.assertTrue(self.policy.exists())
        restore(self.root, snapshot)
        self.assertFalse(self.policy.exists())

    def replacement(self):
        old = dict(self.row, original_sha256='a'*64, evidence={'library':'test'})
        source = self.root/old['source']
        source.parent.mkdir(parents=True)
        source.write_text('// Compiler runtime support: _fmul.\n_fmul: bx lr\n')
        old['source_sha256']=hashlib.sha256(source.read_bytes()).hexdigest()
        self.policy.write_text(json.dumps(dict(schema_version=1,functions=[old])))
        new = dict(old,source=str(Path(old['source']).with_suffix('.cpp')),assembly_form='codewarrior_inline')
        cpp = self.root/new['source']
        cpp.write_text('// Compiler runtime support: _fmul.\nextern "C" asm void _fmul() { bx lr }\n')
        new['source_sha256']=hashlib.sha256(cpp.read_bytes()).hexdigest()
        function = dict(name='_fmul',address='02000000',size=16,source=new['source'],original_sha256='a'*64)
        return dict(runtime_replacement=True,functions=[function],
                    runtime_support=dict(schema_version=1,functions=[new]))

    def test_inline_replacement_and_policy_rollback(self):
        manifest=self.replacement()
        before=self.policy.read_bytes()
        snapshot=capture(self.root,self.root,manifest)
        install(self.root,snapshot)
        self.assertEqual(json.loads(self.policy.read_text())['functions'][0]['assembly_form'],'codewarrior_inline')
        restore(self.root,snapshot)
        self.assertEqual(self.policy.read_bytes(),before)

    def test_inline_replacement_refuses_changed_identity(self):
        manifest=self.replacement()
        manifest['runtime_support']['functions'][0]['evidence']={'library':'different'}
        with self.assertRaises(ValueError):
            capture(self.root,self.root,manifest)

    def test_inline_replacement_refuses_modified_old_source(self):
        manifest=self.replacement()
        (self.root/self.row['source']).write_text('modified original source')
        with self.assertRaises(ValueError):
            capture(self.root,self.root,manifest)

    def test_acceptance_refuses_unbound_runtime_source(self):
        manifest = dict(functions=[dict(source='src/Other.s')],
                        runtime_support=dict(schema_version=1, functions=[self.row]))
        with self.assertRaises(ValueError):
            capture(self.root, self.root, manifest)


SDK_PHRASE = 'SDK support (community reconstruction):'


class SdkAppendTests(unittest.TestCase):
    """Append transaction for community-reconstructed SDK assembly; evidence is hash-bound, never vendor."""
    ORIGINAL = bytes(range(32))

    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.main = Path(self.temp.name) / 'main'
        self.worker = Path(self.temp.name) / 'worker'
        for root in (self.main, self.worker):
            root.mkdir()
        (self.main / 'config/usa/arm9').mkdir(parents=True)
        (self.main / 'extract/usa/arm9').mkdir(parents=True)
        (self.main / 'extract/usa/arm9/arm9.bin').write_bytes(bytes(0x40) + self.ORIGINAL)
        self.original = hashlib.sha256(self.ORIGINAL).hexdigest()
        self.old = dict(module='arm9/main', address='0x02000100', name='_fmul', size=16,
                        classification='runtime_assembly', source='src/RuntimeSupport/_fmul.cpp',
                        source_sha256='b' * 64, original_sha256='a' * 64, evidence={'library': 'ds/test.a'},
                        c_reconstruction_eligible=False, assembly_form='codewarrior_inline',
                        inline_metadata=dict(branches=[], aliases=[], symbol_aliases={}))
        self.policy_document = dict(schema_version=1, authorization='test', functions=[self.old],
                                    report_aliases=[])
        self.policy = self.main / 'config/usa/arm9/runtime_support.json'
        self.policy.write_text(json.dumps(self.policy_document, indent=2) + '\n')
        self.manifest = self.build()

    def write(self, relative, content):
        path = self.worker / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        data = content if isinstance(content, bytes) else content.encode()
        path.write_bytes(data)
        return hashlib.sha256(data).hexdigest()

    def build(self, source_text=SDK_PHRASE + ' Fill.\nextern "C" asm void Fill() { bx lr }\n'):
        source = 'src/RuntimeSupport/Fill.cpp'
        source_hash = self.write(source, source_text)
        commit = 'c' * 40
        copy_hash = self.write('build/provenance/fetch/mi.c', 'asm void MI_CpuFill8')
        comparison = dict(function_id='arm9/main:02000040', original_sha256=self.original,
                          original_words=['0'] * 8,
                          variants=dict(expanded=dict(equals_original=True, assembled_sha256=self.original,
                                                      instruction_count=8),
                                        verbatim=dict(equals_original=False, assembled_sha256='f' * 64,
                                                      instruction_count=6)))
        comparison_hash = self.write('build/provenance/cmp.json', json.dumps(comparison))
        result = dict(status='compared', match=True, raw_match=True, object_match=True, mismatches=0,
                      unit='src/RuntimeSupport/Fill', rom_acceptance=False)
        raw = dict(raw_match=True, functions=[dict(symbol='Fill', target_bytes=32, candidate_bytes=32,
                                                  raw_match=True, relocations_present=False)])
        fresh = 'build/runtime_append/fresh/'
        evidence_manifest = self.write('build/provenance/manifest.json', '{}')
        row = dict(module='arm9/main', name='Fill', address='0x02000040', size=32, source=source,
                   source_sha256=source_hash, classification='runtime_assembly', evidence_class='sdk_reconstruction',
                   evidence=dict(origin='community_reconstruction', vendor_archive_match=False, library=None,
                                 object=None, symbols=['MI_CpuFill8'], size=32,
                                 external_sources=[dict(repository='pret/x', commit=commit, path='a/mi.c',
                                                        url='https://example/pret/x/' + commit + '/a/mi.c',
                                                        local_copy='build/provenance/fetch/mi.c', sha256=copy_hash)],
                                 instruction_identity=dict(comparison='build/provenance/cmp.json',
                                                           comparison_sha256=comparison_hash,
                                                           variants=['expanded'], instructions=8),
                                 fresh_object_check=dict(
                                     result=fresh + 'result.json', result_sha256=self.write(fresh + 'result.json', json.dumps(result)),
                                     bytes=fresh + 'bytes.json', bytes_sha256=self.write(fresh + 'bytes.json', json.dumps(raw)),
                                     candidate_source=fresh + 'candidate.cpp', candidate_source_sha256=self.write(fresh + 'candidate.cpp', source_text)),
                                 evidence_manifest=dict(path='build/provenance/manifest.json', sha256=evidence_manifest)),
                   original_sha256=self.original, c_reconstruction_eligible=False, assembly_form='codewarrior_inline',
                   inline_metadata=dict(branches=[], aliases=[], symbol_aliases={}))
        function = dict(name='Fill', address='0x02000040', size=32, source=source, original_sha256=self.original,
                        function_id='arm9/main:02000040')
        return dict(functions=[function], data=[], runtime_append=dict(schema_version=1, functions=[row]))

    def row(self):
        return self.manifest['runtime_append']['functions'][0]

    def assert_refused(self, message=None):
        with self.assertRaises(ValueError) as context:
            capture(self.main, self.worker, self.manifest)
        if message:
            self.assertIn(message, str(context.exception))

    def test_append_preserves_accepted_rows_and_counts_classes_separately(self):
        before = self.policy.read_bytes()
        snapshot = capture(self.main, self.worker, self.manifest)
        after = json.loads(snapshot['after'])
        self.assertEqual(after['functions'][:1], [self.old])
        self.assertEqual({k: v for k, v in after.items() if k != 'functions'},
                         {k: v for k, v in self.policy_document.items() if k != 'functions'})
        self.assertEqual(after['functions'][1], self.row())
        self.assertEqual(snapshot['before'], before)
        counts = summarize(after['functions'])
        self.assertEqual((counts['compiler_runtime_functions'], counts['compiler_runtime_bytes']), (1, 16))
        self.assertEqual((counts['sdk_reconstruction_functions'], counts['sdk_reconstruction_bytes']), (1, 32))
        self.assertEqual((counts['assembly_functions'], counts['assembly_bytes']), (2, 48))
        self.assertEqual((snapshot['appended'], snapshot['appended_bytes']), (['Fill'], 32))
        self.assertIn('Fill', excluded(self.main) and {r['name'] for r in after['functions']})

    def test_rollback_restores_policy_source_and_maps_exactly(self):
        symbols = self.main / 'config/usa/arm9/symbols.txt'
        symbols.write_text('Fill kind:function(arm,size=0x20) addr:0x02000040\n')
        maps = symbols.read_bytes()
        before = self.policy.read_bytes()
        snapshot = capture(self.main, self.worker, self.manifest)
        install(self.main, snapshot)
        verify(self.main, snapshot)
        self.assertEqual(len(json.loads(self.policy.read_text())['functions']), 2)
        self.policy.write_text('tampered')
        with self.assertRaises(ValueError):
            verify(self.main, snapshot)
        restore(self.main, snapshot)
        self.assertEqual(self.policy.read_bytes(), before)
        self.assertEqual(symbols.read_bytes(), maps)
        self.assertFalse((self.main / self.row()['source']).exists())

    def test_capture_never_writes_main(self):
        before = self.policy.read_bytes()
        capture(self.main, self.worker, self.manifest)
        self.assertEqual(self.policy.read_bytes(), before)

    def test_identity_must_match_selected_function(self):
        for key, value in [('name', 'Other'), ('address', '0x02000044'), ('size', 28), ('original_sha256', 'e' * 64)]:
            with self.subTest(key=key):
                self.manifest = self.build()
                self.manifest['functions'][0][key] = value
                self.assert_refused()

    def test_duplicate_identity_is_refused(self):
        for key, value in [('address', '0x02000100'), ('name', '_fmul'), ('source', 'src/RuntimeSupport/_fmul.cpp')]:
            with self.subTest(key=key):
                self.manifest = self.build()
                self.row()[key] = value
                self.manifest['functions'][0]['source'] = self.row()['source']
                self.assert_refused()

    def test_source_hash_and_unselected_rows_are_bound(self):
        self.row()['source_sha256'] = '0' * 64
        self.assert_refused()
        self.manifest = self.build()
        (self.worker / self.row()['source']).write_text(SDK_PHRASE + ' changed')
        self.assert_refused()
        self.manifest = self.build()
        self.manifest['functions'].append(dict(self.manifest['functions'][0], source='src/RuntimeSupport/Other.cpp'))
        self.assert_refused('exactly the selected')

    def test_source_comment_labels_sdk_not_compiler_runtime(self):
        for text in ('Compiler runtime support: Fill.\nextern "C" asm void Fill() { bx lr }\n',
                     SDK_PHRASE + ' Fill. Compiler runtime support: too.\nextern "C" asm void Fill() { bx lr }\n'):
            self.manifest = self.build(text)
            self.assert_refused()

    def test_vendor_fields_cannot_be_fabricated(self):
        for key, value in [('library', 'ds/lib.a'), ('object', 'x.o'), ('vendor_archive_match', True),
                           ('origin', 'vendor_archive'), ('package_sha256', '1' * 64)]:
            with self.subTest(key=key):
                self.manifest = self.build()
                self.row()['evidence'][key] = value
                self.assert_refused()

    def test_pinned_sources_and_commit_must_hold(self):
        source = self.row()['evidence']['external_sources'][0]
        source['commit'] = 'main'
        self.assert_refused('pin')
        self.manifest = self.build()
        (self.worker / 'build/provenance/fetch/mi.c').write_text('substituted')
        self.assert_refused('pinned hash')
        self.manifest = self.build()
        self.row()['evidence']['external_sources'] = []
        self.assert_refused()

    def test_original_byte_hash_is_checked_against_extracted_module(self):
        (self.main / 'extract/usa/arm9/arm9.bin').write_bytes(bytes(0x40) + bytes(32))
        self.assert_refused('Original ARM9 bytes')

    def thumb_identity(self):
        row = self.row()
        row['mode'] = 'thumb'
        identity = row['evidence']['instruction_identity']
        comparison = json.loads((self.worker / identity['comparison']).read_text())
        comparison['original_words'] = ['0'] * 16
        comparison['variants']['expanded']['instruction_count'] = 16
        identity['instructions'] = 16
        identity['comparison_sha256'] = self.write(identity['comparison'], json.dumps(comparison))
        return row, comparison

    def test_thumb_instruction_identity_uses_halfwords(self):
        row, _ = self.thumb_identity()
        validate_sdk_row(self.worker, row, dict(mode='thumb'))

    def test_sdk_invalid_and_mismatched_mode_rejected(self):
        for mode in ('aarch64', '', None):
            with self.subTest(mode=mode), self.assertRaisesRegex(ValueError, 'mode'):
                validate_sdk_row(self.worker, dict(self.row(), mode=mode), {})
        with self.assertRaisesRegex(ValueError, 'mode'):
            validate_sdk_row(self.worker, self.row(), dict(mode='thumb'))

    def test_thumb_instruction_counts_and_alignment_rejected(self):
        row, comparison = self.thumb_identity()
        identity = row['evidence']['instruction_identity']
        for change in ('identity', 'words', 'variant'):
            with self.subTest(change=change):
                row, comparison = self.thumb_identity()
                identity = row['evidence']['instruction_identity']
                if change == 'identity': identity['instructions'] = 8
                elif change == 'words': comparison['original_words'] = ['0'] * 8
                else: comparison['variants']['expanded']['instruction_count'] = 8
                identity['comparison_sha256'] = self.write(identity['comparison'], json.dumps(comparison))
                with self.assertRaisesRegex(ValueError, 'instruction'):
                    validate_sdk_row(self.worker, row, {})
        with self.assertRaisesRegex(ValueError, 'aligned'):
            validate_sdk_row(self.worker, dict(row, size=31), {})

    def test_instruction_identity_must_equal_original(self):
        path = self.worker / 'build/provenance/cmp.json'
        comparison = json.loads(path.read_text())
        comparison['variants']['expanded']['equals_original'] = False
        evidence = self.row()['evidence']['instruction_identity']
        evidence['comparison_sha256'] = self.write('build/provenance/cmp.json', json.dumps(comparison))
        self.assert_refused('does not equal')
        self.manifest = self.build()
        self.row()['evidence']['instruction_identity']['variants'] = ['verbatim']
        self.assert_refused()

    def test_fresh_object_check_must_bind_this_source(self):
        fresh = self.row()['evidence']['fresh_object_check']
        fresh['candidate_source_sha256'] = '2' * 64
        self.assert_refused()
        self.manifest = self.build()
        result = json.loads((self.worker / 'build/runtime_append/fresh/result.json').read_text())
        result['raw_match'] = False
        fresh = self.row()['evidence']['fresh_object_check']
        fresh['result_sha256'] = self.write('build/runtime_append/fresh/result.json', json.dumps(result))
        self.assert_refused('fresh object check')

    def test_evidence_paths_cannot_escape_worker(self):
        outside = Path(self.temp.name) / 'outside.c'
        outside.write_text('x')
        source = self.row()['evidence']['external_sources'][0]
        source['local_copy'] = '../outside.c'
        source['sha256'] = hashlib.sha256(b'x').hexdigest()
        self.assert_refused('inside the worker')

    def test_append_is_exclusive_and_required_for_sdk_rows(self):
        self.manifest['runtime_replacement'] = True
        self.assert_refused('exclusive')
        self.manifest = self.build()
        self.manifest['runtime_support'] = dict(schema_version=1, functions=[self.row()])
        self.assert_refused('exclusive')
        self.manifest = self.build()
        self.policy.unlink()
        self.assert_refused('prior policy')
        self.manifest = self.build()
        self.policy.write_text(json.dumps(self.policy_document))
        self.assert_refused('canonically')
        # The initial acceptance path never admits SDK rows, even without a prior policy.
        self.policy.unlink()
        manifest = dict(functions=self.manifest['functions'],
                        runtime_support=dict(schema_version=1, functions=[self.row()]))
        with self.assertRaisesRegex(ValueError, 'runtime append'):
            capture(self.main, self.worker, manifest)

    def test_non_inline_or_eligible_rows_are_refused(self):
        for key, value in [('assembly_form', 's'), ('c_reconstruction_eligible', True),
                           ('source', 'src/Other/Fill.cpp'), ('classification', 'runtime_existing_c')]:
            with self.subTest(key=key):
                self.manifest = self.build()
                self.row()[key] = value
                self.manifest['functions'][0]['source'] = self.row()['source']
                self.assert_refused()

    def test_compiler_rows_still_require_compiler_phrase(self):
        source = self.worker / 'src/RuntimeSupport/_fmul.cpp'
        source.parent.mkdir(parents=True, exist_ok=True)
        source.write_text(SDK_PHRASE + ' wrongly labelled\nextern "C" asm void _fmul() { bx lr }\n')
        old = dict(self.old, source_sha256=hashlib.sha256(source.read_bytes()).hexdigest())
        manifest = dict(functions=[dict(name='_fmul', address='0x02000100', size=16, source=old['source'],
                                        original_sha256='a' * 64)],
                        runtime_support=dict(schema_version=1, functions=[old]))
        self.policy.unlink()
        with self.assertRaises(ValueError):
            capture(self.main, self.worker, manifest)

    def test_report_aliases_are_not_recounted_by_an_append(self):
        document = dict(self.policy_document)
        names = [('src/RuntimeSupport/_fdiv.cpp', '.L_0200c274', 256), ('src/RuntimeSupport/_ddiv.cpp', '.L_0200d484', 256),
                 ('src/RuntimeSupport/_u32_div_f.cpp', '.L_0200d158', 500)]
        document['report_aliases'] = [dict(source=s, name=n, size=z) for s, n, z in names]
        self.policy.write_text(json.dumps(document, indent=2) + '\n')
        (self.main / 'build/usa').mkdir(parents=True)
        (self.main / 'build/usa/report.json').write_text(json.dumps(dict(units=[
            dict(metadata=dict(source_path=s), functions=[dict(name=n, size=z, fuzzy_match_percent=100)])
            for s, n, z in names])))
        snapshot = capture(self.main, self.worker, self.manifest)
        self.assertEqual(report_aliases(self.main, snapshot), [])
        snapshot.pop('mode')
        self.assertEqual(len(report_aliases(self.main, snapshot)), 3)

    def test_policy_selection_excludes_sdk_helper_from_candidates(self):
        document = json.loads(capture(self.main, self.worker, self.manifest)['after'])
        self.policy.write_text(json.dumps(document, indent=2) + '\n')
        self.assertIn(('arm9/main', 0x02000040), excluded(self.main))
        (self.main / 'config/usa/arm9/symbols.txt').write_text(
            'Fill kind:function(arm,size=0x20) addr:0x02000040\nGame kind:function(arm,size=0x10) addr:0x02000200\n')
        report = {'units': [dict(name='main_0', metadata=dict(auto_generated=True),
                                 functions=[dict(name='Fill', size=32), dict(name='Game', size=16)])]}
        self.assertEqual([r['name'] for r in select(self.main, report, 'main', 20, 8, 100)], ['Game'])


if __name__ == '__main__':
    unittest.main()
