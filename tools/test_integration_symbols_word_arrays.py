"""Guard typed element extents without consuming neighboring fallback storage."""
import copy
import pathlib
import tempfile
import unittest

from integration_symbols import (
    capture_symbols, install_symbols, restore_symbols, verify_symbols,
)


class InitializedArrayExtents(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.main = pathlib.Path(self.temp.name) / 'main'
        self.worker = pathlib.Path(self.temp.name) / 'worker'
        self.relative = pathlib.Path('config/usa/arm9/symbols.txt')
        self.old = 'sizes kind:data(any) addr:0x020e7c40'
        self.neighbor = 'next_table kind:data(word) addr:0x020e7c94'
        self.before = self.old + '\n' + self.neighbor + '\n'
        for root in (self.main, self.worker):
            path = root / self.relative
            path.parent.mkdir(parents=True)
            path.write_text(self.before)
        self.manifest = {
            'data': [{'name': 'sizes', 'address': '020e7c40',
                      'size': 40, 'section': '.rodata'}],
            'symbol_refinements': [{
                'path': self.relative.as_posix(), 'before': self.old,
                'after': 'sizes kind:data(word[10]) addr:0x020e7c40',
            }],
        }
        self.freeze_worker()

    def freeze_worker(self):
        new = self.manifest['symbol_refinements'][0]['after']
        (self.worker / self.relative).write_text(new + '\n' + self.neighbor + '\n')

    def capture(self):
        return capture_symbols(self.main, self.worker, 'main', self.manifest)

    def test_word_count_is_elements_and_transaction_restores_exact_preimage(self):
        snapshot = self.capture()
        install_symbols(self.main, snapshot)
        verify_symbols(self.main, snapshot)
        self.assertEqual((self.main / self.relative).read_text(),
                         self.manifest['symbol_refinements'][0]['after'] +
                         '\n' + self.neighbor + '\n')
        # The following symbol and 44-byte remainder have no invented labels.
        self.assertEqual(len((self.main / self.relative).read_text().splitlines()), 2)
        restore_symbols(self.main, snapshot)
        self.assertEqual((self.main / self.relative).read_text(), self.before)

    def test_existing_byte_array_refinement_remains_supported(self):
        self.manifest['symbol_refinements'][0]['after'] = (
            'sizes kind:data(byte[40]) addr:0x020e7c40')
        self.freeze_worker()
        self.assertIsNotNone(self.capture())

    def test_reject_element_count_mistaken_for_bytes(self):
        self.manifest['data'][0]['size'] = 10
        with self.assertRaises(ValueError):
            self.capture()

    def test_reject_extent_including_unowned_tail(self):
        self.manifest['symbol_refinements'][0]['after'] = (
            'sizes kind:data(word[21]) addr:0x020e7c40')
        self.freeze_worker()
        with self.assertRaises(ValueError):
            self.capture()

    def test_reject_unaligned_word_address(self):
        self.old = self.old.replace('020e7c40', '020e7c42')
        (self.main / self.relative).write_text(self.old + '\n' + self.neighbor + '\n')
        row = self.manifest['symbol_refinements'][0]
        row['before'] = self.old
        row['after'] = row['after'].replace('020e7c40', '020e7c42')
        self.manifest['data'][0]['address'] = '020e7c42'
        self.freeze_worker()
        with self.assertRaises(ValueError):
            self.capture()

    def test_reject_unsupported_type_and_zero_extent(self):
        for kind in ('halfword[20]', 'word[0]', 'word[-1]', 'word[0xA]', 'float[10]'):
            with self.subTest(kind=kind):
                self.manifest['symbol_refinements'][0]['after'] = (
                    f'sizes kind:data({kind}) addr:0x020e7c40')
                self.freeze_worker()
                with self.assertRaises(ValueError):
                    self.capture()

    def test_reject_duplicate_original_symbol(self):
        (self.main / self.relative).write_text(self.before + self.old + '\n')
        with self.assertRaises(ValueError):
            self.capture()

    def test_reject_same_name_with_different_address_or_prefix(self):
        for duplicate in (self.old + '0',
                          'sizes kind:data(any) addr:0x020e7c80',
                          '  sizes kind:data(any) addr:0x020e7c80'):
            with self.subTest(duplicate=duplicate):
                (self.main / self.relative).write_text(self.before + duplicate + '\n')
                with self.assertRaises(ValueError):
                    self.capture()

    def test_preserve_comment_and_other_symbol_prefix_collisions(self):
        suffix = '# Reference: ' + self.old + '\n'
        suffix += 'sizes_extra kind:data(any) addr:0x020e7c80\n'
        (self.main / self.relative).write_text(self.before + suffix)
        snapshot = self.capture()
        self.assertTrue(snapshot['after'].decode().endswith(suffix))
        self.assertEqual(snapshot['after'].decode().count(self.old), 1)

    def test_preserve_crlf_line_endings(self):
        (self.main / self.relative).write_bytes(self.before.replace('\n', '\r\n').encode())
        snapshot = self.capture()
        expected = self.manifest['symbol_refinements'][0]['after'] + '\r\n'
        expected += self.neighbor + '\r\n'
        self.assertEqual(snapshot['after'], expected.encode())

    def test_reject_duplicate_refinement(self):
        self.manifest['symbol_refinements'].append(
            copy.deepcopy(self.manifest['symbol_refinements'][0]))
        with self.assertRaises(ValueError):
            self.capture()

    def test_reject_stale_worker_map(self):
        (self.worker / self.relative).write_text(self.before)
        with self.assertRaises(ValueError):
            self.capture()

    def test_reject_wrong_section_or_unselected_owner(self):
        for section in ('.bss', '.text'):
            with self.subTest(section=section):
                self.manifest['data'][0]['section'] = section
                with self.assertRaises(ValueError):
                    self.capture()
        self.manifest['data'] = []
        with self.assertRaises(ValueError):
            self.capture()


if __name__ == '__main__':
    unittest.main()
