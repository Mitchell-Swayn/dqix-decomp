"""Regression checks for source-owned member metadata normalization."""
import copy,json,shutil,tempfile,unittest,os
from pathlib import Path
from normalize_source_member_aliases import normalize,elf

PROJECT=Path(os.environ.get('DQIX_MEMBER_ALIAS_FIXTURE_ROOT',Path(__file__).resolve().parents[1]))
SOURCE='src/System/OS_GetLowEntropyData.cpp'
POLICY='config/usa/compiler_profiles.json'

class SourceMemberAliasTest(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)
        self.document=json.loads((PROJECT/POLICY).read_text());self.profile=self.document['sources'][SOURCE]
        alias=self.profile['member_aliases'][0]
        files=[SOURCE,self.profile['executable'],alias['owner_source'],alias['layout_header'],alias['owner_object'],alias['layout_source'],alias['layout_object']]
        for file in files:
            dest=self.root/file;dest.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(PROJECT/file,dest)
        self.obj=self.root/'candidate.o';shutil.copy2(PROJECT/'build/usa/src/System/OS_GetLowEntropyData.o.unnormalized',self.obj)
        self.original=self.obj.read_bytes();self.save_policy()
    def save_policy(self):
        dest=self.root/POLICY;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_text(json.dumps(self.document))
    def check_rejected(self):
        with self.assertRaises(ValueError): normalize(self.obj,SOURCE,POLICY,self.root)
        self.assertEqual(self.original,self.obj.read_bytes())
    def test_preserves_all_payloads_and_resolved_address(self):
        receipt=normalize(self.obj,SOURCE,POLICY,self.root)
        self.assertTrue(receipt['payloads_unchanged']);self.assertEqual(len(receipt['changes']),1)
        change=receipt['changes'][0];self.assertEqual(change['old_addend'],0);self.assertEqual(change['new_addend'],8)
        self.assertEqual(change['resolved_before'],'0x2111640');self.assertEqual(change['resolved_before'],change['resolved_after'])
        _,_,_,_,entries,name=elf(self.obj.read_bytes())
        self.assertIn('data_02111638',[name(e) for e in entries]);self.assertNotIn('data_02111640',[name(e) for e in entries])
    def test_owner_source_drift_rejected_before_mutation(self):
        alias=self.profile['member_aliases'][0];(self.root/alias['owner_source']).write_text('wrong source')
        self.check_rejected()
    def test_out_of_owner_range_rejected_before_mutation(self):
        self.profile['member_aliases'][0]['offset']='0x10';self.save_policy();self.check_rejected()
    def test_offset_inside_owner_but_wrong_field_rejected(self):
        self.profile['member_aliases'][0]['offset']='0x0';self.save_policy();self.check_rejected()
    def test_wrong_compiler_layout_rejected(self):
        alias=self.profile['member_aliases'][0];layout=self.root/alias['layout_object'];blob=bytearray(layout.read_bytes())
        _,_,secs,_,entries,name=elf(blob);entry=next(e for e in entries if name(e)==alias['layout_symbol'])
        blob[secs[entry[5]][4]+entry[1]+4]=4;layout.write_bytes(blob);self.check_rejected()

if __name__=='__main__': unittest.main()
