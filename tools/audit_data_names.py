"""Audit data naming provenance against owning symbol maps and original module bytes."""
import argparse
import collections
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]


def audit(root):
    root = Path(root)
    registry = json.loads((root / 'config/usa/data_names.json').read_text())['symbols']
    modules = {}
    for module in ('main', 'itcm', 'dtcm'):
        stem = 'arm9' if module == 'main' else module
        metadata = (root / f'extract/usa/arm9/{stem}.yaml').read_text()
        base = int(re.search(r'^base_address: (\d+)', metadata, re.M)[1])
        modules[module] = (base, root / f'extract/usa/arm9/{stem}.bin')
    metadata = (root / 'extract/usa/arm9_overlays/overlays.yaml').read_text()
    for index, base in re.findall(r'- id: (\d+)\s+base_address: (\d+)', metadata):
        module = f'ov{int(index):03}'
        modules[module] = (int(base), root / f'extract/usa/arm9_overlays/{module}.bin')
    symbols = {}
    pending = []
    for module in modules:
        directory = root / 'config/usa/arm9'
        if module != 'main':
            directory /= module if module in ('itcm', 'dtcm') else 'overlays/' + module
        for line in (directory / 'symbols.txt').read_text().splitlines():
            match = re.match(r'(\S+) kind:(\S+) addr:0x([0-9a-f]+)', line)
            if match:
                name, kind, address = match.groups()
                symbols[module, name] = (kind, int(address, 16))
                if name.startswith('data_') and kind.startswith(('data', 'bss')):
                    pending.append(f'{module}:{name}')
    binaries = {module: path.read_bytes() for module, (_, path) in modules.items()}
    errors = []
    counts = collections.Counter()
    for identity, record in registry.items():
        module = record['module']
        address = int(record['address'], 16)
        evidence = record['evidence']
        name = record['new_symbol']
        try:
            assert identity == f'arm9/{module}:{address:08x}', 'registry identity differs'
            kind, current_address = symbols[module, name]
            assert current_address == address, 'symbol address differs'
            assert (module, record['old_symbol']) not in symbols, 'original identifier remains live'
            if kind.startswith('bss'):
                assert evidence.get('storage_kind') == 'bss', 'BSS not identified'
                assert evidence['original_bytes_hex'] == '', 'BSS claims initialized ROM bytes'
                counts['bss'] += 1
            else:
                base = modules[module][0]
                size = evidence['observed_size_bytes']
                original = binaries[module][address - base:address - base + size]
                assert len(original) == size, 'record exceeds initialized module bytes'
                assert original.hex() == evidence['original_bytes_hex'], 'original bytes differ'
                assert hashlib.sha256(original).hexdigest() == evidence['original_bytes_sha256'], 'byte hash differs'
                counts['initialized_data'] += 1
            if evidence.get('semantic_review_required'):
                assert 'UnknownRole' in name, 'uncertainty omitted from name'
                counts['semantic_review_required'] += 1
            else:
                counts['content_or_source_supported'] += 1
            source = record.get('source')
            if source:
                text = (root / source).read_text()
                assert re.search(r'\b' + re.escape(name) + r'\b', text), 'name absent from recorded source'
                assert record['old_symbol'] in text, 'original identity comment absent'
        except (AssertionError, KeyError, FileNotFoundError) as exc:
            errors.append(f'{identity}: {exc}')
    aliases = json.loads((root / 'config/usa/data_names.json').read_text()).get('source_aliases', {})
    for old_name, alias in aliases.items():
        try:
            assert old_name == alias['old_symbol'], 'alias identity differs'
            if alias['kind'] == 'bss_member_alias':
                assert alias['original_bytes_hex'] == '', 'BSS alias claims initialized ROM bytes'
                counts['bss_aliases'] += 1
            else:
                address = int(alias['address'], 16)
                base = modules[alias['module']][0]
                original = binaries[alias['module']][address - base:address - base + alias['size_bytes']]
                assert original.hex() == alias['original_bytes_hex'], 'alias bytes differ'
                assert hashlib.sha256(original).hexdigest() == alias['original_bytes_sha256'], 'alias byte hash differs'
                counts['initialized_aliases'] += 1
        except (AssertionError, KeyError) as exc:
            errors.append(f'{old_name}: {exc}')
    return dict(registry_symbols=len(registry), source_aliases=len(aliases), counts=dict(counts),
                remaining_address_named_data_symbols=pending, errors=errors)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    report = audit(args.root)
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))
    raise SystemExit(bool(report['errors'] or report['remaining_address_named_data_symbols']))


if __name__ == '__main__':
    main()
