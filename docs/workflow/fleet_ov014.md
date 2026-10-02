# ov014 encounter-habitat lookup batch

Batch: `fleet_ov014_20261002t155000`, started 2026-10-02 15:43:39 UTC.
Worker: `fleet_ov014`; exclusive worktree/module ov014. Queue untouched.
No prior ov014 variant caps or source ownership were found in this worktree.

## Accepted source

| End-exclusive range | Functions | Purpose |
| --- | ---: | --- |
| `02188b18–02188b20` | 1 | Monster-ID callback |
| `021891f0–0218934c` | 3 | Iterate records, bind loaded header/payload, callback binary search |
| `02189380–02189468` | 6 | Zone/string arrays, monster lookup, habitat entry and string-slot access |

New files are under `src/Factory/ov014/`; the local header travels with the source.
Three units are necessary because dsd accepts only one `.text` range per unit.
Only these exact ranges are marked complete. No module-completion claim.

Worker report delta: **+10 functions, +588 reported code bytes, +0 initialized
data bytes, +0 BSS bytes**. The selected ranges contain **584 instruction bytes
and 4 literal bytes** (the callback pointer at `021893e0`); no alignment gain or
assembly was introduced. ARM9 denominators remain 2,959,478 code bytes,
1,602,476 data bytes and 14,790 functions. ARM7 coverage is unchanged.
These are worker gains pending integrator acceptance, not main coverage.

## Layout evidence and limits

Original `dsd dis` output: `build/factory/fleet_ov014/dis/ov014_5.s`.
`02188c34` loads `enchab_<LG>.nat` from `data/prm/enchab.gp2`, through
the two original path pointers at `021897c4`. `02188d48` allocates/copies the
header and packed payload, traverses zone IDs and checks Zone3D record flags.
`021865a4`, `021865b8` and `0218664c` consume habitat entries and string slots
for menu display. These observations support the encounter-habitat names;
original function names remain address-based.

The file header is 12 bytes: four unsigned 16-bit counts, a 31-bit string-byte
count and a relocation flag. Runtime state adds two pointers, totalling 20 bytes.
Monster records are four bytes: ID plus 12-bit entry offset/4-bit count.
Habitat entries are four bytes: string index, visited flag, 11-bit zone offset
and 4-bit zone count. Actual monster/entry arrays, 16-bit zone IDs and aligned
32-bit string slots are represented by these types; loaded contents remain assets.
Compile-time size assertions and exact object comparisons check the layouts.
String slots may contain offsets or relocated pointers depending on loader state.

The iterator and binary search matched on the second compiled source hypothesis:
declaration order controls saved-register choices (record/count and low/high).
Binding and the six accessors matched on their first successful source hypothesis.
The key callback matched on its first isolated comparison. Header composition
was subsequently verified without changing generated instructions.

## Required deferred dependency

`func_ov014_0218934c`, `0218934c–02189380`, remains **original fallback** after
ten source variants (nine comparisons, one MWCC internal compiler error).
Do not retry without new evidence. The best hypothesis is 76.92%: its 13
instructions have the correct operations and order, with three register-operand
differences around string-count loading and aligned-tail addition. Target uses
`r2` for string count and `r0` for the tail; candidate uses `r0` and `r1`.

Tested count temporaries, operand order, combined versus separate tail
expressions, declaration order, signed offsets and real file-array pointer
differences. Combined arithmetic cancels the target's subtract/add pair;
one pointer expression triggers MWCC `CodeGenExprs.c:630` ICE. A separated
pointer version compiles but is worse. Next investigation: original inlined
layout-helper structure or compiler expression typing, with fresh dependency
evidence rather than another equivalent arithmetic permutation.

Closest source: `build/factory/fleet_ov014/EncounterHabitat-size-best.cpp`.
Closest attempt: `build/matching/20261002T154801-d93ed2a1617d47e4bad00deeafb315eb/`.
Diagnosis: `build/factory/fleet_ov014/size_diagnosis.json`.
Every candidate snapshot/hypothesis survives in `build/matching/attempts.jsonl`.
The 15:50:46 comparison used stale targets after a rejected repeated-section map;
it is diagnostic only and supplies no acceptance evidence. The map was split
into three valid units and fresh originals were generated before acceptance.

Other unresolved dependencies: original loader/state machine `02188bd0–021891f0`,
string relocation `02188b20–02188bd0`, path table/string definitions at
`021897c4–02189800`, menu consumers and runtime flag interfaces. They remain
required work. No original comparison input, ROM link or denominator was changed.

## Verification and measurement

Final object results: key **1/1**, lookup **3/3**, accessors **6/6**, all 100%.
Final candidates: `20261002T155350-18ed16b1d3694c1884d5e5453ceff3fd`,
`20261002T155323-fd6db805b6d44bb6bdbdf47f24c58ee0`, and
`20261002T155323-c1315d1c5317415ab0428e472ef974cd` under `build/matching/`.
`factory_evidence.py` packages the local source, original symbols/relocations,
callers and attempts in `build/factory/fleet_ov014/*_evidence_final.json`.

`ninja -j2 rom check report sha1` passed twice, including the final header layout:
all ARM9 modules and symbols, ARM7 baseline preservation, and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Logs:
`build/fleet_ov014_accept.log`, `build/fleet_ov014_accept_final.log`.
No new gameplay smoke test was performed.

There are 18 recorded object-tool attempts: 15 successful comparisons, two
compiler failures (missing standard header and the size-helper ICE), and one
stale-target diagnostic comparison after map rejection. Two early unknown-unit
name errors created no attempt records. Ten variants apply to the deferred size
function; unrelated range splitting and final verification do not reset its cap.
Start/finish snapshots and measured elapsed time are in
`build/workflow/fleet_ov014_20261002t155000/`. Token usage is unmeasured.
