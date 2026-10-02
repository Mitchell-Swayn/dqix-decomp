"""Local reconstruction factory: durable jobs, experiment index and read-only web UI.

No endpoint executes commands. Coverage comes from archived main batch finishes,
not worker reports. A fresh heartbeat reports liveness, never source acceptance.
"""
import argparse
from contextlib import closing
from datetime import datetime, timezone
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
from pathlib import Path
import sqlite3
import subprocess
import threading
import time
from urllib.parse import urlsplit

ROOT = Path(__file__).resolve().parents[1]


def utc():
    return datetime.now(timezone.utc).isoformat()


def connect(root):
    path = Path(root) / 'build/factory/state.sqlite3'
    path.parent.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(path, timeout=20)
    db.row_factory = sqlite3.Row
    db.executescript('''
      PRAGMA journal_mode=WAL;
      CREATE TABLE IF NOT EXISTS jobs (
        id TEXT PRIMARY KEY, scope TEXT NOT NULL, status TEXT NOT NULL,
        owner TEXT, worktree TEXT, updated_at TEXT, lease_until REAL,
        result TEXT, command TEXT);
      CREATE TABLE IF NOT EXISTS workers (
        id TEXT PRIMARY KEY, model TEXT, status TEXT, task TEXT,
        worktree TEXT, updated_at TEXT, activity_at TEXT);
      CREATE TABLE IF NOT EXISTS attempts (
        id TEXT PRIMARY KEY, unit TEXT, worker TEXT, status TEXT,
        match_percent REAL, elapsed_seconds REAL, started_at TEXT,
        categories TEXT, record TEXT);
    ''')
    return db


def enqueue(db, job, scope, worktree, command):
    if not isinstance(command, list) or not command or not all(isinstance(x, str) for x in command):
        raise ValueError('command must be a nonempty JSON array of argv strings')
    tree = Path(worktree).resolve()
    if not tree.is_dir():
        raise ValueError('worktree directory does not exist')
    with db:
        db.execute('INSERT INTO jobs VALUES (?,?,?,?,?,?,?,?,?)',
                   (job, scope, 'ready', None, str(tree), utc(), None, None, json.dumps(command)))


def claim(db, worker, seconds=180):
    """Atomic claim; expired jobs require explicit retry to avoid duplicate writers."""
    db.execute('BEGIN IMMEDIATE')
    try:
        db.execute("UPDATE jobs SET status='stale' WHERE status='running' AND lease_until < ?", (time.time(),))
        job = db.execute("SELECT * FROM jobs WHERE status='ready' AND worktree NOT IN "
                         "(SELECT worktree FROM jobs WHERE status IN ('running','stale')) ORDER BY updated_at LIMIT 1").fetchone()
        if job:
            db.execute("UPDATE jobs SET status='running',owner=?,updated_at=?,lease_until=? WHERE id=?",
                       (worker, utc(), time.time() + seconds, job['id']))
        db.commit()
        return dict(job) if job else None
    except Exception:
        db.rollback()
        raise


def heartbeat(db, worker, model, status, task, worktree):
    now = utc()
    with db:
        db.execute('INSERT INTO workers VALUES (?,?,?,?,?,?,?) ON CONFLICT(id) DO UPDATE SET '
                   'model=excluded.model,status=excluded.status,task=excluded.task,worktree=excluded.worktree,updated_at=excluded.updated_at',
                   (worker, model, status, task, str(worktree), now, None))
        db.execute("UPDATE jobs SET lease_until=?,updated_at=? WHERE owner=? AND status='running'",
                   (time.time() + 180, now, worker))


def retry(db, job, confirmed_stopped=False):
    with db:
        row = db.execute('SELECT status FROM jobs WHERE id=?', (job,)).fetchone()
        if not row or row['status'] not in ('failed', 'stale'):
            raise ValueError('Only failed/stale jobs can be retried')
        if not confirmed_stopped:
            raise ValueError('Confirm previous process and descendants stopped before reusing its worktree')
        db.execute("UPDATE jobs SET status='ready',owner=NULL,lease_until=NULL,updated_at=? WHERE id=?", (utc(), job))


def run_worker(root, worker, model, once=False, timeout=1800):
    """Run explicitly queued argv without a shell; completion means needs review."""
    with closing(connect(root)) as db:
        _worker_loop(db, root, worker, model, once, timeout)


def _worker_loop(db, root, worker, model, once, timeout):
    while True:
        job = claim(db, worker)
        if not job:
            heartbeat(db, worker, model, 'idle', None, '')
            if once:
                return
            time.sleep(5)
            continue
        logs = Path(root) / 'build/factory/logs'
        logs.mkdir(parents=True, exist_ok=True)
        # Job IDs are metadata, never filenames or shell fragments.
        log = logs / (str(time.time_ns()) + '.log')
        try:
            with log.open('wb') as output:
                proc = subprocess.Popen(json.loads(job['command']), cwd=job['worktree'],
                                        stdout=output, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
                start = time.monotonic()
                while proc.poll() is None:
                    heartbeat(db, worker, model, 'running', job['id'], job['worktree'])
                    if time.monotonic() - start > timeout:
                        # Kill descendants too: stale children must not write into a reused tree.
                        if __import__('os').name == 'nt':
                            subprocess.run(['taskkill', '/PID', str(proc.pid), '/T', '/F'], capture_output=True)
                        else:
                            proc.kill()
                        proc.wait()
                        raise TimeoutError('worker timeout; inspect process cleanup before retry')
                    time.sleep(2)
                status = 'review' if proc.returncode == 0 else 'failed'
                result = f'exit={proc.returncode}; log={log}'
        except Exception as error:
            status, result = 'failed', str(error)
        with db:
            db.execute('UPDATE jobs SET status=?,result=?,updated_at=?,lease_until=NULL WHERE id=?',
                       (status, result, utc(), job['id']))
        heartbeat(db, worker, model, status, job['id'], job['worktree'])
        if once:
            return


def read_json(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def worktrees(root):
    result = subprocess.run(['git', 'worktree', 'list', '--porcelain'], cwd=root,
                            capture_output=True, text=True, timeout=10, check=True)
    return [Path(line[9:]) for line in result.stdout.splitlines() if line.startswith('worktree ')]


def sync_attempts(db, trees):
    for tree in trees:
        ledger = tree / 'build/matching/attempts.jsonl'
        if not ledger.exists():
            continue
        for line in ledger.read_text(encoding='utf-8').splitlines():
            try:
                record = json.loads(line)
                key = str(tree) + ':' + record['attempt']
                if db.execute('SELECT 1 FROM attempts WHERE id=?', (key,)).fetchone():
                    continue
                rows = record.get('summary', [])
                scores = [r['match_percent'] for r in rows if r.get('side') == 'target']
                categories = []
                diff = tree / record['attempt'] / 'diff.json'
                if diff.resolve().is_relative_to((tree / 'build/matching').resolve()) and diff.exists():
                    try:
                        from factory_diff import classify
                        analysis = classify(read_json(diff))
                        categories = [key for key, count in analysis['category_counts'].items() if count]
                    except (ImportError, ValueError, TypeError, KeyError):
                        pass
                db.execute('INSERT OR IGNORE INTO attempts VALUES (?,?,?,?,?,?,?,?,?)',
                           (key, record.get('unit'), tree.name, record.get('status'),
                            min(scores) if scores else None, record.get('elapsed_seconds'),
                            record.get('started_utc'), json.dumps(categories), json.dumps(record)))
            except (ValueError, KeyError, TypeError):
                continue  # concurrent partial line is retried on the next scan
    db.commit()


def snapshot(root, db):
    root = Path(root)
    warnings = []
    try:
        trees = worktrees(root)
        sync_attempts(db, trees)
    except (OSError, subprocess.SubprocessError) as error:
        warnings.append('Worktree scan unavailable: ' + str(error))
    try:
        queue = read_json(root / 'docs/workflow/queue.json').get('tasks', [])
    except (OSError, ValueError):
        queue = []
        warnings.append('Project queue unavailable')
    finishes = []
    # Only main-worktree pilot evidence; worker finish files do not establish acceptance.
    for path in (root / 'docs/workflow/evidence').glob('pilot-*-finish.json'):
        try:
            data = read_json(path)
            if data['snapshot']['rom_sha1'] == 'c7c3014c237900c8281289b8bc76a781969b6278':
                finishes.append(data)
        except (OSError, ValueError, KeyError):
            warnings.append('Unreadable batch evidence: ' + path.name)
    finishes.sort(key=lambda x: x['snapshot']['utc'])
    accepted = finishes[-1]['snapshot'] if finishes else {}
    batches = []
    for batch in finishes[-30:]:
        delta = batch.get('delta', {})
        batches.append(dict(name=batch['name'], elapsed_seconds=batch.get('elapsed_seconds'),
                            utc=batch['snapshot']['utc'], arm9_code_delta=delta.get('arm9', {}).get('matched_code'),
                            arm9_functions_delta=delta.get('arm9', {}).get('matched_functions'),
                            arm7_code_delta=delta.get('arm7', {}).get('source_code_bytes')))
    workers = {r['id']: dict(r) for r in db.execute('SELECT * FROM workers')}
    for task in queue:
        owner = task.get('owner')
        if not owner or owner == 'root':
            continue
        tree = (root / task.get('worktree', '.')).resolve()
        if owner not in workers:
            workers[owner] = dict(id=owner, model=task.get('model'), status='unknown',
                                  task=task.get('scope'), worktree=str(tree), updated_at=None, activity_at=None)
        row = db.execute('SELECT MAX(started_at) FROM attempts WHERE worker=?', (tree.name,)).fetchone()
        workers[owner]['activity_at'] = row[0]
    for worker in workers.values():
        if worker['updated_at']:
            age = (datetime.now(timezone.utc) - datetime.fromisoformat(worker['updated_at'])).total_seconds()
            if age > 180 and worker['status'] in ('running', 'idle'):
                worker['status'] = 'stale'
    attempts = []
    for row in db.execute('SELECT * FROM attempts ORDER BY started_at DESC LIMIT 80'):
        item = dict(row)
        item.pop('record')
        item['categories'] = json.loads(item['categories'])
        attempts.append(item)
    jobs = {t['id']: t for t in queue}
    for row in db.execute('SELECT id,scope,status,owner,result,updated_at FROM jobs'):
        jobs[row['id']] = dict(row)
    fleet = None
    fleet_path = root / 'build/factory/fleet.json'
    if fleet_path.exists():
        try:
            fleet = read_json(fleet_path)
            fleet_age = (datetime.now(timezone.utc) - datetime.fromisoformat(fleet['heartbeat_utc'])).total_seconds()
            fleet['stale'] = fleet_age > 30
            if fleet['stale']:
                warnings.append('Fleet supervisor heartbeat is stale; last process counts are unconfirmed.')
            for lane in fleet.get('workers', []):
                current = workers.setdefault(lane['id'], dict(id=lane['id'], model=fleet.get('model'),
                    task=lane.get('job_id'), worktree=lane['worktree'], updated_at=fleet['heartbeat_utc']))
                current.update(status='stale' if fleet['stale'] else lane['status'],
                               pid=lane.get('pid'), activity_at=lane.get('activity_utc'),
                               completed_batches=lane.get('completed_batches', 0), supervised=True)
                jobs['fleet:' + lane['id']] = dict(id='fleet:' + lane['id'],
                    status='stale' if fleet['stale'] else lane['status'], owner=lane['id'],
                    scope='Independent overlay reconstruction; batch ' + str(lane.get('batches_started', 0)))
        except (OSError, ValueError, KeyError):
            warnings.append('Fleet process state unavailable')
    revision = subprocess.run(['git', 'rev-parse', '--short', 'HEAD'], cwd=root, capture_output=True,
                              text=True, timeout=10).stdout.strip()
    warnings.append('Unknown/stale worker status is not proof of a running agent. Attempt timestamps show observed activity only.')
    return dict(service='dqix-factory', project_root=str(root.resolve()), generated_at=utc(), revision=revision,
                coverage=dict(arm9=accepted.get('arm9', {}), arm7=accepted.get('arm7', {}),
                              accepted_at=accepted.get('utc'), accepted_revision=accepted.get('revision')),
                fleet=fleet, workers=list(workers.values()), jobs=list(jobs.values()), attempts=attempts,
                batches=batches, warnings=warnings)


def serve(root, port, host='127.0.0.1'):
    root = Path(root).resolve()
    cached = {'service': 'dqix-factory', 'project_root': str(root), 'generated_at': None, 'warnings': ['Initial scan in progress']}
    lock = threading.Lock()

    def refresh():
        db = connect(root)
        while True:
            try:
                state = snapshot(root, db)
                with lock:
                    cached.clear()
                    cached.update(state)
            except Exception as error:
                with lock:
                    cached['warnings'] = ['Refresh failed: ' + str(error)]
            time.sleep(5)

    class Handler(BaseHTTPRequestHandler):
        def do_GET(self):
            route = urlsplit(self.path).path
            if route == '/api/state':
                with lock:
                    body = json.dumps(cached).encode()
                mime = 'application/json'
            elif route in ('/', '/index.html', '/app.js', '/style.css'):
                path = root / 'tools/factory_web' / ('index.html' if route == '/' else route[1:])
                if not path.exists():
                    self.send_error(404)
                    return
                body = path.read_bytes()
                mime = {'.html': 'text/html', '.js': 'text/javascript', '.css': 'text/css'}[path.suffix]
            else:
                self.send_error(404)
                return
            self.send_response(200)
            self.send_header('Content-Type', mime + '; charset=utf-8')
            self.send_header('Cache-Control', 'no-store')
            self.send_header('X-Content-Type-Options', 'nosniff')
            self.send_header('Content-Security-Policy', "default-src 'self'; style-src 'self'; script-src 'self'; connect-src 'self'; frame-ancestors 'none'")
            self.end_headers()
            self.wfile.write(body)

    threading.Thread(target=refresh, daemon=True).start()
    server = ThreadingHTTPServer((host, port), Handler)
    print(f'DQIX factory: http://{host}:{port}', flush=True)
    server.serve_forever()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    sub = parser.add_subparsers(dest='action', required=True)
    p = sub.add_parser('serve'); p.add_argument('--port', type=int, default=8765)
    p.add_argument('--host', default='127.0.0.1', help='Local interface address; defaults to loopback')
    sub.add_parser('sync')
    p = sub.add_parser('enqueue')
    p.add_argument('id'); p.add_argument('--scope', required=True); p.add_argument('--worktree', required=True)
    p.add_argument('--command-json', required=True, help='Path to explicit argv JSON array; never a shell string')
    p = sub.add_parser('worker'); p.add_argument('id'); p.add_argument('--model', default='unknown')
    p.add_argument('--once', action='store_true'); p.add_argument('--timeout', type=int, default=1800)
    p = sub.add_parser('heartbeat'); p.add_argument('id'); p.add_argument('--model', default='unknown')
    p.add_argument('--status', choices=['running', 'idle', 'interrupted', 'review', 'failed'], required=True)
    p.add_argument('--task'); p.add_argument('--worktree', default='')
    p = sub.add_parser('retry'); p.add_argument('id'); p.add_argument('--confirmed-stopped', action='store_true')
    args = parser.parse_args()
    if args.action == 'serve':
        serve(args.root, args.port, args.host)
        return
    if args.action == 'worker':
        run_worker(args.root, args.id, args.model, args.once, args.timeout)
        return
    db = connect(args.root)
    if args.action == 'enqueue':
        enqueue(db, args.id, args.scope, args.worktree, read_json(Path(args.command_json)))
    elif args.action == 'heartbeat':
        heartbeat(db, args.id, args.model, args.status, args.task, args.worktree)
    elif args.action == 'retry':
        retry(db, args.id, args.confirmed_stopped)
    else:
        print(json.dumps(snapshot(args.root, db), indent=2))


if __name__ == '__main__':
    main()
