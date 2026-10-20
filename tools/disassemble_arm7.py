#!/usr/bin/env python3
"""Print raw ARM7 disassembly for an explicit runtime address range.

This tool maps addresses through the ROM header and ARM7 autoload inventory.
It does not discover function boundaries or classify arbitrary bytes as code.
Source-unit byte counts are aggregate totals, not positions. Mixed units stay
raw unless a whole range is homogeneous by manifest classification.
"""

from dataclasses import dataclass
import argparse
import hashlib
import json
from pathlib import Path
import sys

from check_arm7 import read_arm7, sha1_file
from arm7_build import validate_layout


ROOT = Path(__file__).resolve().parent.parent


@dataclass(frozen=True)
class PayloadRange:
    module: str
    runtime_start: int
    runtime_end: int
    payload_start: int
    payload_end: int


def address_to_payload(start, end, baseline, config):
    """Map an end-exclusive runtime range to the original ARM7 payload.

    Startup bytes use the ARM7 header load address and begin at payload offset
    zero. Later ranges must fit wholly in one inventory autoload. Cross-region,
    reversed, empty, unmapped and out-of-payload ranges are rejected.
    """
    if not isinstance(start, int) or not isinstance(end, int):
        raise ValueError("addresses must be integers")
    if start >= end:
        raise ValueError("range must be nonempty and end-exclusive")

    payload_size = baseline.get("size")
    load_address = baseline.get("load_address")
    startup_size = config.get("startup_size")
    if not all(isinstance(value, int) and value > 0 for value in
               (payload_size, startup_size)):
        raise ValueError("invalid ARM7 payload or startup size")
    if not isinstance(load_address, int):
        raise ValueError("invalid ARM7 load address")

    regions = [PayloadRange("startup", load_address,
                            load_address + startup_size, 0, startup_size)]
    for module in config.get("autoloads", []):
        name = module.get("name")
        runtime = module.get("runtime_address")
        offset = module.get("payload_offset")
        size = module.get("size")
        if not isinstance(name, str) or not all(isinstance(v, int) for v in
                                                 (runtime, offset, size)) or size <= 0:
            raise ValueError("invalid ARM7 autoload mapping")
        if offset < 0 or offset + size > payload_size:
            raise ValueError(f"{name}: autoload mapping exceeds ARM7 payload")
        regions.append(PayloadRange(name, runtime, runtime + size,
                                    offset, offset + size))

    regions.sort(key=lambda region: region.payload_start)
    prior_payload_end = 0
    for region in regions:
        if region.payload_start != prior_payload_end:
            raise ValueError("startup/autoload payload mappings are not contiguous")
        if region.runtime_start >= region.runtime_end:
            raise ValueError(f"{region.module}: invalid runtime mapping")
        prior_payload_end = region.payload_end
    if prior_payload_end > payload_size:
        raise ValueError("ARM7 mapping exceeds payload")
    table = config.get("autoload_table_offset")
    if (not isinstance(table, int) or table != prior_payload_end
            or table + len(config.get("autoloads", [])) * 12 != payload_size):
        raise ValueError("startup/autoload mappings do not end at the descriptor table")
    runtime_regions = sorted(regions, key=lambda region: region.runtime_start)
    for left, right in zip(runtime_regions, runtime_regions[1:]):
        if left.runtime_end > right.runtime_start:
            raise ValueError("startup/autoload runtime mappings overlap")

    matches = [region for region in regions
               if region.runtime_start <= start < end <= region.runtime_end]
    if len(matches) != 1:
        raise ValueError("range is unmapped, crosses a startup/autoload boundary, or exceeds a mapping")
    region = matches[0]
    payload_start = region.payload_start + start - region.runtime_start
    payload_end = payload_start + end - start
    if payload_start < 0 or payload_end > payload_size:
        raise ValueError("mapped range is truncated by the ARM7 payload")
    return PayloadRange(region.module, start, end, payload_start, payload_end)


def exact_source_unit(start, end, config):
    """Return the exact source unit for this range, if the manifest has one."""
    matches = [unit for unit in config.get("units", [])
               if unit.get("runtime_address") == start
               and unit.get("size") == end - start]
    if len(matches) > 1:
        raise ValueError("multiple source units claim this exact range")
    return matches[0] if matches else None


def parse_hex_address(value):
    try:
        return int(value.removeprefix("0x").removeprefix("0X"), 16)
    except ValueError as error:
        raise argparse.ArgumentTypeError("address must be hexadecimal") from error


def load_original(rom_path, baseline_path, units_path):
    baseline = json.loads(baseline_path.read_text(encoding="utf-8"))
    config = json.loads(units_path.read_text(encoding="utf-8"))
    digest = sha1_file(rom_path)
    if digest != baseline["source_rom_sha1"]:
        raise ValueError("ROM SHA-1 does not match the recorded original USA input")
    metadata, payload = read_arm7(rom_path)
    for key in ("rom_offset", "entry_address", "load_address", "size",
                "overlay_table_size", "payload_sha1"):
        if metadata[key] != baseline[key]:
            raise ValueError(f"ROM header ARM7 {key} differs from baseline")
    if hashlib.sha1(payload).hexdigest() != baseline["payload_sha1"]:
        raise ValueError("ARM7 payload SHA-1 differs from baseline")
    if metadata["overlay_table_size"] != 0:
        raise ValueError("ARM7 overlays need a separate inventory")
    validate_layout(payload, baseline, config)
    return payload, baseline, config


def disassemble_bytes(data, start, mode):
    try:
        from capstone import (Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN,
                              CS_MODE_THUMB)
    except ImportError as error:
        raise ValueError("Capstone is required; install the project's Python tools") from error
    if mode == "arm":
        alignment = 4
        capstone_mode = CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN
        raw_width = 4
    elif mode == "thumb":
        alignment = 2
        capstone_mode = CS_MODE_THUMB | CS_MODE_LITTLE_ENDIAN
        raw_width = 2
    else:
        raise ValueError("mode must be arm or thumb")
    if start % alignment or len(data) % alignment:
        raise ValueError(f"{mode.upper()} range start and size must be {alignment}-byte aligned")
    decoder = Cs(CS_ARCH_ARM, capstone_mode)
    decoder.skipdata = True
    lines = []
    for instruction in decoder.disasm(data, start):
        raw = instruction.bytes.hex(" ")
        if instruction.mnemonic == ".byte":
            lines.append(f"{instruction.address:08x}: {raw:<11} .byte     {instruction.op_str}")
        else:
            lines.append(f"{instruction.address:08x}: {raw:<11} {instruction.mnemonic:<8} {instruction.op_str}")
    if not lines and data:
        for offset in range(0, len(data), raw_width):
            chunk = data[offset:offset + raw_width]
            lines.append(f"{start + offset:08x}: {chunk.hex(' '):<11} .byte     {', '.join(f'0x{byte:02x}' for byte in chunk)}")
    return lines


def label_raw_bytes(data, start, label):
    """Render manifest-classified bytes without decoding them as instructions."""
    lines = []
    for offset in range(0, len(data), 4):
        chunk = data[offset:offset + 4]
        if len(chunk) == 4:
            value = int.from_bytes(chunk, "little")
            lines.append(f"{start + offset:08x}: {chunk.hex(' '):<11} .{label:<8} 0x{value:08x}")
        else:
            lines.append(f"{start + offset:08x}: {chunk.hex(' '):<11} .byte     {', '.join(f'0x{byte:02x}' for byte in chunk)}")
    return lines


def manifest_range_lines(data, start, mode, unit):
    """Render an exact unit without treating aggregate counts as byte offsets."""
    if unit is None:
        return disassemble_bytes(data, start, mode)
    parts = (unit.get("code_bytes", 0), unit.get("reviewed_assembly_bytes", 0),
             unit.get("literal_pool_bytes", 0), unit.get("data_bytes", 0))
    if any(not isinstance(size, int) or size < 0 for size in parts) or sum(parts) != len(data):
        raise ValueError("exact source unit has invalid byte classifications")
    code_size, assembly_size, literal_size, data_size = parts
    if data_size == len(data) and not (code_size or assembly_size or literal_size):
        return label_raw_bytes(data, start, "data")
    if literal_size == len(data) and not (code_size or assembly_size or data_size):
        return label_raw_bytes(data, start, "literal")
    if code_size == len(data) and not (assembly_size or literal_size or data_size):
        return disassemble_bytes(data, start, mode)
    if assembly_size == len(data) and not (code_size or literal_size or data_size):
        return disassemble_bytes(data, start, mode)
    # Manifest counts do not identify where literals or other classes occur.
    return disassemble_bytes(data, start, mode)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("start", type=parse_hex_address, help="start runtime address (hexadecimal)")
    parser.add_argument("end", type=parse_hex_address, help="end-exclusive runtime address (hexadecimal)")
    parser.add_argument("--mode", required=True, choices=("arm", "thumb"),
                        help="decode mode; no mode switching is inferred")
    parser.add_argument("--rom", type=Path, default=ROOT / "extract/baserom_dqix_usa.nds",
                        help="verified original USA ROM (default: extract/baserom_dqix_usa.nds)")
    parser.add_argument("--baseline", type=Path, default=ROOT / "config/usa/arm7/baseline.json")
    parser.add_argument("--units", type=Path, default=ROOT / "config/usa/arm7/source_units.json")
    args = parser.parse_args(argv)
    try:
        payload, baseline, config = load_original(args.rom, args.baseline, args.units)
        mapped = address_to_payload(args.start, args.end, baseline, config)
        data = payload[mapped.payload_start:mapped.payload_end]
        if len(data) != args.end - args.start:
            raise ValueError("mapped ARM7 range is truncated")
        print("RAW ARM7 DISASSEMBLY (not function discovery or code coverage)")
        print("Mixed units use raw decoding: manifest byte counts do not locate literal pools or data.")
        print(f"Range: [{args.start:#010x}, {args.end:#010x}) mode={args.mode} mapping={mapped.module}")
        print(f"ROM payload bytes: [{mapped.payload_start}, {mapped.payload_end})")
        unit = exact_source_unit(args.start, args.end, config)
        if unit:
            print(f"Source-unit annotation: {unit['name']} ({unit['source']})")
            print("Manifest aggregate counts (no byte positions inferred): " + ", ".join(
                f"{key}={unit.get(key, 0)}" for key in
                ("code_bytes", "literal_pool_bytes", "data_bytes", "reviewed_assembly_bytes")))
            classified = (unit.get("code_bytes", 0), unit.get("literal_pool_bytes", 0),
                          unit.get("data_bytes", 0), unit.get("reviewed_assembly_bytes", 0))
            if unit.get("data_bytes", 0) == unit.get("size") and not any(
                    unit.get(key, 0) for key in
                    ("code_bytes", "literal_pool_bytes", "reviewed_assembly_bytes")):
                print("Byte rendering: homogeneous manifest data unit.")
            elif unit.get("literal_pool_bytes", 0) == unit.get("size") and not any(
                    unit.get(key, 0) for key in
                    ("code_bytes", "data_bytes", "reviewed_assembly_bytes")):
                print("Byte rendering: homogeneous manifest literal unit.")
            elif ((unit.get("code_bytes", 0) == unit.get("size")
                   and not any(unit.get(key, 0) for key in
                               ("literal_pool_bytes", "data_bytes", "reviewed_assembly_bytes")))
                  or (unit.get("reviewed_assembly_bytes", 0) == unit.get("size")
                      and not any(unit.get(key, 0) for key in
                                  ("code_bytes", "literal_pool_bytes", "data_bytes")))):
                print("Byte rendering: homogeneous manifest instruction class.")
            elif any(classified) and sum(value > 0 for value in classified) > 1:
                print("Byte rendering: raw; aggregate counts do not identify class positions.")
            else:
                print("Byte rendering: raw; manifest counts do not identify class positions.")
        else:
            print("Source-unit annotation: none; code/data partition unknown.")
        for line in manifest_range_lines(data, args.start, args.mode, unit):
            print(line)
        return 0
    except (OSError, ValueError, KeyError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
