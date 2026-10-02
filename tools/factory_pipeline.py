"""Persistent independent review, repair routing and serialized verified integration.

Only the integration gate advances main. The coordinator never interprets a model
message as acceptance and never acknowledges a handoff before review resolution.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
import importlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

from factory import connect, heartbeat
from factory_fleet import FleetLock, atomic_json, pid_alive, utc


def git(root, *args):
    return subprocess.check_output(['git', *args], cwd=root, text=True, stderr=subprocess.STDOUT).strip()


def commits_between(root, base, tip):
    if base == tip:
        return []
    subprocess.run(['git', 'merge-base', '--is-ancestor', base, tip], cwd=root,
                   check=True, capture_output=True)
    return git(root, 'rev-list', '--reverse', '--ancestry-path', base + '..' + tip).splitlines()


def discover(root, fleet, state):
    """Freeze only producer-idle lanes; reviewer trees never share live edits."""
    added = 0
    for worker in fleet.get('workers', []):
        if worker.get('status') != 'review' or pid_alive(worker.get('pid')):
            continue
        tree = Path(worker['worktree'])
        if git(tree, 'status', '--porcelain', '--untracked-files=no'):
            continue
        tip = git(tree, 'rev-parse', 'HEAD')
        lane = worker['id']
        base = state['lane_bases'].get(lane)
        if base is None:
            base = git(root, 'merge-base', 'HEAD', tip)
        if any(s['lane'] == lane and s['source_tip'] == tip for s in state['submissions']):
            continue
        if any(s['lane'] == lane and s['status'] in ('pending', 'reviewing', 'approved', 'integrating')
               for s in state['submissions']):
            continue
        commits = commits_between(root, base, tip)
        if not commits:
            continue
        module = lane.rsplit('_', 1)[-1]
        if len(module) != 5 or not module.startswith('ov') or not module[2:].isdigit():
            continue
        submission = dict(id=lane + '-' + tip[:12], lane=lane, module=module,
                          base_revision=base, source_tip=tip, commits=commits,
                          worktree=str(tree), fleet_id=fleet['fleet_id'],
                          completed_batches=worker.get('completed_batches', 0),
                          status='pending', discovered_at=utc(), prompt_file=worker['prompt_file'])
        state['submissions'].append(submission)
        added += 1
    return added


def acknowledge(root, fleet, submission):
    # A new supervisor resets its counters. Never apply an older fleet's count.
    if fleet.get('fleet_id') != submission['fleet_id']:
        return
    path = root / 'build/factory/fleet-acks.json'
    acks = json.loads(path.read_text()) if path.exists() else {}
    acks[submission['lane']] = max(acks.get(submission['lane'], 0), submission['completed_batches'])
    atomic_json(path, acks)


def feedback(submission, detail):
    tree = Path(submission['worktree'])
    path = tree / 'build/factory/review-feedback.json'
    atomic_json(path, dict(submission=submission['id'], source_tip=submission['source_tip'],
                           status='changes_requested', detail=detail, issued_at=utc()))
    prompt_path = Path(submission['prompt_file'])
    text = prompt_path.read_text(encoding='utf-8')
    marker = '\n\nAUTOMATED REVIEW FEEDBACK\n'
    text = text.split(marker)[0]
    text += marker + ('Before starting another family, read ' + str(path) +
                     '. Fix the reported issues in your own worktree and commit the correction. '
                     'Preserve prior caps and evidence. Do not change main or approval artifacts. '
                     'If conflict resolution requires main changes, incorporate only the relevant '
                     'interfaces into your source; no merge commits. Provide a linear reviewed candidate.\n')
    prompt_path.write_text(text, encoding='utf-8')


class Pipeline:
    def __init__(self, root, config):
        self.root = Path(root).resolve()
        self.config = config
        self.directory = self.root / 'build/factory'
        self.path = self.directory / 'pipeline.json'
        self.stop = self.directory / 'PIPELINE_STOP'
        self.fleet_path = self.directory / 'fleet.json'
        self.state = json.loads(self.path.read_text()) if self.path.exists() else dict(
            schema_version=1, submissions=[], lane_bases={}, accepted=[], errors=[])
        # Interrupted external stages are never silently approved or relaunched.
        for s in self.state['submissions']:
            if s['status'] in ('reviewing', 'integrating'):
                s['status'] = 'blocked'
                s['error'] = 'Coordinator restarted during stage; inspect preserved logs/processes before retry.'
        self.pool = ThreadPoolExecutor(max_workers=5)
        self.reviews = {}
        self.integration = None
        self.fleet = {}
        self.started = utc()
        self.last_publish = 0
        self.fleet_child = None

    def load_fleet(self):
        self.fleet = json.loads(self.fleet_path.read_text()) if self.fleet_path.exists() else {}

    def restart_drained_fleet(self):
        """Transition once from the old 24-reconstructor fleet to 18 active lanes."""
        if not self.config.get('manage_fleet', True) or self.stop.exists():
            return
        if self.fleet and pid_alive(self.fleet.get('supervisor_pid')):
            return
        if any(pid_alive(w.get('pid')) for w in self.fleet.get('workers', [])):
            return
        if self.fleet_child and self.fleet_child.poll() is None:
            return
        # Do not blindly relaunch a failed supervisor repeatedly.
        if self.state.get('fleet_restart_attempted'):
            return
        self.state['fleet_restart_attempted'] = utc()
        path = Path(self.config['fleet_config'])
        config = json.loads(path.read_text())
        config['max_concurrent'] = 18
        config['max_unreviewed_batches'] = 1
        # Function workers on constructor-only overlays have no native-code job.
        # Move those lanes to unassigned code overlays; constructor data remains
        # required and its existing audit stays preserved in the old branch.
        overlays = self.root / 'config/usa/arm9/overlays'
        assigned = {w['id'].rsplit('_', 1)[-1] for w in config['workers']}
        available = [p.name for p in sorted(overlays.iterdir()) if p.is_dir() and p.name not in assigned
                     and p.name not in ('ov008', 'ov017') and '.text ' in (p / 'delinks.txt').read_text()]
        for worker in config['workers']:
            old_module = worker['id'].rsplit('_', 1)[-1]
            if not available or '.text ' in (overlays / old_module / 'delinks.txt').read_text():
                continue
            module = available.pop(0)
            old_id = worker['id']
            worker['id'] = 'fleet_' + module
            worker['module'] = module
            prompt = Path(worker['prompt_file'])
            text = prompt.read_text()
            text = text.replace('Exclusive module: ' + old_module, 'Exclusive module: ' + module)
            text = text.replace('overlays/' + old_module, 'overlays/' + module)
            text = text.replace('src/Factory/' + old_module, 'src/Factory/' + module).replace(old_id, worker['id'])
            prompt.write_text(text)
            self.state['lane_bases'][worker['id']] = git(worker['worktree'], 'rev-parse', 'HEAD')
            self.state.setdefault('scope_transitions', []).append(dict(old_lane=old_id, new_lane=worker['id'],
                utc=utc(), reason='No text section; preserved constructor-data audit, moved function capacity to native code'))
        path.write_text(json.dumps(config, indent=2) + '\n')
        # Prior run is drained. Preserve its acknowledgments before starting a new counter epoch.
        ack = self.directory / 'fleet-acks.json'
        if ack.exists():
            archive = self.directory / ('fleet-acks-' + str(time.time_ns()) + '.json')
            os.replace(ack, archive)
        (self.directory / 'STOP').unlink(missing_ok=True)
        log = (self.directory / 'pipeline-fleet.log').open('ab')
        try:
            self.fleet_child = subprocess.Popen([sys.executable, str(self.root / 'tools/factory_fleet.py'),
                '--root', str(self.root), '--config', str(path)], cwd=self.root, stdin=subprocess.DEVNULL,
                stdout=log, stderr=log, creationflags=subprocess.CREATE_NO_WINDOW if os.name == 'nt' else 0)
        finally:
            log.close()

    def resolve(self, submission, result, stage):
        if stage == 'review':
            submission['review'] = result
            if (result.get('verdict') == 'approved' and result.get('source_tip') == submission['source_tip']
                    and result.get('base_revision') == submission['base_revision'] and not result.get('findings')):
                submission['status'] = 'approved'
            elif result.get('verdict') == 'changes_requested':
                submission['status'] = 'changes_requested'
                feedback(submission, result)
                acknowledge(self.root, self.fleet, submission)
            else:
                submission['status'] = 'blocked'
        else:
            submission['integration'] = result
            status = result.get('status')
            if status in ('accepted', 'integrated'):
                submission['status'] = 'accepted'
                self.state['lane_bases'][submission['lane']] = submission['source_tip']
                self.state['accepted'].append(dict(submission=submission['id'], result=result, utc=utc()))
                acknowledge(self.root, self.fleet, submission)
            elif status in ('needs_changes', 'changes_requested', 'conflict', 'rejected'):
                submission['status'] = 'changes_requested'
                feedback(submission, result)
                acknowledge(self.root, self.fleet, submission)
            else:
                submission['status'] = 'blocked'
        submission['updated_at'] = utc()

    def step(self):
        self.load_fleet()
        for lane, (future, submission, slot) in list(self.reviews.items()):
            if future.done():
                try:
                    self.resolve(submission, future.result(), 'review')
                except Exception as error:
                    submission.update(status='blocked', error=str(error))
                del self.reviews[lane]
        if self.integration and self.integration[0].done():
            future, submission = self.integration
            try:
                self.resolve(submission, future.result(), 'integration')
            except Exception as error:
                submission.update(status='blocked', error=str(error))
            self.integration = None
        if not self.stop.exists():
            discover(self.root, self.fleet, self.state)
            # During transition, do not exceed the existing 24 native-worker capacity.
            live_reconstruction = sum(pid_alive(w.get('pid')) for w in self.fleet.get('workers', []))
            available = max(0, 24 - live_reconstruction - len(self.reviews) - bool(self.integration))
            for submission in self.state['submissions']:
                if submission['status'] != 'pending' or len(self.reviews) >= 4 or available <= 0:
                    continue
                module = importlib.import_module('factory_review')
                submission['status'] = 'reviewing'
                folder = self.directory / 'reviews' / submission['id']
                slots = {entry[2] for entry in self.reviews.values()}
                slot = next(i for i in range(1, 5) if i not in slots)
                future = self.pool.submit(module.run_review, self.root, dict(submission), self.config['backend'], folder,
                                          model=self.config.get('model', 'gpt-6.1-sol'))
                self.reviews[submission['lane']] = (future, submission, slot)
                available -= 1
            if self.integration is None and available > 0:
                submission = next((s for s in self.state['submissions'] if s['status'] == 'approved'), None)
                if submission:
                    module = importlib.import_module('factory_integrate')
                    submission['status'] = 'integrating'
                    workspace = self.root.parent / ('DQIX-Factory-Integration-' + submission['id'])
                    future = self.pool.submit(module.integrate, self.root, dict(submission), submission['review'], workspace)
                    self.integration = (future, submission)
            self.restart_drained_fleet()
        self.publish()
        return not self.stop.exists() or bool(self.reviews) or self.integration is not None

    def publish(self):
        self.state.update(heartbeat_utc=utc(), supervisor_pid=os.getpid(), started_utc=self.started,
                          stopping=self.stop.exists(), role_capacity=dict(reconstruction=18, review=4, integration=1, coordinator=1))
        self.state['counts'] = {status: sum(s['status'] == status for s in self.state['submissions'])
                                for status in ('pending', 'reviewing', 'approved', 'integrating', 'accepted', 'changes_requested', 'blocked')}
        atomic_json(self.path, self.state)
        if time.monotonic() - self.last_publish < 10:
            return
        self.last_publish = time.monotonic()
        db = connect(self.root)
        try:
            heartbeat(db, 'factory_coordinator', 'deterministic', 'running', 'Dispatch, review routing and integration queue', self.root)
            for slot in range(1, 5):
                current = next((s for f, s, i in self.reviews.values() if i == slot), None)
                heartbeat(db, 'factory_reviewer_' + str(slot), self.config.get('model', 'gpt-6.1-sol'),
                          'running' if current else 'idle', current['id'] if current else 'Waiting for a batch', '')
            heartbeat(db, 'factory_integrator', 'deterministic gates', 'running' if self.integration else 'idle',
                      self.integration[1]['id'] if self.integration else 'Waiting for approved source', '')
        finally:
            db.close()

    def run(self):
        try:
            while True:
                try:
                    if not self.step():
                        break
                    time.sleep(5)
                except Exception as error:
                    self.state['errors'].append(dict(utc=utc(), error=str(error)))
                    self.state['errors'] = self.state['errors'][-30:]
                    self.publish()
                    time.sleep(15)
        finally:
            self.pool.shutdown(wait=True)
            self.publish()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--config', type=Path, required=True)
    args = parser.parse_args()
    with FleetLock(args.root / 'pipeline-lock'):
        Pipeline(args.root, json.loads(args.config.read_text(encoding='utf-8-sig'))).run()


if __name__ == '__main__':
    main()
