import copy
import unittest

from work_batch import delta


class BatchDeltaTests(unittest.TestCase):
    def setUp(self):
        self.before = dict(arm9=dict(total_code=100, total_data=50, total_functions=10,
                                    matched_code=20, matched_data=10, matched_functions=2),
                           arm7=dict(payload_bytes=200, source_code_bytes=10,
                                     binary_fallback_bytes=190))

    def test_matching_gains(self):
        after = copy.deepcopy(self.before)
        after['arm9']['matched_code'] += 4
        after['arm7']['source_code_bytes'] += 8
        after['arm7']['binary_fallback_bytes'] -= 8
        changes = delta(self.before, after)
        self.assertEqual(changes['arm9']['matched_code'], 4)
        self.assertEqual(changes['arm7']['binary_fallback_bytes'], -8)

    def test_denominator_change_rejected(self):
        for cpu, key in [('arm9', 'total_code'), ('arm9', 'total_data'),
                         ('arm9', 'total_functions'), ('arm7', 'payload_bytes')]:
            after = copy.deepcopy(self.before)
            after[cpu][key] += 1
            with self.assertRaises(ValueError):
                delta(self.before, after)

    def test_regression_rejected(self):
        for cpu, key, change in [('arm9', 'matched_code', -1),
                                  ('arm7', 'source_code_bytes', -1),
                                  ('arm7', 'binary_fallback_bytes', 1)]:
            after = copy.deepcopy(self.before)
            after[cpu][key] += change
            with self.assertRaises(ValueError):
                delta(self.before, after)


if __name__ == '__main__':
    unittest.main()
