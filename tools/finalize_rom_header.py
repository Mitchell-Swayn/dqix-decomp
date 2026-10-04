#!/usr/bin/env python3
"""Preserve verified cartridge checksum metadata without requiring a BIOS.

ds-rom 0.6.1 emits a zero secure-area CRC when its encryption key is absent.
The supplied cartridge already contains that checksum. It is reusable only if
the entire corresponding stored secure-area payload is unchanged. No program
bytes are copied or repaired here; the final ROM must pass the target SHA-1.
"""

import argparse
import hashlib
from pathlib import Path
import struct
import sys
from guard_rom_files import check_paths


USA_SHA1 = "c7c3014c237900c8281289b8bc76a781969b6278"
JPN_SHA1 = "4b219246c06343ad56cedfb183ea3bd737776eda"
TARGETS = {b"YDQE": ("USA", USA_SHA1), b"YDQJ": ("JPN", JPN_SHA1)}
HEADER_SIZE = 0x160
SECURE_START = 0x4000
SECURE_END = 0x8000


def crc16(data):
    value = 0xffff
    for byte in data:
        value ^= byte
        for _ in range(8):
            value = (value >> 1) ^ (0xa001 if value & 1 else 0)
    return value


def restore_metadata(rebuilt, original_header, original_secure_area):
    """Return a new image; reject changed data before reusing its checksum."""
    if len(rebuilt) < SECURE_END or len(original_header) != HEADER_SIZE:
        raise ValueError("Truncated ROM/header")
    if len(original_secure_area) != SECURE_END - SECURE_START:
        raise ValueError("Truncated reference secure area")
    if bytes(original_header[12:16]) not in TARGETS or rebuilt[12:16] != original_header[12:16]:
        raise ValueError("Only matching verified USA/JPN cartridge layouts are supported")
    if struct.unpack_from("<I", original_header, 0x20)[0] != SECURE_START:
        raise ValueError("Unexpected original ARM9 offset")
    if struct.unpack_from("<I", rebuilt, 0x20)[0] != SECURE_START:
        raise ValueError("Unexpected rebuilt ARM9 offset")
    for label, header in (("original", original_header), ("rebuilt", rebuilt[:HEADER_SIZE])):
        if crc16(header[:0x15e]) != struct.unpack_from("<H", header, 0x15e)[0]:
            raise ValueError(f"Invalid {label} header CRC16")
    if rebuilt[SECURE_START:SECURE_END] != original_secure_area:
        raise ValueError("Rebuilt secure-area bytes differ; checksum metadata cannot be reused")
    if rebuilt[0x6c:0x6e] not in (b"\0\0", original_header[0x6c:0x6e]):
        raise ValueError("Unexpected rebuilt secure-area CRC16")
    result = bytearray(rebuilt)
    result[0x6c:0x6e] = original_header[0x6c:0x6e]
    struct.pack_into("<H", result, 0x15e, crc16(result[:0x15e]))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--baserom", type=Path, default=Path("extract/baserom_dqix_usa.nds"))
    args = parser.parse_args()
    if args.output.resolve() in (args.input.resolve(), args.baserom.resolve()):
        parser.error("Output must be separate from both inputs")
    try:
        check_paths([args.input, args.baserom], [args.output])
        with args.baserom.open("rb") as stream:
            source_sha1 = hashlib.file_digest(stream, "sha1").hexdigest()
            stream.seek(0)
            header = stream.read(HEADER_SIZE)
            target = TARGETS.get(header[12:16])
            if target is None or source_sha1 != target[1]:
                raise ValueError("Reference ROM is not a verified USA/JPN input")
            region, expected_sha1 = target
            stream.seek(SECURE_START)
            secure_area = stream.read(SECURE_END - SECURE_START)
        if args.input.stat().st_size != args.baserom.stat().st_size:
            raise ValueError("Rebuilt ROM size differs")
        result = restore_metadata(args.input.read_bytes(), header, secure_area)
        if hashlib.sha1(result).hexdigest() != expected_sha1:
            raise ValueError(f"Final {region} SHA-1 differs: other bytes remain unmatched")
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_bytes(result)
        print(f"{region} ROM PASS: {expected_sha1}; original secure-area CRC metadata preserved "
              "after exact secure-area comparison; header CRC recomputed")
    except (OSError, ValueError) as error:
        print(f"ROM finalization FAIL: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
