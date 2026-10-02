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

## Runtime fill, character conversion, and formatted output (2026-10-02)

Based on `ce799e9`. Seven functions in four new units add 448 code bytes
(444 instruction bytes and one four-byte callback-address literal), no data/BSS.
The source-defined optimized fill routine removes `memset`'s remaining original
code dependency. The formatter engine at `02003418` remains original fallback.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_02001b2c` (aligned memory fill) | 1 | Alignment prologue, eight-word blocks, trailing words and bytes match directly. Preserve conditional byte replication and threshold 32. |
| `func_02001960` (byte to wide character) | 4 | Ternary and result-variable forms reverse the two predicated result moves; explicit zero return followed by one return matches. |
| `func_02001998` (wide character to byte) | 1 | Null destination returns zero; otherwise truncate to one byte and return one. |
| `abs` | 1 | Conditional negation matches. |
| `func_020017b0` (long absolute value) | 1 | Same compiler family as abs; retain generic symbol. |
| `func_02003c3c` (bounded output callback) | 1 | Clamp copy length to remaining capacity, copy, then advance the stored count. |
| `func_02003c80` (bounded formatting wrapper) | 2 | Explicit state-member stores avoid aggregate zero-fill; `(buffer + size)[-1]` retains the target address calculation. |

Eleven distinct per-function variants; maximum four on one function. Formatting
and unchanged shared-unit recompilation are excluded. Candidate objects were
compiled without full-ROM builds until they matched. All four units then passed
objdiff at 100%, including after source formatting. Runtime edge behavior is
preserved, including unsigned byte conversion, zero-count operations, and the
original null-buffer/termination logic.

`ninja rom check report` passed ARM9 main, ITCM, DTCM, all overlays, symbol checks,
and the ARM7 preservation baseline. The existing main-worktree guarded header
finalizer again produced exact USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; the older configure-script caveat from
the preceding batch still applies. Logs: `build/runtime-batch2-acceptance.log`,
`build/runtime-batch2-finalize.log`, and `build/matching/` full objdiff/attempts.
Local matched code 149,444 -> 149,892; matched functions 1,134 -> 1,141;
matched data stays 26,488. All three denominators are unchanged. Main integration
must rerun its current pipeline. No gameplay validation was performed.
