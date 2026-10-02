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
