import json,unittest,copy,os,tempfile,shutil
from pathlib import Path
from runtime_code_retention import retained_symbols
B=Path(os.environ.get('DQIX_CODE_RETENTION_FIXTURE_ROOT',Path(__file__).resolve().parents[1]/'build/sdk-main-20261015/fog/build/fallback-code-retention'));ROW=json.loads((B/'cpuset-row.json').read_text()) if (B/'cpuset-row.json').exists() else None;ROOT=B.parents[4];SOURCE=B.parent/'sdk-assembly-stage02-aligned'
@unittest.skipUnless(ROW is not None,'requires local original-byte/source fixture')
class Retention(unittest.TestCase):
 def setUp(self):self.row=copy.deepcopy(ROW)
 def check(self):return retained_symbols(ROOT,self.row,source_root=SOURCE)
 def test_actual_bios_section(self):self.assertEqual(self.check(),['Mod'])
 def test_configure_before_original_extraction(self):
  with tempfile.TemporaryDirectory() as folder:
   root=Path(folder);(root/'config/usa/arm9').mkdir(parents=True)
   shutil.copy2(ROOT/'config/usa/arm9/symbols.txt',root/'config/usa/arm9/symbols.txt')
   self.assertEqual(retained_symbols(root,self.row,source_root=SOURCE,verify_original=False),['Mod'])
   with self.assertRaises(FileNotFoundError):retained_symbols(root,self.row,source_root=SOURCE)
 def test_configure_still_rejects_changed_source(self):
  self.row['source_sha256']='0'*64
  with self.assertRaisesRegex(ValueError,'source hash'):retained_symbols(ROOT,self.row,source_root=SOURCE,verify_original=False)
 def test_no_retention_no_roots(self):self.assertEqual(retained_symbols(ROOT,{}),[])
 def test_source_pin(self):
  self.row['source_sha256']='0'*64
  with self.assertRaisesRegex(ValueError,'source hash'):self.check()
 def test_range_pin(self):
  self.row['retained_fallback_code']['original_sha256']='0'*64
  with self.assertRaisesRegex(ValueError,'range hash'):self.check()
 def test_no_credit(self):
  self.row['retained_fallback_code']['c_instruction_credit']=674
  with self.assertRaisesRegex(ValueError,'Invalid code'):self.check()
 def test_complete_actual_symbols(self):
  self.row['retained_fallback_code']['symbols'].pop()
  with self.assertRaisesRegex(ValueError,'symbol set'):self.check()
 def test_actual_address(self):
  self.row['retained_fallback_code']['symbols'][0]['address']='0x02000210'
  with self.assertRaisesRegex(ValueError,'extent differs'):self.check()
 def test_actual_bytes(self):
  self.row['retained_fallback_code']['symbols'][0]['original_sha256']='0'*64
  with self.assertRaisesRegex(ValueError,'bytes differ'):self.check()
if __name__=='__main__':unittest.main()
