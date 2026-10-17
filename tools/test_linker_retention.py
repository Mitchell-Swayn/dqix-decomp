import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from linker_retention import retained_data_symbols

class RetentionTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.root=Path(self.temp.name); self.module=self.root/'config/usa/arm9/overlays/ov019'; self.module.mkdir(parents=True)
        source=self.root/'src/Constant.cpp'; source.parent.mkdir(); source.write_text('extern const unsigned value=102400;')
        self.source=source
        (self.module/'symbols.txt').write_text('value kind:data(any) addr:0x1004\n')
        (self.module/'delinks.txt').write_text(' .text start:0x1000 end:0x1004 kind:code\n\nsrc/Constant.cpp:\n complete\n .rodata start:0x1004 end:0x1008\n')
        original=self.root/'extract/usa/arm9_overlays/ov019.bin'; original.parent.mkdir(parents=True);original.write_bytes(bytes(4)+bytes.fromhex('00900100'))
        self.original=original
        self.row=dict(name='value',address='0x1004',size=4,section='.rodata',source='src/Constant.cpp',source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),original_sha256=hashlib.sha256(original.read_bytes()[4:]).hexdigest(),reason='Original unused constant')
    def write(self):
        (self.module/'retained_data.json').write_text(json.dumps(dict(schema_version=1,symbols=[self.row])))
    def test_valid_original_source_owned_data(self):
        self.write();self.assertEqual(retained_data_symbols(self.root,'usa'),['value'])
    def test_no_manifest_no_linker_roots(self):
        self.assertEqual(retained_data_symbols(self.root,'usa'),[])
    def test_unknown_symbol_rejected(self):
        self.row['name']='missing';self.write()
        with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')
    def test_address_and_extent_mismatch_rejected(self):
        for field,value in [('address','0x1005'),('size',3)]:
            old=self.row[field];self.row[field]=value;self.write()
            with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')
            self.row[field]=old
    def test_source_hash_change_rejected(self):
        self.write();self.source.write_text('extern const unsigned value=0;')
        with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')
    def test_original_hash_change_rejected(self):
        self.write();self.original.write_bytes(bytes(8))
        with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')
    def test_overlay_without_text_uses_original_metadata(self):
        path = self.module/'delinks.txt'
        path.write_text(path.read_text().replace('.text start:0x1000 end:0x1004 kind:code', '.rodata start:0x1000 end:0x1008 kind:rodata'))
        (self.original.parent/'overlays.yaml').write_text('overlays:\n- id: 19\n  base_address: 4096\n  code_size: 8\n')
        self.write()
        self.assertEqual(retained_data_symbols(self.root,'usa'), ['value'])
        # A changed base must reject the identical source-owned extent and hash.
        (self.original.parent/'overlays.yaml').write_text('overlays:\n- id: 19\n  base_address: 4100\n  code_size: 8\n')
        with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')
    def test_code_entry_rejected(self):
        self.row['section']='.text';self.write()
        with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')
    def test_path_escape_rejected(self):
        self.row['source']='../Constant.cpp';self.write()
        with self.assertRaises(ValueError):retained_data_symbols(self.root,'usa')

if __name__=='__main__':unittest.main()
