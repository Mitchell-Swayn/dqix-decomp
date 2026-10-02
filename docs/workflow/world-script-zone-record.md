# World zone-selected script record

Reconstructs `func_0208daf4` at `0208daf4..0208dc00` and `func_0208dc00` at
`0208dc00..0208dc74`. The runner initializes a three-field loading context with
the active Zone3D information and a caller-owned output record. Opcode 102 selects
the first record whose two integer selectors contain the active information's
16-bit selector. An already matched context rejects further records. Numeric
field names remain neutral until consumers establish their broader roles.

The shared header defines the actual 44-byte output object: a byte field, two
stored 16-bit selectors, a 16-byte text block, a byte field, a float, a fixed-point
vector, and a 16-bit fixed-point value. The reader copies all sixteen text bytes
with `memcpy`, then writes the final byte as zero. It does not initialize unrelated
record bytes. The first reader candidate incorrectly used `strncpy` and matched
98.51%; resolving the actual `memcpy` call was the only required code correction.
The runner matched on its first candidate. Compile-time assertions check record
and context sizes and the observed text/numeric/vector offsets. No GameState
byte-storage view or class-layout change was introduced.

The 16-byte opcode table at `020f1248..020f1258` and twelve-byte loading context
at `02108fc8..02108fd4` are source-owned initialized data and BSS respectively.
Both function objects and both data symbols compare at 100%. Full
`ninja rom check report sha1` passes module/symbol checks and the expected USA
ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. Final log is
`build/sol61-world-map-record/final-acceptance.log`. No gameplay test was run.
These source units are mapped only in USA configuration.

The batch adds two functions, 384 reported code bytes, and 28 reported data bytes.
The function ranges comprise 368 instruction bytes and sixteen compiler literal
bytes. Data comprises sixteen initialized bytes and twelve BSS bytes. Every
ARM9/ARM7 coverage denominator remains unchanged, with no ARM7 source delta.

Seven distinct unit-source SHA-256 versions were passed to candidate builds:
reader three, runner one, and data unit three. This includes layout assertions
and the mechanical rename of a vector field, excludes repeated comparisons of
unchanged sources, and is not an invocation count. The batch clock began after
accepted baseline `74e151d`; setup and integrator work are excluded. Token usage
is unknown. Queue state is integrator-owned.

The adjacent linked-record callback at `0208dc84` was inspected only; no source
candidate or coverage credit was taken. The inherited population draft remains
preserved and uncredited. Per the integrator's fleet transition, this worker stops
after this verified family.

`tools/work_batch.py` measured 490.657456 seconds (8.18 minutes) after baseline
acceptance. Snapshots are archived under `evidence/sol61-world-map-record-*.json`.
