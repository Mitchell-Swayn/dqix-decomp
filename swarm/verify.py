"""Compile one candidate and prove it against the original bytes and relocations.

No link is needed: every relocation the candidate emits is resolved through the
project's symbol tables and compared with the original relocation at that site
(call targets via relocs.txt, literal-pool words via the original word value).
Every original relocation in the range must be produced by the candidate.
"""
import difflib
import os
from pathlib import Path
import shutil
import struct
import subprocess
import time
import uuid

import disasm
from elf import Elf, SHN_UNDEF, STT_FUNC, STT_SECTION
from state import CONFIG

R_ARM_PC24, R_ARM_ABS32, R_ARM_THM_CALL, R_ARM_CALL, R_ARM_JUMP24, R_ARM_V4BX = 1, 2, 10, 28, 29, 40
ARM_CALLS = {R_ARM_PC24, R_ARM_CALL, R_ARM_JUMP24}


def compile_source(project, source_text, suffix='.cpp', include_dir=None, profile='default'):
    """Compile in an isolated scratch directory; returns (object bytes | None, messages)."""
    work = project.state / 'tmp' / f'{os.getpid()}-{uuid.uuid4().hex[:8]}'
    work.mkdir(parents=True)
    try:
        src = work / ('candidate' + suffix)
        src.write_text(source_text)
        obj = work / 'candidate.o'
        executable, flags, _ = project.compiler(profile)
        cmd = [str(project.inputs / CONFIG['wibo']), str(executable), *flags, '-i', 'include',
               *(['-i', str(include_dir)] if include_dir else []),
               '-c', str(src.relative_to(project.root)), '-o', str(obj.relative_to(project.root))]
        if suffix == '.c':
            cmd = [c for c in cmd if c != '-lang=c++'] + ['-lang=c']
        run = subprocess.run(cmd, cwd=project.root, capture_output=True, text=True, timeout=60)
        messages = (run.stdout + run.stderr).replace(str(src.relative_to(project.root)), 'candidate' + suffix)
        if run.returncode or not obj.exists():
            return None, messages
        return obj.read_bytes(), messages
    finally:
        shutil.rmtree(work, ignore_errors=True)


def resolve(db, name, modules):
    """Symbol name -> list of (address, kind, mode) in the allowed modules (old names follow renames)."""
    names = {name} | {r[0] for r in db.execute('SELECT new FROM renames WHERE old=?', (name,))}
    rows = []
    for n in names:
        rows += db.execute('SELECT module,address,kind,mode FROM symbols WHERE name=?', (n,)).fetchall()
    return [(r['address'], r['kind'], r['mode']) for r in rows if not modules or r['module'] in modules]


def check(project, db, task, source_text, symbol=None, suffix='.cpp', include_dir=None, profile='default'):
    started = time.perf_counter()
    result = dict(task=task['id'], status='error', problems=[], warnings=[], profile=profile)
    data, messages = compile_source(project, source_text, suffix, include_dir, profile)
    result['compile_ms'] = round((time.perf_counter() - started) * 1000)
    if data is None:
        result.update(status='compile_error', messages=_trim(messages, 25))
        return result
    elf = Elf(data)
    functions = elf.functions()
    chosen = None
    if symbol:
        chosen = next((f for f in functions if f['name'] == symbol), None)
        if not chosen:
            result['problems'].append(f'symbol {symbol!r} not defined; defined: {[f["name"] for f in functions]}')
            return result
    else:
        strong = [f for f in functions if f['bind'] == 1]
        if len(strong) == 1:
            chosen = strong[0]
        else:
            chosen = next((f for f in functions if f['name'] == task['name']), None)
        if not chosen:
            result['problems'].append('define exactly one global function (or pass --symbol); found '
                                      f'{[f["name"] for f in functions]}')
            return result
    strong = [f['name'] for f in functions if f is not chosen and f['bind'] == 1]
    weak = [f['name'] for f in functions if f is not chosen and f['bind'] != 1]
    clashing = [n for n in strong if db.execute('SELECT 1 FROM symbols WHERE name=?', (n,)).fetchone()]
    if clashing:
        result['problems'].append(f'also defines existing functions {clashing}; declare them extern instead')
    elif strong:  # e.g. C++ base/complete destructor variants; unreferenced copies are dead-stripped.
        result['warnings'].append(f'also emits global functions {strong}; integration verifies they are unused')
    if weak:
        result['warnings'].append(f'also emitted (unused inline/static copies are dead-stripped): {weak}')
    # Global data would occupy new space in the ROM; unreferenced local data is dead-stripped.
    data = {s['index'] for s in elf.sections if s['flags'] & 2 and not s['flags'] & 4 and s['size']}
    exported = [s['name'] for s in elf.symbols if s['shndx'] in data and s['bind'] in (1, 2) and s['name']]
    if exported:
        result['problems'].append(f'defines global data {exported}; reference original data via extern symbols')
    result['symbol'] = chosen['name']
    section = elf.sections[chosen['shndx']]
    start = chosen['value'] & ~1
    thumb = bool(chosen['value'] & 1) or any(
        s['name'] == '$t' and s['shndx'] == chosen['shndx'] and s['value'] <= start for s in elf.symbols)
    code = elf.raw(section)[start:start + chosen['size']]
    original = task['original']
    mode = 'thumb' if thumb else 'arm'
    result.update(size=len(code), original_size=len(original))
    if mode != task['mode']:
        result['problems'].append(f'mode is {mode}; original is {task["mode"]} (use {task["mode"].upper()} after the include)')

    base, module = task['address'], task['module']
    # Relocation sites are compared by offset, which is meaningless once the sizes differ.
    aligned = len(code) == len(original)
    orig_relocs = {r['site']: r for r in db.execute(
        'SELECT site,kind,target,target_modules FROM relocs WHERE module=? AND site>=? AND site<?',
        (module, base, base + len(original)))}
    masks, covered, notes_c, notes_o = {}, set(), {}, {}
    for site, r in orig_relocs.items():
        notes_o[site - base] = f'{r["kind"]} -> {_name(db, r)}'
    for rel in elf.relocations.get(chosen['shndx'], []):
        off = rel['offset'] - start
        if not 0 <= off < len(code) or rel['type'] == R_ARM_V4BX:
            continue
        sym = rel['symbol']
        label = sym['name'] or '?'
        notes_c[off] = f'-> {label}{rel["addend"]:+#x}' if rel['addend'] and rel['type'] == R_ARM_ABS32 else f'-> {label}'
        orig = orig_relocs.get(base + off)
        if orig is None:  # relocs.txt is incomplete; prove the linked value from the original encoding.
            orig = _implied_reloc(rel['type'], original, off, base, task['mode'])
            if orig is None:
                if aligned:
                    result['problems'].append(f'+{off:#x}: candidate relocates to {label}; original has a plain value here')
                continue
            orig['target_modules'] = ','.join(CONFIG['modules'])
        covered.add(base + off)
        modules = orig['target_modules'].split(',') if orig['target_modules'] else []
        if sym['shndx'] != SHN_UNDEF and sym['bind'] != 2:  # Weak inline copies resolve like externals.
            if sym is chosen or (sym['name'] == chosen['name']):
                targets = [(base, 'function', task['mode'])]
            elif sym['type'] == STT_FUNC:
                result['problems'].append(f'+{off:#x}: calls {label} defined in this file; one function per task')
                continue
            else:
                kind = 'section' if sym['type'] == STT_SECTION else 'object'
                result['problems'].append(
                    f'+{off:#x}: references local {kind} {label}; declare the original data symbol extern '
                    f'(original -> {_name(db, orig)})')
                continue
        else:
            targets = resolve(db, label, modules)
            if not targets:
                result['problems'].append(f'+{off:#x}: unknown symbol {label}; original -> {_name(db, orig)}')
                continue
        problem = _check_reloc(rel, off, targets, orig, original, masks)
        if problem and aligned:
            result['problems'].append(f'+{off:#x}: {problem}')
    for site in sorted(set(orig_relocs) - covered):
        if aligned:
            result['problems'].append(f'+{site - base:#x}: original relocates to {_name(db, orig_relocs[site])}; '
                                      'candidate has a constant/none (reference the symbol instead)')
    # Byte comparison outside relocated fields.
    size_ok = len(code) == len(original)
    if not size_ok:
        padding = len(code) < len(original) and len(original) - len(code) < 4 and not any(original[len(code):])
        result['problems'].append(
            f'size {len(code):#x} != original {len(original):#x}' + (
                '; the original extent includes alignment padding, so symbols.txt needs a boundary fix '
                '(release with a note)' if padding else
                '; call and data targets are compared once the sizes match'))
    differing = []
    for off in range(0, min(len(code), len(original))):
        mask = masks.get(off, 0xff)
        if (code[off] ^ original[off]) & mask:
            differing.append(off)
    result['differing_bytes'] = len(differing)
    rows_o = disasm.listing(original, base, task['mode'])
    rows_c = disasm.listing(code, base, mode)
    text_o = [_line(o, t, notes_o) for o, s, t in rows_o]
    text_c = [_line(o, t, notes_c) for o, s, t in rows_c]
    same = difflib.SequenceMatcher(None, text_o, text_c, autojunk=False)
    matched = sum(b.size for b in same.get_matching_blocks())
    result['score'] = round(matched / max(len(text_o), len(text_c), 1), 3)
    if not result['problems'] and not differing and size_ok:
        result.update(status='match', score=1.0)
    else:
        result['status'] = 'mismatch'
        result['diff'] = _diff([o for o, _, _ in rows_o], text_o, [o for o, _, _ in rows_c], text_c)
    result['elapsed_ms'] = round((time.perf_counter() - started) * 1000)
    return result


def _implied_reloc(kind, original, off, base, mode):
    """Synthesize the original relocation at a site from its encoded word/branch."""
    if off + 4 > len(original):
        return None
    word, = struct.unpack_from('<I', original, off)
    site = base + off
    if kind == R_ARM_ABS32:
        return dict(kind='load', target=word)
    if kind in ARM_CALLS and mode == 'arm':
        disp = ((word & 0xffffff) ^ 0x800000) - 0x800000
        if word >> 28 == 0xf:  # BLX immediate
            return dict(kind='arm_call_thumb', target=site + 8 + disp * 4 + ((word >> 23) & 2))
        return dict(kind='arm_branch' if (word >> 24) & 1 == 0 else 'arm_call', target=site + 8 + disp * 4)
    if kind == R_ARM_THM_CALL and mode == 'thumb':
        hi, lo = struct.unpack_from('<HH', original, off)
        if hi & 0xf800 != 0xf000 or lo & 0xe800 != 0xe800:
            return None
        disp = ((((hi & 0x7ff) << 12) | ((lo & 0x7ff) << 1)) ^ 0x400000) - 0x400000
        target = site + 4 + disp
        if lo & 0xf800 == 0xe800:
            return dict(kind='thumb_call_arm', target=target & ~3)
        return dict(kind='thumb_call', target=target)
    return None


def _check_reloc(rel, off, targets, orig, original, masks):
    kind, t = rel['type'], rel['addend']
    if kind == R_ARM_ABS32:
        if orig['kind'] != 'load':
            return f'candidate loads an address; original is {orig["kind"]}'
        value, = struct.unpack_from('<I', original, off)
        ok = any(value in (addr + t, (addr | 1) + t) for addr, k, m in targets)
        for i in range(4):
            masks[off + i] = 0
        return None if ok else f'address {rel["symbol"]["name"]}{t:+#x} != original word {value:#010x}'
    if kind in ARM_CALLS:
        expected = {(addr + t + 8) & ~1 for addr, k, m in targets}
        if orig['kind'] not in ('arm_call', 'arm_branch', 'arm_call_thumb'):
            return f'candidate branches; original relocation is {orig["kind"]}'
        if orig['target'] & ~1 not in expected:
            return f'branch to {rel["symbol"]["name"]} but original goes to {orig["target"]:#010x}'
        masks.update({off: 0, off + 1: 0, off + 2: 0})
        if orig['kind'] == 'arm_call_thumb':  # Linker turns BL into BLX for Thumb targets.
            masks[off + 3] = 0
        return None
    if kind == R_ARM_THM_CALL:
        expected = {(addr + t + 4) & ~1 for addr, k, m in targets}
        if orig['kind'] not in ('thumb_call', 'thumb_call_arm'):
            return f'candidate calls; original relocation is {orig["kind"]}'
        if orig['target'] & ~1 not in expected:
            return f'call to {rel["symbol"]["name"]} but original goes to {orig["target"]:#010x}'
        masks.update({off: 0, off + 1: 0xf8, off + 2: 0})
        masks[off + 3] = 0xe8 if orig['kind'] == 'thumb_call_arm' else 0xf8
        return None
    return f'unsupported relocation type {kind}'


def _name(db, reloc):
    modules = reloc['target_modules'].split(',') if reloc['target_modules'] else []
    target = reloc['target']
    for module in modules or [None]:
        row = db.execute('SELECT name FROM symbols WHERE address IN (?,?)' + (' AND module=?' if module else '')
                         + " ORDER BY kind='function' DESC LIMIT 1",
                         (target, target & ~1, module) if module else (target, target & ~1)).fetchone()
        if row:
            return row[0]
    return f'{target:#010x}'


def _line(offset, text, notes):
    if offset in notes:
        # Hide encoded displacement/word so equivalent relocations compare equal.
        head = text.split()[0]
        return f'{head:<8} {notes[offset].split("-> ", 1)[-1]}'
    return text.split('   ;')[0]


def _diff(offs_a, a, offs_b, b):
    """Unified-style instruction diff: '-' original, '+' candidate, with byte offsets."""
    out = []
    for group in difflib.SequenceMatcher(None, a, b, autojunk=False).get_grouped_opcodes(2):
        for tag, i1, i2, j1, j2 in group:
            if tag == 'equal':
                out += [f'  {offs_a[k]:>4x}  {a[k]}' for k in range(i1, i2)]
            else:
                out += [f'- {offs_a[k]:>4x}  {a[k]}' for k in range(i1, i2)]
                out += [f'+ {offs_b[k]:>4x}  {b[k]}' for k in range(j1, j2)]
        out.append('  ...')
    return out


def _trim(text, limit):
    lines = [l for l in text.splitlines() if l.strip()]
    return lines[:limit] + ([f'... {len(lines) - limit} more lines'] if len(lines) > limit else [])
