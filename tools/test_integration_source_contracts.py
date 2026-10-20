"""Scope, artifact and failure-injection tests for the reviewed contract mode."""
import copy
import json
from pathlib import Path
import shutil
import stat
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

import integrate_verified_mixed_subset as mixed
import integration_source_contracts as contracts
from integration_bookkeeping import Bookkeeping, json_bytes
from integration_lock import integration_guard


class RenderedBookkeeping(Bookkeeping):
    def prepare(self,record,measures,timestamp):
        super().prepare(record,measures,timestamp,render=lambda root,r,a,out:out.write_text('accepted page'))
        (self.stage/'snapshots/contract.json').write_text('{"contract":true}')


class ContractTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup)
        self.base=Path(self.temp.name);self.root=self.base/'main';self.worker=self.base/'worker';self.preimages=self.base/'preimages'
        self.root.mkdir();self.worker.mkdir();self.review=self.base/'independent-review.json';self.calls=[];self.mode=None
        self.before={
            'src/Owner.cpp':'// Original: arm9/ov001 @ 0x02100000; symbol: old_owner; size: 0x4.\nextern "C" void Getter(void) {}\n',
            'src/Caller.cpp':'// Original: arm9/main @ 0x02000000; symbol: old_caller; size: 0x10.\nextern "C" unsigned Getter(void*);\nunsigned Caller(){return Getter(0);}\nvoid Neighbor(){}\n'}
        self.after={
            'src/Owner.cpp':self.before['src/Owner.cpp'].replace('void Getter(void) {}','void* Getter(void* value) {return value;}'),
            'src/Caller.cpp':self.before['src/Caller.cpp'].replace('unsigned Getter(void*);','void* Getter(void*);').replace('return Getter(0);','return (unsigned)Getter(0);')}
        for source,code in self.before.items():self.write(self.root/source,code);(self.root/source).chmod(0o640)
        for source,code in self.after.items():self.write(self.worker/source,code)
        self.write(self.root/'src/AssemblyFallback/caller.inc','bl Getter\n')
        self.write(self.root/'src/UserDirty.cpp','existing unrelated user changes')
        functions=[dict(source='src/Owner.cpp',module='ov001',name='Getter',address='0x02100000',size=4),dict(source='src/Caller.cpp',module='main',name='Caller',address='0x02000000',size=16),dict(source='src/Caller.cpp',module='main',name='Neighbor',address='0x02000010',size=4)]
        for module,source,start,end in [('main','src/Caller.cpp',0x2000000,0x2000014),('ov001','src/Owner.cpp',0x2100000,0x2100004)]:
            relative=mixed.delinks_path(module)
            self.write(self.root/relative,'    .text start:0x%08x end:0x%08x\n\n%s:\n    complete\n    .text start:0x%08x end:0x%08x\n'%(start,end,source,start,end))
            self.write(self.root/relative.with_name('symbols.txt'),'\n'.join('%s kind:function(arm) addr:%s size:0x%x'%(r['name'],r['address'],r['size']) for r in functions if r['module']==module)+'\n')
        self.config=dict(units=[dict(name=s[:-4],target_path='build/usa/delinks/'+s[:-4]+'.o',base_path='build/usa/'+s[:-4]+'.o',scratch=dict(platform='nds_arm9'),metadata=dict(complete=True,source_path=s)) for s in self.before])
        self.write(self.root/'objdiff.json',json_bytes(self.config));self.write(self.root/'tools/configure.py','# pinned builder\n')
        for u in self.config['units']:self.write(self.root/u['target_path'],'original '+u['name'])
        self.report=dict(measures=self.measures(3,24),units=[dict(name=s[:-4],functions=[dict(name=r['name'],size=str(r['size']),fuzzy_match_percent=100,metadata={}) for r in functions if r['source']==s],sections=[dict(name='.text',size=str(sum(r['size'] for r in functions if r['source']==s)),fuzzy_match_percent=100)],measures=self.measures(sum(r['source']==s for r in functions),sum(r['size'] for r in functions if r['source']==s)),metadata=dict(complete=True,source_path=s)) for s in self.before])
        self.write(self.root/mixed.REPORT,json_bytes(self.report));self.write(self.root/mixed.ARM7,b'{"stable":true}')
        self.write(self.root/'build/progress/index.html','prior page')
        self.evidence='evidence/original-calls.md';self.write(self.worker/self.evidence,'Module-qualified original callsites and independently reviewed parameter/return dataflow.')
        edits={
            'src/Owner.cpp':[dict(kind='definition',symbol='Getter',before='void Getter(void) {}',after='void* Getter(void* value) {return value;}')],
            'src/Caller.cpp':[dict(kind='declaration',symbol='Getter',before='unsigned Getter(void*);',after='void* Getter(void*);'),dict(kind='dataflow',symbol='Getter',before='return Getter(0);',after='return (unsigned)Getter(0);')]}
        self.manifest=dict(schema=contracts.SCHEMA,preparer='migration-worker',functions=functions,units=[s[:-4] for s in self.before],source_hashes={s:contracts.digest(c.encode()) for s,c in self.after.items()},source_contracts=dict(files=[dict(path=s,before_sha256=contracts.digest(self.before[s].encode()),after_sha256=contracts.digest(self.after[s].encode()),edits=edits[s]) for s in self.before],symbols=[dict(name='Getter',owner='src/Owner.cpp',references=[])],evidence=[dict(path=self.evidence,sha256=contracts.digest((self.worker/self.evidence).read_bytes()))],context_sha256={}))
        self.args=SimpleNamespace(project=self.root,worker=self.worker,receipts=self.root/'build/receipts',label='contracts',manifest='manifest.json',role='test',recover_failed=False,restore_interrupted=False,preimage_tree=None,source_contract_only=True,contract_review=self.review)
        self.seal();shutil.copytree(self.root,self.preimages)

    @staticmethod
    def write(path,content):
        path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(content if isinstance(content,bytes) else content.encode())

    @staticmethod
    def measures(functions,code):return dict(total_functions=functions,total_code=code,total_data=0,matched_functions=functions,matched_code=code,matched_data=0)

    def seal(self):
        c=self.manifest['source_contracts'];c['context_sha256']=contracts.context_hashes(self.root)
        for symbol in c['symbols']:
            before=contracts.references(self.root,symbol['name']);after=contracts.references(self.root,symbol['name'],{s:v.encode() for s,v in self.after.items()})
            symbol['references']=[dict(path=p,before_sha256=before[p],after_sha256=after[p],conformance='owner' if p==symbol['owner'] else 'repaired' if p in self.after else 'unchanged',evidence=[self.evidence]) for p in before]
        self.write(self.worker/'manifest.json',json_bytes(self.manifest))
        self.write(self.review,json_bytes(dict(schema='arm9-source-contract-review-v1',decision='approve',reviewer='independent-reviewer',proposal_sha256=contracts.proposal_sha256(self.manifest),evidence_sha256={r['path']:r['sha256'] for r in c['evidence']})))

    def prepare(self):return contracts.prepare(self.root,self.worker,self.manifest,self.review)

    def work(self,root,folder,label,phase):
        if self.mode=='start-failure' and phase=='start':raise RuntimeError('workflow start failed')
        if self.mode=='post-gate-failure' and phase=='finish':raise RuntimeError('post full gate failed')
        self.write(root/('build/workflow/'+label+'/'+phase+'.json'),'{"workflow":true}')

    def gate(self,root,folder,command,log):
        self.calls.append((command,log))
        if log=='rollback-validation.log':
            if self.mode=='rollback-failure':raise RuntimeError('rollback verification failed')
            self.write(root/mixed.REPORT,json_bytes(self.report));self.write(root/mixed.ARM7,b'{"stable":true}')
            for depfile in (root/'build/usa/src').rglob('*.d'):depfile.touch()
            if self.mode=='rollback-changes-source':self.write(root/'src/Owner.cpp','changed after restoration')
            return
        if self.mode in ('gate-failure','rollback-failure','rollback-changes-source'):raise RuntimeError('full gate failed')
        report=copy.deepcopy(self.report)
        if self.mode=='denominator':report['measures']['total_code']+=4
        if self.mode=='credit':report['measures']['matched_functions']+=1
        if self.mode=='identity':report['units'][0]['functions'][0]['name']='Alias'
        if self.mode=='function':report['units'][0]['functions'][0]['fuzzy_match_percent']=99
        self.write(root/mixed.REPORT,json_bytes(report))
        if self.mode=='arm7':self.write(root/mixed.ARM7,'{"changed":true}')
        if self.mode=='target':self.write(root/self.config['units'][0]['target_path'],'corrupt original')
        if self.mode=='context':self.write(root/'tools/configure.py','# unauthorized change\n')
        if self.mode=='new-reference':self.write(root/'src/Introduced.cpp','void Surprise(){Getter(0);}')
        if self.mode=='mode':(root/'src/Owner.cpp').chmod(0o600)
        self.write(folder/'comparison.json',json_bytes(dict(match=self.mode!='object',units=2,matched=2,errors=0,mismatched=0)))
        for module,count in [('main',2),('ov001',1)]:self.write(folder/('layout-'+module+'.json'),json_bytes(dict(match=self.mode!='layout',functions=count,differences=[])))

    def execute(self,bookkeeping=RenderedBookkeeping):
        with integration_guard(self.root) as transaction:return mixed.run(self.args,transaction,self.gate,self.work,bookkeeping)

    def assert_restored(self):
        for path in self.preimages.rglob('*'):
            if path.is_file():
                current=self.root/path.relative_to(self.preimages)
                self.assertEqual(current.read_bytes(),path.read_bytes(),str(current))
                self.assertEqual(stat.S_IMODE(current.stat().st_mode),stat.S_IMODE(path.stat().st_mode))
        self.assertFalse((self.root/'build/progress/integration.lock').exists())
        self.assertFalse((self.root/'build/progress/snapshots/contract.json').exists())
        self.assertFalse((self.args.receipts/self.args.label/'receipt.json').exists())

    def test_existing_owner_caller_multi_function_multi_module_zero_credit(self):
        result=self.execute();self.assertTrue(result['accepted']);self.assertEqual(result['functions'],0);self.assertEqual(result['code_bytes'],0);self.assertEqual(result['refined_functions'],3);self.assertEqual(result['c_instruction_credit'],0)
        for source,expected in self.after.items():self.assertEqual((self.root/source).read_text(),expected);self.assertEqual(stat.S_IMODE((self.root/source).stat().st_mode),0o640)
        self.assertEqual(self.calls[0][0].count(mixed.FULL),1);self.assertEqual(self.calls[0][0].count('tools/audit_link_layout.py'),2)
        self.assertEqual((self.args.receipts/self.args.label/'contract-review.json').read_bytes(),self.review.read_bytes())

    def test_all_gate_failures_rollback_without_publishing(self):
        for mode in ('start-failure','gate-failure','post-gate-failure','object','layout','function','identity','credit','denominator','arm7','mode'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaises((RuntimeError,ValueError)):self.execute()
                self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label)

    def test_partial_install_rolls_back_all_source_preimages_and_modes(self):
        original=mixed.atomic_write;count=0
        def failing(path,data):
            nonlocal count
            if Path(path).is_relative_to(self.root/'src'):
                count+=1
                if count==2:raise OSError('second source install failed')
            return original(path,data)
        with patch.object(mixed,'atomic_write',side_effect=failing):
            with self.assertRaisesRegex(OSError,'second source'):self.execute()
        self.assert_restored()

    def test_publication_failure_restores_page_checkpoint_receipt_and_snapshot(self):
        class Failing(RenderedBookkeeping):
            def publish(self):super().publish();raise RuntimeError('publication failed after writes')
        with self.assertRaisesRegex(RuntimeError,'publication'):self.execute(Failing)
        self.assert_restored()

    def test_failed_rollback_and_dirty_restored_state_retain_publication_lock(self):
        for mode in ('rollback-failure','rollback-changes-source'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaises((RuntimeError,ValueError)):self.execute()
                self.assertTrue((self.root/'build/progress/integration.lock').exists())
                shutil.rmtree(self.root);shutil.copytree(self.preimages,self.root)

    def test_unauthorized_target_or_tool_mutation_is_never_overwritten(self):
        for mode in ('target','context'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaisesRegex(ValueError,'Unrecognized dirty'):self.execute()
                self.assertTrue((self.root/'build/progress/integration.lock').exists())
                shutil.rmtree(self.root);shutil.copytree(self.preimages,self.root)

    def test_new_unjournaled_reference_retains_failed_rollback_gate(self):
        self.mode='new-reference'
        with self.assertRaisesRegex(ValueError,'restored reference census'):self.execute()
        self.assertTrue((self.root/'build/progress/integration.lock').exists())
        self.assertTrue((self.root/'src/Introduced.cpp').exists())

    def test_incomplete_reference_census_and_unlisted_edit_rejected(self):
        self.manifest['source_contracts']['symbols'][0]['references'].pop();self.write(self.worker/'manifest.json',json_bytes(self.manifest))
        with self.assertRaisesRegex(ValueError,'review'):self.prepare()
        self.seal();self.manifest['source_contracts']['symbols'][0]['references'].pop();self.write(self.review,json_bytes(dict(schema='arm9-source-contract-review-v1',decision='approve',reviewer='reviewer',proposal_sha256=contracts.proposal_sha256(self.manifest),evidence_sha256={self.evidence:self.manifest['source_contracts']['evidence'][0]['sha256']})))
        with self.assertRaisesRegex(ValueError,'Incomplete contract reference census'):self.prepare()
        self.seal();self.after['src/Caller.cpp']+='void Unlisted(){}\n';self.write(self.worker/'src/Caller.cpp',self.after['src/Caller.cpp']);self.manifest['source_contracts']['files'][1]['after_sha256']=contracts.digest(self.after['src/Caller.cpp'].encode());self.manifest['source_hashes']['src/Caller.cpp']=contracts.digest(self.after['src/Caller.cpp'].encode());self.seal()
        with self.assertRaisesRegex(ValueError,'exceed explicit edits'):self.prepare()

    def test_strict_manifest_mixed_policy_even_empty_rejected(self):
        for key in ('data','dependencies','runtime_append','function_renames','source_refinements','symbol_map_additions'):
            with self.subTest(key=key):
                self.manifest[key]=[]
                with self.assertRaisesRegex(ValueError,'manifest fields'):self.prepare()
                del self.manifest[key]
        with self.assertRaisesRegex(ValueError,'review mode'):mixed.prepare(self.root,self.worker,self.manifest)

    def test_stale_owner_or_context_or_evidence_refused(self):
        (self.root/'src/Owner.cpp').write_text('stale owner')
        with self.assertRaisesRegex(ValueError,'source hash'):self.prepare()
        (self.root/'src/Owner.cpp').write_text(self.before['src/Owner.cpp']);(self.root/'tools/configure.py').write_text('stale tool')
        with self.assertRaisesRegex(ValueError,'context hash'):self.prepare()
        (self.root/'tools/configure.py').write_text('# pinned builder\n');(self.worker/self.evidence).write_text('changed evidence')
        with self.assertRaisesRegex(ValueError,'evidence hash'):self.prepare()

    def test_all_original_tu_functions_and_owned_extent_required(self):
        self.manifest['functions'].pop();self.seal()
        with self.assertRaisesRegex(ValueError,'function inventory'):self.prepare()

    def test_new_incomplete_or_data_owned_unit_refused(self):
        relative=mixed.delinks_path('ov001');original=(self.root/relative).read_text()
        for text in (original.replace('    complete','    incomplete'),original+'    .data start:0x02100004 end:0x02100008\n'):
            (self.root/relative).write_text(text);self.seal()
            with self.assertRaisesRegex(ValueError,'not complete|code only|outside top section'):self.prepare()
        (self.root/relative).write_text(original);self.seal();(self.root/'src/Owner.cpp').unlink()
        with self.assertRaisesRegex(ValueError,'existing ordinary'):self.prepare()

    def test_review_is_external_independent_exact_and_nonsymlink(self):
        review=json.loads(self.review.read_text());review['reviewer']=self.manifest['preparer'];self.write(self.review,json_bytes(review))
        with self.assertRaisesRegex(ValueError,'Independent contract review'):self.prepare()
        self.seal();inside=self.worker/'review.json';shutil.copy2(self.review,inside)
        with self.assertRaisesRegex(ValueError,'outside worker'):contracts.prepare(self.root,self.worker,self.manifest,inside)
        link=self.base/'review-link.json';link.symlink_to(self.review)
        with self.assertRaisesRegex(ValueError,'nonsymlink'):contracts.prepare(self.root,self.worker,self.manifest,link)

    def interrupt(self,bookkeeping=RenderedBookkeeping):
        self.mode='gate-failure'
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute(bookkeeping)
        self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages;self.mode=None

    def test_interrupted_recovery_restores_existing_sources_and_original_targets(self):
        self.interrupt()
        with integration_guard(self.root,recovery=True) as transaction:result=mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue(result['recovered_rollback']);self.assert_restored()

    def test_corrupt_review_or_evidence_or_backup_refuses_recovery(self):
        self.interrupt();folder=self.args.receipts/self.args.label
        for path in (folder/'contract-review.json',folder/'contract-evidence-0000.bin',next(folder.glob('preimage-*.bin'))):
            old=path.read_bytes();path.write_bytes(b'corrupt')
            with integration_guard(self.root,recovery=True) as transaction:
                with self.assertRaises(ValueError):mixed.run(self.args,transaction,self.gate,self.work)
            self.assertTrue((self.root/'build/progress/integration.lock').exists());path.write_bytes(old)

    def test_partial_publication_interruption_recovers_entire_union(self):
        class Interrupted(RenderedBookkeeping):
            def publish(self):super().publish();raise RuntimeError('interrupted publication')
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute(Interrupted)
        self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages
        with integration_guard(self.root,recovery=True) as transaction:mixed.run(self.args,transaction,self.gate,self.work)
        self.assert_restored()

    def test_preprocessor_and_identity_comment_edits_refused(self):
        row=self.manifest['source_contracts']['files'][0];edit=dict(kind='definition',symbol='Getter',before='// Original:',after='// Altered:');row['edits'].insert(0,edit);self.after[row['path']]=self.after[row['path']].replace(edit['before'],edit['after']);self.write(self.worker/row['path'],self.after[row['path']]);row['after_sha256']=contracts.digest(self.after[row['path']].encode());self.manifest['source_hashes'][row['path']]=row['after_sha256'];self.seal()
        with self.assertRaisesRegex(ValueError,'identity lines'):self.prepare()

    def add_header(self):
        source='include/Contract.h';before='extern "C" unsigned Getter(void*);\n';after='extern "C" void* Getter(void*);\n';self.write(self.root/source,before);self.write(self.worker/source,after);self.after[source]=after
        self.manifest['source_contracts']['files'].append(dict(path=source,before_sha256=contracts.digest(before.encode()),after_sha256=contracts.digest(after.encode()),edits=[dict(kind='declaration',symbol='Getter',before=before,after=after)]))
        for unit in self.config['units']:
            self.write((self.root/unit['base_path']).with_suffix('.d'),unit['base_path']+': '+unit['metadata']['source_path']+' /bench/project/include/Contract.h\n')
        self.seal();shutil.rmtree(self.preimages);shutil.copytree(self.root,self.preimages)

    def test_existing_header_install_and_failed_transaction_restore(self):
        self.add_header();self.mode='post-gate-failure'
        with self.assertRaisesRegex(RuntimeError,'post full gate'):self.execute()
        self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label);self.mode=None
        result=self.execute();self.assertTrue(result['accepted']);self.assertEqual((self.root/'include/Contract.h').read_text(),self.after['include/Contract.h'])

    def test_missing_and_stale_depfiles_and_omitted_transitive_tus_refused(self):
        self.add_header();depfile=(self.root/self.config['units'][0]['base_path']).with_suffix('.d');saved=depfile.read_bytes();depfile.unlink()
        with self.assertRaisesRegex(ValueError,'complete compiler depfiles'):self.prepare()
        self.write(depfile,saved);(self.root/'include/Contract.h').touch()
        with self.assertRaisesRegex(ValueError,'Stale compiler depfile'):self.prepare()

    def test_frozen_targets_and_context_are_never_rewritten_during_rollback(self):
        target=self.root/self.config['units'][0]['target_path'];builder=self.root/'tools/configure.py'
        before={p:(p.stat().st_ino,p.stat().st_mtime_ns) for p in (target,builder)}
        self.mode='gate-failure'
        with self.assertRaises(RuntimeError):self.execute()
        self.assertEqual(before,{p:(p.stat().st_ino,p.stat().st_mtime_ns) for p in before})
        self.assertGreater((self.root/'src/Owner.cpp').stat().st_mtime_ns,(self.preimages/'src/Owner.cpp').stat().st_mtime_ns)

    def test_nonstandard_header_and_fallback_extensions_in_reference_census(self):
        for extension in ('.inl','.ipp','.hh','.S'):
            self.write(self.root/('src/Reference'+extension),'Getter')
        self.seal()
        self.assertTrue(all('src/Reference'+e in contracts.references(self.root,'Getter') for e in ('.inl','.ipp','.hh','.S')))

    def test_unsupported_source_extension_reference_fails_closed(self):
        self.write(self.root/'src/Unsupported.cc','Getter');self.seal()
        with self.assertRaisesRegex(ValueError,'source caller comparison units'):self.prepare()

    def test_unchanged_ordinary_caller_must_be_compared(self):
        self.write(self.root/'src/UnlistedCaller.cpp','void Other(){Getter(0);}')
        self.seal()
        with self.assertRaisesRegex(ValueError,'source caller comparison units'):self.prepare()

    def test_same_function_alias_or_wrong_extent_refused(self):
        self.manifest['functions'].append(copy.deepcopy(self.manifest['functions'][0]));self.seal()
        with self.assertRaisesRegex(ValueError,'Duplicate/aliased'):self.prepare()
        self.manifest['functions'].pop();self.manifest['functions'][0]['address']='0x02100004';self.seal()
        with self.assertRaisesRegex(ValueError,'function inventory'):self.prepare()

    def test_changed_header_transitive_uncompiled_source_refused(self):
        self.add_header()
        self.write(self.root/'include/Wrapper.h','#include <Contract.h>\n')
        self.write(self.root/'src/Indirect.cpp','#include <Wrapper.h>\nvoid Other(){}\n')
        self.seal()
        with self.assertRaisesRegex(ValueError,'header-dependent source TUs'):self.prepare()

    def test_stale_preimage_before_first_install_refused(self):
        plan,snapshots,dependencies,maps,changes,audit=self.prepare()
        folder=self.root/'build/test-journal';folder.mkdir(parents=True)
        journal=mixed.recovery.make_journal(self.root,folder,json_bytes(self.manifest),changes,set())
        (self.root/'src/Owner.cpp').write_text('changed after capture')
        with self.assertRaisesRegex(ValueError,'reference census|preimage changed'):contracts.verify_preimages(self.root,audit,journal)

    def test_unchanged_symbol_header_macro_alias_requires_all_dependent_tus(self):
        self.write(self.root/'include/Alias.h','#define IndirectGetter Getter\n')
        self.write(self.root/'src/MacroCaller.cpp','#include <Alias.h>\nvoid Other(){IndirectGetter(0); }\n')
        for unit in self.config['units']:
            self.write((self.root/unit['base_path']).with_suffix('.d'),unit['base_path']+': '+unit['metadata']['source_path']+'\n')
        self.seal()
        with self.assertRaisesRegex(ValueError,'header-dependent source TUs'):self.prepare()

    def test_wrapper_holds_global_guard_for_contract_mode(self):
        import runpy,sys
        argv=['gate','--project',str(self.root),'--worker',str(self.worker),'--manifest','manifest.json','--receipts',str(self.args.receipts),'--label','contracts','--source-contract-only','--contract-review',str(self.review)]
        def invoked(args,transaction):self.assertIsNotNone(transaction.stream);self.assertTrue(args.source_contract_only);self.assertFalse(transaction.changed)
        with patch.object(sys,'argv',argv),patch.object(mixed,'run',side_effect=invoked) as call:runpy.run_path(str(Path(mixed.__file__).with_name('integrate_verified_subset.py')),run_name='__main__')
        self.assertEqual(call.call_count,1)


if __name__=='__main__':unittest.main()
