import unittest
from summarize_executable_assets import summarize


class AssetSummaryTests(unittest.TestCase):
    def test_interpreter_association_requires_bcfg_path_and_checks_lookup(self):
        rows=[{'path':'model.chr::animation.bcfg','size':32,'sha256':'a',
               'script_structure_candidate':{'instructions':2,'opcodes':{'100':1,'999':1}}},
              {'path':'text.bin','size':32,'sha256':'b',
               'script_structure_candidate':{'instructions':2,'opcodes':{'100':2}}}]
        result=summarize({'nitrofs_equal':True,'top_level_files':2,'records':rows},'{ 0x64, &BCFGScript_Opcode_64 }')
        self.assertEqual(len(result['source_associated_bcfg']),1)
        self.assertEqual(result['source_associated_bcfg'][0]['unsupported_lookup_opcodes'],[999])
        self.assertEqual(result['script_candidate_extensions'],{'.bcfg':1,'.bin':1})
        self.assertEqual(result['source_coverage_credit'],0)

    def test_rejected_native_signature_does_not_clear_opaque_payload(self):
        row={'path':'dwc/utility.bin','size':100,'sha256':'a','native_header_candidates':[
            {'signature':'PE','offset':10,'structure':{'status':'rejected_PE_signature'}}]}
        result=summarize({'nitrofs_equal':True,'top_level_files':1,'records':[row]},'{ 0x64, &BCFGScript_Opcode_64 }')
        self.assertEqual(len(result['unresolved_payloads']),1)
        self.assertEqual(result['native_signature_statuses'],{'rejected_PE_signature':1})
        self.assertIn('unknown',result['limitations'][-1])

    def test_unverified_assets_or_missing_source_lookup_rejected(self):
        with self.assertRaises(ValueError):summarize({'nitrofs_equal':False},'')
        with self.assertRaises(ValueError):summarize({'nitrofs_equal':True},'no lookup')


if __name__=='__main__':unittest.main()
