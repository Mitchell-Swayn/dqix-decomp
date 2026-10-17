import copy
import hashlib
import struct
import unittest

from audit_arm7_partition import build, partition


class PartitionTests(unittest.TestCase):
    def test_unknown_gaps_and_agreeing_overlap_count_once(self):
        rows=partition(0,12,[{'start':2,'end':6,'classification':'instruction','evidence':'caller'},
                             {'start':4,'end':8,'classification':'instruction','evidence':'symbol'}])
        self.assertEqual(sum(row['size'] for row in rows),12)
        self.assertEqual(sum(row['size'] for row in rows if row['classification']=='instruction'),6)
        self.assertEqual(rows[2]['evidence'],['caller','symbol'])

    def test_conflicts_and_out_of_domain_fail_closed(self):
        claims=[{'start':0,'end':8,'classification':'instruction','evidence':'branch'},
                {'start':4,'end':8,'classification':'literal_pool','evidence':'ldr'}]
        with self.assertRaises(ValueError):partition(0,12,claims)
        for start,end in ((-1,2),(3,3),(8,13)):
            with self.assertRaises(ValueError):partition(0,12,[dict(start=start,end=end,classification='instruction',evidence='test')])

    def fixture(self):
        payload=bytearray(76)
        struct.pack_into('<6I',payload,0,0x1040,0x104c,0x1018,0x1018,0x1018,0)
        struct.pack_into('<3I',payload,64,0x2000,40,8)
        config={'startup_size':24,'autoload_parameters_offset':0,'autoload_table_offset':64,
                'autoloads':[dict(name='test',payload_offset=24,runtime_address=0x2000,size=40,bss_size=8)],
                'units':[dict(name='mixed',payload_offset=24,runtime_address=0x2000,size=16,
                              autoload='test',code_bytes=12,literal_pool_bytes=4,symbols={'entry':0x2000}),
                         dict(name='code',payload_offset=40,runtime_address=0x2010,size=4,
                              autoload='test',code_bytes=4,literal_pool_bytes=0,symbols={'code':0x2010},
                              bss=dict(runtime_address=0x2028,size=4,symbols={'state':0x2028}))]}
        baseline={'size':76,'load_address':0x1000,'source_rom_sha1':'0'*40,
                  'payload_sha1':hashlib.sha1(payload).hexdigest()}
        inventory={'schema_version':1,'source_rom_sha1':'0'*40,'payload_sha1':baseline['payload_sha1'],
                   'scopes':[dict(name='startup',autoload=None,payload_offset='0x0',runtime_address='0x1000',size='0x18',
                                  totals=dict(instruction=0,literal_pool=0,initialized_data=24),
                                  ranges=[dict(payload_offset='0x0',size='0x18',classification='initialized_data',evidence='copy params')])]}
        return bytes(payload),baseline,config,inventory

    def test_mixed_totals_do_not_invent_literal_positions_or_function_denominator(self):
        result=build(*self.fixture())
        self.assertEqual(result['payload_totals'],{'initialized_data':36,'instruction':4,'unknown':36})
        self.assertEqual(result['mixed_unit_constraints'][0]['aggregate_classes']['literal_pool'],4)
        self.assertEqual(sum(row['size'] for row in result['payload_intervals']),76)
        self.assertEqual(result['instruction_byte_bounds']['minimum'],16)
        self.assertEqual(result['instruction_byte_bounds']['maximum'],36)
        self.assertEqual(result['bss_size'],8);self.assertEqual(result['bss_source_defined'],4)
        self.assertIsNone(result['function_denominator'])
        self.assertEqual(result['source_coverage_credit'],0)
        self.assertTrue(all('runtime_start' in row and 'original_sha256' in row for row in result['payload_intervals']))

    def test_original_descriptor_and_payload_hash_tampering_rejected(self):
        payload,baseline,config,inventory=self.fixture()
        with self.assertRaises(ValueError):build(payload[:-1],baseline,config,inventory)
        altered=bytearray(payload);altered[64]^=1
        baseline=copy.deepcopy(baseline);baseline['payload_sha1']=hashlib.sha1(altered).hexdigest()
        with self.assertRaisesRegex(ValueError,'descriptor'):build(bytes(altered),baseline,config,inventory)

    def test_source_class_overlapping_independent_pool_is_rejected(self):
        payload,baseline,config,inventory=self.fixture()
        inventory['scopes'].append(dict(name='literal',autoload='test',payload_offset='0x28',runtime_address='0x2010',size='0x4',
             totals=dict(instruction=0,literal_pool=4,initialized_data=0),
             ranges=[dict(payload_offset='0x28',size='0x4',classification='literal_pool',evidence='validated ldr')]))
        with self.assertRaisesRegex(ValueError,'Conflicting'):build(payload,baseline,config,inventory)


if __name__=='__main__':unittest.main()
