#!/usr/bin/env python3
"""Compare NitroFS and inventory decoded NARC/GPC2/map members without extraction."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct

from gpc import decompress_nitro_lz, members as gpc_members


def region(data, offset, size):
    if offset < 0 or size < 0 or offset + size > len(data):
        raise ValueError(f"Out-of-bounds region {offset:#x}+{size:#x}")
    return data[offset:offset + size]


def names(fnt):
    """Decode Nitro directory tables; return file ID -> lossless printable path."""
    region(fnt, 0, 8)
    count = struct.unpack_from('<H', fnt, 6)[0]
    region(fnt, 0, count * 8)
    result, visited = {}, set()

    def walk(index, parent):
        if index >= count or index in visited:
            raise ValueError("Invalid or cyclic FNT directory")
        visited.add(index)
        offset, fid, _ = struct.unpack_from('<IHH', fnt, index * 8)
        while True:
            marker = region(fnt, offset, 1)[0]
            offset += 1
            if marker == 0:
                break
            length = marker & 127
            if not length:
                raise ValueError("Empty FNT name")
            # Escapes non-ASCII bytes; do not write any paths to the filesystem.
            name = region(fnt, offset, length).decode('ascii', 'backslashreplace')
            offset += length
            path = parent + name
            if marker & 128:
                child = struct.unpack('<H', region(fnt, offset, 2))[0]
                offset += 2
                if child < 0xf000:
                    raise ValueError("Invalid FNT directory ID")
                walk(child - 0xf000, path + '/')
            else:
                if fid in result or path in result.values():
                    raise ValueError("Duplicate NitroFS file ID or path")
                result[fid] = path
                fid += 1

    walk(0, '')
    return result


def nitrofs(rom):
    region(rom, 0, 0x160)
    fnt_offset, fnt_size, fat_offset, fat_size = struct.unpack_from('<4I', rom, 0x40)
    table = names(region(rom, fnt_offset, fnt_size))
    fat = region(rom, fat_offset, fat_size)
    if len(fat) % 8:
        raise ValueError("Invalid FAT length")
    output = {}
    for fid, path in table.items():
        start, end = struct.unpack('<II', region(fat, fid * 8, 8))
        output[path] = region(rom, start, end - start)
    return output


def narc(data):
    region(data, 0, 16)
    magic, bom, version, size, header_size, count = struct.unpack_from('<4sHHIHH', data)
    if magic != b'NARC' or bom != 0xfffe or version != 0x100 or size != len(data):
        raise ValueError("Unsupported NARC header")
    sections, offset = {}, header_size
    for _ in range(count):
        magic, size = struct.unpack('<4sI', region(data, offset, 8))
        if size < 8 or magic in sections:
            raise ValueError("Invalid NARC section")
        sections[magic] = region(data, offset + 8, size - 8)
        offset += size
    if offset != len(data):
        raise ValueError("NARC section sizes do not cover container")
    fat, image = sections[b'BTAF'], sections[b'GMIF']
    count = struct.unpack('<H', region(fat, 0, 2))[0]
    fnt = sections.get(b'BTNF')
    paths = names(fnt) if fnt else {}
    output = {}
    for fid in range(count):
        first, last = struct.unpack('<II', region(fat, 4 + fid * 8, 8))
        path = paths.get(fid, f'@{fid:05}')
        if path in output:
            raise ValueError("Duplicate NARC member path")
        output[path] = region(image, first, last - first)
    return output


def script_shape(data):
    """Structural check only, derived from Resource/Script.cpp; no execution."""
    if len(data) < 16:
        return None
    count, data_offset, length, unknown = struct.unpack_from('<iIiI', data)
    if count < 0 or count > (len(data)-16)//4 or length < 0:
        return None
    if data_offset < 16 or data_offset + length > len(data):
        return None
    offset = 16
    opcodes = Counter()
    for _ in range(count):
        if offset + 3 > data_offset:
            return None
        opcode, argc = struct.unpack_from('<HB', data, offset)
        parameter_offset = (3 + (argc + 3)//4 + 3) & ~3
        end = offset + parameter_offset + argc * 4
        if end > data_offset or argc > 128:
            return None
        opcodes[opcode] += 1
        offset = end
    padding = data[offset:data_offset]
    if padding and not (all(b == 0xff for b in padding) or all(b == 0 for b in padding)):
        return None
    return dict(instructions=count, data_offset=data_offset, data_size=length,
                instruction_padding=len(padding), header_word_4=unknown,
                opcodes=dict(sorted(opcodes.items())))


def inspect_pe(data, signature_offset):
    """Validate a PE image candidate, including embedded DOS-relative offsets.

    This is format triage, not instruction analysis or a Windows loader emulator.
    A rejected PE signature says nothing about raw ARM code in the same payload.
    """
    bases = []
    start = 0
    while True:
        base = data.find(b'MZ', start, signature_offset)
        if base < 0:
            break
        if base + 64 <= len(data):
            pe_offset = struct.unpack_from('<I', data, base + 0x3c)[0]
            if pe_offset >= 64 and base + pe_offset == signature_offset:
                bases.append(base)
        start = base + 2
    if not bases:
        return dict(status='rejected_PE_signature', reason='No DOS MZ header with e_lfanew pointing to this signature')
    failures = []
    for base in bases:
        try:
            if region(data, signature_offset, 4) != b'PE\0\0':
                raise ValueError('PE signature missing')
            machine, section_count, _, _, _, optional_size, characteristics = struct.unpack(
                '<HHIIIHH', region(data, signature_offset + 4, 20))
            if not section_count or not machine:
                raise ValueError('Empty machine or section count')
            optional_offset = signature_offset + 24
            optional = region(data, optional_offset, optional_size)
            magic = struct.unpack('<H', region(optional, 0, 2))[0]
            if magic not in (0x10b, 0x20b):
                raise ValueError('Not a PE32 or PE32+ optional header')
            minimum = 96 if magic == 0x10b else 112
            if optional_size < minimum:
                raise ValueError('Truncated optional header')
            headers_size = struct.unpack_from('<I', optional, 60)[0]
            if headers_size < optional_offset + optional_size + section_count * 40 - base:
                raise ValueError('Section table extends beyond SizeOfHeaders')
            region(data, base, headers_size)
            sections = []
            for index in range(section_count):
                section = region(data, optional_offset + optional_size + index * 40, 40)
                raw_size, raw_offset = struct.unpack_from('<II', section, 16)
                if raw_size:
                    region(data, base + raw_offset, raw_size)
                sections.append(dict(name=section[:8].rstrip(b'\0').decode('ascii', 'backslashreplace'),
                                     raw_offset=raw_offset, raw_size=raw_size))
            return dict(status='structurally_valid_PE_candidate', image_offset=base,
                        machine=machine, optional_magic=magic, characteristics=characteristics,
                        sections=sections)
        except (ValueError, struct.error) as error:
            failures.append(str(error))
    return dict(status='rejected_PE_signature', reason='; '.join(failures))


def inspect_macho32(data, offset):
    try:
        magic, cpu, subtype, file_type, count, command_size, flags = struct.unpack(
            '<7I', region(data, offset, 28))
        if magic != 0xfeedface or cpu not in (7, 12, 18) or not 1 <= file_type <= 12:
            raise ValueError('Implausible 32-bit Mach-O architecture/file type')
        commands = region(data, offset + 28, command_size)
        if count > command_size // 8:
            raise ValueError('Mach-O command count exceeds command region')
        cursor = 0
        for _ in range(count):
            command, size = struct.unpack('<II', region(commands, cursor, 8))
            if size < 8 or size % 4:
                raise ValueError('Invalid Mach-O load command size')
            region(commands, cursor, size)
            cursor += size
        if cursor != command_size:
            raise ValueError('Mach-O command size mismatch')
        return dict(status='structural_MachO_candidate', cpu=cpu, file_type=file_type,
                    load_commands=count, note='Header/command structure only, not execution proof')
    except (ValueError, struct.error) as error:
        return dict(status='rejected_MachO_signature', reason=str(error))


def native_candidates(data):
    """Weak triage signatures. Raw ARM/Thumb code has no required magic."""
    findings = []
    for magic, label in ((b'\x7fELF', 'ELF'), (b'PE\0\0', 'PE'),
                         (b'\xce\xfa\xed\xfe', 'Mach-O32'), (b'\xcf\xfa\xed\xfe', 'Mach-O64')):
        start = 0
        while True:
            offset = data.find(magic, start)
            if offset < 0:
                break
            candidate = dict(offset=offset, signature=label)
            if label == 'PE':
                candidate['structure'] = inspect_pe(data, offset)
            elif label == 'Mach-O32':
                candidate['structure'] = inspect_macho32(data, offset)
            findings.append(candidate)
            start = offset + len(magic)
    return findings


def audit(original, rebuilt):
    before, after = nitrofs(original), nitrofs(rebuilt)
    if before.keys() != after.keys():
        raise ValueError(f"NitroFS paths differ: missing={sorted(before.keys()-after.keys())}, added={sorted(after.keys()-before.keys())}")
    changed = [path for path in before if before[path] != after[path]]
    if changed:
        raise ValueError(f"NitroFS bytes differ: {changed}")
    records, errors = [], []

    def visit(path, payload, depth):
        item = dict(path=path, size=len(payload), sha256=hashlib.sha256(payload).hexdigest(),
                    magic_hex=payload[:4].hex(), depth=depth)
        records.append(item)
        if payload.startswith((b'NARC', b'GPC2')):
            item['container'] = 'NARC' if payload.startswith(b'NARC') else 'GPC2'
            try:
                if depth >= 12:
                    raise ValueError("Nested archive depth limit")
                if item['container'] == 'NARC':
                    members = narc(payload)
                    item['members'] = len(members)
                    for name, content in sorted(members.items()):
                        visit(path + '::' + name, content, depth + 1)
                else:
                    members = gpc_members(payload)
                    item['members'] = len(members)
                    item['member_compression'] = dict(Counter(str(m['compression']) for m in members))
                    for member in members:
                        name = member['name'] or '@' + str(member['id'])
                        visit(path + '::' + name, member['payload'], depth + 1)
            except (ValueError, KeyError, struct.error) as error:
                item['container_error'] = str(error)
                errors.append(path)
        elif (path.startswith('data/map/') and '::' in path and
              Path(path).suffix.lower() in ('.bmbl', '.bpos', '.bmdj', '.bats', '.dat', '.nsbtx') and
              payload.startswith(b'\x10')):
            # These member extensions are routed through FileIO's BIOS LZ77
            # wrapper by the source-backed Zone3D loaders. Do not infer generic
            # compression from a lone 0x10 byte in unrelated files/scripts.
            item['compression'] = 'Nitro_LZ77_0x10'
            try:
                if depth >= 12:
                    raise ValueError('Nested compression depth limit')
                decoded = decompress_nitro_lz(payload)
                item['decoded_size'] = len(decoded)
                visit(path + '::@lz77', decoded, depth + 1)
            except (ValueError, struct.error) as error:
                item['compression_error'] = str(error)
                errors.append(path)
        else:
            # PAC and proprietary formats remain opaque; extension is not proof of format.
            item['native_header_candidates'] = native_candidates(payload)
            shape = script_shape(payload)
            if shape is not None:
                item['script_structure_candidate'] = shape
    for path, payload in sorted(before.items()):
        visit(path, payload, 0)
    return dict(schema_version=1, original_sha1=hashlib.sha1(original).hexdigest(),
        rebuilt_sha1=hashlib.sha1(rebuilt).hexdigest(), nitrofs_equal=True,
        top_level_files=len(before), records_including_members=len(records),
        top_level_extensions=dict(sorted(Counter(Path(p).suffix for p in before).items())),
        narc_containers=sum(r.get('container') == 'NARC' for r in records),
        gpc2_containers=sum(r.get('container') == 'GPC2' for r in records),
        nitro_lz_members=sum(r.get('compression') == 'Nitro_LZ77_0x10' for r in records),
        container_errors=errors,
        native_candidate_files=sum(bool(r.get('native_header_candidates')) for r in records),
        script_structure_candidates=sum('script_structure_candidate' in r for r in records),
        limitations=["Only FNT-named NitroFS files compared; executables, overlays, banner and padding are outside this check.",
                     "NARC/GPC2 and source-backed Nitro LZ map members decoded; opaque PAC and other formats remain unknown.",
                     "Header signatures are triage candidates, not established executable code; absence proves nothing about raw code.",
                     "Script structural candidates do not prove interpreter association or semantic coverage."], records=records)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--original', type=Path, default=Path('extract/baserom_dqix_usa.nds'))
    parser.add_argument('--rebuilt', type=Path, default=Path('dqix_usa.nds'))
    parser.add_argument('--output', type=Path, default=Path('build/usa/assets-audit.json'))
    args = parser.parse_args()
    result = audit(args.original.read_bytes(), args.rebuilt.read_bytes())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in result.items() if k != 'records'}, indent=2))


if __name__ == '__main__':
    main()
