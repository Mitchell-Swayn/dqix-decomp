import unittest
from generate_assembly_fallbacks import render

class ReferenceAssemblyTests(unittest.TestCase):
    def row(self,assembly):
        return dict(id='arm9/main:02000000',module_id='arm9/main',name='PendingFunction',address=0x02000000,size=16,mode='arm',original_sha256='a'*64,assembly=assembly)

    def test_internal_branch_and_literal_preserve_locations(self):
        text=render(self.row('02000000: bne #0x2000008\n02000004: .word 0x01234567 ; literal\n02000008: bx lr'),{})
        self.assertIn('bne loc_02000008',text)
        self.assertIn('dcd 0x01234567 // literal',text)
        self.assertIn('symbol: PendingFunction; size: 0x10',text)
        self.assertIn('Not compiled or linked',text)
        self.assertIn('no C/C++ reconstruction credit',text)

    def test_conditional_call_resolves_current_symbol(self):
        text=render(self.row('02000000: blne #0x2000100'),{('arm9/main',0x02000100):'RenamedCallee'})
        self.assertIn('blne RenamedCallee',text)

    def test_unknown_target_is_explicit(self):
        text=render(self.row('02000000: bl #0x2000100'),{})
        self.assertIn('address_02000100',text)

    def test_empty_disassembly_is_rejected(self):
        with self.assertRaisesRegex(ValueError,'Empty assembly'):
            render(self.row(''),{})

if __name__=='__main__':unittest.main()
