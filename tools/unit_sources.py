"""Assign stable source destinations to inventoried units without coverage credit."""
import argparse
import json
from pathlib import Path, PurePosixPath
import re
import subprocess


def catalog(root, report):
    config = root / 'config/usa/arm9'
    paths = [('main', config / 'delinks.txt'), ('itcm', config / 'itcm/delinks.txt'),
             ('dtcm', config / 'dtcm/delinks.txt')]
    paths += [(p.parent.name, p) for p in sorted((config / 'overlays').glob('*/delinks.txt'))]
    owners, symbols = {}, {}
    for module, path in paths:
        for line in path.read_text().splitlines():
            line = line.split('//', 1)[0].strip()
            if line.endswith(('.cpp:', '.c:', '.s:', '.S:')):
                owners.setdefault(Path(line[:-1]).with_suffix('').as_posix(), []).append(module)
        symbols[module] = {}
        for line in (path.parent / 'symbols.txt').read_text().splitlines():
            m = re.match(r'(\S+)\s+.*\baddr:0x([0-9a-fA-F]+)', line)
            if m:
                symbols[module][m[1]] = int(m[2], 16)
    units, functions = {}, {}
    for u in report['units']:
        name, metadata = u['name'], u.get('metadata', {})
        module = [name.rsplit('_', 1)[0]] if metadata.get('auto_generated') else owners.get(name, [])
        if len(module) != 1 or module[0] not in symbols:
            raise ValueError('Ambiguous source owner: ' + name)
        module = module[0]
        key = 'arm9/' + module + '/' + name
        source = metadata.get('source_path') or f'src/Units/arm9/{module}/{name}.cpp'
        path = PurePosixPath(source)
        if path.is_absolute() or '..' in path.parts or path.suffix not in ('.cpp', '.c'):
            raise ValueError('Invalid unit source destination')
        units[key] = dict(module='arm9/' + module, report_unit=name, source_path=source,
                          placeholder=bool(metadata.get('auto_generated')))
        for f in u.get('functions', []):
            if f['name'] not in symbols[module]:
                raise ValueError('Missing function address: ' + f['name'])
            identity = f"arm9/{module}:{symbols[module][f['name']]:08x}"
            if identity in functions:
                raise ValueError('Duplicate function destination: ' + identity)
            functions[identity] = key
    expected = int(report['measures']['total_functions'])
    if len(functions) != expected:
        raise ValueError('Function destination inventory does not reconcile')
    return dict(schema_version=1, policy='Stable unit source destinations; placeholders grant zero coverage',
                baseline_revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=root, text=True).strip(),
                units=units, functions=functions)


def materialize(root, document):
    for unit in document['units'].values():
        path = root / unit['source_path']
        if path.exists():
            continue
        if not unit['placeholder']:
            raise ValueError('Existing source unit file is missing: ' + str(path))
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text('// Reserved source destination for ' + unit['module'] + ' / ' + unit['report_unit'] + '.\n'
                        '// No reconstructed functions or data yet; original bytes remain binary fallback.\n', encoding='utf-8')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--report', type=Path)
    args = parser.parse_args()
    root = args.root.resolve()
    path = root / 'config/usa/unit_sources.json'
    if path.exists():
        raise ValueError('Stable catalog already exists; do not regenerate from changing fallback IDs')
    report = json.loads((args.report or root / 'build/usa/report.json').read_text())
    document = catalog(root, report)
    materialize(root, document)
    path.write_text(json.dumps(document, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(units=len(document['units']), functions=len(document['functions']),
                         placeholders=sum(u['placeholder'] for u in document['units'].values()))))


if __name__ == '__main__':
    main()
