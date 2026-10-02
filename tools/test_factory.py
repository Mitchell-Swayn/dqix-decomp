import json
from pathlib import Path
import sqlite3
import sys
import tempfile
import time
import unittest
from unittest.mock import patch

from factory import claim, connect, enqueue, heartbeat, run_worker, snapshot, sync_attempts, utc


class FactoryTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.db = connect(self.root)

    def tearDown(self):
        self.db.close()
        self.temp.cleanup()

    def add(self, name, tree=None):
        enqueue(self.db, name, 'test job', tree or self.root, [sys.executable, '-c', 'pass'])

    def test_two_connections_cannot_claim_same_job(self):
        self.add('one')
        other = connect(self.root)
        try:
            self.assertEqual(claim(self.db, 'a')['id'], 'one')
            self.assertIsNone(claim(other, 'b'))
        finally:
            other.close()

    def test_same_worktree_serialized(self):
        self.add('one'); self.add('two')
        self.assertIsNotNone(claim(self.db, 'a'))
        self.assertIsNone(claim(self.db, 'b'))

    def test_expired_job_not_automatically_reused(self):
        self.add('one'); self.add('two')
        claim(self.db, 'a', -1)
        self.assertIsNone(claim(self.db, 'b'))
        self.assertEqual(self.db.execute("SELECT status FROM jobs WHERE id='one'").fetchone()[0], 'stale')

    def test_different_worktree_parallel(self):
        other = self.root / 'other'; other.mkdir()
        self.add('one'); self.add('two', other)
        self.assertIsNotNone(claim(self.db, 'a'))
        self.assertIsNotNone(claim(self.db, 'b'))

    def test_shell_string_rejected(self):
        with self.assertRaises(ValueError):
            enqueue(self.db, 'bad', 'bad', self.root, 'echo bad')

    def test_worker_success_only_enters_review(self):
        self.add('one')
        run_worker(self.root, 'a', 'test', once=True)
        row = self.db.execute('SELECT * FROM jobs').fetchone()
        self.assertEqual(row['status'], 'review')
        self.assertIn('exit=0', row['result'])

    def test_worker_failure_recorded(self):
        enqueue(self.db, 'bad', 'bad', self.root, [sys.executable, '-c', 'raise SystemExit(3)'])
        run_worker(self.root, 'a', 'test', once=True)
        self.assertEqual(self.db.execute('SELECT status FROM jobs').fetchone()[0], 'failed')

    def test_attempt_import_idempotent_partial_line(self):
        folder = self.root / 'build/matching'; folder.mkdir(parents=True)
        record = dict(attempt='build/matching/example', unit='test', status='compared',
                      summary=[dict(side='target', match_percent=80)], started_utc='2026-10-03T00:00:00+00:00')
        (folder / 'attempts.jsonl').write_text(json.dumps(record) + '\n{"partial":')
        sync_attempts(self.db, [self.root]); sync_attempts(self.db, [self.root])
        self.assertEqual(self.db.execute('SELECT count(*) FROM attempts').fetchone()[0], 1)

    def test_snapshot_uses_archived_acceptance_not_live_reports(self):
        evidence = self.root / 'docs/workflow/evidence'; evidence.mkdir(parents=True)
        (evidence.parent / 'queue.json').write_text(json.dumps({'tasks': [
            dict(id='task', owner='worker', status='active', worktree='.', scope='scope')]}))
        good = dict(name='pilot-1', snapshot=dict(utc='2026-10-03T00:00:00+00:00', revision='accepted',
                    rom_sha1='c7c3014c237900c8281289b8bc76a781969b6278', arm9={'matched_code': 12}, arm7={}))
        (evidence / 'pilot-1-finish.json').write_text(json.dumps(good))
        fake = dict(good, name='worker-later', snapshot=dict(good['snapshot'], arm9={'matched_code': 999}))
        (evidence / 'worker-later-finish.json').write_text(json.dumps(fake))
        with patch('factory.worktrees', return_value=[]), patch('factory.subprocess.run') as run:
            run.return_value.stdout = 'head'
            data = snapshot(self.root, self.db)
        self.assertEqual(data['coverage']['arm9']['matched_code'], 12)
        self.assertEqual(data['workers'][0]['status'], 'unknown')

    def test_fleet_status_and_staleness_override_worker_heartbeat(self):
        heartbeat(self.db, 'fleet_test', 'test', 'running', 'test', str(self.root / 'worker'))
        fleet_path = self.root / 'build/factory/fleet.json'
        fleet = dict(heartbeat_utc=utc(), workers=[dict(id='fleet_test', worktree=str(self.root / 'worker'),
                     status='review', pid=None, completed_batches=2)], counts={'running': 0})
        fleet_path.write_text(json.dumps(fleet))
        with patch('factory.worktrees', return_value=[]), patch('factory.subprocess.run') as run:
            run.return_value.stdout = 'head'
            data = snapshot(self.root, self.db)
            self.assertEqual(data['workers'][0]['status'], 'review')
            fleet['heartbeat_utc'] = '2000-01-01T00:00:00+00:00'
            fleet_path.write_text(json.dumps(fleet))
            data = snapshot(self.root, self.db)
            self.assertEqual(data['workers'][0]['status'], 'stale')
            self.assertTrue(data['fleet']['stale'])


if __name__ == '__main__':
    unittest.main()
