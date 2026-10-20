"""Conservative raw function comparison for little-endian ELF32 objects."""
from pathlib import Path
import struct


def read_functions(path, names_filter=None, metadata_only=False, section_filter=None):
    data = Path(path).read_bytes()
    if len(data) < 52 or data[:6] != b'\x7fELF\x01\x01':
        raise ValueError('Raw comparison requires little-endian ELF32')
    offset = struct.unpack_from('<I', data, 32)[0]
    stride, count = struct.unpack_from('<HH', data, 46)
    if stride < 40 or offset + stride * count > len(data):
        raise ValueError('Invalid ELF section table')
    sections = [struct.unpack_from('<10I', data, offset + i * stride) for i in range(count)]

    def contents(section):
        start, size = section[4:6]
        if start + size > len(data):
            raise ValueError('ELF section exceeds file bounds')
        return data[start:start + size]

    section_names = None
    if section_filter is not None:
        names_index = struct.unpack_from('<H', data, 50)[0]
        if names_index >= count:
            raise ValueError('Invalid ELF section name table')
        table = contents(sections[names_index])
        section_names = []
        for entry in sections:
            if entry[0] >= len(table):
                raise ValueError('Invalid ELF section name')
            section_names.append(table[entry[0]:].split(b'\0', 1)[0].decode('utf-8'))
        if section_filter not in section_names:
            raise ValueError(f'Missing ELF module section: {section_filter}')

    relocated = {s[7] for s in sections if s[1] in (4, 9) and s[5]}
    functions = {}
    for section in sections:
        if section[1] != 2:
            continue
        if section[6] >= count or section[9] < 16 or section[5] % section[9]:
            raise ValueError('Invalid ELF symbol table')
        names = contents(sections[section[6]])
        symbols = contents(section)
        for position in range(0, len(symbols), section[9]):
            name, value, size, info, other, index = struct.unpack_from('<IIIBBH', symbols, position)
            if info & 15 != 2 or not size or index == 0 or index >= count:
                continue
            if section_names is not None and section_names[index] != section_filter:
                continue
            if name >= len(names):
                raise ValueError('Invalid ELF symbol name')
            label = names[name:].split(b'\0', 1)[0].decode('utf-8')
            if names_filter is not None and label not in names_filter:
                continue
            if label in functions:
                raise ValueError(f'Duplicate function symbol: {label}')
            if metadata_only:
                # MWLD's linked ELF may store code in separate module binaries;
                # section sizes can be zero while symbols retain valid addresses.
                functions[label] = {'size': size, 'address': value & ~1}
                continue
            code = sections[index]
            start = (value & ~1) - code[3]  # Clear ARM Thumb symbol bit.
            content = contents(code)
            if start < 0 or start + size > len(content):
                raise ValueError(f'Function exceeds section: {label}')
            functions[label] = {'bytes': content[start:start + size], 'relocated': index in relocated,
                                'address': value & ~1}
    return functions


def compare(target, candidate):
    left, right = read_functions(target), read_functions(candidate)
    if not left and not right:
        return {'functions': [], 'raw_match': None, 'notice': 'No sized functions; raw function proof unavailable'}
    rows = []
    for name in sorted(left.keys() | right.keys()):
        a, b = left.get(name), right.get(name)
        relocated = bool((a and a['relocated']) or (b and b['relocated']))
        rows.append({'symbol': name, 'target_bytes': len(a['bytes']) if a else None,
                     'candidate_bytes': len(b['bytes']) if b else None,
                     'raw_match': None if relocated else bool(a and b and a['bytes'] == b['bytes']),
                     'relocations_present': relocated})
    return {'functions': rows, 'raw_match': None if any(r['relocations_present'] for r in rows)
            else all(r['raw_match'] for r in rows)}
