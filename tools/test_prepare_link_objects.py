import struct
import tempfile
import unittest
from pathlib import Path
from prepare_link_objects import InvalidElf, prepare_elf, prepare_objects, read_symbol_config

CONFIG = {'_fdiv': dict(address=0x0200c1c0, size=0x3b8, type=2),
          '.L_0200c274': dict(address=0x0200c274, size=256, type=1)}


def fixture(binding=1, object_start=0xb4, object_size=256, function_size=0x3b8, text_size=0x3b8, object_name='.L_0200c274'):
    names = b'\0_fdiv\0' + object_name.encode() + b'\0'
    text = bytes(i % 256 for i in range(text_size))
    strings_offset = 52 + text_size
    symbols_offset = strings_offset + len(names)
    symbols = bytes(16) + struct.pack('<IIIBBH', 1, 0, function_size, 0x12, 0, 1)
    symbols += struct.pack('<IIIBBH', 7, object_start, object_size, binding << 4 | 1, 0, 1)
    section_offset = symbols_offset + len(symbols)
    header = struct.pack('<16sHHIIIIIHHHHHH', b'\x7fELF\x01\x01\x01' + bytes(9), 1, 40, 1, 0, 0, section_offset, 0, 52, 0, 0, 40, 4, 0)
    sections = bytes(40)
    sections += struct.pack('<IIIIIIIIII', 0, 1, 6, 0, 52, text_size, 0, 0, 4, 0)
    sections += struct.pack('<IIIIIIIIII', 0, 3, 0, 0, strings_offset, len(names), 0, 0, 1, 0)
    sections += struct.pack('<IIIIIIIIII', 0, 2, 0, 0, symbols_offset, len(symbols), 2, 1, 4, 16)
    return header + text + names + symbols + sections


class LinkObjectsTests(unittest.TestCase):
    def test_only_allowlisted_size_changes(self):
        original = fixture()
        patched, changes = prepare_elf(original, CONFIG)
        self.assertEqual(len(changes), 1)
        change = changes[0]
        self.assertEqual((change['symbol'], change['owner'], change['original_size']), ('.L_0200c274', '_fdiv', 256))
        offset = change['st_size_offset']
        self.assertEqual(patched, original[:offset] + bytes(4) + original[offset + 4:])
        self.assertEqual(prepare_elf(patched, CONFIG), (patched, []))

    def test_valid_size_sum_is_unchanged(self):
        original = fixture(text_size=0x4b8)
        self.assertEqual(prepare_elf(original, CONFIG), (original, []))

    def test_other_global_and_local_objects_not_repaired(self):
        for original in [fixture(object_name='ordinary_global'), fixture(binding=0)]:
            with self.assertRaises(InvalidElf):
                prepare_elf(original, CONFIG)

    def test_changed_ranges_rejected(self):
        for original in [fixture(object_start=0x3b0), fixture(object_start=0xb8), fixture(object_size=252), fixture(function_size=0x3bc)]:
            with self.assertRaises(InvalidElf):
                prepare_elf(original, CONFIG)

    def test_configured_address_and_owner_required(self):
        for config in [{}, dict(CONFIG, _fdiv=dict(address=0x0200c1c4, size=0x3b8, type=2))]:
            with self.assertRaises(InvalidElf):
                prepare_elf(fixture(), config)

    def test_rejects_wrong_format_and_truncation(self):
        original = fixture()
        for bad in [b'', original[:40], original[:-1], original[:4] + b'\x02' + original[5:], original[:18] + b'\x03\0' + original[20:]]:
            with self.subTest(length=len(bad)), self.assertRaises(InvalidElf):
                prepare_elf(bad, CONFIG)

    def test_originals_and_source_objects_preserved(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            fallback = root / 'delinks'
            fallback.mkdir()
            original = fallback / 'main_5.o'
            original.write_bytes(fixture())
            source = root / 'source.o'
            source.write_bytes(b'not a fallback ELF')
            objects = root / 'objects.txt'
            objects.write_text(f'"{original}"\n"{source}"\n')
            output = root / 'link_objects.txt'
            prepare_objects(objects, fallback, root / 'link_objects', output, root / 'report.json', CONFIG)
            self.assertEqual(original.read_bytes(), fixture())
            self.assertEqual(source.read_bytes(), b'not a fallback ELF')
            self.assertIn(str(source), output.read_text())
            self.assertNotEqual((root / 'link_objects/main_5.o').read_bytes(), original.read_bytes())
            with self.assertRaises(ValueError):
                prepare_objects(objects, fallback, fallback, output, root / 'report.json', CONFIG)
            with self.assertRaises(ValueError):
                prepare_objects(objects, fallback, root / 'link_objects', objects, root / 'report.json', CONFIG)
            symbols = root / 'symbols.txt'
            symbols.write_text('_fdiv kind:function(arm,size=0x3b8) addr:0x0200c1c0\n.L_0200c274 kind:data(byte[256]) addr:0x0200c274\n')
            self.assertEqual(read_symbol_config(symbols), CONFIG)


if __name__ == '__main__':
    unittest.main()
