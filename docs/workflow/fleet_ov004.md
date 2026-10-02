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
