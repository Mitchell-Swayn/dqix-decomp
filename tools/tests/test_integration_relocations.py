import copy
import hashlib
from pathlib import Path
import sys
import tempfile
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from integration_relocations import capture_relocations, install_relocations, verify_relocations, restore_relocations

class Relocations(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.main = Path(self.temp.name)/'main'
        self.worker = Path(self.temp.name)/'worker'
        self.line = 'from:0x02000004 kind:load to:0x021701db module:overlay(4)'
        self.path = 'config/usa/arm9/relocs.txt'
        original = bytes.fromhex('11223344db01170255667788')
        for root in [self.main,self.worker]:
            (root/'config/usa/arm9').mkdir(parents=True)
        (self.main/'config/usa/arm9/delinks.txt').write_text('    .text start:0x01ffffff end:0x02000000 kind:code align:4\n    .rodata start:0x02000000 end:0x0200000c kind:rodata align:4\n    .data start:0x0200000c end:0x02000010 kind:data align:4\n    .bss start:0x02000010 end:0x02000014 kind:bss align:4\n\n')
        (self.main/self.path).write_text(self.line+'\nother unchanged line\n')
        (self.worker/self.path).write_text('other unchanged line\n')
        (self.main/'extract/usa/arm9').mkdir(parents=True)
        (self.main/'extract/usa/arm9/arm9.yaml').write_text('base_address: 33554432\n')
        (self.main/'extract/usa/arm9/arm9.bin').write_bytes(original)
        (self.worker/'src').mkdir()
        (self.worker/'src/Table.cpp').write_text('const unsigned short numericTable[6] = {};\n')
        self.manifest = {'module':'main','data':[{'name':'table','address':'0x02000000','size':12,'section':'.rodata','source':'src/Table.cpp','sha256':hashlib.sha256(original).hexdigest()}], 'source_hashes':{'src/Table.cpp':hashlib.sha256((self.worker/'src/Table.cpp').read_bytes()).hexdigest()},'relocation_removals':[{'path':self.path,'line':self.line,'address':'0x02000004','original_word_hex':'021701db','reason':'Source numericTable represents adjacent unsigned halfwords.'}]}
    def capture(self):
        return capture_relocations(self.main,self.worker,'main',self.manifest)
    def test_success_and_rollback(self):
        snapshot=self.capture();before=(self.main/self.path).read_bytes()
        install_relocations(self.main,snapshot);verify_relocations(self.main,snapshot)
        self.assertEqual((self.main/self.path).read_text(),'other unchanged line\n')
        restore_relocations(self.main,snapshot);self.assertEqual((self.main/self.path).read_bytes(),before)
    def test_multiple_overlay_targets(self):
        old=self.line;self.line=old.replace('overlay(4)', 'overlays(31,32)')
        (self.main/self.path).write_text(self.line+'\nother unchanged line\n')
        self.manifest['relocation_removals'][0]['line']=self.line
        self.assertIsNotNone(self.capture())
    def test_outside_extent(self):
        self.manifest['data'][0]['size']=4
        with self.assertRaises(ValueError):self.capture()
    def test_fake_data_section(self):
        self.manifest['data'][0]['section']='.data'
        with self.assertRaises(ValueError):self.capture()
    def test_wrong_module(self):
        self.manifest['relocation_removals'][0]['path']='config/usa/arm9/overlays/ov004/relocs.txt'
        with self.assertRaises(ValueError):self.capture()
    def test_non_load(self):
        self.manifest['relocation_removals'][0]['line']=self.line.replace('kind:load','kind:arm_call')
        with self.assertRaises(ValueError):self.capture()
    def test_original_hash(self):
        self.manifest['data'][0]['sha256']='0'*64
        with self.assertRaises(ValueError):self.capture()
    def test_original_word(self):
        self.manifest['relocation_removals'][0]['original_word_hex']='021701dc'
        with self.assertRaises(ValueError):self.capture()
    def test_source_changed(self):
        (self.worker/'src/Table.cpp').write_text('changed')
        with self.assertRaises(ValueError):self.capture()
    def test_concurrent_map_change(self):
        snapshot=self.capture();(self.main/self.path).write_text('concurrent')
        with self.assertRaises(ValueError):install_relocations(self.main,snapshot)
    def test_verify_changed(self):
        snapshot=self.capture();install_relocations(self.main,snapshot)
        (self.main/self.path).write_text('concurrent')
        with self.assertRaises(ValueError):verify_relocations(self.main,snapshot)
    def test_bss(self):
        self.manifest['data'][0]['section']='.bss'
        with self.assertRaises(ValueError):self.capture()
    def test_worker_still_has_line(self):
        (self.worker/self.path).write_text(self.line+'\n')
        with self.assertRaises(ValueError):self.capture()
    def test_duplicate_removal(self):
        self.manifest['relocation_removals'].append(copy.deepcopy(self.manifest['relocation_removals'][0]))
        with self.assertRaises(ValueError):self.capture()

if __name__ == '__main__':unittest.main()
