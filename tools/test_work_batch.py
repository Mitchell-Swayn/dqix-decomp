import copy
import unittest

from work_batch import accounting, delta


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

    def test_runtime_assembly_gain_is_not_c_gain(self):
        after = copy.deepcopy(self.before)
        after['arm9']['matched_code'] += 188
        after['arm9']['matched_functions'] += 1
        changes = delta(self.before, after)
        split = accounting(changes, 1, 188)
        self.assertEqual(split['binary_report_arm9'], dict(matched_functions=1, matched_code=188))
        self.assertEqual(split['runtime_assembly'], dict(functions=1, bytes=188))
        self.assertEqual(split['c_reconstruction'], dict(functions=0, code_bytes=0))
        self.assertEqual(split['c_instruction_credit_from_assembly'], 0)
        self.assertEqual(accounting(changes)['c_reconstruction'], dict(functions=1, code_bytes=188))

    def test_assembly_gain_cannot_exceed_report_gain(self):
        after = copy.deepcopy(self.before)
        after['arm9']['matched_code'] += 188
        after['arm9']['matched_functions'] += 1
        changes = delta(self.before, after)
        for functions, size in ((2, 188), (1, 189), (-1, 0)):
            with self.assertRaises(ValueError):
                accounting(changes, functions, size)


if __name__ == '__main__':
    unittest.main()
