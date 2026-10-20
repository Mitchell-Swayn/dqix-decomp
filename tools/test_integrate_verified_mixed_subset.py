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
from integration_lock import integration_guard
from integration_bookkeeping import Bookkeeping,json_bytes
from arm9_module import delinks_path


class RenderedBookkeeping(Bookkeeping):
    def prepare(self,record,measures,timestamp):
        super().prepare(record,measures,timestamp,render=lambda root,r,a,out:out.write_text('accepted page'))
        (self.stage/'snapshots/new.json').write_text('{"new":true}')


class MixedDriverTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup)
        self.base=Path(self.temp.name);self.root=self.base/'main';self.worker=self.base/'worker';self.preimages=self.base/'preimages'
        self.root.mkdir();self.worker.mkdir();self.calls=[];self.mode=None
        self.manifest=dict(functions=[],units=[],source_hashes={})
        units=[]
        for n in range(7):
            module='ov%03d'%n;p=delinks_path(module)
            header='    .text start:0x02150000 end:0x02151000\n'
            self.write(self.root/p,header);self.write(self.root/p.with_name('symbols.txt'),'')
            blocks=[]
            for i in range(7):
                name='TestModule%dFunction%d'%(n,i);source='src/Util/'+name+'.cpp';address=0x2150000+i*16
                code='// Original: arm9/'+module+' @ 0x%08X; symbol: %s; size: 0x10.\nvoid %s() {}\n'%(address,name,name)
                self.write(self.worker/source,code)
                row=dict(module=module,name=name,source=source,address=hex(address),size=16)
                self.manifest['functions'].append(row);self.manifest['units'].append(source[:-4]);self.manifest['source_hashes'][source]=mixed.recovery.digest(code.encode())
                blocks.append(source+':\n    complete\n    .text start:0x%08x end:0x%08x'%(address,address+16))
            self.write(self.worker/p,header+'\n'+'\n\n'.join(blocks)+'\n')
            units.append(dict(name=module+'_0',measures=self.measures(7,112,0,0),functions=[]))
        self.report=dict(measures=self.measures(49,784,0,0),units=units)
        self.write(self.root/mixed.REPORT,json_bytes(self.report));self.write(self.root/mixed.ARM7,b'{"stable":true}')
        self.write(self.root/'build/progress/index.html','user dirty baseline page')
        self.write(self.root/'src/UserDirty.cpp','preserve my existing edits')
        self.write(self.worker/'manifest.json',json_bytes(self.manifest))
        self.args=SimpleNamespace(project=self.root,worker=self.worker,receipts=self.root/'build/receipts',label='mixed-test',manifest='manifest.json',role='test',recover_failed=False,restore_interrupted=False,preimage_tree=None)
        shutil.copytree(self.root,self.preimages)

    @staticmethod
    def measures(total,code,matched,matched_code):
        return dict(total_functions=total,total_code=code,total_data=0,matched_functions=matched,matched_code=matched_code,matched_data=0)

    @staticmethod
    def write(path,content):
        path.parent.mkdir(parents=True,exist_ok=True)
        path.write_bytes(content if isinstance(content,bytes) else content.encode())

    def work(self,root,folder,label,phase):
        self.write(root/('build/workflow/'+label+'/'+phase+'.json'),'{"workflow":true}')

    def gate(self,root,folder,command,log):
        self.calls.append((command,log))
        if log=='rollback-validation.log':
            if self.mode=='rollback-failure':raise RuntimeError('rollback build failed')
            self.write(root/mixed.REPORT,json_bytes(self.report));self.write(root/mixed.ARM7,b'{"stable":true}')
            if self.mode=='rollback-arm7-format':self.write(root/mixed.ARM7,json.dumps(dict(stable=True),indent=2))
            return
        if self.mode in ('gate-failure','rollback-failure','rollback-arm7-format'):raise RuntimeError('full gate failed')
        if self.mode=='dirty':
            row=self.manifest['functions'][0];self.write(root/row['source'],'human edit during transaction')
            raise RuntimeError('full gate failed')
        report=copy.deepcopy(self.report)
        report['measures']=self.measures(49,784,49,784)
        for unit in report['units']:unit['measures']=self.measures(0,0,0,0)
        for row in self.manifest['functions']:
            report['units'].append(dict(name=row['source'][:-4],measures=self.measures(1,16,1,16),functions=[dict(name=row['name'],size=16,fuzzy_match_percent=100)]))
        if self.mode=='denominator':report['measures']['total_code']+=4
        if self.mode=='function':report['units'][-1]['functions'][0]['fuzzy_match_percent']=99
        if self.mode=='module-gain':report['units'][-1]['measures']['matched_code']-=4
        self.write(root/mixed.REPORT,json_bytes(report))
        if self.mode=='arm7':self.write(root/mixed.ARM7,'{"changed":true}')
        if self.mode=='arm7-format':self.write(root/mixed.ARM7,json.dumps(dict(stable=True),indent=2))
        self.write(folder/'comparison.json',json_bytes(dict(match=self.mode!='object',units=49,matched=49,errors=0,mismatched=0)))
        for n in range(7):self.write(folder/('layout-ov%03d.json'%n),json_bytes(dict(match=self.mode!='layout',functions=7,differences=[])))

    def execute(self,bookkeeping=RenderedBookkeeping):
        with integration_guard(self.root) as transaction:
            return mixed.run(self.args,transaction,self.gate,self.work,bookkeeping)

    def assert_restored(self):
        for p in self.preimages.rglob('*'):
            if p.is_file():self.assertEqual((self.root/p.relative_to(self.preimages)).read_bytes(),p.read_bytes(),str(p))
        for row in self.manifest['functions']:self.assertFalse((self.root/row['source']).exists())
        self.assertFalse((self.root/'build/progress/integration.lock').exists())
        self.assertFalse((self.root/'build/progress/snapshots/new.json').exists())
        self.assertFalse((self.args.receipts/self.args.label/'receipt.json').exists())

    def test_49_across_seven_modules_one_gate_all_layouts_one_publication(self):
        result=self.execute()
        self.assertTrue(result['accepted']);self.assertEqual(result['functions'],49)
        self.assertEqual(len(self.calls),1)
        command=self.calls[0][0]
        self.assertEqual(command.count('tools/configure.py'),1)
        self.assertEqual(command.count(mixed.FULL),1)
        self.assertEqual(command.count('tools/audit_link_layout.py'),7)
        self.assertEqual(command.count('tools/compile_verify_batch.py'),1)
        self.assertTrue((self.args.receipts/self.args.label/'receipt.json').exists())
        self.assertEqual((self.root/'src/UserDirty.cpp').read_text(),'preserve my existing edits')
        self.assertFalse((self.root/'build/progress/integration.lock').exists())

    def test_all_mandatory_gate_failures_restore_entire_union(self):
        for mode in ('gate-failure','object','layout','function','module-gain','denominator','arm7'):
            with self.subTest(mode=mode):
                self.mode=mode
                with self.assertRaises((RuntimeError,ValueError)):self.execute()
                self.assert_restored();shutil.rmtree(self.args.receipts/self.args.label)
        self.assertEqual(len([x for x in self.calls if x[1]=='rollback-validation.log']),7)

    def test_partial_second_map_install_restores_first_and_all_sources(self):
        original=mixed.atomic_write;count=0
        def failing(path,data):
            nonlocal count
            if Path(path).name=='delinks.txt' and Path(path).is_relative_to(self.root):
                count+=1
                if count==2:raise OSError('second module map failed')
            return original(path,data)
        with patch.object(mixed,'atomic_write',side_effect=failing):
            with self.assertRaisesRegex(OSError,'second module'):self.execute()
        self.assert_restored()

    def test_partial_publication_failure_restores_checkpoint_page_and_snapshots(self):
        class Failing(RenderedBookkeeping):
            def publish(self):
                super().publish();raise RuntimeError('publication failed after writes')
        with self.assertRaisesRegex(RuntimeError,'publication'):self.execute(Failing)
        self.assert_restored()

    def test_failed_rollback_retains_publication_ownership(self):
        self.mode='rollback-failure'
        with self.assertRaisesRegex(RuntimeError,'rollback build'):self.execute()
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_unrecognized_dirty_source_never_overwritten(self):
        self.mode='dirty';row=self.manifest['functions'][0]
        with self.assertRaisesRegex(ValueError,'Unrecognized dirty'):self.execute()
        self.assertEqual((self.root/row['source']).read_text(),'human edit during transaction')
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def interrupt(self,bookkeeping=RenderedBookkeeping):
        self.mode='gate-failure'
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute(bookkeeping)
        self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages;self.mode=None

    def test_interrupted_recovery_authenticates_all_maps_and_source_hashes(self):
        self.interrupt()
        with integration_guard(self.root,recovery=True) as transaction:
            result=mixed.run(self.args,transaction,self.gate,self.work)
        self.assertFalse(result['accepted']);self.assertTrue(result['recovered_rollback']);self.assert_restored()

    def test_corrupt_saved_or_independent_preimage_fails_before_restore(self):
        self.interrupt();folder=self.args.receipts/self.args.label
        backup=next(folder.glob('preimage-*.bin'));backup.write_bytes(b'corrupt')
        current=(self.root/delinks_path('ov000')).read_bytes()
        with integration_guard(self.root,recovery=True) as transaction:
            with self.assertRaisesRegex(ValueError,'Corrupt journal'):
                mixed.run(self.args,transaction,self.gate,self.work)
        self.assertEqual((self.root/delinks_path('ov000')).read_bytes(),current)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_wrapper_is_only_opt_in_entrypoint_and_holds_guard_before_helper(self):
        import runpy,sys
        argv=['gate','--project',str(self.root),'--worker',str(self.worker),'--manifest','manifest.json','--receipts',str(self.args.receipts),'--label',self.args.label,'--mixed-source-only']
        calls=[]
        def invoked(args,transaction):
            self.assertIsNotNone(transaction.stream)
            self.assertTrue(args.mixed_source_only)
            self.assertFalse(transaction.changed)
            calls.append(args)
        with patch.object(sys,'argv',argv),patch.object(mixed,'run',side_effect=invoked):
            runpy.run_path(str(Path(mixed.__file__).with_name('integrate_verified_subset.py')),run_name='__main__')
        self.assertEqual(len(calls),1)
        self.assertFalse((self.args.receipts/self.args.label).exists())

    def test_wrong_source_map_extent_fails_before_any_mutation(self):
        path=self.worker/delinks_path('ov000')
        path.write_text(path.read_text().replace('end:0x02150010','end:0x0215000c'))
        with self.assertRaisesRegex(ValueError,'delink extent'):self.execute()
        self.assertFalse((self.root/'build/progress/integration.lock').exists())
        self.assertFalse(self.args.receipts.exists())

    def test_independent_map_preimage_tampering_refuses_recovery(self):
        self.interrupt()
        path=self.preimages/delinks_path('ov006')
        path.write_text(path.read_text()+'\n// changed independent preimage\n')
        with integration_guard(self.root,recovery=True) as transaction:
            with self.assertRaisesRegex(ValueError,'Independent preimage differs|Changed journal postimage'):
                mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_changed_worker_source_hash_refuses_interrupted_recovery(self):
        self.interrupt()
        (self.worker/self.manifest['functions'][0]['source']).write_text('changed')
        with integration_guard(self.root,recovery=True) as transaction:
            with self.assertRaisesRegex(ValueError,'source hash'):
                mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_interruption_after_partial_publication_recovers_entire_union(self):
        class Interrupted(RenderedBookkeeping):
            def publish(self):
                super().publish();raise RuntimeError('interrupted publication')
        with patch.object(mixed,'rollback',side_effect=RuntimeError('process interrupted')):
            with self.assertRaisesRegex(RuntimeError,'process interrupted'):self.execute(Interrupted)
        self.assertTrue((self.root/'build/progress/snapshots/new.json').exists())
        self.args.restore_interrupted=True;self.args.preimage_tree=self.preimages
        with integration_guard(self.root,recovery=True) as transaction:
            mixed.run(self.args,transaction,self.gate,self.work)
        self.assert_restored()
        self.assertTrue((self.args.receipts/self.args.label/'rolled-back-receipt.json').exists())

    def test_bookkeeping_rollback_failure_retains_guard_for_authenticated_recovery(self):
        class BrokenRollback(RenderedBookkeeping):
            def publish(self):raise RuntimeError('publish')
            def rollback(self):raise RuntimeError('bookkeeping rollback')
        with self.assertRaisesRegex(RuntimeError,'bookkeeping rollback'):self.execute(BrokenRollback)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())
        self.args.recover_failed=True;self.args.preimage_tree=self.preimages
        with integration_guard(self.root,recovery=True) as transaction:
            mixed.run(self.args,transaction,self.gate,self.work)
        self.assert_restored()

    def test_small_batch_refused_before_capture_or_full_gate(self):
        d=copy.deepcopy(self.manifest);d['functions']=d['functions'][:39]
        d['source_hashes']={r['source']:d['source_hashes'][r['source']] for r in d['functions']}
        self.write(self.worker/'manifest.json',json_bytes(d))
        with self.assertRaisesRegex(ValueError,'40 to 50'):self.execute()
        self.assertFalse(self.calls)
        self.assertFalse(self.args.receipts.exists())

    def test_success_preserves_existing_map_and_owner_context_modes(self):
        expected={}
        for n in range(7):
            for filename,mode in (('delinks.txt',0o664),('symbols.txt',0o640)):
                relative=delinks_path('ov%03d'%n).with_name(filename)
                (self.root/relative).chmod(mode);expected[relative]=mode
        result=self.execute()
        for relative,mode in expected.items():
            self.assertEqual(stat.S_IMODE((self.root/relative).stat().st_mode),mode,str(relative))
        self.assertEqual(result['arm7_report_sha256_before'],mixed.recovery.digest(b'{"stable":true}'))
        self.assertEqual(result['arm7_report_sha256_after'],result['arm7_report_sha256_before'])

    def test_same_json_reformatted_arm7_report_rejected_before_publication(self):
        self.mode='arm7-format'
        with self.assertRaisesRegex(ValueError,'ARM7 report byte SHA256'):self.execute()
        self.assert_restored()

    def test_reformatted_arm7_after_rollback_keeps_publication_lock(self):
        self.mode='rollback-arm7-format'
        with self.assertRaisesRegex(ValueError,'rollback reports differ'):self.execute()
        self.assertTrue((self.root/'build/progress/integration.lock').exists())

    def test_recovery_requires_exact_arm7_bytes_after_rollback_gate(self):
        self.interrupt();self.mode='rollback-arm7-format'
        with integration_guard(self.root,recovery=True) as transaction:
            with self.assertRaisesRegex(ValueError,'rollback reports differ'):
                mixed.run(self.args,transaction,self.gate,self.work)
        self.assertTrue((self.root/'build/progress/integration.lock').exists())


if __name__=='__main__':unittest.main()
