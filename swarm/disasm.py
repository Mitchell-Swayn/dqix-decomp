"""Capstone-backed ARM/Thumb listings with literal-pool detection (hex fallback)."""
import os
from pathlib import Path
import re
import struct
import sys

_CANDIDATES = [os.environ.get('SWARM_PYDEPS'), Path(__file__).resolve().parents[1] / 'build/swarm/pydeps',
               Path(__file__).resolve().parents[2] / 'build/fmul-verification/pydeps']
try:
    import capstone
except ImportError:
    capstone = None
    for path in _CANDIDATES:
        if path and (Path(path) / 'capstone').is_dir():
            sys.path.insert(0, str(path))
            try:
                import capstone
                break
            except ImportError:
                capstone = None

_engines = {}
PC_LOAD = re.compile(r'\[pc(?:, #(-?0x[0-9a-f]+|-?\d+))?\]')


def _engine(mode):
    if mode not in _engines:
        m = capstone.CS_MODE_THUMB if mode == 'thumb' else capstone.CS_MODE_ARM
        _engines[mode] = capstone.Cs(capstone.CS_ARCH_ARM, m)
    return _engines[mode]


def listing(code, address, mode):
    """Return [(offset, size, text)] covering every byte of code."""
    rows, pools, offset = [], set(), 0
    width = 2 if mode == 'thumb' else 4
    while offset < len(code):
        if offset in pools and offset + 4 <= len(code):
            rows.append((offset, 4, '.word    0x%08x' % struct.unpack_from('<I', code, offset)))
            offset += 4
            continue
        if not any(code[offset:]) and len(code) - offset < 4:  # Alignment padding after the last instruction.
            rows.append((offset, len(code) - offset, '.pad'))
            break
        insn = None
        if capstone:
            insn = next(_engine(mode).disasm(code[offset:offset + 4], address + offset, 1), None)
        if insn is None:
            size = min(width, len(code) - offset)
            rows.append((offset, size, '.byte    ' + code[offset:offset + size].hex()))
            offset += size
            continue
        text = f'{insn.mnemonic:<8} {insn.op_str}'
        match = PC_LOAD.search(insn.op_str) if insn.mnemonic.startswith('ldr') else None
        if match:
            pc = (address + offset + (4 if mode == 'thumb' else 8)) & ~3
            target = pc + int(match[1] or '0', 0) - address
            if 0 <= target < len(code):
                pools.add(target)
                text += f'   ; ={target + address:#010x}'
        rows.append((offset, insn.size, text))
        offset += insn.size
    return rows


def available():
    return capstone is not None
