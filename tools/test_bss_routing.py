import unittest
import tempfile
from pathlib import Path
from arm9_module import split_data,verify_measures
from integration_bookkeeping import checkpoint,integration_record

class BssRoutingTests(unittest.TestCase):
 def test_mixed_route_preserves_coverage(self):
  rows=[dict(section='.data',size=4),dict(section='.bss',size=32)]
  initialized,bss=split_data(rows,'main')
  self.assertEqual((sum(r['size'] for r in initialized),sum(r['size'] for r in bss)),(4,32))
  before=dict(total_code=1,total_data=40,total_functions=1,matched_code=0,matched_data=0,matched_functions=0)
  verify_measures(before,dict(before,matched_data=36),[],rows)
 def test_invalid_sections_rejected(self):
  for section,module in [('.text','main'),(None,'main')]:
   with self.assertRaises(ValueError):split_data([dict(section=section,size=4)],module)
  self.assertEqual(len(split_data([dict(section='.bss',size=4)],'ov034')[1]),1)
 def test_autoload_bss_routing(self):
  for module in ['itcm','dtcm']:
   self.assertEqual(len(split_data([dict(section='.bss',size=4)],module)[1]),1)
 def test_autoload_original_bounds(self):
  from audit_bss_layout import original_bounds
  with tempfile.TemporaryDirectory() as d:
   p=Path(d)/'itcm.yaml';p.write_text('base_address: 1000\ncode_size: 96\nbss_size: 32\n')
   self.assertEqual(original_bounds(p,'itcm'),dict(base_address=1000,bss_start=1096,bss_end=1128))
   p.write_text('base_address: 1000\ncode_size: 96\nbss_size: 0\n')
   with self.assertRaises(ValueError):original_bounds(p,'itcm')
 def test_checkpoint_keeps_bss_separate(self):
  with tempfile.TemporaryDirectory() as directory:
   record=dict(accepted=True,functions=0,code_bytes=0,data_bytes=4,bss_bytes=32,elapsed_seconds=1,before={},after={},validation_seconds=1,role='worker')
   result=checkpoint(Path(directory),'batch',record,{},'now')
   self.assertEqual((result['new_data_bytes'],result['new_bss_bytes']),(4,32))
   with self.assertRaises(ValueError):integration_record(dict(record,bss_bytes=-1))
