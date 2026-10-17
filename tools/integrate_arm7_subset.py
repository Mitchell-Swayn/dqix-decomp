"""Accept new ARM7 source units under the project-wide publication transaction.

ARM7's builder verifies every linked source byte, symbol, literal and BSS range.
This entry point additionally enforces exact classification deltas and rollback.
It never overwrites existing source units or introduces assembly exceptions.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import time
from datetime import datetime, timezone

from integration_lock import integration_guard
from arm7_build import validate_layout

CONFIG = Path('config/usa/arm7/source_units.json')
INPUTS = Path('/home/swayn/.local/share/factory-inputs/dqix')
COUNTERS = {
    'source_code_bytes': 'code_bytes',
    'source_literal_pool_bytes': 'literal_pool_bytes',
    'source_data_bytes': 'data_bytes',
}


def merge_units(current, worker, names):
    """Copy only explicitly selected new units, retaining every original unit."""
    if not names or len(names) != len(set(names)):
        raise ValueError('Selected ARM7 unit names must be nonempty and unique')
    if {k: v for k, v in current.items() if k != 'units'} != {
        k: v for k, v in worker.items() if k != 'units'
    }:
        raise ValueError('ARM7 module layout metadata changed')
    old = {u['name']: u for u in current['units']}
    if len(old) != len(current['units']):
        raise ValueError('Duplicate current ARM7 unit names')
    candidates = {u['name']: u for u in worker['units']}
    if len(candidates) != len(worker['units']):
        raise ValueError('Duplicate worker ARM7 unit names')
    if any(candidates.get(name) != unit for name, unit in old.items()):
        raise ValueError('Worker changed an existing ARM7 source unit')
    added = []
    for name in names:
        if name in old or name not in candidates:
            raise ValueError('Selected unit is existing or missing: ' + name)
        unit = candidates[name]
        if unit.get('reviewed_assembly_bytes', 0) or 'assembly_exception' in unit:
            raise ValueError('New assembly requires separate provenance review')
        if not unit['source'].startswith('config/usa/arm7/src/'):
            raise ValueError('ARM7 sources must be inside the ARM7 source tree')
        added.append(unit)
    merged = {**current, 'units': current['units'] + added}
    return merged, added


def verify_deltas(before9, after9, before7, after7, units):
    if before9 != after9:
        raise ValueError('ARM9 coverage changed during ARM7-only acceptance')
    for key in ['payload_bytes', 'total_bss_bytes', 'function_count',
                'payload_sha1', 'reviewed_assembly_bytes', 'reviewed_assembly_functions']:
        if before7[key] != after7[key]:
            raise ValueError('ARM7 denominator or assembly accounting changed: ' + key)
    expected = {counter: sum(u.get(field, 0) for u in units)
                for counter, field in COUNTERS.items()}
    expected['source_bss_bytes'] = sum(u.get('bss', {}).get('size', 0) for u in units)
    expected['source_functions'] = sum(len(u['symbols']) for u in units
                                       if not u.get('data_bytes', 0))
    expected['binary_fallback_bytes'] = -sum(u['size'] for u in units)
    expected['unreconstructed_bss_bytes'] = -expected['source_bss_bytes']
    for key, delta in expected.items():
        if after7[key] - before7[key] != delta:
            raise ValueError('Unexpected ARM7 coverage delta: ' + key)
    if not after7['module_check_passed'] or not after7['source_symbol_checks_passed']:
        raise ValueError('ARM7 linked source checks failed')
    return expected



def original_rom_path(root, override=None):
    from rom_inputs import input_rom
    path = Path(override) if override is not None else input_rom(root)
    # The host preflight uses the same original mounted read-only for validation.
    # Preserve custom/bound paths; only translate this gate's Docker mount.
    if override is None and not path.exists():
        resolved = path.resolve()
        if resolved.is_relative_to('/inputs'):
            path = INPUTS / resolved.relative_to('/inputs')
    return path


def capture_snapshots(root, worker, manifest, units):
    declared = {f['path']: f['sha256'] for f in manifest['files']}
    if len(declared) != len(manifest['files']) or not {u['source'] for u in units} <= set(declared):
        raise ValueError('Missing or duplicate source snapshots')
    snapshots = {}
    targets = set()
    for source, expected_hash in declared.items():
        relative = Path(source)
        if (relative.as_posix() != source or relative.is_absolute()
                or '..' in relative.parts or not source.startswith('config/usa/arm7/src/')):
            raise ValueError('Source/header path must be canonical inside ARM7 tree')
        path = (worker / source).resolve()
        destination = root / source
        target = destination.resolve()
        if destination.is_symlink() or target in targets:
            raise ValueError('Source/header target is a symlink or path alias')
        targets.add(target)
        if not path.is_relative_to(worker / 'config/usa/arm7/src') or not target.is_relative_to(root / 'config/usa/arm7/src'):
            raise ValueError('Source/header escaped assigned ARM7 tree')
        content = path.read_bytes()
        if hashlib.sha256(content).hexdigest() != expected_hash:
            raise ValueError('Source snapshot changed: ' + source)
        if target.exists():
            raise ValueError('Existing ARM7 sources/headers cannot be overwritten: ' + source)
        if re.search(rb'\b(?:asm|__asm|INCBIN)\b', content):
            raise ValueError('Unreviewed assembly in new source/header: ' + source)
        snapshots[source] = content
    return declared, snapshots


def verify_snapshots(root, snapshots, merged, report, units):
    if json.loads((root / CONFIG).read_text()) != merged:
        raise ValueError('Installed ARM7 unit configuration changed during validation')
    for source, content in snapshots.items():
        if (root / source).read_bytes() != content:
            raise ValueError('Installed source/header snapshot changed: ' + source)
    verified = {u['name']: u for u in report['units']}
    if len(verified) != len(report['units']) or set(verified) != {u['name'] for u in merged['units']}:
        raise ValueError('Duplicate builder unit records')
    for unit in units:
        record = verified[unit['name']]
        if any(record.get(key) != value for key, value in unit.items()):
            raise ValueError('Builder unit differs from submitted configuration')
        if record['source_sha1'] != hashlib.sha1(snapshots[unit['source']]).hexdigest():
            raise ValueError('Builder source snapshot differs')
        for dependency in record.get('dependencies', []):
            if dependency['path'] in snapshots and dependency['sha1'] != hashlib.sha1(snapshots[dependency['path']]).hexdigest():
                raise ValueError('Builder dependency snapshot differs')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--worker', type=Path, required=True)
    parser.add_argument('--manifest', required=True,
                        help='Worker-relative JSON with unit_names and files (path/sha256)')
    parser.add_argument('--receipts', type=Path, required=True)
    parser.add_argument('--label', required=True)
    parser.add_argument('--role', default='arm7')
    parser.add_argument('--original-rom', type=Path, help='Host original ROM; exact baseline SHA1 required')
    args = parser.parse_args()
    root, worker, receipts = args.project.resolve(), args.worker.resolve(), args.receipts.resolve()
    if not re.fullmatch(r'[A-Za-z0-9_-]+', args.label) or not receipts.is_relative_to(root / 'build'):
        parser.error('Invalid label or receipts outside main build/')
    manifest_path = (worker / args.manifest).resolve()
    if not manifest_path.is_relative_to(worker):
        parser.error('Manifest must be inside worker')
    now = lambda: datetime.now(timezone.utc).isoformat()
    with integration_guard(root) as transaction:
        start, clock = now(), time.monotonic()
        manifest = json.loads(manifest_path.read_text())
        current = json.loads((root / CONFIG).read_text())
        merged, units = merge_units(current, json.loads((worker / CONFIG).read_text()), manifest['unit_names'])
        declared, snapshots = capture_snapshots(root, worker, manifest, units)
        # Range/byte validation is also repeated by the builder before linking.
        from check_arm7 import read_arm7
        baseline = json.loads((root / 'config/usa/arm7/baseline.json').read_text())
        rom = original_rom_path(root, args.original_rom)
        with rom.open('rb') as stream:
            if hashlib.file_digest(stream, 'sha1').hexdigest() != baseline['source_rom_sha1']:
                raise ValueError('Original ROM SHA1 differs from ARM7 baseline')
        metadata, original = read_arm7(rom)
        if metadata['payload_sha1'] != baseline['payload_sha1']:
            raise ValueError('Original ARM7 payload SHA1 differs from baseline')
        validate_layout(original, baseline, merged)
        folder = receipts / args.label
        folder.mkdir(parents=True, exist_ok=False)
        before9 = json.loads((root / 'build/usa/report.json').read_text())['measures']
        before7 = json.loads((root / 'build/usa/arm7/report.json').read_text())
        backup = {p: (root / p).read_bytes() for p in [CONFIG, Path('build/usa/report.json'), Path('build/usa/arm7/report.json')]}
        (folder / 'manifest.json').write_text(json.dumps(manifest, indent=2))
        (folder / 'source_units.before.json').write_bytes(backup[CONFIG])
        command = ('python3 tools/configure.py usa --compiler /opt/dqix/mwccarm '
                   '--dsd /inputs/dsd --objdiff /inputs/objdiff-cli -w /inputs/wibo '
                   '--keep-symbol func_0200bbd8 --keep-symbol func_020dc008 '
                   '--keep-symbol func_020dc020 && ninja -j 2 rom check report sha1')

        def validate(log_name):
            with (folder / log_name).open('w') as log:
                subprocess.run(['sudo', '-n', 'docker', 'run', '--rm', '--user', '1000:1000',
                                '-v', str(root) + ':/bench/project', '-v',
                                str(INPUTS) + ':/inputs:ro',
                                '-w', '/bench/project', 'factory-dqix:0.1', 'bash', '-c', command],
                               stdout=log, stderr=subprocess.STDOUT, check=True)

        copied = []
        transaction.begin_changes()
        try:
            for source in declared:
                target = root / source
                target.parent.mkdir(parents=True, exist_ok=True)
                copied.append(target)
                target.write_bytes(snapshots[source])
            (root / CONFIG).write_text(json.dumps(merged, indent=2) + '\n')
            t = time.monotonic()
            validate('validation.log')
            validation_seconds = time.monotonic() - t
            after9 = json.loads((root / 'build/usa/report.json').read_text())['measures']
            after7 = json.loads((root / 'build/usa/arm7/report.json').read_text())
            deltas = verify_deltas(before9, after9, before7, after7, units)
            verify_snapshots(root, snapshots, merged, after7, units)
            record = {'accepted': True, 'processor': 'ARM7', 'role': args.role,
                      'start': start, 'finish': now(), 'elapsed_seconds': time.monotonic() - clock,
                      'validation_seconds': validation_seconds, 'deltas': deltas,
                      'before_arm7': before7, 'after_arm7': after7, 'arm9_unchanged': True,
                      'source_sha256': declared, 'units': units}
            (folder / 'receipt.json').write_text(json.dumps(record, indent=2))
            transaction.release_publication()
            subprocess.run(['python3', 'tools/progress_dashboard.py'], cwd=root, check=True)
            print(json.dumps({'accepted': True, 'deltas': deltas}))
        except Exception:
            if not transaction.changed:
                transaction.begin_changes()
            (folder / 'receipt.json').unlink(missing_ok=True)
            for target in copied:
                target.unlink(missing_ok=True)
            for path, content in backup.items():
                (root / path).write_bytes(content)
            validate('rollback-validation.log')
            if json.loads((root / 'build/usa/report.json').read_text())['measures'] != before9 or json.loads((root / 'build/usa/arm7/report.json').read_text()) != before7:
                raise RuntimeError('Rollback reports differ; publication remains locked')
            (folder / 'failure.json').write_text(json.dumps({'accepted': False, 'start': start, 'finish': now(), 'rollback_verified': True}, indent=2))
            transaction.release_publication()
            raise


if __name__ == '__main__':
    main()
