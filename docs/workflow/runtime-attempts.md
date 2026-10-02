# Runtime matching attempts

## Runtime memory and text primitives (2026-10-02)

Based on `94fa80c`. The inherited VectorMath working-tree state was left alone.
The existing ignored string-input draft was inspected before new candidates.
Pinned MWCC 2.0/sp2p2, existing ARM9 options, and candidate-only compilation were
used throughout iteration. Original objdiff targets were not edited.

| Function | Distinct variants this batch | Result / useful finding |
| --- | ---: | --- |
| `memcpy` | 2 | Guarded do/while with pre-decrement count matches; post-decrement while puts a branch at entry. |
| `memmove` | 3 | Same loop shape; declare the destination cursor in each branch to preserve initial comparison order. |
| `memset` | 1 | Wrapper preserves destination across the existing fill-helper call. |
| `func_02001ac0` (memchr) | 2 | Guarded do/while preserves initial count test and byte truncation. |
| `func_02001aec` (memcmp) | 2 | Guarded do/while; preserve post-increment loads and reloads for the -1/1 result. |
| `func_02003d58` (string input callback) | 3 | Inherited goto shape is 128/132 bytes; early-return shape is 140/132. Inverting the unread branch (`!endOfInput` decrements cursor, else clears flag) exactly matches 132 bytes. |
| `func_020055d4` (decimal floating wrapper) | 1 | Tail call with null end pointer; target address remains a compiler relocation/literal. |
| `func_02005a94` (decimal integer wrapper) | 1 | Tail call with null end pointer and base 10. |
| `func_02005aa8` (wide-string length) | 1 | The existing strlen loop family matches with two-byte characters. |

Total: 16 distinct per-function variants, excluding unchanged functions recompiled
in a shared translation unit and final formatting/verification builds. No
function reached the ten-unproductive-variant limit. Generic names remain where
the runtime ABI has not been promoted to a public interface. The fill helper,
number parsers, and their data remain explicit original fallback dependencies.

Four new source units report 100%: nine functions and 432 code bytes, including
eight compiler-generated address-literal bytes. No new standalone data or BSS.
Local report delta: matched code 149,012 -> 149,444; matched functions
1,125 -> 1,134; matched data remains 26,488. Denominators remain 2,959,478 code
bytes, 1,602,476 data bytes, and 14,790 functions.

Validation: direct byte comparison during iteration; full objdiff JSON through
`match_unit.py --no-build` after source boundaries were installed; final source
formatting rebuilt and compared again. Logs and attempt JSON are under ignored
`build/matching/`. `ninja rom check report sha1` passed every ARM9 module and
symbol check, and the preserved ARM7 baseline check. This older worktree's
configure script predates the guarded USA header-finalization step, so its raw
ROM SHA-1 step failed. Running the already accepted main-worktree
`tools/finalize_rom_header.py` with a separate output then passed the exact USA
SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. No build-pipeline changes are
included in this batch. Logs: `build/runtime-primitives-acceptance.log` and
`build/runtime-primitives-finalize.log`. Integration must rerun the current main
pipeline. This evidence establishes byte equivalence, not gameplay validation.
