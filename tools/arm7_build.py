#!/usr/bin/env python3
"""Compile, link, verify and package declared ARM7 source slices.

Unreconstructed bytes remain explicit binary fallback. Source units are linked
at runtime (autoload) addresses, then placed at their cartridge payload offsets.
The pinned dsd tool does not support this ARM7 operation.
"""

import argparse
import hashlib
import json
import re
from pathlib import Path
import struct
import subprocess
import sys

from check_arm7 import read_arm7, sha1_file


CC_FLAGS = ["-O2", "-proc", "arm7tdmi", "-fp", "soft", "-interworking",
            "-enum", "int", "-char", "signed", "-inline", "noauto",
            "-lang=c", "-sym", "on", "-gccinc", "-nolink"]


def read_elf(path):
    """Read the ELF32 ARM section and symbol subset needed for MWLD checks."""
    data = path.read_bytes()
    if data[:7] != b"\x7fELF\x01\x01\x01" or len(data) < 52:
        raise ValueError(f"{path}: expected little-endian ELF32")
    header = struct.unpack_from("<16sHHIIIIIHHHHHH", data)
    if header[2] != 40:
        raise ValueError(f"{path}: expected ARM ELF machine")
    shoff, shsize, count, names_index = header[6], header[11], header[12], header[13]
    if shsize != 40 or shoff + count * shsize > len(data) or names_index >= count:
        raise ValueError(f"{path}: invalid ELF section table")
    sections = [struct.unpack_from("<10I", data, shoff + i * shsize) for i in range(count)]

    def contents(section):
        start, size = section[4:6]
        if start + size > len(data):
            raise ValueError(f"{path}: truncated ELF section")
        return data[start:start + size]

    def string(table, offset):
        end = table.find(b"\0", offset)
        if end < 0:
            raise ValueError(f"{path}: invalid ELF string")
        return table[offset:end].decode("ascii")

    names = contents(sections[names_index])
    allocated = []
    symbols = {}
    for section in sections:
        name = string(names, section[0])
        # MWLD marks its linked memory image with SHF_MASKPROC (0x10000000)
        # rather than ELF's usual SHF_ALLOC. Require an actual load address.
        if (section[2] & 2 or section[3]) and section[5]:
            if section[1] != 1:
                raise ValueError(f"{path}: unexpected allocated section {name}")
            allocated.append((name, section[3], contents(section)))
        if section[1] == 2:
            strings = contents(sections[section[6]])
            entries = contents(section)
            if section[9] != 16 or len(entries) % 16:
                raise ValueError(f"{path}: invalid ELF symbol table")
            for offset in range(0, len(entries), 16):
                name_offset, value, size, info, other, index = struct.unpack_from("<IIIBBH", entries, offset)
                name = string(strings, name_offset)
                if name and index:
                    symbols[name] = value
    return allocated, symbols


def validate_layout(payload, baseline, config):
    """Validate the startup copy descriptors, not a guessed contiguous mapping."""
    base = baseline["load_address"]
    params = struct.unpack_from("<6I", payload, config["autoload_parameters_offset"])
    table = config["autoload_table_offset"]
    if params != (base + table, base + len(payload),
                  base + config["startup_size"], base + config["startup_size"],
                  base + config["startup_size"], 0):
        raise ValueError("ARM7 startup autoload parameters differ from inventory")
    cursor = config["startup_size"]
    if table + len(config["autoloads"]) * 12 != len(payload):
        raise ValueError("ARM7 autoload table does not end at payload boundary")
    for index, module in enumerate(config["autoloads"]):
        actual = struct.unpack_from("<3I", payload, table + index * 12)
        if actual != (module["runtime_address"], module["size"], module["bss_size"]):
            raise ValueError(f"ARM7 {module['name']} autoload descriptor differs")
        if module["payload_offset"] != cursor:
            raise ValueError("ARM7 autoload source ranges are not contiguous")
        cursor += module["size"]
    if cursor != table:
        raise ValueError("ARM7 autoload sources do not reach descriptor table")
    end = 0
    for unit in sorted(config["units"], key=lambda item: item["payload_offset"]):
        start, size = unit["payload_offset"], unit["size"]
        module = next(m for m in config["autoloads"] if m["name"] == unit["autoload"])
        if start < end or start < module["payload_offset"] or start + size > module["payload_offset"] + module["size"]:
            raise ValueError("ARM7 source unit overlaps or lies outside its autoload")
        if unit["runtime_address"] != module["runtime_address"] + start - module["payload_offset"]:
            raise ValueError("ARM7 source unit runtime mapping differs")
        if unit["code_bytes"] + unit["literal_pool_bytes"] != size:
            raise ValueError("ARM7 source unit byte classification does not sum to size")
        end = start + size


def write_rom_config(source_path, output_path, arm7_bin):
    # Keeping the config beside dsd's output preserves every other relative path.
    if source_path.resolve().parent != output_path.resolve().parent:
        raise ValueError("ARM7 ROM config must be beside its input ROM config")
    if source_path.resolve() == output_path.resolve():
        raise ValueError("ARM7 ROM config must not overwrite the ARM9 ROM config")
    original = source_path.read_text(encoding="utf-8")
    replacement = "arm7_bin: " + json.dumps(arm7_bin.resolve().as_posix())
    result, count = re.subn(r"^arm7_bin:.*$", lambda _: replacement, original, flags=re.MULTILINE)
    if count != 1:
        raise ValueError("Expected exactly one arm7_bin in dsd ROM config")
    output_path.write_text(result, encoding="utf-8")


def build(args):
    root = Path(__file__).resolve().parent.parent
    # A failed rebuild must not leave an earlier success report looking current.
    report_path = args.output / "report.json"
    if report_path.is_file():
        report_path.unlink()
    baseline = json.loads(args.baseline.read_text(encoding="utf-8"))
    config = json.loads(args.units.read_text(encoding="utf-8"))
    if sha1_file(args.baserom) != baseline["source_rom_sha1"]:
        raise ValueError("USA base ROM hash does not match baseline")
    metadata, original = read_arm7(args.baserom)
    if metadata["payload_sha1"] != baseline["payload_sha1"]:
        raise ValueError("ARM7 payload hash does not match baseline")
    validate_layout(original, baseline, config)
    args.output.mkdir(parents=True, exist_ok=True)
    compiler = args.compiler.resolve() / "mwccarm.exe"
    linker = args.compiler.resolve() / "mwldarm.exe"
    runner = [str(args.runner.resolve())] if args.runner else []
    rebuilt = bytearray(original)
    report_units = []
    for unit in config["units"]:
        name = unit["name"]
        if not re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", name):
            raise ValueError("Source unit names must be simple identifiers")
        output = (args.output / name).resolve()
        output.mkdir(parents=True, exist_ok=True)
        source = root / unit["source"]
        subprocess.run([*runner, str(compiler), *CC_FLAGS, "-c", str(source), "-o", str(output / f"{name}.o")], check=True)
        externals = "\n".join(f"    {symbol} = 0x{address:08x};" for symbol, address in unit["externals"].items())
        lcf = (f"MEMORY {{ ARM7 : ORIGIN = 0x{unit['runtime_address']:08x} }}\n"
               f"SECTIONS {{\n{externals}\n    .arm7 : {{ {name}.o(.text) }} > ARM7\n}}\n")
        (output / f"{name}.lcf").write_text(lcf, encoding="ascii")
        subprocess.run([*runner, str(linker), "-proc", "arm7tdmi", "-nostdlib", "-interworking",
                        "-m", unit["entry"], "-map", "closure,unused", "-msgstyle", "gcc",
                        f"{name}.o", f"{name}.lcf", "-o", f"{name}.elf"], cwd=output, check=True)
        sections, symbols = read_elf(output / f"{name}.elf")
        if len(sections) != 1 or sections[0][1] != unit["runtime_address"]:
            raise ValueError(f"{name}: linked section placement differs")
        linked = sections[0][2]
        start, size = unit["payload_offset"], unit["size"]
        if len(linked) != size or linked != original[start:start + size]:
            raise ValueError(f"{name}: compiled source does not match original bytes")
        for symbol, address in unit["symbols"].items():
            if symbols.get(symbol) != address:
                raise ValueError(f"{name}: linked symbol {symbol} address differs")
        rebuilt[start:start + size] = linked
        report_units.append({**unit, "source_sha1": sha1_file(source),
                             "linked_sha1": hashlib.sha1(linked).hexdigest(),
                             "module_check_passed": True, "symbol_check_passed": True})
    if rebuilt != original:
        raise ValueError("Rebuilt ARM7 payload differs")
    binary = args.output / "arm7.bin"
    binary.write_bytes(rebuilt)
    source_bytes = sum(u["size"] for u in config["units"])
    report = {
        "schema_version": 1,
        "module": "cartridge_arm7",
        "processor": "ARM7TDMI",
        "payload_sha1": hashlib.sha1(rebuilt).hexdigest(),
        "payload_bytes": len(rebuilt),
        "source_code_bytes": sum(u["code_bytes"] for u in config["units"]),
        "source_literal_pool_bytes": sum(u["literal_pool_bytes"] for u in config["units"]),
        "source_data_bytes": 0,
        "source_functions": sum(len(u["symbols"]) for u in config["units"]),
        "binary_fallback_bytes": len(rebuilt) - source_bytes,
        "reviewed_assembly_bytes": 0,
        "code_data_partition": "only reconstructed units classified; remainder unknown",
        "function_count": None,
        "module_check_passed": True,
        "source_symbol_checks_passed": True,
        "cc_flags": CC_FLAGS,
        "compiler_sha1": sha1_file(compiler),
        "linker_sha1": sha1_file(linker),
        "autoloads": config["autoloads"],
        "units": report_units,
    }
    if args.rom_config:
        target = args.output_rom_config or args.rom_config.with_name("rom_config_arm7.yaml")
        write_rom_config(args.rom_config, target, binary)
    report_path.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"ARM7 source build PASS: {source_bytes} source-owned bytes, "
          f"{len(rebuilt) - source_bytes} binary fallback bytes")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baserom", type=Path, default=Path("extract/baserom_dqix_usa.nds"))
    parser.add_argument("--baseline", type=Path, default=Path("config/usa/arm7/baseline.json"))
    parser.add_argument("--units", type=Path, default=Path("config/usa/arm7/source_units.json"))
    parser.add_argument("--compiler", type=Path, default=Path("tools/mwccarm/2.0/sp2p2"))
    parser.add_argument("--runner", type=Path, help="Path to Wine/Wibo on non-Windows hosts")
    parser.add_argument("--output", type=Path, default=Path("build/usa/arm7"))
    parser.add_argument("--rom-config", type=Path)
    parser.add_argument("--output-rom-config", type=Path)
    args = parser.parse_args()
    try:
        build(args)
    except (OSError, ValueError, KeyError, StopIteration, struct.error, subprocess.CalledProcessError) as error:
        print(f"ARM7 source build FAIL: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
