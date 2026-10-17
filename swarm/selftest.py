#!/usr/bin/env python3
"""Validate the verifier against already-integrated source with known outcomes.

Every sampled single-function unit from the build must be reported as a match;
each deliberately perturbed copy must be reported as a mismatch or error.
"""
import argparse
import json
from pathlib import Path
import random
import re
import sqlite3
import sys
import time

sys.path.insert(0, str(Path(__file__).resolve().parent))
from build import owned_ranges  # noqa: E402
from state import CONFIG, Project  # noqa: E402
from verify import check  # noqa: E402


def samples(project, db, evidence):
    policy = json.loads((project.root / 'config/usa/compiler_profiles.json').read_text())['sources']
    profiles = profile_map(project)
    special = set(policy)
    out = []
    for module in CONFIG['modules']:
        cdir = project.config_dir(module)
        if not (cdir / 'delinks.txt').exists():
            continue
        units = {}
        for start, end, section, owner in owned_ranges(cdir, complete_only=True):
            units.setdefault(owner, []).append((section, start, end))
        for owner, ranges in units.items():
            if len(ranges) != 1 or ranges[0][0] != 'text' or (owner in special and owner not in profiles):
                continue
            if not owner.endswith(('.c', '.cpp')) or not (project.root / owner).is_file() or \
                    owner.startswith('src/RuntimeSupport/'):
                continue
            _, start, end = ranges[0]
            fns = evidence.execute('SELECT id,address,size,original_bytes FROM functions WHERE module_id=? AND '
                                   'address>=? AND address<? AND size>0', (module, start, end)).fetchall()
            if len(fns) != 1 or fns[0][1] != start or fns[0][2] != end - start:
                continue
            sym = db.execute("SELECT name,mode FROM symbols WHERE module=? AND address=? AND kind='function'",
                             (module, start)).fetchone()
            if sym:
                out.append(dict(id=fns[0][0], module=module, name=sym['name'], address=start, size=end - start,
                                mode=sym['mode'], original=fns[0][3], source=owner,
                                profile=profiles.get(owner, 'default')))
    return out


def profile_map(project):
    """Sources whose recorded compiler profile is expressible as a named swarm profile."""
    policy = json.loads((project.root / 'config/usa/compiler_profiles.json').read_text())['sources']
    out = {}
    for source, entry in policy.items():
        if {'member_aliases', 'function_extents', 'absolute_linker_symbols'} & set(entry) or 'file' in entry['flags']:
            continue
        for name, p in CONFIG['profiles'].items():
            iw = '-nointerworking' not in entry['flags']
            if p['version'] == entry['version'] and p['opt'] in entry['flags'] and p['interworking'] == iw:
                out[source] = name
    return out


def perturb(text):
    """Change one integer literal so the generated code should differ."""
    body = text[text.find('{'):] if '{' in text else text
    comments = [m.span() for m in re.finditer(r'//[^\n]*|/\*.*?\*/', body, re.S)]
    nums = [m for m in re.finditer(r'(?<![\w.])(0x[0-9a-fA-F]+|\d+)(?![\w.])', body)
            if not any(a <= m.start() < b for a, b in comments)]
    if not nums:
        return None
    m = nums[len(nums) // 2]
    value = int(m[1], 16) if m[1].lower().startswith('0x') else int(m[1], 8 if len(m[1]) > 1 and m[1][0] == '0' else 10)
    return text[:len(text) - len(body) + m.start()] + str(value + 3) + text[len(text) - len(body) + m.end():]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--project'); p.add_argument('--count', type=int, default=200)
    p.add_argument('--seed', type=int, default=1); p.add_argument('--evidence')
    p.add_argument('--only', help='regex filter on source path')
    args = p.parse_args()
    project = Project(args.project)
    db = project.connect()
    meta = dict(db.execute('SELECT key,value FROM meta').fetchall())
    evidence = sqlite3.connect(f"file:{args.evidence or json.loads(meta['evidence'])}?mode=ro", uri=True)
    pool = samples(project, db, evidence)
    if args.only:
        pool = [t for t in pool if re.search(args.only, t['source'])]
    random.Random(args.seed).shuffle(pool)
    pool = pool[:args.count]
    started = time.monotonic()
    good, bad, failures, perturbed, caught, escaped = 0, 0, [], 0, 0, []
    for task in pool:
        text = (project.root / task['source']).read_text()
        inc = Path(task['source']).parent
        suffix = Path(task['source']).suffix
        r = check(project, db, task, text, None, suffix, inc, task['profile'])
        if r['status'] == 'match':
            good += 1
        else:
            bad += 1
            failures.append(dict(task=task['id'], source=task['source'], status=r['status'],
                                 problems=r['problems'][:4], messages=r.get('messages', [])[:4],
                                 diff=r.get('diff', [])[:12]))
            continue
        changed = perturb(text)
        if changed and changed != text:
            perturbed += 1
            r2 = check(project, db, task, changed, None, suffix, inc, task['profile'])
            if r2['status'] != 'match':
                caught += 1
            else:
                escaped.append(task['source'])  # Literal may be dead/unused; inspect manually.
    elapsed = time.monotonic() - started
    print(json.dumps(dict(sampled=len(pool), matched=good, not_matched=bad, perturbed=perturbed,
                          perturbed_rejected=caught, perturbed_accepted=escaped[:10],
                          seconds=round(elapsed, 2), checks_per_second=round((len(pool) + perturbed) / elapsed, 1),
                          failures=failures[:args.count]), indent=1))
    return 0 if not bad else 1


if __name__ == '__main__':
    sys.exit(main())
