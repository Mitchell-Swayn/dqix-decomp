import copy
import json
import unittest
from unittest.mock import patch
import test_integration_dependencies as single_tests
from integration_dependencies import sha
from mixed_integration_dependencies import (capture_mixed_dependencies,
    install_mixed_dependencies, verify_mixed_dependencies, restore_mixed_dependencies)


class MixedDependenciesTests(unittest.TestCase):
    setUp = single_tests.DependenciesTests.setUp
    dependency = single_tests.DependenciesTests.dependency

    def fixture(self):
        rows=[]; renames=[]; names={}; deps=[]; hashes={}
        for module,old,new in [('ov000','OldA','NewA'),('ov001','OldB','NewB')]:
            source='src/'+new+'.cpp'
            path=self.worker/source;path.parent.mkdir(parents=True,exist_ok=True)
            path.write_text('void '+new+'() {}\n');hashes[source]=sha(path.read_bytes())
            rows.append(dict(module=module,name=new,source=source,address='0x02100000',size=4))
            renames.append(dict(module=module,old=old,new=new))
            identity='arm9/'+module+':02100000'
            names[identity]=dict(function_id=identity,module=module,address='0x02100000',
                old_symbol=old,new_symbol=new,source=source,evidence={'note':'Evidenced operation'})
            deps.append(self.dependency('config/usa/arm9/overlays/'+module+'/symbols.txt',
                (old+' kind:function(arm,size=0x4) addr:0x02100000\n').encode(),
                (new+' kind:function(arm,size=0x4) addr:0x02100000\n').encode()))
        deps += [self.dependency('config/usa/function_names.json',b'{"schema_version":1,"functions":{}}',
            json.dumps({'schema_version':1,'functions':names}).encode()),
            self.dependency('src/Caller.cpp',b'// Original: OldA\nOldA(); OldB();\n',b'// Original: OldA\nNewA(); NewB();\n'),
            self.dependency('tools/configure.py',b'active_function_name = "-force_active OldA,OldB"\n',b'active_function_name = "-force_active NewA,NewB"\n'),
            self.dependency('config/usa/keep_symbols.txt',b'OldA\nOldB\n',b'NewA\nNewB\n')]
        self.manifest=dict(functions=rows,function_renames=renames,dependencies=deps,source_hashes=hashes)
        return self.manifest

    def test_union_shared_files_captured_once_module_qualified_and_restored(self):
        self.fixture();snapshots=capture_mixed_dependencies(self.main,self.worker,self.manifest)
        self.assertEqual(len(snapshots),6)
        self.assertEqual(len({s['path'] for s in snapshots}),6)
        self.assertEqual([x['function_id'] for x in snapshots[0]['selected_identities']],
                         ['arm9/ov000:02100000','arm9/ov001:02100000'])
        install_mixed_dependencies(self.main,snapshots);verify_mixed_dependencies(self.main,snapshots)
        self.assertEqual((self.main/'src/Caller.cpp').read_text(),'// Original: OldA\nNewA(); NewB();\n')
        restore_mixed_dependencies(self.main,snapshots)
        for s in snapshots:self.assertEqual((self.main/s['path']).read_bytes(),s['before'])

    def test_duplicate_and_conflicting_declarations_rejected_without_writes(self):
        self.fixture()
        for conflicting in (False,True):
            manifest=copy.deepcopy(self.manifest);duplicate=dict(manifest['dependencies'][0])
            if conflicting:duplicate['after_sha256']='0'*64
            manifest['dependencies'].append(duplicate)
            with self.assertRaisesRegex(ValueError,'Duplicate dependency'):
                capture_mixed_dependencies(self.main,self.worker,manifest)
        self.assertTrue((self.main/'src/Caller.cpp').read_text().endswith('OldA(); OldB();\n'))

    def test_wrong_module_size_identity_and_duplicate_selected_fail_closed(self):
        self.fixture()
        for key,value in [('module','ov002'),('size',8),('function_id','arm9/ov001:02100000')]:
            manifest=copy.deepcopy(self.manifest);manifest['functions'][0][key]=value
            with self.assertRaises((ValueError,FileNotFoundError)):
                capture_mixed_dependencies(self.main,self.worker,manifest)
        manifest=copy.deepcopy(self.manifest);manifest['functions'].append(manifest['functions'][0])
        with self.assertRaisesRegex(ValueError,'Duplicate selected'):
            capture_mixed_dependencies(self.main,self.worker,manifest)

    def test_global_policy_source_and_hash_tampering_rejected(self):
        self.fixture()
        for relative,after in [('config/usa/function_names.json',b'{"schema_version":2,"functions":{}}'),
                               ('src/Caller.cpp',b'int NewA(int); NewB();\n'),
                               ('tools/configure.py',b'active_function_name = "-force_active NewA,Foreign"\n')]:
            manifest=copy.deepcopy(self.manifest)
            dep=next(x for x in manifest['dependencies'] if x['path']==relative)
            (self.worker/relative).write_bytes(after);dep['after_sha256']=sha(after)
            with self.assertRaises(ValueError):capture_mixed_dependencies(self.main,self.worker,manifest)
            self.fixture()
        self.manifest['source_hashes']['src/NewA.cpp']='0'*64
        with self.assertRaisesRegex(ValueError,'source hash'):
            capture_mixed_dependencies(self.main,self.worker,self.manifest)

    def test_unselected_overlay_duplicate_original_name_is_ambiguous(self):
        self.fixture();p=self.main/'config/usa/arm9/overlays/ov002/symbols.txt';p.parent.mkdir(parents=True)
        p.write_text('OldA kind:function(arm,size=0x4) addr:0x02100000\n')
        with self.assertRaisesRegex(ValueError,'Ambiguous original'):
            capture_mixed_dependencies(self.main,self.worker,self.manifest)

    def test_capture_tampering_and_stale_second_preimage_reject_before_first_write(self):
        self.fixture();snapshots=capture_mixed_dependencies(self.main,self.worker,self.manifest)
        for mutation in ('duplicate','postimage','provenance'):
            changed=copy.deepcopy(snapshots)
            if mutation=='duplicate':changed.append(changed[0])
            elif mutation=='postimage':changed[-1]['after']=b'tampered'
            else:changed[-1]['selected_identities']=[]
            with self.assertRaises(ValueError):install_mixed_dependencies(self.main,changed)
        (self.main/snapshots[1]['path']).write_bytes(b'concurrent')
        with self.assertRaisesRegex(ValueError,'after capture'):
            install_mixed_dependencies(self.main,snapshots)
        self.assertEqual((self.main/snapshots[0]['path']).read_bytes(),snapshots[0]['before'])

    def test_partial_install_is_restorable_as_one_union(self):
        self.fixture();snapshots=capture_mixed_dependencies(self.main,self.worker,self.manifest)
        from integration_dependencies import atomic_write
        count=0
        def fail(path,content):
            nonlocal count
            count+=1
            if count==3:path.write_bytes(b'partial');raise OSError('disk failure')
            atomic_write(path,content)
        with patch('integration_dependencies.atomic_write',fail):
            with self.assertRaises(OSError):install_mixed_dependencies(self.main,snapshots)
        restore_mixed_dependencies(self.main,snapshots)
        for s in snapshots:self.assertEqual((self.main/s['path']).read_bytes(),s['before'])

    def test_missing_dependency_and_non_source_payload_rejected(self):
        self.fixture();self.manifest['dependencies'].pop(3)
        with self.assertRaisesRegex(ValueError,'Missing rename dependencies'):
            capture_mixed_dependencies(self.main,self.worker,self.manifest)
        self.fixture();self.manifest['data']=[{'unsupported':'data'}]
        with self.assertRaisesRegex(ValueError,'source functions only'):
            capture_mixed_dependencies(self.main,self.worker,self.manifest)

    def test_union_profile_policy_is_exact_and_compiler_hash_bound(self):
        self.fixture();inputs=self.main/'inputs';inputs.mkdir();(inputs/'compiler.exe').write_bytes(b'compiler')
        (self.main/'swarm').mkdir();(self.main/'swarm/config.json').write_text(json.dumps(dict(inputs=str(inputs),compiler='compiler.exe',
            flags=['-O2','-interworking'],profiles={'O4p':dict(version='2.0/sp2p2',opt='-O4,p',interworking=True)})))
        profiles={}
        for row in self.manifest['functions']:
            row['profile']='O4p'
            profiles[row['source']]=dict(version='2.0/sp2p2',executable='configured_default',executable_sha256=sha(b'compiler'),
                source=row['source'],flags=['-O4,p','-interworking','-i','include'],origin='swarm profile O4p; exact bytes and relocations verified')
        path='config/usa/compiler_profiles.json'
        self.manifest['dependencies'].append(self.dependency(path,b'{"sources":{}}',json.dumps({'sources':profiles}).encode()))
        captures=capture_mixed_dependencies(self.main,self.worker,self.manifest)
        self.assertEqual(sum(s['path']==path for s in captures),1)
        profiles['src/NewB.cpp']['executable_sha256']='0'*64
        self.manifest['dependencies'][-1]=self.dependency(path,b'{"sources":{}}',json.dumps({'sources':profiles}).encode())
        with self.assertRaisesRegex(ValueError,'executable hash'):
            capture_mixed_dependencies(self.main,self.worker,self.manifest)


if __name__=='__main__':unittest.main()
