"""Coverage partitions must reconcile; unknown/fallback coverage stays visible."""
import copy
from pathlib import Path
import tempfile
import unittest

from progress_treemap import arm7_tiles, arm9_units


class TreemapTests(unittest.TestCase):
    def arm7(self):
        return dict(units=[dict(name='test', source='test.c', size=20,
                               code_bytes=12, literal_pool_bytes=4, data_bytes=4,
                               bss=dict(size=8)),
                           dict(name='asm', source='asm.c', size=4,
                                reviewed_assembly_bytes=4)],
                    source_code_bytes=12, source_literal_pool_bytes=4,
                    source_data_bytes=4, reviewed_assembly_bytes=4,
                    source_bss_bytes=8, binary_fallback_bytes=76, payload_bytes=100,
                    total_bss_bytes=32, unreconstructed_bss_bytes=24)

    def test_arm7_categories_and_denominators(self):
        tiles = arm7_tiles(self.arm7())
        self.assertEqual(sum(t['size'] for t in tiles if t['view'] == 'payload'), 100)
        self.assertEqual(sum(t['size'] for t in tiles if t['view'] == 'bss'), 32)
        self.assertEqual({t['kind'] for t in tiles},
                         {'instructions', 'literals', 'data', 'assembly', 'bss', 'fallback'})

    def test_arm7_rejects_hidden_bytes_and_counter_changes(self):
        for key in ('source_code_bytes', 'source_literal_pool_bytes', 'source_data_bytes',
                    'reviewed_assembly_bytes', 'source_bss_bytes', 'payload_bytes',
                    'total_bss_bytes', 'binary_fallback_bytes'):
            report = self.arm7()
            report[key] += 1
            with self.subTest(key=key), self.assertRaises(ValueError):
                arm7_tiles(report)
        report = self.arm7()
        report['units'][0]['size'] += 1
        with self.assertRaises(ValueError):
            arm7_tiles(report)

    def fixture(self, root):
        config = root / 'config/usa/arm9'
        for module in ('', 'itcm', 'dtcm'):
            path = config / module / 'delinks.txt'
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text('src/Test.cpp:\n' if not module else '')
        measures = dict(total_code='32', matched_code='12', total_data='8',
                        matched_data='0', total_functions=2, matched_functions=1)
        report = dict(measures=measures, units=[dict(name='src/Test', measures=dict(measures),
                     metadata=dict(source_path='src/Test.cpp'))])
        assembly = dict(units=[dict(name='src/Test', category='source_units_with_assembly_syntax')])
        return report, assembly

    def test_arm9_ownership_and_assembly_label(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            report, assembly = self.fixture(root)
            units = arm9_units(root, report, assembly)
            self.assertEqual(units[0]['module'], 'main')
            self.assertEqual(units[0]['category'], 'source_units_with_assembly_syntax')
            self.assertEqual(units[0]['measures']['total_code'], 32)

    def test_arm9_rejects_reduced_denominator_and_overcredit(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            report, assembly = self.fixture(root)
            bad = copy.deepcopy(report)
            bad['measures']['total_code'] = '31'
            with self.assertRaises(ValueError):
                arm9_units(root, bad, assembly)
            report['units'][0]['measures']['matched_code'] = '33'
            with self.assertRaises(ValueError):
                arm9_units(root, report, assembly)

    def test_arm9_rejects_ambiguous_ownership(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            report, assembly = self.fixture(root)
            (root / 'config/usa/arm9/itcm/delinks.txt').write_text('src/Test.cpp:\n')
            with self.assertRaises(ValueError):
                arm9_units(root, report, assembly)


if __name__ == '__main__':
    unittest.main()
