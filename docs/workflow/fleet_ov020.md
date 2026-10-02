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

## Continuation: title menu selection and BG setup

Batch `fleet_ov020_20261003t_cont2`, baseline
`73ea59e3af31453e841fb2b7f78e91d31d432a3e`. The runtime clock recorded
2026-10-02 15:49:48.307430 UTC through 15:56:13.493060 UTC:
**385.185630 seconds**. These timestamps come from `work_batch.py`, independently
of the dispatch date in the batch name. Worker acceptance only; no integration.

| Function | Behavior | Instruction bytes | Literal bytes |
| --- | --- | ---: | ---: |
| `func_ov020_0218c7bc` | Configure title main BG1 control | 48 | 4 |
| `func_ov020_0218c7f0` | Configure both menu grids and entry counts | 80 | 0 |
| `func_ov020_0218c840` | Update menu, accept button/touch selection, set scene byte | 316 | 16 |
| `func_ov020_0218cd64` | Configure corresponding sub BG0 control | 48 | 4 |

Accepted text ranges: `[0x0218c7bc, 0x0218c98c)` and
`[0x0218cd64, 0x0218cd98)`. Accepted rodata:
`[0x0218d974, 0x0218db90)`: two full integer scene tables (28/32 bytes)
and two full label arrays with 32-byte rows (224/256 bytes).
`Delete` is a real row between `Create` and `Title`; the eight-row version adds
`On the way` after `Start`. No binary substitutes or interior aliases are used.

Report delta: **+4 functions, +516 matched text bytes** (492 instructions,
24 literals), **+540 rodata bytes**. Writable initialized data, BSS, alignment,
assembly and ARM7 gains: zero. All coverage denominators remain unchanged.

Original `dsd dis` evidence and mapped callers establish the two selection grids
at menu offsets 0x20/0x70, the input subobject at 0x4, and the menu's 0x238-byte
extent. ARM9 `func_0205ba68` assigns grid dimensions and orientation-dependent
field pointers; `func_0205bacc` assigns its entry count. `func_0205c790` initializes
the menu and its flags; `func_0205c77c` resets two input counters and sets its
enable byte. `func_ov020_0218b710` passes controller+0xc as the menu, configures
1x7 or 1x8 grids, and indexes the labels with a 32-byte stride. The selector tables
have matching entry counts. The selection handler combines the observed button
edge helper with the nonnegative touch-selection result using bitwise OR, retains
the special scene-6 early return, and writes the chosen GameState byte before
setting controller state/frame fields to -1.

The local `TitleController.h` now shares these actual subobjects with the prior
brightness reconstruction. Unknown UI/resource regions stay explicit; this is
a partial layout. Main UI singleton/object routines, mode query, button-state
storage (`data_02114e30`), the earlier controller UI/resources, and all other
ov020 code/data remain dependencies or required reconstruction. The main
GameState byte accessors already have matching source. Semantic UI names are
reconstruction hypotheses, not recovered developer names. No shared include
headers or other modules were edited.

Attempts: one compiled code variant per new function, all exact. The label
extension had two compiled data variants: first omitted the observed `Delete`
row (85.71%/87.50%), second corrected the transcription and matched. Thus five
new candidate-object comparisons plus one existing-brightness regression
comparison, recorded as six attempts. No function has an exhausted variant cap.
An initial map configuration rejected duplicate `.text` entries before compiling;
the main/sub BG helpers consequently use separate source units. Failed candidates
and hypotheses remain in the matching ledger. Prior evidence was preserved.

Validation: all final candidate symbols exact; `factory_evidence.py` packaged
the three new units; `factory_diff.py` reports zero final mismatched symbols.
Existing brightness unit remained 5/5 exact after the layout change.
`ninja -j2 rom check report sha1` passed, including module/symbol checks and ARM7
preservation. Original input and generated ROM SHA-1 both equal
`c7c3014c237900c8281289b8bc76a781969b6278`. `git diff --check` passed.
Gameplay was not tested; token usage was not measured.

Verbose evidence: `build/factory/fleet_ov020/*cont2*`,
`build/workflow/fleet_ov020_20261003t_cont2/`, and matching attempts
`20261002T155326-*`, `20261002T155400-dac8bab136db4c9c9cbdfac823470709`,
`20261002T155427-90e4279567f64fe1ae8487d657f642a4`.
No main/queue edits or merge; ov020 remains incomplete.
