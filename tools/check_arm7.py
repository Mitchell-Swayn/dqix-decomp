#!/usr/bin/env python3
"""Check the unmodified cartridge ARM7 baseline without claiming source coverage.

This checks header-defined ARM7 boundaries and bytes independently of dsd's
ARM9-only module report. It is not a linker symbol check or a decompiler.
"""

import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys


def sha1_file(path):
    digest = hashlib.sha1()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def read_arm7(path):
    with path.open("rb") as stream:
        header = stream.read(0x60)
        if len(header) != 0x60:
            raise ValueError(f"{path}: truncated ROM header")
        offset, entry, address, size = struct.unpack_from("<4I", header, 0x30)
        overlay_offset, overlay_size = struct.unpack_from("<2I", header, 0x58)
        if not size or offset + size > path.stat().st_size:
            raise ValueError(f"{path}: invalid ARM7 payload extent")
        if not address <= (entry & ~1) < address + size:
            raise ValueError(f"{path}: ARM7 entry is outside payload")
        stream.seek(offset)
        payload = stream.read(size)
    return {
        "rom_offset": offset,
        "entry_address": entry,
        "load_address": address,
        "size": size,
        "overlay_table_size": overlay_size,
        "overlay_table_offset": overlay_offset,
        "payload_sha1": hashlib.sha1(payload).hexdigest(),
    }, payload


def verify(args):
    baseline = json.loads(args.baseline.read_text(encoding="utf-8"))
    source_sha1 = sha1_file(args.baserom)
    if source_sha1 != baseline["source_rom_sha1"]:
        raise ValueError("Base ROM SHA-1 does not match the recorded USA input")
    source, payload = read_arm7(args.baserom)
    rebuilt, rebuilt_payload = read_arm7(args.rom)
    for key in ("rom_offset", "entry_address", "load_address", "size",
                "overlay_table_size", "payload_sha1"):
        if source[key] != baseline[key]:
            raise ValueError(f"Source ARM7 {key} differs from baseline")
        if rebuilt[key] != source[key]:
            raise ValueError(f"Rebuilt ARM7 {key} differs from source")
    if source["overlay_table_size"] != 0:
        raise ValueError("ARM7 overlays need a separate inventory and byte check")
    if args.extracted.read_bytes() != payload:
        raise ValueError("Extracted ARM7 payload differs from source ROM")
    if rebuilt_payload != payload:
        raise ValueError("Rebuilt ARM7 payload differs from source ROM")
    if baseline["symbols"] != [{
        "name": "arm7_entry",
        "address": source["entry_address"],
        "evidence": "USA ROM header ARM7 entry address at offset 0x34",
        "status": "header-derived label; function extent and original name unknown",
    }]:
        raise ValueError("Entry symbol baseline has changed; review verifier")
    # Byte preservation cannot establish source ownership. The independent
    # source compiler/linker writes that evidence in arm7/report.json.
    report = {
        "schema_version": 1,
        "module": "cartridge_arm7",
        "processor": baseline["processor"],
        "verification": "original binary preservation; not source reconstruction",
        "source_rom_sha1": source_sha1,
        "module_checks_passed": True,
        "header_entry_symbol_check_passed": True,
        "linker_symbol_check": "not performed here; see ARM7 source build report",
        "payload": source,
        "source_coverage": "not measured by this preservation check; see arm7/report.json",
        "preserved_payload_bytes": source["size"],
        "code_data_partition": "unknown",
        "function_count": None,
        "symbols": baseline["symbols"],
    }
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(f"ARM7 baseline PASS: {source['size']:,} bytes preserved; "
          f"source coverage measured separately; report: {args.output}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baserom", type=Path, default=Path("extract/baserom_dqix_usa.nds"))
    parser.add_argument("--rom", type=Path, default=Path("dqix_usa.nds"))
    parser.add_argument("--extracted", type=Path, default=Path("extract/usa/arm7/arm7.bin"))
    parser.add_argument("--baseline", type=Path, default=Path("config/usa/arm7/baseline.json"))
    parser.add_argument("--output", type=Path, default=Path("build/usa/arm7-report.json"))
    args = parser.parse_args()
    try:
        verify(args)
    except (OSError, ValueError, KeyError) as error:
        # A failed check must not leave a stale PASS record at the requested path.
        if args.output.exists():
            args.output.unlink()
        print(f"ARM7 baseline FAIL: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
