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
