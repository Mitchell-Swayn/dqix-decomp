"""Transactional removal of evidence-bound false load relocations in initialized data."""
import hashlib
import re
from pathlib import Path
import yaml
from integrate_batch import parse_delinks
from arm9_module import delinks_path, module_binaries, manifest_rows


def original_module(root, module):
    original, _ = module_binaries(module)
    if module == 'main':
        metadata = yaml.safe_load((root / 'extract/usa/arm9/arm9.yaml').read_text())
    elif module in ('itcm', 'dtcm'):
        metadata = yaml.safe_load((root / f'extract/usa/arm9/{module}.yaml').read_text())
    else:
        records = yaml.safe_load((root / 'extract/usa/arm9_overlays/overlays.yaml').read_text())['overlays']
        matches = [row for row in records if row['id'] == int(module[2:])]
        if len(matches) != 1:
            raise ValueError('Original module metadata is ambiguous')
        metadata = matches[0]
    return int(metadata['base_address']), (root / original).read_bytes()


def capture_relocations(main, worker, module, manifest):
    removals = manifest.get('relocation_removals', [])
    if not removals:
        return None
    _, data, _ = manifest_rows(manifest, module)
    relative = delinks_path(module).with_name('relocs.txt')
    before = (main / relative).read_bytes()
    lines = before.decode().splitlines(keepends=True)
    worker_lines = (worker / relative).read_text().splitlines()
    base, original = original_module(main, module)
    header = parse_delinks((main / delinks_path(module)).read_text(), allow_empty_sections=module != "main").header
    initialized_sections = {section: (int(start, 16), int(end, 16)) for section, start, end in re.findall(r"(?m)^\s*(\.data|\.rodata|\.ctor)\s+start:0x([0-9a-fA-F]+) end:0x([0-9a-fA-F]+)", header)}
    selected = []
    seen = set()
    for item in removals:
        if item['path'] != relative.as_posix():
            raise ValueError('Relocation removal outside selected module')
        line = item['line']
        match = re.fullmatch(r'from:0x([0-9a-fA-F]+) kind:load to:0x([0-9a-fA-F]+) module:(main|itcm|dtcm|overlay\([0-9]+\)|overlays\([0-9]+(?:,[0-9]+)*\))', line)
        if not match or not item.get('reason', '').strip():
            raise ValueError('Only explained exact load relocation removals are supported')
        address = int(item['address'], 16)
        if address != int(match[1], 16) or address in seen:
            raise ValueError('Relocation address differs or is duplicated')
        seen.add(address)
        if sum(x.rstrip('\r\n') == line for x in lines) != 1 or line in worker_lines:
            raise ValueError('Removal must exist once in main and be absent from worker')
        owners = [row for row in data if row.get('section') in ('.data', '.rodata', '.ctor') and int(row['address'], 16) <= address and address + 4 <= int(row['address'], 16) + int(row['size'])]
        if len(owners) != 1:
            raise ValueError('Removal must lie wholly within one selected initialized data extent')
        owner = owners[0]
        bounds = initialized_sections.get(owner['section'])
        if bounds is None or not (bounds[0] <= int(owner['address'], 16) and int(owner['address'], 16) + int(owner['size']) <= bounds[1]):
            raise ValueError('Selected initialized extent lies outside original data section')
        source = owner['source']
        source_path = (worker / source).resolve()
        if not source_path.is_relative_to((worker / 'src').resolve()) or hashlib.sha256(source_path.read_bytes()).hexdigest() != manifest.get('source_hashes', {}).get(source):
            raise ValueError('Removal evidence must bind an unchanged selected source')
        start = int(owner['address'], 16) - base
        size = int(owner['size'])
        if start < 0 or start + size > len(original) or hashlib.sha256(original[start:start + size]).hexdigest() != owner['sha256']:
            raise ValueError('Original selected data extent hash mismatch')
        word = item['original_word_hex']
        if not re.fullmatch(r'[0-9a-fA-F]{8}', word) or int(word, 16) != int.from_bytes(original[address-base:address-base+4], 'little') or int(word, 16) != int(match[2], 16):
            raise ValueError('Original numeric word differs from relocation target or evidence')
        selected.append(line)
    after = ''.join(x for x in lines if x.rstrip('\r\n') not in selected).encode()
    # Worker map may include unrelated disjoint changes; only exact selected removals transfer.
    return dict(path=relative.as_posix(), before=before, after=after)


def install_relocations(root, snapshot):
    if snapshot:
        path = root / snapshot['path']
        if path.read_bytes() != snapshot['before']:
            raise ValueError('Main relocation map changed after capture')
        path.write_bytes(snapshot['after'])


def verify_relocations(root, snapshot):
    if snapshot and (root / snapshot['path']).read_bytes() != snapshot['after']:
        raise ValueError('Installed relocation map changed')


def restore_relocations(root, snapshot):
    if snapshot:
        (root / snapshot['path']).write_bytes(snapshot['before'])
