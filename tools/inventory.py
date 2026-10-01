#!/usr/bin/env python3
"""Audit USA cartridge executable containers without treating binary copies as source.

Uses only the Python standard library. Run after `ninja rom check report`.
The JSON contains metadata, ranges and hashes, never ROM payload bytes.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess

TARGET_SHA1 = "c7c3014c237900c8281289b8bc76a781969b6278"
COUNTERS = ("total_code", "matched_code", "total_data", "matched_data",
            "total_functions", "matched_functions", "complete_code", "complete_data")


def digest(data):
    return hashlib.sha256(data).hexdigest()


def bounded(data, start, size):
    if start < 0 or size < 0 or start + size > len(data):
        raise ValueError(f"ROM range outside file: {start:#x}+{size:#x}")
    return data[start:start + size]


def cartridge(data):
    if len(data) < 0x160:
        raise ValueError("Truncated NDS header")
    result = {"gamecode": data[12:16].decode("ascii"), "processors": {}, "overlays": {}}
    fat_start, fat_size = struct.unpack_from("<II", data, 0x48)
    fat = bounded(data, fat_start, fat_size)
    if len(fat) % 8:
        raise ValueError("Invalid file allocation table size")
    for cpu, offset, table_offset in (("arm9", 0x20, 0x50), ("arm7", 0x30, 0x58)):
        start, entry, address, size = struct.unpack_from("<IIII", data, offset)
        payload = bounded(data, start, size)
        result["processors"][cpu] = dict(rom_offset=start, stored_size=size,
            entry=entry, load_address=address, stored_sha256=digest(payload))
        start, size = struct.unpack_from("<II", data, table_offset)
        table = bounded(data, start, size)
        if len(table) % 32:
            raise ValueError(f"Invalid {cpu} overlay table size")
        records = []
        for record in struct.iter_unpack("<8I", table):
            oid, address, initialized, bss, ctor_start, ctor_end, fid, flags = record
            if fid * 8 + 8 > len(fat):
                raise ValueError(f"Overlay {oid} has invalid FAT file ID")
            first, last = struct.unpack_from("<II", fat, fid * 8)
            payload = bounded(data, first, last - first)
            records.append(dict(id=oid, load_address=address, initialized_size=initialized,
                bss_size=bss, ctor_start=ctor_start, ctor_end=ctor_end, file_id=fid,
                flags=flags, rom_offset=first, stored_size=len(payload), stored_sha256=digest(payload)))
        if len({r["id"] for r in records}) != len(records):
            raise ValueError(f"Duplicate {cpu} overlay IDs")
        result["overlays"][cpu] = records
    return result


def flat_numbers(path):
    # Only the documented flat integer fields of dsd extraction metadata are needed.
    return {key: int(value) for key, value in
            re.findall(r"^(\w+): (\d+)$", path.read_text(), re.M)}


def delinks(path):
    sections, sources = [], []
    current = None
    for line in path.read_text().splitlines():
        line = line.split("//", 1)[0].strip()
        if not line:
            continue
        if line.endswith(('.cpp:', '.c:', '.s:', '.S:')):
            current = {"source": line[:-1], "declared_complete": False, "ranges": []}
            sources.append(current)
        elif line == "complete":
            current["declared_complete"] = True
        elif line.startswith('.'):
            match = re.fullmatch(r"(\S+)\s+start:(0x[0-9a-fA-F]+)\s+end:(0x[0-9a-fA-F]+)(.*)", line)
            if not match:
                raise ValueError(f"Unparsed section in {path}: {line}")
            name, start, end, tail = match.groups()
            start, end = int(start, 16), int(end, 16)
            if end < start:
                raise ValueError(f"Reversed section in {path}")
            item = dict(section=name, start=start, end=end, size=end-start)
            kind = re.search(r"kind:(\w+)", tail)
            if kind:
                item["kind"] = kind[1]
                sections.append(item)
            elif current is not None:
                current["ranges"].append(item)
            else:
                raise ValueError(f"Range without owner in {path}")
    for source in sources:
        for item in source["ranges"]:
            if not any(s["section"] == item["section"] and s["start"] <= item["start"]
                       <= item["end"] <= s["end"] for s in sections):
                raise ValueError(f"Source range outside section in {path}: {item}")
    return sections, sources


def inventory(root):
    rom_path = root / "extract/baserom_dqix_usa.nds"
    rom = rom_path.read_bytes()
    sha1 = hashlib.sha1(rom).hexdigest()
    if sha1 != TARGET_SHA1:
        raise ValueError(f"Wrong USA ROM SHA-1: {sha1}")
    cart = cartridge(rom)
    extract = root / "extract/usa"
    report_path = root / "build/usa/report.json"
    report_bytes = report_path.read_bytes()
    report = json.loads(report_bytes)
    modules = []
    paths = [("main", "arm9/arm9.bin", "arm9/arm9.yaml", "arm9/delinks.txt"),
             ("itcm", "arm9/itcm.bin", "arm9/itcm.yaml", "arm9/itcm/delinks.txt"),
             ("dtcm", "arm9/dtcm.bin", "arm9/dtcm.yaml", "arm9/dtcm/delinks.txt")]
    for ov in cart["overlays"]["arm9"]:
        name = f"ov{ov['id']:03}"
        paths.append((name, f"arm9_overlays/{name}.bin", None, f"arm9/overlays/{name}/delinks.txt"))
    configured = {p.parent.name for p in (root / "config/usa/arm9/overlays").glob("*/delinks.txt")}
    expected = {f"ov{o['id']:03}" for o in cart["overlays"]["arm9"]}
    if configured != expected:
        raise ValueError(f"ROM/config overlay disagreement: {configured ^ expected}")
    source_owners = {}
    for name, binary, metadata, config in paths:
        payload = (extract / binary).read_bytes()
        sections, sources = delinks(root / "config/usa" / config)
        for source in sources:
            source_owners.setdefault(str(Path(source["source"]).with_suffix('')).replace('\\', '/'), []).append(name)
        module = dict(name=name, processor="arm9", initialized_size=len(payload),
            extracted_sha256=digest(payload), sections=sections, source_ranges=sources,
            config=config, report_coverage={k: 0 for k in COUNTERS},
            generated_fallback_units=0, source_units=0,
            verification="dsd check module hash and symbols via ninja check; report via objdiff")
        if metadata:
            module["extraction_metadata"] = flat_numbers(extract / metadata)
        else:
            ov = next(o for o in cart["overlays"]["arm9"] if name == f"ov{o['id']:03}")
            module["overlay"] = ov
            if len(payload) != ov["initialized_size"]:
                raise ValueError(f"Extracted overlay size differs: {name}")
        modules.append(module)
    by_name = {m["name"]: m for m in modules}
    for unit in report["units"]:
        owners = source_owners.get(unit["name"], [])
        if unit.get("metadata", {}).get("auto_generated"):
            owners = [unit["name"].rsplit('_', 1)[0]]
        if len(owners) != 1 or owners[0] not in by_name:
            raise ValueError(f"Unassigned/ambiguous report unit: {unit['name']}: {owners}")
        module = by_name[owners[0]]
        module["generated_fallback_units" if unit.get("metadata", {}).get("auto_generated") else "source_units"] += 1
        for key in COUNTERS:
            module["report_coverage"][key] += int(unit.get("measures", {}).get(key, 0))
    for key in COUNTERS:
        if sum(m["report_coverage"][key] for m in modules) != int(report["measures"].get(key, 0)):
            raise ValueError(f"Per-module report counters do not reconcile: {key}")
    arm7 = (extract / "arm7/arm7.bin").read_bytes()
    arm7_header = cart["processors"]["arm7"]
    if digest(arm7) != arm7_header["stored_sha256"]:
        raise ValueError("Extracted ARM7 differs from cartridge program")
    modules.append(dict(name="arm7", processor="arm7", initialized_size=len(arm7),
        extracted_sha256=digest(arm7), extraction_metadata=flat_numbers(extract / "arm7/arm7.yaml"),
        report_coverage=None, source_coverage="untracked; original binary passthrough",
        code_data_split="unknown", verification="exact extracted bytes compared to ROM header range"))
    for ov in cart["overlays"]["arm7"]:
        modules.append(dict(name=f"arm7_ov{ov['id']:03}", processor="arm7", overlay=ov,
                            report_coverage=None, source_coverage="untracked"))
    revision = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip()
    config_bytes = (root / "tools/configure.py").read_text()
    versions = dict(re.findall(r"^(DSD_VERSION|OBJDIFF_VERSION|MWCC_VERSION|WIBO_VERSION)\s*=\s*[\"']([^\"']+)", config_bytes, re.M))
    return dict(schema_version=1, source_revision=revision, rom_sha1=sha1,
        report_sha256=digest(report_bytes), report_measures=report["measures"],
        configured_tool_versions=versions, cartridge=cart, modules=modules,
        scope="Header-declared modules plus extracted ARM9 ITCM/DTCM. Not a complete native-code audit.",
        unknowns=["ARM7 code/data/function boundaries and autoloads have not been analyzed.",
                  "Asset files and script payloads have not been audited for embedded executable code.",
                  "ARM9 section ranges include padding and possible embedded data; report counters are symbol-based.",
                  "Declared complete ranges are configuration claims; use matched report counters for byte coverage.",
                  "Data report includes BSS; initialized bytes are not a code-coverage denominator.",
                  "No gameplay or final ROM SHA-1 verification is performed by this inventory."])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parent.parent)
    parser.add_argument("--output", type=Path, default=Path("build/usa/inventory.json"))
    args = parser.parse_args()
    result = inventory(args.root.resolve())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n', encoding="utf-8")
    print(f"Inventoried {len(result['modules'])} modules; ARM7 remains outside objdiff coverage. {args.output}")


if __name__ == "__main__":
    main()
