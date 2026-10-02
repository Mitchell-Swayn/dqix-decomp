# ov004 count-cache reconstruction

Batch: `fleet_ov004_20261003_0150`; baseline `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
No pre-existing ov004 source ranges or attempt caps were found. Queue untouched.

## Accepted family

| Range (end exclusive) | Reconstruction | Functions |
| --- | --- | ---: |
| `021537e0–02153944` | Secondary-key sum, primary-key sums and lookup | 4 |
| `021545f0–02154618` | Indexed record setter | 1 |
| `021546c0–02154718` | Paired-key count lookup | 1 |
| `021707c0–021707c4` | Cache pointer, zero-initialized BSS | 0 |

Source under `src/Factory/ov004/` uses an actual twenty-element array of
six-byte records. Allocation/initialization at `02154350` establishes the full
126-byte cache: two signed keys, two unsigned count bytes per record, two signed
aggregate counts at offsets `78/7a`, and state at `7c` (hexadecimal offsets).
The allocation, initialization and consuming menu handlers remain original
fallback. The cache's gameplay category names are unresolved; field names describe
observed count roles. No initialized-data dependency was concealed or replaced.
Lookup leaves outputs unchanged on a missing pair. Its callers include
`02154618` and `02154748`; sums are consumed by `02154b7c` and `02154c78`.

## Matching and verification

- Nine distinct source/compiler variants: six summation-family variants, one
  setter variant, two paired-lookup variants. Reverification runs are separate.
  Primary lookup became exact in family variant five; all four family functions
  became exact in variant six. No function reached the ten-variant cap.
- Findings: explicit promoted key locals preserve compare operand order;
  `always_inline` embeds the secondary search under `-inline noauto`; expressing
  the global cache argument inside the loop reproduces load hoisting/register
  allocation; short-circuiting the secondary key reproduces its conditional load.
- dsd rejected multiple disjoint `.text` ranges in a single delink block. The
  setter and paired lookup therefore use separate contiguous source objects with
  one local layout header. This failed map hypothesis is archived in
  `build/factory/ov004-config-2.log`; stale-target comparisons were not accepted.
- Final object comparisons: `5/5`, `1/1`, `1/1` symbols exact. Final attempt
  directories have prefixes `20261002T155102` under `build/matching/`.
  Candidate snapshots, failed hypotheses and conservative mismatch diagnoses
  remain there; final read-only evidence bundles are
  `build/factory/ov004-*-final-evidence.json`. Original disassembly is
  `build/factory/ov004-dis/ov004_5.s`.
- `ninja -j2 rom check report sha1` passed, including all ARM9 modules, symbols,
  ARM7 preservation and exact ROM SHA-1
  `c7c3014c237900c8281289b8bc76a781969b6278`.
  Log: `build/factory/ov004-acceptance.log`. Original input SHA-1 was also
  independently rechecked. No gameplay tests were performed in this batch.

Delta: **+6 functions, +484 reported code bytes, +4 reported data bytes**.
Physical split: **472 instruction bytes, 12 literal-pool bytes, 0 initialized
data bytes, 4 BSS bytes, 0 assembly bytes**. No alignment storage gain claimed.
Report totals remain 14,790 functions / 2,959,478 code bytes / 1,602,476 data bytes.
ARM7 unchanged. Full module completion is not claimed.

Elapsed wall time and report deltas are recorded by `tools/work_batch.py` in
`build/workflow/fleet_ov004_20261003_0150/{start,finish}.json`. Token use unmeasured.
All remaining functions, cache lifecycle, category semantics and other module
data/BSS remain required work; no deferred function was waived.

## Continuation: count-menu selection and display

Batch: `fleet_ov004_20261003_cont02`; baseline
`3971e0c2050681a4ba7c188ae4c192c005faa740`. Previous source and attempt evidence
were preserved; no capped function was retried. Integrator queue untouched.

| Range (end exclusive) | Reconstruction | New functions |
| --- | --- | ---: |
| `02153944–02153b6c` | Type-6 entry lookup and selection-ID decoder | 2 |
| `02154618–021546c0` | Secondary-key count display population | 1 |
| `02154718–0215482c` | Primary-key display population and both refresh callbacks | 3 |

The decoder initializes all three signed outputs to -1, then reads selected
entries through ov023. Top-level selection IDs 26–29 select the observed paths.
The secondary selection maps IDs 26–31 to even keys and 32–37 to odd keys;
the primary selection maps IDs 26–31 to keys 1–6. Missing entries and unknown
IDs preserve the sentinels, except for fields already written by the chosen
top-level path. Category/gameplay names remain unresolved.

The two population handlers display cached total counts and set label IDs.
Secondary label arithmetic explicitly promotes the key as unsigned before adding
25, while the cache lookup uses signed keys. Primary labels preserve both
16-bit truncations around subtracting 1 and adding 37. The refresh callbacks
populate the display and refresh entry 55 only when its type is 6. The original
callback table at `0216fa8c` contains pointers to all four handlers and remains
fallback data; no initialized-data gain is claimed.

`CountMenu.h` is module-local. Its external UI objects remain opaque because these
functions access them only through observed ov011/ov023 interfaces. The existing
actual twenty-record `CountCache` array is reused. No shared header was changed.
The allocated cache, missing-pair behavior, and original external interfaces are
preserved; no substitute arrays, binary code or assembly were introduced.

Matching used six candidate-unit variants: secondary population 2, primary
population/callbacks 1, selection/entry lookup 3. No function reached ten
unproductive variants. The first secondary variant differed only in a signed
load. Selection variants using nested `return` cases emitted branches to the
outer return block (82.40%); explicit default returns did not change that result.
Using case `break` statements matched the original immediate return epilogues
and branch tables. These tables contain 22 executable ARM branch instructions,
not embedded initialized-data substitutes. Final read-only rechecks are separate
from variant counts.

Candidate snapshots, diffs and diagnoses are under `build/matching/` with
`20261002T155434`, `155451`, `155603`, `155627` and `155643` prefixes; final
rechecks have prefix `20261002T155804`. `factory_evidence.py` bundles are
`build/factory/ov004-cont02-*-final-evidence.json`; the first failed selection
and secondary diagnoses are saved beside them. Original disassembly and caller
analysis use the preserved dsd output in `build/factory/ov004-dis/`, including
ov004, ov011 and ov023. Comparison inputs were unchanged.

All six new functions matched in final object comparisons (2/2, 1/1, 3/3).
`ninja -j2 rom check report sha1` passed, including all ARM9 modules, symbols,
ARM7 preservation, and ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
Log: `build/factory/ov004-cont02-acceptance.log`. The independent original input
SHA-1 was rechecked separately. No runtime/gameplay tests were performed.

Delta: **+6 functions, +996 reported code bytes, +0 reported data bytes**.
Physical split: **988 instruction bytes (including the executable branch tables),
8 literal-pool bytes, 0 initialized-data bytes, 0 BSS bytes, 0 assembly bytes**.
No alignment gain. Coverage denominators unchanged; ARM7 unchanged.
Elapsed wall time and accepted worker-local report deltas are recorded by
`tools/work_batch.py` in `build/workflow/fleet_ov004_20261003_cont02/`.
Token usage unmeasured. No main integration or module-completion claim.

Remaining required dependencies include cache allocation/lifecycle (`02154350`),
live count computation (`02153b6c`), external UI implementation/types, gameplay
category semantics, and the original callback table and other ov004 data/BSS.
These were not attempted in this continuation and retain their original fallback.
