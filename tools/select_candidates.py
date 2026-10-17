#!/usr/bin/env python3
"""Select bounded, still-fallback-owned functions from a measured coverage report."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys


def select(root, report, module, limit, minimum, maximum):
    from runtime_support import excluded
    runtime = excluded(root)
    config = root / 'config/usa/arm9'
    if module == 'itcm' or module == 'dtcm':
        config /= module
    elif module != 'main':
        if not re.fullmatch(r'ov0(?:0[0-9]|[12][0-9]|3[0-4])', module):
            raise ValueError('Unsupported module')
        config = config / 'overlays' / module
    declarations = {}
    for line in (config / 'symbols.txt').read_text().splitlines():
        match = re.match(r'(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)\s+addr:0x([0-9a-fA-F]+)', line)
        if match:
            declarations[match[1]] = (match[2], int(match[3], 16), int(match[4], 16))
    rows = []
    for unit in report['units']:
        if not unit['name'].startswith(module + '_') or not unit.get('metadata', {}).get('auto_generated', False):
            continue
        for function in unit.get('functions', []):
            name, size = function['name'], int(function['size'])
            if not minimum <= size <= maximum or not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*', name):
                continue
            if name not in declarations or declarations[name][1] != size:
                continue
            mode, _, address = declarations[name]
            if ('arm9/' + module, address) in runtime:
                continue
            rows.append({'name': name, 'address': f'{address:08x}', 'size': size,
                         'mode': mode, 'module': module, 'fallback_unit': unit['name']})
    rows.sort(key=lambda row: (row['size'], int(row['address'], 16)))
    names = [row['name'] for row in rows]
    if len(names) != len(set(names)):
        raise ValueError('Duplicate function ownership in coverage report')
    return rows[:limit]


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--report', type=Path, default=Path('build/usa/report.json'))
    parser.add_argument('--module', default='main')
    parser.add_argument('--limit', type=int, default=100)
    parser.add_argument('--min-bytes', type=int, default=8)
    parser.add_argument('--max-bytes', type=int, default=24)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args(argv)
    try:
        if not 1 <= args.limit <= 1000 or not 0 < args.min_bytes <= args.max_bytes:
            raise ValueError('Invalid selection limits')
        root = args.project.resolve()
        path = root / args.report
        rows = select(root, json.loads(path.read_text()), args.module, args.limit, args.min_bytes, args.max_bytes)
        result = {'schema_version': 1, 'report_sha256': hashlib.sha256(path.read_bytes()).hexdigest(),
                  'functions': rows, 'selection_limit': 'Small functions ranked by size; boundaries still need Ghidra review.'}
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps({'selected': len(rows), 'module': args.module, 'artifacts': str(args.output)}))
        return 0
    except (OSError, ValueError, KeyError, TypeError) as error:
        print(json.dumps({'status': 'error', 'error': str(error)}))
        return 2


if __name__ == '__main__':
    sys.exit(main())
