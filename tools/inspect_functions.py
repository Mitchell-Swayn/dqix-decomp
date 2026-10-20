#!/usr/bin/env python3
"""Collect a batch through the HTTP backend used by Ghidra MCP, without mutations."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys
import time
from urllib.parse import urlencode
from urllib.request import urlopen


def request(server, endpoint, **params):
    url = server.rstrip('/') + '/' + endpoint + '?' + urlencode(params)
    with urlopen(url, timeout=60) as response:
        text = response.read().decode('utf-8')
    if re.match(r'(?i)\s*(error|no program|no function|function not found|failed)', text):
        raise ValueError(text.strip())
    return text


def fingerprint(server):
    # This backend lacks program IDs. This detects many active-program changes,
    # but cannot distinguish programs with identical layouts and symbol lists.
    text = request(server, 'segments', limit=10000) + request(server, 'list_functions')
    return hashlib.sha256(text.encode()).hexdigest()


def inspect(server, rows, expected=None):
    identity = fingerprint(server)
    if expected and expected != identity:
        raise ValueError('Active Ghidra program fingerprint differs from expected')
    results = []
    for row in rows:
        address = f"{int(str(row['address']), 16):08x}"
        entry = dict(row, address=address)
        try:
            entry['function'] = request(server, 'get_function_by_address', address=address)
            entry['pseudocode'] = request(server, 'decompile_function', address=address)
            entry['assembly'] = request(server, 'disassemble_function', address=address)
            entry['references_to'] = request(server, 'xrefs_to', address=address, limit=200)
            issues = []
            if 'WARNING' in entry['pseudocode'] or 'UNRECOVERED' in entry['pseudocode']:
                issues.append('incomplete_decompilation')
            if 'software_interrupt' in entry['pseudocode']:
                issues.append('interrupt_routine')
            asm = entry['assembly'].lower()
            if re.search(r'add\s+sp,sp', asm) and re.search(r'ldmia\s+sp!', asm) and not re.search(r'(stmdb|push)', asm):
                issues.append('possible_shared_epilogue')
            entry['review_flags'] = issues
            entry['status'] = 'inspected'
        except (OSError, ValueError) as error:
            entry.update(status='error', error=str(error))
        results.append(entry)
    if fingerprint(server) != identity:
        raise ValueError('Active Ghidra program changed during inspection; discard this batch')
    return {'schema_version': 1, 'program_fingerprint': identity,
            'identity_limit': 'Layout/symbol fingerprint, not a unique program ID; keep the program fixed.',
            'functions': results}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path, help='JSON array, or object with functions array; address is hexadecimal')
    parser.add_argument('--server', required=True, help='Ghidra MCP HTTP backend, e.g. http://127.0.0.1:8082')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--expect-fingerprint')
    args = parser.parse_args(argv)
    start = time.monotonic()
    try:
        document = json.loads(args.manifest.read_text())
        rows = document if isinstance(document, list) else document['functions']
        if not rows or len(rows) > 1000:
            raise ValueError('Select between 1 and 1000 functions')
        result = inspect(args.server, rows, args.expect_fingerprint)
        result['elapsed_seconds'] = time.monotonic() - start
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, indent=2) + '\n')
        errors = sum(row['status'] == 'error' for row in result['functions'])
        print(json.dumps({'functions': len(rows), 'errors': errors,
                          'review_flags': sum(bool(row.get('review_flags')) for row in result['functions']),
                          'elapsed_seconds': result['elapsed_seconds'], 'artifacts': str(args.output),
                          'program_fingerprint': result['program_fingerprint']}))
        return 2 if errors else 0
    except (OSError, ValueError, KeyError, TypeError) as error:
        print(json.dumps({'status': 'error', 'error': str(error)}))
        return 2


if __name__ == '__main__':
    sys.exit(main())
