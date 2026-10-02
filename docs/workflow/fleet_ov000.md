# ov000 combat target records

Batch: `fleet_ov000_20261003_a`; baseline `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
Exclusive worker worktree; queue and other modules unchanged. No earlier ov000
candidate or variant-cap evidence was present in this worktree.

## Reconstructed family

| Range (end exclusive) | Functions | Instruction bytes | Purpose |
| --- | ---: | ---: | --- |
| `02157cdc–02157d14` | 1 | 56 | Reset target payload and pool link |
| `0215fef0–02160030` | 7 | 320 | Reset payload, append target pairs, indexed/latest target lookup, result-list append/indexed lookup |

All eight functions retain their original symbol names. Sources and the local
layout header are under `src/Factory/ov000/`. No shared-header change is needed.
Gain: 8 functions, 376 instruction/code bytes, 0 literal bytes, 0 initialized
data bytes, 0 BSS bytes, 0 assembly bytes. Original code fallback decreases by
376 bytes; no data fallback is removed. These ranges do not complete ov000.

## Layout and caller evidence

Original dsd disassembly, not generated pseudocode, supplied the implementation:

- `0215e938` indexes target records at stride `0x24`; `02157cdc` resets their
  `0x20` payload and separately clears the link at `0x20`.
- Target payload: three result-head pointers at `0x00`, signed identifier at
  `0x0c`, three signed target IDs at `0x0e`, three byte values at `0x14`, byte
  target count at `0x17`, three byte result counts at `0x18`. The remaining five
  bytes are explicitly unknown. The two append entry points enforce capacity 3.
- `0215e958` allocates result nodes at stride `0x24`, clears their `0x20` payload,
  and separately initializes the link at `0x20`. The source models an actual
  node and typed link rather than an offset access or pointer-array substitute.
- `0215c758` writes target ID/count and calls `0215ffc4` with
  a result from `0215e958`; other append callers occur throughout the combat
  resolution routines. `02157cdc` is also used by pool initialization.
- Empty latest-target lookup reads slot zero, whose reset value is `-1`.
  Indexed target lookup bounds against capacity, not current count; result
  lookup checks its recorded count and follows links while non-null. These
  original behaviors are retained.

Unresolved: meanings of the two identical target-append entry points, target
byte values, remaining target payload fields, result payload fields and list
categories. No semantic names beyond observed record operations are asserted.
Only external code dependency is the existing project `memset` declaration.
No globals, tables, or original binary fragments are declared as data inputs.

## Iteration and verification

One compiled reconstruction variant per function; all eight matched 100% on
that variant. One initial compile invocation per unit failed because this
toolchain has no system `string.h`; the candidates were corrected to include
the existing `std_library_functions.h`. Four `match_unit` invocations total
(two failed compilation, two exact comparisons); no function approaches its
ten-unproductive-variant cap. Candidate snapshots and failed hypotheses remain
under ignored `build/matching/` and factory attempt records.

The initial delink declaration attempted two `.text` intervals in one object;
dsd rejected duplicate sections. The pool reset was placed in its own source
unit with the common local layout header. All reconfigurations used the explicitly
supplied read-only compiler path. No compiler tooling or comparison input was
edited.

Object evidence:

- `build/matching/20261002T154729-574bc4fd3940401c8323d0b9e92b4eae/`: 7/7 exact.
- `build/matching/20261002T154730-45976ed20b6e48a6933dd28462e05181/`: 1/1 exact.
- `build/factory/fleet_ov000/target_records_evidence.json` and
  `reset_evidence.json`: objects, maps, relocations, callers and prior attempts.
- `build/factory/fleet_ov000/target_records_diagnosis.json`: factory_diff reports
  no observed instruction differences.

Full acceptance command: `.venv/Scripts/ninja.exe -j2 rom check report sha1`;
passed all module and symbol checks, ARM7 preservation checks and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278` (exit 0). The report advances
1,651 to 1,659 functions and 218,816 to 219,192 code bytes; matched data stays
66,724 bytes. Denominators stay 14,790 functions, 2,959,478 code bytes and
1,602,476 data bytes. Verbose output is
`build/factory/fleet_ov000/acceptance.log`. No gameplay smoke
test was run for this byte-identical reconstruction. Batch start/finish
snapshots, deltas and elapsed wall time are recorded by `tools/work_batch.py`
under `build/workflow/fleet_ov000_20261003_a/`. Token usage is unmeasured.
