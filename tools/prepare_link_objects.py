"""Make link-only fallback ELF copies acceptable to Metrowerks' size validator.

The two explicitly allowlisted data labels overlap their containing division
functions. MWLD sums both sizes and can reject a section. Original objdiff inputs are never
modified. Only reviewed size fields and configuration-bound text alignment fields may differ in a prepared copy.
"""
import argparse
import hashlib
import json
import os
import re
from pathlib import Path
import struct
import subprocess


class InvalidElf(ValueError):
    pass


ALLOWLIST = {
    '.L_0200c274': dict(address=0x0200c274, size=256, owner='_fdiv', owner_address=0x0200c1c0, owner_size=0x3b8),
    '.L_0200d484': dict(address=0x0200d484, size=256, owner='_ddiv', owner_address=0x0200d34c, owner_size=0x544),
}


def read_symbol_config(path):
    records = {}
    for line in path.read_text().splitlines():
        match = re.fullmatch(r'(\S+) kind:(function\((?:arm|thumb),size=(0x[0-9a-f]+)\)|data\(byte\[(\d+)\]\)) addr:(0x[0-9a-f]+)', line.strip())
        if match:
            name, kind, function_size, data_size, address = match.groups()
            if name in records:
                raise ValueError('duplicate configured symbol: ' + name)
            records[name] = dict(address=int(address, 16), size=int(function_size, 16) if function_size else int(data_size),
                                 type=2 if function_size else 1)
    return records


def prepare_elf(original, configured_symbols):
    if len(original) < 52 or original[:7] != b'\x7fELF\x01\x01\x01':
        raise InvalidElf('expected ELF32 little-endian version 1')
    header = struct.unpack_from('<16sHHIIIIIHHHHHH', original)
    if header[1:3] != (1, 40):
        raise InvalidElf('expected relocatable ARM ELF')
    section_offset, section_size, section_count = header[6], header[11], header[12]
    if section_size != 40 or not section_count or section_offset + section_count * 40 > len(original):
        raise InvalidElf('invalid section header table')
    sections = [struct.unpack_from('<IIIIIIIIII', original, section_offset + i * 40)
                for i in range(section_count)]
    for section in sections:
        if section[1] != 8 and section[4] + section[5] > len(original):
            raise InvalidElf('section payload outside file')
    symbols = []
    for section in sections:
        if section[1] != 2:
            continue
        if section[9] != 16 or section[5] % 16 or section[6] >= len(sections):
            raise InvalidElf('invalid symbol table')
        strings = sections[section[6]]
        if strings[1] != 3:
            raise InvalidElf('symbol table has no string table')
        names = original[strings[4]:strings[4] + strings[5]]
        for offset in range(section[4], section[4] + section[5], 16):
            name, value, size, info, other, index = struct.unpack_from('<IIIBBH', original, offset)
            end = names.find(b'\0', name)
            if name >= len(names) or end < 0:
                raise InvalidElf('invalid symbol name')
            if index >= len(sections) and index < 0xff00:
                raise InvalidElf('invalid symbol section')
            symbols.append(dict(name=names[name:end].decode('utf-8'),
                                value=value, size=size, binding=info >> 4, type=info & 15,
                                section=index, offset=offset))
    patched = bytearray(original)
    changes = []
    for index, section in enumerate(sections):
        # The workaround concerns executable PROGBITS, not program data/BSS.
        if section[1] != 1 or not section[2] & 4:
            continue
        members = [symbol for symbol in symbols if symbol['section'] == index and symbol['size'] and symbol['type'] != 3]
        if sum(symbol['size'] for symbol in members) <= section[5]:
            continue
        functions = [symbol for symbol in members if symbol['type'] == 2]
        for symbol in members:
            expected = ALLOWLIST.get(symbol['name'])
            if expected is None or symbol['binding'] != 1 or symbol['type'] != 1:
                continue
            owners = [function for function in functions
                      if function['value'] <= symbol['value'] and
                      symbol['value'] + symbol['size'] <= function['value'] + function['size'] <= section[5]]
            if len(owners) != 1:
                continue
            owner = owners[0]
            if (symbol['size'] != expected['size'] or owner['name'] != expected['owner'] or
                    owner['size'] != expected['owner_size'] or
                    symbol['value'] - owner['value'] != expected['address'] - expected['owner_address']):
                raise InvalidElf('allowlisted ELF symbol range changed: ' + symbol['name'])
            for name, address, size, kind in [(symbol['name'], expected['address'], expected['size'], 1),
                                               (owner['name'], expected['owner_address'], expected['owner_size'], 2)]:
                if configured_symbols.get(name) != dict(address=address, size=size, type=kind):
                    raise InvalidElf('configured symbol does not match allowlist: ' + name)
            struct.pack_into('<I', patched, symbol['offset'] + 8, 0)
            changes.append(dict(symbol=symbol['name'], owner=owners[0]['name'],
                                section=index, original_size=symbol['size'],
                                st_size_offset=symbol['offset'] + 8))
        removed = sum(change['original_size'] for change in changes if change['section'] == index)
        if sum(symbol['size'] for symbol in members) - removed > section[5]:
            raise InvalidElf('overlapping sizes cannot be repaired by the explicit division-table allowlist alone')
    # A halfword-aligned original text slice can begin inside a former aggregate.
    # Bind its base to configured, sized global function/object symbols; lower
    # alignment only in this link copy, preserving every original target byte.
    for index, section in enumerate(sections):
        if section[1] != 1 or not section[2] & 4 or section[8] != 4:
            continue
        bases = set()
        for symbol in symbols:
            configured = configured_symbols.get(symbol['name'])
            if (configured and symbol['section'] == index and symbol['binding'] == 1 and
                    symbol['size'] and symbol['type'] in (1, 2)):
                value = symbol['value'] & ~1 if symbol['type'] == 2 else symbol['value']
                bases.add(configured['address'] - value)
        if any(base % 4 == 2 for base in bases):
            if len(bases) != 1:
                raise InvalidElf('Configured symbols disagree on halfword text slice base')
            offset = section_offset + index * 40 + 32
            struct.pack_into('<I', patched, offset, 2)
            changes.append(dict(section=index, section_alignment_offset=offset,
                                original_alignment=4, alignment=2, configured_base=next(iter(bases))))
    for section in sections:
        if section[1] not in (2, 8):
            start, size = section[4], section[5]
            if original[start:start + size] != patched[start:start + size]:
                raise InvalidElf('symbol metadata overlaps another section payload')
    allowed = {position for change in changes for position in range(change.get('st_size_offset', change.get('section_alignment_offset')), change.get('st_size_offset', change.get('section_alignment_offset')) + 4)}
    # Compare unchanged ranges in C rather than iterating over every byte in
    # Python. Only the same explicitly allowlisted metadata bytes may differ.
    cursor = 0
    for position in sorted(allowed):
        if original[cursor:position] != patched[cursor:position]:
            raise AssertionError('unexpected ELF mutation')
        cursor = position + 1
    if original[cursor:] != patched[cursor:]:
        raise AssertionError('unexpected ELF mutation')
    return bytes(patched), changes


def prepare_objects(objects_file, fallback_dir, output_dir, output_list, report_file, configured_symbols):
    fallback_dir, output_dir = fallback_dir.resolve(), output_dir.resolve()
    if output_dir == fallback_dir or fallback_dir in output_dir.parents:
        raise ValueError('link copies must be outside the original delink directory')
    if objects_file.resolve() == output_list.resolve():
        raise ValueError('link object list must not replace original object list')
    output_dir.mkdir(parents=True, exist_ok=True)
    lines, records = [], []
    parents = {}
    created = set()
    for line in objects_file.read_text().splitlines():
        if not line.strip():
            continue
        path = Path(line.strip().strip('"'))
        # Directory layouts stay fixed during one linker invocation. Resolve
        # common parents once, while still checking each object's own symlink.
        parent = parents.get(path.parent)
        if parent is None:
            parent = parents[path.parent] = path.parent.resolve()
        resolved = (parent / path.name).resolve() if path.is_symlink() else parent / path.name
        runtime_assembly = resolved.suffix == '.o' and 'src/RuntimeSupport' in path.as_posix()
        if resolved.parent != fallback_dir and not runtime_assembly:
            lines.append(line)
            continue
        if resolved.suffix != '.o':
            raise ValueError('unexpected non-object delink input')
        original = resolved.read_bytes()
        prepared, changes = prepare_elf(original, configured_symbols)
        destination = output_dir / ('runtime' if runtime_assembly else '') / resolved.name
        if destination.parent not in created:
            destination.parent.mkdir(parents=True, exist_ok=True)
            created.add(destination.parent)
        if destination.resolve() == resolved:
            raise ValueError('refusing to overwrite original object')
        destination.write_bytes(prepared)
        # Keep response-file paths relative, as dsd does, for Wine as well as Windows.
        try:
            link_path = os.path.relpath(destination)
        except ValueError:  # A different Windows drive cannot be expressed relatively.
            link_path = str(destination)
        lines.append('"' + link_path + '"')
        records.append(dict(original=str(path), copy=str(destination), changes=changes,
                            original_sha256=hashlib.sha256(original).hexdigest(),
                            copy_sha256=hashlib.sha256(prepared).hexdigest()))
    output_list.parent.mkdir(parents=True, exist_ok=True)
    output_list.write_text('\n'.join(lines) + '\n')
    report_file.parent.mkdir(parents=True, exist_ok=True)
    report_file.write_text(json.dumps(dict(schema_version=1, purpose='link-only ELF metadata; no source coverage', objects=records), indent=2) + '\n')
    print(f'Prepared {len(records)} fallback copies; corrected {sum(len(r["changes"]) for r in records)} allowlisted symbol sizes')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['objects', 'fallback-dir', 'output-dir', 'output-list', 'report', 'symbol-config']:
        parser.add_argument('--' + name, type=Path, required=True)
    parser.add_argument("--link-command", nargs=argparse.REMAINDER, help="run the linker after preparing copies")
    parser.add_argument("--lcf", type=Path, help="enable byte-identical short-path link copies")
    args = parser.parse_args()
    prepare_objects(args.objects, args.fallback_dir, args.output_dir, args.output_list, args.report, read_symbol_config(args.symbol_config))
    if args.link_command:
        if args.lcf:
            from short_link import run
            run(args.output_list, args.lcf, args.output_dir.parent / 'short_link', args.link_command)
        else:
            subprocess.run(args.link_command, check=True)


if __name__ == '__main__':
    main()
