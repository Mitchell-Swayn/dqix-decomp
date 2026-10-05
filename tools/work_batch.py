"""Record reproducible coverage deltas for bounded reconstruction batches."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]


def capture(root):
    report = root / 'build/usa/report.json'
    arm7 = root / 'build/usa/arm7/report.json'
    measures = json.loads(report.read_text())['measures']
    a7 = json.loads(arm7.read_text())
    keys = ('total_code', 'total_data', 'total_functions', 'matched_code',
            'matched_data', 'matched_functions')
    a7keys = ('source_functions', 'source_code_bytes', 'source_literal_pool_bytes',
              'source_data_bytes', 'source_bss_bytes', 'reviewed_assembly_bytes',
              'binary_fallback_bytes', 'payload_bytes')
    sha = hashlib.sha1()
    with (root / 'dqix_usa.nds').open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            sha.update(block)
    return dict(utc=datetime.now(timezone.utc).isoformat(),
                revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
                dirty=bool(subprocess.check_output(['git', 'status', '--porcelain'], cwd=root, text=True).strip()),
                arm9={key: int(measures.get(key, 0)) for key in keys},
                arm7={key: int(a7.get(key, 0)) for key in a7keys},
                report_sha256=hashlib.sha256(report.read_bytes()).hexdigest(),
                arm7_report_sha256=hashlib.sha256(arm7.read_bytes()).hexdigest(),
                rom_sha1=sha.hexdigest(), token_usage=None)


def delta(before, after):
    for key in ('total_code', 'total_data', 'total_functions'):
        if before['arm9'][key] != after['arm9'][key]:
            raise ValueError('ARM9 denominator changed: ' + key)
    if before['arm7']['payload_bytes'] != after['arm7']['payload_bytes']:
        raise ValueError('ARM7 payload denominator changed')
    result = {cpu: {key: after[cpu][key] - value for key, value in before[cpu].items()}
              for cpu in ('arm9', 'arm7')}
    for cpu, values in result.items():
        for key, value in values.items():
            if key != 'binary_fallback_bytes' and value < 0:
                raise ValueError('Coverage decreased: ' + cpu + '.' + key)
    if result['arm7']['binary_fallback_bytes'] > 0:
        raise ValueError('ARM7 fallback increased')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=('start', 'finish'))
    parser.add_argument('name')
    parser.add_argument('--attempts', type=int)
    parser.add_argument('--notes', default='')
    args = parser.parse_args()
    if not re.fullmatch(r'[a-z0-9][a-z0-9_-]{0,79}', args.name):
        parser.error('name must contain only lowercase letters, digits, underscores and hyphens')
    if args.attempts is not None and args.attempts < 0:
        parser.error('attempts cannot be negative')
    directory = ROOT / 'build/workflow' / args.name
    path = directory / (args.action + '.json')
    if path.exists():
        parser.error('batch snapshot already exists; choose a new batch name')
    current = capture(ROOT)
    if current['rom_sha1'] != 'c7c3014c237900c8281289b8bc76a781969b6278':
        parser.error('current ROM SHA1 does not match acceptance target')
    record = dict(schema_version=1, name=args.name, snapshot=current,
                  notes=args.notes, attempts=args.attempts,
                  evidence_limit='Reads existing reports and ROM; does not run or replace acceptance checks.')
    if args.action == 'finish':
        before = json.loads((directory / 'start.json').read_text())['snapshot']
        record['delta'] = delta(before, current)
        record['elapsed_seconds'] = (datetime.fromisoformat(current['utc']) -
                                     datetime.fromisoformat(before['utc'])).total_seconds()
    directory.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({key: record[key] for key in ('name', 'delta', 'elapsed_seconds') if key in record}))
    print(path)


if __name__ == '__main__':
    main()
