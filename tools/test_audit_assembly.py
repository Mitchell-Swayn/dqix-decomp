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

    def runtime_root(self, directory, with_sdk=True):
        root = Path(directory)
        (root / 'src/RuntimeSupport').mkdir(parents=True)
        (root / 'build/usa/build').mkdir(parents=True)
        (root / 'config/usa/arm9').mkdir(parents=True)
        original = bytes(range(32))
        (root / 'build/usa/build/arm9.bin').write_bytes(original)
        rows, units = [], []
        for name, size, start, text, extra in (
                ('_fmul', 16, 0, '// Compiler runtime support\nextern "C" asm void _fmul() { bx lr }\n', {}),
                ('Fill', 16, 16, '// SDK support (community reconstruction)\nextern "C" asm void Fill() { bx lr }\n',
                 {'evidence_class': 'sdk_reconstruction'})):
            if name == 'Fill' and not with_sdk:
                continue
            source = root / f'src/RuntimeSupport/{name}.cpp'
            source.write_text(text)
            evidence = {'library': 'a.a'} if not extra else {'origin': 'community_reconstruction', 'library': None}
            rows.append(dict(module='arm9/main', address=hex(0x02000000 + start), name=name, size=size,
                             source=f'src/RuntimeSupport/{name}.cpp', classification='runtime_assembly',
                             source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),
                             original_sha256=hashlib.sha256(original[start:start + size]).hexdigest(),
                             evidence=evidence, **extra))
            units.append({'name': f'src/RuntimeSupport/{name}', 'metadata': {'auto_generated': False, 'source_path': f'src/RuntimeSupport/{name}.cpp'},
                          'measures': {'total_code': size, 'matched_code': size, 'total_functions': 1, 'matched_functions': 1},
                          'functions': [{'name': name, 'size': size, 'fuzzy_match_percent': 100}]})
        (root / 'config/usa/arm9/runtime_support.json').write_text(json.dumps(dict(schema_version=1, functions=rows)))
        total = sum(r['size'] for r in rows)
        report = root / 'report.json'
        report.write_text(json.dumps({'measures': {'total_code': total, 'matched_code': total, 'total_functions': len(rows),
                                                   'matched_functions': len(rows)}, 'units': units}))
        return root, report

    def test_runtime_audit_separates_sdk_from_compiler_and_gives_no_c_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root, report = self.runtime_root(directory)
            result = audit(root, report)
            summary = result['runtime_support']
            self.assertEqual((summary['compiler_runtime_functions'], summary['compiler_runtime_bytes']), (1, 16))
            self.assertEqual((summary['sdk_reconstruction_functions'], summary['sdk_reconstruction_bytes']), (1, 16))
            self.assertEqual((summary['assembly_functions'], summary['assembly_bytes']), (2, 32))
            self.assertEqual(summary['c_instruction_credit'], 0)
            reviews = {r['symbol']: r for r in result['runtime_reviews']}
            self.assertEqual(reviews['Fill']['evidence_class'], 'sdk_reconstruction')
            self.assertEqual(reviews['Fill']['evidence_origin'], 'community_reconstruction')
            self.assertIn('not a vendor original', reviews['Fill']['review_status'])
            self.assertEqual(reviews['_fmul']['evidence_class'], 'compiler_runtime')
            self.assertEqual({r['c_instruction_credit'] for r in reviews.values()}, {0})
            self.assertTrue(all(site['review_status'].startswith('explicitly reviewed') for entry in result['sites'] for site in entry['sites']))

    def test_existing_compiler_only_policy_audit_is_unchanged(self):
        with tempfile.TemporaryDirectory() as directory:
            root, report = self.runtime_root(directory, with_sdk=False)
            summary = audit(root, report)['runtime_support']
            self.assertEqual((summary['assembly_functions'], summary['assembly_bytes']), (1, 16))
            self.assertEqual(summary['sdk_reconstruction_functions'], 0)

    def test_sdk_helper_source_or_bytes_drift_is_refused(self):
        with tempfile.TemporaryDirectory() as directory:
            root, report = self.runtime_root(directory)
            (root / 'src/RuntimeSupport/Fill.cpp').write_text('// edited\n')
            with self.assertRaisesRegex(ValueError, 'Accepted runtime assembly'):
                audit(root, report)


if __name__ == "__main__":
    unittest.main()
