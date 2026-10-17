import importlib.util, json
from pathlib import Path
import tempfile
import unittest

SPEC = importlib.util.spec_from_file_location("generate_lcf", Path(__file__).parents[1] / "generate_lcf.py")
module = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(module)


class DataAlignmentTests(unittest.TestCase):
    def run_case(self, start, end, next_section=".data"):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            config = root / "arm9"
            config.mkdir()
            (config / "delinks.txt").write_text("src/Names.cpp:\n    complete\n    .data start:0x%08x end:0x%08x\n" % (start, end))
            lcf = root / "out.lcf"
            lcf.write_text("SECTIONS {\n    .arm9 : {\n        ALIGNALL(4);\n        old.o(.data)\n        Names.o(.data)\n        next.o(" + next_section + ")\n        later.o(.data)\n    } > ARM9\n}\n")
            module.apply_source_data_alignment(lcf, config)
            return lcf.read_text()

    def test_declared_thumb_split_includes_successor_only(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary); config = root / 'arm9'; config.mkdir()
            (config/'delinks.txt').write_text('src/WaitByLoop.cpp:\n    complete\n    .text start:0x02000466 end:0x0200046a\n')
            (config/'runtime_support.json').write_text(json.dumps({'functions':[{'source':'src/WaitByLoop.cpp','address':'0x02000466','size':4,'mode':'thumb','inline_metadata':{'text_alignment':2}}]}))
            lcf=root/'out.lcf'; lcf.write_text('SECTIONS {\n    .arm9 : {\n        ALIGNALL(4);\n        old.o(.text)\n        WaitByLoop.o(.text)\n        next.o(.text)\n        later.o(.text)\n    } > ARM9\n}\n')
            module.apply_source_data_alignment(lcf,config)
            self.assertIn('ALIGNALL(1);\n        WaitByLoop.o(.text)\n        next.o(.text)\n        ALIGNALL(4);\n        later.o(.text)',lcf.read_text())
            policy=json.loads((config/'runtime_support.json').read_text()); policy['functions'][0]['address']='0x02000464'; (config/'runtime_support.json').write_text(json.dumps(policy))
            with self.assertRaisesRegex(ValueError, 'accepted source range'): module.apply_source_data_alignment(lcf,config)

    def test_aligned_range_unchanged(self):
        text = self.run_case(0x2001000, 0x2001004)
        self.assertNotIn("ALIGNALL(1)", text)

    def test_unaligned_start_restore_after_owner(self):
        text = self.run_case(0x2001002, 0x2001004)
        self.assertIn("ALIGNALL(1);\n        Names.o(.data)\n        ALIGNALL(4);", text)

    def test_unaligned_end_includes_successor(self):
        text = self.run_case(0x2001000, 0x2001002)
        self.assertIn("Names.o(.data)\n        next.o(.data)\n        ALIGNALL(4);", text)
        self.assertIn("old.o(.data)\n        ALIGNALL(1);", text)

    def test_different_section_not_included(self):
        text = self.run_case(0x2001000, 0x2001002, ".bss")
        self.assertIn("Names.o(.data)\n        ALIGNALL(4);\n        next.o(.bss)", text)

    def test_same_object_name_in_different_modules_is_scoped(self):
        with tempfile.TemporaryDirectory() as temporary:
            root=Path(temporary);config=root/'arm9';overlay=config/'overlays/ov001';overlay.mkdir(parents=True)
            (config/'delinks.txt').write_text('src/Main/Names.cpp:\n    .data start:0x02001000 end:0x02001004\n')
            (overlay/'delinks.txt').write_text('src/Overlay/Names.cpp:\n    .data start:0x02101002 end:0x02101004\n')
            lcf=root/'out.lcf';lcf.write_text('SECTIONS {\n .arm9 : {\n  Names.o(.data)\n } > ARM9\n .ov001 : {\n  Names.o(.data)\n } > OV001\n}\n')
            module.apply_source_data_alignment(lcf,config)
            text=lcf.read_text();self.assertEqual(text.count('ALIGNALL(1)'),1)
            self.assertIn('.arm9 : {\n  Names.o(.data)\n }',text)
            self.assertIn('.ov001 : {\n  ALIGNALL(1);\n  Names.o(.data)',text)

    def test_duplicate_owning_input_is_rejected(self):
        with tempfile.TemporaryDirectory() as temporary:
            root=Path(temporary);config=root/'arm9';config.mkdir()
            (config/'delinks.txt').write_text('src/Names.cpp:\n    .data start:0x02001002 end:0x02001004\n')
            lcf=root/'out.lcf';lcf.write_text('SECTIONS {\n .arm9 : {\n  Names.o(.data)\n  Names.o(.data)\n } > ARM9\n}\n')
            with self.assertRaisesRegex(ValueError,'one owning'):module.apply_source_data_alignment(lcf,config)


if __name__ == "__main__":
    unittest.main()
