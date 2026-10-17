"""Build the task database from the evidence inventory and current project ownership."""
import json
from pathlib import Path
import re
import sqlite3
import sys
import time

import disasm
from state import CONFIG, log, module_from_reloc

SYMBOL = re.compile(r'(\S+)\s+kind:(\w+)(?:\(([^)]*)\))?.*?\saddr:0x([0-9a-fA-F]+)')
RELOC = re.compile(r'from:0x([0-9a-fA-F]+)\s+kind:(\w+)\s+to:0x([0-9a-fA-F]+)\s+module:(\S+)')
RANGE = re.compile(r'^\s*\.(\w+)\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)')
DECL = re.compile(r'(?m)^[ \t]*((?:extern[ \t]+"C"[ \t]+)?(?:[A-Za-z_][\w:<>]*[ \t\*&]+)+?'
                  r'([A-Za-z_]\w*)[ \t]*\(([^;{}()]*(?:\([^()]*\)[^;{}()]*)*)\))[ \t]*(?:const[ \t]*)?([;{])')
SOURCE_SUFFIXES = {'.c', '.cpp', '.h', '.hpp'}


def parse_symbols(path):
    for line in path.read_text().splitlines():
        m = SYMBOL.match(line)
        if not m:
            continue
        name, kind, args, addr = m[1], m[2], m[3] or '', int(m[4], 16)
        mode = size = None
        if kind == 'function':
            parts = dict(p.split('=', 1) if '=' in p else (p, None) for p in args.split(','))
            mode = 'thumb' if 'thumb' in parts else 'arm'
            size = int(parts['size'], 16) if parts.get('size') else None
        yield name, addr, kind, mode, size


def text_ranges(config_dir):
    """[start,end) of the module's .text sections from the delinks.txt header.

    Other code sections (.init static initialisers with .ctor entries) cannot be split
    into single-function units.
    """
    head = (config_dir / 'delinks.txt').read_text().split('\n\n')[0]
    return [(int(a, 16), int(b, 16)) for name, a, b in
            re.findall(r'^\s+(\S+)\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)', head, re.M) if name == '.text']


def owned_ranges(config_dir, complete_only=False):
    """Source-owned [start,end) ranges from a module's delinks.txt (header excluded).

    Incomplete units still own their ranges for DSD but are not built or matched.
    """
    blocks, owner = {}, None
    for line in (config_dir / 'delinks.txt').read_text().splitlines():
        if line and not line[0].isspace():
            owner = line.rstrip().rstrip(':') if line.rstrip().endswith(':') else None
            if owner:
                blocks[owner] = dict(complete=False, ranges=[])
            continue
        if owner and line.strip() == 'complete':
            blocks[owner]['complete'] = True
        m = RANGE.match(line)
        if owner and m:
            blocks[owner]['ranges'].append((int(m[2], 16), int(m[3], 16), m[1], owner))
    return [r for b in blocks.values() if b['complete'] or not complete_only for r in b['ranges']]


def scan_decls(root, known):
    """First declaration/definition text for every known symbol name in src/ and include/."""
    found = {}
    files = sorted(p for d in ('include', 'src') for p in (root / d).rglob('*')
                   if p.suffix in SOURCE_SUFFIXES and 'AssemblyFallback' not in p.parts)
    for path in files:
        text = path.read_text(errors='replace')
        for m in DECL.finditer(text):
            name = m[2]
            if name not in known or name in found and found[name][2] == '{':
                continue
            decl = ' '.join(m[1].split())
            line = text.count('\n', 0, m.start()) + 1
            # Prefer definitions (matched source) over bare declarations.
            if name not in found or m[4] == '{':
                found[name] = (decl + ';', f'{path.relative_to(root)}:{line}', m[4])
    return {k: v[:2] for k, v in found.items()}


def symbolize(index, modules, address):
    """Best symbol name for an address within candidate modules: exact, else nearest data + offset."""
    best = None
    for module in modules:
        rows = index.get(module, ())
        exact = rows.get(address) or rows.get(address & ~1)
        if exact:
            return exact
    return best or f'{address:#010x}'


SYSTEM_MNEMONICS = {'svc', 'swi', 'mrc', 'mcr', 'mrs', 'msr', 'cdp', 'ldc', 'stc'}


def sdk_hints(root):
    """function id -> (hint lines, assembly-only reference) from the advisory SDK inventory."""
    path = root / 'config/usa/sdk_function_candidates.json'
    out = {}
    if not path.exists():
        return out
    for f in json.loads(path.read_text())['functions']:
        lines, c_forms = [], 0
        for c in f['sdk_candidates'][:3]:
            defs = c.get('reconstructed_definitions', [])
            c_forms += sum(d['source_form'] == 'c' for d in defs)
            ref = next((d['url'] for d in defs if d['source_form'] == 'c'), None) or c.get('assembly_url') or c['path']
            lines.append(f"SDK reference ({f['confidence']}, similarity {f['similarity']:.2f}): {c['name']}  {ref}")
        out[f['id']] = (lines, c_forms == 0)
    return out


def classify(listing, sdk):
    """Hints and whether the routine is probably hand-written assembly (not a C target)."""
    lines, asm_only = sdk or ([], False)
    hints = list(lines)
    used = {l.split(':', 1)[1].split()[0] for l in listing.splitlines() if ':' in l and l.split(':', 1)[1].split()}
    system = sorted(used & SYSTEM_MNEMONICS)
    if system:
        hints.append(f"uses {', '.join(system)}: probably hand-written assembly")
    if lines and asm_only:
        hints.append('SDK reference exists only as assembly: probably not a C target')
    ops = [l.split(':', 1)[1].split()[0] for l in listing.splitlines()
           if ':' in l and l.split(':', 1)[1].split() and not l.split(':', 1)[1].split()[0].startswith('.')]
    block = sum(o.startswith(('ldm', 'stm')) for o in ops)
    leaf = not any(o in ('bl', 'blx') for o in ops)
    transfer = leaf and len(ops) >= 4 and block * 2 >= len(ops) - 1
    if transfer:
        hints.append('leaf made mostly of ldm/stm block transfers: likely SDK assembly')
    first = ops[0] if ops else ''
    tail = first.startswith('pop') or (first == 'add' and ' sp, sp' in listing.splitlines()[0]) or \
        first.startswith('ldm') and 'sp!' in listing.splitlines()[0]
    if tail and not any(o.startswith('push') for o in ops):
        hints.append('starts by restoring a caller frame: shared epilogue tail, not a standalone C function')
    if ops == ['ldr', 'bx'] and 'bx       ip' in listing:
        target = listing.rsplit('-> ', 1)[-1].strip() if '-> ' in listing else 'the loaded function'
        hints.append(f'tail call: a C forwarder compiles to ldr ip/bx ip, e.g. '
                     f'extern "C" void Name(params) {{ {target}(params); }}')
    if ops == ['bx']:
        hints.append('empty function: extern "C" void Name(void) {}')
    return '\n'.join(hints), int(bool(system) or (bool(lines) and asm_only) or transfer or
                                 (tail and not any(o.startswith('push') for o in ops)))


def render_listing(code, address, mode, module, reloc_rows, index):
    lines = []
    for offset, size, text in disasm.listing(code, address, mode):
        site = address + offset
        r = reloc_rows.get(site)
        if r:
            kind, target, tmods = r
            text += f'   ; {kind} -> {symbolize(index, tmods, target)}'
        lines.append(f'{site:08X}: {text}')
    return '\n'.join(lines)


def build(project, evidence=None, force=False):
    root = project.root
    started = time.monotonic()
    evidence = Path(evidence) if evidence else next(
        p for p in (root / 'build/evidence/functions.sqlite', root / 'inventory/functions.sqlite') if p.exists())
    src = sqlite3.connect(f'file:{evidence}?mode=ro', uri=True)
    src.row_factory = sqlite3.Row
    tables = {r[0] for r in src.execute("SELECT name FROM sqlite_master WHERE type='table'")}
    missing = {'functions', 'relationships', 'ghidra_analysis'} - tables
    if missing:
        raise SystemExit(f'{evidence} lacks {", ".join(sorted(missing))}; pass --evidence')
    previous, events = {}, []
    if project.db_path.exists():
        if not force:
            raise SystemExit(f'{project.db_path} exists; pass --force to rebuild (task progress is preserved)')
        old = project.connect()
        previous = {r['id']: dict(r) for r in old.execute(
            "SELECT * FROM tasks WHERE status!='open' OR checks>0 OR notes!=''")}
        renames = old.execute('SELECT * FROM renames').fetchall()
        events = old.execute('SELECT * FROM events').fetchall()
        old.close()
        for suffix in ('', '-wal', '-shm'):
            Path(str(project.db_path) + suffix).unlink(missing_ok=True)
    else:
        renames = []
    db = project.connect(create=True)
    db.execute('BEGIN')
    db.executemany('INSERT INTO renames VALUES(?,?,?)', [tuple(r) for r in renames])
    db.executemany('INSERT INTO events VALUES(?,?,?,?,?)', [tuple(r) for r in events])

    # Symbols and relocations for every configured ARM9 module.
    index, sym_rows, relocs = {}, [], {}
    for module in CONFIG['modules']:
        cdir = project.config_dir(module)
        if not (cdir / 'symbols.txt').exists():
            continue
        names = index.setdefault(module, {})
        for name, addr, kind, mode, size in parse_symbols(cdir / 'symbols.txt'):
            sym_rows.append((module, name, addr, kind, mode, size))
            names.setdefault(addr, name)
        rows = relocs.setdefault(module, {})
        if (cdir / 'relocs.txt').exists():
            for line in (cdir / 'relocs.txt').read_text().splitlines():
                m = RELOC.match(line)
                if m:
                    rows[int(m[1], 16)] = (m[2], int(m[3], 16), module_from_reloc(m[4]))
    db.executemany('INSERT OR IGNORE INTO symbols VALUES(?,?,?,?,?,?)', sym_rows)
    db.executemany('INSERT INTO relocs VALUES(?,?,?,?,?)', [
        (module, site, kind, target, ','.join(tmods)) for module, rows in relocs.items()
        for site, (kind, target, tmods) in rows.items()])
    # A function is referenced only by relocations that unambiguously target its module;
    # calls into overlay groups resolve elsewhere and do not stop MWLD dead-stripping.
    referenced = {(tmods[0], t & ~1) for rows in relocs.values() for kind, t, tmods in rows.values()
                  if len(tmods) == 1}

    sys.path.insert(0, str(root / 'tools'))
    try:
        from runtime_support import excluded
        runtime = excluded(root)
    except Exception:
        runtime = set()

    functions = {(m, a): (n, mode, size) for m, n, a, k, mode, size in sym_rows if k == 'function'}
    extents = {}
    for m, n, a, k, mode, size in sym_rows:
        if k == 'function' and size:
            extents.setdefault(m, []).append((a, a + size))
    for rows in extents.values():
        rows.sort()

    def overlapped(module, start, end):
        """Another function symbol's extent covers part of this range (DSD refuses the split)."""
        import bisect
        rows = extents.get(module, [])
        i = bisect.bisect_left(rows, (start, end))
        return any(a < end and start < b and (a, b) != (start, end) for a, b in rows[max(0, i - 8):i + 8])
    pseudo = {}
    for row in src.execute('SELECT function_id, document FROM ghidra_analysis'):
        try:
            pseudo[row[0]] = json.loads(row[1]).get('pseudocode')
        except ValueError:
            pass
    hints = sdk_hints(root)
    tasks, skipped = [], {}
    for module in CONFIG['modules']:
        cdir = project.config_dir(module)
        if not (cdir / 'delinks.txt').exists():
            continue
        owned = owned_ranges(cdir)
        complete = owned_ranges(cdir, complete_only=True)
        text = text_ranges(cdir)
        for row in src.execute('SELECT * FROM functions WHERE module_id=? AND size>0 ORDER BY address', (module,)):
            start, end = row['address'], row['address'] + row['size']
            reason = None
            if any(a < end and start < b for a, b, _, _ in owned):
                if not any(a < end and start < b for a, b, _, _ in complete):
                    skipped['in_incomplete_unit'] = skipped.get('in_incomplete_unit', 0) + 1
                continue  # Owned by a source unit.
            current = functions.get((module, start))
            if not any(a <= start and end <= b for a, b in text):
                reason = 'outside_text_section'
            elif (module, start) in runtime:
                reason = 'runtime_support'
            elif not current:
                reason = 'no_symbol'
            elif current[2] != row['size']:
                reason = 'size_differs_from_symbols'
            elif overlapped(module, start, end):
                reason = 'overlaps_other_symbol'
            if reason:
                skipped[reason] = skipped.get(reason, 0) + 1
                continue
            name, mode, size = current
            listing = render_listing(row['original_bytes'], start, mode, module, relocs.get(module, {}), index)
            hint, asm_likely = classify(listing, hints.get(row['id']))
            tasks.append((row['id'], module, name, start, size, mode, row['original_bytes'], listing,
                          pseudo.get(row['id']), int((module, start) in referenced), hint, asm_likely))
    db.executemany('INSERT INTO tasks(id,module,name,address,size,mode,original,listing,pseudocode,referenced,'
                   'hints,asm_likely) VALUES(?,?,?,?,?,?,?,?,?,?,?,?)', tasks)
    for tid, old in previous.items():
        db.execute('UPDATE tasks SET status=?,worker=?,lease_until=?,checks=?,best=?,gave_up=?,notes=?,source=?,'
                   'symbol=?,subsystem=?,profile=?,suffix=?,updated=? WHERE id=?',
                   (old['status'], old['worker'], old['lease_until'], old['checks'], old['best'], old['gave_up'],
                    old['notes'], old['source'], old['symbol'], old['subsystem'], old.get('profile'),
                    old.get('suffix'), old['updated'], tid))
    db.executemany('INSERT OR IGNORE INTO edges VALUES(?,?)', src.execute(
        'SELECT caller_id, callee_id FROM relationships WHERE caller_id!=callee_id'))
    known = {r[1] for r in sym_rows if r[3] == 'function'}
    decls = scan_decls(root, known)
    db.executemany('INSERT INTO decls VALUES(?,?,?)', [(k, d, p) for k, (d, p) in decls.items()])
    meta = dict(built=time.time(), evidence=str(evidence), capstone=disasm.available(), tasks=len(tasks),
                asm_likely=sum(t[-1] for t in tasks),
                skipped=skipped, report_measures=_measures(root))
    db.executemany('INSERT OR REPLACE INTO meta VALUES(?,?)', [(k, json.dumps(v)) for k, v in meta.items()])
    log(db, 'build', tasks=len(tasks), skipped=skipped)
    db.execute('COMMIT')
    return dict(tasks=len(tasks), asm_likely=sum(t[-1] for t in tasks), skipped=skipped, declarations=len(decls), symbols=len(sym_rows),
                capstone=disasm.available(), seconds=round(time.monotonic() - started, 2), db=str(project.db_path))


def _measures(root):
    path = root / 'build/usa/report.json'
    return json.loads(path.read_text())['measures'] if path.exists() else None
