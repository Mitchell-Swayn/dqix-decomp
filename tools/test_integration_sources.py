import hashlib
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from integration_sources import capture_sources, install_source, verify_sources


class SourceSnapshotTests(unittest.TestCase):
    def setUp(self):
        temporary = tempfile.TemporaryDirectory(); self.addCleanup(temporary.cleanup)
        self.root = Path(temporary.name)
        self.worker = self.root/'worker'; self.project = self.root/'project'
        self.source = 'src/Review/New.cpp'
        target = self.worker/self.source; target.parent.mkdir(parents=True); target.write_bytes(b'original source\n')
        self.expected = hashlib.sha256(target.read_bytes()).hexdigest()

    def test_worker_change_after_capture_installs_frozen_bytes(self):
        snapshots, audit = capture_sources(self.worker,[self.source],{'source_hashes':{self.source:self.expected}})
        (self.worker/self.source).write_bytes(b'changed worker\n')
        copied=[];install_source(self.project,self.source,snapshots[self.source],copied)
        self.assertEqual((self.project/self.source).read_bytes(),b'original source\n')
        verify_sources(self.project,snapshots)
        self.assertEqual(audit['source_hash_authority'],'manifest')
        (self.project/self.source).write_bytes(b'changed installed source\n')
        with self.assertRaisesRegex(ValueError,'Installed source changed'):verify_sources(self.project,snapshots)

    def test_wrong_expected_hash_rejected_before_project_mutation(self):
        with self.assertRaisesRegex(ValueError,'differs from manifest'):
            capture_sources(self.worker,[self.source],{'source_hashes':{self.source:'0'*64}})
        self.assertFalse(self.project.exists())

    def test_partial_write_is_registered_for_rollback(self):
        snapshots,_=capture_sources(self.worker,[self.source],{})
        copied=[]
        original_write=Path.write_bytes
        def partial_write(path, content):
            original_write(path,content[:5]);raise OSError('partial source write')
        with patch.object(Path,'write_bytes',partial_write):
            with self.assertRaisesRegex(OSError,'partial source write'):
                install_source(self.project,self.source,snapshots[self.source],copied)
        self.assertEqual(copied,[self.source])
        for source in copied:(self.project/source).unlink()
        self.assertFalse((self.project/self.source).exists())

    def test_legacy_capture_is_explicitly_unpinned_and_exact_keys_required(self):
        _,audit=capture_sources(self.worker,[self.source],{})
        self.assertEqual(audit['source_hash_authority'],'captured-legacy-unpinned')
        self.assertEqual(audit['source_hashes'],{self.source:self.expected})
        for invalid in (None, [], {}, {self.source:self.expected,'src/extra.cpp':self.expected}):
            with self.assertRaises(ValueError):capture_sources(self.worker,[self.source],{'source_hashes':invalid})

    def test_noncanonical_and_symlink_paths_rejected(self):
        for source in ('src/Review/../Review/New.cpp','src//Review/New.cpp','/src/Review/New.cpp'):
            with self.assertRaises(ValueError):capture_sources(self.worker,[source],{})
        alias=self.worker/'src/Review/Alias.cpp';alias.symlink_to(self.worker/self.source)
        with self.assertRaises(ValueError):capture_sources(self.worker,['src/Review/Alias.cpp'],{})


if __name__=='__main__':unittest.main()
