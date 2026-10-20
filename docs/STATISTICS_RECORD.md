# Statistics record

`GameState_CopyStatisticsRecord` copies the `0xB0`-byte statistics snapshot from
`GameState + 0x7540`; `GameState_StoreStatisticsRecord` writes the same range.
The compact subrecord starts at snapshot offset `0x68`. Battle defeat, party-wipe
and alchemy callers pass that address to `Statistics_AddCompact*` routines.

The script getters copy the snapshot, extract a field and write a script integer
reference. Their field identities match the saturating update routines below.
Names such as qualified party outcome, tracked action and quest-menu success
retain the established writer's operational category; a more specific event
identity is not proven by the layout alone.

| Snapshot offset | Bits | Counter | Update routine |
|---|---|---|---|
| `0x20` | 0–15 | Quest-menu success | `Statistics_AddQuestMenuSuccessCount` |
| `0x20` | 16–31 | Party talk | `Statistics_AddPartyTalkCount` |
| `0x28` | 22–31 | Vocation changes | `Statistics_AddVocationChangeCount` |
| `0x2C` | 0–23 | Steal attempts | `Statistics_AddStealAttemptCount` |
| `0x74` | 16–31 | Compact qualified party outcomes | `GameStats_AddQualifiedPartyOutcomeCount` at compact `+0x0C` |
| `0x7C` | 20–31 | Compact tracked actions | `Statistics_AddCompactTrackedActionCount` at compact `+0x14` |
| `0x80` | 0–15 | Compact party wipes | `Statistics_AddCompactPartyWipeCount` at compact `+0x18` |
| `0x80` | 16–31 | Compact alchemy | `Statistics_AddCompactAlchemyCount` at compact `+0x18` |
| `0x88` | 0–23 | Compact monster defeats | `Statistics_AddCompactMonsterDefeatCount` at compact `+0x20` |
| `0x8C` | 0–23 | Compact experience earned | `Statistics_AddCompactExperienceEarned` at compact `+0x24` |

`FieldBattle_AdvanceLifecycleAndParticipantWait` increments the compact party-wipe
counter after detecting an inactive party. The ov006 alchemy completion routine
increments the compact alchemy counter after updating the alchemy operation count.
`Combat_SubtractHealthAndRecordProtagonistDefeat` updates both main and compact
protagonist-defeat counters, independently confirming the compact base.

The getters at snapshot `0x98` and `0x9C` read low 17-bit fields; `0xA4` reads a
low byte, and `0xAC` reads a complete word. Their meanings remain unresolved and
retain offset-qualified names. Main and compact counters have different widths
and saturation limits; they are not interchangeable.

Statistics update helpers live under `src/GameState/`; ov023 script-facing getters
live under `src/Script/ov023/`. Naming and source placement preserve the original
instructions, signatures and counter arithmetic.
