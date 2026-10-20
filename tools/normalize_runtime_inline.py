"""Normalize only ELF metadata for reviewed CodeWarrior runtime assembly.

Instruction/literal section contents and relocations remain byte-for-byte intact.
The C++ inline assembler omits exported interior labels and treats explicit
shared-tail branch encodings as data. Restore the original public labels and
mapping metadata using the hash-bound runtime policy, never replacement code.
"""
import hashlib
import json
from pathlib import Path
import struct
import sys


def normalize(path, source, root=None):
    root = Path(root or Path(__file__).resolve().parents[1])
    source = Path(source)
    policy = json.loads((root / 'config/usa/arm9/runtime_support.json').read_text())
    row = next(r for r in policy['functions'] if r['source'] == source.as_posix())
    if row.get('assembly_form') != 'codewarrior_inline':
        raise ValueError('Not an accepted inline runtime source')
    if hashlib.sha256((root / source).read_bytes()).hexdigest() != row['source_sha256']:
        raise ValueError('Runtime inline source differs from accepted hash')
    original = Path(path).read_bytes()
    data = bytearray(original)
    if data[:7] != b'\x7fELF\x01\x01\x01':
        raise ValueError('Expected ELF32 little endian')
    section_offset = struct.unpack_from('<I', data, 32)[0]
    stride, count = struct.unpack_from('<HH', data, 46)
    sections = [list(struct.unpack_from('<10I', data, section_offset+i*stride)) for i in range(count)]
    symbol_index = next(i for i,s in enumerate(sections) if s[1] == 2)
    symbols = sections[symbol_index]
    string_index = symbols[6]
    strings = sections[string_index]
    names = bytearray(data[strings[4]:strings[4]+strings[5]])
    entries = [list(struct.unpack_from('<IIIBBH', data, pos))
               for pos in range(symbols[4],symbols[4]+symbols[5],symbols[9])]
    def name(entry):
        return bytes(names[entry[0]:]).split(b'\0',1)[0].decode()
    function = next(e for e in entries if name(e) == row['name'])
    text_index, start = function[5], function[1] & ~1
    section = sections[text_index]
    if section[1] != 1 or not section[2]&4 or start != 0 or function[2] < row['size']:
        raise ValueError('Unexpected runtime function extent')
    function[2] = row['size']
    metadata = row['inline_metadata']
    if (row.get('mode', 'arm') == 'thumb' or function[1] & 1) and metadata['branches']:
        raise ValueError('ARM shared-tail branch metadata is invalid for Thumb functions')
    for entry in entries:
        replacement = metadata.get('symbol_aliases', {}).get(name(entry))
        if replacement:
            entry[0] = len(names)
            names.extend(replacement.encode()+b'\0')
    alignment = metadata.get('text_alignment')
    if alignment is not None:
        if row.get('mode', 'arm') != 'thumb' or alignment != 2 or section[8] not in (2, 4):
            raise ValueError('Invalid source-bound Thumb text alignment')
        section[8] = alignment
    code_offsets = set()
    for branch in metadata['branches']:
        offset,cond,delta = (branch[k] for k in ('offset','condition','displacement'))
        expected = (cond<<28)|0x0a000000|(((delta-8)//4)&0xffffff)
        if struct.unpack_from('<I',data,section[4]+offset)[0] != expected:
            raise ValueError('Shared-tail branch encoding changed')
        code_offsets.add(offset)
    table_offsets = {a['offset'] for a in metadata['aliases'] if a['type'] == 1}
    for entry in entries:
        if entry[5] != text_index:
            continue
        if name(entry) == '$d' and entry[1] in code_offsets|table_offsets:
            # A non-mapping local name/type avoids objdiff's zero-sized data path.
            entry[0] += 1
            entry[3] = 0
    for alias in metadata['aliases']:
        matches = [e for e in entries if name(e) == alias['name']]
        expected = [None, alias['offset'],alias['size'],16|alias['type'],0,text_index]
        if matches:
            if matches[0][1:] != expected[1:]:
                raise ValueError('Runtime alias metadata changed')
        else:
            expected[0] = len(names)
            names.extend(alias['name'].encode()+b'\0')
            entries.append(expected)
    # Append replacement metadata tables; leave original section payloads intact.
    data.extend(bytes((-len(data))%4))
    strings[4],strings[5] = len(data),len(names)
    data.extend(names)
    data.extend(bytes((-len(data))%4))
    symbols[4],symbols[5] = len(data),len(entries)*16
    for entry in entries:
        data.extend(struct.pack('<IIIBBH',*entry))
    for index in ({symbol_index,string_index,text_index} if alignment is not None else {symbol_index,string_index}):
        struct.pack_into('<10I',data,section_offset+index*stride,*sections[index])
    for section_before in [struct.unpack_from('<10I',original,section_offset+i*stride) for i in range(count)]:
        if section_before[1] in (0,2,3,8):
            continue
        offset,size = section_before[4:6]
        if original[offset:offset+size] != data[offset:offset+size]:
            raise ValueError('Normalization changed executable/data/relocation contents')
    Path(path).write_bytes(data)


if __name__ == '__main__':
    normalize(sys.argv[1],sys.argv[2])
