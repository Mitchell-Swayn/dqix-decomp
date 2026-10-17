"""Single-coordinator integration of submitted functions with full ROM acceptance.

A batch is installed (source, delink range, symbol rename, reference rename,
naming registry), then configure + `ninja rom check report sha1` runs once.
On failure the batch is rolled back and bisected; failing functions return to
the open pool with the build log tail as a note.
"""
import contextlib
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import time

from state import CONFIG, log
from verify import check

COMMENT = '// Original: {module} @ 0x{address:08X}; symbol: {old}; size: 0x{size:X}.\n'
SOURCE_SUFFIXES = ('.c', '.cpp', '.h', '.hpp')


@contextlib.contextmanager
def project_lock(project):
    path = project.root / 'build/progress/integration-process.lock'
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('a') as stream:
        fcntl.flock(stream, fcntl.LOCK_EX)
        try:
            yield
        finally:
            fcntl.flock(stream, fcntl.LOCK_UN)


class Files:
    """Records original contents of every touched file so a batch can be undone exactly."""

    def __init__(self, root):
        self.root, self.saved = root, {}

    def write(self, path, text):
        path = self.root / path
        if path not in self.saved:
            self.saved[path] = path.read_bytes() if path.exists() else None
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def read(self, path):
        return (self.root / path).read_text()

    def rollback(self):
        for path, data in self.saved.items():
            if data is None:
                path.unlink(missing_ok=True)
            else:
                path.write_bytes(data)
        self.saved = {}


def word_sub(text, old, new):
    return re.sub(rf'(?<![\w$]){re.escape(old)}(?![\w$])', new, text)


def source_files(root):
    for base in ('src', 'include'):
        for path in (root / base).rglob('*'):
            if path.suffix in SOURCE_SUFFIXES and 'AssemblyFallback' not in path.parts and path.is_file():
                yield path


# Inventories/registries that do not feed the build; stale names there are harmless.
REFERENCE_ONLY = {'function_names.json', 'function_naming.json', 'source_layout.json', 'source_units.json',
                  'assembly_fallbacks.json', 'sdk_function_candidates.json'}


def protected_names(root):
    """Text of build-affecting configuration; functions named there keep their original symbol."""
    text = ''
    for path in (root / 'config/usa').rglob('*.json'):
        if path.name not in REFERENCE_ONLY:
            text += path.read_text(errors='replace')
    return text


def delink_basenames(root):
    """DSD requires delink source file names to be unique across every module."""
    names = set()
    for path in (root / 'config/usa/arm9').rglob('delinks.txt'):
        for line in path.read_text().splitlines():
            if line and not line[0].isspace() and line.rstrip().endswith(':'):
                names.add(Path(line.rstrip()[:-1]).stem.lower())
    return names


def plan(project, db, task, protected, basenames):
    """Prepare one install, re-verifying the submitted source against current names."""
    text = task['source']
    for old, new in db.execute('SELECT old,new FROM renames'):
        text = word_sub(text, old, new)
    old, new = task['name'], task['symbol']
    if new != old and re.search(rf'(?<![\w$]){re.escape(old)}(?![\w$])', protected):
        text, new = word_sub(text, new, old), old  # Keep the configured identity.
    elif new != old:
        text = word_sub(text, old, new)  # Self-references (recursion) follow the rename.
    from build import text_ranges
    if not any(a <= task['address'] and task['address'] + task['size'] <= b
               for a, b in text_ranges(project.config_dir(task['module']))):
        return None, 'outside the module .text section (.init/.ctor units need the existing tools)'
    result = check(project, db, task, text, new, task['suffix'] or '.cpp', profile=task['profile'] or 'default')
    if result['status'] != 'match':
        return None, f"re-check failed: {result['problems'][:3] or result.get('messages', [])[:3]}"
    module_dir = task['module'].split('/')[1]
    sub = Path('src') / (task['subsystem'] or 'Unclassified')
    if module_dir != 'main':
        sub = sub / module_dir
    path = sub / f"{new}{task['suffix'] or '.cpp'}"
    if (project.root / path).exists() or new.lower() in basenames:
        return None, f'source file name {new} already used by another unit; choose a distinct name'
    comment = COMMENT.format(module=task['module'], address=task['address'], old=old, size=task['size'])
    if 'Original:' not in text:
        m = re.search(rf'^[^\n;]*\b{re.escape(new)}\s*\([^;]*?\)\s*\{{', text, re.M)
        text = text[:m.start()] + comment + text[m.start():] if m else comment + text
    return dict(task=task, path=path.as_posix(), text=text, old=old, new=new), None


def install(project, files, items):
    root = project.root
    registry_path = Path('config/usa/function_names.json')
    registry = json.loads(files.read(registry_path)) if (root / registry_path).exists() else \
        {'schema_version': 1, 'functions': {}}
    renames = {i['old']: i['new'] for i in items if i['old'] != i['new']}
    for item in items:
        t = item['task']
        files.write(item['path'], item['text'])
        cdir = project.config_dir(t['module']).relative_to(root)
        delinks = files.read(cdir / 'delinks.txt').rstrip('\n')
        delinks += (f"\n\n{item['path']}:\n    complete\n"
                    f"    .text start:0x{t['address']:08x} end:0x{t['address'] + t['size']:08x}\n")
        files.write(cdir / 'delinks.txt', delinks)
        if item['old'] != item['new']:
            symbols = files.read(cdir / 'symbols.txt')
            pattern = rf'(?m)^{re.escape(item["old"])}(?= kind:function\([^)]*\) addr:0x{t["address"]:08x}\b)'
            symbols, n = re.subn(pattern, item['new'], symbols)
            if n != 1:
                raise RuntimeError(f"symbols.txt entry for {item['old']} not found exactly once")
            files.write(cdir / 'symbols.txt', symbols)
            registry['functions'][t['id']] = dict(
                function_id=t['id'], module=t['module'].split('/')[1], address=f"0x{t['address']:08X}",
                old_symbol=item['old'], new_symbol=item['new'], source=item['path'],
                evidence=dict(status='swarm', worker=t['worker'], note=(t['notes'] or '').strip()[-500:]))
    if renames:
        rx = re.compile(r'(?<![\w$])(' + '|'.join(map(re.escape, renames)) + r')(?![\w$])')
        new_paths = {i['path'] for i in items}
        for path in source_files(root):
            rel = path.relative_to(root).as_posix()
            if rel in new_paths:
                continue
            text = path.read_text(errors='replace')
            if rx.search(text):
                files.write(rel, rx.sub(lambda m: renames[m[1]], text))
        files.write(registry_path, json.dumps(registry, indent=2) + '\n')
    profiled = [i for i in items if (i['task']['profile'] or 'default') != 'default']
    if profiled:  # configure.py builds these sources with the recorded compiler and flags.
        policy_path = Path('config/usa/compiler_profiles.json')
        policy = json.loads(files.read(policy_path))
        for item in profiled:
            name = item['task']['profile']
            executable, flags, field = project.compiler(name)
            policy['sources'][item['path']] = dict(
                version=CONFIG['profiles'][name]['version'], executable=field,
                executable_sha256=hashlib.sha256(executable.read_bytes()).hexdigest(), source=item['path'],
                flags=flags + ['-i', 'include'], origin=f'swarm profile {name}; exact bytes and relocations verified')
        files.write(policy_path, json.dumps(policy, indent=2) + '\n')
    sync_keep_symbols(project, files, renames, [i['new'] for i in items if not i['task']['referenced']])


def sync_keep_symbols(project, files, renames, batch_unreferenced):
    """List new units' unreferenced functions; generate_lcf.py emits them as FORCEACTIVE.

    MWLD runs with -dead and its command-line force_active list is limited to 255 characters.
    """
    keep = Path('config/usa/keep_symbols.txt')
    old = files.read(keep).splitlines() if (project.root / keep).exists() else \
        ['# Reconstructed functions without unambiguous references (FORCEACTIVE against -dead).']
    lines = [l if l.startswith('#') else renames.get(l, l) for l in old if l]
    lines += [n for n in batch_unreferenced if n not in lines]
    if lines != [l for l in old if l]:
        files.write(keep, '\n'.join(lines) + '\n')


def run_build(project, log_path):
    c = CONFIG['container']
    cmd = c['configure'] + ''.join(f' --keep-symbol {k}' for k in CONFIG['keep_symbols']) + ' && ' + c['build']
    docker = ['sudo', '-n', 'docker', 'run', '--rm', '--user', f'{os.getuid()}:{os.getgid()}',
              '-v', f'{project.root}:/bench/project', '-v', f'{project.inputs}:/inputs:ro',
              '-w', '/bench/project', c['image'], 'bash', '-c', cmd]
    started = time.monotonic()
    with open(log_path, 'w') as out:
        code = subprocess.run(docker, stdout=out, stderr=subprocess.STDOUT).returncode
    return code, time.monotonic() - started


def accepted(project, items, before):
    report = json.loads((project.root / 'build/usa/report.json').read_text())
    after = report['measures']
    for key in ('total_code', 'total_functions', 'total_data'):
        if str(after[key]) != str(before[key]):
            return f'denominator {key} changed {before[key]} -> {after[key]}'
    units = {u['name']: u for u in report['units']}
    for item in items:
        unit = units.get(item['path'].rsplit('.', 1)[0])
        fns = {f['name']: f for f in (unit or {}).get('functions', [])}
        if item['new'] not in fns or fns[item['new']].get('fuzzy_match_percent') != 100:
            return f"{item['new']} not 100% matched in report"
    gained = int(after['matched_functions']) - int(before['matched_functions'])
    if gained != len(items):
        return f'matched_functions gained {gained}, expected {len(items)}'
    return None


def tail(path, lines=12):
    text = [l for l in Path(path).read_text(errors='replace').splitlines() if 'warning' not in l]
    errors = [l for l in text if re.search(r'error|FAILED|mismatch|differ|panicked|not found', l, re.I)]
    return '\n'.join((errors or text)[-lines:])


def integrate(project, limit, dry_run=False):
    db = project.connect()
    run_dir = project.state / 'integrate' / time.strftime('%Y%m%dT%H%M%S')
    run_dir.mkdir(parents=True)
    summary = dict(run=str(run_dir), integrated=[], rejected=[], builds=[])
    with project_lock(project):
        rows = db.execute("SELECT * FROM tasks WHERE status='submitted' ORDER BY updated LIMIT ?",
                          (limit,)).fetchall()
        protected = protected_names(project.root)
        basenames = delink_basenames(project.root)
        items = []
        for task in rows:
            item, error = plan(project, db, task, protected, basenames)
            if error:
                reject(db, task, error, summary)
            else:
                items.append(item)
        names = [i['new'].lower() for i in items]
        dupes = {n for n in names if names.count(n) > 1}
        for item in [i for i in items if i['new'].lower() in dupes][1:]:
            items.remove(item); reject(db, item['task'], f"name {item['new']} duplicated in batch", summary)
        if dry_run or not items:
            summary['planned'] = [(i['task']['id'], i['path']) for i in items]
            return summary
        before_path = project.root / 'build/usa/report.json'
        before = json.loads(before_path.read_text())['measures']
        state = dict(before=before, clean=True)
        good = bisect(project, db, items, state, summary, run_dir, top=True)
        if not state['clean']:  # Last build was of a rejected subset; rebuild the accepted tree.
            code, seconds = run_build(project, run_dir / 'final.log')
            summary['builds'].append(dict(label='final', ok=code == 0, seconds=round(seconds, 1)))
            if code:
                raise RuntimeError(f'final rebuild failed; see {run_dir / "final.log"}')
        summary['matched_functions_gained'] = len(good)
    return summary


def current_names(db, items):
    """Rename references between new sources: earlier commits and other members of this subset."""
    renames = {old: new for old, new in db.execute('SELECT old,new FROM renames')}
    renames.update({i['old']: i['new'] for i in items if i['old'] != i['new']})
    for item in items:
        base = item.setdefault('planned', item['text'])  # Recompute per subset: members may be rejected.
        own = {k: v for k, v in renames.items() if k != item['old']}  # Keep the Original: comment.
        rx = own and re.compile(r'(?<![\w$])(' + '|'.join(map(re.escape, own)) + r')(?![\w$])')
        item['text'] = rx.sub(lambda m: own[m[1]], base) if rx else base


def bisect(project, db, items, state, summary, run_dir, top=False):
    files = Files(project.root)
    label = f'{len(summary["builds"]):03d}-n{len(items)}'
    current_names(db, items)
    try:
        install(project, files, items)
        code, seconds = run_build(project, run_dir / f'{label}.log')
        problem = f'build exited {code}: {tail(run_dir / f"{label}.log")}' if code else \
            accepted(project, items, state['before'])
    except Exception as error:  # Install failure: undo and treat as rejection.
        code, seconds, problem = -1, 0, f'install failed: {error}'
    summary['builds'].append(dict(label=label, ok=not problem, seconds=round(seconds, 1)))
    if not problem:
        commit(db, items, summary)
        state['before'] = json.loads((project.root / 'build/usa/report.json').read_text())['measures']
        state['clean'] = True
        return items
    files.rollback()
    state['clean'] = False
    if top:  # Distinguish a broken starting tree from bad submissions before rejecting anything.
        code, seconds = run_build(project, run_dir / 'baseline.log')
        summary['builds'].append(dict(label='baseline', ok=code == 0, seconds=round(seconds, 1)))
        if code:
            raise RuntimeError(f'starting tree does not build; nothing rejected. See {run_dir / "baseline.log"}')
        state['before'] = json.loads((project.root / 'build/usa/report.json').read_text())['measures']
        state['clean'] = True
    if len(items) == 1:
        reject(db, items[0]['task'], problem, summary)
        return []
    half = len(items) // 2
    return bisect(project, db, items[:half], state, summary, run_dir) + \
        bisect(project, db, items[half:], state, summary, run_dir)


def commit(db, items, summary):
    db.execute('BEGIN IMMEDIATE')
    for item in items:
        t = item['task']
        db.execute("UPDATE tasks SET status='integrated', symbol=?, source=?, updated=? WHERE id=?",
                   (item['new'], item['text'], time.time(), t['id']))
        if item['old'] != item['new']:
            db.execute('UPDATE symbols SET name=? WHERE module=? AND address=? AND name=?',
                       (item['new'], t['module'], t['address'], item['old']))
            db.execute('INSERT OR REPLACE INTO renames VALUES(?,?,?)', (t['module'], item['old'], item['new']))
        m = re.search(rf'^([^\n;{{}}]*\b{re.escape(item["new"])}\s*\([^;{{}}]*\))\s*\{{', item['text'], re.M)
        if m:
            db.execute('INSERT OR REPLACE INTO decls VALUES(?,?,?)',
                       (item['new'], ' '.join(m[1].split()) + ';', item['path']))
        log(db, 'integrated', t['id'], t['worker'], path=item['path'])
        summary['integrated'].append(dict(task=t['id'], symbol=item['new'], path=item['path']))
    db.execute('COMMIT')


def reject(db, task, reason, summary):
    stamp = time.strftime('%Y-%m-%d %H:%M')
    db.execute("UPDATE tasks SET status='open', worker=NULL, gave_up=gave_up+1, notes=notes || ?, updated=? "
               "WHERE id=?", (f'[{stamp} integrator] rejected: {reason[:600]}\n', time.time(), task['id']))
    log(db, 'rejected', task['id'], task['worker'], reason=reason[:2000])
    summary['rejected'].append(dict(task=task['id'], reason=reason[:300]))
