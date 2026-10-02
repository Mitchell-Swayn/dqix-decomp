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

## Continuation: action records and parent lists

Batch `fleet_ov000_20261003_b`, baseline
`62d9b93fe491b79f64bf820da264926c6888f0e3`. Existing work and prior attempt
records were inspected and preserved. No deferred/capped variants exist for
this family. The integrator-owned queue and other modules were not edited.

| Range (end exclusive) | Functions | Instruction bytes | Purpose |
| --- | ---: | ---: | --- |
| `02157d14–02157d3c` | 1 | 40 | Reset action payload and separate pool link |
| `0215fe64–0215fef0` | 3 | 140 | Reset action payload; append/index results by category |
| `02160030–02160130` | 5 | 256 | Reset parent record; append/index separate action and target lists |

Gain: **9 functions, 436 instruction/code bytes**; literal, initialized data,
BSS and assembly gains are each **0 bytes**. Code fallback decreases by 436
bytes, with no data fallback removed. Symbols retain their original names.
The new sources and layout header are local to `src/Factory/ov000/`.

Original disassembly establishes the layouts:

- `0215e918` returns action records at stride `0x34`; `02157d14` clears the
  `0x30` payload and separately resets the link at `0x30`. Initialization loops
  at `0215d114` and `0215d200` use the same stride and reset function.
- The loop at `0215bccc` clears six result-head pointers and six byte counts
  (except category 1), proving arrays at `0x00` and `0x26`. Cross-overlay callers
  in ov024 append categories 0–5; ov025's `021d8dd4` branch family queries
  those categories. The payload identifier is at `0x1c`, combatant ID at `0x20`.
- `0215e9d8` returns parent records at stride `0x28`. Their independent action
  and target lists have heads at `0x10`/`0x14` and counts at `0x08`/`0x09`.
  The setup at `02157a5c` appends previously reconstructed target records;
  `02157c48` appends action records. Traversal follows their distinct typed links.
- Parent reset clears a `0x0e`-byte values subobject at `0x18`, then separately
  writes its final halfword at `0x24`. Caller writes from combatant data confirm
  that halfword. Unknown bytes remain explicit rather than assigned semantics.

The first compiled layouts matched all nine functions. Broader caller review
then corrected the action result arrays from three to six categories; the
second compiled variant also matched all nine. **Two compiled variants per
function, six match_unit invocations, zero unproductive variants or compile
failures** in this batch. No prior cap was reset. Initial and final candidates
and hypotheses remain in `build/matching/attempts.jsonl` and its snapshots.

Final exact comparison directories:

- `build/matching/20261002T155608-fb7494b76a474e9199d460bc7992cee4/`: 1/1.
- `build/matching/20261002T155609-856839e7c4854b2c90305627f381a56b/`: 3/3.
- `build/matching/20261002T155609-f3e36df30dda4591a94aad5174360793/`: 5/5.

`factory_evidence` packages are
`build/factory/fleet_ov000/action_{reset,results,groups}_evidence_b_final.json`;
the corresponding `factory_diff` diagnoses each report zero mismatched symbols.
Original instructions, relevant clear loop and cross-overlay caller excerpts
are archived in `action_original_evidence_b.txt`. The map-based caller scan
returned no explicit call-relocation records; caller evidence above comes
directly from original dsd disassembly, not that empty scan or pseudocode.

Both full `.venv/Scripts/ninja.exe -j2 rom check report sha1` runs passed (exit 0),
including the final corrected header. All module/symbol and ARM7 preservation
checks passed, and ROM SHA-1 remains
`c7c3014c237900c8281289b8bc76a781969b6278`. Final log:
`build/factory/fleet_ov000/acceptance_b_final.log`. The report advances 1,659
to 1,668 matched functions and 219,192 to 219,628 code bytes. Matched data
stays 66,724 bytes. Denominators remain 14,790 functions, 2,959,478 code bytes,
1,602,476 data bytes. Every reconfiguration used the required explicit compiler
path; tooling and original comparison inputs were unchanged.

Remaining dependencies: pool allocators/initialization and combat resolution
callers remain original fallback. Payload meanings, result category meanings,
the identifier semantics and remaining parent values are unresolved. The only
external code called by these reconstructed units is the existing `memset`.
No external program-data inputs were introduced. ov000 remains incomplete;
no runtime test was run, and no integration or merge was performed.
Token usage is unmeasured. Batch snapshots and deltas are under
`build/workflow/fleet_ov000_20261003_b/`.
Measured start-to-finish elapsed time: **436.353105 seconds** (snapshot taken
after acceptance and evidence drafting, before the final Git commit).
