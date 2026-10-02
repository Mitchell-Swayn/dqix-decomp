# Assigned ov009 lifecycle functions

Starting revision: `e041288d9d6de7c1ab10aa209ce1e0cc76aebae8`.
None of the five assigned functions was already covered. The packet's fallback
unit name `ov009_3` was stale: disassembly placed the first three in `ov009_6`
and the last two in `ov009_4`. Ownership follows the exact named ranges.

| Function | Bytes | Candidate comparisons, including final verification | Prior attempts |
|---|---:|---:|---:|
| `func_ov009_021842a0` | 684 | 2 | 0 |
| `func_ov009_0218454c` | 632 | 6 | 0 |
| `func_ov009_021847c4` | 40 | 2 | 0 |
| `func_ov009_02184848` | 464 | 2 | 0 |
| `func_ov009_02184a18` | 420 | 2 | 0 |

All five final objects match exactly. Initialization's five source variants
matched 96.20%, 94.94%, 98.73%, 96.20%, then 100%; four were unproductive.
Its final verification also matched 100%. The other functions matched on their
first comparisons and final verifications. Counts above include unchanged
verification comparisons, not only source variants.

Initialization requires branching on the byte assignment expression. Separate
one-element and four-element embedded arrays reproduce the two loop origins
and register scheduling. Allocation and destruction establish nine embedded
SafeAllocator objects, optional auxiliary arenas, and two text buffers.
The shared layout uses existing Object3D and ZoneState2754 declarations and
checks key offsets. Unresolved field and subobject meanings retain unknown names.

Advance copies thirteen native C++ member pointers, replaces the final entry
with the existing null member-pointer constant, and invokes the selected
callback. It retains native virtual dispatch and this adjustment. Referenced
callback data and other unassigned functions remain external dependencies;
no data or additional functions were reconstructed.

The initial full check exposed dead stripping of the allocation entry, whose
cross-overlay callers can be symbolized against other overlays at the same
address. A source `force_active` pragma preserves this entry without changing
its instructions. The subsequent module and symbol checks passed.

`ninja -j2 rom check report sha1` passed after the final changes: ARM9 main,
ITCM, DTCM, all 35 overlays, symbol verification, ARM7 baseline, and the exact
USA ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. The original input
was independently hashed and matched the same target. `git diff --check`
passed. Gain is five functions and 2,240 reported code bytes: 2,224 instruction
bytes and 16 literal bytes. Data/BSS gains are zero; denominators and ARM7
counters are unchanged. Only the assigned functions are credited.

Detailed candidates and comparisons are under ignored `build/matching/`;
disassembly is under `build/assigned-dis/`. Full acceptance output is
`build/assigned-acceptance-final.log`. Batch measurement uses
`build/workflow/assigned_ov009/`. The snapshot began after the first reset source
was written, using the unchanged starting report; it excludes initial reading
and disassembly time. No runtime smoke test or token measurement is claimed.
