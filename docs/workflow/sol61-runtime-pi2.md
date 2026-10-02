# Pi/2 reduction investigation

This bounded batch accepted no new code or data. Both reduction routines remain
required original fallbacks. Temporary source ownership blocks were removed
before full acceptance; no symbols, relocations, aliases or denominators changed.
Queue state is left to the root integrator.

`func_02007028`, range `02007028..020076f0`, reduces a binary64 argument by
an integer multiple of pi/2 and returns a compensated two-double remainder.
Its small-input cases handle zero or one multiple directly, its medium path
uses successively finer products when cancellation exceeds 16 or 49 exponent
bits, and its large finite path splits the mantissa into up to three base-2^24
chunks before calling `func_02007a10`. The source-owned sine and cosine routines
still depend on this fallback. Its tables retain the existing mathematical
definitions and original interior symbol references.

Ten source hypotheses were compared, plus one failed compilation caused by a
prefix-replacement typo; that typo was corrected within the same hypothesis.
The comparisons were: initial translation (74.42%), guarded trailing-zero
chunk trimming (86.87%), reusing the absolute value as `r` (74.19%), reordered
double declarations (86.87%), reusing exponent difference locals (86.87%),
reversed multiplication operands (86.87%), using `z` for the absolute value
(67.74%), a scoped absolute-value temporary (74.19%), separately scoped saved
remainders (89.17%), and separately scoped multiplication corrections (95.62%).
Unchanged recompilations were not counted as new hypotheses. The ten-hypothesis
cap was reached and work switched to the large-input kernel.

The closest outer reducer has the target's exact 1736-byte function extent.
Small-input cases, the initial medium path, and large-input chunk processing
align; the remaining differences concern stack locations and registers in the
second and third cancellation refinements. First differences are spills at
offsets `0x308`, `0x30c`, and the corresponding reload at `0x358`. Its preserved
draft is ignored `build/RuntimePiReduction-pending.cpp`, SHA-256
`a34b155253b728222d2c82005d7308c59fa76bdec61dfccc78de1714a93daf9f`.
Comparison evidence is under
`build/matching/20261002T140741-82adc08a927246768a69d72b3884c891/`.
Future work needs concrete evidence for the remaining cancellation temporary
lifetimes before resuming this capped routine. Its word casts still rely on
pinned-MWCC type punning; the draft does not establish portable C++ alias safety.

`func_02007a10`, range `02007a10..020085cc`, convolves those chunks with the
existing 2/pi digits and pi/2 pieces, keeping the integer multiple modulo eight
and selecting one, two or three output components by precision. A reference
translation informed by the permissively licensed
[Sun fdlibm kernel](https://netlib.org/fdlibm/k_rem_pio2.c) was compared at 29.43%.
Explicit nonnegative loop guards gave 29.56%. The target uses a 0x264-byte local
frame; the first candidate uses 0x24c and is 2832 rather than 3004 bytes. The
reference license notice is preserved in the draft. The existing target table's
term counts `{2,3,4,6}` remain authoritative rather than newer library defaults.

Kernel source is preserved as ignored `build/RuntimePiReductionKernel-pending.cpp`,
SHA-256 `4f50a4ea2bcde8b7e4354b29f9284a82d0ae973248dd53cc8debfcab4252f146`.
Kernel comparison logs
are under `build/matching/20261002T141148-db3a0aec76c34ca4b7adf5882016857c/`.
Only two kernel hypotheses have been tried; the next useful investigation is
target loop structure and temporary homes, not further outer-reducer variants.
The kernel draft has not been numerically validated or accepted.

After restoring both fallbacks, `ninja rom check report sha1` passed full module,
symbol, ARM7 baseline and ROM checks. The independent original input and output
both have SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. An immediate
`ninja rom report` was a no-op. Logs remain in ignored
`build/sol61-runtime-pi2-acceptance.log` and `build/sol61-runtime-pi2-noop.log`.
Thirteen candidate compilations were attempted: ten compared outer hypotheses,
one outer typo failure and two compared kernel hypotheses. A build-graph setup
failure before regenerating configuration did not compile source and is excluded.
Token usage was not measured. Batch snapshots record the verified zero delta
and 1245.0 elapsed seconds; neither draft contributes coverage. The baseline
snapshot preceded the atan2 portability-review experiments, so this interval
includes that review as well as reduction work. Snapshots are archived as
`evidence/sol61-runtime-pi2-start.json` and
`evidence/sol61-runtime-pi2-finish.json`.
