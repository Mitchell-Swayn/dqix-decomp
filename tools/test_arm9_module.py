import copy
import unittest
from pathlib import Path
from arm9_module import delinks_path, manifest_rows, module_section, verify_measures, verify_manifest_units
from audit_link_layout import audit
from integrate_batch import parse_delinks
from elf_function_bytes import read_functions


class ModuleTests(unittest.TestCase):
    def test_all_configured_modules_have_unique_routes(self):
        modules = ['main', 'itcm', 'dtcm'] + [f'ov{i:03d}' for i in range(35)]
        self.assertEqual(len({delinks_path(m) for m in modules}), 38)
        self.assertEqual(module_section('main'), 'ARM9')
        self.assertEqual(str(delinks_path('ov004')), 'config/usa/arm9/overlays/ov004/delinks.txt')
        for name in ('ov035', 'ov-01', '../main', 'arm7', 'OV000', 'ov0'):
            with self.assertRaises(ValueError):
                delinks_path(name)

    def test_legacy_main_and_data_only_manifests(self):
        row = {'name': 'fn', 'source': 'src/x.cpp', 'size': 4}
        self.assertEqual(manifest_rows({'functions': [row]}, 'main'), ([row], [], ['src/x.cpp']))
        self.assertEqual(manifest_rows({'functions': [], 'data': [row]}, 'dtcm'), ([], [row], ['src/x.cpp']))
        with self.assertRaises(ValueError):
            manifest_rows({'functions': [{**row, 'module': 'ov001'}]}, 'ov000')
        with self.assertRaises(ValueError):
            manifest_rows({'functions': []}, 'main')
        with self.assertRaises(ValueError):
            manifest_rows({'functions': [row, row]}, 'main')

    def test_zero_length_overlay_sections_allocate_no_ranges(self):
        text = '    .text start:0x100 end:0x110 kind:code\n    .bss start:0x110 end:0x110 kind:bss\n'
        with self.assertRaises(ValueError):
            parse_delinks(text)
        parse_delinks(text, allow_empty_sections=True)
        for start, end in ((0x110, 0x114), (0x110, 0x110), (0x114, 0x110)):
            with self.assertRaises(ValueError):
                parse_delinks(text + f'src/a.cpp:\n    complete\n    .bss start:0x{start:x} end:0x{end:x}\n',
                              allow_empty_sections=True)

    def test_comparison_units_cover_only_complete_declared_sources(self):
        manifest = {'functions': [{'source': 'src/a.cpp'}], 'units': ['src/a']}
        config = {'units': [{'name': 'src/a', 'metadata': {'complete': True, 'source_path': 'src/a.cpp'}}]}
        verify_manifest_units(manifest, config)
        for bad in ({'units': []}, {'units': ['src/a', 'src/a']},
                    {'functions': [{'source': 'src/b.cpp'}]}):
            with self.assertRaises(ValueError):
                verify_manifest_units({**manifest, **bad}, config)
        config['units'][0]['metadata']['complete'] = False
        with self.assertRaises(ValueError):
            verify_manifest_units(manifest, config)

    def test_exact_deltas_and_fixed_denominators(self):
        before = dict(total_functions=10, total_code='100', total_data='60', matched_functions=1,
                      matched_code='4', matched_data='8')
        after = {**before, 'matched_functions': 2, 'matched_code': '12', 'matched_data': '16'}
        verify_measures(before, after, [{'size': 8}], [{'size': 8}])
        for key in before:
            changed = copy.deepcopy(after)
            changed[key] = int(changed[key]) + 1
            with self.assertRaisesRegex(ValueError, 'denominator|delta'):
                verify_measures(before, changed, [{'size': 8}], [{'size': 8}])

    @unittest.skipUnless(Path('build/usa/arm9.o').exists(), 'local linked ELF unavailable')
    def test_real_linked_main_itcm_overlay_and_wrong_module(self):
        for module in ('main', 'itcm', 'ov000'):
            symbols = read_functions('build/usa/arm9.o', metadata_only=True,
                                     section_filter=module_section(module))
            self.assertTrue(symbols, module)
            name, symbol = next(iter(symbols.items()))
            rows = [{'name': name, 'address': f"{symbol['address']:08x}", 'size': symbol['size']}]
            self.assertTrue(audit('build/usa/arm9.o', rows, module)['match'])
            other = 'itcm' if module == 'main' else 'main'
            self.assertFalse(audit('build/usa/arm9.o', rows, other)['match'])
        with self.assertRaisesRegex(ValueError, 'Missing ELF module section'):
            read_functions('build/usa/arm9.o', metadata_only=True, section_filter='OV999')


if __name__ == '__main__':
    unittest.main()
