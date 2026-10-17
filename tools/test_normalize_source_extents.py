import copy,hashlib,json,tempfile,unittest,os
from pathlib import Path
from normalize_source_extents import normalize
from normalize_source_member_aliases import elf

FIXTURE=Path(os.environ.get('DQIX_SOURCE_EXTENTS_FIXTURE_ROOT',Path(__file__).resolve().parents[1]/'build/sdk-main-20261015/main_07/build/proof-0003'))/'compiled-before-metadata.o'
SOURCE=Path(os.environ.get('DQIX_SOURCE_EXTENTS_FIXTURE_ROOT',Path(__file__).resolve().parents[1]/'build/sdk-main-20261015/main_07/build/proof-0003'))/'frozen-source.cpp'
@unittest.skipUnless(FIXTURE.is_file() and SOURCE.is_file(), "requires local compiler fixture")
class Extents(unittest.TestCase):
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
  (self.root/'source.cpp').write_bytes(SOURCE.read_bytes());(self.root/'compiler.exe').write_bytes(b'pinned test compiler')
  self.obj=self.root/'candidate.o';self.obj.write_bytes(FIXTURE.read_bytes())
  self.row=dict(source_sha256=hashlib.sha256(SOURCE.read_bytes()).hexdigest(),executable='compiler.exe',executable_sha256=hashlib.sha256(b'pinned test compiler').hexdigest(),function_extents=[dict(name='func_0200961c',compiled_size=80,size=76,aliases=[dict(name='func_02009668',offset=76,size=4,kind='unreachable_arm_return')])])
 def run_policy(self):
  (self.root/'policy.json').write_text(json.dumps(dict(sources={'source.cpp':self.row})))
  return normalize(self.obj,'source.cpp','policy.json',root=self.root)
 def test_real_compiler_metadata_partition(self):
  before=self.obj.read_bytes();receipt=self.run_policy();self.assertTrue(receipt['payloads_and_relocations_unchanged'])
  _,_,sections,_,entries,name=elf(self.obj.read_bytes());self.assertEqual(next(e[2] for e in entries if name(e)=='func_0200961c'),76)
  alias=next(e for e in entries if name(e)=='func_02009668');self.assertEqual(alias[1:3],[76,4])
  self.assertEqual(self.obj.with_suffix('.o.unnormalized').read_bytes(),before)
 def test_source_hash(self):
  (self.root/'source.cpp').write_text('changed')
  with self.assertRaisesRegex(ValueError,'Source hash'):self.run_policy()
 def test_compiler_hash(self):
  (self.root/'compiler.exe').write_text('changed')
  with self.assertRaisesRegex(ValueError,'Compiler hash'):self.run_policy()
 def test_extent(self):
  self.row['function_extents'][0]['compiled_size']=76
  with self.assertRaisesRegex(ValueError,'compiled extent'):self.run_policy()
 def test_gap(self):
  self.row['function_extents'][0]['aliases'][0]['offset']=72
  with self.assertRaisesRegex(ValueError,'noncontiguous'):self.run_policy()
 def test_not_return(self):
  data=bytearray(self.obj.read_bytes());_,_,sections,_,entries,name=elf(data);fn=next(e for e in entries if name(e)=='func_0200961c');data[sections[fn[5]][4]+76]^=1;self.obj.write_bytes(data)
  with self.assertRaisesRegex(ValueError,'not ARM bx lr'):self.run_policy()
 def test_partition(self):
  self.row['function_extents'][0]['aliases']=[]
  with self.assertRaisesRegex(ValueError,'partition'):self.run_policy()
if __name__=='__main__':unittest.main()
