import unittest,tempfile,json,hashlib
from pathlib import Path
from integration_failure_evidence import capture
class FailureEvidence(unittest.TestCase):
 def test_nonselected_fallback_config_and_candidate_are_independent_before_restore(self):
  with tempfile.TemporaryDirectory() as d:
   root=Path(d);folder=root/'build/receipt';folder.mkdir(parents=True)
   config=dict(units=[dict(name='main_11',target_path='config/usa/arm9/../../../build/original.o',metadata=dict(auto_generated=True)),dict(name='src/Candidate',target_path='build/target.o',base_path='build/candidate.o',metadata=dict(source_path='src/Candidate.cpp'))])
   (root/'objdiff.json').write_text(json.dumps(config));(root/'build.ninja').write_text('failure configuration')
   for relative,b in [('build/original.o',b'fallback-with-object-prefix'),('build/target.o',b'original'),('build/candidate.o',b'candidate')]: (root/relative).write_bytes(b)
   (root/'build/usa/build').mkdir(parents=True);(root/'build/usa/build/arm9_ov021.bin').write_bytes(b'failed unselected module bytes')
   evidence=capture(root,folder);self.assertEqual((folder/'failure-evidence/files/build/usa/build/arm9_ov021.bin').read_bytes(),b'failed unselected module bytes');saved=folder/'failure-evidence/files/build/original.o'
   self.assertEqual(saved.read_bytes(),b'fallback-with-object-prefix');self.assertNotEqual(saved.stat().st_ino,(root/'build/original.o').stat().st_ino);self.assertEqual(saved.stat().st_nlink,1)
   (root/'build/original.o').write_bytes(b'rebuilt');(root/'objdiff.json').write_text('restored')
   self.assertEqual(saved.read_bytes(),b'fallback-with-object-prefix');self.assertEqual(json.loads((folder/'failure-evidence/files/objdiff.json').read_text()),config)
   self.assertEqual(evidence['files']['build/original.o']['sha256'],hashlib.sha256(saved.read_bytes()).hexdigest());self.assertEqual(evidence['credit'],0)
 def test_escaping_object_path_fails_before_external_copy(self):
  with tempfile.TemporaryDirectory() as d:
   root=Path(d);folder=root/'build/receipt';folder.mkdir(parents=True);(root/'objdiff.json').write_text(json.dumps(dict(units=[dict(name='bad',target_path='../private.o')])))
   with self.assertRaisesRegex(ValueError,'escapes project'):capture(root,folder)
if __name__=='__main__':unittest.main()
