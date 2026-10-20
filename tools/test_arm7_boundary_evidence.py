import struct
import unittest
from arm7_boundary_evidence import verify_proposal


class BoundaryEvidenceTests(unittest.TestCase):
    def fixture(self):
        payload=bytearray(40)
        struct.pack_into('<3I',payload,0,0xe59f0000,0xe12fff1e,0x12345678)
        struct.pack_into('<I',payload,16,0xebfffffa)
        config={'autoloads':[dict(runtime_address=0x2000,payload_offset=0,size=40)]}
        baseline={'source_rom_sha1':'0'*40}
        proposal={'original_rom_sha1':'0'*40,'ranges':[dict(name='test',start='2000',code_end='2008',end='200c',
                           code_bytes=8,literal_pool_bytes=4,callers=['2010'])]}
        return proposal,bytes(payload),baseline,config

    def test_original_caller_and_exact_pool_reference_support_bounded_claims(self):
        claims,records=verify_proposal(*self.fixture())
        self.assertEqual([(r['start'],r['end'],r['classification']) for r in claims],[(0,8,'instruction'),(8,12,'literal_pool')])
        self.assertEqual(records[0]['direct_callers'][0]['target'],0x2000)
        self.assertEqual(records[0]['pool_loads'][0]['target'],0x2008)
        self.assertEqual(records[0]['original_authorship'],'unknown')

    def test_wrong_caller_or_unreferenced_pool_rejected(self):
        proposal,payload,baseline,config=self.fixture()
        altered=bytearray(payload);struct.pack_into('<I',altered,16,0xebfffffb)
        with self.assertRaisesRegex(ValueError,'caller'):verify_proposal(proposal,altered,baseline,config)
        altered=bytearray(payload);struct.pack_into('<I',altered,0,0xe1a00000)
        with self.assertRaisesRegex(ValueError,'completely referenced'):verify_proposal(proposal,altered,baseline,config)

    def test_branch_into_pool_and_missing_terminal_rejected(self):
        proposal,payload,baseline,config=self.fixture()
        altered=bytearray(payload);struct.pack_into('<I',altered,4,0xeaffffff)
        with self.assertRaisesRegex(ValueError,'branch enters'):verify_proposal(proposal,altered,baseline,config)
        altered=bytearray(payload);struct.pack_into('<I',altered,4,0xe1a00000)
        with self.assertRaisesRegex(ValueError,'unconditional BX'):verify_proposal(proposal,altered,baseline,config)


if __name__=='__main__':unittest.main()
