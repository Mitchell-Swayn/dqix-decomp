#!/usr/bin/env python3
"""Generate an offline, interactive USA matching treemap (no ROM bytes included)."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess

from audit_assembly import audit
from inventory import delinks

ROOT = Path(__file__).resolve().parents[1]
KEYS = ('total_code', 'matched_code', 'total_data', 'matched_data',
        'total_functions', 'matched_functions')


def arm9_units(root, report, assembly):
    owners = {}
    config = root / 'config/usa/arm9'
    paths = [('main', config / 'delinks.txt'),
             ('itcm', config / 'itcm/delinks.txt'),
             ('dtcm', config / 'dtcm/delinks.txt')]
    paths += [(p.parent.name, p) for p in sorted((config / 'overlays').glob('*/delinks.txt'))]
    modules = {name for name, _ in paths}
    for name, path in paths:
        for source in delinks(path)[1]:
            stem = Path(source['source']).with_suffix('').as_posix()
            owners.setdefault(stem, []).append(name)
    categories = {u['name']: u['category'] for u in assembly['units']}
    result = []
    for unit in report['units']:
        name = unit['name']
        metadata = unit.get('metadata', {})
        owner = ([name.rsplit('_', 1)[0]] if metadata.get('auto_generated')
                 else owners.get(name, []))
        if len(owner) != 1 or owner[0] not in modules:
            raise ValueError(f'Unassigned/ambiguous ARM9 unit: {name}: {owner}')
        measures = {k: int(unit['measures'].get(k, 0)) for k in KEYS}
        for total, matched in zip(KEYS[::2], KEYS[1::2]):
            if not 0 <= measures[matched] <= measures[total]:
                raise ValueError(f'Invalid {matched} for {name}')
        result.append(dict(name=name, module=owner[0], measures=measures,
                           category=categories[name], source=metadata.get('source_path'),
                           functions=[dict(name=f['name'], size=int(f['size']),
                                           similarity=f.get('fuzzy_match_percent'))
                                      for f in unit.get('functions', [])]))
    for key in KEYS:
        if sum(u['measures'][key] for u in result) != int(report['measures'].get(key, 0)):
            raise ValueError(f'ARM9 units do not reconcile: {key}')
    return result


def arm7_tiles(report):
    """Partition stored payload and runtime BSS independently; never infer code totals."""
    tiles = []
    fields = [('code_bytes', 'instructions', 'source_code_bytes'),
              ('literal_pool_bytes', 'literals', 'source_literal_pool_bytes'),
              ('data_bytes', 'data', 'source_data_bytes'),
              ('reviewed_assembly_bytes', 'assembly', 'reviewed_assembly_bytes')]
    for unit in report['units']:
        parts = [(kind, int(unit.get(field, 0))) for field, kind, _ in fields]
        if sum(size for _, size in parts) != int(unit['size']):
            raise ValueError(f'ARM7 unit partition differs: {unit["name"]}')
        for kind, size in parts:
            if size:
                tiles.append(dict(name=unit['name'], module=unit.get('autoload', 'startup'),
                                  kind=kind, size=size, source=unit['source'], view='payload'))
        bss = int(unit.get('bss', {}).get('size', 0))
        if bss:
            tiles.append(dict(name=unit['name'], module=unit.get('autoload', 'startup'),
                              kind='bss', size=bss, source=unit['source'], view='bss'))
    for _, kind, counter in fields:
        if sum(t['size'] for t in tiles if t['kind'] == kind) != int(report[counter]):
            raise ValueError(f'ARM7 units do not reconcile: {counter}')
    if sum(t['size'] for t in tiles if t['kind'] == 'bss') != int(report['source_bss_bytes']):
        raise ValueError('ARM7 source BSS does not reconcile')
    for view, total, fallback in [('payload', 'payload_bytes', 'binary_fallback_bytes'),
                                  ('bss', 'total_bss_bytes', 'unreconstructed_bss_bytes')]:
        size = int(report[fallback])
        if size < 0:
            raise ValueError('Negative fallback size')
        if size:
            tiles.append(dict(name='Original binary fallback', module='Unclassified',
                              kind='fallback', size=size, source=None, view=view))
        if sum(t['size'] for t in tiles if t['view'] == view) != int(report[total]):
            raise ValueError(f'ARM7 {view} denominator differs')
    return tiles


def generate(root, report_path, arm7_path, output):
    raw = report_path.read_bytes()
    a7raw = arm7_path.read_bytes()
    report, arm7 = json.loads(raw), json.loads(a7raw)
    assembly = audit(root, report_path)
    revision = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip()
    dirty = bool(subprocess.check_output(['git', 'status', '--porcelain'], cwd=root, text=True).strip())
    data = dict(generated=datetime.now(timezone.utc).isoformat(), revision=revision, dirty=dirty,
                report_time=datetime.fromtimestamp(report_path.stat().st_mtime, timezone.utc).isoformat(),
                report_sha256=hashlib.sha256(raw).hexdigest(),
                arm7_report_sha256=hashlib.sha256(a7raw).hexdigest(),
                measures={k: int(report['measures'].get(k, 0)) for k in KEYS},
                units=arm9_units(root, report, assembly), arm7=arm7_tiles(arm7),
                arm7_measures={k: arm7[k] for k in ('payload_bytes', 'source_code_bytes',
                    'source_literal_pool_bytes', 'source_data_bytes', 'source_functions',
                    'reviewed_assembly_bytes', 'binary_fallback_bytes', 'source_bss_bytes',
                    'total_bss_bytes', 'unreconstructed_bss_bytes')})
    # Prevent source/symbol names from terminating the embedded script element.
    payload = json.dumps(data, separators=(',', ':'), ensure_ascii=True).replace('<', '\\u003c')
    template = (root / 'tools/progress_treemap.html').read_text(encoding='utf-8')
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(template.replace('__PROGRESS_DATA__', payload), encoding='utf-8')
    print(f'{output.resolve()} ({len(data["units"])} ARM9 units; counters reconciled)')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--report', type=Path, default=ROOT / 'build/usa/report.json')
    parser.add_argument('--arm7-report', type=Path, default=ROOT / 'build/usa/arm7/report.json')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/progress/treemap.html')
    args = parser.parse_args()
    generate(ROOT, args.report, args.arm7_report, args.output)


if __name__ == '__main__':
    main()
