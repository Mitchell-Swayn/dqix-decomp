#!/usr/bin/env python3
"""Audit USA cartridge executable containers without treating binary copies as source.

Uses only the Python standard library. Run after `ninja rom check report`.
The JSON contains metadata, ranges and hashes, never ROM payload bytes.
"""
import argparse
import hashlib
import json
from pathlib import Path
from rom_inputs import input_rom
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


def arm7_components(root, payload, load_address):
    """Partition the parent ARM7 payload; never add autoload sizes twice.

    Initialized payload extents are known, but their complete code/data split is
    not. The independent source report supplies bounded positive coverage only.
    """
    config_path = root / 'config/usa/arm7/source_units.json'
    if not config_path.exists():
        return dict(source_coverage='untracked; original binary passthrough',
                    code_data_split='unknown', subcomponents=None)
    config = json.loads(config_path.read_text())
    startup_size = config['startup_size']
    table_offset = config['autoload_table_offset']
    autoloads = config['autoloads']
    table_size = 12 * len(autoloads)
    if startup_size <= 0 or table_offset + table_size != len(payload):
        raise ValueError('ARM7 startup/table extent is invalid')
    table = bounded(payload, table_offset, table_size)
    parameters = struct.unpack('<6I', bounded(payload, config['autoload_parameters_offset'], 24))
    if parameters != (load_address + table_offset, load_address + len(payload),
                      load_address + startup_size, load_address + startup_size,
                      load_address + startup_size, 0):
        raise ValueError('ARM7 autoload parameters differ from configured layout')
    if config['autoload_parameters_offset'] + 24 > startup_size:
        raise ValueError('ARM7 autoload parameters outside startup')
    parts = [dict(name='startup', kind='startup_and_parameters', payload_offset=0,
                  initialized_size=startup_size, runtime_address=load_address, bss_size=0)]
    end = startup_size
    seen = set()
    for index, autoload in enumerate(autoloads):
        if autoload['name'] in seen:
            raise ValueError('Duplicate ARM7 autoload name')
        seen.add(autoload['name'])
        if autoload['payload_offset'] != end or autoload['size'] <= 0:
            raise ValueError('ARM7 autoloads overlap or leave unaccounted payload bytes')
        descriptor = struct.unpack_from('<3I', table, index * 12)
        if descriptor != (autoload['runtime_address'], autoload['size'], autoload['bss_size']):
            raise ValueError('ARM7 descriptor differs from configured autoload')
        parts.append(dict(name=autoload['name'], kind='autoload',
            payload_offset=autoload['payload_offset'], initialized_size=autoload['size'],
            runtime_address=autoload['runtime_address'], bss_size=autoload['bss_size']))
        end += autoload['size']
    if end != table_offset:
        raise ValueError('ARM7 autoloads do not end at descriptor table')
    parts.append(dict(name='autoload_table', kind='copy_descriptors', payload_offset=table_offset,
                      initialized_size=table_size, runtime_address=load_address+table_offset, bss_size=0))
    for part in parts:
        part['parent_module'] = 'arm7'
        part['accounting'] = 'partition of parent initialized bytes; do not add to module total'
        part['sha256'] = digest(bounded(payload, part['payload_offset'], part['initialized_size']))
        part['source_units'] = []
    owners = {p['name']: p for p in parts if p['kind'] == 'autoload'}
    ranges, bss_ranges = [], []
    for unit in config['units']:
        owner = owners.get(unit['autoload'])
        if owner is None:
            raise ValueError('ARM7 source unit has unknown autoload')
        first, last = unit['payload_offset'], unit['payload_offset'] + unit['size']
        if not owner['payload_offset'] <= first < last <= owner['payload_offset'] + owner['initialized_size']:
            raise ValueError('ARM7 source unit outside autoload')
        if unit['runtime_address'] != owner['runtime_address'] + first - owner['payload_offset']:
            raise ValueError('ARM7 source unit runtime mapping differs')
        if any(first < b and a < last for a, b in ranges):
            raise ValueError('ARM7 source unit overlap')
        ranges.append((first, last))
        owned_bytes = (unit['code_bytes'] + unit['literal_pool_bytes'] +
                       unit.get('data_bytes', 0) + unit.get('reviewed_assembly_bytes', 0))
        if owned_bytes != unit['size'] or min(unit['code_bytes'], unit['literal_pool_bytes'],
                                             unit.get('data_bytes', 0), unit.get('reviewed_assembly_bytes', 0)) < 0:
            raise ValueError('ARM7 source unit ownership does not cover its payload range')
        if 'bss' in unit:
            bss = unit['bss']
            first_bss, last_bss = bss['runtime_address'], bss['runtime_address'] + bss['size']
            owner_bss = owner['runtime_address'] + owner['initialized_size']
            if not owner_bss <= first_bss < last_bss <= owner_bss + owner['bss_size']:
                raise ValueError('ARM7 source BSS outside autoload BSS range')
            if any(first_bss < b and a < last_bss for a, b in bss_ranges):
                raise ValueError('ARM7 source BSS overlap')
            bss_ranges.append((first_bss, last_bss))
        owner['source_units'].append(unit)
    result = dict(subcomponents=parts,
        source_coverage='independent source pipeline; see source_build_report',
        code_data_split='only reconstructed units classified; full denominator unknown',
        source_build_report=None)
    report_path = root / 'build/usa/arm7/report.json'
    if not report_path.exists():
        result['source_coverage'] = 'source configuration present; build report missing, no measured source credit'
        return result
    report_bytes = report_path.read_bytes()
    report = json.loads(report_bytes)
    if report['payload_bytes'] != len(payload) or report['payload_sha1'] != hashlib.sha1(payload).hexdigest():
        raise ValueError('ARM7 source report payload differs')
    if not report['module_check_passed'] or not report['source_symbol_checks_passed']:
        raise ValueError('ARM7 source report checks did not pass')
    if report['autoloads'] != autoloads or len(report['units']) != len(config['units']):
        raise ValueError('ARM7 source report/config differ; rebuild')
    for declared, measured in zip(config['units'], report['units']):
        if any(measured.get(k) != v for k, v in declared.items()):
            raise ValueError('ARM7 source report unit metadata differs; rebuild')
        source = (root / declared['source']).read_bytes()
        original = bounded(payload, declared['payload_offset'], declared['size'])
        if measured['source_sha1'] != hashlib.sha1(source).hexdigest():
            raise ValueError('ARM7 source changed since report; rebuild')
        if declared.get('reviewed_assembly_bytes', 0):
            exception_path = declared.get('assembly_exception')
            if not exception_path:
                raise ValueError('ARM7 assembly unit lacks reviewed exception record')
            exception = (root / exception_path).read_bytes()
            if measured.get('assembly_exception_sha1') != hashlib.sha1(exception).hexdigest():
                raise ValueError('ARM7 assembly exception changed since report; rebuild')
        if measured['linked_sha1'] != hashlib.sha1(original).hexdigest():
            raise ValueError('ARM7 linked source bytes differ from original')
        if not measured['module_check_passed'] or not measured['symbol_check_passed']:
            raise ValueError('ARM7 source unit did not pass checks')
    expected = {
        'source_code_bytes': sum(u['code_bytes'] for u in config['units']),
        'source_literal_pool_bytes': sum(u['literal_pool_bytes'] for u in config['units']),
        'source_data_bytes': sum(u.get('data_bytes', 0) for u in config['units']),
        'source_functions': sum(len(u['symbols']) for u in config['units'] if u['code_bytes'] > 0),
        'reviewed_assembly_functions': sum(len(u['symbols']) for u in config['units'] if u.get('reviewed_assembly_bytes', 0)),
        'binary_fallback_bytes': len(payload) - sum(u['size'] for u in config['units']),
        'reviewed_assembly_bytes': sum(u.get('reviewed_assembly_bytes', 0) for u in config['units']),
    }
    if any(report.get(k, 0) != v for k, v in expected.items()):
        raise ValueError('ARM7 source report counters do not reconcile')
    if sum(report[k] for k in ('source_code_bytes', 'source_literal_pool_bytes', 'source_data_bytes',
                              'reviewed_assembly_bytes', 'binary_fallback_bytes')) != len(payload):
        raise ValueError('ARM7 payload ownership counters do not cover parent bytes')
    source_bss = sum(u.get('bss', {}).get('size', 0) for u in config['units'])
    total_bss = sum(a['bss_size'] for a in autoloads)
    if report.get('source_bss_bytes', 0) != source_bss:
        raise ValueError('ARM7 source BSS counter differs from ownership ranges')
    if 'total_bss_bytes' in report and (report['total_bss_bytes'] != total_bss or
            report['unreconstructed_bss_bytes'] != total_bss - source_bss):
        raise ValueError('ARM7 BSS counters do not reconcile')
    result['source_build_report'] = dict(path='build/usa/arm7/report.json', sha256=digest(report_bytes),
        measures={k: report[k] for k in ('source_code_bytes', 'source_literal_pool_bytes',
            'source_data_bytes', 'source_functions', 'binary_fallback_bytes', 'reviewed_assembly_bytes',
            'function_count', 'code_data_partition')},
        compiler_sha1=report['compiler_sha1'], linker_sha1=report['linker_sha1'],
        bss_measures=dict(source_bss_bytes=source_bss, total_bss_bytes=total_bss,
                          unreconstructed_bss_bytes=total_bss-source_bss),
        reviewed_assembly_functions=report.get('reviewed_assembly_functions', 0))
    for part in parts:
        part['measured_reconstructed_bytes'] = sum(u['size'] for u in part['source_units'])
        part['reviewed_assembly_bytes'] = sum(u.get('reviewed_assembly_bytes', 0) for u in part['source_units'])
        part['source_data_bytes'] = sum(u.get('data_bytes', 0) for u in part['source_units'])
        part['source_code_bytes'] = sum(u['code_bytes'] for u in part['source_units'])
        part['measured_c_cpp_bytes'] = part['measured_reconstructed_bytes'] - part['reviewed_assembly_bytes']
        part['source_bss_bytes'] = sum(u.get('bss', {}).get('size', 0) for u in part['source_units'])
        part['binary_fallback_bytes'] = part['initialized_size'] - part['measured_reconstructed_bytes']
    return result


def inventory(root):
    rom_path = input_rom(root)
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
    arm7_module = dict(name="arm7", processor="arm7", initialized_size=len(arm7),
        extracted_sha256=digest(arm7), extraction_metadata=flat_numbers(extract / "arm7/arm7.yaml"),
        report_coverage=None, verification="exact extracted bytes compared to ROM header range")
    arm7_module.update(arm7_components(root, arm7, arm7_header['load_address']))
    modules.append(arm7_module)
    for ov in cart["overlays"]["arm7"]:
        modules.append(dict(name=f"arm7_ov{ov['id']:03}", processor="arm7", overlay=ov,
                            report_coverage=None, source_coverage="untracked"))
    revision = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root, text=True).strip()
    config_bytes = (root / "tools/configure.py").read_text()
    versions = dict(re.findall(r"^(DSD_VERSION|OBJDIFF_VERSION|MWCC_VERSION|WIBO_VERSION)\s*=\s*[\"']([^\"']+)", config_bytes, re.M))
    return dict(schema_version=1, source_revision=revision, rom_sha1=sha1,
        report_sha256=digest(report_bytes), report_measures=report["measures"],
        configured_tool_versions=versions, cartridge=cart, modules=modules,
        scope="Header-declared modules, extracted ARM9 ITCM/DTCM, and configured ARM7 autoload partitions. Not a complete native-code audit.",
        unknowns=["ARM7 complete code/data/function boundaries remain unknown; autoload/source subcomponents are reported when configured.",
                  "Asset files and script payloads have not been fully audited for embedded executable code; see the separate asset triage report.",
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
