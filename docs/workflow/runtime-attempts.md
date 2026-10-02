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

## Runtime stream buffers and sprintf (2026-10-02)

Based on `e41f6a4`. Six functions in three new units add 568 code bytes
(564 instructions and one four-byte stream-table address literal), no data/BSS.
The stream table remains original data and the formatter engine remains original
code. The source-defined flush/reset/write routines now call each other directly.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_0200173c` (flush three standard streams) | 2 | Invert the next-index condition to retain the branch and original register allocation. |
| `func_020017bc` (text-conversion hook) | 1 | Original body is exactly one return instruction; reconstructed as the corresponding empty C function, not a substitute for missing behavior. |
| `func_020017c0` (reset buffer cursor/capacity) | 1 | Preserve alignment-mask subtraction and reload of stream position. |
| `func_020017f0` (write pending buffer) | 1 | Preserve callback ABI, output count, position advance, and reset only after success. |
| `func_02001878` (flush stream state) | 1 | Reconstructed bitfields reproduce the observed mode/state extraction and updates. |
| `sprintf` | 4 | Two unavailable stdarg/builtin spellings rejected; address rounding-up adds an instruction; the observed aligned last-parameter home slot plus four bytes matches. |

Ten distinct per-function variants including rejected compiler candidates;
maximum four for one function. `RuntimeStream.h` documents an inferred 0x4c-byte
ABI with reserved fields and a compile-time size check. Names describe observed
use, not recovered original declarations. `#pragma dont_inline on` retains the
observed calls, including the original empty text hook. Generic symbols remain.

The sprintf argument-pointer expression is specific to the pinned MWCC ARM
variadic ABI: taking the last named parameter's address makes the compiler save
r0-r3 contiguously with stack arguments; the next aligned four-byte slot begins
the unnamed arguments. This is documented in source and is not a portable host
varargs implementation. Its complete 44-byte body, including stack register
saves/restores and call relocation, matches.

All three units pass objdiff at 100% after final source formatting. The single
batch ROM build passed ARM9 main, ITCM, DTCM, all overlays, symbols, and ARM7
preservation; the existing main header finalizer produced exact USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The older configure-script caveat
still applies. Logs: `build/runtime-batch3-acceptance.log`,
`build/runtime-batch3-finalize.log`, and `build/matching/`.
Local matched code 149,892 -> 150,460; functions 1,141 -> 1,147; data unchanged
at 26,488. All denominators unchanged. No gameplay validation was performed.

## Runtime termination and wide conversion (2026-10-02)

Based on `37e290b`. Six functions in three new units add 624 code bytes
(584 instructions and forty compiler-generated address-literal bytes), no
data/BSS. Exit callback state, mutex bookkeeping, destructor-list head and
locale tables remain external fallback globals. Source-defined exit handling
now reaches the source-defined destructor chain and stream flush routines.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_02001578` (abort path) | 1 | Raise signal 1, set the original abort flag, and enter termination. |
| `func_0200159c` (termination dispatch) | 1 | Preserve destructor/early-hook suppression on abort and clear the hook after calling it. |
| `func_020015e8` (exit callback stack) | 6 | Guarded do/while retains the original first check; explicit index and handler temporaries with volatile count/table preserve the original reload and fetch-before-count-store sequence. |
| `func_0200edf4` (destructor chain) | 2 | Guarded do/while and explicit reload of the list head reproduce callback-safe traversal. |
| `func_020019ac` (locale character encoder) | 1 | Dispatch through the locale's character-method table. |
| `func_020019c8` (wide string conversion) | 1 | Preserve null-pointer handling, the four-byte temporary, truncation/count comparison and original terminating-byte behavior. |

Twelve distinct per-function variants; maximum six for one function. Unchanged
shared-unit recompiles and formatting checks are excluded. Exit-loop variants
covered a while loop, separate handler/count expressions, guarded pre-decrement,
a saved index, and successive explicit shared-access qualifiers. The volatile
qualifiers model the observed shared callback-stack access ordering; they do
not establish the original source declarations. Recursive mutex handling keeps
the same counterintuitive TryLockMutex branch as the earlier signal dispatcher.
The unused final status argument and ordinary return paths remain as observed.

All three units report 100% objdiff. One full batch build passed ARM9 modules,
symbols, and ARM7 preservation. Main's existing guarded header finalizer again
produced exact USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`; the older
configure-script caveat remains. Logs: `build/runtime-batch4-acceptance.log`,
`build/runtime-batch4-finalize.log`, and `build/matching/`.
Local matched code 150,460 -> 151,084; functions 1,147 -> 1,153; data unchanged
at 26,488. Denominators unchanged. No gameplay validation was performed.

## Binary64 inspection and decimal rounding (2026-10-02)

Based on `aee1f08`. Six matched functions in five units add 376 code bytes
(368 instructions and eight compiler-generated mask-literal bytes), no data/BSS.
Binary64 helpers preserve raw sign/payload bits, including zero, subnormal,
infinity and NaN cases. Classification result values remain 1=NaN, 2=infinity,
3=zero, 4=normal, 5=subnormal. The sign test retains its sign-mask return value.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_02008da4` (copy sign) | 1 | Direct high-word masking matches both argument homes. |
| `func_02008f3c` (absolute value) | 1 | Explicit word pointer retains the observed stack address register. |
| `func_0200aa60` (sign bit) | 1 | High-word sign mask matches. |
| `func_0200aa74` (classify binary64) | 1 | Separate exponent and fraction tests match both literal masks. |
| `func_020095b0` (decimal rounding comparison) | 2 | Guarded do/while retains the top range check; exact ties inspect the preceding digit's parity. |
| `func_0200966c` (round decimal length) | 1 | Preserve length update before testing the rounding direction and calling the increment helper. |
| `func_0200961c` (increment decimal digits, deferred) | 4 | Best candidate matches the first 76 bytes exactly but MWCC emits an extra unreachable return; alternate while shape does not match. |
| `func_02009668` (adjacent return, deferred) | 1 | Although an empty function matches this four-byte label alone, it is not accepted independently because the preceding candidate produces this same trailing return. |

Twelve distinct per-function candidates, seven for accepted functions and five
for the deferred pair; maximum four for one function. The increment helper and
adjacent label remain original fallback with no new source credit. This is a
possible function-boundary question, not evidence authorizing a denominator or
symbol-size change. Next investigation should trace callers/boundaries and the
compiler's epilogue behavior before further source variants. The ignored draft
`build/RuntimeDecimalRounding-pending.cpp` retains the best shape. No metadata
or original target objects were patched.

`RuntimeDecimal.h` records the sign/exponent/length layout and 32-digit capacity,
confirmed by the limits at `02009880` and `02009924`; no object is source-owned by
this declaration. All five accepted units report 100% after final formatting.
One ROM build passed all ARM9 module and symbol checks and ARM7 preservation;
the existing main guarded finalizer produced exact USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Older configure caveat unchanged.
Logs: `build/runtime-batch5-acceptance.log`, `build/runtime-batch5-finalize.log`,
and `build/matching/`. Local matched code 151,084 -> 151,460; functions
1,153 -> 1,159; data stays 26,488. Denominators unchanged. No gameplay test.

## Decimal construction and magnitude comparison (2026-10-02)

Based on `cd3b5ac`. Four functions in three units add 808 instruction/code bytes,
no compiler literals, standalone data or BSS. These retain the existing decimal
layout and leave division/modulo and decimal-increment dependencies unchanged.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_020096ac` (unsigned integer to decimal) | 2 | Match division/remainder calls and use a first-digit temporary to preserve the original swap/store order. |
| `func_020098fc` (text to decimal) | 2 | Explicit next-byte temporary reproduces the initial load-before-increment; preserve the original comparison of the raw next byte to numeric 5. |
| `func_02009d1c` (magnitude equality) | 3 | Declare the running index first and retain the observed tail-length reload. |
| `func_02009dfc` (magnitude ordering) | 5 | Explicit right-then-left digit temporaries avoid pointer hoisting and reproduce register order; retain the tail-length reload. |

Twelve distinct candidates; maximum five on one function. A repeated compile
whose text replacement made no change is not counted as a new variant. Testing
optimize-for-size on did not change the two comparison results. Volatile reads
are limited to the observed tail-loop length loads; they preserve generated
accesses rather than assert recovered original qualifiers. The helpers compare
magnitudes without consulting sign and retain their zero/length edge behavior.
In particular, the text constructor's numeric-5 test is not silently changed to
ASCII '5', and integer zero retains zero digits and exponent -1.

All three units report 100% objdiff after formatting. One full ROM build passed
ARM9 main, ITCM, DTCM, all overlays, symbol checks, and ARM7 preservation. Main's
existing guarded header finalizer produced exact USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; older configure caveat unchanged.
Logs: `build/runtime-batch6-acceptance.log`, `build/runtime-batch6-finalize.log`,
and `build/matching/`. Local matched code 151,460 -> 152,268; functions
1,159 -> 1,163; data unchanged at 26,488. Denominators unchanged. No gameplay test.

## Runtime value, allocator, and termination hooks (2026-10-02)

Based on `ec1482a`. Five functions in three units add 116 code bytes
(100 instructions and sixteen compiler-generated address-literal bytes), no
data/BSS. These reconstruct the existing runtime-to-platform interfaces, not
new assembly trampolines: the pinned compiler emits the observed tail calls.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_02001710` (stored NaN conversion) | 1 | Load the existing binary32 value and call its existing double converter. |
| `func_02001728` (conditional release) | 1 | Preserve the null-pointer check before the existing release entry. |
| `func_0200ab10` (default arena release) | 1 | Call the source-defined `FreeArenaHeap(0, -1, pointer)`. |
| `func_0200f368` (termination platform hook) | 1 | Call the existing platform routine with the observed tail-call ABI. |
| `__clear` | 2 | Returning the original destination preserves r0 and matches the separate cursor register; void form was four bytes short. |

Six distinct candidates, maximum two on one function. The `__clear` return type
is inferred from preserved register behavior; no original declaration is claimed.
The binary32 NaN storage and conversion/platform routines remain explicit
fallback dependencies. Source-defined termination now reaches the matching
platform hook, and conditional release reaches the matching allocator wrapper.

All three units report 100% objdiff. One full ROM build passed all ARM9 modules,
symbols, and ARM7 preservation; main's existing guarded header finalizer produced
exact USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. Older configure
caveat unchanged. Logs: `build/runtime-batch7-acceptance.log`,
`build/runtime-batch7-finalize.log`, and `build/matching/`.
Local matched code 152,268 -> 152,384; functions 1,163 -> 1,168; data remains
26,488. Denominators unchanged. No gameplay validation was performed.

## Binary64 floor, exponent, and sine helpers (2026-10-02)

Based on `c6569b9`. Four functions add 1,596 code bytes (1,508 instructions
and 88 compiler literal bytes), with no data/BSS or denominator changes.

| Function | Distinct variants | Result / useful finding |
| --- | ---: | --- |
| `func_02008f5c` (floor) | 3 | Signed word reads preserve stack reloads; declaring exponent before the low word gives the observed allocation. |
| `func_0200911c` (fraction/exponent decomposition) | 1 | Normalize subnormals with 2^54 and retain zero/nonfinite behavior. |
| `func_020091d8` (power-of-two scaling) | 2 | Signed low-word read and constant-first final multiplication retain the observed order. |
| `func_02009424` (sine dispatch) | 2 | Initialize zero before reading the high word; preserve reduction quadrant and kernel arguments. |

Eight distinct variants, maximum three per function. Word access follows the
pinned little-endian binary64 ABI. Large/small arithmetic and the original
nonfinite/signed-zero paths remain explicit; no floating-point simplification
or replacement library is used. Existing reduction and sine/cosine kernels
remain fallback dependencies.

Native C arithmetic identifies four compiler runtime symbols from call-site
relocations and original branch destinations: `_dadd` at 0x0200ab28, `_dmul`
at 0x0200b0f0, `_dsub` at 0x0200b608, and `_dgr` at 0x0200bc78. Only those
symbol names change; addresses, sizes, binding and function counts do not.
Searches of both worktrees' src/include found no old-name references to update.
No object or relocation is rewritten for comparison.

All four units report 100% objdiff. The full ROM build passed module/symbol
checks and ARM7 preservation. Main's existing guarded finalizer produced exact
USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`; the older local configure
still lacks that final build step, so it wrote a separate ignored output ROM.
Logs: `build/runtime-batch8-acceptance.log`, `build/runtime-batch8-finalize.log`,
and `build/matching/`. Local matched code 152,384 -> 153,980; functions
1,168 -> 1,172; data remains 26,488. No gameplay validation was performed.

## Binary64 trigonometric kernels (2026-10-02)

Based on `64714ba`. Three functions add 1,804 code bytes (1,680 instructions
and 124 compiler literal bytes), no data/BSS. Each matched its first distinct
candidate: cosine dispatch `func_02008dcc`, sine kernel `func_020085cc`, and
cosine kernel `func_020076f0`. All three units report 100% objdiff.

The kernels retain the original polynomial coefficients and evaluation order,
small-argument integer conversion, compensated tail arithmetic, and cosine's
high-word-derived quarter argument. Decimal coefficient spellings reproduce the
original binary64 literal bits. The existing sine dispatcher now reaches two
source-defined kernels; argument reduction remains fallback. Native `(int)x`
conversion emits `_dfix`, identifying its original entry at 0x0200af44. Only
that symbol name changed, with size/address/count untouched and no existing
src/include references requiring updates in either worktree.

Full module/symbol/ARM7 checks passed, and the guarded separate-output finalizer
produced USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. The old local
configure finalization caveat remains. Logs: `build/runtime-batch9-acceptance.log`,
`build/runtime-batch9-finalize.log`, and `build/matching/`. Local matched code
153,980 -> 155,784; functions 1,172 -> 1,175; data unchanged at 26,488.
Denominators unchanged. No gameplay validation. The work_batch start command
resolved its imported script's MAIN root, so that ignored timing snapshot does
not measure this isolated batch's coverage; no elapsed result is claimed here.

## Arctangent and exponent scaling dependencies (2026-10-02)

Based on `46b1749`. Two functions plus their two read-only tables add 1,416 code
bytes (1,368 instructions and 48 literals) and 152 initialized data bytes, no BSS.
The arctangent body `func_02008848` matched in eight distinct variants; exponent
wrapper `func_0200aae4` matched its first. All three units and both data symbols
report 100% objdiff. Inspection-to-final-validation artifact timestamps measured
492.7 seconds; this is wall time, not CPU time or a future estimate.

The arctangent preserves all four reduction intervals, tiny/huge/nonfinite
behavior, coefficient order, and the compensated low/high-angle result. A separate
result local fixes allocation versus reusing z. External tables alone lost one
original duplicate literal, while merging all tables changed coefficient loads.
Defining the contiguous 64-byte low/high angle struct with the function and
keeping the 88-byte coefficient array separate reproduces the original code and
read-only data. Values are decimal spellings of the original binary64 constants.

The guessed interior symbol at 0x020e6ce4 is now the high member of
`gRuntimeArctangentAngles` at 0x020e6cc4. Its sole relocation from 0x02008da0 is
represented as the same base plus 0x20, preserving the resolved pointer exactly.
Explicit 64/88-byte data sizes document the recovered layouts; no code ranges,
function counts, or coverage denominators change. No other source references
needed updating. This is source-level data ownership and relocation grouping,
not a modification of candidate/original object bytes.

Full modules, symbols and ARM7 preservation passed; the guarded separate-output
finalizer produced exact USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
Older configure caveat unchanged. Logs: `build/runtime-batch10-acceptance.log`,
`build/runtime-batch10-finalize.log`, and `build/matching/`. Local matched code
155,784 -> 157,200; functions 1,175 -> 1,177; data 26,488 -> 26,640.
No gameplay validation was performed.

## Decimal bit count and formatting (2026-10-02)

Based on `ab542e0`. Two exact dependencies add 316 code bytes (304 instructions
and twelve compiler mask-literal bytes), no data/BSS. Bit count `func_0200a9cc`
matched its first parallel unsigned-64-bit reduction. Decimal format
`func_0200a300` took four variants: guarded do/while loops and a separate digit
load before the postincrement store preserve the original loop scheduling.
The first format halfword remains explicitly uninterpreted; precision is the
signed halfword at +2. Special N/I digits bypass numeric padding/conversion.

Decimal multiply `func_02009778` remains fallback after nine variants. Its
388-byte control flow and division literals match, but local allocation and
left-length-load scheduling still differ (best direct comparison 323/388 bytes,
including unresolved call relocation). Guarded loops fixed the initial 12-byte
shortfall; scoped/predeclared indices, pointer-base hoisting, chained end/cursor
initialization and explicit available-length locals did not resolve allocation.
A volatile-read trial had no benefit and is not installed. No further variants
were attempted. Next useful evidence is original declaration/lifetime structure
or a independently matching caller; no ABI/register shim or assembly substitute.
The earlier decimal-increment/no-op boundary issue also remains deferred.

Both installed units are 100% objdiff. Full modules/symbols/ARM7 checks passed;
guarded separate-output finalization produced exact USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Older configure caveat unchanged.
Inspection-to-validation artifact timestamps measured 408.4 seconds. Fourteen
distinct candidates total including the deferred multiply. Logs:
`build/runtime-batch11-acceptance.log`, `build/runtime-batch11-finalize.log`,
and `build/matching/`. Local matched code 157,200 -> 157,516; functions
1,177 -> 1,179; data remains 26,640. Denominators unchanged; no gameplay test.

## Decimal decomposition and powers of two (2026-10-02)

Based on `e43be00`. Two functions add 1,284 code bytes (1,200 instructions,
including the original switch branches, and 84 address literals); their numeric
text table adds 212 initialized data bytes. No BSS or denominator changes.

| Function/data | Distinct variants | Finding |
| --- | ---: | --- |
| `func_0200a180` (double-to-decimal) | 3 | Keep the normalized double live separately from its bit-view union; declare integer/power temporaries in original stack order. |
| `func_02009998` (decimal power of two) | 4 | Preserve division-toward-zero bias and full 38-byte decimal object copy through a typed union; a memberwise copy omitted padding and memcpy remained a call. |
| `gRuntimeDecimalPowers` | 1 | Twenty-one numeric strings with their verified zero padding occupy 212 bytes. |

The converter preserves signed zero and N/I exceptional output, computes the
significand's effective width through bit count, and uses the existing decimal
multiply fallback. The power routine retains the original precomputed cases,
recursive squaring, and odd positive/negative adjustment. Source-owned strings
have their original mutable data-section placement; no ROM byte array is used.

Native unsigned-64-bit conversion identifies `_ll_ufrom_d` at 0x0200afe8; only
its name changes. The text table's 21 former labels become one typed struct;
21 affected relocation records express the same addresses as base+member offset
(the first base reference is already unchanged). A mechanical comparison checked
that every configured main-module load relocation still resolves identically.
No USA source references needed updating. An unrelated Japanese-only address
alias in Zone3D remains untouched.

All three units report 100% objdiff. Full modules/symbols/ARM7 preservation and
guarded separate-output finalization pass with USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; older configure caveat unchanged.
First-draft creation to final-validation artifact timestamps measured 358.6 seconds.
Logs: `build/runtime-batch12-acceptance.log`, `build/runtime-batch12-finalize.log`,
and `build/matching/`. Local code 157,516 -> 158,800; functions 1,179 -> 1,181;
data 26,640 -> 26,852. No gameplay test. Deferred multiply/increment remain fallback.


## Console stream callbacks and bounded follow-up probes (2026-10-02)

Based on `6f9c22f`. Three callbacks add 140 instruction bytes, no literals/data/BSS:
read `func_0200d8cc` (three variants), write `func_0200d91c` (two), and close
`func_0200d950` (one). Read preserves requested count except when CR/LF terminates
input; comparisons mask the raw semihosting return to one byte while the store
keeps the original raw-value register. Write passes each character's address to
the existing semihosting entry. Handle/context remain intentionally unused,
and close returns the observed success value. The BIOS/semihosting routines
remain explicit assembly fallback; these are ordinary C callbacks, not wrappers
claiming their instructions.

Decimal subtraction `func_02009edc` remains fallback after four variants. Whole
object copying and guarded borrow/normalization loops produce the exact 676-byte
shape, but long-lived pointer allocation differs (best direct 576/676 bytes).
Predeclared remainder and recomputed-base forms did not resolve it. Packed signed
and unsigned decoders `func_0200d958`/`func_0200d9e4` remain fallback after four
variants each: the compiler hoists their shared prefix shift and emits 136 rather
than 140 bytes; explicit intermediates and byte signedness changes did not help.
Removing optimize-for-size-off worsened both to 128 bytes. No code-range changes
or assembly substitutions were made. Further work needs compiler-family/source
expression evidence; the existing candidates remain ignored drafts.

The installed unit is 100% for all three symbols. Full module/symbol/ARM7 checks
and guarded separate-output finalization pass with USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; older configure caveat unchanged.
Eighteen distinct candidates including deferred probes; maximum four per function.
First-inspection artifact timestamp to these notes: 530.1 seconds wall time.
Logs: `build/runtime-batch13-acceptance.log`, `build/runtime-batch13-finalize.log`,
and `build/matching/`. Local code 158,800 -> 158,940; functions 1,181 -> 1,184;
data remains 26,852. Denominators unchanged; no gameplay validation.

## Runtime unwind table lookup (2026-10-02)

Based on `6911520`. Four functions add 440 code bytes (436 instructions and
one four-byte division literal), no data/BSS. Each matched its first candidate:
range binary search `func_0200da70`, action lookup `func_0200dad4`, action tag
`func_0200dbdc`, and descriptor-header skipping `func_0200f2bc`.

The 12-byte range and 20-byte lookup-state types record observed offsets with
size checks. Range endpoints remain inclusive. Low size bit selects an inline
descriptor instead of a descriptor pointer. Header flag0x40 consumes a second
packed integer. The lookup preserves zero termination, delta/length accumulation,
early out-of-range returns, and the five-bit action tag. Packed decoding and
table-provider entries remain explicit fallback; no low-level context restore or
assembly exception gains source credit. The table provider's coincident empty
boundaries are left untouched pending linker-boundary evidence.

Both units and all four symbols report 100% objdiff. Full modules/symbols/ARM7
checks and separate-output guarded finalization produce exact USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; older configure caveat unchanged.
Inspection-to-validation timestamps measured 159.9 seconds. Logs:
`build/runtime-batch14-acceptance.log`, `build/runtime-batch14-finalize.log`,
and `build/matching/`. Local code 158,940 -> 159,380; functions 1,184 -> 1,188;
data remains 26,852. Denominators unchanged. No gameplay validation.
