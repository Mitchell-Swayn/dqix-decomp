import hashlib
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from integration_source_refinements import capture_refinements,install_refinement,restore_refinements,verify_refinements


class RefinementTests(unittest.TestCase):
    def setUp(self):
        temporary=tempfile.TemporaryDirectory();self.addCleanup(temporary.cleanup)
        self.main=Path(temporary.name)/'main';self.worker=Path(temporary.name)/'worker'
        for root in (self.main,self.worker):(root/'src').mkdir(parents=True)
        self.before=b'extern "C" unsigned Getter(void*);\nint Caller(){return Getter(0);}\n'
        self.after=self.before.replace(b'unsigned Getter',b'unsigned char Getter')
        (self.main/'src/Caller.cpp').write_bytes(self.before);(self.worker/'src/Caller.cpp').write_bytes(self.after)
        owner=b'extern "C" unsigned char Getter(void* p) {return 0;}\n';(self.main/'src/Owner.cpp').write_bytes(owner)
        self.change={'before':'extern "C" unsigned Getter(void*);','after':'extern "C" unsigned char Getter(void*);',
                     'canonical_source':'src/Owner.cpp','canonical_source_sha256':hashlib.sha256(owner).hexdigest()}
        self.entry={'source':'src/Caller.cpp','before_sha256':hashlib.sha256(self.before).hexdigest(),
                    'after_sha256':hashlib.sha256(self.after).hexdigest(),'changes':[self.change]}
        self.manifest={'functions':[{'source':'src/Caller.cpp'}],'source_refinements':[self.entry]}

    def test_install_owner_verification_and_partial_write_rollback(self):
        snapshot=capture_refinements(self.main,self.worker,self.manifest)
        write=Path.write_bytes
        def partial(path,content):write(path,content[:3]);raise OSError('partial write')
        with patch.object(Path,'write_bytes',partial):
            with self.assertRaises(OSError):install_refinement(self.main,'src/Caller.cpp',snapshot['sources']['src/Caller.cpp'])
        restore_refinements(self.main,snapshot)
        self.assertEqual((self.main/'src/Caller.cpp').read_bytes(),self.before)
        install_refinement(self.main,'src/Caller.cpp',snapshot['sources']['src/Caller.cpp']);verify_refinements(self.main,snapshot)
        (self.main/'src/Owner.cpp').write_text('changed owner')
        with self.assertRaisesRegex(ValueError,'owning source changed'):verify_refinements(self.main,snapshot)
        restore_refinements(self.main,snapshot)
        self.assertEqual((self.main/'src/Caller.cpp').read_bytes(),self.before)

    def test_body_parameter_and_hash_changes_fail_closed(self):
        self.change['canonical_source_sha256']='0'*64
        with self.assertRaisesRegex(ValueError,'owner hash'):capture_refinements(self.main,self.worker,self.manifest)
        self.change['canonical_source_sha256']=hashlib.sha256((self.main/'src/Owner.cpp').read_bytes()).hexdigest()
        changed=self.after.replace(b'Getter(0)',b'Getter((void*)4)');(self.worker/'src/Caller.cpp').write_bytes(changed)
        self.entry['after_sha256']=hashlib.sha256(changed).hexdigest()
        with self.assertRaisesRegex(ValueError,'more than explicit'):capture_refinements(self.main,self.worker,self.manifest)
        self.change['after']='extern "C" unsigned char Getter(int);'
        with self.assertRaisesRegex(ValueError,'parameters'):capture_refinements(self.main,self.worker,self.manifest)

    def test_wrong_owner_return_and_mixed_policy_refused(self):
        self.change['after']='extern "C" int Getter(void*);'
        with self.assertRaisesRegex(ValueError,'owning definition'):capture_refinements(self.main,self.worker,self.manifest)
        self.manifest['function_renames']=[{'old':'Old','new':'New'}]
        with self.assertRaisesRegex(ValueError,'other policy'):capture_refinements(self.main,self.worker,self.manifest)


if __name__=='__main__':unittest.main()
