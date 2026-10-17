import copy
import tempfile
import hashlib
import io
import struct
import tarfile
import json
from pathlib import Path
import unittest
from runtime_vendor import validate_compiler_row
from runtime_support import capture, summarize

def fixture(root):
    def write(name, data):
        p=root/name; p.parent.mkdir(parents=True,exist_ok=True)
        p.write_bytes(data); return hashlib.sha256(data).hexdigest()
    names=b'\0_test\0errno\0test.s\0'
    symbols=b'\0'*16+struct.pack('<IIIBBH',1,0,8,0x12,0,1)+struct.pack('<IIIBBH',7,0,0,0x10,0,0)+struct.pack('<IIIBBH',13,0,0,4,0,0xfff1)
    payloads=[b'',struct.pack('<II',0xe12fff1e,0),symbols,names,struct.pack('<IIi',4,(2<<8)|2,0)]
    entries=[]; content=bytearray(b'\0'*52)
    for i,body in enumerate(payloads):
        offset=len(content);content.extend(body)
        entries.append((0,[0,1,2,3,4][i],6 if i==1 else 0,0,offset,len(body),3 if i==2 else 2 if i==4 else 0,1 if i==4 else 0,4,16 if i==2 else 12 if i==4 else 0))
    shoff=len(content)
    for entry in entries:content.extend(struct.pack('<10I',*entry))
    struct.pack_into('<16sHHIIIIIHHHHHH',content,0,b'\x7fELF\x01\x01\x01'+b'\0'*9,1,40,1,0,0,shoff,0,52,0,0,40,len(entries),0)
    obj=bytes(content); head=('test.o/'.ljust(16)+'0'.ljust(12)+'0'.ljust(6)+'0'.ljust(6)+'100644'.ljust(8)+str(len(obj)).ljust(10)+'`\n').encode();archive=b'!<arch>\n'+head+obj+(b'\n' if len(obj)%2 else b'')
    tarbytes=io.BytesIO()
    with tarfile.open(fileobj=tarbytes,mode='w:xz') as tar:
        entry=tarfile.TarInfo('package/sdk/test/lib.a');entry.size=len(archive);tar.addfile(entry,io.BytesIO(archive))
    package_hash=write('build/vendor-proof/package.tar.xz',tarbytes.getvalue())
    source='src/RuntimeSupport/_test.cpp';source_hash=write(source,b'// Compiler runtime support: _test.\nextern "C" asm void _test() { bx lr }\n')
    write('build/vendor-proof/candidate.cpp',(root/source).read_bytes());object_hash=write('build/vendor-proof/candidate.o',obj)
    result_hash=write('build/vendor-proof/result.json',json.dumps({'status':'compared','object_match':True,'mismatches':0,'unit':source[:-4],'rom_acceptance':False,'raw_match':None}).encode())
    raw=struct.pack('<II',0xe12fff1e,0x020f0000);original=hashlib.sha256(raw).hexdigest();write('extract/usa/arm9/arm9.bin',raw)
    write('config/usa/arm9/symbols.txt',b'errno kind:data(any) addr:0x020f0000\n')
    write('config/usa/arm9/runtime_support.json',(json.dumps({'schema_version':1,'functions':[]},indent=2)+'\n').encode())
    fresh={'candidate_source':'build/vendor-proof/candidate.cpp','candidate_source_sha256':source_hash,'candidate_object':'build/vendor-proof/candidate.o','candidate_object_sha256':object_hash,'result':'build/vendor-proof/result.json','result_sha256':result_hash}
    evidence={'origin':'vendor_archive','vendor_archive_match':True,'exact_resolved_match':True,'library':'test/lib.a','object':'test.o','archive_sha256':hashlib.sha256(archive).hexdigest(),'object_sha256':object_hash,'package_sha256':package_hash,'package_url':'https://example.invalid/vendor-package','authentication':{'package':'build/vendor-proof/package.tar.xz','package_sha256':package_hash,'archive_member':'package/sdk/test/lib.a'},'vendor_symbol':'_test','source_files':['test.s'],'symbols':['_test','errno'],'relocations':[[4,'errno',2]],'relocation_bindings':{'errno':{'target_symbol':'errno','address':'0x020f0000'}},'fresh_object_check':fresh}
    row={'module':'arm9/main','name':'_test','address':'0x02000000','size':8,'source':source,'source_sha256':source_hash,'classification':'runtime_assembly','evidence_class':'compiler_runtime','assembly_form':'codewarrior_inline','c_reconstruction_eligible':False,'original_sha256':original,'evidence':evidence}
    function={'name':'_test','address':'02000000','size':8,'source':source,'original_sha256':original}
    return row,function


class VendorAppendTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup)
        self.root=Path(self.temp.name);self.row,self.function=fixture(self.root)

    def validate(self):
        validate_compiler_row(self.root, self.root, self.row, self.function)

    def test_package_full_function_and_candidate(self):
        self.validate()

    def test_vendor_object_hash_tamper(self):
        self.row['evidence']['object_sha256'] = '0'*64
        with self.assertRaises(ValueError): self.validate()

    def test_relocation_owning_symbol_tamper(self):
        self.row['evidence']['relocation_bindings']['errno']['address'] = '0x020f3394'
        with self.assertRaises(ValueError): self.validate()

    def test_candidate_source_hash_tamper(self):
        self.row['evidence']['fresh_object_check']['candidate_source_sha256'] = '0'*64
        with self.assertRaises(ValueError): self.validate()

    def test_reject_community_claim(self):
        self.row['evidence']['origin'] = 'community_reconstruction'
        with self.assertRaises(ValueError): self.validate()

    def test_full_extent_required(self):
        self.row['size'] -= 4
        with self.assertRaises(ValueError): self.validate()

    def test_append_preserves_prior_and_zero_c_credit(self):
        before=(self.root/'config/usa/arm9/runtime_support.json').read_bytes()
        m={'functions':[self.function],'runtime_append':{'schema_version':1,'functions':[self.row]}}
        s=capture(self.root,self.root,m);prior=json.loads(before);after=json.loads(s['after'])
        self.assertEqual(after['functions'][:-1],prior['functions'])
        self.assertEqual({k:v for k,v in after.items() if k!='functions'},{k:v for k,v in prior.items() if k!='functions'})
        self.assertFalse(after['functions'][-1]['c_reconstruction_eligible'])
        self.assertEqual(summarize([self.row])['compiler_runtime_bytes'],8)
        self.assertEqual((self.root/'config/usa/arm9/runtime_support.json').read_bytes(),before)

if __name__=='__main__': unittest.main()
