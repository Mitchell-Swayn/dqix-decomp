# ov021 worker batch

Batch: `fleet_ov021_20261003_0145`, started 2026-10-02 15:43:23 UTC.
Baseline revision: `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
No previous ov021 source, workflow notes, or matching attempts were present.

## Accepted family

| Source | Original range (end exclusive) | Functions | Instruction bytes | Literal bytes |
| --- | --- | ---: | ---: | ---: |
| SceneLifecycle.cpp | 0218b5a0–0218b5fc | 2 | 88 | 4 |
| SceneFrame.cpp | 0218baf8–0218bbc4 | 2 | 196 | 8 |

The lifecycle initializes the shared brightness prefix and scene allocator,
then destroys that allocator and frees its backing allocation through the main
allocator. The frame pair advances the scene, latches an exit request, processes
sound, enables three DISP3DCNT features, submits rendering, flushes OAM cache
ranges, and requests a geometry buffer swap. Unknown dependencies keep their
original address names; these descriptions do not establish the overlay's
gameplay identity.

The main dispatcher at 02001184 allocates 0xbc bytes, initializes the context,
calls 0218b5fc, destroys it, and frees the context. Overlay21Context models that
allocation with the 0x2c brightness prefix, actual SafeAllocator at 0x2c, scene
pointer at 0x40, texture-state subobject at 0x44, object pointer at 0xb4, and exit
flag at 0xb8. The texture subobject's two ten-word image-state arrays, two
palette-state records, allocation keys and sizes follow 0207de48/0207df50.
Compile-time checks establish 0x2c, 0x70 and 0xbc sizes. No shared header edits.

InitializeBrightnessState's existing GameResources interface is called through
a documented cast: its disassembly accesses only the common 0x00–0x28 prefix.
This overlay's later layout differs from GameResources, so the context does not
pretend to contain a full GameResources object.

## Attempts and validation

- Initial candidate comparison: both lifecycle functions exact, both frame
  functions exact (one source variant per function).
- First full acceptance failed ov021 because MWLD discarded the lifecycle unit:
  main's ambiguous overlay calls resolve to ov015/ov016 symbol names. The linked
  frame addresses consequently moved backward by 0x5c. No instruction changes
  were needed.
- Added `#pragma force_active on/reset` around the two lifecycle entrypoints.
  The second lifecycle comparison remained exact; full symbol addresses returned
  to their original values. This is retention metadata, not assembly or a code
  substitute.
- Three candidate-building comparison calls total, plus one read-only frame
  recheck. No unproductive instruction variants or exhausted prior caps.
- Final `.venv/Scripts/ninja.exe -j2 rom check report sha1` exited 0. All module
  and symbol checks passed, ARM7 baseline passed, and ROM SHA-1 equals
  `c7c3014c237900c8281289b8bc76a781969b6278`. Original input SHA-1 separately
  checked against the same value. Input/output isolation guards passed.
- `git diff --check` passed. No gameplay smoke test was performed in this batch.

Verbose original disassembly, acceptance logs, and final factory_evidence
packages are under ignored `build/factory/fleet_ov021/`. Candidate snapshots,
objdiff output, diagnoses and attempt counts are under `build/matching/`.
The batch start/finish records under `build/workflow/fleet_ov021_20261003_0145/`
provide measured elapsed wall time and revision/coverage snapshots. Tokens were
not measured.

## Coverage and remaining work

ARM9 report delta: +4 matched functions, +296 matched code bytes (284
instructions plus 12 literals), +0 initialized data bytes, +0 BSS bytes, and
no assembly added. Before/after: 1651/1655 functions, 218816/219112 code bytes,
66724/66724 data bytes. Denominators remain 14790 functions, 2959478 code bytes,
1602476 data bytes. ARM7 coverage unchanged. These are local worker gains,
pending integrator acceptance.

The 0x4fc-byte entry loop at 0218b5fc–0218baf8 remains original fallback,
including its 80-byte literal pool. The 16-byte rodata array at 0218bbc4 and
four-byte ctor entry remain fallback; no data coverage is claimed. External
scene/camera/sound/OAM internals remain unresolved, as do most entry-loop
dependencies. The module has no BSS payload in its current map. ov021 is not
complete. No queue edit, integration or merge was performed.

## Continuation: entry loop and edge-color dependency

Batch `fleet_ov021_20261003_entry_0416` began at 2026-10-02 15:51:15 UTC
from `6e1c6bdf8f91eede4ad7803d436fff6ad5a9dece`. The timestamp suffix is
an identifier, not the recorded start time. The worktree was clean; previous
evidence showed zero entry-loop variants. No queue or other-module edits.

**Verified gain:** `SceneEdgeColors.cpp`, rodata range `0218bbc4–0218bbd4`
(end exclusive), an actual eight-element unsigned-short RGB555 array/record.
All eight values are `0x1086`. The original entry copies the record to its
stack and calls `020c555c`, whose original code copies 16 bytes to `04000330`.
The source record is 16 bytes, with the mapped 4-byte section alignment.
Candidate comparison was 100% on the first variant; the original entry-loop
fallback now references this source-owned table.

**Capped function:** `func_ov021_0218b5fc`, range `0218b5fc–0218baf8`,
1276 bytes (1196 instructions, 80 literals), remains incomplete and original
fallback. `SceneEntry.cpp` retains the fourth, clearest candidate at 97.492165%
object similarity, with the edge-color type factored into its local header.
This percentage is diagnostic, with zero function/code/literal coverage credit.
Do not reset its cumulative **ten unproductive variants** in another batch.

The entry initializes display/VRAM banks and OAM, saves a texture allocation
scope, allocates a `0xdb8` scene and its `0x4b238` arena, runs the two existing
frame functions, then cleans up sound/graphics and restores the texture scope.
Original ov009 initializer/callers establish nine SafeAllocator subobjects
and a GameState indexed-record pointer at scene offset `0xd88`. Other external
layout bytes remain explicitly unknown. `02010954` returns a free
GameStateIndexedRecord; the previous context's `gameObject` field at `0xb4`
now has that correct shared type, preserving the layout and prior matches.

| Variant | Hypothesis | Entry similarity |
| --- | --- | ---: |
| 1 | Direct volatile registers, pointer color copy, conditional while | 50.47% |
| 2 | Enum IDs, BG1 base, explicit top-tested exits | 77.74% |
| 3 | Proposed linker-valued IDs, separate BG0 address, indexed color copy | 89.75% |
| 4 | Typed aggregate copy of eight halfwords | 97.49% |
| 5 | Explicit assignment for sub-display enable | 97.49% |
| 6 | One-expression SDK-style inline enable | 97.49% |
| 7 | Nonvolatile inline enable | 97.49% |
| 8 | Explicit inline control-word temporary (helper did not inline) | 91.54% |
| 9 | Enable within the timing call's comma argument | 97.49% |
| 10 | Inline helper carries timing receiver through enable | 97.49% |

Remaining target differences in variant 4: at function offsets `0x3b0–0x3c0`,
the original sub-display enable uses pointer r2/data r1 and prepares the next
call's r0 early; the candidate uses pointer r1/data r0 and moves the receiver
later. The literal values 9 and 23 differ from proposed absolute-ID relocations
in the candidate object. Their exact symbolic origin is a hypothesis, not an
established SDK interface. Proposed linker definitions are preserved only in
ignored `build/factory/fleet_ov021/entry_linker_symbols_hypothesis.json`.
No relocation, original object, or input binary was patched to erase differences.
Next work requires new evidence about the original SDK display accessor/call
interface and the overlay-ID expressions, rather than more equivalent variants.

Validation: 11 building comparisons (ten entry, one data) plus one read-only
recheck of the restored entry. The recheck confirmed the same 97.49% candidate.
Full `.venv/Scripts/ninja.exe -j2 rom check report sha1` passed, including all
module and symbol checks, ARM7 baseline, ROM input/output isolation and target
SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. `git diff --check` passed.
No gameplay test. No assembly added.

Report delta: **+0 functions, +0 instructions, +0 literals, +16 initialized
data bytes, +0 BSS bytes**. ARM9 before/after: 1655/1655 functions,
219112/219112 code bytes, 66724/66740 data bytes. Denominators remain
14790 functions, 2959478 code bytes and 1602476 data bytes. ARM7 unchanged.
The ctor's four-byte zero entry, entry-loop function and external implementations
remain unresolved. ov021 is incomplete; this is local worker evidence pending
integrator review.

All ten snapshots, diffs and conservative diagnoses remain under ignored
`build/matching/`; disassembly, factory evidence and full acceptance logs are
under `build/factory/fleet_ov021/`. Start/finish measurements are under
`build/workflow/fleet_ov021_20261003_entry_0416/`. Token usage is unmeasured.
