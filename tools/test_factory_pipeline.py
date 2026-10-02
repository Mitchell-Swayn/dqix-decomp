import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

from factory_pipeline import Pipeline, acknowledge, commits_between, discover


class PipelineTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        subprocess.run(['git', 'init', '-q', str(self.root)], check=True)
        self.git('config', 'user.email', 'test@example.invalid')
        self.git('config', 'user.name', 'Test')
        (self.root / 'source.txt').write_text('baseline')
        self.git('add', '.'); self.git('commit', '-qm', 'baseline')
        self.base = self.git('rev-parse', 'HEAD')
        (self.root / 'source.txt').write_text('candidate')
        self.git('commit', '-qam', 'candidate')
        self.tip = self.git('rev-parse', 'HEAD')
        self.sub = dict(id='test', lane='fleet_ov000', module='ov000', worktree=str(self.root),
                        base_revision=self.base, source_tip=self.tip, commits=[self.tip],
                        fleet_id='one', completed_batches=1, status='pending')

    def tearDown(self):
        self.temp.cleanup()

    def git(self, *args):
        return subprocess.check_output(['git', *args], cwd=self.root, text=True, stderr=subprocess.STDOUT).strip()

    def test_ordered_immutable_commit_range(self):
        self.assertEqual(commits_between(self.root, self.base, self.tip), [self.tip])
        self.assertEqual(commits_between(self.root, self.tip, self.tip), [])
        with self.assertRaises(subprocess.CalledProcessError):
            commits_between(self.root, self.tip, self.base)

    def test_old_fleet_ack_never_releases_new_counter_epoch(self):
        acknowledge(self.root, {'fleet_id': 'two'}, self.sub)
        self.assertFalse((self.root / 'build/factory/fleet-acks.json').exists())
        acknowledge(self.root, {'fleet_id': 'one'}, self.sub)
        self.assertEqual(json.loads((self.root / 'build/factory/fleet-acks.json').read_text()), {'fleet_ov000': 1})

    def test_review_must_bind_exact_tip_and_base(self):
        pipe = Pipeline(self.root, {})
        try:
            sub = dict(self.sub)
            pipe.resolve(sub, dict(verdict='approved', source_tip=self.base, base_revision=self.base, findings=[]), 'review')
            self.assertEqual(sub['status'], 'blocked')
            pipe.resolve(sub, dict(verdict='approved', source_tip=self.tip, base_revision=self.base, findings=[]), 'review')
            self.assertEqual(sub['status'], 'approved')
            self.assertFalse((self.root / 'build/factory/fleet-acks.json').exists())
        finally:
            pipe.pool.shutdown()

    def test_discovery_ignores_running_and_duplicates(self):
        state = dict(submissions=[], lane_bases={'fleet_ov000': self.base})
        worker = dict(id='fleet_ov000', worktree=str(self.root), status='running', pid=None,
                      completed_batches=1, prompt_file=str(self.root / 'prompt.txt'))
        fleet = dict(fleet_id='one', workers=[worker])
        self.assertEqual(discover(self.root, fleet, state), 0)
        worker['status'] = 'review'
        self.assertEqual(discover(self.root, fleet, state), 1)
        self.assertEqual(state['submissions'][0]['source_tip'], self.tip)
        self.assertEqual(discover(self.root, fleet, state), 0)
        (self.root / 'source.txt').write_text('uncommitted')
        state['submissions'].clear()
        self.assertEqual(discover(self.root, fleet, state), 0)


if __name__ == '__main__':
    unittest.main()
