# ov011 worker handoff

Batch: `fleet_ov011_20261003_0210`, based on
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`, branch `work/fleet_ov011`.
Exclusive worktree: `C:\Users\swayn\Projects\DQIX-Decomp-fleet-ov011`.
No other modules, shared headers, shared tooling, or integrator queue were edited.

## Accepted allocator-node family

| Function | Range (end exclusive) | Observed behavior | Candidate variants |
| --- | --- | --- | --- |
| `func_ov011_021842a0` | `0x021842a0..0x021842c8` | Reset ID, allocator pointer, and links | 1 |
| `func_ov011_021842c8` | `0x021842c8..0x02184324` | Recursive ID lookup, sibling before child | 1 |
| `func_ov011_02184324` | `0x02184324..0x02184354` | Append to sibling chain | 2 |
| `func_ov011_02184354` | `0x02184354..0x02184374` | Set first child or append child sibling | 1 |
| `func_ov011_021845c8` | `0x021845c8..0x021845f4` | Reset node and create type-B allocator, alignment 4 | 1 |

Source lives in `src/Factory/ov011/AllocatorNodes.cpp`,
`AllocatorNodeCreate.cpp`, and their local `AllocatorNodes.h`.
The two complete delink ranges total 0x100 bytes. Coverage delta:
**+5 functions, +256 instruction/code bytes, +0 literals, +0 initialized
data, +0 BSS, +0 assembly**. ARM9 and ARM7 denominators remain unchanged.
ARM9 report moves from 1,651 to 1,656 matched functions and from 218,816
to 219,072 matched code bytes; matched data remains 66,724 bytes.
This is a partial family reconstruction, not module completion.

## Type and caller evidence

`dsd dis --config-path config/usa/arm9/config.yaml --asm-path build/analysis`
provided original instruction/literal disassembly. Existing `SafeAllocator`
is the actual 0x14-byte subobject at offset 4. The reconstructed node is 0x20
bytes: ID at 0, allocator at 4, sibling at 0x18, child at 0x1c; its size is
checked at compile time.

Original script handlers `0x02184de4` and `0x02184ed0` allocate 0x20-byte
records, initialize them, assign IDs, create embedded allocators, and append
sibling/child records. Allocation consumers `0x021844a4` and `0x021844f4`
search by ID and allocate through the returned allocator subobject.
The manager initializer at `0x0218438c` uses the same prefix. These callers
remain original fallback. Symbol names remain address-based because semantic
names above are reconstruction interpretations rather than recovered names.

## Experiments and verification

Three successful object comparison runs with `tools/match_unit.py --worker
fleet_ov011 --hypothesis ...`: two for AllocatorNodes, one for
AllocatorNodeCreate. The only failed function hypothesis was the early-return
empty sibling-chain branch (66.67%); placing the positive condition around
the loop reproduced the target's separate terminal empty-chain store, yielding
100% for all five functions. `#pragma dont_inline on` keeps the local calls.
The first delink draft used two `.text` ranges in one unit; dsd rejected that
configuration before candidate compilation, so initialization was split into
its own contiguous unit. No ten-variant caps were reached or inherited.

All comparison target hashes were unchanged before/after comparison.
Factory evidence and conservative diff diagnosis are under ignored `build/`:
`build/factory/ov011-nodes-final-evidence.json`,
`ov011-create-final-evidence.json`, `ov011-nodes-diff.json`, and
`build/matching/attempts.jsonl` (including preserved candidate snapshots).
Factory caller enumeration returns no overlay call rows due to its module
spelling resolution; caller observations above come directly from the original
ov011 disassembly and relocation map, not that empty enumeration.

`ninja -j2 rom check report sha1` passed (exit 0): all module checks, symbol
checks, ARM7 baseline preservation, report generation, input/output isolation,
and ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
Input ROM SHA-1 was independently read and verified. Logs:
`build/ov011-accept.log`, `build/ov011-configure-accept.log`.
No runtime smoke test was performed for this batch.

`tools/work_batch.py start/finish` records are in
`build/workflow/fleet_ov011_20261003_0210/`: measured elapsed **312.188304 s**,
three object comparisons, unchanged denominators. An early finish snapshot
taken while ROM acceptance was still running is retained separately as
`finish-preaccept.json`; authoritative `finish.json` was regenerated after
acceptance exited successfully. Token usage was not measured.

## Remaining dependencies

The larger manager layout after its allocator-node prefix, recursive teardown
at `0x02184604` (including its ov023 subobject at offset 0x118), node creation
script handlers, allocation consumers, constructor table, and program-owned
rodata/data are still required reconstruction work. Existing fallback remains
for every range outside the five accepted functions. A subsequent batch can
use this typed prefix to establish those manager and script interfaces.

## Continuation: allocator script creation and numeric arguments

Batch `fleet_ov011_20261003_cont_alloc`, based on local commit
`b057c87ce7c1a4521b9e6569ee3995f7e6c0cb88`. Prior source and evidence were
preserved. No shared headers, other modules, tooling, or queue were edited.

| Function | Range (end exclusive) | Observed behavior |
| --- | --- | --- |
| `func_ov011_02184c30` | `0x02184c30..0x02184c4c` | Float tag 1 to integer; otherwise return raw word |
| `func_ov011_02184c4c` | `0x02184c4c..0x02184c68` | Integer tag 0 to float; otherwise return raw float word |
| `func_ov011_02184de4` | `0x02184de4..0x02184ed0` | Create an ID-unique sibling allocator from a selected resource allocator |

The two complete delink ranges total **292 instruction/code bytes, three
functions**. Literals, initialized data, BSS, and assembly gains are zero.
ARM9 matched functions change 1,656 -> 1,659 and matched code
219,072 -> 219,364; matched data remains 66,724. Denominators remain
14,790 functions, 2,959,478 code bytes, and 1,602,476 data bytes.
ARM7 counters are unchanged. This is partial ov011 reconstruction.

Original ov011 disassembly and relocation maps establish eight-byte local
arguments with numeric tags 0/1, distinct from the shared Script::Parameter
encoding. The sibling handler selects actual `GameResources::allocator_array_38`
elements 0, 7, and 5 (offsets 0x38, 0xc4, and 0x9c) for selectors 0, 1, and 2.
It allocates the actual 0x20-byte node, resets it, assigns its ID, allocates
the selected allocator's largest available block, creates a type-B allocator
with alignment 4, and appends the node. Original error paths retain any prior
allocations; reconstruction does not add cleanup. The dispatch table at
0x021889a0 references the handler and remains original program-owned data.
ov017 instance getters and the ov011 identity getter remain fallback dependencies.
New argument types are local to `src/Factory/ov011/AllocatorScript.h`.

### Preserved capped child creation experiment

`func_ov011_02184ed0` (`0x02184ed0..0x02184fb0`) remains required work and
original fallback. **Its accumulated cap is 10 attempts: nine compiled
variants plus one duplicate-declaration compilation failure. Do not reset
this count in the next batch.** Closest result is 64.28571%; call sequence,
branch structure, offsets, and allocation behavior match, but saved registers
and register operands differ. Target retains node in r7, size in r4, argument
count in r8, and arguments in r9; candidate shares the dead root's r4 with
the node, then uses r5 for size and r7/r8 for count/arguments. Nested positive
checks degraded control-flow matching to 50%; register qualifiers, signed size,
declaration positions, integer reuse, and bounded root scope did not fix it.
The sibling handler first matched on the seventh attempt (sixth compiled
variant), after placing the allocator declaration after the root declaration.

Draft: `build/factory/AllocatorScript-child-capped.cpp`. Full source snapshots,
compiler failure, and hypotheses remain in `build/matching/attempts.jsonl` and
its attempt directories. Diagnosis: `build/factory/ov011-script-capped-diff.json`;
last combined comparison: `20261002T155729-c784b6cd0a6f41d58ef61d6dae5a2fea`.
Next investigation should establish the original source/compiler context of
the child handler or recover a different manager dependency; further declaration
shuffling without new evidence is not authorized by the cap policy.

### Validation and measurement

Twelve match-unit invocations: eleven completed comparisons and one compilation
failure. Numeric conversion helpers matched on their first candidate; the
isolated sibling object also matched. Target object hashes remained unchanged
within every comparison. Final evidence packages:
`build/factory/ov011-script-final-evidence.json` and
`build/factory/ov011-script-numbers-final-evidence.json`.

`ninja -j2 rom check report sha1` passed, exit 0: full modules, symbols, ARM7
preservation, report, input/output isolation, and USA ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Independent input SHA-1 also matches.
Logs: `build/ov011-cont-accept.log` and `build/ov011-cont-configure-accept.log`.
Every configure used the assigned worktree's explicit read-only compiler path.
No runtime tests were performed. `git diff --check` passed.

Start/finish snapshots are in `build/workflow/fleet_ov011_20261003_cont_alloc/`.
Measured reconstruction/acceptance elapsed: **573.696488 seconds**; finish
records the verified source before its commit. Token usage was not measured.
Remaining work includes capped child creation, manager layout and lifecycle,
recursive teardown/ov023 subobject, allocation consumers, other script handlers,
and program-owned data. No integration or merge occurred.
