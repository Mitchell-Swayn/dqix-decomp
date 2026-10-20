"""Align assembler mapping metadata with dsd's original ARM9 objects.

dsd 0.10.2 omits ARM $d mapping symbols for its named 256-byte division tables
inside .text. mwasm emits them, causing objdiff to compare data against
instructions despite identical bytes. Anonymize only those local metadata
symbols and retain mapping for ordinary literal pools; never alter code,
literal bytes, public symbols, relocations or section sizes. Section-symbol
st_size is cleared because it is metadata, not an additional sized object.
"""
from pathlib import Path
import struct
import sys


def normalize(path):
    data = bytearray(Path(path).read_bytes())
    if data[:6] != b'\x7fELF\x01\x01':
        raise ValueError('Expected little-endian ELF32 assembler object')
    offset = struct.unpack_from('<I', data, 32)[0]
    stride, count = struct.unpack_from('<HH', data, 46)
    sections = [struct.unpack_from('<10I', data, offset + i * stride) for i in range(count)]
    for section in sections:
        if section[1] != 2:
            continue
        strings = sections[section[6]]
        names = data[strings[4]:strings[4] + strings[5]]
        table_offsets = set()
        for position in range(section[4], section[4] + section[5], section[9]):
            name, value, size, info, other, index = struct.unpack_from('<IIIBBH', data, position)
            label = bytes(names[name:]).split(b'\0', 1)[0]
            if info & 15 == 3:
                struct.pack_into('<I', data, position + 8, 0)
            if info & 15 == 1 and size == 256 and label.startswith(b'.L_'):
                table_offsets.add((index, value))
        for position in range(section[4], section[4] + section[5], section[9]):
            name, value, size, info, other, index = struct.unpack_from('<IIIBBH', data, position)
            label = bytes(names[name:]).split(b'\0', 1)[0]
            if (info >> 4 == 0 and (index, value) in table_offsets and
                    (label == b'$d' or label.startswith(b'$d.'))):
                struct.pack_into('<I', data, position, name + 1)
                data[position + 12] = 0
    Path(path).write_bytes(data)


if __name__ == '__main__':
    normalize(sys.argv[1])
