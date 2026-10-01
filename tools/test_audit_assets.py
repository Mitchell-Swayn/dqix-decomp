import struct
import unittest

from audit_assets import audit, inspect_pe, names, narc, native_candidates, nitrofs, script_shape


class AssetAuditTests(unittest.TestCase):
    def rom(self, payload=b'abc'):
        data = bytearray(0x400)
        fnt = struct.pack('<IHH', 8, 0, 1) + b'\x05a.bin\x00'
        struct.pack_into('<4I', data, 0x40, 0x180, len(fnt), 0x200, 8)
        data[0x180:0x180+len(fnt)] = fnt
        struct.pack_into('<II', data, 0x200, 0x300, 0x300+len(payload))
        data[0x300:0x300+len(payload)] = payload
        return data

    def test_nitrofs_round_trip(self):
        self.assertEqual(nitrofs(self.rom()), {'a.bin': b'abc'})
        self.assertTrue(audit(self.rom(), self.rom())['nitrofs_equal'])

    def test_gpc_members_are_included_in_recursive_audit(self):
        table = struct.pack('<I3I', 12 << 3, 123, 0, 7)
        names_data = struct.pack('<I', 4 << 3) + b'a\0\0\0'
        payload = struct.pack('<I', 3 << 3) + b'xyz\0'
        header = struct.pack('<4s6HI', b'GPC2', 1, 5, 9, 11, 3, 1, 2)
        rom = self.rom(header + table + names_data + payload)
        result = audit(rom, rom)
        self.assertEqual(result['gpc2_containers'], 1)
        self.assertEqual(result['records_including_members'], 2)
        self.assertEqual(result['records'][1]['path'], 'a.bin::a')
        self.assertEqual(result['records'][1]['size'], 3)

    def test_byte_change_fails(self):
        with self.assertRaisesRegex(ValueError, 'bytes differ'):
            audit(self.rom(), self.rom(b'abd'))

    def test_directory_cycle_fails(self):
        with self.assertRaisesRegex(ValueError, 'cyclic'):
            names(struct.pack('<IHH', 8, 0, 1) + b'\x81a\x00\xf0\x00')

    def test_narc_member_and_bounds(self):
        fat = struct.pack('<4sIHHII', b'BTAF', 20, 1, 0, 0, 3)
        fnt_data = struct.pack('<IHH', 8, 0, 1) + b'\0'
        fnt = struct.pack('<4sI', b'BTNF', 8+len(fnt_data)) + fnt_data
        img = struct.pack('<4sI', b'GMIF', 11) + b'abc'
        body = fat + fnt + img
        header = struct.pack('<4sHHIHH', b'NARC', 0xfffe, 0x100, 16+len(body), 16, 3)
        self.assertEqual(narc(header+body), {'@00000': b'abc'})
        with self.assertRaises(ValueError):
            narc(header+body[:-1])

    def test_script_padding_and_truncation(self):
        data = struct.pack('<iIiI', 1, 24, 2, 1) + b'\x64\x00\x00\x00' + b'\xff'*4 + b'a\0'
        self.assertEqual(script_shape(data)['instruction_padding'], 4)
        self.assertIsNone(script_shape(data[:-1]))

    def test_signature_is_only_candidate(self):
        self.assertEqual(native_candidates(b'abc\x7fELF')[0]['offset'], 3)

    def test_macho_signature_needs_valid_header_and_commands(self):
        invalid = b'\xce\xfa\xed\xfe' + b'\xff' * 24
        self.assertEqual(native_candidates(invalid)[0]['structure']['status'], 'rejected_MachO_signature')
        plausible = struct.pack('<7I', 0xfeedface, 12, 0, 1, 1, 8, 0) + struct.pack('<2I', 2, 8)
        self.assertEqual(native_candidates(plausible)[0]['structure']['status'], 'structural_MachO_candidate')

    def pe_image(self):
        data = bytearray(0x210)
        data[:2] = b'MZ'
        struct.pack_into('<I', data, 0x3c, 0x80)
        data[0x80:0x84] = b'PE\0\0'
        struct.pack_into('<HHIIIHH', data, 0x84, 0x1c0, 1, 0, 0, 0, 96, 0x102)
        struct.pack_into('<H', data, 0x98, 0x10b)
        struct.pack_into('<I', data, 0x98+60, 0x200)
        data[0xf8:0x100] = b'.text\0\0\0'
        struct.pack_into('<II', data, 0xf8+16, 16, 0x200)
        return data

    def test_pe_signature_without_dos_header_rejected(self):
        self.assertEqual(inspect_pe(b'PE\0\0', 0)['status'], 'rejected_PE_signature')

    def test_structural_pe_and_embedded_pe(self):
        image = self.pe_image()
        self.assertEqual(inspect_pe(image, 0x80)['machine'], 0x1c0)
        self.assertEqual(inspect_pe(b'prefix'+image, 0x86)['image_offset'], 6)

    def test_pe_section_outside_payload_rejected(self):
        image = self.pe_image()
        self.assertEqual(inspect_pe(image[:-1], 0x80)['status'], 'rejected_PE_signature')

    def test_wrong_dos_pe_pointer_rejected(self):
        image = self.pe_image()
        struct.pack_into('<I', image, 0x3c, 0x81)
        self.assertEqual(inspect_pe(image, 0x80)['status'], 'rejected_PE_signature')


if __name__ == '__main__':
    unittest.main()
