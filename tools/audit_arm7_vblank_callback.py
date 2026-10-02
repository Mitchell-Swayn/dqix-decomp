"""Audit the startup-installed ARM7 VBlank callback and its bounded partition."""

import argparse
import json
from pathlib import Path
import struct
import sys

from disassemble_arm7 import address_to_payload, load_original

ROOT = Path(__file__).resolve().parent.parent
CALLBACK = 0x037F84F0


def inspect_callback(data, address=CALLBACK):
    """Check both paths of the short callback, excluding its inline literal."""
    from capstone import Cs, CS_ARCH_ARM, CS_MODE_ARM, CS_MODE_LITTLE_ENDIAN

    if address % 4 or len(data) != 36:
        raise ValueError("callback requires 36 bytes at an ARM-aligned address")
    decoder = Cs(CS_ARCH_ARM, CS_MODE_ARM | CS_MODE_LITTLE_ENDIAN)
    decoder.detail = True
    instructions = list(decoder.disasm(data[:32], address))
    expected = ["push", "ldr", "ldr", "cmp", "beq", "bl", "pop", "bx"]
    if len(instructions) != 8 or [i.mnemonic for i in instructions] != expected:
        raise ValueError("callback control-flow shape differs from the evidenced routine")
    push, literal_load, indirect_load, compare, branch, call, pop, ret = instructions
    if (push.op_str != "{r3, lr}" or pop.op_str != "{r3, lr}"
            or indirect_load.op_str != "r0, [r0]" or compare.op_str != "r0, #0"
            or literal_load.op_str != "r0, [pc, #0x14]" or ret.op_str != "lr"):
        raise ValueError("callback register/return path differs from the evidenced routine")
    literal_address = literal_load.address + 8 + literal_load.operands[1].mem.disp
    if literal_address != address + 32 or branch.operands[0].imm != pop.address:
        raise ValueError("callback branch or literal boundary differs")
    call_target = call.operands[0].imm
    if address <= call_target < address + len(data) or call_target % 4:
        raise ValueError("callback call must target an external ARM routine")
    # beq reaches pop directly; the other path calls an external routine and
    # falls through to pop. Both then reach bx lr, so no path enters the pool.
    return {"address": address, "instruction_bytes": 32, "literal_pool_bytes": 4,
            "literal_address": literal_address,
            "literal_value": struct.unpack_from("<I", data, 32)[0],
            "external_call": call_target,
            "reachable_instructions": [i.address for i in instructions]}


def audit_callback(payload, baseline, config):
    def read(address, size=4):
        mapped = address_to_payload(address, address + size, baseline, config)
        return payload[mapped.payload_start:mapped.payload_end]

    def word(address):
        return struct.unpack("<I", read(address))[0]

    # These exact instructions carry the pointer from the confirmed startup
    # scope into the original handler-registration routine with IRQ mask 1.
    expected_words = {
        0x037F83E8: 0xE59F10A8,  # ldr r1, [pc, #0xa8] -> 0x037f8498
        0x037F83EC: 0xE3A00001,  # mov r0, #1
        0x037F83F0: 0xEB000CFE,  # bl 0x037fb7f0
        0x037F8498: CALLBACK,
        # Mask 1 selects index zero. The first loop iteration follows blt to
        # b854, then moveq selects the VBlank response and stmne stores r1.
        0x037FB7F8: 0xE3A09000, 0x037FB800: 0xE59F507C,
        0x037FB808: 0xE1A08009, 0x037FB818: 0xE3100001,
        0x037FB81C: 0x0A000011, 0x037FB820: 0xE1A0A008,
        0x037FB824: 0xE3590008, 0x037FB828: 0xBA000003,
        0x037FB83C: 0xE3590003, 0x037FB840: 0xBA000003,
        0x037FB854: 0xE3590000, 0x037FB858: 0x17841109,
        0x037FB85C: 0x01A0A005, 0x037FB860: 0xE35A0000,
        0x037FB864: 0x188A5002,
        0x037FB868: 0xE2899001, 0x037FB86C: 0xE3590019,
        0x037FB870: 0xE1A000A0, 0x037FB874: 0xBAFFFFE7,
        # The matched VBlank dispatcher loads that same callback, checks null
        # and calls it through bx r3 (ARM mode for this even pointer).
        0x037FB784: 0xE59F0038, 0x037FB78C: 0xE5903060,
        0x037FB798: 0xE3530000, 0x037FB79C: 0x0A000001,
        0x037FB7A0: 0xE1A0E00F, 0x037FB7A4: 0xE12FFF13,
    }
    for address, expected in expected_words.items():
        if word(address) != expected:
            raise ValueError(f"reference instruction/word differs at {address:#010x}")
    response = word(0x037FB884)
    dispatcher_response = word(0x037FB7C4) + 0x60
    if response != dispatcher_response or response != 0x03808E9C:
        raise ValueError("registration and dispatch callback storage differ")
    result = inspect_callback(read(CALLBACK, 36))
    mapped = address_to_payload(CALLBACK, CALLBACK + 36, baseline, config)
    return {**result, "payload_offset": mapped.payload_start,
            "callback_storage": response, "startup_pointer_literal": 0x037F8498,
            "registration_call": 0x037F83F0, "dispatch_call": 0x037FB7A4}


def load_verified(rom=ROOT / "extract/baserom_dqix_usa.nds"):
    payload, baseline, config = load_original(
        rom, ROOT / "config/usa/arm7/baseline.json",
        ROOT / "config/usa/arm7/source_units.json")
    return audit_callback(payload, baseline, config)


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--rom", type=Path, default=ROOT / "extract/baserom_dqix_usa.nds")
    args = parser.parse_args(argv)
    try:
        result = load_verified(args.rom)
    except (OSError, ValueError, KeyError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 2
    print(json.dumps({"evidence_only": True, "source_coverage_credit": 0,
                      "callback": result}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
