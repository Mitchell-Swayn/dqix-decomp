#!/usr/bin/env python3
"""Validate original function ranges and prepare one source object per function."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys

from match_unit import within


def existing_ranges(text):
    owner = None
    ranges = []
    for line in text.splitlines():
        if line and not line[0].isspace() and line.endswith(':'):
            owner = line[:-1]
        match = re.search(r'\.text\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)', line)
        if owner and match:
            ranges.append((int(match[1], 16), int(match[2], 16), owner))
    return ranges


def plan(root, rows, delinks, source_dir, candidate_dir=None):
    config = within(root, root / delinks)
    text = config.read_text()
    original_section = re.search(r'^\s*\.text\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)', text)
    if not original_section:
        raise ValueError('Missing original .text section bounds')
    occupied = existing_ranges(text)
    symbols = config.parent / 'symbols.txt'
    declarations = {}
    for line in symbols.read_text().splitlines():
        match = re.match(r'(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)\s+addr:0x([0-9a-fA-F]+)', line)
        if match:
            declarations[match[1]] = (match[2], int(match[3], 16), int(match[4], 16))
    files, units, selected = {}, [], []
    from runtime_support import excluded
    runtime = excluded(root)
    for row in rows:
        if ('arm9/main', int(str(row['address']), 16)) in runtime:
            raise ValueError('Accepted runtime helper is excluded from C reconstruction: ' + row['name'])
        name = row['name']
        if not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*', name):
            raise ValueError(f'Unsupported symbol identifier: {name}')
        start, size = int(str(row['address']), 16), int(row['size'])
        if name not in declarations or declarations[name][1:] != (size, start):
            raise ValueError(f'Range differs from original symbols.txt: {name}')
        mode = declarations[name][0]
        if start % (4 if mode == 'arm' else 2) or size <= 0:
            raise ValueError(f'Invalid range alignment/size: {name}')
        end = start + size
        if not int(original_section[1], 16) <= start < end <= int(original_section[2], 16):
            raise ValueError(f'{name} is outside the original .text section')
        if 'possible_shared_epilogue' in row.get('review_flags', []):
            raise ValueError(f'{name} may be a shared epilogue; resolve its boundary before preparation')
        overlaps = [owner for a, b, owner in occupied if start < b and a < end]
        if overlaps:
            raise ValueError(f'{name} overlaps assigned range: {overlaps}')
        occupied.append((start, end, name))
        relative = Path(source_dir) / (name + '.cpp')
        destination = within(root, root / relative)
        if destination.exists():
            raise ValueError(f'Refusing to overwrite source: {relative}')
        if candidate_dir:
            content = (candidate_dir / (name + '.cpp')).read_text()
        else:
            pseudocode = row.get('pseudocode', row.get('code', 'No pseudocode supplied.'))
            pseudocode = str(pseudocode).replace('*/', '* /')
            content = (f'#include <globaldefs.h>\n// {name}: {start:#010x}–{end:#010x}, {mode}\n'
                       f'#error Reconstruct {name} before compiling this candidate\n'
                       f'/* Ghidra evidence; recover types and review before implementing:\n{pseudocode}\n*/\n')
        files[destination] = content
        text += f'\n{relative.as_posix()}:\n    complete\n    .text start:0x{start:08x} end:0x{end:08x}\n'
        units.append(relative.with_suffix('').as_posix())
        selected.append(dict(name=name, address=f'{start:08x}', size=size, mode=mode, source=relative.as_posix(),
                             **{k: row[k] for k in ('function_id','module','original_sha256','rank','context_package') if k in row}))
    return config, text, files, {'schema_version': 1, 'units': units, 'functions': selected,
                                'original_config_sha256': hashlib.sha256(config.read_bytes()).hexdigest(),
                                'configured': False, 'rom_acceptance': False}


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('manifest', type=Path)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--delinks', default='config/usa/arm9/delinks.txt')
    parser.add_argument('--source-dir', required=True, help='Project-relative directory under src/')
    parser.add_argument('--candidate-dir', type=Path, help='Copy reviewed NAME.cpp candidates instead of TODO scaffolds')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--write', action='store_true', help='Write source and delink entries; default is preview')
    args = parser.parse_args(argv)
    try:
        root = args.project.resolve()
        source_dir = Path(args.source_dir)
        if source_dir.is_absolute() or source_dir.parts[0] != 'src':
            raise ValueError('source-dir must be project-relative under src/')
        within(root / 'src', root / source_dir)
        output = within(root / 'build', root / args.output)
        if output.exists():
            raise ValueError('Refusing to overwrite output manifest')
        document = json.loads(args.manifest.read_text())
        rows = document if isinstance(document, list) else document['functions']
        if not rows:
            raise ValueError('Manifest must select functions')
        config, text, files, result = plan(root, rows, args.delinks, args.source_dir, args.candidate_dir)
        if args.write:
            created = []
            try:
                for path, content in files.items():
                    path.parent.mkdir(parents=True, exist_ok=True)
                    with path.open('x') as stream:
                        created.append(path)
                        stream.write(content)
                if hashlib.sha256(config.read_bytes()).hexdigest() != result['original_config_sha256']:
                    raise ValueError('Delink configuration changed during preparation')
                config.write_text(text)
            except Exception:
                for path in created:
                    path.unlink()
                raise
        result['written'] = args.write
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(result, indent=2) + '\n')
        print(json.dumps({'functions': len(rows), 'written': args.write, 'manifest': str(output),
                          'next_step': 'Configure and generate original target objects before compile_verify_batch.'}))
        return 0
    except (OSError, ValueError, KeyError, TypeError, IndexError) as error:
        print(json.dumps({'status': 'error', 'error': str(error)}))
        return 2


if __name__ == '__main__':
    sys.exit(main())
