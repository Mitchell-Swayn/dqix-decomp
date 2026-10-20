#!/usr/bin/env python3
"""Locate missing or shifted reconstructed functions in the linked ELF."""
import argparse
import json
from pathlib import Path
import sys

from elf_function_bytes import read_functions
from arm9_module import module_section


def audit(elf, rows, module=None):
    symbols = read_functions(elf, names_filter={row['name'] for row in rows}, metadata_only=True,
                             section_filter=module_section(module) if module else None)
    differences = []
    for row in rows:
        name, expected = row['name'], int(str(row['address']), 16)
        symbol = symbols.get(name)
        if symbol is None:
            differences.append({'function': name, 'issue': 'missing', 'expected_address': f'{expected:08x}'})
        elif symbol['address'] != expected or symbol['size'] != int(row['size']):
            differences.append({'function': name, 'issue': 'layout', 'expected_address': f'{expected:08x}',
                                'actual_address': f"{symbol['address']:08x}", 'expected_size': int(row['size']),
                                'actual_size': symbol['size']})
    return {'functions': len(rows), 'match': not differences, 'differences': differences,
            'rom_acceptance': False}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('--elf', type=Path, required=True)
    parser.add_argument('--output', type=Path)
    parser.add_argument('--module', help='ARM9 module: main, itcm, dtcm, ov000..ov034')
    args = parser.parse_args(argv)
    try:
        document = json.loads(args.manifest.read_text())
        rows = document if isinstance(document, list) else document['functions']
        if not rows:
            raise ValueError('No functions selected')
        result = audit(args.elf, rows, args.module)
        if args.output:
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps({**result, 'differences': result['differences'][:10],
                          'difference_count': len(result['differences'])}))
        return 0 if result['match'] else 1
    except (OSError, ValueError, KeyError, TypeError) as error:
        print(json.dumps({'status': 'error', 'error': str(error), 'match': False}))
        return 2


if __name__ == '__main__':
    sys.exit(main())
