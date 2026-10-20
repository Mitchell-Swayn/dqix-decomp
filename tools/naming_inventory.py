"""Resolve report functions by owning delink module, never by source basename."""
import hashlib
import json
from pathlib import Path
import re
from function_naming import readable_names


def owning_modules(root):
    owners = {}
    base = Path(root) / 'config/usa/arm9'
    for path in base.rglob('delinks.txt'):
        parts = path.relative_to(base).parts
        module = 'main' if len(parts) == 1 else parts[-2]
        for line in path.read_text().splitlines():
            if line.startswith('src/') and line.endswith(':'):
                owners.setdefault(line[:-1], set()).add(module)
    return owners


def symbol_addresses(root):
    result = {}
    base = Path(root) / 'config/usa/arm9'
    for path in base.rglob('symbols.txt'):
        parts = path.relative_to(base).parts
        module = 'main' if len(parts) == 1 else parts[-2]
        for line in path.read_text().splitlines():
            match = re.match(r'(\S+) kind:function\([^\n]*addr:0x([0-9a-fA-F]+)', line)
            if match:
                key = (module, match[1])
                if key in result:
                    raise ValueError('Duplicate module-qualified symbol: ' + repr(key))
                result[key] = int(match[2], 16)
    return result


def qualified_scope(readable):
    """Nominal linkage scope, excluding namespaces appearing only in arguments.

    A qualified scope is not evidence of the function's semantic subsystem.
    """
    head = readable.split('(', 1)[0]
    return head.rsplit('::', 1)[0] if '::' in head else None


def inventory(root, report=None):
    root = Path(root)
    report = report or json.loads((root / 'build/usa/report.json').read_text())
    owners, symbols = owning_modules(root), symbol_addresses(root)
    registry_path = root / 'config/usa/function_names.json'
    registry = json.loads(registry_path.read_text()).get('functions', {}) if registry_path.exists() else {}
    runtime_path = root / 'config/usa/arm9/runtime_support.json'
    policy = json.loads(runtime_path.read_text()) if runtime_path.exists() else {}
    runtime = {(r['module'], int(r['address'], 16), r['name']): r for r in policy.get('functions', [])}
    aliases = {(r['source'], r['name']): r for r in policy.get('report_aliases', [])}
    units, seen = [], set()
    for unit in report['units']:
        source = unit.get('metadata', {}).get('source_path')
        if not source:
            continue
        modules = sorted(owners.get(source, []))
        raw = (root / source).read_bytes()
        comments = re.findall(r'//\s*Original:[^\n]*', raw.decode())
        rows = []
        for function in unit.get('functions', []):
            if function.get('fuzzy_match_percent') != 100:
                continue
            name = function['name']
            matches = [(m, symbols[m, name]) for m in modules if (m, name) in symbols]
            alias = aliases.get((source, name))
            if not matches and alias and len(modules) == 1 and re.fullmatch(r'\.L_[0-9a-fA-F]{8}', name):
                if int(function['size']) != alias['size']:
                    raise ValueError('Runtime alias size differs from policy')
                matches = [(modules[0], int(name[3:], 16))]
            if len(matches) != 1:
                raise ValueError('Function lacks one exact owning module identity: ' + source + ':' + name)
            module, address = matches[0]
            identity = f'arm9/{module}:{address:08x}'
            if identity in seen:
                raise ValueError('Duplicate function identity: ' + identity)
            seen.add(identity)
            record = registry.get(identity, {})
            original = record.get('old_symbol')
            provenance = []
            if original:
                provenance.append('address-bound naming registry')
            for comment in comments:
                if re.search(r'arm9/' + re.escape(module) + r'\s*@\s*0x' + f'{address:08x}' + r'\b', comment, re.I):
                    match = re.search(r'symbol:\s*(\S+)', comment)
                    if match:
                        original = match[1].rstrip(';')
                        provenance.append(comment)
            support = runtime.get(('arm9/' + module, address, name))
            if support:
                original = original or name
                provenance.append('accepted runtime/SDK policy and dedicated source header')
            if alias:
                original = name
                provenance.append('accepted nested runtime report alias; overlapping extent, no independent routine credit')
            rows.append(dict(function_id=identity,module=module,address=f'0x{address:08x}',symbol=name,original_symbol=original,source=source,size=int(function['size']),provenance=provenance,registry=record,runtime_or_sdk_policy=bool(support),nested_runtime_alias=bool(alias)))
        units.append(dict(unit=unit['name'],source=source,modules=modules,source_sha256=hashlib.sha256(raw).hexdigest(),functions=rows,data_only=not unit.get('functions'),sections=unit.get('sections', [])))
    rows = [f for u in units for f in u['functions']]
    for row, readable in zip(rows, readable_names([r['symbol'] for r in rows])):
        row['readable_name'] = readable
        row['class_scope'] = qualified_scope(readable)
    return dict(units=units,matched_functions=len(rows),source_units=len(units),measures=report['measures'])


if __name__ == '__main__':
    import argparse
    from integration_lock import integration_guard
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--project', type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    with integration_guard(args.project.resolve()):
        result = inventory(args.project.resolve())
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: v for k, v in result.items() if k != 'units'}))
