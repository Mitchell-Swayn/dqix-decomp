#!/usr/bin/env python3
"""Optional differential tests against original USA ARM9 decompression routines.

Explicit run: python tools/test_gpc_native.py --samples-per-kind 8
Requires optional unicorn==2.1.4 and an existing user-ROM extraction. Standard
unittest discovery skips this integration test unless DQIX_NATIVE_GPC_TESTS=1.
No game bytes are embedded in this file or written into the report.
"""

import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import random
import struct
import unittest

import gpc


FUNCTIONS = {1: 0x020CAA10, 2: 0x020CAB94, 3: 0x020CAB94, 4: 0x020CA95C}
CODE_START, CODE_END = 0x020CA95C, 0x020CAD00
ALGORITHM_SHA256 = "0207844940c601f90e02c46844db494934b3efcbe930e4898e98a3ec7d5b5bf5"
ARM9_BASE = 0x02000000
CONTEXT, INPUT, OUTPUT = 0x10000000, 0x11000000, 0x15000040
STACK, RETURN = 0x1E000000, 0x1F000000
FRAGMENTS = (1, 2, 3, 7, 31, 257, 1024, 4096, 16384)


def rounded_page(size):
    return (size + 4095) & ~4095


def native_decompress(arm9, compressed, fragmented=False):
    """Call the native algorithm with the initialization done by ExtendedNitroVM.

    Huffman output is word-written; retain up to three padding bytes beyond the
    logical output, but compare only the declared length. Guard bytes surround
    that rounded output allocation. Input has readable padding for native LDRs.
    """
    from unicorn import Uc, UC_ARCH_ARM, UC_MODE_ARM
    from unicorn.arm_const import (UC_CPU_ARM_946, UC_ARM_REG_CPSR,
                                   UC_ARM_REG_LR, UC_ARM_REG_PC, UC_ARM_REG_R0,
                                   UC_ARM_REG_R1, UC_ARM_REG_R2, UC_ARM_REG_SP)
    prefix, = struct.unpack_from("<I", compressed)
    kind, size = prefix & 7, prefix >> 3
    if kind not in FUNCTIONS:
        raise ValueError("Native harness targets kinds 1, 2, 3 and 4")
    emulator = Uc(UC_ARCH_ARM, UC_MODE_ARM)
    emulator.ctl_set_cpu_model(UC_CPU_ARM_946)
    emulator.mem_map(ARM9_BASE, rounded_page(len(arm9)))
    emulator.mem_write(ARM9_BASE, arm9)
    emulator.mem_map(CONTEXT, 4096)
    body = compressed[4:]
    emulator.mem_map(INPUT, rounded_page(len(body) + 8))
    emulator.mem_write(INPUT, body + bytes(8))
    output_capacity = (size + 3) & ~3
    emulator.mem_map(OUTPUT - 64, rounded_page(output_capacity + 128))
    emulator.mem_write(OUTPUT - 64, b"\xa5" * (output_capacity + 128))
    emulator.mem_map(STACK, 0x10000)
    emulator.mem_map(RETURN, 4096)
    context = bytearray(0x228)
    struct.pack_into("<II", context, 0, OUTPUT, size)
    struct.pack_into("<III", context, 0x21C, size, kind, OUTPUT + output_capacity)
    if kind == 1:
        context[0x11] = 3
    elif kind in (2, 3):
        struct.pack_into("<I", context, 8, CONTEXT + 0x1C)
        struct.pack_into("<h", context, 0x14, -1)
        context[0x18] = 1 << kind
    emulator.mem_write(CONTEXT, bytes(context))
    offset, calls = 0, 0
    while offset < len(body):
        count = min(len(body) - offset, FRAGMENTS[calls % len(FRAGMENTS)]) if fragmented else len(body)
        emulator.reg_write(UC_ARM_REG_CPSR, 0x13)
        emulator.reg_write(UC_ARM_REG_R0, CONTEXT)
        emulator.reg_write(UC_ARM_REG_R1, INPUT + offset)
        emulator.reg_write(UC_ARM_REG_R2, count)
        emulator.reg_write(UC_ARM_REG_SP, STACK + 0xFFF0)
        emulator.reg_write(UC_ARM_REG_LR, RETURN)
        emulator.emu_start(FUNCTIONS[kind], RETURN, timeout=10_000_000,
                           count=max(100_000, size * 500 + len(body) * 100))
        if emulator.reg_read(UC_ARM_REG_PC) != RETURN:
            raise AssertionError("Native routine exhausted instruction/time budget")
        offset += count
        calls += 1
        remaining, = struct.unpack("<I", emulator.mem_read(CONTEXT + 4, 4))
        if remaining == 0:
            break
    remaining, = struct.unpack("<I", emulator.mem_read(CONTEXT + 4, 4))
    if remaining:
        raise AssertionError(f"Native decompression incomplete: {remaining} bytes remain")
    if emulator.mem_read(OUTPUT - 64, 64) != b"\xa5" * 64:
        raise AssertionError("Native output underflow")
    if emulator.mem_read(OUTPUT + output_capacity, 64) != b"\xa5" * 64:
        raise AssertionError("Native output overflow beyond rounded allocation")
    return bytes(emulator.mem_read(OUTPUT, size)), calls


def synthetic_cases():
    def packed(kind, size, body):
        return struct.pack("<I", size << 3 | kind) + body
    literals = b"".join(b"\0" + bytes(range(i, i + 8)) for i in range(0, 256, 8)) * 16
    return [
        ("synthetic/lz-overlapping-copy", packed(1, 9, b"\x20AB\x40\x01")),
        ("synthetic/lz-maximum-token-length", packed(1, 19, b"\x40A\xf0\x00")),
        ("synthetic/lz-maximum-distance", packed(1, 4099, literals + b"\x80\x0f\xff")),
        ("synthetic/huffman-nibbles-partial-word", packed(2, 9, b"\x01\xc0\x01\x0a" + struct.pack("<I", 0x55555555))),
        ("synthetic/huffman-bytes-partial-word", packed(3, 7, b"\x01\xc0AB" + struct.pack("<I", 0x55555555))),
        ("synthetic/rle-literals-max-run", packed(4, 134, b"\x02ABC\xffx\x00z")),
    ]


def compressed_sections(path):
    """Read GPC2 stored spans without first decoding their member payloads."""
    data = path.read_bytes()
    header = struct.unpack("<4s6HI", gpc.take(data, 0, 20))
    magic, count_flags, header_words, table_end_words, first_words, table_words, name_words, flags = header
    if magic != b"GPC2" or header_words != 5:
        raise ValueError(f"Unexpected GPC2 header: {path}")
    table_end, first = table_end_words * 4, first_words * 4
    table_data = gpc.take(data, 20, table_end - 20)
    yield "file-table", table_data
    table = gpc.decompress(table_data)
    if len(table) != (count_flags & 4095) * 12 or len(table) != table_words * 4:
        raise ValueError(f"Unexpected GPC2 file table: {path}")
    if name_words:
        yield "name-table", gpc.take(data, table_end, first - table_end)
    if not flags & 0x10000000:
        for index in range(count_flags & 4095):
            _, offsets, lengths = struct.unpack_from("<III", table, index * 12)
            yield f"member-{index}", gpc.take(data, first + (offsets & 0xFFFFFF) * 4, lengths & 0xFFFFFF)


def sample_cases(files_root, samples_per_kind, maximum):
    randomizer = random.Random(9)
    samples = {kind: [] for kind in FUNCTIONS}
    seen = {kind: 0 for kind in FUNCTIONS}
    largest = {}
    files = 0
    for path in sorted(files_root.rglob("*.gp2")):
        files += 1
        for label, data in compressed_sections(path):
            prefix, = struct.unpack("<I", gpc.take(data, 0, 4))
            kind, size = prefix & 7, prefix >> 3
            if kind not in samples or size == 0 or size > maximum:
                continue
            seen[kind] += 1
            identifier = f"{path.relative_to(files_root).as_posix()}:{label}"
            if kind not in largest or size > largest[kind][0]:
                largest[kind] = (size, identifier, data)
            if len(samples[kind]) < samples_per_kind:
                samples[kind].append((identifier, data))
            else:
                choice = randomizer.randrange(seen[kind])
                if choice < samples_per_kind:
                    samples[kind][choice] = (identifier, data)
    if not files:
        raise ValueError("No extracted .gp2 files found")
    result = [case for kind in sorted(samples) for case in samples[kind]]
    names = {name for name, _ in result}
    result.extend((name, data) for _, name, data in largest.values() if name not in names)
    return result, seen, files


def validate(arm9_path, files_root, samples_per_kind=8, maximum=512 * 1024):
    arm9 = arm9_path.read_bytes()
    algorithm_hash = hashlib.sha256(arm9[CODE_START - ARM9_BASE:CODE_END - ARM9_BASE]).hexdigest()
    if algorithm_hash != ALGORITHM_SHA256:
        raise ValueError("Native algorithm bytes do not match the pinned USA extraction")
    sampled, seen, files = sample_cases(files_root, samples_per_kind, maximum)
    rows = []
    for name, compressed in synthetic_cases() + sampled:
        expected = gpc.decompress(compressed, maximum=maximum)
        for fragmented in (False, True):
            try:
                actual, calls = native_decompress(arm9, compressed, fragmented)
            except Exception as error:
                raise AssertionError(f"{name} fragmented={fragmented}: {error}") from error
            if actual != expected:
                first = next(i for i, (a, b) in enumerate(zip(actual, expected)) if a != b)
                raise AssertionError(f"{name} fragmented={fragmented}: mismatch at output byte {first}")
            rows.append({"sample": name, "kind": compressed[0] & 7,
                         "compressed_size": len(compressed), "output_size": len(expected),
                         "compressed_sha256": hashlib.sha256(compressed).hexdigest(),
                         "output_sha256": hashlib.sha256(actual).hexdigest(),
                         "fragmented": fragmented, "native_calls": calls, "matched": True})
    import unicorn
    return {"schema_version": 1, "unicorn_version": unicorn.__version__,
            "cpu": "ARM946", "arm9_sha256": hashlib.sha256(arm9).hexdigest(),
            "algorithm_bytes_sha256": algorithm_hash,
            "gpc_decoder_sha256": hashlib.sha256(Path(gpc.__file__).read_bytes()).hexdigest(),
            "functions": {str(k): hex(v) for k, v in FUNCTIONS.items()},
            "gpc_files_scanned": files, "eligible_sections_by_kind": seen,
            "sample_limit_per_kind": samples_per_kind, "maximum_output_size": maximum,
            "comparisons": len(rows), "all_matched": True, "samples": rows}


@unittest.skipUnless(os.environ.get("DQIX_NATIVE_GPC_TESTS") == "1" and importlib.util.find_spec("unicorn"),
                     "optional native-ROM test: set DQIX_NATIVE_GPC_TESTS=1 and install unicorn")
class NativeGpcTests(unittest.TestCase):
    def test_native_routines_match_decoder(self):
        root = Path(__file__).resolve().parent.parent
        report = validate(root / "extract/usa/arm9/arm9.bin", root / "extract/usa/files", 2)
        self.assertTrue(report["all_matched"])


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--arm9", type=Path, default=Path("extract/usa/arm9/arm9.bin"))
    parser.add_argument("--files", type=Path, default=Path("extract/usa/files"))
    parser.add_argument("--samples-per-kind", type=int, default=8)
    parser.add_argument("--maximum", type=int, default=512 * 1024)
    parser.add_argument("--report", type=Path, default=Path("build/usa/gpc-native-validation.json"))
    args = parser.parse_args()
    if args.samples_per_kind < 1:
        parser.error("--samples-per-kind must be positive")
    if args.report.is_file():
        args.report.unlink()
    report = validate(args.arm9, args.files, args.samples_per_kind, args.maximum)
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"Native GPC PASS: {report['comparisons']} comparisons; report: {args.report}")
