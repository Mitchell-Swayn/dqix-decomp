import copy
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from integration_bookkeeping import Bookkeeping, SCHEMA, accepted_receipts, atomic_write, checkpoint, integration_record
from integration_lock import integration_guard


def receipt(functions=1, code=16, data=0, marked=False):
    document = {'accepted': True, 'functions': functions, 'code_bytes': code, 'data_bytes': data,
                'before': {'matched_functions': 1}, 'after': {'matched_functions': 1+functions},
                'validation_seconds': 1.0, 'role': 'worker'}
    if marked:document.update(receipt_schema=SCHEMA, processor='ARM9')
    return document


class BookkeepingTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name);self.receipts = self.root/'build/run'
        self.receipts.mkdir(parents=True)
        self.label = 'new'
        (self.receipts/self.label).mkdir()

    def write_receipt(self, label, document, failure=False, rolled_back=False):
        directory = self.receipts/label;directory.mkdir(exist_ok=True)
        (directory/'receipt.json').write_text(json.dumps(document))
        if failure:(directory/'failure.json').write_text('{}')
        if rolled_back:(directory/'rolled-back-receipt.json').write_text('{}')

    def test_foreign_validation_and_failed_folders_do_not_pollute_totals_or_labels(self):
        self.write_receipt('legacy', receipt(2,32))
        self.write_receipt('data-only', receipt(0,0,28,marked=True))
        self.write_receipt('support-validation', {'accepted':True, 'functions':7, 'code_bytes':428, 'rom_sha1':'proof'})
        self.write_receipt('foreign-schema', {**receipt(), 'receipt_schema':'support-validation-v1'})
        self.write_receipt('arm7', {**receipt(), 'processor':'ARM7'})
        self.write_receipt('failed', receipt(90,900), failure=True)
        self.write_receipt('rolled-back', receipt(80,800), rolled_back=True)
        self.write_receipt('not-accepted', {'accepted':False})
        records = accepted_receipts(self.receipts)
        self.assertEqual([label for label, _ in records], ['data-only','legacy'])
        result = checkpoint(self.receipts,'new',receipt(1,16,marked=True),{'matched_functions':4},'now')
        self.assertEqual(result['accepted_batches'], ['data-only','legacy','new'])
        self.assertEqual((result['new_functions'],result['new_code_bytes'],result['new_data_bytes']), (3,48,28))

    def test_corrupt_integration_counts_fail_closed_but_foreign_records_are_ignored(self):
        for bad in ('16', True, -1, None):
            with self.assertRaises(ValueError):integration_record({**receipt(marked=True),'code_bytes':bad})
        with self.assertRaises(ValueError):integration_record({'accepted':True,'receipt_schema':SCHEMA})
        self.assertFalse(integration_record(['not','a','receipt']))
        self.assertFalse(integration_record({'accepted':True,'match':True,'functions':7}))
        self.write_receipt('broken',receipt())
        (self.receipts/'broken/receipt.json').write_text('broken JSON')
        with self.assertRaises(json.JSONDecodeError):accepted_receipts(self.receipts)

    def test_prepare_failure_never_publishes_success(self):
        page = self.root/'build/progress/index.html';page.parent.mkdir(parents=True);page.write_bytes(b'accepted old page')
        ledger = self.receipts/'checkpoint.json';ledger.write_bytes(b'old checkpoint')
        state = Bookkeeping(self.root,self.receipts,self.label)
        def broken_render(*args):raise RuntimeError('Invalid report or renderer')
        with integration_guard(self.root) as owner:
            owner.begin_changes()
            with self.assertRaisesRegex(RuntimeError,'renderer'):
                state.prepare(receipt(marked=True),{},'now',render=broken_render)
            self.assertFalse((self.receipts/self.label/'receipt.json').exists())
            self.assertEqual(page.read_bytes(),b'accepted old page')
            self.assertEqual(ledger.read_bytes(),b'old checkpoint')
            state.rollback();owner.release_publication()

    def test_prepare_publish_and_rollback_restore_workflow_checkpoint_page_history(self):
        progress = self.root/'build/progress';history=progress/'snapshots';history.mkdir(parents=True)
        old = history/'old.json';old.write_text('{}');old_time=old.stat().st_mtime_ns
        page=progress/'index.html';page.write_bytes(b'old page')
        checkpoint_path=self.receipts/'checkpoint.json';checkpoint_path.write_bytes(b'old checkpoint')
        workflow=self.root/'build/workflow'/self.label;workflow.mkdir(parents=True)
        start=workflow/'start.json';start.write_bytes(b'old start')
        state=Bookkeeping(self.root,self.receipts,self.label)
        def render(root, report, arm7, output):
            self.assertTrue((progress/'integration.lock').exists())
            self.assertFalse(output.exists())
            self.assertFalse((output.parent/'snapshots/old.json').exists())
            self.assertEqual(old.read_text(), '{}')
            (output.parent/'snapshots/new.json').write_text('{}')
            output.write_bytes(b'new page')
        with integration_guard(self.root) as owner:
            owner.begin_changes()
            start.write_bytes(b'new start');(workflow/'finish.json').write_bytes(b'new finish')
            state.prepare(receipt(marked=True),{},'now',render=render)
            self.assertEqual(page.read_bytes(),b'old page')
            self.assertFalse((self.receipts/self.label/'receipt.json').exists())
            state.publish()
            self.assertTrue((progress/'integration.lock').exists())
            self.assertEqual(page.read_bytes(),b'new page')
            self.assertEqual([name for name,_ in accepted_receipts(self.receipts)],['new'])
            state.rollback()
            self.assertEqual(page.read_bytes(),b'old page')
            self.assertEqual(checkpoint_path.read_bytes(),b'old checkpoint')
            self.assertEqual(start.read_bytes(),b'old start')
            self.assertFalse((workflow/'finish.json').exists())
            self.assertEqual(list(history.glob('*.json')),[old])
            self.assertEqual(old.stat().st_mtime_ns,old_time)
            self.assertFalse((self.receipts/self.label/'receipt.json').exists())
            self.assertTrue((self.receipts/self.label/'rolled-back-receipt.json').exists())
            self.assertEqual(accepted_receipts(self.receipts),[])
            owner.release_publication()

    def test_partial_publication_failure_restores_absent_outputs_and_quarantines_receipt(self):
        state=Bookkeeping(self.root,self.receipts,self.label)
        def render(root, report, arm7, output):
            (output.parent/'snapshots/new.json').write_text('{}');output.write_bytes(b'new page')
        with integration_guard(self.root) as owner:
            owner.begin_changes()
            state.prepare(receipt(marked=True),{},'now',render=render)
            original_write=atomic_write
            def fail_checkpoint(path,content):
                if Path(path)==self.receipts/'checkpoint.json':raise OSError('Disk failure')
                original_write(path,content)
            with patch('integration_bookkeeping.atomic_write',side_effect=fail_checkpoint):
                with self.assertRaisesRegex(OSError,'Disk failure'):state.publish()
            state.rollback()
            self.assertFalse((self.root/'build/progress/index.html').exists())
            self.assertFalse((self.root/'build/progress/snapshots/new.json').exists())
            self.assertFalse((self.receipts/'checkpoint.json').exists())
            self.assertFalse((self.receipts/self.label/'receipt.json').exists())
            self.assertTrue((self.receipts/self.label/'rolled-back-receipt.json').exists())
            owner.release_publication()

    def test_rollback_bookkeeping_failure_retains_publication_lock(self):
        state=Bookkeeping(self.root,self.receipts,self.label)
        with self.assertRaisesRegex(OSError,'Restore failed'):
            with integration_guard(self.root) as owner:
                owner.begin_changes()
                with patch.object(state,'rollback',side_effect=OSError('Restore failed')):
                    state.rollback()
        self.assertTrue((self.root/'build/progress/integration.lock').exists())
        with self.assertRaisesRegex(RuntimeError,'unfinished'):
            with integration_guard(self.root):pass

    def test_archive_is_not_read_copied_or_rewritten(self):
        history=self.root/'build/progress/snapshots';history.mkdir(parents=True)
        old=history/'old.json';old.write_bytes(b'old immutable snapshot')
        before=old.stat()
        read=Path.read_bytes
        def guarded(path):
            if path==old:raise AssertionError('Historical snapshot read')
            return read(path)
        def render(root,report,arm7,output):
            self.assertEqual(list((output.parent/'snapshots').iterdir()),[])
            output.write_bytes(b'new page')
        with patch.object(Path,'read_bytes',guarded):
            state=Bookkeeping(self.root,self.receipts,self.label)
            state.prepare(receipt(marked=True),{},'now',render=render)
            state.publish();state.rollback()
        self.assertEqual(old.read_bytes(),b'old immutable snapshot')
        self.assertEqual(old.stat().st_mtime_ns,before.st_mtime_ns)
        self.assertEqual(old.stat().st_ino,before.st_ino)

    def test_existing_snapshot_collision_is_rejected_without_overwrite(self):
        history=self.root/'build/progress/snapshots';history.mkdir(parents=True)
        old=history/'old.json';old.write_bytes(b'old snapshot')
        state=Bookkeeping(self.root,self.receipts,self.label)
        def render(root,report,arm7,output):
            (output.parent/'snapshots/old.json').write_bytes(b'bad replacement')
            output.write_bytes(b'new page')
        state.prepare(receipt(marked=True),{},'now',render=render)
        with self.assertRaisesRegex(ValueError,'archived snapshot'):state.publish()
        state.rollback()
        self.assertEqual(old.read_bytes(),b'old snapshot')


if __name__ == '__main__':unittest.main()
