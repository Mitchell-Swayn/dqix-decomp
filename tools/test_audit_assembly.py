#!/usr/bin/env python3
"""Guard assembly audit comment handling, transitive includes and reconciliation."""
import json
import hashlib
from pathlib import Path
import tempfile
import unittest

from audit_assembly import audit, reviewed_exceptions, without_comments


class AssemblyAuditTests(unittest.TestCase):
    def test_review_rejects_source_byte_and_match_changes(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root / 'status.cpp'
            source.write_text('__asm("mrs r0, cpsr");\n')
            binary = root / 'module.bin'
            binary.write_bytes(b'\0\0\x0f\xe1')
            manifest = root / 'config/usa/arm9/assembly_exceptions.json'
            manifest.parent.mkdir(parents=True)
            entry = dict(unit='status', source='status.cpp', module_path='module.bin',
                source_sha256=hashlib.sha256(source.read_text().encode()).hexdigest(),
                original_bytes_sha256=hashlib.sha256(binary.read_bytes()).hexdigest(),
                module_base='0x2000000', start='0x2000000', end='0x2000004',
                reviewed_assembly_routine_bytes=4, inline_assembly_instruction_bytes=4,
                c_instruction_credit=0,
                routines=[dict(symbol='status', start='0x2000000', end='0x2000004')])
            manifest.write_text(json.dumps(dict(schema_version=1, exceptions=[entry])))
            function = dict(name='status', size=4, fuzzy_match_percent=100)
            report = dict(units=[dict(name='status', measures=dict(total_code=4, matched_code=4), functions=[function])])
            self.assertEqual(len(reviewed_exceptions(root, report)), 1)
            source.write_text('__asm("msr cpsr_c, r0");\n')
            with self.assertRaisesRegex(ValueError, 'source changed'):
                reviewed_exceptions(root, report)
            source.write_text('__asm("mrs r0, cpsr");\n')
            binary.write_bytes(b'\0' * 4)
            with self.assertRaisesRegex(ValueError, 'bytes differ'):
                reviewed_exceptions(root, report)
            binary.write_bytes(b'\0\0\x0f\xe1')
            function['fuzzy_match_percent'] = 99
            with self.assertRaisesRegex(ValueError, 'routine mismatch'):
                reviewed_exceptions(root, report)

    def test_comments_do_not_create_sites(self):
        self.assertNotIn("asm", without_comments("// asm\n/* __asm */\nint f();"))
        self.assertEqual(without_comments('"// literal"'), '"// literal"')

    def test_transitive_cycle_and_counter_partition(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "src").mkdir()
            (root / "include").mkdir()
            (root / "src/a.cpp").write_text('#include "a.h"\nint f();')
            (root / "include/a.h").write_text('#include "b.h"\n')
            (root / "include/b.h").write_text('#include "a.h"\n__asm("mrs r0, cpsr");')
            (root / "src/b.cpp").write_text('// asm in comment\nint f() { return 1; }')
            report = root / "report.json"
            report.write_text(json.dumps({"measures": {"total_code": 12, "matched_code": 8},
                "units": [{"name": name, "measures": {"total_code": 4, "matched_code": matched}}
                          for name, matched in (("src/a", 4), ("src/b", 4), ("main_0", 0))]}))
            result = audit(root, report)
            self.assertEqual(result["units"][0]["assembly_sources"], ["include/b.h"])
            self.assertEqual(result["groups"]["source_units_with_assembly_syntax"]["matched_code"], 4)
            self.assertEqual(result["groups"]["source_units_without_detected_assembly"]["matched_code"], 4)
            self.assertEqual(result["groups"]["original_binary_units"]["total_code"], 4)
            data = json.loads(report.read_text())
            data["measures"]["total_code"] = 11
            report.write_text(json.dumps(data))
            with self.assertRaises(ValueError):
                audit(root, report)


if __name__ == "__main__":
    unittest.main()
