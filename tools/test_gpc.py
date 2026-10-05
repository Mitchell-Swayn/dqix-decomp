#!/usr/bin/env python3
import struct
import unittest

from gpc import decompress, decompress_nitro_lz, members


def packed(kind, length, content):
    return struct.pack("<I", length << 3 | kind) + content


class GPCCompressionTests(unittest.TestCase):
    def test_raw_and_truncation(self):
        self.assertEqual(decompress(packed(0, 3, b"abc")), b"abc")
        with self.assertRaises(ValueError):
            decompress(packed(0, 4, b"abc"))

    def test_lz_overlapping_copy(self):
        self.assertEqual(decompress(packed(1, 7, b"\x40a\x30\x00")), b"aaaaaaa")
        with self.assertRaises(ValueError):
            decompress(packed(1, 3, b"\x80\x00\x00"))

    def test_rle_literal_and_run(self):
        self.assertEqual(decompress(packed(4, 5, b"\x01ab\x80c")), b"abccc")
        with self.assertRaises(ValueError):
            decompress(packed(4, 2, b"\x80c"))

    def test_huffman_eight_bit_and_nibbles(self):
        # Four-byte tree: root at index1, both children terminal at2/3.
        tree = b"\x01\xc0AB"
        bits = struct.pack("<I", 0x60000000)  # 0,1,1,0
        self.assertEqual(decompress(packed(3, 4, tree + bits)), b"ABBA")
        self.assertEqual(decompress(packed(2, 2, b"\x01\xc0\x01\x02" + bits)), b"\x21\x12")

    def test_malformed_huffman_and_expansion_limit(self):
        with self.assertRaises(ValueError):
            decompress(packed(3, 1, b"\x01\x3fAB" + b"\0" * 4))
        with self.assertRaises(ValueError):
            decompress(packed(0, 999, b""), maximum=10)

    def test_container_offsets_and_name(self):
        entry = struct.pack("<3I", 123, 0, 7)
        table = packed(0, 12, entry)
        names = packed(0, 4, b"a\0\0\0")
        data = packed(0, 3, b"xyz") + b"\0"
        header = struct.pack("<4s6HI", b"GPC2", 1, 5, 9, 11, 3, 1, 2)
        record = members(header + table + names + data)[0]
        self.assertEqual(record["name"], "a")
        self.assertEqual(record["payload"], b"xyz")

    def test_nitro_lz_header(self):
        self.assertEqual(decompress_nitro_lz(struct.pack('<I', 7 << 8 | 0x10) + b'\x40a\x30\x00'), b'aaaaaaa')
        with self.assertRaises(ValueError):
            decompress_nitro_lz(struct.pack('<I', 7 << 8 | 0x11) + b'\x40a\x30\x00')


if __name__ == "__main__":
    unittest.main()
