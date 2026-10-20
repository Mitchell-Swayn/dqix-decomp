#!/usr/bin/env python3
"""One Ninja build and parallel object comparisons, returning one agent JSON result."""
import argparse
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
import json
import os
from pathlib import Path
import shutil
import sys
import time

from elf_function_bytes import compare as compare_bytes
from match_unit import new_attempt, object_paths, run_logged, select_unit, sha256, summarize, within
from objdiff_diagnosis import classify


def compare_unit(root, unit, directory, initial, raw_required, deferred_aliases=None):
    started = time.monotonic()
    target, base = object_paths(root, unit)
    directory.mkdir()
    record = {'unit': unit['name'], 'artifacts': str(directory.relative_to(root)), 'rom_acceptance': False}
    try:
        if not base.is_file():
            raise ValueError('Candidate object missing')
        if unit.get('metadata', {}).get('source_path'):
            source = within(root, root / unit['metadata']['source_path'])
            if initial.get('source_sha256') != sha256(source):
                raise ValueError('Candidate source changed during batch')
            (directory / ('candidate' + source.suffix)).write_bytes(source.read_bytes())
        record.update(target_sha256_before=sha256(target), candidate_sha256_before=sha256(base))
        if record['target_sha256_before'] != initial['target_sha256']:
            raise ValueError('Original target changed during build')
        command = [str(root / ('objdiff-cli.exe' if os.name == 'nt' else 'objdiff-cli')),
                   'diff', '-1', str(target), '-2', str(base), '-o', str(directory / 'diff.json'), '--format', 'json']
        record['command'] = command
        run_logged(command, root, directory, 'objdiff')
        document = json.loads((directory / 'diff.json').read_text())
        rows = summarize(document)
        mismatches = [row for row in rows if row['match_percent'] < 100 or not row['paired']]
        record['all_object_symbols_match'] = not mismatches
        if deferred_aliases:
            from integration_data_aliases import verify_deferred_objects
            deferred = verify_deferred_objects(target, base, deferred_aliases)
            omitted = [row for row in mismatches if row['symbol'] in deferred and row['side']=='target' and row['section']=='.bss' and not row['paired']]
            if {row['symbol'] for row in omitted} != set(deferred):
                raise ValueError('Declared deferred aliases do not match original-only object labels')
            mismatches = [row for row in mismatches if row not in omitted]
            record['linker_aliases_deferred'] = deferred
            record['linked_alias_audit_required'] = True
        diagnosis = classify(document)
        raw = compare_bytes(target, base)
        (directory / 'diagnosis.json').write_text(json.dumps(diagnosis, indent=2) + '\n')
        (directory / 'bytes.json').write_text(json.dumps(raw, indent=2) + '\n')
        if sha256(target) != record['target_sha256_before'] or sha256(base) != record['candidate_sha256_before']:
            raise ValueError('Object changed during comparison')
        if unit.get('metadata', {}).get('source_path') and sha256(source) != initial['source_sha256']:
            raise ValueError('Candidate source changed during comparison')
        record.update(status='compared', object_match=not mismatches, raw_match=raw['raw_match'],
                      match=not mismatches and (not raw_required or raw['raw_match'] is True),
                      symbols=len(rows), mismatches=len(mismatches),
                      differences=mismatches[:3], categories=diagnosis['category_counts'])
    except (OSError, ValueError, TypeError, KeyError, IndexError) as error:
        record.update(status='error', match=False, error=str(error))
    record['elapsed_seconds'] = time.monotonic() - started
    (directory / 'result.json').write_text(json.dumps(record, indent=2) + '\n')
    return record


def run(root, names, jobs=2, compare_jobs=4, ninja=None, no_build=False, raw_required=False, deferred_aliases=None):
    started = time.monotonic()
    config = root / 'objdiff.json'
    document = json.loads(config.read_text())
    if not names or len(names) != len(set(names)):
        raise ValueError('Select at least one unit, without duplicates')
    units = [select_unit(document, name) for name in names]
    initial = []
    for unit in units:
        target, base = object_paths(root, unit)
        if not target.is_file():
            raise ValueError(f'Original target missing: {target}; configure/extract first')
        source = unit.get('metadata', {}).get('source_path')
        initial.append({'target_sha256': sha256(target),
                        'source_sha256': sha256(within(root, root / source)) if source else None})
    attempt = new_attempt(root)
    config_hash = sha256(config)
    build_started = time.monotonic()
    try:
        if not no_build:
            local = root / ('.venv/Scripts/ninja.exe' if os.name == 'nt' else '.venv/bin/ninja')
            executable = ninja or (str(local) if local.is_file() else shutil.which('ninja'))
            if not executable:
                raise ValueError('Ninja not found')
            command = [executable, '-j', str(jobs)] + [str(object_paths(root, unit)[1].relative_to(root)) for unit in units]
            (attempt / 'build-command.json').write_text(json.dumps(command) + '\n')
            run_logged(command, root, attempt, 'ninja')
        build_seconds = time.monotonic() - build_started
        if config_hash != sha256(config):
            raise ValueError('objdiff configuration changed during build')
        compare_started = time.monotonic()
        with ThreadPoolExecutor(max_workers=compare_jobs) as pool:
            futures = [pool.submit(compare_unit, root, unit, attempt / f'unit-{index:04d}', initial[index], raw_required, (deferred_aliases or {}).get(unit['name']))
                       for index, unit in enumerate(units)]
            results = [future.result() for future in futures]
        if config_hash != sha256(config):
            raise ValueError('objdiff configuration changed during comparison')
        errors = sum(row['status'] == 'error' for row in results)
        matched = sum(row['match'] for row in results)
        result = {'status': 'compared', 'units': len(units), 'matched': matched,
                  'mismatched': len(units) - matched - errors, 'errors': errors,
                  'match': matched == len(units), 'build_seconds': build_seconds,
                  'compare_seconds': time.monotonic() - compare_started,
                  'elapsed_seconds': time.monotonic() - started,
                  'raw_required': raw_required, 'rom_acceptance': False,
                  'linker_aliases_deferred': sorted({name for row in results for name in row.get('linker_aliases_deferred', [])}),
                  'linked_alias_audit_required': any(row.get('linked_alias_audit_required') for row in results),
                  'artifacts': str(attempt.relative_to(root)),
                  'differences': [row for row in results if not row['match']][:10]}
        (attempt / 'units.json').write_text(json.dumps(results, indent=2) + '\n')
        code = 2 if errors else 1 if not result['match'] else 0
    except (OSError, ValueError, TypeError, KeyError) as error:
        # A failed batch build stops every comparison, including stale objects.
        result = {'status': 'error', 'match': False, 'error': str(error),
                  'units': len(units), 'elapsed_seconds': time.monotonic() - started,
                  'rom_acceptance': False, 'artifacts': str(attempt.relative_to(root))}
        code = 2
    result['started_utc'] = datetime.fromtimestamp(time.time() - (time.monotonic() - started), timezone.utc).isoformat()
    (attempt / 'batch.json').write_text(json.dumps(result, indent=2) + '\n')
    return code, result


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('units', nargs='*')
    parser.add_argument('--manifest', type=Path, help='JSON object with units array, or array of unit names')
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--jobs', type=int, default=2)
    parser.add_argument('--compare-jobs', type=int, default=4)
    parser.add_argument('--ninja')
    parser.add_argument('--no-build', action='store_true')
    parser.add_argument('--verify-manifest-sources', action='store_true', help='Require complete comparison units covering exactly the manifest sources')
    parser.add_argument('--require-raw', action='store_true', help='Require raw bytes equal; functions with code relocations cannot pass')
    args = parser.parse_args(argv)
    try:
        if not 1 <= args.jobs <= 256 or not 1 <= args.compare_jobs <= 32:
            raise ValueError('Invalid concurrency limits')
        names = args.units
        if args.manifest:
            if names:
                raise ValueError('Use unit names or a manifest, not both')
            document = json.loads(args.manifest.read_text())
            names = document if isinstance(document, list) else document['units']
        if args.verify_manifest_sources:
            if not args.manifest:
                raise ValueError('Source verification requires a manifest')
            from arm9_module import verify_manifest_units
            verify_manifest_units(document, json.loads((args.project / 'objdiff.json').read_text()))
        deferred = {}
        if args.manifest and isinstance(document, dict) and document.get('data_alias_dependency'):
            from integration_data_aliases import selected_aliases
            for alias in selected_aliases(args.project.resolve(), document.get('module','main'), document):
                deferred.setdefault(str(Path(alias['source']).with_suffix('')), []).append(alias)
        code, result = run(args.project.resolve(), names, args.jobs, args.compare_jobs,
                           args.ninja, args.no_build, args.require_raw, deferred)
    except (OSError, ValueError, KeyError, TypeError) as error:
        code, result = 2, {'status': 'error', 'match': False, 'error': str(error), 'rom_acceptance': False}
    print(json.dumps(result))
    return code


if __name__ == '__main__':
    sys.exit(main())
