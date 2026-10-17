import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import tempfile
import unittest
import sys
sys.path.insert(0,str(Path(__file__).parents[1]))

SPEC = importlib.util.spec_from_file_location('audit_bss_layout', Path(__file__).parents[1] / 'audit_bss_layout.py')
module = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(module)
BASE = 0x02000000


def fixture(linked=False, bss_type=8, object_size=32, section_size=32, object_shift=0, init=False, boundary_shift=0, duplicate_other_section=False):
    section_name = 'ARM9' if linked else '.bss'
    section = dict(name=section_name, type=1 if linked else bss_type, flags=3,
                   address=BASE if linked else 0, size=0 if linked else section_size,
                   data=b'' if linked or bss_type == 8 else bytes(section_size), align=4)
    descriptions = [section]
    if init:
        descriptions.append(dict(name='.init', type=1, flags=6, address=0, size=4, data=bytes(4), align=4))
    labels = ['global'] + (['ARM9_BSS_START', 'ARM9_BSS_END'] if linked else [])
    strings = b'\0'
    offsets = {}
    for label in labels:
        offsets[label] = len(strings)
        strings += label.encode() + b'\0'
    entries = bytes(16) + struct.pack('<IIIBBH', offsets['global'], (BASE + 32 if linked else 0) + object_shift, object_size, 0x11, 0, 1)
    if duplicate_other_section:
        entries += struct.pack('<IIIBBH',offsets['global'],BASE+100,32,0x11,0,2)
    if linked:
        for label, value in [('ARM9_BSS_START', BASE + 16), ('ARM9_BSS_END', BASE + 80 + boundary_shift)]:
            entries += struct.pack('<IIIBBH', offsets[label], value, 0, 0x10, 0, 1)
    descriptions += [dict(name='.shstrtab', type=3, flags=0, address=0, data=b'', size=0, align=1),
                     dict(name='.strtab', type=3, flags=0, address=0, data=strings, size=len(strings), align=1),
                     dict(name='.symtab', type=2, flags=0, address=0, data=entries, size=len(entries), align=4)]
    section_strings = b'\0'
    section_offsets = {}
    for description in descriptions:
        section_offsets[description['name']] = len(section_strings)
        section_strings += description['name'].encode() + b'\0'
    names_index = next(i for i, s in enumerate(descriptions, 1) if s['name'] == '.shstrtab')
    descriptions[names_index - 1].update(data=section_strings, size=len(section_strings))
    strings_index = names_index + 1
    payload = b''
    sections = bytes(40)
    for description in descriptions:
        offset = 52 + len(payload)
        payload += description['data']
        sections += struct.pack('<10I', section_offsets[description['name']], description['type'], description['flags'],
                                description['address'], offset, description['size'],
                                strings_index if description['type'] == 2 else 0, 1 if description['type'] == 2 else 0,
                                description['align'], 16 if description['type'] == 2 else 0)
    header = struct.pack('<16sHHIIIIIHHHHHH', b'\x7fELF\x01\x01\x01' + bytes(9), 2 if linked else 1, 40, 1,
                         0, 0, 52 + len(payload), 0, 52, 0, 0, 40, len(descriptions) + 1, names_index)
    return header + payload + sections


class BssAuditTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'src').mkdir()
        (self.root / 'build').mkdir()
        (self.root / 'src/Unit.cpp').write_text('char global[32];\n')
        self.config = self.root / 'original.yaml'
        self.config.write_text(f'base_address: {BASE}\nbss_start: {BASE+16}\nbss_end: {BASE+80}\n')
        self.original = self.root / 'original.bin'
        self.generated = self.root / 'generated.bin'
        self.original.write_bytes(bytes(16))
        self.generated.write_bytes(bytes(16))
        self.linked = self.root / 'linked.elf'
        self.target = self.root / 'build/target.o'
        self.candidate = self.root / 'build/candidate.o'
        self.linked.write_bytes(fixture(linked=True))
        self.target.write_bytes(fixture())
        self.candidate.write_bytes(fixture())
        self.objdiff = self.root / 'objdiff.json'
        self.objdiff.write_text(json.dumps({'units': [dict(name='src/Unit', target_path='build/target.o', base_path='build/candidate.o', metadata=dict(source_path='src/Unit.cpp', complete=True))]}))
        self.manifest = dict(module='main', data=[dict(name='global', address=BASE+32, size=32, source='src/Unit.cpp', section='.bss')],
                             source_hashes={'src/Unit.cpp': hashlib.sha256((self.root/'src/Unit.cpp').read_bytes()).hexdigest()},
                             original_bss_metadata_sha256=hashlib.sha256(self.config.read_bytes()).hexdigest())

    def audit(self):
        return module.audit(self.root, self.manifest, self.linked, self.config, self.original, self.generated, self.objdiff)

    def test_exact_pod_bss(self):
        self.assertEqual(self.audit()['bss_bytes'], 32)

    def test_initialized_storage_rejected(self):
        self.candidate.write_bytes(fixture(bss_type=1))
        with self.assertRaisesRegex(ValueError, 'SHT_NOBITS'):
            self.audit()

    def test_hidden_initializer_rejected(self):
        self.candidate.write_bytes(fixture(init=True))
        with self.assertRaisesRegex(ValueError, 'allocated section'):
            self.audit()

    def test_extra_padding_reservation_rejected(self):
        self.candidate.write_bytes(fixture(section_size=36))
        with self.assertRaisesRegex(ValueError, 'owned extents'):
            self.audit()

    def test_wrong_symbol_size_rejected(self):
        self.candidate.write_bytes(fixture(object_size=28))
        with self.assertRaisesRegex(ValueError, 'size/extent'):
            self.audit()

    def test_shifted_linked_object_rejected(self):
        self.linked.write_bytes(fixture(linked=True, object_shift=4))
        with self.assertRaisesRegex(ValueError, 'Linked BSS object'):
            self.audit()

    def test_changed_bss_end_rejected(self):
        self.linked.write_bytes(fixture(linked=True, boundary_shift=4))
        with self.assertRaisesRegex(ValueError, 'boundary differs'):
            self.audit()

    def test_original_metadata_hash_rejected(self):
        self.manifest['original_bss_metadata_sha256'] = '0' * 64
        with self.assertRaisesRegex(ValueError, 'metadata hash'):
            self.audit()

    def test_source_change_rejected(self):
        (self.root / 'src/Unit.cpp').write_text('char global[32] = {1};\n')
        with self.assertRaisesRegex(ValueError, 'Source location/hash'):
            self.audit()

    def test_module_change_rejected(self):
        self.generated.write_bytes(bytes(15) + b'\1')
        with self.assertRaisesRegex(ValueError, 'Module bytes/extent'):
            self.audit()

    def test_hardlinked_original_rejected(self):
        self.generated.unlink()
        self.generated.hardlink_to(self.original)
        with self.assertRaisesRegex(ValueError, 'independent files'):
            self.audit()

    def test_overlapping_rows_rejected(self):
        self.manifest['data'].append(dict(self.manifest['data'][0], name='other'))
        with self.assertRaisesRegex(ValueError, 'Overlapping linked'):
            self.audit()


if __name__ == '__main__':
    unittest.main()

class DeclaredPayloadTests(unittest.TestCase):
    def test_declared_mixed_payload_sizes(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/'mixed.o';path.write_bytes(fixture(init=True))
            rows=[dict(name='global',size=32)]
            declared=[dict(section='.bss',start=0,end=32),dict(section='.init',start=32,end=36)]
            result=module.object_layout(path,rows,declared)
            self.assertEqual([s['name'] for s in result['allocated']],['.bss','.init'])
            with self.assertRaisesRegex(ValueError,'declared payload'):
                module.object_layout(path,rows,declared[:1])

    def test_overlay_bounds_are_original_entry(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/'overlays.yaml'
            path.write_text('overlays:\n- id: 1\n  base_address: 1000\n  code_size: 100\n  bss_size: 20\n- id: 34\n  base_address: 2000\n  code_size: 200\n  bss_size: 40\n')
            self.assertEqual(module.original_bounds(path,'ov034'),dict(base_address=2000,bss_start=2200,bss_end=2240))
            with self.assertRaises(ValueError):module.original_bounds(path,'ov002')

class LinkedSectionFilterTests(unittest.TestCase):
    def test_filter_rejects_missing_module(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/'linked.o';path.write_bytes(fixture(linked=True))
            with self.assertRaisesRegex(ValueError,'selected ELF module'):
                module.read_elf(path,{'global'},'OV001')
            self.assertIn('global',module.read_elf(path,{'global'},'ARM9')['symbols'])

    def test_duplicate_in_other_section_is_ignored(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/'linked.o';path.write_bytes(fixture(linked=True,init=True,duplicate_other_section=True))
            with self.assertRaisesRegex(ValueError,'Duplicate selected'):
                module.read_elf(path,{'global'})
            self.assertEqual(module.read_elf(path,{'global'},'ARM9')['symbols']['global']['value'],BASE+32)
