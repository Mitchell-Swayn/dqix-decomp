import hashlib
import json
import os
import tempfile
from pathlib import Path
import unittest
from unittest.mock import patch

from integration_dependencies import (capture_dependencies, install_dependencies,
                                      restore_dependencies, verify_dependencies)


class DependenciesTests(unittest.TestCase):
    def setUp(self):
        directory = tempfile.TemporaryDirectory()
        self.addCleanup(directory.cleanup)
        self.main = Path(directory.name)/'main'
        self.worker = Path(directory.name)/'worker'
        for root in (self.main,self.worker):
            (root/'config/usa/arm9').mkdir(parents=True)
            (root/'config/usa/arm9/symbols.txt').write_text('Old kind:function(arm,size=0x4) addr:0x02000000\n')
        self.manifest = {'functions':[{'name':'New','source':'src/New.cpp','size':4,'address':'0x02000000'}]}

    def dependency(self,path,before,after):
        for root,content in ((self.main,before),(self.worker,after)):
            if content is not None:
                (root/path).parent.mkdir(parents=True,exist_ok=True)
                (root/path).write_bytes(content)
        return {'path':path,'before_sha256':hashlib.sha256(before).hexdigest() if before is not None else None,
                'after_sha256':hashlib.sha256(after).hexdigest()}

    def test_hash_mismatch_and_nonallowlisted_path_fail_before_mutation(self):
        dependency=self.dependency('config/usa/keep_symbols.txt',b'Existing\n',b'Existing\nNew\n')
        dependency['before_sha256']='0'*64
        self.manifest['dependencies']=[dependency]
        with self.assertRaisesRegex(ValueError,'hash mismatch'):
            capture_dependencies(self.main,self.worker,'main',self.manifest)
        self.assertEqual((self.main/dependency['path']).read_bytes(),b'Existing\n')
        self.manifest['dependencies']=[self.dependency('config/usa/arm9/runtime_support.json',b'{}',b'{ }')]
        with self.assertRaisesRegex(ValueError,'allowlisted'):
            capture_dependencies(self.main,self.worker,'main',self.manifest)

    def test_preimage_checked_again_and_partial_install_restored(self):
        deps=[self.dependency('config/usa/keep_symbols.txt',b'Existing\n',b'Existing\nNew\n')]
        self.manifest['dependencies']=deps
        snapshots=capture_dependencies(self.main,self.worker,'main',self.manifest)
        original_mode=(self.main/deps[0]['path']).stat().st_mode
        (self.main/deps[0]['path']).write_bytes(b'concurrent change')
        with self.assertRaisesRegex(ValueError,'after capture'):
            install_dependencies(self.main,snapshots)
        (self.main/deps[0]['path']).write_bytes(b'Existing\n')
        def partial(path,content):
            path.write_bytes(content[:3])
            raise OSError('simulated disk failure')
        with patch('integration_dependencies.atomic_write',partial):
            with self.assertRaises(OSError):install_dependencies(self.main,snapshots)
        restore_dependencies(self.main,snapshots)
        self.assertEqual((self.main/deps[0]['path']).read_bytes(),b'Existing\n')
        self.assertEqual((self.main/deps[0]['path']).stat().st_mode,original_mode)
        install_dependencies(self.main,snapshots)
        verify_dependencies(self.main,snapshots)
        restore_dependencies(self.main,snapshots)
        self.assertEqual((self.main/deps[0]['path']).read_bytes(),b'Existing\n')

    def test_source_type_edits_and_symlinks_rejected(self):
        self.manifest['dependencies']=[self.dependency('include/Calls.h',b'int Callee(int);\n',b'void Callee(void);\n')]
        with self.assertRaisesRegex(ValueError,'more than selected identifiers'):
            capture_dependencies(self.main,self.worker,'main',self.manifest)
        (self.worker/'include/Calls.h').unlink()
        (self.worker/'include/Calls.h').symlink_to(self.main/'include/Calls.h')
        with self.assertRaisesRegex(ValueError,'escapes'):
            capture_dependencies(self.main,self.worker,'main',self.manifest)

    def test_selected_rename_preserves_original_comments_and_all_references(self):
        self.manifest['function_renames']=[{'old':'Old','new':'New'}]
        record={'function_id':'arm9/main:02000000','module':'main','address':'0x02000000',
                'old_symbol':'Old','new_symbol':'New','source':'src/New.cpp',
                'evidence':{'note':'Returns the evidenced state word'}}
        deps=[self.dependency('config/usa/arm9/symbols.txt',
                    b'Old kind:function(arm,size=0x4) addr:0x02000000\r\n',
                    b'New kind:function(arm,size=0x4) addr:0x02000000\r\n'),
              self.dependency('config/usa/function_names.json',
                    b'{"schema_version":1,"functions":{}}',
                    json.dumps({'schema_version':1,'functions':{'arm9/main:02000000':record}}).encode()),
              self.dependency('src/Caller.cpp',b'// Original: Old\nint Old(int);\n',
                    b'// Original: Old\nint New(int);\n')]
        self.manifest['dependencies']=deps
        snapshots=capture_dependencies(self.main,self.worker,'main',self.manifest)
        install_dependencies(self.main,snapshots);verify_dependencies(self.main,snapshots)
        restore_dependencies(self.main,snapshots)
        self.assertEqual((self.main/'src/Caller.cpp').read_bytes(),b'// Original: Old\nint Old(int);\n')
        self.manifest['dependencies']=deps[:-1]
        with self.assertRaisesRegex(ValueError,'Missing rename dependencies'):
            capture_dependencies(self.main,self.worker,'main',self.manifest)

    def test_profile_is_bound_to_approved_flags_and_actual_compiler(self):
        inputs=self.main/'inputs';inputs.mkdir();(inputs/'compiler.exe').write_bytes(b'pinned compiler')
        (self.main/'swarm').mkdir()
        (self.main/'swarm/config.json').write_text(json.dumps({'inputs':str(inputs),'compiler':'compiler.exe',
            'flags':['-O2'],'profiles':{'O4p':{'version':'2.0/sp2p2','opt':'-O4,p','interworking':True}}}))
        self.manifest['functions'][0]['profile']='O4p'
        profile={'version':'2.0/sp2p2','executable':'configured_default','executable_sha256':hashlib.sha256(b'pinned compiler').hexdigest(),
                 'source':'src/New.cpp','flags':['-O4,p','-i','include'],
                 'origin':'swarm profile O4p; exact bytes and relocations verified'}
        before=b'{"sources":{}}'
        path='config/usa/compiler_profiles.json'
        after=json.dumps({'sources':{'src/New.cpp':profile}}).encode()
        self.manifest['dependencies']=[self.dependency(path,before,after)]
        self.assertEqual(len(capture_dependencies(self.main,self.worker,'main',self.manifest)),1)
        profile['flags']=['-O0','-i','include']
        after=json.dumps({'sources':{'src/New.cpp':profile}}).encode()
        self.manifest['dependencies']=[self.dependency(path,before,after)]
        with self.assertRaisesRegex(ValueError,'approved profile'):
            capture_dependencies(self.main,self.worker,'main',self.manifest)

    def test_rollback_invalidates_rejected_object_freshness(self):
        dependency=self.dependency('config/usa/keep_symbols.txt',b'Existing\n',b'Existing\nNew\n')
        target=self.main/dependency['path'];os.utime(target,ns=(1,1))
        self.manifest['dependencies']=[dependency]
        snapshots=capture_dependencies(self.main,self.worker,'main',self.manifest)
        install_dependencies(self.main,snapshots)
        artifact=self.main/'rejected.o';artifact.write_bytes(b'rejected object')
        os.utime(artifact,ns=(2,2))
        restore_dependencies(self.main,snapshots)
        self.assertGreater(target.stat().st_mtime_ns,artifact.stat().st_mtime_ns)
        self.assertEqual(target.read_bytes(),b'Existing\n')


    def configure_fixture(self):
        self.test_selected_rename_preserves_original_comments_and_all_references()
        self.manifest['dependencies'].append(self.dependency('src/Caller.cpp',
            b'// Original: Old\nint Old(int);\n',b'// Original: Old\nint New(int);\n'))
        before=b'active_function_name = "-force_active Other,Old"\nflags = "unchanged"\n'
        after=b'active_function_name = "-force_active Other,New"\nflags = "unchanged"\n'
        dependency=self.dependency('tools/configure.py',before,after)
        self.manifest['dependencies'].append(dependency)
        return before,after,dependency

    def test_selected_configure_root_transaction_and_partial_rollback(self):
        before,after,dependency=self.configure_fixture()
        snapshots=capture_dependencies(self.main,self.worker,'main',self.manifest)
        install_dependencies(self.main,snapshots);verify_dependencies(self.main,snapshots)
        self.assertEqual((self.main/'tools/configure.py').read_bytes(),after)
        restore_dependencies(self.main,snapshots)
        self.assertEqual((self.main/'tools/configure.py').read_bytes(),before)
        from integration_dependencies import atomic_write
        def partial(path,content):
            if path.name=='configure.py':
                path.write_bytes(content[:7]);raise OSError('partial configure install')
            atomic_write(path,content)
        with patch('integration_dependencies.atomic_write',partial):
            with self.assertRaisesRegex(OSError,'partial configure'):install_dependencies(self.main,snapshots)
        restore_dependencies(self.main,snapshots)
        for row in snapshots:self.assertEqual((self.main/row['path']).read_bytes(),row['before'])

    def test_configure_root_hash_mismatch_is_rejected(self):
        before,after,dependency=self.configure_fixture()
        dependency['after_sha256']='0'*64
        with self.assertRaisesRegex(ValueError,'hash mismatch'):capture_dependencies(self.main,self.worker,'main',self.manifest)
        self.assertEqual((self.main/'tools/configure.py').read_bytes(),before)

    def test_configure_unrelated_policy_and_roots_are_rejected(self):
        before,after,dependency=self.configure_fixture()
        for changed in (after.replace(b'unchanged',b'changed'),after.replace(b'Other',b'Foreign')):
            dependency.update(self.dependency('tools/configure.py',before,changed))
            with self.assertRaisesRegex(ValueError,'more than selected linker root'):capture_dependencies(self.main,self.worker,'main',self.manifest)

    def test_missing_configure_root_dependency_is_rejected(self):
        self.configure_fixture();self.manifest['dependencies'].pop()
        with self.assertRaisesRegex(ValueError,'Missing rename dependencies'):capture_dependencies(self.main,self.worker,'main',self.manifest)

    def test_ambiguous_configure_root_assignment_is_rejected(self):
        before,after,dependency=self.configure_fixture()
        dependency.update(self.dependency('tools/configure.py',before+before,after+after))
        with self.assertRaisesRegex(ValueError,'ambiguous or unsupported'):capture_dependencies(self.main,self.worker,'main',self.manifest)


if __name__=='__main__':unittest.main()
