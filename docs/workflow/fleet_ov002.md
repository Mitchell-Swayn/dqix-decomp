# ov002 worker evidence

Batch `fleet_ov002_20261002t1544`, based on
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`.

Reconstructed the inventory-menu party-list family in
`src/Factory/ov002/InventoryPartyLists.cpp`. The exclusive end of the accepted
range is `0x02157500`; every function in that range matches.

| Function | Range | Instruction bytes |
| --- | --- | ---: |
| `func_ov002_021573f8` | `0x021573f8–0x02157424` | 44 |
| `func_ov002_02157424` | `0x02157424–0x02157480` | 92 |
| `func_ov002_02157480` | `0x02157480–0x021574d4` | 84 |
| `func_ov002_021574d4` | `0x021574d4–0x02157500` | 44 |

The two list builders initialize unused output slots to -1 and copy menu-owned
lists. The owner-list builder first emits sentinel 4. The indexed readers retain
the original negative-index return and caller-dependent upper bounds.

Original disassembly generated with `dsd dis` establishes the actual menu fields:
count at `+0x1c50`, five integer owners at `+0x1c54`, five signed-byte party
indices at `+0x1c6e`, and signed-byte count at `+0x1c73`. The initializer
`func_ov002_0215505c` clears five owner entries, copies indices returned by
`func_02011494`, then appends 4. Its second list excludes party members whose
`+0x1c4` field is nonzero. That field's semantic meaning remains unresolved.
The partial state type records real array extents and verifies accessed offsets;
its opaque prefix does not claim reconstruction of the rest of the menu.

Explicit ov002 call relocations establish the connected family: the readers
call their builders at `0x02157410` and `0x021574ec`; further builder callers
occur at `0x0215dbc0`, `0x02160290`, `0x021604cc`, and `0x02160600`.
Reader callers include `0x02162ca4`, `0x0216453c`, and `0x02168338`.
`factory_evidence.py` packaged the maps and objects, but its automated caller
records are empty because its module keys do not resolve the map's `overlay(2)`
spelling. These caller observations were checked directly in the relocation map
and original disassembly; no tooling was changed.

Validation: first candidate failed to compile because pinned MWCC has no
`stddef.h`; replacing it with existing project definitions yielded 4/4 exact
symbols on the first compiled variant. Two candidate build attempts total,
one per-function compiled variant, plus one no-build confirmation after enabling
the complete range. No previous variant-cap records were found for this family.
`factory_diff.py` reports zero mismatched symbols. Full
`ninja -j2 rom check report sha1` passed all configured module and symbol checks,
ARM7 preservation checks, and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Original input SHA-1 was also rechecked.
No runtime test was performed.

Measured by `work_batch.py`: 300.78923 seconds; +4 matched functions, +264
matched code bytes, +0 data bytes, unchanged denominators. Literal, initialized
data, BSS, and assembly gains are all zero; ARM7 deltas are zero. The range has
only two internal call relocations and no external program-data dependencies.
Token usage is unknown. No main queue or shared header changes.

Logs, candidate snapshots, and verbose evidence remain under ignored `build/`:
`fleet_ov002_dis/ov002_4.s`, `fleet_ov002_acceptance.log`,
`fleet_ov002_party_evidence_final.json`, `fleet_ov002_party_diff_diagnosis.json`,
`matching/20261002T154549-d6981ded69734e2d9a0284268659b734/`,
`matching/20261002T154622-0b8198cc7a0f499a87a3ef1efde66f1d/`,
`matching/20261002T154732-0da3fb714f924538a4290e7b8669eeb4/`, and
`workflow/fleet_ov002_20261002t1544/`.

Remaining required work includes the menu initializer, inventory lookup/count
functions at `0x0215707c` and `0x02157108`, and their storage interfaces. They
remain original fallback and were not attempted in this batch. ov002 is not
complete. The partial menu layout is local to this unit; broader reconstruction
should reconcile it with a shared menu type once more fields are established.

## Continuation: inventory queries

Batch `fleet_ov002_20261003t_cont01`, based on
`27a6ea1a60283b68527ee394d1b3bba21398a396`. Existing work and attempt evidence
were inspected first; no ownership conflict or prior lookup variants were found.

| Function | Accepted range (exclusive end) | Instruction bytes |
| --- | --- | ---: |
| `func_ov002_02157108` | `0x02157108..0x02157174` | 108 |
| `func_ov002_02157500` | `0x02157500..0x0215753c` | 60 |

The count query uses owner 4 for the bag, owner 5 for a second shared list,
and otherwise looks up a member using the supplied owner index. Missing members
produce zero. The attribute query reads an item through the original lookup,
searches the menu-owned serialized item table, and returns bits 14..15 of the
word at record offset 8, or zero for a negative item or missing record.
Its caller at `0x021634a8` distinguishes zero and two; the field's gameplay
meaning and the second shared list's name remain unresolved.

Original `dsd dis` output establishes real storage: `func_0208660c` initializes
the bag's 152 signed-short items at +0xc, 152 signed-byte quantities at +0x13c,
and binds its 12-byte descriptor with `func_020a093c`. The second descriptor
starts at +0xe04, with 94 items at +0xe10 and 94 quantities at +0xecc.
The intervening storage remains explicitly opaque, not reconstructed data.
`func_02083960` scans exactly eight signed item slots at member-state +0x454;
`func_02053c6c` returns that state from the game object's +0x150 pointer.
`func_02010828` returns GameState +0x2a04, overlapping the existing main
header's opaque `GameStateIndexList` prefix. This local, typed storage view
must be reconciled with that main-owned layout in later work.

The item table at menu +0x7ec is a real `ZoneState2754` subobject: the loader
at `0x02156c7c` resets it and calls `BuildAlternateForKeys` on it.
`func_020dedd0` advances by 32-byte serialized records and compares the key
at +0x18. The local item record view preserves that size and key offset.
`InventoryMenuState.h` now shares the same menu layout across the three local
units and retains the established five-entry party arrays. No shared include
header, other module, integrator queue, or tooling was edited.

Deferred lookup `GetInventoryItemByID`, `0x0215707c..0x02157108`, remains
original fallback. Preserve its cumulative **seven unsuccessful comparisons**
across six distinct source variants; next comparison is number eight, with
three attempts remaining before the ten-attempt switch threshold. Best result
is 88.57143%: only the secondary-list address calculation differs, using
index/add +0xe00/load +0x10 instead of add +0x204/add +0xc00/index/load +0xc.
Tested flat arrays, nested arrays, inline slot access, a common descriptor
join, separate descriptor returns, and void-pointer subobject conversion.
The joined version reached 74.28571%; the others reached 88.57143%.
An accidental seventh comparison repeated variant six against the stale target
after dsd rejected duplicate `.text` sections. It receives no new hypothesis
credit and still counts toward the conservative cap. Disjoint accepted ranges
were then assigned separate source files. Next work should investigate the
original subobject/accessor contract rather than merely permuting expressions.
All candidates and failed comparisons remain in ignored `build/matching/`,
plus the standalone `build/fleet_ov002_lookup_v6.cpp` draft.

Count matched on its first compiled variant and remained exact throughout.
Attribute query required two variants: the first misread hexadecimal shift
`0x10` as the wrong bit position; correcting the field to bits 14..15 matched.
Eleven candidate comparison calls total, including the stale-target replay
and the four-function party-list regression check. Both accepted units and all
four prior functions match exactly; `factory_diff.py` diagnoses zero mismatches.
No runtime testing or measured token usage.

Full `ninja -j2 rom check report sha1` passed module/symbol checks, ARM7
preservation, and ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
Original input SHA-1 was independently rechecked. `work_batch.py` recorded
545.805298 seconds, +2 matched functions, +168 instruction/code bytes, +0
matched data, unchanged denominators. Literal, initialized data, BSS, assembly,
and all ARM7 deltas are zero. Coverage is local worker evidence, not integration.

Verbose evidence: `build/fleet_ov002_cont_acceptance.log`,
`build/fleet_ov002_count_evidence_final.json`,
`build/fleet_ov002_attributes_evidence.json`,
`build/fleet_ov002_count_diff_final.json`,
`build/fleet_ov002_attributes_diff_final.json`, and
`build/workflow/fleet_ov002_20261003t_cont01/`.
The initializer, lookup, storage implementation/data, and remaining menu
interfaces remain required fallback work; ov002 is not complete.
