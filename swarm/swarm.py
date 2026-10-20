#!/usr/bin/env python3
"""Parallel function-level decompilation: lease, context, check, submit, integrate.

Workers:      next | context | check | submit | release
Coordinator:  build | status | integrate
"""
import argparse
import json
import os
from pathlib import Path
import re
import sys
import time

sys.path.insert(0, str(Path(__file__).resolve().parent))
from state import CONFIG, Project, log  # noqa: E402

PENDING = "('open','leased')"


def expire(db):
    db.execute("UPDATE tasks SET status='open', worker=NULL, lease_until=NULL "
               "WHERE status='leased' AND lease_until<?", (time.time(),))


def get_task(db, ident):
    """Accept a task id (arm9/main:0200961c), a bare address, or a current/old symbol name."""
    row = db.execute('SELECT * FROM tasks WHERE id=?', (ident,)).fetchone()
    if row is None and re.fullmatch(r'(0x)?[0-9a-fA-F]{8}', ident):
        rows = db.execute('SELECT * FROM tasks WHERE address=?', (int(ident, 16),)).fetchall()
        row = rows[0] if len(rows) == 1 else None
        if len(rows) > 1:
            raise SystemExit(f'address is ambiguous across modules: {[r["id"] for r in rows]}')
    if row is None:
        row = db.execute('SELECT * FROM tasks WHERE name=?', (ident,)).fetchone()
    if row is None:
        raise SystemExit(f'unknown task {ident!r}')
    return row


def worker_name(args, task=None):
    """Explicit --worker, then SWARM_WORKER, then the current lease holder."""
    if args.worker or os.environ.get('SWARM_WORKER'):
        return args.worker or os.environ['SWARM_WORKER']
    if task is not None and task['status'] == 'leased' and task['worker']:
        return task['worker']
    return f'pid{os.getppid()}'


# ---------------------------------------------------------------- context

def callee_rows(db, task_id, direction='callee', limit=None):
    col, other = ('caller', 'callee') if direction == 'callee' else ('callee', 'caller')
    rows = db.execute(f'SELECT {other} AS id FROM edges WHERE {col}=? ORDER BY {other}', (task_id,)).fetchall()
    out = []
    for r in rows[:limit] if limit else rows:
        module, addr = r['id'].split(':')
        addr = int(addr, 16)
        t = db.execute('SELECT name,status FROM tasks WHERE id=?', (r['id'],)).fetchone()
        sym = db.execute("SELECT name FROM symbols WHERE module=? AND address=? AND kind='function'",
                         (module, addr)).fetchone()
        name = sym['name'] if sym else (t['name'] if t else r['id'])
        status = t['status'] if t else 'source'
        d = db.execute('SELECT decl,path FROM decls WHERE name=?', (name,)).fetchone()
        out.append((name, status, d['decl'] if d else None, d['path'] if d else None))
    return out, len(rows)


def render_context(db, task, full=False):
    lines = [f"# {task['id']}  {task['name']}  {task['mode']}  size={task['size']:#x}  "
             f"status={task['status']}  checks={task['checks']}  best={task['best']}"]
    if task['hints']:
        lines += ['hint: ' + h for h in task['hints'].splitlines()]
    if not task['referenced']:
        lines.append('note: no relocation references this function (likely called via data tables or unused)')
    lines += ['', '## Original', task['listing'], '']
    callees, n = callee_rows(db, task['id'])
    if callees:
        lines.append(f'## Calls ({n})')
        for name, status, decl, path in callees:
            lines.append(f'  {name:<40} [{status}]' + (f'  {decl}   // {path}' if decl else ''))
        lines.append('')
    callers, n = callee_rows(db, task['id'], 'caller', None if full else 6)
    if callers:
        lines.append(f'## Called by ({n}{"" if full or n <= 6 else ", first 6; use --callers"})')
        for name, status, decl, path in callers:
            lines.append(f'  {name:<40} [{status}]' + (f'  // {path}' if path else ''))
        lines.append('')
    if task['pseudocode']:
        lines += ['## Ghidra pseudocode (unverified hint)', task['pseudocode'].strip(), '']
    if task['notes']:
        lines += ['## Notes from earlier attempts', task['notes'].strip(), '']
    return '\n'.join(lines)


def grep(project, pattern, limit=40):
    rx = re.compile(pattern)
    hits = []
    for base in ('include', 'src'):
        for path in sorted((project.root / base).rglob('*')):
            if path.suffix not in ('.h', '.hpp', '.c', '.cpp') or 'AssemblyFallback' in path.parts:
                continue
            for i, line in enumerate(path.read_text(errors='replace').splitlines(), 1):
                if rx.search(line):
                    hits.append(f'{path.relative_to(project.root)}:{i}: {line.strip()[:160]}')
                    if len(hits) >= limit:
                        return hits + ['(more results truncated)']
    return hits


# ---------------------------------------------------------------- commands

def cmd_build(project, args):
    from build import build
    print(json.dumps(build(project, args.evidence, args.force), indent=1))


def fleet_stop(project, worker):
    """build/swarm/fleet.json: {"deadline": epoch, "stop": regex of worker names to stop}."""
    path = project.state / 'fleet.json'
    if not path.exists():
        return None
    fleet = json.loads(path.read_text())
    if fleet.get('deadline') and time.time() >= fleet['deadline']:
        return 'run deadline reached'
    if fleet.get('stop') and re.search(fleet['stop'], worker):
        return fleet.get('reason', 'stopped by coordinator')
    return None


def cmd_next(project, args):
    stop = fleet_stop(project, worker_name(args))
    if stop:
        print(f'STOP: {stop}. Release any task you still hold, then finish with your report.')
        return 3
    db = project.connect()
    db.execute('BEGIN IMMEDIATE')
    expire(db)
    where, params = ["t.status='open'"], []
    if args.module:
        where.append('t.module=?'); params.append(args.module)
    if args.max_size is not None:
        where.append('t.size<=?'); params.append(args.max_size)
    if args.min_size is not None:
        where.append('t.size>=?'); params.append(args.min_size)
    row = db.execute(f'''SELECT t.*, (SELECT count(*) FROM edges e JOIN tasks c ON c.id=e.callee
                         WHERE e.caller=t.id AND c.status IN {PENDING}) AS pending
                         FROM tasks t WHERE {' AND '.join(where)}
                         ORDER BY t.gave_up, t.asm_likely, pending, t.size, t.id LIMIT 1''', params).fetchone()
    if row is None:
        db.execute('COMMIT')
        print('no open tasks match')
        return 1
    worker = worker_name(args)
    db.execute("UPDATE tasks SET status='leased', worker=?, lease_until=?, updated=? WHERE id=?",
               (worker, time.time() + CONFIG['lease_seconds'], time.time(), row['id']))
    log(db, 'lease', row['id'], worker)
    db.execute('COMMIT')
    print(render_context(db, get_task(db, row['id'])))


def cmd_context(project, args):
    db = project.connect()
    if args.grep:
        print('\n'.join(grep(project, args.grep)) or 'no matches')
        return
    if args.symbol:
        rows = db.execute('SELECT * FROM symbols WHERE name=?', (args.symbol,)).fetchall()
        d = db.execute('SELECT decl,path FROM decls WHERE name=?', (args.symbol,)).fetchone()
        for r in rows:
            print(f"{r['module']}  {r['name']}  {r['kind']}  {r['address']:#010x}" +
                  (f"  {r['mode']} size={r['size']:#x}" if r['kind'] == 'function' else ''))
        if d:
            print(f"decl: {d['decl']}   // {d['path']}")
        t = db.execute('SELECT id,status FROM tasks WHERE name=?', (args.symbol,)).fetchone()
        if t:
            print(f"task: {t['id']} [{t['status']}]")
        if not rows:
            print('unknown symbol')
        return
    task = get_task(db, args.task)
    if args.callers:
        rows, n = callee_rows(db, task['id'], 'caller')
        for name, status, decl, path in rows:
            print(f'{name:<40} [{status}]' + (f'  {decl}   // {path}' if decl else ''))
        return
    print(render_context(db, task, full=True))


def _read_source(path):
    if path == '-':
        return sys.stdin.read(), '.cpp'
    p = Path(path)
    return p.read_text(), '.c' if p.suffix == '.c' else '.cpp'


def _print_check(result, verbose):
    status = result['status']
    head = f"{status.upper()}  {result['task']}"
    if 'symbol' in result:
        head += f"  symbol={result['symbol']}  size={result.get('size', 0):#x}/{result.get('original_size', 0):#x}"
    if 'score' in result:
        head += f"  score={result['score']}  differing_bytes={result.get('differing_bytes')}"
    print(head + f"  ({result.get('elapsed_ms', result.get('compile_ms'))} ms)")
    for line in result.get('messages', []):
        print('  ' + line)
    for problem in result['problems']:
        print('  problem: ' + problem)
    for row in result.get('canonical', {}).get('declarations', []):
        print(f"  canonical: {row['path']} [{row['authority']}] {row['decl']}")
        print(f"    candidate: {row['candidate_declaration']}")
    for line in result.get('canonical', {}).get('messages', []):
        print('  ' + line)
    for warning in result.get('warnings', []):
        print('  warning: ' + warning)
    if result.get('diff') and (verbose or status != 'match'):
        print('  diff (- original, + candidate):')
        diff = result['diff'] if verbose else result['diff'][:60]
        for line in diff:
            print('    ' + line)
        if len(diff) < len(result['diff']):
            print(f"    ({len(result['diff']) - len(diff)} more lines; --verbose shows all)")


def run_check(project, db, args, task):
    from verify import check
    text, suffix = _read_source(args.file)
    include_dir = None
    if args.file != '-':
        parent = Path(args.file).resolve().parent
        include_dir = parent.relative_to(project.root) if parent.is_relative_to(project.root) else parent
    result = check(project, db, task, text, args.symbol, suffix, include_dir, args.profile)
    score = result.get('score', 0) if result['status'] in ('match', 'mismatch') else 0
    if not result['status'].startswith('canonical_'):
        db.execute('UPDATE tasks SET checks=checks+1, best=max(best,?), updated=? WHERE id=?',
                   (score, time.time(), task['id']))
    log(db, 'check', task['id'], worker_name(args, task), status=result['status'], score=score)
    return result, text, suffix


def cmd_check(project, args):
    db = project.connect()
    task = get_task(db, args.task)
    result, _, _ = run_check(project, db, args, task)
    if args.json:
        print(json.dumps(result, indent=1))
    else:
        _print_check(result, args.verbose)
    return 0 if result['status'] == 'match' else 1


def cmd_submit(project, args):
    db = project.connect()
    task = get_task(db, args.task)
    resubmit = task['status'] == 'submitted' and task['worker'] == worker_name(args, task)
    if task['status'] not in ('open', 'leased') and not resubmit:
        raise SystemExit(f"task is {task['status']}" + (
            f" by {task['worker']}" if task['status'] == 'submitted' else '') + '; nothing to submit')
    result, text, suffix = run_check(project, db, args, task)
    _print_check(result, False)
    if result['status'] != 'match':
        print('not submitted: candidate does not match')
        return 1
    from canonical import accepted_read, snapshot, StateUnavailable
    try:
        with accepted_read(project):
            if snapshot(project, db)[0] != result['canonical_state']:
                raise StateUnavailable('canonical inputs changed before submit; rerun submit')
            current = get_task(db, args.task)
            if current['status'] not in ('open', 'leased') and not (
                    current['status'] == 'submitted' and current['worker'] == worker_name(args, current)):
                print('not submitted: task state changed; retry')
                return 1
            return _enqueue(project, db, args, current, result, text, suffix)
    except StateUnavailable as error:
        print('not submitted: ' + str(error))
        return 1


def _enqueue(project, db, args, task, result, text, suffix):
    symbol = result['symbol']
    clash = db.execute('SELECT module,address FROM symbols WHERE name=? AND NOT (module=? AND address=?)',
                       (symbol, task['module'], task['address'])).fetchone()
    if clash or db.execute("SELECT 1 FROM tasks WHERE symbol=? AND id!=? AND status IN ('submitted','integrated')",
                           (symbol, task['id'])).fetchone():
        print(f'not submitted: name {symbol} is already used; choose a distinct descriptive name')
        return 1
    mangled = db.execute("SELECT name FROM symbols WHERE name LIKE ? AND NOT (module=? AND address=?)",
                         (f'_Z%{len(symbol)}{symbol}%', task['module'], task['address'])).fetchone()
    if mangled and re.match(rf'_ZN?(\d+\w+?)*{len(symbol)}{re.escape(symbol)}', mangled[0]):
        print(f'not submitted: {symbol} is the base name of existing C++ function {mangled[0]}; '
              'choose a name that describes this function')
        return 1
    from integrate import delink_basenames
    if symbol.lower() in delink_basenames(project.root):
        print(f'not submitted: a source unit named {symbol} already exists; choose a distinct name')
        return 1
    db.execute("UPDATE tasks SET status='submitted', worker=?, source=?, symbol=?, subsystem=?, profile=?, "
               "suffix=?, updated=?, lease_until=NULL WHERE id=?",
               (worker_name(args, task), text, symbol, args.subsystem or 'Unclassified', args.profile, suffix,
                time.time(), task['id']))
    if args.note:
        _append_note(db, task, worker_name(args, task), args.note)
    log(db, 'submit', task['id'], worker_name(args, task), symbol=symbol)
    if re.fullmatch(r'func_(ov\d{3}_)?[0-9a-f]{8}', symbol):
        print('submitted (address-only name: naming remains pending work)')
    else:
        print('submitted')
    return 0


def _append_note(db, task, worker, note):
    stamp = time.strftime('%Y-%m-%d %H:%M')
    db.execute("UPDATE tasks SET notes=notes || ? WHERE id=?", (f'[{stamp} {worker}] {note.strip()}\n', task['id']))


def cmd_release(project, args):
    db = project.connect()
    task = get_task(db, args.task)
    if task['status'] != 'leased':
        raise SystemExit(f"task is {task['status']}")
    db.execute("UPDATE tasks SET status='open', worker=NULL, lease_until=NULL, gave_up=gave_up+1, updated=? "
               "WHERE id=?", (time.time(), task['id']))
    if args.note:
        _append_note(db, task, worker_name(args, task), args.note)
    log(db, 'release', task['id'], worker_name(args, task), note=args.note)
    print('released')


def cmd_status(project, args):
    db = project.connect()
    expire(db)
    counts = dict(db.execute('SELECT status, count(*) FROM tasks GROUP BY status').fetchall())
    size = dict(db.execute('SELECT status, sum(size) FROM tasks GROUP BY status').fetchall())
    since = time.time() - 3600
    recent = dict(db.execute('SELECT kind, count(*) FROM events WHERE time>? GROUP BY kind', (since,)).fetchall())
    out = dict(tasks=counts, bytes=size, last_hour=recent)
    if args.leases:
        out['leases'] = [dict(r) for r in db.execute(
            "SELECT id, worker, round(lease_until-?) AS seconds_left, checks FROM tasks WHERE status='leased'",
            (time.time(),))]
    print(json.dumps(out, indent=1))


TRIVIAL = [  # (listing ops regex, source template) for bodies that need no judgement.
    (r'bx lr', 'extern "C" void {name}(void)\n{{\n}}\n'),
    (r'movs? r0, #(0x[0-9a-f]+|\d+)\|bx lr', 'extern "C" int {name}(void)\n{{\n    return {0};\n}}\n'),
]


def cmd_autosolve(project, args):
    """Generate, verify and submit empty and constant-return functions without a worker."""
    from verify import check
    db = project.connect()
    expire(db)
    rows = db.execute("SELECT * FROM tasks WHERE status='open' AND size<=8 "
                      "AND notes NOT LIKE '%integrator] rejected%'").fetchall()
    solved = []
    for task in rows:
        ops = '|'.join(' '.join(line.split(':', 1)[1].split()) for line in task['listing'].splitlines()
                       if not line.split(':', 1)[1].split()[0].startswith('.'))
        for pattern, template in TRIVIAL:
            m = re.fullmatch(pattern, ops)
            if not m:
                continue
            source = (f"#include <globaldefs.h>\n{task['mode'].upper()}\n\n"
                      + template.format(*m.groups(), name=task['name']))
            result = check(project, db, task, source)
            if result['status'] == 'match' and not args.dry_run:
                db.execute("UPDATE tasks SET status='submitted', worker='autosolve', source=?, symbol=?, "
                           "subsystem='Unclassified', profile='default', suffix='.cpp', updated=? "
                           "WHERE id=? AND status='open'", (source, task['name'], time.time(), task['id']))
                log(db, 'submit', task['id'], 'autosolve', symbol=task['name'])
            if result['status'] == 'match':
                solved.append(task['id'])
            break
    print(json.dumps(dict(candidates=len(rows), solved=len(solved), dry_run=args.dry_run)))


def cmd_integrate(project, args):
    from integrate import integrate
    print(json.dumps(integrate(project, args.limit, args.dry_run), indent=1))


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--project', help='project root (default: this checkout)')
    sub = p.add_subparsers(dest='command', required=True)

    s = sub.add_parser('build', help='create/refresh the task database'); s.set_defaults(fn=cmd_build)
    s.add_argument('--evidence'); s.add_argument('--force', action='store_true')

    s = sub.add_parser('next', help='lease the next ready task and print its context'); s.set_defaults(fn=cmd_next)
    s.add_argument('--worker'); s.add_argument('--module'); s.add_argument('--max-size', type=int)
    s.add_argument('--min-size', type=int)

    s = sub.add_parser('context', help='task context, symbol lookup or header search'); s.set_defaults(fn=cmd_context)
    s.add_argument('task', nargs='?'); s.add_argument('--callers', action='store_true')
    s.add_argument('--symbol'); s.add_argument('--grep', metavar='REGEX')
    s.add_argument('--worker', help=argparse.SUPPRESS)

    for name, fn in (('check', cmd_check), ('submit', cmd_submit)):
        s = sub.add_parser(name, help=f'{name} a candidate source file'); s.set_defaults(fn=fn)
        s.add_argument('task'); s.add_argument('file', help="candidate .cpp/.c ('-' for stdin)")
        s.add_argument('--symbol', help='function to compare when the file defines several')
        s.add_argument('--worker')
        s.add_argument('--profile', default='default', choices=sorted(CONFIG['profiles']),
                       help='compiler profile (SDK code often needs O4p or an older compiler)')
        if name == 'check':
            s.add_argument('--json', action='store_true'); s.add_argument('--verbose', action='store_true')
        else:
            s.add_argument('--subsystem', default='Unclassified', choices=CONFIG['subsystems'],
                           help='src/ subdirectory; the module directory (ov017, itcm) is added automatically')
            s.add_argument('--note', help='evidence for the chosen name/types')

    s = sub.add_parser('release', help='give a leased task back with notes'); s.set_defaults(fn=cmd_release)
    s.add_argument('task'); s.add_argument('--note'); s.add_argument('--worker')

    s = sub.add_parser('status', help='progress summary'); s.set_defaults(fn=cmd_status)
    s.add_argument('--leases', action='store_true'); s.add_argument('--worker', help=argparse.SUPPRESS)

    s = sub.add_parser('autosolve', help='submit empty/constant-return functions automatically')
    s.set_defaults(fn=cmd_autosolve); s.add_argument('--dry-run', action='store_true')

    s = sub.add_parser('integrate', help='integrate submitted functions (single coordinator)')
    s.set_defaults(fn=cmd_integrate)
    s.add_argument('--limit', type=int, default=50); s.add_argument('--dry-run', action='store_true')

    args = p.parse_args(argv)
    if args.command == 'context' and not (args.task or args.symbol or args.grep):
        p.error('context needs a task, --symbol or --grep')
    return args.fn(Project(args.project), args) or 0


if __name__ == '__main__':
    sys.exit(main())
