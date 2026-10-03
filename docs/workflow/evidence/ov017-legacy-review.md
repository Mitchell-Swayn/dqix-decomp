# ov017 legacy repair provenance

Repair packet: `legacy-DQIX-Decomp-luna-runtime`.
External source history: base `03358014be54535df2a389ed2d28ba83d552465b`, commits
`1966e512bcfa2ab5747c21ffd1d63273e0bd4685`,
`88e7c352dd133c259cb63c38739d9b2a374165fe`,
`67d42c3abb9b65e55d36a82d0f23df416a9ef589`,
`7ddf3f82da305e30999eb0f962b680d51201ee12` (source tip).
The preserved local chain is `91f370f`, `c2a5afa`, `63f2dfc`, `b79fb4c`,
after `39e7ba58c9ac2561461874001573cf49d532f9cf`.
This repair appends to starting HEAD `b79fb4c95b082682bb564435a7cc4757d876f32d`.

Use AllocatorUnion for data_02114e20 and the allocator argument of func_02012da4,
consistent with existing allocator users and the reviewed main_33.o relocation.
Both repaired candidate objects compare at 100%: lifecycle 2/2, payload 4/4.
No unproductive source variants were incurred; supplied prior_attempts is empty.

Remove unauthorized GameStateIdentityUpdate.cpp (main 0x02011b68?0x02011fb4)
and PeerIdentityPresentationStorage.cpp (ov008 0x02189228?0x0218936c), including
source registrations. These ranges remain required reconstruction work in their
own assignments. No new source credit is claimed for their original bytes.
Existing historical batch JSON files describe the earlier submission and are
preserved as historical evidence, not acceptance of those ranges in this repair.
Shared types remain necessary for the retained ov017 packet and manager sources.

Verbose verification and measurement artifacts are under ignored build/:
legacy-review-baseline.log, legacy-review-objects.log,
legacy-review-acceptance.log, matching/, workflow/ov017-legacy-review/.
The initial stale generated graph was regenerated without changing the harness.

Full `ninja rom check report sha1` passed before and after repair, including
module/symbol checks, ARM7 checks, and SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`.
ARM9 coverage correction: -3 functions,
-1424 code bytes, 0 data bytes.
All denominators unchanged; ARM7 measures unchanged.
Measured repair interval: 99.212 seconds. Token usage unknown.
work_batch.py finish rejects the intentional coverage decrease; its strict guard
was preserved. Raw capture/deltas are in repair-delta.json alongside start.json.
