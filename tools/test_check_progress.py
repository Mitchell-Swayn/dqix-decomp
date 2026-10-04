#!/usr/bin/env python3
import unittest

from check_progress import compare


class ProgressTests(unittest.TestCase):
    def test_denominator_reduction_cannot_hide_behind_higher_percentage(self):
        before = {"measures": {"total_code": "100", "matched_code": "50"}}
        after = {"measures": {"total_code": "60", "matched_code": "50"}}
        self.assertEqual(compare(before, after)["regressions"], ["total_code decreased from 100 to 60"])

    def test_actual_new_coverage_is_recorded(self):
        before = {"measures": {"total_code": "100", "matched_code": "50"}}
        after = {"measures": {"total_code": "100", "matched_code": "70"}}
        result = compare(before, after)
        self.assertEqual(result["regressions"], [])
        self.assertEqual(result["delta"]["matched_code"], 20)

    def test_impossible_matched_total_is_rejected(self):
        result = compare({"measures": {}}, {"measures": {"matched_functions": 2, "total_functions": 1}})
        self.assertIn("Matched functions exceeds its total", result["regressions"])


if __name__ == "__main__":
    unittest.main()
