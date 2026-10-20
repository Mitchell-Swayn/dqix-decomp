import json
import os
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

from generate_lcf import apply_absolute_symbols, apply_module_symbols
from arm7_build import read_elf


class AbsoluteSymbolsTest(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.lcf = self.root / "arm9.lcf"
        self.config = self.root / "linker_symbols.json"
        self.original = "MEMORY {}\nSECTIONS {\n    .text : {}\n}\n"
        self.lcf.write_text(self.original)

    def test_optional_config_preserves_lcf(self):
        apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), self.original)

    def test_absolute_values_add_no_sections(self):
        self.config.write_text(json.dumps({"SDK_SYS_STACKSIZE": "0x0", "SDK_IRQ_STACKSIZE": "0x400"}))
        apply_absolute_symbols(self.lcf, self.config)
        expected = self.original.replace("SECTIONS {", "SECTIONS {\n    SDK_SYS_STACKSIZE = 0x0;\n    SDK_IRQ_STACKSIZE = 0x400;")
        self.assertEqual(self.lcf.read_text(), expected)
        with self.assertRaises(ValueError):
            apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), expected)

    def alias_config(self, **changes):
        alias = dict(base="data_table", offset="0x600", object="Table.o", section=".rodata")
        alias.update(changes)
        return {"data_midpoint": alias}

    def write_alias_fixture(self):
        self.original = "MEMORY {}\nSECTIONS {\n    .arm9 : {\n        Table.o(.rodata)\n    }\n}\n"
        self.lcf.write_text(self.original)
        (self.root / "symbols.txt").write_text(
            "data_table kind:data(any) addr:0x02000000\n"
            "data_midpoint kind:data(any) addr:0x02000600\n")

    def test_interior_alias_follows_owner_in_output_section(self):
        self.write_alias_fixture()
        self.config.write_text(json.dumps(self.alias_config()))
        apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), self.original.replace(
            "        Table.o(.rodata)",
            "        Table.o(.rodata)\n        data_midpoint = data_table + 0x600;"))

    def test_missing_or_duplicate_owner_is_rejected_without_write(self):
        self.write_alias_fixture()
        self.config.write_text(json.dumps(self.alias_config()))
        for text in [self.original.replace("Table.o", "Other.o"),
                     self.original.replace("Table.o(.rodata)", "Table.o(.rodata)\n        Table.o(.rodata)")]:
            self.lcf.write_text(text)
            with self.assertRaises(ValueError):
                apply_absolute_symbols(self.lcf, self.config)
            self.assertEqual(self.lcf.read_text(), text)

    def test_missing_base_symbol_is_rejected_without_write(self):
        self.write_alias_fixture()
        self.config.write_text(json.dumps(self.alias_config(base="undeclared_table")))
        with self.assertRaises(ValueError):
            apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), self.original)

    def test_invalid_alias_schema_is_rejected_without_write(self):
        self.write_alias_fixture()
        bad = [self.alias_config(base="data_table;"), self.alias_config(offset="0x100000000"),
               self.alias_config(object="../Table.o"), self.alias_config(section=".rodata);"),
               self.alias_config(base="data_midpoint"), self.alias_config(extra="0x0"),
               self.alias_config(offset=2)]
        for config in bad:
            with self.subTest(config=config):
                self.config.write_text(json.dumps(config))
                with self.assertRaises(ValueError):
                    apply_absolute_symbols(self.lcf, self.config)
                self.assertEqual(self.lcf.read_text(), self.original)

    def test_invalid_config_does_not_modify_lcf(self):
        for config in [{"BAD;": "0x0"}, {"GOOD": "0x100000000"}, {"GOOD": 1},
                       {"BAD": "data + 1"}, {"BAD": "data + 0x100000000"}, []]:
            with self.subTest(config=config):
                self.config.write_text(json.dumps(config))
                with self.assertRaises(ValueError):
                    apply_absolute_symbols(self.lcf, self.config)
                self.assertEqual(self.lcf.read_text(), self.original)

    def test_missing_sections_is_rejected(self):
        self.config.write_text('{"GOOD": "0x0"}')
        self.lcf.write_text("unexpected LCF layout")
        with self.assertRaises(ValueError):
            apply_absolute_symbols(self.lcf, self.config)
        self.assertEqual(self.lcf.read_text(), "unexpected LCF layout")

    def write_module_fixture(self):
        directory = self.root / "arm9"
        itcm = directory / "itcm"
        itcm.mkdir(parents=True)
        (directory / "linker_symbols.json").write_text('{"SDK_IRQ_STACKSIZE": "0x400"}')
        (itcm / "symbols.txt").write_text(
            'table kind:bss(size=0x1000) addr:0x01ff8000\n'
            'table_end kind:bss(size=0x0) addr:0x01ff9000\n')
        (itcm / "linker_symbols.json").write_text(json.dumps({"table_end": dict(
            base="table", offset="0x1000", object="ItcmTable.o", section=".bss")}))
        self.original = ('MEMORY {}\nSECTIONS {\n    .arm9 : {\n        Main.o(.text)\n    } > ARM9\n'
                         '    .itcm : {\n        ItcmTable.o(.bss)\n    } > ITCM\n}\n')
        self.lcf.write_text(self.original)
        return directory, itcm

    def test_module_local_alias_uses_own_symbols_and_section(self):
        directory, _ = self.write_module_fixture()
        apply_module_symbols(self.lcf, directory)
        self.assertIn('SDK_IRQ_STACKSIZE = 0x400;', self.lcf.read_text())
        self.assertIn('ItcmTable.o(.bss)\n        table_end = table + 0x1000;', self.lcf.read_text())

    def test_cross_module_owner_rejected_and_all_changes_rolled_back(self):
        directory, _ = self.write_module_fixture()
        wrong = self.original.replace('Main.o(.text)', 'ItcmTable.o(.bss)').replace(
            '    .itcm : {\n        ItcmTable.o(.bss)\n    } > ITCM\n', '')
        self.lcf.write_text(wrong)
        with self.assertRaisesRegex(ValueError, 'outside module'):
            apply_module_symbols(self.lcf, directory)
        self.assertEqual(self.lcf.read_text(), wrong)

    def test_symbol_in_different_module_does_not_satisfy_alias(self):
        directory, itcm = self.write_module_fixture()
        (directory / 'symbols.txt').write_bytes((itcm / 'symbols.txt').read_bytes())
        (itcm / 'symbols.txt').write_text('table_end kind:bss(size=0x0) addr:0x01ff9000\n')
        with self.assertRaisesRegex(ValueError, 'base missing'):
            apply_module_symbols(self.lcf, directory)
        self.assertEqual(self.lcf.read_text(), self.original)

    def test_unknown_module_is_rejected_without_modifying_lcf(self):
        directory, _ = self.write_module_fixture()
        bad = directory / 'unrecognized'
        bad.mkdir()
        (bad / 'linker_symbols.json').write_text('{}')
        with self.assertRaisesRegex(ValueError, 'Unknown linker alias module'):
            apply_module_symbols(self.lcf, directory)
        self.assertEqual(self.lcf.read_text(), self.original)


class PinnedLinkerAliasTest(unittest.TestCase):
    @unittest.skipUnless(os.name == "nt", "pinned MWCC executables require Windows")
    def test_one_past_bss_alias_and_module_end_alignment(self):
        compiler = Path(__file__).resolve().parents[1] / "tools/mwccarm/2.0/sp2p2"
        if not (compiler / "mwccarm.exe").is_file():
            self.skipTest("pinned MWCC toolchain unavailable")
        with tempfile.TemporaryDirectory(prefix="lcf queue ") as directory:
            root = Path(directory)
            config_directory = root / 'arm9'
            itcm = config_directory / 'itcm'
            itcm.mkdir(parents=True)
            (root / 'Queue.cpp').write_text(
                'unsigned int queue[1024];\nextern unsigned char queue_end[];\n'
                'extern const unsigned char* const pointer = queue_end;\n'
                'extern "C" int entry() { return queue[0]; }\n')
            lcf = root / 'test.lcf'
            lcf.write_text('MEMORY { ARM9 : ORIGIN = 0x02000000\n'
                           'ITCM : ORIGIN = 0x01ffe270 }\nSECTIONS {\n'
                           '    .arm9 : {\n        Queue.o(.text)\n        Queue.o(.rodata)\n    } > ARM9\n'
                           '    .itcm : {\n        Queue.o(.bss)\n'
                           '        . = ALIGN(32);\n        bss_end = .;\n    } > ITCM\n}\n')
            (itcm / 'symbols.txt').write_text(
                'queue kind:bss(size=0x1000) addr:0x01ffe270\n'
                'queue_end kind:bss(size=0x0) addr:0x01fff270\n')
            (itcm / 'linker_symbols.json').write_text(json.dumps({'queue_end': dict(
                base='queue', offset='0x1000', object='Queue.o', section='.bss')}))
            apply_module_symbols(lcf, config_directory)
            commands = [[str(compiler / 'mwccarm.exe'), '-O2', '-proc', 'arm946e', '-nolink',
                         '-sym', 'on', '-lang=c++', '-gccinc', '-c', 'Queue.cpp', '-o', 'Queue.o'],
                        [str(compiler / 'mwldarm.exe'), '-proc', 'arm946e', '-nostdlib',
                         '-m', 'entry', '-force_active', 'queue,pointer', 'Queue.o', 'test.lcf',
                         '-o', 'linked.o']]
            for command in commands:
                result = subprocess.run(command, cwd=root, capture_output=True, text=True)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            allocated, symbols, _ = read_elf(root / 'linked.o')
            self.assertEqual(symbols['queue_end'], symbols['queue'] + 4096)
            self.assertEqual(symbols['bss_end'] - symbols['queue_end'], 16)
            _, address, image = allocated[0]
            self.assertEqual(struct.unpack_from('<I', image, symbols['pointer'] - address)[0],
                             symbols['queue_end'])

    @unittest.skipUnless(os.name == "nt", "pinned MWCC executables require Windows")
    def test_alias_address_section_and_relocation(self):
        compiler = Path(__file__).resolve().parents[1] / "tools/mwccarm/2.0/sp2p2"
        if not (compiler / "mwccarm.exe").is_file():
            self.skipTest("pinned MWCC toolchain unavailable")
        with tempfile.TemporaryDirectory(prefix="lcf alias ") as directory:
            root = Path(directory)
            source = root / "Table.cpp"
            source.write_text(
                'extern const unsigned short data_table[4] = {1, 2, 3, 4};\n'
                'extern const unsigned short data_midpoint;\n'
                'extern const unsigned short* const data_pointer = &data_midpoint;\n'
                'extern "C" int entry() { return data_midpoint; }\n')
            lcf = root / "test.lcf"
            lcf.write_text('MEMORY { ARM9 : ORIGIN = 0x02000000 }\n'
                           'SECTIONS {\n    .arm9 : {\n        Table.o(.text)\n'
                           '        Table.o(.rodata)\n        Table.o(.data)\n    } > ARM9\n}\n')
            config = root / "linker_symbols.json"
            config.write_text(json.dumps({"data_midpoint": dict(
                base="data_table", offset="0x2", object="Table.o", section=".rodata")}))
            (root / "symbols.txt").write_text(
                "data_table kind:data(any) addr:0x02000000\n"
                "data_midpoint kind:data(any) addr:0x02000002\n")
            apply_absolute_symbols(lcf, config)
            commands = [[str(compiler / "mwccarm.exe"), "-O2", "-proc", "arm946e", "-nolink",
                         "-sym", "on", "-lang=c++", "-gccinc", "-c", str(source), "-o", str(root / "Table.o")],
                        [str(compiler / "mwldarm.exe"), "-proc", "arm946e", "-nostdlib",
                         "-m", "entry", "-force_active", "data_table,data_pointer",
                         "Table.o", "test.lcf", "-o", "linked.o"]]
            for command in commands:
                result = subprocess.run(command, cwd=root, capture_output=True, text=True)
                self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            linked = root / "linked.o"
            allocated, symbols, _ = read_elf(linked)
            self.assertIn("data_table", symbols, sorted(symbols))
            self.assertEqual(symbols["data_midpoint"], symbols["data_table"] + 2)
            self.assertEqual(len(allocated), 1)
            _, image_address, image = allocated[0]
            pointer_offset = symbols["data_pointer"] - image_address
            self.assertEqual(struct.unpack_from("<I", image, pointer_offset)[0], symbols["data_midpoint"])
            # Correct address alone is insufficient: dsd associates symbols
            # with modules using the ELF section, which follows LCF placement.
            raw = linked.read_bytes()
            header = struct.unpack_from("<16sHHIIIIIHHHHHH", raw)
            sections = [struct.unpack_from("<10I", raw, header[6] + i * header[11])
                        for i in range(header[12])]
            symbol_sections = {}
            for section in sections:
                if section[1] != 2:
                    continue
                strings = sections[section[6]]
                table = raw[strings[4]:strings[4] + strings[5]]
                for offset in range(section[4], section[4] + section[5], section[9]):
                    name, _, _, _, _, index = struct.unpack_from("<IIIBBH", raw, offset)
                    symbol_sections[table[name:table.index(b"\0", name)].decode()] = index
            self.assertEqual(symbol_sections["data_midpoint"], symbol_sections["data_table"])


if __name__ == "__main__":
    unittest.main()
