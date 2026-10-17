import json,tempfile,unittest,shutil,struct,os
from pathlib import Path
from partial_link_absolute_symbols import normalize
from normalize_source_member_aliases import elf
FIXTURE=Path(os.environ.get('DQIX_ABSOLUTE_LINK_FIXTURE_ROOT',Path(__file__).resolve().parents[1]/'build/sdk-main-20261015/fog/build/absolute-link-patch/build/probe'))
@unittest.skipUnless((FIXTURE/"candidate.o.before-absolute-link").is_file(), "requires local compiler fixture")
class Absolute(unittest.TestCase):
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
  for n in ('source.cpp','compiler.exe','policy.json','linker.json'):shutil.copy2(FIXTURE/n,self.root/n)
  self.obj=self.root/'candidate.o';shutil.copy2(FIXTURE/'candidate.o.before-absolute-link',self.obj)
  self.policy=json.loads((self.root/'policy.json').read_text())
 def run_policy(self):
  (self.root/'policy.json').write_text(json.dumps(self.policy));return normalize(self.obj,'source.cpp','policy.json',root=self.root)
 def test_real_compiler_two_relocations(self):
  before=self.obj.read_bytes();r=self.run_policy();self.assertEqual(len(r['changes']),2);self.assertEqual({v['resolved'] for v in r['changes']},{0,1024})
  _,_,bs,_,_,_=elf(before);_,_,ss,_,_,_=elf(self.obj.read_bytes())
  self.assertEqual(sum(s[5] for s in bs if s[1]==4)-sum(s[5] for s in ss if s[1]==4),24)
  self.assertEqual(self.obj.with_suffix('.o.before-absolute-link').read_bytes(),before)
 def test_linker_owns_absolute_symbol_definitions(self):
  before=self.obj.read_bytes();_,_,bs,_,be,bname=elf(before);self.run_policy();_,_,ss,_,se,sname=elf(self.obj.read_bytes())
  self.assertEqual(be,se)
  for entry in se:
   if sname(entry) in ('SDK_SYS_STACKSIZE','SDK_IRQ_STACKSIZE'):self.assertEqual(entry[5],0)
 def test_source(self):
  (self.root/'source.cpp').write_text('changed')
  with self.assertRaisesRegex(ValueError,'Source hash'):self.run_policy()
 def test_compiler(self):
  (self.root/'compiler.exe').write_text('changed')
  with self.assertRaisesRegex(ValueError,'Compiler hash'):self.run_policy()
 def test_policy(self):
  (self.root/'linker.json').write_text('{}')
  with self.assertRaisesRegex(ValueError,'Linker policy hash'):self.run_policy()
 def test_non_absolute(self):
  self.policy['sources']['source.cpp']['absolute_linker_symbols']['symbols']=['data_020e9a50']
  with self.assertRaisesRegex(ValueError,'not an absolute'):self.run_policy()
 def test_not_present(self):
  self.policy['sources']['source.cpp']['absolute_linker_symbols']['symbols']=['NO_SUCH_CONSTANT']
  with self.assertRaisesRegex(ValueError,'not an absolute'):self.run_policy()
 def test_instruction_destination(self):
  data=bytearray(self.obj.read_bytes());_,_,sections,si,entries,name=elf(data)
  wanted={i for i,e in enumerate(entries) if name(e)=='SDK_SYS_STACKSIZE'}
  for sec in sections:
   if sec[1]!=4:continue
   for pos in range(sec[4],sec[4]+sec[5],12):
    if struct.unpack_from('<I',data,pos+4)[0]>>8 in wanted:struct.pack_into('<I',data,pos,0)
  self.obj.write_bytes(data)
  with self.assertRaisesRegex(ValueError,'mapped data'):self.run_policy()
if __name__=='__main__':unittest.main()
