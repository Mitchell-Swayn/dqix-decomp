#!/usr/bin/env python3
"""Guard assembly audit comment handling, transitive includes and reconciliation."""
import json
from pathlib import Path
import tempfile
import unittest

from audit_assembly import audit, without_comments


class AssemblyAuditTests(unittest.TestCase):
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
