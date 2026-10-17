import hashlib
import json
from pathlib import Path
import struct
import tempfile
import unittest

from normalize_runtime_inline import normalize
from test_prepare_link_objects import fixture


class RuntimeInlineMetadataTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.source = 'src/RuntimeSupport/_fdiv.cpp'
        p = self.root / self.source
        p.parent.mkdir(parents=True)
        p.write_text('extern "C" asm void _fdiv() { bx lr }\n')
        self.row = dict(name='_fdiv',source=self.source,size=952,
                        assembly_form='codewarrior_inline',
                        source_sha256=hashlib.sha256(p.read_bytes()).hexdigest(),
                        inline_metadata=dict(branches=[dict(offset=0,condition=14,displacement=20)],
                                             aliases=[dict(name='.L_0200c274',offset=180,size=256,type=1)]))
        self.policy = self.root / 'config/usa/arm9/runtime_support.json'
        self.policy.parent.mkdir(parents=True)
        self.write_policy()
        self.obj = self.root / 'runtime.o'
        raw = bytearray(fixture())
        struct.pack_into('<I',raw,52,0xea000003)
        self.original = bytes(raw)
        self.obj.write_bytes(self.original)

    def write_policy(self):
        self.policy.write_text(json.dumps(dict(functions=[self.row])))

    def test_executable_contents_unchanged(self):
        normalize(self.obj,self.source,self.root)
        self.assertEqual(self.obj.read_bytes()[52:52+952],self.original[52:52+952])

    def test_sdk_row_without_shared_tails_normalizes_without_changing_code(self):
        self.row.update(evidence_class='sdk_reconstruction',
                        inline_metadata=dict(branches=[], aliases=[], symbol_aliases={}))
        self.write_policy()
        normalize(self.obj, self.source, self.root)
        self.assertEqual(self.obj.read_bytes()[52:52+952], self.original[52:52+952])
        self.assertEqual(self.obj.read_bytes()[:52], self.original[:52])

    def thumb_object(self):
        raw = bytearray(self.original)
        sections = struct.unpack_from('<I', raw, 32)[0]
        symbols = struct.unpack_from('<I', raw, sections + 3 * 40 + 16)[0]
        struct.pack_into('<I', raw, symbols + 16 + 4, 1)
        self.obj.write_bytes(raw)
        return bytes(raw)

    def test_thumb_symbol_bit_and_payload_preserved(self):
        self.row.update(mode='thumb', inline_metadata=dict(branches=[], aliases=[]))
        self.write_policy()
        before = self.thumb_object()
        normalize(self.obj, self.source, self.root)
        after = self.obj.read_bytes()
        sections = struct.unpack_from('<I', after, 32)[0]
        symbols = struct.unpack_from('<I', after, sections + 3 * 40 + 16)[0]
        self.assertEqual(struct.unpack_from('<I', after, symbols + 16 + 4)[0], 1)
        self.assertEqual(after[52:52+952], before[52:52+952])

    def test_declared_thumb_text_alignment_preserves_payload_and_symbol_bit(self):
        self.row.update(mode='thumb', inline_metadata=dict(branches=[], aliases=[], text_alignment=2))
        self.write_policy()
        before = self.thumb_object()
        normalize(self.obj, self.source, self.root)
        after = self.obj.read_bytes()
        sections = struct.unpack_from('<I', after, 32)[0]
        self.assertEqual(struct.unpack_from('<I', after, sections + 40 + 32)[0], 2)
        self.assertEqual(after[52:52+952], before[52:52+952])
        symbols = struct.unpack_from('<I', after, sections + 3 * 40 + 16)[0]
        self.assertEqual(struct.unpack_from('<I', after, symbols + 16 + 4)[0], 1)

    def test_invalid_alignment_and_arm_alignment_rejected_without_writing(self):
        for mode, alignment in (('arm', 2), ('thumb', 1), ('thumb', 4)):
            with self.subTest(mode=mode, alignment=alignment):
                self.row.update(mode=mode, inline_metadata=dict(branches=[], aliases=[], text_alignment=alignment))
                self.write_policy()
                before = self.thumb_object()
                with self.assertRaisesRegex(ValueError, 'alignment'):
                    normalize(self.obj, self.source, self.root)
                self.assertEqual(self.obj.read_bytes(), before)

    def test_thumb_rejects_arm_shared_tail_metadata_without_writing(self):
        self.row['mode'] = 'thumb'
        self.write_policy()
        before = self.thumb_object()
        with self.assertRaisesRegex(ValueError, 'shared-tail.*Thumb'):
            normalize(self.obj, self.source, self.root)
        self.assertEqual(self.obj.read_bytes(), before)

    def test_modified_source_rejected(self):
        (self.root/self.source).write_text('asm void _fdiv() {}')
        with self.assertRaisesRegex(ValueError,'accepted hash'):
            normalize(self.obj,self.source,self.root)
        self.assertEqual(self.obj.read_bytes(),self.original)

    def test_changed_branch_encoding_rejected(self):
        raw = bytearray(self.original)
        struct.pack_into('<I',raw,52,0xea000004)
        self.obj.write_bytes(raw)
        with self.assertRaisesRegex(ValueError,'branch encoding'):
            normalize(self.obj,self.source,self.root)
        self.assertEqual(self.obj.read_bytes(),raw)

    def test_conflicting_alias_rejected(self):
        self.row['inline_metadata']['aliases'][0]['size']=252
        self.write_policy()
        with self.assertRaisesRegex(ValueError,'alias metadata'):
            normalize(self.obj,self.source,self.root)
        self.assertEqual(self.obj.read_bytes(),self.original)


if __name__ == '__main__':
    unittest.main()
