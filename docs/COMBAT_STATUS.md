# Combat status record

A combatant's battle status lives in its `currentStats_` record (`ModifiableCombatStats`,
at `GameObject + 0x138`). The `CombatStatus_*`, `Combat_*` status and `BattleAI_*` target
filter functions in `src/GameState/`, `src/Combat/ov000/` and `src/Combat/ov024/` read and
write the fields below.

Identities come from the battle message text (`data/prm/actmsg.gp2`, `actmsg_en.nat`)
that each handler emits, and from the action-to-handler links in `data/prm/actdt_b.gp2`
(`actdt_b_en.nat`). Damage recovery and turn-based recovery confirm the timed statuses.

## Active-flag words

| Field | Meaning |
|---|---|
| `0x14` bit 1 with `0x22` bits 0-1 | Poison (1) or Envenom (2) |
| `0x14` bits 20, 21 | Schizofanic, Mist Me (consumed on use) |
| `0x18` bit 5 | Pincushion pending |
| `0x2A`, `0x2C` | Whipping Boy cover target and protector links (reciprocal) |

Each timed status also has an activation bit in these words. A status clears its bit
when its stage returns to neutral or its duration expires.

## Stat stages (`0x58`)

Signed three-bit stages, clamped to two steps in either direction.

| Bits | Stage | Timer |
|---|---|---|
| 0-2 | Attack | |
| 3-5 | Defence | |
| 6-8 | Agility | |
| 9-11 | Charm | |
| 12-14 | Magical Might | |
| 15-17 | Magical Mending | |
| 18-20 | Spell resistance | `0x74` |
| 21-23 | Breath resistance | `0x75` |
| 24-26 | Shield-block chance | `0x76` |
| 27-29 | Evasion | `0x77` |

## Timed statuses

Each status has a duration byte and a recovery byte, 0x23 bytes apart.

| Duration | Status |
|---|---|
| `0x5C` | Paralysis |
| `0x5D` | Sleep (also cleared by damage) |
| `0x5E` | Confusion (Fuddle; also cleared by damage) |
| `0x5F` | Dazzle, including sand, ink and flash variants |
| `0x60` | Fizzle |
| `0x61` | Bounce (Magic Mirror) |
| `0x62` | Vanish |
| `0x63` | Feel the Burn |
| `0x64` | Rotstopper |
| `0x66` | Reverse Cycle |
| `0x67` | Alma Mater |
| `0x68` | Focus Pocus |
| `0x69` | Right as Rain |
| `0x6B` | Holy Impregnable |
| `0x6C` | Fire barrier (flame shield) |
| `0x6D` | Ice barrier (ice shield) |
| `0x78` | 0 Zone |
| `0x79` | Rough 'n' Tumble |
| `0x7A` | Soul Asylum |
| `0x7B` | Eerie Light |
| `0x7C` | Knight Watch |
| `0x7D` | Twocus Pocus |

## Enemy AI susceptibility

| Field | Meaning |
|---|---|
| `0x47` | Sleep susceptibility |
| `0x4D` | Poison susceptibility |

Offsets `0x65` and `0x6A` are not yet identified.
