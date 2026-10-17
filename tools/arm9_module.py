"""Strict USA ARM9 module routing for integration and linked-symbol audits."""
from pathlib import Path
import re


def module_section(module):
    if module == 'main':
        return 'ARM9'
    if module in ('itcm', 'dtcm'):
        return module.upper()
    if re.fullmatch(r'ov[0-9]{3}', module) and int(module[2:]) <= 34:
        return module.upper()
    raise ValueError(f'Unsupported USA ARM9 module: {module}')


def delinks_path(module):
    module_section(module)
    root = Path('config/usa/arm9')
    if module == 'main':
        return root / 'delinks.txt'
    if module in ('itcm', 'dtcm'):
        return root / module / 'delinks.txt'
    return root / 'overlays' / module / 'delinks.txt'


def manifest_rows(document, module):
    module_section(module)
    functions, data = document.get('functions', []), document.get('data', [])
    rows = functions + data
    if not rows or document.get('module', module) != module:
        raise ValueError('Select a nonempty manifest for the chosen module')
    if any(row.get('module', module) != module for row in rows):
        raise ValueError('Manifest row module differs from selected module')
    if len({row['name'] for row in rows}) != len(rows):
        raise ValueError('Duplicate manifest symbol')
    if any(int(row['size']) <= 0 for row in rows):
        raise ValueError('Manifest sizes must be positive')
    return functions, data, list(dict.fromkeys(row['source'] for row in rows))


def verify_measures(before, after, functions, data):
    for key in ('total_functions', 'total_code', 'total_data'):
        if before[key] != after[key]:
            raise ValueError(f'Coverage denominator changed: {key}')
    expected = {'matched_functions': len(functions),
                'matched_code': sum(int(row['size']) for row in functions),
                'matched_data': sum(int(row['size']) for row in data)}
    for key, delta in expected.items():
        if int(after.get(key, 0)) - int(before.get(key, 0)) != delta:
            raise ValueError(f'Unexpected coverage delta: {key}, expected {delta}')


def module_binaries(module):
    module_section(module)
    if module == 'main':
        return Path('extract/usa/arm9/arm9.bin'), Path('build/usa/build/arm9.bin')
    if module in ('itcm', 'dtcm'):
        return Path(f'extract/usa/arm9/{module}.bin'), Path(f'build/usa/build/{module}.bin')
    return Path(f'extract/usa/arm9_overlays/{module}.bin'), Path(f'build/usa/build/arm9_{module}.bin')


def verify_manifest_units(manifest, config):
    """Require comparisons to cover precisely every declared source unit."""
    selected = manifest['units']
    expected = {row['source'] for row in manifest.get('functions', []) + manifest.get('data', [])}
    if not expected or not selected or len(selected) != len(set(selected)):
        raise ValueError('Select nonempty, unique source units for manifest rows')
    sources = []
    for name in selected:
        units = [unit for unit in config['units'] if unit['name'] == name]
        if len(units) != 1:
            raise ValueError(f'Expected one configured unit: {name}')
        metadata = units[0].get('metadata', {})
        if metadata.get('complete') is not True or not metadata.get('source_path'):
            raise ValueError(f'Manifest unit is not complete source: {name}')
        sources.append(metadata['source_path'])
    if len(sources) != len(set(sources)) or set(sources) != expected:
        raise ValueError('Compared units differ from declared manifest sources')


def split_data(rows, module):
    """Route exact initialized and zero-fill storage without changing coverage."""
    module_section(module)
    initialized, bss = [], []
    for row in rows:
        section = row.get('section')
        if section in ('.data', '.rodata', '.ctor'):
            initialized.append(row)
        elif section == '.bss':
            bss.append(row)
        else:
            raise ValueError(f'Unsupported data section for {module}: {section}')
    return initialized, bss
