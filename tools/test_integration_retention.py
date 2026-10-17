import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from test_linker_retention import RetentionTests
from integration_retention import capture_retention_policy,install_retention_policy,verify_retention_policy,restore_retention_policy

class IntegrationRetentionTests(unittest.TestCase):
    def setUp(self):
        fixture=RetentionTests();fixture.setUp();self.addCleanup(fixture.doCleanups)
        fixture.write();self.worker=fixture.root;self.row=fixture.row
        temp=tempfile.TemporaryDirectory();self.addCleanup(temp.cleanup);self.main=Path(temp.name)
        self.relative='config/usa/arm9/overlays/ov019/retained_data.json';self.path=self.worker/self.relative
        self.manifest={'retention_policy':self.relative,'retention_policy_sha256':hashlib.sha256(self.path.read_bytes()).hexdigest()}
        self.data=[dict(name=self.row['name'],address=self.row['address'],section=self.row['section'],size=self.row['size'],source=self.row['source'],sha256=self.row['original_sha256'])]
        self.sources={self.row['source']:(self.worker/self.row['source']).read_bytes()}
    def capture(self):return capture_retention_policy(self.main,self.worker,'ov019',self.manifest,self.data,self.sources)
    def test_install_verify_restore_absent_policy(self):
        snapshot=self.capture();directory=self.main/Path(self.relative).parent;directory.mkdir(parents=True)
        for name in ('symbols.txt','delinks.txt'):(directory/name).write_bytes((self.path.parent/name).read_bytes())
        source=self.main/self.row['source'];source.parent.mkdir(parents=True);source.write_bytes(self.sources[self.row['source']])
        install_retention_policy(self.main,snapshot);verify_retention_policy(self.main,snapshot)
        restore_retention_policy(self.main,snapshot);self.assertFalse((self.main/self.relative).exists())
    def test_manifest_hash_is_mandatory(self):
        del self.manifest['retention_policy_sha256']
        with self.assertRaises(ValueError):self.capture()
    def test_wrong_module_dependency_rejected(self):
        self.manifest['retention_policy']=self.relative.replace('ov019','ov010')
        with self.assertRaises(ValueError):self.capture()
    def test_unselected_root_rejected(self):
        self.data=[]
        with self.assertRaises(ValueError):self.capture()
    def test_extent_and_original_binding_rejected(self):
        for key,value in [('size',8),('address','0x1005'),('sha256','0'*64)]:
            old=self.data[0][key];self.data[0][key]=value
            with self.assertRaises(ValueError):self.capture()
            self.data[0][key]=old
    def test_captured_source_hash_binding_rejected(self):
        self.sources[self.row['source']]=b'changed'
        with self.assertRaises(ValueError):self.capture()
    def test_existing_root_cannot_change(self):
        path=self.main/self.relative;path.parent.mkdir(parents=True)
        document=json.loads(self.path.read_text());document['symbols'][0]['reason']='Existing approved reason';path.write_text(json.dumps(document))
        before=path.read_bytes()
        with self.assertRaises(ValueError):self.capture()
        self.assertEqual(path.read_bytes(),before)
    def test_verify_detects_changed_policy(self):
        snapshot=self.capture();path=self.main/self.relative;path.parent.mkdir(parents=True);path.write_bytes(b'changed')
        with self.assertRaises(ValueError):verify_retention_policy(self.main,snapshot)
    def test_restore_existing_empty_policy_bytes(self):
        path=self.main/self.relative;path.parent.mkdir(parents=True)
        before=b'{"schema_version":1,"symbols":[]}\n';path.write_bytes(before)
        snapshot=self.capture();path.write_bytes(snapshot['after']);restore_retention_policy(self.main,snapshot)
        self.assertEqual(path.read_bytes(),before)
    def test_policy_change_between_capture_and_install_rejected(self):
        snapshot=self.capture();path=self.main/self.relative;path.parent.mkdir(parents=True);path.write_bytes(b'foreign change')
        with self.assertRaises(ValueError):install_retention_policy(self.main,snapshot)
        self.assertEqual(path.read_bytes(),b'foreign change')
    def test_no_policy_unchanged(self):
        self.assertIsNone(capture_retention_policy(self.main,self.worker,'ov019',{},self.data,self.sources))
    def test_hash_without_policy_rejected(self):
        with self.assertRaises(ValueError):capture_retention_policy(self.main,self.worker,'ov019',{'retention_policy_sha256':'0'*64},self.data,self.sources)

if __name__=='__main__':unittest.main()
