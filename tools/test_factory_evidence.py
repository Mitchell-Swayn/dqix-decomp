"""Fixture-based evidence tests: provenance, ELF parsing, bounds and input isolation."""
import hashlib
import json
from pathlib import Path
import struct
import tempfile
import unittest
from unittest.mock import patch

import factory_evidence as evidence


def elf_fixture(rela=False):
    names = b"\0.shstrtab\0.strtab\0.text\0.symtab\0.rel.text\0"
    strings = b"\0Func\0External\0"
    symbols = bytes(16) + struct.pack("<IIIBBH", 1, 0, 4, 0x12, 0, 3) + struct.pack("<IIIBBH", 6, 0, 0, 0x12, 0, 0)
    relocation = struct.pack("<IIi", 0, (2 << 8) | 28, -8) if rela else struct.pack("<II", 0, (2 << 8) | 28)
    payloads = [b"", names, strings, bytes(4), symbols, relocation]
    sections, data = [], bytearray(52)
    for index, payload in enumerate(payloads):
        offset = len(data)
        data.extend(payload)
        name_offset = [0, 1, 11, 19, 25, 33][index]
        kind = [0, 3, 3, 1, 2, 4 if rela else 9][index]
        sections.append((name_offset, kind, 6 if index == 3 else 0, 0, offset, len(payload),
                         2 if index == 4 else 4 if index == 5 else 0,
                         3 if index == 5 else 0, 4, 16 if index == 4 else (12 if rela else 8) if index == 5 else 0))
    section_offset = len(data)
    for section in sections:
        data.extend(struct.pack("<IIIIIIIIII", *section))
    data[:52] = struct.pack("<16sHHIIIIIHHHHHH", b"\x7fELF\x01\x01\x01" + bytes(9), 1, 40, 1, 0,
                            0, section_offset, 0, 52, 0, 0, 40, 6, 1)
    return bytes(data)


class EvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name).resolve()
        self.unit = {"name": "src/Func", "target_path": "build/usa/delinks/src/Func.o",
                     "base_path": "build/usa/src/Func.o", "metadata": {"source_path": "src/Func.cpp"},
                     "scratch": {"compiler": "mwcc_30_137", "c_flags": "-O2", "ctx_path": "build/usa/src/Func.ctx.cpp"}}
        self.write("objdiff.json", json.dumps({"units": [self.unit]}))
        self.write("src/Func.cpp", "extern void External();\nvoid Func() { External(); }\n")
        self.write("include/Func.h", "void Func();\n")
        self.write("build/usa/src/Func.ctx.cpp", "void External();\n")
        self.write(self.unit["target_path"], elf_fixture())
        self.write(self.unit["base_path"], elf_fixture(True))
        self.write("config/usa/arm9/symbols.txt", "Func kind:function(arm,size=0x4) addr:0x02001000\nCaller kind:function(arm,size=0x10) addr:0x02002000\n")
        self.write("config/usa/arm9/relocs.txt", "from:0x02002004 kind:arm_call to:0x02001000 module:main\nfrom:0x02002008 kind:load to:0x02001000 module:main\n")

    def write(self, relative, content):
        path = self.root / relative
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(content) if isinstance(content, bytes) else path.write_text(content, encoding="utf-8")
        return path

    def test_package_real_provenance_and_calls(self):
        self.write("build/matching/attempts.jsonl", json.dumps({"unit": "elsewhere"}) + "\n" +
                   json.dumps({"unit": "src/Func", "status": "compared", "mismatches": 1}) + "\n")
        result = evidence.build_evidence(self.root, "src/Func")
        self.assertEqual(result["source"]["sha256"], hashlib.sha256((self.root / "src/Func.cpp").read_bytes()).hexdigest())
        self.assertIn("void Func()", result["source"]["text"])
        self.assertEqual(result["compiler"]["configured"]["c_flags"], "-O2")
        self.assertIn("External", result["compiler"]["context"]["text"])
        self.assertEqual(result["target"]["analysis"]["symbols"][1]["name"], "Func")
        self.assertEqual(result["target"]["analysis"]["relocations"][0]["symbol"], "External")
        self.assertIsNone(result["target"]["analysis"]["relocations"][0]["addend"])
        self.assertEqual(result["candidate"]["analysis"]["relocations"][0]["addend"], -8)
        self.assertEqual(len(result["callers"]["records"]), 1)
        self.assertEqual(result["callers"]["records"][0]["caller"], "Caller")
        self.assertEqual(result["callers"]["records"][0]["line"], 1)
        self.assertEqual(result["prior_attempts"]["records"][0]["line"], 2)
        self.assertTrue(any(row["path"] == "include/Func.h" for row in result["source_references"]["records"]))

    def test_missing_and_invalid_files_are_explicit(self):
        (self.root / self.unit["base_path"]).unlink()
        (self.root / "src/Func.cpp").unlink()
        self.write(self.unit["target_path"], b"not ELF")
        result = evidence.build_evidence(self.root, "src/Func")
        self.assertEqual(result["source"]["status"], "unavailable")
        self.assertEqual(result["candidate"]["analysis"]["status"], "unavailable")
        self.assertEqual(result["target"]["analysis"]["status"], "unavailable")
        self.assertEqual(result["callers"]["status"], "unavailable")
        self.assertEqual(result["prior_attempts"]["status"], "unavailable")

    def test_exact_unit_and_escape_rejected(self):
        for name in ("Func", "src/func", "../src/Func"):
            with self.assertRaises(ValueError):
                evidence.build_evidence(self.root, name)
        self.write("objdiff.json", json.dumps({"units": [self.unit, self.unit]}))
        with self.assertRaises(ValueError):
            evidence.build_evidence(self.root, "src/Func")
        for key in ("target_path", "base_path"):
            self.write("objdiff.json", json.dumps({"units": [{**self.unit, key: "../outside.o"}]}))
            with self.assertRaises(ValueError):
                evidence.build_evidence(self.root, "src/Func")

    def test_identical_input_paths_rejected(self):
        self.write("objdiff.json", json.dumps({"units": [{**self.unit, "base_path": self.unit["target_path"]}]}))
        with self.assertRaisesRegex(ValueError, "independent"):
            evidence.build_evidence(self.root, "src/Func")

    def test_original_only_unit_supported(self):
        self.write("objdiff.json", json.dumps({"units": [{"name": "main_0", "target_path": self.unit["target_path"]}]}))
        result = evidence.build_evidence(self.root, "main_0")
        self.assertEqual(result["candidate"]["status"], "unavailable")
        self.assertEqual(result["compiler"]["status"], "unavailable")
        self.assertEqual(result["target"]["analysis"]["status"], "available")

    def test_bad_elf_bounds(self):
        samples = [b"", elf_fixture()[:-1]]
        bad = bytearray(elf_fixture())
        struct.pack_into("<I", bad, 32, 0xffffffff)
        samples.append(bytes(bad))
        bad = bytearray(elf_fixture())
        section_offset = struct.unpack_from("<I", bad, 32)[0]
        struct.pack_into("<I", bad, section_offset + 5 * 40 + 24, 999)
        samples.append(bytes(bad))
        for data in samples:
            with self.subTest(size=len(data)):
                path = self.write("bad.o", data)
                with self.assertRaises(ValueError):
                    evidence.read_elf(path)

    def test_ledger_bounds_and_malformed_records(self):
        rows = [{"unit": "src/Func", "variant": index} for index in range(110)]
        self.write("build/matching/attempts.jsonl", "bad json\n" + "\n".join(map(json.dumps, rows)) + "\n")
        result = evidence.prior_attempts(self.root, "src/Func")
        self.assertEqual(len(result["records"]), 100)
        self.assertEqual(result["records"][0]["record"]["variant"], 10)
        self.assertTrue(result["truncated"])
        self.assertEqual(len(result["diagnostics"]), 1)
        with patch.object(evidence, "LEDGER_LIMIT", 120):
            result = evidence.prior_attempts(self.root, "src/Func")
        self.assertTrue(result["truncated"])
        self.assertIsNone(result["ledger"]["sha256"])
        self.assertEqual(result["records"][-1]["record"]["variant"], 109)

    def test_reference_limit_and_no_substring_match(self):
        self.write("src/Other.cpp", "OtherFunc();\nFunc();\nFunc();\n")
        result = evidence.source_references(self.root, {"Func"}, limit=1)
        self.assertTrue(result["truncated"])
        self.assertNotIn("OtherFunc", result["records"][0]["text"])

    def test_cli_never_overwrites_inputs_or_evidence(self):
        before = (self.root / self.unit["target_path"]).read_bytes()
        output = self.root / "build/factory/evidence.json"
        argv = ["--root", str(self.root), "--unit", "src/Func", "--output", str(output)]
        self.assertEqual(evidence.main(argv), 0)
        self.assertTrue(output.is_file())
        self.assertEqual(evidence.main(argv), 2)
        self.assertEqual((self.root / self.unit["target_path"]).read_bytes(), before)
        self.assertEqual(evidence.main(argv[:-1] + [str(self.root / self.unit["target_path"])]), 2)


if __name__ == "__main__":
    unittest.main()
