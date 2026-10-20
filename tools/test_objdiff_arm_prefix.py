"""Real ELF parser regressions; run with the locally built pinned objdiff binary."""
import json
import os
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest


def elf_fixture(path, mappings):
    # Actual immutable fixture bytes: 8 bytes OBJECT data, then ARM bx lr.
    text=bytes.fromhex('efbeadde785634121eff2fe1')
    names=bytearray(b'\0')
    def name(value):
        offset=len(names);names.extend(value.encode()+b'\0');return offset
    symbols=[bytes(16)]
    for address,mode in mappings:
        symbols.append(struct.pack('<IIIBBH',name('$'+mode),address,0,0,0,1))
    local_count=len(symbols)
    symbols += [struct.pack('<IIIBBH',name('BuildInfo'),0,8,0x11,0,1),
                struct.pack('<IIIBBH',name('main'),8,4,0x12,0,1)]
    shnames=b'\0.text\0.symtab\0.strtab\0.shstrtab\0'
    payload=bytearray(bytes(52));sections=[(0,0,0,0,0,0,0,0,0,0)]
    for shname,kind,flags,data,link,info,align,entry in [
        (1,1,6,text,0,0,4,0),
        (7,2,0,b''.join(symbols),3,local_count,4,16),
        (15,3,0,bytes(names),0,0,1,0),
        (23,3,0,shnames,0,0,1,0)]:
        payload.extend(bytes((-len(payload))%align));offset=len(payload);payload.extend(data)
        sections.append((shname,kind,flags,0,offset,len(data),link,info,align,entry))
    payload.extend(bytes((-len(payload))%4));shoff=len(payload)
    for section in sections:payload.extend(struct.pack('<10I',*section))
    header=struct.pack('<16sHHIIIIIHHHHHH',b'\x7fELF\x01\x01\x01'+bytes(9),1,40,1,0,0,shoff,0x05000000,52,0,0,40,5,4)
    payload[:52]=header;path.write_bytes(payload)
    return text


@unittest.skipUnless(os.environ.get('OBJDIFF_PREFIX_TEST_BINARY'), 'locally built pinned objdiff required')
class ArmPrefixParser(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)
        self.binary=Path(os.environ['OBJDIFF_PREFIX_TEST_BINARY']).resolve()

    def diff(self, path, label):
        output=self.root/(label+'.json')
        result=subprocess.run([str(self.binary),'diff','-1',str(path),'-o',str(output),'--format','json'],capture_output=True,text=True)
        self.assertEqual(result.returncode,0,result.stderr)
        return json.loads(output.read_text())

    def report(self, path, label):
        (self.root/'objdiff.json').write_text(json.dumps({'units':[{'name':'fixture','target_path':str(path)}]}))
        output=self.root/(label+'-report.json')
        result=subprocess.run([str(self.binary),'-C',str(self.root),'report','generate','-o',str(output)],capture_output=True,text=True)
        self.assertEqual(result.returncode,0,result.stderr)
        return json.loads(output.read_text())

    def test_leading_object_matches_explicit_data_map_without_changing_bytes_or_measures(self):
        prefix=self.root/'prefix.o';explicit=self.root/'explicit.o'
        self.assertEqual(elf_fixture(prefix,[(8,'a')]),elf_fixture(explicit,[(0,'d'),(8,'a')]))
        original=prefix.read_bytes()
        self.assertEqual(self.diff(prefix,'prefix'),self.diff(explicit,'explicit'))
        self.assertEqual(self.report(prefix,'prefix'),self.report(explicit,'explicit'))
        self.assertEqual(prefix.read_bytes(),original)
        unit=self.report(prefix,'identities')['units'][0]
        self.assertEqual([(f['name'],int(f['size'])) for f in unit['functions']],[('BuildInfo',8),('main',4)])
        self.assertEqual(int(unit['measures']['total_code']),12)
        self.assertEqual(unit['measures']['total_functions'],2)

    def test_mapping_at_zero_and_empty_maps_are_retained(self):
        zero=self.root/'zero.o';empty=self.root/'empty.o'
        elf_fixture(zero,[(0,'a')]);elf_fixture(empty,[])
        self.assertEqual(self.diff(zero,'zero'),self.diff(empty,'empty'))
        self.assertEqual(self.report(zero,'zero'),self.report(empty,'empty'))


if __name__=='__main__':unittest.main()
