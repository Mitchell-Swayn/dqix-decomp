"""Driver transaction tests with a deliberately mocked compiler/ROM validator.
These tests prove ledger ownership/rollback behavior, not source acceptance.
"""
import contextlib
import io
import json
from pathlib import Path
import runpy
import sys
import tempfile
import unittest
from unittest.mock import patch

from integration_bookkeeping import atomic_write


class DriverTests(unittest.TestCase):
    def run_case(self, publication_failure=False):
        with tempfile.TemporaryDirectory() as temporary:
            root=Path(temporary)/'main';worker=Path(temporary)/'worker';label='candidate'
            receipts=root/'build/run';folder=receipts/label
            source='src/Review/New.cpp';delinks=Path('config/usa/arm9/delinks.txt')
            header='    .text start:0x02000000 end:0x02000100 kind:code align:4\n'
            before={'total_functions':10,'total_code':'40','total_data':'16',
                    'matched_functions':1,'matched_code':'4','matched_data':'0'}
            after={**before,'matched_functions':2,'matched_code':'8'}
            for base in (root,worker):(base/delinks).parent.mkdir(parents=True)
            (root/delinks).write_text(header)
            (worker/delinks).write_text(header+'\n'+source+':\n    complete\n    .text start:0x02000010 end:0x02000014\n')
            (worker/source).parent.mkdir(parents=True);(worker/source).write_text('void New() {}\n')
            (worker/'manifest.json').write_text(json.dumps({'functions':[{'name':'New','address':'02000010','size':4,'source':source}], 'units':['src/Review/New']}))
            report=root/'build/usa/report.json';report.parent.mkdir(parents=True);report.write_text(json.dumps({'measures':before}))
            receipts.mkdir(parents=True);checkpoint=receipts/'checkpoint.json';checkpoint.write_bytes(b'previous checkpoint')
            foreign=receipts/'support-validation';foreign.mkdir();(foreign/'receipt.json').write_text(json.dumps({'accepted':True,'match':True,'functions':99,'code_bytes':400}))
            progress=root/'build/progress';progress.mkdir(parents=True);page=progress/'index.html';page.write_bytes(b'previous page')
            history=progress/'snapshots';history.mkdir();(history/'previous.json').write_text('{}')
            workflow=root/'build/workflow'/label;commands=[]
            def command(argv,**kwargs):
                self.assertTrue((progress/'integration.lock').exists(),argv)
                commands.append(argv)
                if argv[0]=='sudo':
                    if 'rollback' in Path(kwargs['stdout'].name).name:
                        self.assertFalse((root/source).exists())
                        self.assertEqual(json.loads(report.read_text())['measures'],before)
                    else:
                        self.assertTrue((root/source).exists());report.write_text(json.dumps({'measures':after}))
                elif argv[:2]==['python3','tools/work_batch.py']:
                    workflow.mkdir(parents=True,exist_ok=True);(workflow/(argv[2]+'.json')).write_text(argv[2])
                else:raise AssertionError('Unexpected external command: '+str(argv))
            def render(root,report,arm7,output,**kwargs):
                self.assertTrue((progress/'integration.lock').exists())
                self.assertEqual(page.read_bytes(),b'previous page')
                output.write_bytes(b'prepared accepted page');(output.parent/'snapshots/new.json').write_text('{}')
            failed_once = False
            def write(path,content):
                nonlocal failed_once
                if publication_failure and not failed_once and Path(path)==checkpoint:
                    failed_once = True
                    raise OSError('Checkpoint publication failed')
                atomic_write(path,content)
            argv=['gate','--project',str(root),'--worker',str(worker),'--manifest','manifest.json',
                  '--receipts',str(receipts),'--label',label]
            script=Path(__file__).with_name('integrate_verified_subset.py')
            with patch.object(sys,'argv',argv),patch('subprocess.run',side_effect=command), \
                 patch('progress_dashboard.generate',side_effect=render), \
                 patch('integration_bookkeeping.atomic_write',side_effect=write),contextlib.redirect_stdout(io.StringIO()):
                if publication_failure:
                    with self.assertRaisesRegex(OSError,'Checkpoint publication failed'):
                        runpy.run_path(str(script),run_name='__main__')
                else:runpy.run_path(str(script),run_name='__main__')
            self.assertFalse((progress/'integration.lock').exists())
            if publication_failure:
                self.assertEqual(json.loads(report.read_text())['measures'],before)
                self.assertEqual((root/delinks).read_text(),header)
                self.assertFalse((root/source).exists())
                self.assertFalse((workflow/'start.json').exists());self.assertFalse((workflow/'finish.json').exists())
                self.assertEqual(checkpoint.read_bytes(),b'previous checkpoint');self.assertEqual(page.read_bytes(),b'previous page')
                self.assertEqual([p.name for p in history.glob('*.json')],['previous.json'])
                self.assertFalse((folder/'receipt.json').exists());self.assertTrue((folder/'rolled-back-receipt.json').exists())
                self.assertFalse(json.loads((folder/'failure.json').read_text())['accepted'])
                self.assertEqual(sum(command[0]=='sudo' for command in commands),2)
            else:
                record=json.loads((folder/'receipt.json').read_text());self.assertTrue(record['accepted'])
                ledger=json.loads(checkpoint.read_text());self.assertEqual(ledger['accepted_batches'],[label])
                self.assertEqual((ledger['new_functions'],ledger['new_code_bytes']), (1,4))
                self.assertEqual(page.read_bytes(),b'prepared accepted page')
                self.assertEqual(sum(command[0]=='sudo' for command in commands),1)

    def test_foreign_support_receipt_does_not_break_valid_publication(self):
        self.run_case()

    def test_late_checkpoint_failure_rolls_back_source_and_all_bookkeeping(self):
        self.run_case(publication_failure=True)


if __name__ == '__main__':unittest.main()
