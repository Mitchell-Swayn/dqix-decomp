import struct
import unittest
from export_item_sprites import decode_frames


def sample(pixels=None, x=0):
    pixels = pixels if pixels is not None else bytes([0x21] * 32)
    return (struct.pack('<HHHHI4H', 1, 3, 8, 8, 1, x, 0, 0, 0) + pixels
            + struct.pack('<I4H', 4, 0x7c1f, 0x001f, 0x03e0, 0x7c00))


class SpriteDecodeTests(unittest.TestCase):
    def test_nibble_order_rgb_and_transparency(self):
        width, height, rgba = decode_frames(sample(bytes([0x20, 0x31]) + bytes(30)))[0]
        self.assertEqual((width, height), (8, 8))
        self.assertEqual(rgba[3], 0)
        self.assertEqual(rgba[4:8], bytes([0, 255, 0, 255]))
        self.assertEqual(rgba[8:12], bytes([255, 0, 0, 255]))
        self.assertEqual(rgba[12:16], bytes([0, 0, 255, 255]))

    def test_rejects_truncated_palette(self):
        with self.assertRaises(ValueError):
            decode_frames(sample()[:-1])

    def test_rejects_rectangle_outside_frame(self):
        with self.assertRaises(ValueError):
            decode_frames(sample(x=1))

    def test_rejects_missing_palette_index(self):
        with self.assertRaises(ValueError):
            decode_frames(sample(bytes([0xff] * 32)))
