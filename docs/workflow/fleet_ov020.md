# ov020 title transition reconstruction

Batch `fleet_ov020_20261002t1550`, baseline `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
Measured interval: 2026-10-02 15:43:38.173876 UTC through 15:47:58.076773 UTC
(259.902897 seconds). This is worker acceptance, not integrated main coverage.

## Accepted family

`src/Factory/ov020/TitleTransitions.cpp` reconstructs the contiguous half-open
range `[0x0218d644, 0x0218d8d8)` using C++ and the existing GameState/SafeAllocator
interfaces. Symbol names retain their address identities.

| Function | Behavior | Instruction bytes | Literal bytes |
| --- | --- | ---: | ---: |
| `func_ov020_0218d644` | Advance/apply both brightness transitions | 352 | 8 |
| `func_ov020_0218d7ac` | Start/apply main brightness transition | 80 | 4 |
| `func_ov020_0218d800` | Start/apply sub brightness transition | 80 | 4 |
| `func_ov020_0218d854` | Advance/clamp the wait countdown | 68 | 0 |
| `func_ov020_0218d898` | Query whether either transition remains active | 64 | 0 |

Report delta: **+5 functions, +660 matched text bytes**, comprising 644 instruction
bytes and 16 literal bytes. Initialized data, rodata, BSS, alignment and assembly
gains are zero. All denominators remain unchanged; ARM7 deltas are zero.

## Evidence and types

Original disassembly was generated with `dsd dis` from the original module maps.
`func_ov020_0218b710` calls these functions repeatedly while displaying logos and
title resources, supplies brightness targets 0/-16 and durations such as 500,
and initializes the wait countdown to 2000. No generated pseudocode was used.

The controller has existing SafeAllocator subobjects at offsets 0x470/0x484,
a signed wait countdown at 0x4e4, and main/sub brightness subobjects at
0x4e8/0x4f4. Each brightness subobject contains a float current value, signed
integer target and signed remaining milliseconds. Earlier UI state and the
0x498..0x4e4 gap remain explicitly unrecovered; this is a partial controller
layout, not a claim to reconstruct its other fields.

GameState supplies the effective delta time. Original ARM9 helpers
`func_020c39a0`/`func_020c39c8` encode/decode signed brightness through the hardware
master brightness registers at 0x0400006c/0x0400106c. These helpers remain external
dependencies and original fallback. The selected family owns no global arrays
or program data and has no unresolved binary data dependency.

Integer-returning inline predicates preserve the original comparison/boolean
materialization, matching the established pattern in `src/Resource/Brightness.cpp`.
No shared header changes or other-module edits were needed.

## Attempts and verification

One compiled candidate variant per function (one five-function object comparison):
all five symbols matched 100%. No prior ov020 source or variant-cap evidence was
present in this worktree's factory/workflow notes. An initial CLI invocation used
an incorrect unit name and failed before compiling; it is not a source variant.

- `tools/match_unit.py src/Factory/ov020/TitleTransitions --worker fleet_ov020 --hypothesis ...`: 5/5 exact.
- `tools/factory_evidence.py`: original module and candidate evidence packaged.
- `tools/factory_diff.py`: zero mismatched symbols in every diagnosis category.
- `.venv/Scripts/ninja.exe -j2 rom check report sha1`: exit 0; ARM9, all overlays,
  symbols, ARM7 preservation and final SHA-1 passed.
- Original input SHA-1 independently checked:
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- Generated ROM SHA-1: `c7c3014c237900c8281289b8bc76a781969b6278`.
- `git diff --check`: passed. Gameplay was not tested in this batch.

Verbose local artifacts: `build/factory/fleet_ov020/`, comparison
`build/matching/20261002T154549-e51c76665d464926aaad99e000c029ad/`, and
`build/workflow/fleet_ov020_20261002t1550/{start,finish}.json`.
Token usage was not measured.

All other ov020 functions and data remain required work under original fallback.
Further reconstruction needs the title controller's earlier UI/resource fields,
its large initialization/display function, allocator cleanup, and its tables and
strings. No queue changes, integration or merge into main were performed.
