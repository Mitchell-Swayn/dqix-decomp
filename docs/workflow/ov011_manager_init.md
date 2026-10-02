# ov011 assigned manager initializers

Starting revision: `039055bbde7fd706535beafb996dc6148b2b6589`.
Neither assigned function was already source-covered. Only the contiguous
`0x02184374..0x021844a4` range is reconstructed; other fallback code stays required.

| Assigned function | Size | Cumulative candidates, including prior attempts | Result |
| --- | ---: | ---: | --- |
| `func_ov011_02184374` | 24 | 3 (prior 0) | 100% object match |
| `func_ov011_0218438c` | 280 | 3 (prior 0) | 100% object match |

The first two candidates failed compilation because `string.h` was unavailable
and `System/Memory.h` did not declare `memset`. Using the existing
`std_library_functions.h` declaration produced the first compiled object,
matching both functions exactly. Tool setup failures before compilation are
not additional source variants.

The smaller initializer clears two halfword counters and two links in a
0x7c-byte record. The manager initializer resets its existing allocator-node
prefix, selected fields and a 0x54-byte buffer, initializes external subobjects,
and saves hardware power/display flags. Unknown fields retain offset-based
names and opaque payloads. No other functions or initialized data are defined.

Object evidence: ignored
`build/matching/20261002T185021-bbae1ce437644c83925cdd0039089d0e/`.
Target SHA-256 before and after comparison:
`7697239d3ec066616c254bc466f8fa71be71cb4202b4d5a4f84f079caa651143`.
Compiler failures: `build/ov011-compile.log` was overwritten by the final
successful compile; their diagnostics and tested includes are recorded above.
No assembly or binary substitutes were used. No dependency requests are needed.

Baseline acceptance log: `build/ov011-baseline.log`.
Batch acceptance log: `build/ov011-manager-accept.log`.
Measurement: `build/workflow/ov011-manager/`.
The independently hashed input ROM is
`c7c3014c237900c8281289b8bc76a781969b6278`.
No runtime smoke tests were performed; token usage was not measured.

`ninja rom check report sha1` passed: all modules and symbols, ARM7
preservation, input/output isolation, and exact USA ROM SHA-1. Batch elapsed
time was 347.784883 seconds. ARM9 report gains are two functions and 304 code
bytes (300 instruction bytes and four literal bytes); initialized data and
BSS gains are zero. All denominators and ARM7 counters remain unchanged.
Matched ARM9 functions increased from 1,757 to 1,759 and code bytes from
228,232 to 228,536. The full module remains incomplete.

## Shared interface repair

Repair starting revision: `f72657f78860c33e707b91b77ac362a320364e30`.
Both assigned functions were already source-covered and matched exactly before
this repair. The initializer now includes `Resource/GameResources.h` and uses
its existing `GameResources*` return declaration for `func_ov017_0218b5b0`,
removing the conflicting local `void*` declaration.

One additional compiled source variant matched both functions exactly, bringing
each cumulative count to 4, including the supplied prior count of 3. Baseline
rebuilds and comparisons of unchanged source are verification, not new variants.
The repair changes no reconstructed ranges or coverage denominators.
Before/after object evidence is under ignored `build/matching/`:
`20261002T191111-ae3be4657ac340ac8f0c9d04677918a8` and
`20261002T191118-de0e267eef294e3aa129041c8ce9d487`.
Full acceptance log: `build/ov011-repair-accept.log`.
Batch measurement: `build/workflow/ov011-interface-repair/`.
