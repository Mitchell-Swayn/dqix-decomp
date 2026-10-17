import struct
import tempfile
import unittest
from pathlib import Path
from normalize_asm_mapping import normalize


class MappingMetadataTests(unittest.TestCase):
    def test_only_named_table_mapping_and_section_size_change(self):
        names = b'\0.text\0.L_table\0$d\0$a\0_fdiv\0'
        text = bytes(i % 256 for i in range(952))
        symbols = bytes(16)
        rows = [(1, 0, 952, 3), (7, 180, 256, 17), (16, 180, 0, 1),
                (16, 948, 0, 1), (19, 0, 0, 2), (22, 0, 952, 18)]
        for name, value, size, info in rows:
            symbols += struct.pack('<IIIBBH', name, value, size, info, 0, 1)
        strings_offset = 52 + len(text)
        symbols_offset = strings_offset + len(names)
        section_offset = symbols_offset + len(symbols)
        header = struct.pack('<16sHHIIIIIHHHHHH', b'\x7fELF\x01\x01\x01' + bytes(9),
                             1, 40, 1, 0, 0, section_offset, 0, 52, 0, 0, 40, 4, 0)
        sections = bytes(40)
        sections += struct.pack('<10I', 0, 1, 6, 0, 52, len(text), 0, 0, 4, 0)
        sections += struct.pack('<10I', 0, 3, 0, 0, strings_offset, len(names), 0, 0, 1, 0)
        sections += struct.pack('<10I', 0, 2, 0, 0, symbols_offset, len(symbols), 2, 1, 4, 16)
        original = header + text + names + symbols + sections
        expected = bytearray(original)
        struct.pack_into('<I', expected, symbols_offset + 16 + 8, 0)
        struct.pack_into('<I', expected, symbols_offset + 48, 17)
        expected[symbols_offset + 48 + 12] = 0
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / 'runtime.o'
            path.write_bytes(original)
            normalize(path)
            self.assertEqual(path.read_bytes(), expected)
            normalize(path)
            self.assertEqual(path.read_bytes(), expected)


if __name__ == '__main__':
    unittest.main()
