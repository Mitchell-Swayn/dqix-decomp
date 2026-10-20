"""Recovery bookkeeping/freshness tests; Docker validation is mocked here."""
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from integration_lock import integration_guard
from integration_recovery import recover,verify_rollback_state


class RecoveryTests(unittest.TestCase):
    def setUp(self):
        temporary=tempfile.TemporaryDirectory();self.addCleanup(temporary.cleanup)
        self.main=Path(temporary.name)/'main';self.worker=Path(temporary.name)/'worker'
        self.receipts=self.main/'build/run';self.label='rejected';self.folder=self.receipts/self.label
        self.folder.mkdir(parents=True);self.worker.mkdir()
        self.map=self.main/'config/usa/arm9/delinks.txt';self.map.parent.mkdir(parents=True);self.map.write_text('accepted map')
        (self.folder/'config_usa_arm9_delinks.txt.before').write_bytes(self.map.read_bytes())
        manifest={'module':'main','functions':[{'name':'New','source':'src/New.cpp'}]}
        (self.folder/'manifest.json').write_text(json.dumps(manifest))
        self.before={'matched_functions':1,'matched_code':'4'};arm7={'source_functions':1}
        for name,document in [('build_usa_report.json.before',{'measures':self.before}),('build_usa_arm7_report.json.before',arm7)]:
            (self.folder/name).write_text(json.dumps(document))
        report=self.main/'build/usa/report.json';report.parent.mkdir();report.write_text(json.dumps({'measures':self.before}))
        report=self.main/'build/usa/arm7/report.json';report.parent.mkdir();report.write_text(json.dumps(arm7))
        self.page=self.main/'build/progress/index.html';self.page.parent.mkdir();self.page.write_bytes(b'accepted page')
        (self.receipts/'checkpoint.json').write_bytes(b'accepted checkpoint')
        workflow=self.main/'build/workflow'/self.label;workflow.mkdir(parents=True)
        (workflow/'start.json').write_text(json.dumps({'snapshot':{'arm9':self.before,'rom_sha1':'c7c3014c237900c8281289b8bc76a781969b6278'}}))

    def test_unpublished_preimage_recovery_keeps_accepted_page_and_earns_no_credit(self):
        with integration_guard(self.main) as transaction:
            transaction.begin_changes()
            def validator(*args,**kwargs):
                self.assertTrue(transaction.publication.exists())
                self.assertEqual(self.page.read_bytes(),b'accepted page')
            with patch('integration_recovery.subprocess.run',side_effect=validator):
                recover(self.main,self.worker,self.receipts,self.label,'main',transaction)
            self.assertFalse(transaction.changed)
        record=json.loads((self.folder/'failure.json').read_text())
        self.assertFalse(record['accepted']);self.assertEqual(record['before'],record['after'])
        self.assertFalse((self.main/'build/workflow'/self.label/'start.json').exists())
        self.assertEqual(self.page.read_bytes(),b'accepted page')

    def test_wrong_preimage_and_partial_publication_are_not_recovered(self):
        self.map.write_text('tampered')
        with self.assertRaisesRegex(ValueError,'preimage'):
            verify_rollback_state(self.main,self.worker,self.folder,'main')
        self.map.write_text('accepted map');(self.folder/'publication').mkdir()
        with self.assertRaisesRegex(ValueError,'Publication'):
            verify_rollback_state(self.main,self.worker,self.folder,'main')


class InterruptedRestoreTests(unittest.TestCase):
    def setUp(self):
        RecoveryTests.setUp(self)
        import hashlib
        from integrate_batch import parse_delinks
        self.preimages=self.main.parent/'preimages'
        relative=Path('config/usa/arm9/delinks.txt')
        header='    .text start:0x02000000 end:0x02000010 kind:code align:4\n    .rodata start:0x02000010 end:0x02000014 kind:data align:4\n'
        (self.preimages/relative).parent.mkdir(parents=True)
        (self.preimages/relative).write_text(header)
        (self.folder/'config_usa_arm9_delinks.txt.before').write_text(header)
        (self.worker/relative).parent.mkdir(parents=True)
        (self.worker/relative).write_text(header+'\nsrc/New.cpp:\n    complete\n    .text start:0x02000000 end:0x02000004\n')
        baseline=parse_delinks(header);staged=parse_delinks((self.worker/relative).read_text())
        baseline.blocks['src/New.cpp']=staged.blocks['src/New.cpp']
        self.map.write_text(baseline.header+'\n\n'+'\n\n'.join(baseline.blocks.values())+'\n')
        self.source=self.main/'src/New.cpp';self.source.parent.mkdir();self.source.write_text('extern "C" int New(){return 1;}\n')
        (self.worker/'src').mkdir();(self.worker/'src/New.cpp').write_bytes(self.source.read_bytes())
        manifest={'module':'main','functions':[{'name':'New','source':'src/New.cpp','address':'0x02000000','size':4}],
                  'source_hashes':{'src/New.cpp':hashlib.sha256(self.source.read_bytes()).hexdigest()}}
        (self.folder/'manifest.json').write_text(json.dumps(manifest))

    def test_interrupted_restore_validates_rollback_without_credit(self):
        from integration_recovery import restore_interrupted
        with integration_guard(self.main) as transaction:
            transaction.begin_changes()
            def validator(*args,**kwargs):
                self.assertFalse(self.source.exists())
                self.assertEqual(self.map.read_bytes(),(self.preimages/'config/usa/arm9/delinks.txt').read_bytes())
                self.assertTrue(transaction.publication.exists())
            with patch('integration_recovery.subprocess.run',side_effect=validator):
                restore_interrupted(self.main,self.worker,self.receipts,self.label,'main',self.preimages,transaction)
            self.assertFalse(transaction.changed)
        self.assertEqual(self.page.read_bytes(),b'accepted page')
        self.assertFalse(json.loads((self.folder/'failure.json').read_text())['accepted'])
        self.assertTrue((self.folder/'recovered-rollback.json').exists())

    def test_interrupted_after_hash_mismatch_cannot_mutate_any_path(self):
        from integration_recovery import restore_interrupted
        self.source.write_text('concurrent user change')
        original_map=self.map.read_bytes()
        with integration_guard(self.main) as transaction:
            transaction.begin_changes()
            with self.assertRaisesRegex(ValueError,'source after hash mismatch'):
                restore_interrupted(self.main,self.worker,self.receipts,self.label,'main',self.preimages,transaction)
            self.assertEqual(self.source.read_text(),'concurrent user change')
            self.assertEqual(self.map.read_bytes(),original_map)
            transaction.release_publication()

    def test_interrupted_preimage_mismatch_cannot_delete_candidate(self):
        from integration_recovery import restore_interrupted
        (self.preimages/'config/usa/arm9/delinks.txt').write_text('wrong preimage')
        with integration_guard(self.main) as transaction:
            transaction.begin_changes()
            with self.assertRaisesRegex(ValueError,'preimage hash mismatch'):
                restore_interrupted(self.main,self.worker,self.receipts,self.label,'main',self.preimages,transaction)
            self.assertTrue(self.source.exists())
            transaction.release_publication()


if __name__=='__main__':unittest.main()
