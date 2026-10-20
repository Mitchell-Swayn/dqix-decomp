"""Atomic new-owner/caller contracts through the unchanged shared transaction."""
import copy
import json
from pathlib import Path
import shutil
import unittest
from unittest.mock import patch

import integration_source_additions as additions
ORIGINAL_DERIVE=additions.derive
import integration_source_contracts as contracts
import integrate_verified_mixed_subset as mixed
from integration_bookkeeping import json_bytes
from integration_lock import integration_guard
import test_integration_source_contracts as fixtures
from test_integration_source_contracts import RenderedBookkeeping


class AdditionTests(unittest.TestCase):
    write=staticmethod(fixtures.ContractTests.write)
    measures=staticmethod(fixtures.ContractTests.measures)
    work=fixtures.ContractTests.work
    execute=fixtures.ContractTests.execute
    interrupt=fixtures.ContractTests.interrupt

    def setUp(self):
        fixtures.ContractTests.setUp(self)
        self.owner='src/Owner.cpp';self.minted='build/usa/delinks/src/Owner.o'
        self.owner_unit=copy.deepcopy(self.config['units'][0]);self.owner_report=copy.deepcopy(self.report['units'][0])
        relative=mixed.delinks_path('ov001');shutil.copytree(self.root/'config',self.worker/'config')
        document=mixed.parse_delinks((self.root/relative).read_text(),allow_empty_sections=True)
        self.write(self.root/relative,document.header+'\n');(self.root/self.owner).unlink();(self.root/self.minted).unlink()
        fallback=dict(name='ov001_0',target_path='build/usa/delinks/ov001_0.o',metadata=dict(complete=False,auto_generated=True))
        self.config['units'][0]=fallback;self.write(self.root/'objdiff.json',json_bytes(self.config));self.write(self.root/fallback['target_path'],'original fallback inventory')
        old=self.report['units'][0];old['name']='ov001_0';old['metadata']=dict(complete=False,auto_generated=True);old['functions'][0].pop('fuzzy_match_percent');old['measures']['matched_functions']=0;old['measures']['matched_code']=0
        self.report['measures']['matched_functions']=2;self.report['measures']['matched_code']=20;self.write(self.root/mixed.REPORT,json_bytes(self.report))
        symbols=self.root/relative.with_name('symbols.txt');symbols.write_text('Getter kind:function(arm,size=0x4) addr:0x02100000\n')
        self.write(self.root/'extract/usa/config.yaml','original module configuration\n');self.write(self.root/'extract/usa/arm9/arm9.bin',b'original instructions')
        self.dsd=self.base/'original-dsd';self.write(self.dsd,b'pinned executable');self.addCleanup(patch.stopall);patch.object(additions,'DSD',self.dsd).start()
        self.derive_patch=patch.object(additions,'derive',side_effect=self.derive).start()
        self.manifest['schema']=additions.SCHEMA;self.manifest['new_sources']=[self.owner];self.manifest['functions'][0]['mode']='arm';self.manifest['source_contracts']['files'].pop(0)
        self.args.source_contract_only=False;self.args.source_contract_additions=True
        self.seal();shutil.rmtree(self.preimages);shutil.copytree(self.root,self.preimages)

    def seal(self):
        if self.manifest['schema']==contracts.SCHEMA:return fixtures.ContractTests.seal(self)
        c=self.manifest['source_contracts'];c['context_sha256']=contracts.context_hashes(self.root);c['dsd_sha256']=contracts.digest(self.dsd.read_bytes());c['original_inputs_sha256']=additions.original_input_hashes(self.root)
        for symbol in c['symbols']:
            before=contracts.references(self.root,symbol['name']);after=contracts.references(self.root,symbol['name'],{s:v.encode() for s,v in self.after.items()})
            symbol['references']=[dict(path=p,before_sha256=before.get(p),after_sha256=after[p],conformance='owner' if p==symbol['owner'] else 'repaired' if p in self.after else 'unchanged',evidence=[self.evidence]) for p in after]
        self.write(self.worker/'manifest.json',json_bytes(self.manifest));self.write(self.review,json_bytes(dict(schema='arm9-source-contract-review-v1',decision='approve',reviewer='independent-reviewer',proposal_sha256=contracts.proposal_sha256(self.manifest),evidence_sha256={r['path']:r['sha256'] for r in c['evidence']})))

    def derive(self,root,maps,manifest,config,rows):
        expected=copy.deepcopy(config);expected['units']=[self.owner_unit if u['name']=='ov001_0' else u for u in expected['units']]
        return dict(objdiff=json_bytes(expected),targets={self.minted:b'independently derived original owner'},target_modes={self.minted:0o644})

    def prepare(self):return additions.prepare(self.root,self.worker,self.manifest,self.review)

    def gate(self,root,folder,command,log):
        self.calls.append((command,log))
        if log=='rollback-validation.log':
            if self.mode=='rollback-failure':raise RuntimeError('rollback verification failed')
            self.write(root/mixed.REPORT,json_bytes(self.report));self.write(root/mixed.ARM7,b'{"stable":true}')
            if self.mode=='rollback-changes-source':self.write(root/'src/Caller.cpp','unknown restored caller')
            return
        expected=self.derive(root,{},self.manifest,json.loads((root/'objdiff.json').read_text()),[])
        self.write(root/'objdiff.json',expected['objdiff']);self.write(root/self.minted,expected['targets'][self.minted]);(root/self.minted).chmod(0o644)
        if self.mode in ('gate-failure','rollback-failure','rollback-changes-source'):raise RuntimeError('full gate failed')
        report=copy.deepcopy(self.report);report['units'][0]=copy.deepcopy(self.owner_report);report['measures']=self.measures(3,24)
        if self.mode=='false-credit':report['measures']['matched_code']+=16
        if self.mode=='denominator':report['measures']['total_code']+=4
        if self.mode=='caller-identity':report['units'][1]['functions'][0]['name']='ChangedCaller'
        if self.mode=='caller-function':report['units'][1]['functions'][0]['fuzzy_match_percent']=99
        if self.mode=='new-function':report['units'][0]['functions'][0]['fuzzy_match_percent']=99
        self.write(root/mixed.REPORT,json_bytes(report))
        if self.mode=='arm7':self.write(root/mixed.ARM7,b'{"changed":true}')
        if self.mode=='minted-target':self.write(root/self.minted,b'tampered original target')
        if self.mode in ('objdiff-target','objdiff-options'):
            cfg=json.loads((root/'objdiff.json').read_text())
            if self.mode=='objdiff-target':cfg['units'][1]['target_path']='build/usa/delinks/substitute.o'
            else:cfg['build_target']=True
            self.write(root/'objdiff.json',json_bytes(cfg))
        self.write(folder/'comparison.json',json_bytes(dict(match=self.mode!='object',units=2,matched=2,errors=0,mismatched=0)))
        for module,count in [('main',2),('ov001',1)]:self.write(folder/('layout-'+module+'.json'),json_bytes(dict(match=self.mode!='layout',functions=count,differences=[])))

    def assert_restored(self):
        fixtures.ContractTests.assert_restored(self)
        self.assertFalse((self.root/self.owner).exists());self.assertFalse((self.root/self.minted).exists())

    def test_atomic_new_owner_and_existing_caller_credit_only_new_range(self):
        result=self.execute();self.assertTrue(result['accepted']);self.assertEqual(result['functions'],1);self.assertEqual(result['code_bytes'],4);self.assertEqual(result['refined_functions'],2);self.assertTrue(result['source_contract_additions']);self.assertNotIn('c_instruction_credit',result)
        self.assertEqual((self.root/self.owner).read_text(),self.after[self.owner]);self.assertEqual((self.root/'src/Caller.cpp').read_text(),self.after['src/Caller.cpp'])
        self.assertEqual(self.calls[0][0].count(mixed.FULL),1);self.assertEqual(self.calls[0][0].count('tools/audit_link_layout.py'),2)
        journal=json.loads((self.args.receipts/self.args.label/'mixed-journal.json').read_text());rows={r['path']:r for r in journal['entries']}
        self.assertFalse(rows['objdiff.json']['generated']);self.assertFalse(rows[self.minted]['generated']);self.assertTrue(rows['build/usa/delinks/src/Caller.o']['immutable'])

    def test_all_binary_report_and_post_gate_failures_restore_atomic_union(self):
        for mode in ('start-failure','gate-failure','post-gate-failure','object','layout','false-credit','denominator','caller-identity','caller-function','new-function','arm7'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaises((RuntimeError,ValueError)):self.execute()
                self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label)

    def test_unknown_new_target_or_comparison_config_preserved_with_lock(self):
        for mode in ('minted-target','objdiff-target','objdiff-options'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaisesRegex(ValueError,'Unrecognized dirty'):self.execute()
                self.assertTrue((self.root/'build/progress/integration.lock').exists())
                shutil.rmtree(self.root);shutil.copytree(self.preimages,self.root)

    def test_partial_caller_then_owner_install_failure_restores_both(self):
        original=mixed.atomic_write
        def failing(path,data):
            if Path(path)==self.root/self.owner:raise OSError('new owner install interrupted')
            return original(path,data)
        with patch.object(mixed,'atomic_write',side_effect=failing):
            with self.assertRaisesRegex(OSError,'owner install'):self.execute()
        self.assert_restored()

    def test_new_owner_inventory_mode_extent_and_unrelated_source_rejected(self):
        self.manifest['functions'][0]['mode']='thumb';self.seal()
        with self.assertRaisesRegex(ValueError,'original symbol inventory'):self.prepare()
        self.manifest['functions'][0]['mode']='arm';self.manifest['new_sources'].append('src/Unrelated.cpp');self.seal()
        with self.assertRaisesRegex(ValueError,'exactly one selected function'):self.prepare()

    def test_v2_zero_credit_entrypoint_cannot_accept_additions(self):
        with self.assertRaisesRegex(ValueError,'manifest fields'):contracts.prepare(self.root,self.worker,self.manifest,self.review)
        with self.assertRaisesRegex(ValueError,'review mode'):mixed.prepare(self.root,self.worker,self.manifest)

    def test_interruption_after_new_target_minted_authenticates_and_restores(self):
        self.interrupt();self.assertTrue((self.root/self.minted).exists())
        with integration_guard(self.root,recovery=True) as transaction:result=mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue(result['recovered_rollback']);self.assert_restored()

    def test_recovery_rederives_objdiff_and_target_postimages(self):
        self.interrupt();original=self.derive
        def different(*args):
            result=original(*args);result['targets'][self.minted]=b'changed expected target';return result
        self.derive_patch.side_effect=different
        with integration_guard(self.root,recovery=True) as transaction:
            with self.assertRaisesRegex(ValueError,'postimage'):mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_publication_interruption_and_failure_roll_back_new_and_existing(self):
        class Failing(RenderedBookkeeping):
            def publish(self):super().publish();raise RuntimeError('publication interrupted')
        with self.assertRaisesRegex(RuntimeError,'publication'):self.execute(Failing)
        self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label)
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute(Failing)
        self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages
        with integration_guard(self.root,recovery=True) as transaction:mixed.run(self.args,transaction,self.gate,self.work)
        self.assert_restored()

    def test_failed_rollback_verification_retains_publication_lock(self):
        self.mode='rollback-failure'
        with self.assertRaisesRegex(RuntimeError,'rollback verification'):self.execute()
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_original_module_input_and_tool_drift_rejected_after_full_gate(self):
        original=self.gate
        def gate(root,folder,command,log):
            original(root,folder,command,log)
            if log=='validation.log':self.write(root/'extract/usa/arm9/arm9.bin',b'unknown input mutation')
        with integration_guard(self.root) as transaction:
            with self.assertRaisesRegex(ValueError,'Unrecognized dirty immutable'):mixed.run(self.args,transaction,gate,self.work,RenderedBookkeeping)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_independent_derivation_reproduces_baseline_and_rejects_old_unit_changes(self):
        self.config['custom_make']='ninja'
        self.config['units'][1]['scratch'].update(compiler='pinned',c_flags='-O2')
        self.write(self.root/'objdiff.json',json_bytes(self.config));self.seal()
        rows=[self.manifest['functions'][0]]
        maps={mixed.delinks_path('ov001').as_posix():(self.worker/mixed.delinks_path('ov001')).read_bytes()}
        expected=self.derive(self.root,maps,self.manifest,self.config,rows)
        def run(argv,cwd,**kwargs):
            self.assertEqual(kwargs['umask'],0o022)
            stage=Path(cwd)
            if argv[1]=='objdiff':
                has_new=b'src/Owner.cpp:' in (stage/mixed.delinks_path('ov001')).read_bytes()
                cfg=json.loads(expected['objdiff']) if has_new else copy.deepcopy(self.config)
                if self.mode=='baseline-drift' and not has_new:cfg['custom_make']='substitute'
                if self.mode=='derived-options' and has_new:cfg['custom_make']='substitute'
                if self.mode=='derived-old-target' and has_new:cfg['units'][1]['target_path']='build/usa/delinks/substitute.o'
                self.write(stage/'objdiff.json',json_bytes(cfg))
            else:
                self.write(stage/self.minted,expected['targets'][self.minted]);(stage/self.minted).chmod(0o644)
        with patch.object(additions.subprocess,'run',side_effect=run):
            result=ORIGINAL_DERIVE(self.root,maps,self.manifest,self.config,rows)
            self.assertEqual(result['objdiff'],expected['objdiff']);self.assertEqual(result['targets'],expected['targets'])
            for mode in ('baseline-drift','derived-options','derived-old-target'):
                self.mode=mode
                with self.assertRaisesRegex(ValueError,'reproduce|options changed|existing source comparison'):ORIGINAL_DERIVE(self.root,maps,self.manifest,self.config,rows)
        self.assertEqual((self.root/'objdiff.json').read_bytes(),json_bytes(self.config));self.assertFalse((self.root/self.minted).exists())

    def test_external_dsd_drift_retains_rollback_publication_lock(self):
        original=self.gate
        def gate(root,folder,command,log):
            original(root,folder,command,log)
            if log=='validation.log':self.dsd.write_bytes(b'changed external tool')
        with integration_guard(self.root) as transaction:
            with self.assertRaisesRegex(ValueError,'restored original tool'):mixed.run(self.args,transaction,gate,self.work,RenderedBookkeeping)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_wrapper_holds_same_guard_and_rejects_mixed_mode_combination(self):
        import runpy,sys
        argv=['gate','--project',str(self.root),'--worker',str(self.worker),'--manifest','manifest.json','--receipts',str(self.args.receipts),'--label','contracts','--source-contract-additions','--contract-review',str(self.review)]
        def invoked(args,transaction):self.assertIsNotNone(transaction.stream);self.assertTrue(args.source_contract_additions);self.assertFalse(transaction.changed)
        with patch.object(sys,'argv',argv),patch.object(mixed,'run',side_effect=invoked) as call:runpy.run_path(str(Path(mixed.__file__).with_name('integrate_verified_subset.py')),run_name='__main__')
        self.assertEqual(call.call_count,1)


if __name__=='__main__':unittest.main()
