"""Trace ARM7 startup call veneers to their Thumb BIOS-call stubs."""

import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys

from arm7_build import validate_layout
from check_arm7 import read_arm7, sha1_file
from disassemble_arm7 import address_to_payload

ROOT = Path(__file__).resolve().parent.parent
STARTUP_LOOP = (0x037F8000, 0x037F8478)
VENEERS = (0x037F84A0, 0x037F84AC)
TARGETS = (0x03803EF0, 0x03803EBE)


def inspect_thumb_swi_stub(code, address):
    """Recognize an exact `svc #imm; bx lr` two-instruction Thumb stub."""
    if address & 1:
        raise ValueError("Thumb stub address must be halfword-aligned")
    if len(code) != 4:
        raise ValueError("Thumb SWI stub must be exactly four bytes")
    try:
        from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB, CS_MODE_LITTLE_ENDIAN
    except ImportError as error:
        raise ValueError("Capstone is required to audit ARM7 instruction bytes") from error
    decoder = Cs(CS_ARCH_ARM, CS_MODE_THUMB | CS_MODE_LITTLE_ENDIAN)
    decoder.detail = True
    instructions = list(decoder.disasm(code, address))
    if len(instructions) != 2 or any(instruction.size != 2 for instruction in instructions):
        raise ValueError("expected exactly two Thumb instructions")
    swi, ret = instructions
    if swi.mnemonic != "svc" or not swi.operands:
        raise ValueError("first Thumb instruction is not an SVC")
    if ret.mnemonic != "bx" or ret.op_str != "lr":
        raise ValueError("second Thumb instruction is not bx lr")
    return {"address": address, "size": 4, "swi": swi.operands[0].imm,
            "return_address": ret.address}


def _word(payload, baseline, config, address):
    mapped = address_to_payload(address, address + 4, baseline, config)
    return struct.unpack_from("<I", payload, mapped.payload_start)[0]


def _veneer_target(payload, baseline, config, veneer):
    """Validate the two-instruction ARM veneer and resolve its inline word."""
    try:
        from capstone import (Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN,
                              CS_OP_MEM)
    except ImportError as error:
        raise ValueError("Capstone is required to audit ARM7 instruction bytes") from error
    mapped = address_to_payload(veneer, veneer + 8, baseline, config)
    data = payload[mapped.payload_start:mapped.payload_end]
    decoder = Cs(CS_ARCH_ARM, CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN)
    decoder.detail = True
    instructions = list(decoder.disasm(data, veneer))
    if len(instructions) != 2 or [item.mnemonic for item in instructions] != ["ldr", "bx"]:
        raise ValueError(f"{veneer:#010x}: not the expected ldr/bx veneer")
    load, jump = instructions
    if jump.op_str != "ip" or len(load.operands) < 2:
        raise ValueError(f"{veneer:#010x}: veneer does not branch through ip")
    if load.reg_name(load.operands[0].reg) != "ip":
        raise ValueError(f"{veneer:#010x}: veneer does not load ip")
    memory = load.operands[1]
    if memory.type != CS_OP_MEM or load.reg_name(memory.mem.base) != "pc":
        raise ValueError(f"{veneer:#010x}: literal load is not PC-relative")
    literal_address = load.address + 8 + memory.mem.disp
    if literal_address != veneer + 8:
        raise ValueError(f"{veneer:#010x}: inline literal is not immediately after veneer")
    literal = _word(payload, baseline, config, literal_address)
    return {"address": veneer, "literal_address": literal_address,
            "literal_value": literal, "target_address": literal & ~1,
            "target_mode": "thumb" if literal & 1 else "arm"}


def audit_targets(payload, baseline, config):
    """Return verified veneer, caller and Thumb-stub evidence for the two targets."""
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN, CS_OP_IMM

    start, end = STARTUP_LOOP
    mapped = address_to_payload(start, end, baseline, config)
    decoder = Cs(CS_ARCH_ARM, CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN)
    decoder.detail = True
    callers = {veneer: [] for veneer in VENEERS}
    for instruction in decoder.disasm(
            payload[mapped.payload_start:mapped.payload_end], start):
        if instruction.mnemonic == "bl" and instruction.operands[0].type == CS_OP_IMM:
            target = instruction.operands[0].imm
            if target in callers:
                callers[target].append(instruction.address)

    results = []
    for veneer, expected_target in zip(VENEERS, TARGETS):
        if not callers[veneer]:
            raise ValueError(f"{veneer:#010x}: no direct caller found in the startup loop")
        link = _veneer_target(payload, baseline, config, veneer)
        if link["target_mode"] != "thumb" or link["target_address"] != expected_target:
            raise ValueError(f"{veneer:#010x}: unexpected veneer target {link['literal_value']:#010x}")
        mapped = address_to_payload(expected_target, expected_target + 4, baseline, config)
        stub = inspect_thumb_swi_stub(
            payload[mapped.payload_start:mapped.payload_end], expected_target)
        results.append({**link, "call_sites": callers[veneer], "stub": stub,
                        "payload_offset": mapped.payload_start})
    return results


def load_verified(rom_path, baseline_path, units_path):
    baseline = json.loads(baseline_path.read_text(encoding="utf-8"))
    config = json.loads(units_path.read_text(encoding="utf-8"))
    if sha1_file(rom_path) != baseline["source_rom_sha1"]:
        raise ValueError("ROM SHA-1 does not match the recorded original USA input")
    _, payload = read_arm7(rom_path)
    if len(payload) != baseline["size"]:
        raise ValueError("ARM7 payload size differs from baseline")
    if hashlib.sha1(payload).hexdigest() != baseline["payload_sha1"]:
        raise ValueError("ARM7 payload SHA-1 differs from baseline")
    validate_layout(payload, baseline, config)
    return audit_targets(payload, baseline, config)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rom", type=Path, default=ROOT / "extract/baserom_dqix_usa.nds")
    parser.add_argument("--baseline", type=Path, default=ROOT / "config/usa/arm7/baseline.json")
    parser.add_argument("--units", type=Path, default=ROOT / "config/usa/arm7/source_units.json")
    args = parser.parse_args(argv)
    try:
        results = load_verified(args.rom, args.baseline, args.units)
    except (OSError, ValueError, KeyError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 2
    printable = []
    for result in results:
        printable.append({
            "veneer": f"{result['address']:#010x}",
            "literal": f"{result['literal_address']:#010x} -> {result['literal_value']:#010x}",
            "target": f"{result['target_address']:#010x} ({result['target_mode']})",
            "swi": result["stub"]["swi"],
            "call_sites": [f"{address:#010x}" for address in result["call_sites"]],
            "size": result["stub"]["size"],
        })
    print(json.dumps({"evidence_only": True, "source_coverage_credit": 0,
                      "targets": printable}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

