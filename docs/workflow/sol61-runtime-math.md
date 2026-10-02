# Shared CRT math reconstruction (Sol 6.1, 2026-10-02)

Based on `4274776`. Before the batch snapshot, the checked-out worker baseline
passed `ninja rom check report sha1`. This batch reconstructs three functions
and seven related constant arrays without changing any original symbol address
or configured relocation.

`func_02005ac4` at `02005ac4..02005ea0` implements two-argument arctangent.
Its word tests propagate NaNs with `x + y`, preserve signed-zero quadrants,
handle both infinite arguments, shortcut `x == 1`, and avoid extreme ratios
using the exponent difference. Ordinary ratios call the existing source-owned
absolute-value and one-argument arctangent routines. The final two quadrants
use the original compensated pi subtraction order. The negative-y, positive-x
case flips the stored angle's binary64 sign bit.

Six initial candidates progressed from 51.01% to an exact 988-byte object.
Taking the stored angle's word view restored its original stack home; ordered
word declarations recovered register allocation, and signed low-word views
recovered both original parameter reloads. Low-word negation is performed as
unsigned subtraction to avoid signed overflow. A seventh source cleanup made
the `x == 1` word subtraction unsigned as well, retaining the exact match.
The source relies on the pinned little-endian MWCC binary64 word-access ABI,
like the existing source-owned floating-point helpers.

The adjacent entry functions `func_02009598` and `func_020095a4` at
`02009598..020095b0` call the two-argument arctangent and power routines.
Each matched its first candidate. The power implementation remains explicit
original fallback. The arctangent entry is called at `0202eb8c`; the power
entry is called by the decimal-to-binary routine at `0200a670` and `0200a6ac`.
These are original function boundaries, not newly introduced wrappers.

The constant region `020e6abc..020e6cc4` contains 520 source-owned bytes:

| Field | Offset | Extent | Evidence |
| --- | ---: | ---: | --- |
| `powerLog2High` | 0 | 16 | High 24-significand-bit parts of log2(1), log2(1.5). |
| `powerBases` | 16 | 16 | 1 and 1.5; power normalization indexes the pair. |
| `powerLog2Low` | 32 | 16 | Residual parts of the same logarithms. |
| `piOver2MultipleHighWords` | 48 | 128 | Binary64 high words of n*pi/2 for n=1..32; reduction tests cancellation against them. |
| `twoOverPiDigits` | 176 | 264 | 66 fractional base-2^24 digits of 2/pi supplied to the large reduction kernel. |
| `reductionTerms` | 440 | 16 | Four initial convolution term counts selected by the kernel precision index. |
| `piOver2Pieces` | 456 | 64 | Eight successive 24-significand-bit pieces of pi/2 used by the reduction convolution. |

`tools/generate_runtime_math_tables.py` regenerates the mathematical arrays
without reading any ROM. It computes pi by the Chudnovsky series at 540 decimal
digits, derives the 2/pi digit sequence and pi/2 pieces, and computes log2(1.5)
using high-precision Decimal logarithms. The four term counts are retained as
the observed algorithm configuration. The first generated record matched the
entire target `.rodata` payload exactly. Both payloads have SHA-256
`75c9dc07b3682eeea93c4a8285b754e0d716899605c0d76bb8149011f1bfa1a9`.
The target object's inferred section alignment is 1 and the typed candidate's
alignment is 4; the original four-byte-aligned linked addresses all pass.

The coherent record retains its original root name and all six interior names
through the reviewed linker alias support. All original relocation targets
remain unchanged. The interior target labels appear as unpaired in objdiff,
while the root and whole `.rodata` payload match at 100%. The report credits
exactly 520 data bytes; aliases introduce no additional storage or coverage.

Validation: exact function objects, explicit complete-table byte comparison,
the generator's `--check`, and full `ninja rom check report sha1` all pass.
The USA SHA-1 is `c7c3014c237900c8281289b8bc76a781969b6278`. Logs and hashes are
under ignored `build/sol61-runtime-*-acceptance.log`,
`build/sol61-runtime-math-bytes.json`, and `build/matching/`. Gameplay and an
independent numerical differential test were not performed; exact code and
data equivalence preserve the original implementation's behavior.

The batch adds 1012 reported code bytes (952 instructions and 60 compiler
literal-pool bytes), three functions, and 520 initialized read-only data bytes.
All code/data/function denominators and ARM7 coverage counters are unchanged.
Ten distinct candidates were measured: seven arctangent forms, one per entry
function, and one table record. Unchanged verification builds are excluded.
Token usage was not measured. Queue state is reported to the root integrator.
