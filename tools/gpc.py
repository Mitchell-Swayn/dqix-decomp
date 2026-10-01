#!/usr/bin/env python3
"""Bounded GPC2 reader derived from the reconstructed game loader.

Compression prefixes use a three-bit type and 29-bit output length, unlike the
usual Nitro compression header. Implementations follow DecompressA/B/C at USA
0x020caa10/0x020cab94/0x020ca95c. This is analysis tooling, not matching game code.
"""

import struct


def take(data, offset, size):
    if offset < 0 or size < 0 or offset + size > len(data):
        raise ValueError("Truncated GPC/compressed data")
    return data[offset:offset + size]


def decompress(data, maximum=64 * 1024 * 1024):
    prefix = struct.unpack("<I", take(data, 0, 4))[0]
    kind, size = prefix & 7, prefix >> 3
    if size > maximum:
        raise ValueError("Decompressed data exceeds audit size limit")
    if kind == 0:
        return take(data, 4, size)
    output = bytearray()
    offset = 4
    if kind == 1:
        while len(output) < size:
            flags = take(data, offset, 1)[0]
            offset += 1
            for bit in range(7, -1, -1):
                if len(output) >= size:
                    break
                if flags & (1 << bit):
                    first, second = take(data, offset, 2)
                    offset += 2
                    length, distance = (first >> 4) + 3, ((first & 15) << 8 | second) + 1
                    if distance > len(output) or len(output) + length > size:
                        raise ValueError("Invalid LZ backreference")
                    for _ in range(length):
                        output.append(output[-distance])
                else:
                    output.append(take(data, offset, 1)[0])
                    offset += 1
    elif kind == 4:
        while len(output) < size:
            control = take(data, offset, 1)[0]
            offset += 1
            length = (control & 127) + (3 if control & 128 else 1)
            if len(output) + length > size:
                raise ValueError("RLE packet exceeds declared output")
            if control & 128:
                output.extend(take(data, offset, 1) * length)
                offset += 1
            else:
                output.extend(take(data, offset, length))
                offset += length
    elif kind in (2, 3):
        tree_size = (take(data, offset, 1)[0] + 1) * 2
        tree = take(data, offset, tree_size)
        offset += tree_size
        node = 1
        pending_nibble = None
        while len(output) < size:
            word = struct.unpack("<I", take(data, offset, 4))[0]
            offset += 4
            for bit_index in range(31, -1, -1):
                bit = (word >> bit_index) & 1
                control = take(tree, node, 1)[0]
                node = (node & ~1) + ((control & 63) + 1) * 2 + bit
                value = take(tree, node, 1)[0]
                if (control << bit) & 128:
                    node = 1
                    if kind == 3:
                        output.append(value)
                    elif value > 15:
                        raise ValueError("Huffman nibble leaf exceeds four bits")
                    elif pending_nibble is None:
                        pending_nibble = value
                    else:
                        output.append(pending_nibble | value << 4)
                        pending_nibble = None
                    if len(output) == size:
                        break
    else:
        raise ValueError(f"Unknown GPC compression type {kind}")
    return bytes(output)


def members(data):
    magic, count_flags, header_words, table_end_words, first_words, table_words, name_words, flags = struct.unpack(
        "<4s6HI", take(data, 0, 20))
    if magic != b"GPC2" or header_words != 5:
        raise ValueError("Unsupported GPC2 header")
    count = count_flags & 4095
    table_end, first = table_end_words * 4, first_words * 4
    if not 20 <= table_end <= first <= len(data):
        raise ValueError("Invalid GPC2 header/table boundaries")
    if first + (flags & 0x0fffffff) * 4 != len(data):
        raise ValueError("GPC2 stored size differs from header")
    table = decompress(take(data, 20, table_end - 20))
    if len(table) != table_words * 4 or len(table) != count * 12:
        raise ValueError("GPC2 file-table count differs")
    names = decompress(take(data, table_end, first - table_end)) if name_words else b""
    if len(names) != name_words * 4:
        raise ValueError("GPC2 filename-table size differs")
    output = []
    for index in range(count):
        crc, offset_flags, size_flags = struct.unpack_from("<3I", table, index * 12)
        start = first + (offset_flags & 0xffffff) * 4
        stored_size = size_flags & 0xffffff
        stored = take(data, start, stored_size)
        payload = stored if flags & 0x10000000 else decompress(stored)
        name_offset = (offset_flags >> 24) | ((size_flags >> 24) << 8)
        name = None
        if names:
            if name_offset >= len(names) or b"\0" not in names[name_offset:]:
                raise ValueError("Invalid GPC2 filename offset")
            name = names[name_offset:].split(b"\0", 1)[0].decode("ascii", "backslashreplace")
        output.append({"id": index, "name": name, "crc": crc, "stored_offset": start,
                       "stored_size": stored_size, "compression": None if flags & 0x10000000 else stored[0] & 7,
                       "payload": payload})
    return output
