# ov024 worker evidence

## Batch fleet_ov024_20261002t161000

Measured interval: 2026-10-02 15:43:39 to 15:54:52 UTC; 673.28545 seconds
(11m 13s), including analysis and verification. Baseline revision:
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. No prior local ov024 variant
evidence or source ownership was found. Queue and other modules were not edited.

Six damage-adjustment callbacks are reconstructed in two complete source units:

| Unit | Half-open range | Functions | Instructions | Literals |
| --- | --- | ---: | ---: | ---: |
| DamageAdjustments.cpp | 0x021d8a40–0x021d8ad8 | 3 | 148 bytes | 4 bytes |
| StatDamageAdjustments.cpp | 0x021d8b68–0x021d8c10 | 3 | 152 bytes | 16 bytes |

Report delta: **+6 functions, +320 code bytes**, including the 20 literal bytes.
Initialized data, BSS and necessary assembly deltas are zero. ARM9 denominators
remain 14,790 functions, 2,959,478 code bytes and 1,602,476 data bytes. ARM7 is
unchanged. These results do not constitute module completion or integration.

Original `dsd dis` output and dispatcher 0x021da55c establish a native
member-function table at 0x021ff1e0, a context pointer, actor/target indices,
unsigned-short action ID, action-record pointer and sixth-argument incoming
damage. The retained callbacks check the target category/flag, add or scale
damage, or use the actor's base attack with an RNG multiplier of 0.85–0.95.
Existing GameObject/BaseCombatStats layouts provide the actual stat subobjects.
The local context header describes only the observed prefix; no context objects
or action records are instantiated. Neutral address names preserve unknown
skill identities and existing relocations.

### Verification and local evidence

- Both final objects: 3/3 symbols at 100% using `match_unit.py --worker fleet_ov024`.
- Full `.venv/Scripts/ninja.exe -j2 rom check report sha1`: PASS, including all
  module/symbol checks and SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`.
- Original input SHA-1 independently checked against the same target.
- No runtime tests were performed. Tokens were not measured.
- Logs, original disassembly, factory evidence and diagnosis are under
  ignored `build/factory/ov024_*`; source snapshots/diffs are under
  `build/matching/`; batch start/finish records are under
  `build/workflow/fleet_ov024_20261002t161000/`.

### Deferred required function and dependencies

`func_ov024_021d8ad8` (0x021d8ad8–0x021d8b68, 144 instruction bytes) remains
original fallback, with **zero accepted coverage**. It looks up both combatants,
uses 0.75 times current attack and current defense with CalculatePhysicalDamage,
and returns the incoming damage if either combatant is absent.

Ten source variants reached the cap: explicit integer temporaries (50%),
unsigned-short snapshots (50%), direct arguments (50%), float locals (39.47%),
full PrimaryCombatStats snapshots (44.68%), reused unsigned temporaries (69.44%),
reused signed results with unsigned conversions (75%), direct loads with the
same reuse (75%), incoming-parameter reuse (44.44%), and a local stat-pointer
array (75%). Best snapshots include
`build/matching/20261002T155011-d48b15d7095a4681a2d4254a7406e838/candidate.cpp`
and `build/matching/20261002T155142-5d654dd5823b4b25928e5c36abe72516/candidate.cpp`.
The remaining differences are stat-pointer register assignment, sinking the
context RNG load, and the adjusted-attack register. Do not retry these variants
without new evidence. Next investigate the original callback class/context and
compiler expression evaluation in its callers. CombatCalculations.h still has
an obsolete int* declaration while BasicAttackCalculation.cpp implements Random*;
no shared header was changed for the deferred candidate.

There were 13 object-comparison invocations: ten physical-callback variants,
one comparison against stale targets after a failed duplicate-section map
regeneration, and the two final exact units. dsd rejected two disjoint .text
ranges in one unit; splitting source units resolved that configuration issue.
The four original exact callbacks used one source hypothesis each; the two
adjacent scaling callbacks also used one hypothesis each.

The callback table, full context/action layouts, category predicate
`func_ov000_02156068`, and all other unreconstructed ov024 code/data remain
explicit fallback dependencies. No instruction, literal, data, BSS or alignment
denominator was changed.
