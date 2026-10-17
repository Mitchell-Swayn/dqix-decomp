import pathlib,tempfile,unittest
from integration_symbols import capture_symbols,install_symbols,verify_symbols,restore_symbols
class Symbols(unittest.TestCase):
 def setUp(self):
  self.t=tempfile.TemporaryDirectory();self.main=pathlib.Path(self.t.name)/'main';self.worker=pathlib.Path(self.t.name)/'worker';self.rel=pathlib.Path('config/usa/arm9/overlays/ov007/symbols.txt')
  for root in [self.main,self.worker]:(root/self.rel).parent.mkdir(parents=True);(root/self.rel).write_text('old kind:data(word) addr:0x021842a8\n')
  self.line='ctor_end kind:data(word) addr:0x021842a0';(self.worker/self.rel).write_text((self.worker/self.rel).read_text()+self.line+'\n');self.m={'data':[{'name':'ctor_end','address':'021842a0'}],'symbol_additions':[{'path':self.rel.as_posix(),'line':self.line}]}
 def tearDown(self):self.t.cleanup()
 def test_transaction_preserves_and_restores_map(self):
  before=(self.main/self.rel).read_bytes();s=capture_symbols(self.main,self.worker,'ov007',self.m);install_symbols(self.main,s);verify_symbols(self.main,s);self.assertIn(self.line,(self.main/self.rel).read_text());restore_symbols(self.main,s);self.assertEqual((self.main/self.rel).read_bytes(),before)
 def test_reject_address(self):
  self.m['data'][0]['address']='021842a4'
  with self.assertRaises(ValueError):capture_symbols(self.main,self.worker,'ov007',self.m)
 def test_reject_unselected(self):
  self.m['data']=[]
  with self.assertRaises(ValueError):capture_symbols(self.main,self.worker,'ov007',self.m)
 def test_reject_other_module(self):
  with self.assertRaises(ValueError):capture_symbols(self.main,self.worker,'ov018',self.m)
 def test_reject_existing(self):
  (self.main/self.rel).write_text(self.line+'\n')
  with self.assertRaises(ValueError):capture_symbols(self.main,self.worker,'ov007',self.m)
 def test_reject_concurrent_change(self):
  s=capture_symbols(self.main,self.worker,'ov007',self.m);(self.main/self.rel).write_text('changed\n')
  with self.assertRaises(ValueError):install_symbols(self.main,s)
if __name__=='__main__':unittest.main()
