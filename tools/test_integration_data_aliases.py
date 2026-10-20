import copy
import json
from pathlib import Path
import struct
import tempfile
import unittest
from integration_data_aliases import (capture_data_aliases, install_data_aliases,
    verify_data_aliases, restore_data_aliases, selected_aliases,
    verify_deferred_objects, audit_linked_aliases, digest)


def object_file(path, aliases=False, extra=False, wrong_alias_size=False):
    names = bytearray(b'\0')
    entries = [bytes(16)]
    labels = [('arena',0,32)]
    if aliases:
        labels += [('label1',4,9 if wrong_alias_size else 8),('label2',12,20)]
    for name, offset, size in labels:
        position = len(names); names.extend(name.encode()+b'\0')
        entries.append(struct.pack('<IIIBBH',position,offset,size,17,0,4))
    section_names = b'\0.shstrtab\0.strtab\0.symtab\0.bss\0.data\0'
    sections = [(0,0,0,0,b'',0,0,0,0),
                (1,3,0,0,section_names,0,0,1,0),
                (11,3,0,0,bytes(names),0,0,1,0),
                (19,2,0,0,b''.join(entries),2,1,4,16),
                (27,8,3,0,b'',0,0,1 if aliases else 32,0)]
    if extra: sections.append((32,1,3,0,bytes(4),0,0,4,0))
    blob=bytearray(52); headers=[]
    for name,kind,flags,address,data,link,info,align,stride in sections:
        blob.extend(bytes((-len(blob))%max(1,align)))
        offset=len(blob)
        if kind!=8:blob.extend(data)
        headers.append((name,kind,flags,address,offset,32 if kind==8 else len(data),link,info,align,stride))
    blob.extend(bytes((-len(blob))%4));table_offset=len(blob)
    for header in headers:blob.extend(struct.pack('<10I',*header))
    ident=b'\x7fELF\x01\x01\x01'+bytes(9)
    struct.pack_into('<16sHHIIIIIHHHHHH',blob,0,ident,1,40,1,0,0,table_offset,0,52,0,0,40,len(headers),1)
    path.write_bytes(blob)


class DataAliasTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory(); self.root=Path(self.temp.name)
        self.main=self.root/'main'; self.worker=self.root/'worker'
        self.path='config/usa/arm9/overlays/ov032/linker_symbols.json'
        self.symbols='config/usa/arm9/overlays/ov032/symbols.txt'
        self.source='src/Sound/Arena.cpp'
        for root in (self.main,self.worker):
            (root/self.symbols).parent.mkdir(parents=True)
            (root/self.symbols).write_text('arena kind:bss addr:0x02000100\nlabel1 kind:bss addr:0x02000104\nlabel2 kind:bss addr:0x0200010c ambiguous\n')
        (self.worker/self.source).parent.mkdir(parents=True)
        (self.worker/self.source).write_text('extern "C" { unsigned char arena[32]; }\n')
        self.policy={name:dict(base='arena',offset=offset,object='Arena.o',section='.bss') for name,offset in [('label1','0x4'),('label2','0xc')]}
        self.manifest=dict(module='ov032',functions=[],data=[dict(name='arena',address='0x02000100',size=32,source=self.source,section='.bss')],source_hashes={self.source:digest((self.worker/self.source).read_bytes())},data_alias_dependency=dict(path=self.path,before_sha256=None,after_sha256=None,aliases=['label1','label2']))
        self.write_policy()
    def tearDown(self):self.temp.cleanup()
    def write_policy(self):
        (self.worker/self.path).write_text(json.dumps(self.policy))
        self.manifest['data_alias_dependency']['after_sha256']=digest((self.worker/self.path).read_bytes())
    def capture(self):return capture_data_aliases(self.main,self.worker,'ov032',self.manifest)
    def test_install_verify_and_restore_absent_policy(self):
        snapshot=self.capture();install_data_aliases(self.main,snapshot)
        verify_data_aliases(self.main,snapshot,dict(match=True,linked_aliases_audited=['label1','label2']))
        restore_data_aliases(self.main,snapshot);self.assertFalse((self.main/self.path).exists())
    def test_wrong_module(self):
        with self.assertRaises(ValueError):capture_data_aliases(self.main,self.worker,'ov031',self.manifest)
    def test_wrong_base(self):
        self.policy['label1']['base']='other';self.write_policy()
        with self.assertRaises(ValueError):self.capture()
    def test_wrong_offset(self):
        self.policy['label1']['offset']='0x5';self.write_policy()
        with self.assertRaises(ValueError):self.capture()
    def test_wrong_name(self):
        self.policy['invented']=self.policy.pop('label1');self.manifest['data_alias_dependency']['aliases'][0]='invented';self.write_policy()
        with self.assertRaises(ValueError):self.capture()
    def test_wrong_source_object(self):
        self.policy['label1']['object']='Other.o';self.write_policy()
        with self.assertRaises(ValueError):self.capture()
    def test_policy_hash_stale(self):
        self.manifest['data_alias_dependency']['after_sha256']='0'*64
        with self.assertRaises(ValueError):self.capture()
    def test_before_hash_stale(self):
        self.manifest['data_alias_dependency']['before_sha256']='0'*64
        with self.assertRaises(ValueError):self.capture()
    def test_owner_hash_stale(self):
        (self.worker/self.source).write_text('unsigned char arena[16];')
        with self.assertRaises(ValueError):self.capture()
    def test_existing_entry_altered(self):
        before=json.dumps({'existing':'0x10'}).encode();(self.main/self.path).write_bytes(before)
        self.manifest['data_alias_dependency']['before_sha256']=digest(before)
        self.policy['existing']='0x11';self.write_policy()
        with self.assertRaises(ValueError):self.capture()
    def test_existing_entry_preserved(self):
        before=json.dumps({'existing':'0x10'}).encode();(self.main/self.path).write_bytes(before)
        self.manifest['data_alias_dependency']['before_sha256']=digest(before)
        self.policy['existing']='0x10';self.write_policy();snapshot=self.capture()
        install_data_aliases(self.main,snapshot);restore_data_aliases(self.main,snapshot)
        self.assertEqual((self.main/self.path).read_bytes(),before)
    def test_undeclared_added_entry(self):
        self.policy['extra']='0x10';self.write_policy()
        with self.assertRaises(ValueError):self.capture()
    def test_original_alias_omitted(self):
        self.manifest['data_alias_dependency']['aliases'].pop()
        with self.assertRaises(ValueError):self.capture()
    def test_original_symbol_address_changed(self):
        (self.main/self.symbols).write_text((self.main/self.symbols).read_text().replace('02000104','02000105'))
        with self.assertRaises(ValueError):self.capture()
    def test_missing_deferred_alias_audit(self):
        snapshot=self.capture();install_data_aliases(self.main,snapshot)
        with self.assertRaises(ValueError):verify_data_aliases(self.main,snapshot,dict(match=True))
        with self.assertRaises(ValueError):verify_data_aliases(self.main,snapshot,dict(match=True,linked_aliases_audited=['label1']))
    def test_concurrent_policy_change(self):
        snapshot=self.capture();(self.main/self.path).write_text('{}')
        with self.assertRaises(ValueError):install_data_aliases(self.main,snapshot)
    def profile_fixture(self, stale=False):
        before=json.dumps({'existing':'0x10'}).encode()
        (self.main/self.path).write_bytes(before)
        self.manifest['data_alias_dependency']['before_sha256']=digest(before)
        self.policy['existing']='0x10';self.write_policy()
        old_pin='0'*64 if stale else digest(before)
        profiles={'schema_version':1,'retained':{'value':17},'sources':{
            'sdk_a.cpp':{'source_sha256':'a'*64,'flags':['-O2'],'absolute_linker_symbols':{'policy':self.path,'policy_sha256':old_pin,'symbols':['existing']}},
            'sdk_b.cpp':{'source_sha256':'b'*64,'flags':['-O3'],'absolute_linker_symbols':{'policy':self.path,'policy_sha256':old_pin,'symbols':['existing']}},
            'unrelated.cpp':{'absolute_linker_symbols':{'policy':'config/usa/arm9/other.json','policy_sha256':'c'*64,'symbols':['other']}}}}
        self.profile_path=self.main/'config/usa/compiler_profiles.json'
        self.profile_path.write_text(json.dumps(profiles,indent=2)+'\n')
        return profiles
    def test_absolute_profile_pins_derived_only_and_rollback(self):
        original=self.profile_fixture();original_bytes=self.profile_path.read_bytes();snapshot=self.capture()
        expected=copy.deepcopy(original)
        for name in ['sdk_a.cpp','sdk_b.cpp']:
            expected['sources'][name]['absolute_linker_symbols']['policy_sha256']=self.manifest['data_alias_dependency']['after_sha256']
        self.assertEqual(json.loads(snapshot['profiles']['after']),expected)
        self.assertEqual(snapshot['profiles']['sources'],['sdk_a.cpp','sdk_b.cpp'])
        install_data_aliases(self.main,snapshot)
        verify_data_aliases(self.main,snapshot,dict(match=True,linked_aliases_audited=['label1','label2']))
        restore_data_aliases(self.main,snapshot)
        self.assertEqual(self.profile_path.read_bytes(),original_bytes)
    def test_mismatched_absolute_profile_policy_pin_rejected(self):
        self.profile_fixture(stale=True)
        with self.assertRaises(ValueError):self.capture()
    def test_worker_profile_edits_not_imported(self):
        original=self.profile_fixture()
        wp=self.worker/'config/usa/compiler_profiles.json';wp.write_text('{"sources":{"malicious.cpp":{"flags":["-O0"]}}}')
        snapshot=self.capture()
        self.assertEqual(set(json.loads(snapshot['profiles']['after'])['sources']),set(original['sources']))
    def test_profile_changed_before_install_rejects_without_policy_write(self):
        self.profile_fixture();snapshot=self.capture();before=(self.main/self.path).read_bytes()
        self.profile_path.write_text('{"sources":{}}')
        with self.assertRaises(ValueError):install_data_aliases(self.main,snapshot)
        self.assertEqual((self.main/self.path).read_bytes(),before)
    def test_profile_changed_after_install_rejected(self):
        self.profile_fixture();snapshot=self.capture();install_data_aliases(self.main,snapshot)
        self.profile_path.write_text('{"sources":{}}')
        with self.assertRaises(ValueError):verify_data_aliases(self.main,snapshot)
    def test_invalid_profile_schema_rejected(self):
        self.profile_fixture();self.profile_path.write_text('{"sources":[]}')
        with self.assertRaises(ValueError):self.capture()
    def test_unrelated_profile_policy_not_rewritten(self):
        self.profile_fixture();profiles=json.loads(self.profile_path.read_text())
        profiles['sources']={k:v for k,v in profiles['sources'].items() if k=='unrelated.cpp'}
        self.profile_path.write_text(json.dumps(profiles))
        self.assertIsNone(self.capture()['profiles'])
    def objects(self,extra=False,wrong=False):
        left=self.root/'target.o';right=self.root/'candidate.o'
        object_file(left,True,wrong_alias_size=wrong);object_file(right,extra=extra)
        return left,right,selected_aliases(self.worker,'ov032',self.manifest)
    def test_deferred_objects_exact_nobits_without_mutation(self):
        left,right,aliases=self.objects();before=[p.read_bytes() for p in (left,right)]
        self.assertEqual(verify_deferred_objects(left,right,aliases),['label1','label2'])
        self.assertEqual([p.read_bytes() for p in (left,right)],before)
    def test_extra_allocated_data_rejected(self):
        left,right,aliases=self.objects(extra=True)
        with self.assertRaises(ValueError):verify_deferred_objects(left,right,aliases)
    def test_extra_bss_storage_rejected(self):
        left,right,aliases=self.objects()
        blob=bytearray(right.read_bytes()); table=struct.unpack_from('<I',blob,32)[0]
        struct.pack_into('<I',blob,table+4*40+20,64);right.write_bytes(blob)
        with self.assertRaises(ValueError):verify_deferred_objects(left,right,aliases)
    def test_wrong_original_alias_extent_rejected(self):
        left,right,aliases=self.objects(wrong=True)
        with self.assertRaises(ValueError):verify_deferred_objects(left,right,aliases)
    def test_linked_alias_missing_wrong_address_or_extent_rejected(self):
        aliases=selected_aliases(self.worker,'ov032',self.manifest)
        linked={'symbols':{a['name']:dict(value=a['address'],size=0,type=0,binding=1,section=4) for a in aliases}}
        self.assertEqual(audit_linked_aliases(linked,aliases,4),['label1','label2'])
        for field,value in [('value',0),('size',4),('type',1),('binding',0),('section',3)]:
            changed=copy.deepcopy(linked);changed['symbols']['label1'][field]=value
            with self.assertRaises(ValueError):audit_linked_aliases(changed,aliases,4)
        del linked['symbols']['label2']
        with self.assertRaises(ValueError):audit_linked_aliases(linked,aliases,4)

if __name__=='__main__':unittest.main()
