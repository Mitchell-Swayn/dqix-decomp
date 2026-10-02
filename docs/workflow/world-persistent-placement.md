# World persistent placement initialization

Reconstructs ARM9 `func_0208ea10` (`0208ea10..0208ec04`) and
`func_0208ec04` (`0208ec04..0208ec78`), with the original 96-byte initialization
opcode/path pool at `020f1308..020f1368`. The initialization routine parses the
variant table and field scripts 1 through 63, then initializes persistent records
98 and 99. The reset routine clears placement flags and derives the low nine-bit
value from the four-bit field at bit 25. The source keeps neutral names for fields
whose broader semantics are not established.

Both functions compare at 100%. The pool is one typed contiguous object.
Original path names and relocation targets remain checked through source-owned
interior aliases; the pool's base name becomes `gWorldPlacementPersistentData`.
This config depends on the accepted alias helper from integrator commit
`8ffd3d6`; a temporary exact copy of its `tools/generate_lcf.py` was used for
worker validation and is excluded from this source commit.

Objdiff splits the original pool into four symbol extents while the candidate
owns all 96 bytes. Its per-symbol score is therefore 70.59% plus three unpaired
interior aliases. Direct ELF comparison confirms identical 96-byte `.data`
contents and the same four ARM ABS32 callback relocations, normalized by offset.
Full module and symbol checks verify all retained aliases at their original
addresses. Evidence is `build/sol61-world/data-section-compare.json`.

`ninja rom check report sha1` passes with expected USA ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; final log is
`build/sol61-world/alias-acceptance.log`. Coverage gains are +2 functions,
+616 reported code bytes, and +96 initialized data bytes. The function ranges
contain 588 instruction bytes and 28 compiler-generated literal bytes. The
initialized data consists of 40 opcode-table bytes and 56 path-slot bytes.
All three ARM9 denominators remain unchanged. No gameplay test was run.

Candidate experiments: reset 2, initialization 6 (including carrier/alias access
variants), data pool 2. The initialization required computing its table address
inside the final loop to reproduce the original address scheduling. Declaring
that base earlier moved one ADD; moving the loop counter first also changed
register allocation.

The inherited population draft at `0208f168` remains uncredited and untracked.
Six new variants reproduced the already documented 97.674416% result in
`world-attempts.md`: all differences are the combined predicate/object-null
guard. This duplicate effort adds no new matching evidence. The original draft
and delinks are archived under `build/sol61-world/inherited-*`; the corrected
97% draft remains `src/World/WorldObjectInstanceListPopulate.cpp` with no active
delink. Further work requires new evidence for that early branch.

The batch clock began after valid baseline acceptance at 2026-10-02 13:14:16 UTC.
`tools/work_batch.py` measured 1,026.881068 seconds (17.11 minutes) after
baseline acceptance; worker integration time is separate. Snapshots are archived
as `evidence/sol61-world-start.json` and `evidence/sol61-world-finish.json`. Token usage is unknown.
