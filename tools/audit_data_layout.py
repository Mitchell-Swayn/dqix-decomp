#!/usr/bin/env python3
"""Verify source-owned initialized data against linked symbols and module bytes.

Linked MWLD ELF sections reference external module binaries. This check requires
both the generated module and independently extracted original module explicitly.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct


def number(value):
    return value if isinstance(value, int) else int(value, 16)


def symbols(path, section_name, selected_names):
    blob = Path(path).read_bytes()
    if blob[:6] != b"\x7fELF\x01\x01":
        raise ValueError("Expected little-endian ELF32")
    offset = struct.unpack_from("<I", blob, 32)[0]
    stride, count, names_index = struct.unpack_from("<HHH", blob, 46)
    if stride < 40 or offset + stride * count > len(blob):
        raise ValueError("Invalid section table")
    sections = [struct.unpack_from("<10I", blob, offset + i * stride) for i in range(count)]
    def contents(section):
        start, size = section[4:6]
        if start + size > len(blob):
            raise ValueError("Section outside ELF")
        return blob[start:start + size]
    names = contents(sections[names_index])
    selected = [i for i, s in enumerate(sections) if names[s[0]:].split(b"\0", 1)[0].decode() == section_name]
    if len(selected) != 1:
        raise ValueError("Expected one linked module section")
    index = selected[0]
    found = {}
    for table in sections:
        if table[1] != 2:
            continue
        if table[9] < 16 or table[5] % table[9] or table[6] >= count:
            raise ValueError("Invalid symbol table")
        strings = contents(sections[table[6]])
        entries = contents(table)
        for position in range(0, len(entries), table[9]):
            name, address, size, info, other, owner = struct.unpack_from("<IIIBBH", entries, position)
            if owner != index or info & 15 != 1:
                continue
            label = strings[name:].split(b"\0", 1)[0].decode()
            if label not in selected_names:
                continue
            if label in found:
                raise ValueError("Duplicate object symbol: " + label)
            found[label] = (address, size)
    return sections[index][3], found


def audit(elf, rows, section, original, generated):
    base, found = symbols(elf, section, {row["name"] for row in rows})
    if Path(original).samefile(generated):
        raise ValueError("Original and generated module must be independent files")
    left, right = Path(original).read_bytes(), Path(generated).read_bytes()
    differences = []
    intervals = []
    for row in rows:
        name, address, size = row["name"], number(row["address"]), int(row["size"])
        if row["section"] not in (".data", ".rodata", ".ctor") or size <= 0:
            raise ValueError("Only positive initialized data extents are supported")
        if any(address < end and start < address + size for start, end in intervals):
            raise ValueError("Overlapping data extents")
        intervals.append((address, address + size))
        start = address - base
        if start < 0 or start + size > min(len(left), len(right)):
            raise ValueError("Data extent outside module")
        expected, actual = left[start:start + size], right[start:start + size]
        if found.get(name) != (address, size):
            differences.append(dict(name=name, issue="symbol-layout", expected=[address, size], actual=found.get(name)))
        if expected != actual:
            differences.append(dict(name=name, issue="module-bytes"))
        if hashlib.sha256(expected).hexdigest() != row["sha256"]:
            differences.append(dict(name=name, issue="original-provenance-hash"))
    return dict(data_symbols=len(rows), data_bytes=sum(int(row["size"]) for row in rows), match=not differences, differences=differences, rom_acceptance=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("--elf", type=Path, required=True)
    parser.add_argument("--section", required=True)
    parser.add_argument("--original", type=Path, required=True)
    parser.add_argument("--generated", type=Path, required=True)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    try:
        rows = json.loads(args.manifest.read_text())["data"]
        if not rows:
            raise ValueError("No data selected")
        result = audit(args.elf, rows, args.section, args.original, args.generated)
        if args.output:
            args.output.write_text(json.dumps(result, indent=2) + "\n")
        print(json.dumps(result))
        return 0 if result["match"] else 1
    except (OSError, ValueError, KeyError, TypeError, struct.error) as error:
        print(json.dumps(dict(match=False, error=str(error))))
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
