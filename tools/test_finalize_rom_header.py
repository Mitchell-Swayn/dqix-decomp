#!/usr/bin/env python3
import struct
import unittest

from finalize_rom_header import crc16, restore_metadata


class HeaderFinalizationTests(unittest.TestCase):
    def setUp(self):
        self.original = bytearray(0x9000)
        self.original[12:16] = b"YDQE"
        struct.pack_into("<I", self.original, 0x20, 0x4000)
        struct.pack_into("<H", self.original, 0x6c, 0x1234)
        struct.pack_into("<H", self.original, 0x15e, crc16(self.original[:0x15e]))
        self.raw = bytearray(self.original)
        self.raw[0x6c:0x6e] = b"\0\0"
        struct.pack_into("<H", self.raw, 0x15e, crc16(self.raw[:0x15e]))

    def restore(self):
        return restore_metadata(self.raw, self.original[:0x160], self.original[0x4000:0x8000])

    def test_standard_crc_vector(self):
        self.assertEqual(crc16(b"123456789"), 0x4b37)

    def test_only_metadata_restored_and_input_unmodified(self):
        self.assertEqual(self.restore(), self.original)
        self.assertEqual(self.raw[0x6c:0x6e], b"\0\0")

    def test_already_correct_header_is_unchanged(self):
        self.raw = self.original.copy()
        self.assertEqual(self.restore(), self.original)

    def test_changed_secure_payload_is_rejected(self):
        self.raw[0x7fff] ^= 1
        with self.assertRaisesRegex(ValueError, "secure-area bytes differ"):
            self.restore()

    def test_corrupt_header_is_not_silently_repaired(self):
        self.raw[0x70] ^= 1
        with self.assertRaisesRegex(ValueError, "header CRC16"):
            self.restore()

    def test_wrong_layout_is_rejected(self):
        self.raw[0x20] ^= 4
        with self.assertRaisesRegex(ValueError, "ARM9 offset"):
            self.restore()


if __name__ == "__main__":
    unittest.main()
