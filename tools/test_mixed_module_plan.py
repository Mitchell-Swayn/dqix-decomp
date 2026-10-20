import copy
import unittest
from mixed_module_plan import source_only_plan, unique_captures


def proposal():
    rows=[dict(module='ov%03d'%(i%7),name='Function%d'%i,source='src/Util/Function%d.cpp'%i,address=hex(0x2150000+(i//7)*32),size=16) for i in range(49)]
    return dict(functions=rows,source_hashes={r['source']:'a'*64 for r in rows})


class MixedPlanningTests(unittest.TestCase):
    def test_49_functions_seven_modules_keep_overlapping_load_addresses(self):
        plan=source_only_plan(proposal())
        self.assertEqual(len(plan['modules']),7)
        self.assertEqual(plan['expected_functions'],49)
        self.assertEqual(plan['expected_code_bytes'],49*16)
        self.assertFalse(plan['acceptance'])
        self.assertEqual(sum(len(x['functions']) for x in plan['modules'].values()),49)

    def test_refuse_identity_source_symbol_and_extent_collisions(self):
        for field in ('name','source','address'):
            d=proposal();other=7 if field=='address' else 1
            d['functions'][other][field]=d['functions'][0][field]
            with self.assertRaises(ValueError):source_only_plan(d)
        d=proposal();d['functions'][7]['address']=hex(0x2150008)
        with self.assertRaises(ValueError):source_only_plan(d)

    def test_refuse_unpinned_or_invalid_module_and_non_source_transactions(self):
        for mutate in (lambda d:d.pop('source_hashes'),lambda d:d['functions'][0].update(module='arm9/main'),lambda d:d.update(data=[{}]),lambda d:d.update(runtime_append={'functions':[{}]}),lambda d:d['functions'][0].update(source='src/../outside.cpp')):
            d=proposal();mutate(d)
            with self.assertRaises((ValueError,TypeError)):source_only_plan(d)

    def test_snapshot_conflicts_cannot_silently_overwrite_another_module(self):
        first=dict(path='config/usa/compiler_profiles.json',before=b'baseline',after=b'module-a')
        second=dict(first,after=b'module-b')
        with self.assertRaisesRegex(ValueError,'combined capture'):unique_captures([[first],[second]])
        with self.assertRaisesRegex(ValueError,'combined capture'):unique_captures([[first],[dict(first,before=b'other')]])
        self.assertEqual(unique_captures([[first],[copy.deepcopy(first)]]),[first])
        self.assertEqual(first['after'],b'module-a')


if __name__=='__main__':unittest.main()
