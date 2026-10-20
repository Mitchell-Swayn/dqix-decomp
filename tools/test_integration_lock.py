import multiprocessing
from pathlib import Path
import tempfile
import unittest
from integration_lock import integration_guard

def contender(root, ready, finished):
    ready.set()
    with integration_guard(root):
        finished.set()

class IntegrationLockTests(unittest.TestCase):
    def test_contender_cannot_enter_until_owner_releases(self):
        with tempfile.TemporaryDirectory() as root:
            ready, finished = multiprocessing.Event(), multiprocessing.Event()
            with integration_guard(root) as owner:
                owner.begin_changes()
                worker = multiprocessing.Process(target=contender, args=(root, ready, finished))
                worker.start()
                self.assertTrue(ready.wait(3))
                self.assertFalse(finished.wait(.15))
                owner.release_publication()
                self.assertFalse(finished.wait(.15))
            self.assertTrue(finished.wait(3))
            worker.join(3)
            self.assertEqual(worker.exitcode, 0)

    def test_failed_recovery_retains_publication_gate_and_releases_process_gate(self):
        with tempfile.TemporaryDirectory() as root:
            with self.assertRaises(ValueError):
                with integration_guard(root) as owner:
                    owner.begin_changes()
                    raise ValueError('rollback failed')
            self.assertTrue((Path(root)/'build/progress/integration.lock').exists())
            with self.assertRaisesRegex(RuntimeError, 'unfinished'):
                with integration_guard(root):
                    self.fail('must not enter')

    def test_verified_rollback_releases_publication_gate(self):
        with tempfile.TemporaryDirectory() as root:
            with self.assertRaises(ValueError):
                with integration_guard(root) as owner:
                    owner.begin_changes()
                    owner.release_publication()
                    raise ValueError('candidate rejected, accepted state restored')
            with integration_guard(root):
                self.assertFalse((Path(root)/'build/progress/integration.lock').exists())

    def test_explicit_recovery_requires_marker_and_keeps_it_until_verified(self):
        with tempfile.TemporaryDirectory() as root:
            with self.assertRaisesRegex(RuntimeError,'requires'):
                with integration_guard(root,recovery=True):self.fail('No unfinished transaction')
            with integration_guard(root) as owner:owner.begin_changes()
            with self.assertRaises(ValueError):
                with integration_guard(root,recovery=True) as owner:
                    self.assertTrue(owner.changed)
                    raise ValueError('still unverified')
            with self.assertRaisesRegex(RuntimeError,'unfinished'):
                with integration_guard(root):self.fail('Must remain blocked')
            with integration_guard(root,recovery=True) as owner:owner.release_publication()
            with integration_guard(root):pass
