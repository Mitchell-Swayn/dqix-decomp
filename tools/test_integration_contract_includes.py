"""Existing canonical-header insertions, exact depfiles and rollback/recovery."""
import copy
import os
from pathlib import Path
import shutil
import unittest
from unittest.mock import patch

import integration_contract_includes as inc
import integration_source_contracts as contracts
import integrate_verified_mixed_subset as mixed
from integration_bookkeeping import json_bytes
from integration_lock import integration_guard
import test_integration_source_contracts as fixtures


class IncludeTests(unittest.TestCase):
    write=staticmethod(fixtures.ContractTests.write)
    measures=staticmethod(fixtures.ContractTests.measures)
    work=fixtures.ContractTests.work
    execute=fixtures.ContractTests.execute
    interrupt=fixtures.ContractTests.interrupt
    seal=fixtures.ContractTests.seal
    prepare=fixtures.ContractTests.prepare
    assert_restored=fixtures.ContractTests.assert_restored

    def setUp(self):
        fixtures.ContractTests.setUp(self)
        self.source='src/Owner.cpp';self.dep='build/usa/src/Owner.d';self.target='build/usa/src/Owner.o'
        self.write(self.root/'include/Base.h','#pragma once\n');self.write(self.root/'include/Types.h','#pragma once\n#include <Leaf.h>\nstruct CanonicalVector {int x,y,z;};\n');self.write(self.root/'include/Leaf.h','#pragma once\ntypedef int Scalar;\n')
        for source in self.before:
            self.before[source]='#include <Base.h>\nARM\n'+self.before[source]
            prefix='#include <Base.h>\n'+('#include <Types.h>\n' if source==self.source else '')+'ARM\n'
            self.after[source]=prefix+self.after[source]
            self.write(self.root/source,self.before[source]);self.write(self.worker/source,self.after[source])
            row=next(r for r in self.manifest['source_contracts']['files'] if r['path']==source)
            row['before_sha256']=contracts.digest(self.before[source].encode());row['after_sha256']=contracts.digest(self.after[source].encode());self.manifest['source_hashes'][source]=row['after_sha256']
        self.before_dep=(self.target+': '+self.source+' \\\n\t/bench/project/include/Base.h\n').encode()
        self.after_dep=(self.target+': '+self.source+' \\\n\t/bench/project/include/Base.h \\\n\t/bench/project/include/Types.h \\\n\t/bench/project/include/Leaf.h\n').encode()
        self.write(self.root/self.dep,self.before_dep);self.write(self.worker/self.dep,self.after_dep)
        self.block=dict(directives=[dict(after='#include <Base.h>',directive='#include <Types.h>',header='include/Types.h')],headers_sha256={p:contracts.digest((self.root/p).read_bytes()) for p in ('include/Base.h','include/Types.h','include/Leaf.h')},before_depfile_sha256=contracts.digest(self.before_dep),after_depfile_sha256=contracts.digest(self.after_dep))
        next(r for r in self.manifest['source_contracts']['files'] if r['path']==self.source)['include_additions']=self.block
        self.seal();shutil.rmtree(self.preimages);shutil.copytree(self.root,self.preimages)

    def gate(self,root,folder,command,log):
        fixtures.ContractTests.gate(self,root,folder,command,log)
        if log=='rollback-validation.log':
            self.write(root/self.dep,self.after_dep if self.mode=='rollback-deps-changed' else self.before_dep)
            return
        self.write(root/self.dep,self.after_dep)
        if self.mode=='include-deps':self.write(root/self.dep,b'unknown compiler/user dependency edit')
        if self.mode=='include-header':self.write(root/'include/Leaf.h',b'unknown header change')
        if self.mode=='include-header-mode':(root/'include/Leaf.h').chmod(0o600)
        if self.mode=='include-dep-mode':(root/self.dep).chmod(0o600)
        if self.mode=='include-stale':os.utime(root/self.dep,ns=(1,1))
        if self.mode=='rollback-deps-changed':raise RuntimeError('full gate failed')

    def test_existing_header_insertion_exact_depfiles_and_zero_credit(self):
        result=self.execute();self.assertTrue(result['accepted']);self.assertEqual(result['functions'],0);self.assertEqual(result['code_bytes'],0)
        self.assertEqual((self.root/self.source).read_text(),self.after[self.source]);self.assertEqual((self.root/self.dep).read_bytes(),self.after_dep)
        journal=__import__('json').loads((self.args.receipts/self.args.label/'mixed-journal.json').read_text());rows={r['path']:r for r in journal['entries']}
        self.assertFalse(rows[self.dep]['generated']);self.assertNotIn('immutable',rows[self.dep]);self.assertTrue(rows['include/Types.h']['immutable']);self.assertTrue(rows['include/Leaf.h']['immutable'])

    def test_metadata_builder_pins_exact_existing_dependency_union(self):
        self.assertEqual(inc.metadata(self.root,self.worker,self.source,self.block['directives']),self.block)

    def test_default_mode_rejects_unlisted_include_addition(self):
        next(r for r in self.manifest['source_contracts']['files'] if r['path']==self.source).pop('include_additions');self.seal()
        with self.assertRaisesRegex(ValueError,'exceed explicit edits'):self.prepare()
        self.assertFalse(self.args.receipts.exists())

    def test_other_directive_or_macro_selector_changes_are_rejected(self):
        row=next(r for r in self.manifest['source_contracts']['files'] if r['path']==self.source)
        row['edits'].append(dict(kind='type',symbol='Getter',before='ARM\n',after='THUMB\n'));self.after[self.source]=self.after[self.source].replace('ARM\n','THUMB\n');self.write(self.worker/self.source,self.after[self.source]);row['after_sha256']=contracts.digest(self.after[self.source].encode());self.manifest['source_hashes'][self.source]=row['after_sha256'];self.write(self.worker/self.dep,self.after_dep);self.seal()
        with self.assertRaisesRegex(ValueError,'other directives'):self.prepare()
        row['edits'][-1].update(before='#include <Types.h>',after='#pragma pack(1)\n#include <Types.h>');self.after[self.source]=self.after[self.source].replace('THUMB\n','ARM\n').replace('#include <Types.h>','#pragma pack(1)\n#include <Types.h>');self.write(self.worker/self.source,self.after[self.source]);row['after_sha256']=contracts.digest(self.after[self.source].encode());self.manifest['source_hashes'][self.source]=row['after_sha256'];self.write(self.worker/self.dep,self.after_dep);self.seal()
        with self.assertRaisesRegex(ValueError,'preprocessor directives'):self.prepare()

    def test_transitive_hash_membership_and_worker_dependency_pins_required(self):
        self.block['headers_sha256'].pop('include/Leaf.h');self.seal()
        with self.assertRaisesRegex(ValueError,'hash membership'):self.prepare()
        self.block['headers_sha256']['include/Leaf.h']=contracts.digest((self.root/'include/Leaf.h').read_bytes());self.block['after_depfile_sha256']='0'*64;self.seal()
        with self.assertRaisesRegex(ValueError,'pre/postimage hash'):self.prepare()

    def test_worker_dependency_missing_leaf_or_unpinned_extra_refused(self):
        for content in (self.after_dep.replace(b' \\\n\t/bench/project/include/Leaf.h',b''),self.after_dep+b'\t/bench/project/include/Side.h\n'):
            self.write(self.root/'include/Side.h','#pragma once\n');self.write(self.worker/self.dep,content);self.block['after_depfile_sha256']=contracts.digest(content);self.seal()
            with self.assertRaisesRegex(ValueError,'complete declared include closure'):self.prepare()

    def test_canonical_resolution_rejects_traversal_duplicates_and_symlinks(self):
        self.block['directives'][0]['directive']='#include <../Types.h>';self.seal()
        with self.assertRaisesRegex(ValueError,'Noncanonical include'):self.prepare()
        self.block['directives'][0]['directive']='#include <Types.h>';self.write(self.root/'libs/Test/include/Types.h',(self.root/'include/Types.h').read_bytes());self.seal()
        with self.assertRaisesRegex(ValueError,'one canonical'):self.prepare()
        shutil.rmtree(self.root/'libs');header=self.root/'include/Types.h';header.rename(self.root/'include/ActualTypes.h');header.symlink_to('ActualTypes.h')
        with self.assertRaisesRegex(ValueError,'escapes tree|Symlinked|escapes its|dependency path escapes|Dependency path escapes'):self.prepare()

    def test_macro_include_closure_and_already_present_header_refused(self):
        self.write(self.root/'include/Types.h','#include SELECTED_HEADER\n');self.write(self.worker/self.dep,self.after_dep);self.seal()
        with self.assertRaisesRegex(ValueError,'literal include'):self.prepare()
        self.block['directives'][0].update(directive='#include "Base.h"',header='include/Base.h');self.seal()
        with self.assertRaisesRegex(ValueError,'already a dependency'):self.prepare()

    def test_include_placement_duplicate_and_conditional_anchors_refused(self):
        directive=self.block['directives'][0]
        with self.assertRaisesRegex(ValueError,'conditional'):inc.insert(b'#if FLAG\n#include <Base.h>\n#endif\n',[directive])
        with self.assertRaisesRegex(ValueError,'Ambiguous'):inc.insert(b'#include <Base.h>\n#include <Base.h>\n',[directive])
        with self.assertRaisesRegex(ValueError,'placement'):inc.protected(b'#include <Base.h>\nARM\n',b'#include <Base.h>\nARM\n#include <Types.h>\n',[directive])

    def test_macro_continuations_cannot_hide_other_directive_edits(self):
        directive=self.block['directives'][0]
        before=b'#include <Base.h>\n#define VALUE \\\n  1\n'
        after=b'#include <Base.h>\n#include <Types.h>\n#define VALUE \\\n  2\n'
        with self.assertRaisesRegex(ValueError,'other directives'):inc.protected(before,after,[directive])
        with self.assertRaisesRegex(ValueError,'macro continuation'):inc.insert(b'#define VALUE \\\n#include <Base.h>\n',[directive])

    def test_baseline_dependency_hash_and_freshness_required(self):
        self.block['before_depfile_sha256']='0'*64;self.seal()
        with self.assertRaisesRegex(ValueError,'pre/postimage hash'):self.prepare()
        self.block['before_depfile_sha256']=contracts.digest(self.before_dep);os.utime(self.root/self.dep,ns=(1,1));self.seal()
        with self.assertRaisesRegex(ValueError,'Stale compiler'):self.prepare()

    def test_dependency_modes_and_freshness_failures_restore_and_rebuild(self):
        for mode in ('include-dep-mode','include-stale','post-gate-failure'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaises((ValueError,RuntimeError)):self.execute()
                self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label)

    def test_unknown_header_or_depfile_edits_keep_failed_rollback_lock(self):
        for mode in ('include-deps','include-header','include-header-mode','rollback-deps-changed'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaises((ValueError,RuntimeError)):self.execute()
                self.assertTrue((self.root/'build/progress/integration.lock').exists())
                shutil.rmtree(self.root);shutil.copytree(self.preimages,self.root)

    def test_partial_install_never_copies_worker_dependency_file(self):
        original=mixed.atomic_write
        def failing(path,data):
            if Path(path)==self.root/'src/Caller.cpp':raise OSError('second TU install failed')
            if Path(path)==self.root/self.dep and data==self.after_dep:raise AssertionError('worker depfile installed')
            return original(path,data)
        with patch.object(mixed,'atomic_write',side_effect=failing):
            with self.assertRaisesRegex(OSError,'second TU'):self.execute()
        self.assert_restored()

    def test_interrupted_after_compiled_depfile_recovery_restores_known_union(self):
        self.mode='post-gate-failure'
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute()
        self.assertEqual((self.root/self.dep).read_bytes(),self.after_dep);self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages;self.mode=None
        with integration_guard(self.root,recovery=True) as transaction:result=mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue(result['recovered_rollback']);self.assert_restored()

    def test_publication_failure_and_interruption_restore_dependency_preimages(self):
        class Failing(fixtures.RenderedBookkeeping):
            def publish(self):super().publish();raise RuntimeError('publication interrupted')
        with self.assertRaisesRegex(RuntimeError,'publication'):self.execute(Failing)
        self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label)
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute(Failing)
        self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages
        with integration_guard(self.root,recovery=True) as transaction:mixed.run(self.args,transaction,self.gate,self.work)
        self.assert_restored()

    def test_corrupt_worker_or_independent_dependency_preimage_refuses_recovery(self):
        self.interrupt()
        for path in (self.worker/self.dep,self.preimages/self.dep):
            before=path.read_bytes();path.write_bytes(b'corrupt retained dependencies')
            with integration_guard(self.root,recovery=True) as transaction:
                with self.assertRaises(ValueError):mixed.run(self.args,transaction,self.gate,self.work)
            self.assertTrue((self.root/'build/progress/integration.lock').exists());path.write_bytes(before)


if __name__=='__main__':unittest.main()
