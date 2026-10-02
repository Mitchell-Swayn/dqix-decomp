# ov012 pattern-search helpers

Batch: `fleet_ov012_20261003_0150`; worker `fleet_ov012`. Baseline revision:
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. No prior ov012 source units or
variant caps were present. Integrator queue and other modules were untouched.

| Range (end exclusive) | Reconstructed behavior | Variants |
| --- | --- | --- |
| `021845f8..02184654` | Reset pattern resource and resolve 15 delimiters | 2 |
| `021855f0..02185634` | Copy ASCII uppercase bytes into a precleared buffer | 2 |
| `02185634..02185684` | Find a matching byte window across candidate positions | 2 |
| `021859f4..02185a24` | Test byte-set membership for the pattern interpreter | 2 |
| `0218afbc..0218b008` | Fifteen five-byte delimiter strings and one alignment byte | 2 |

Original instructions were obtained using `dsd dis` with the unchanged USA
maps. The `02184d80` parser calls the uppercase and byte-window helpers, and
`02185684` calls the byte-set helper. Initialization callers pass the embedded
state at owner offset `0x1480`. Its resource occupies offsets `0x18..0x23`,
selected pointer/offset occupy `0x24/0x28`, and delimiter codes start at `0x2a`.
The first 24 state bytes and resource record element types remain unrecovered.

`func_020424e4` scans character records using encoding index 1 and compares
their bytes through `func_02001aec`. The latter is already reconstructed in
`src/System/RuntimeMemory.cpp`. The uppercase caller clears a 12-byte stack
buffer before invoking the helper; the helper deliberately omits a terminator.
No new shared headers, instructions in assembly, or binary substitutes were used.

First candidates matched initialization instructions, but omitted table
alignment and differed in loop-increment order and signed-character assignment.
Second candidates matched all four functions and the complete table at 100%.
There were six unit comparisons / eight function candidate compilations,
with two variants per function; no function approached the ten-variant cap.

Evidence and verbose logs remain in ignored `build/`: original disassembly
`factory/fleet_ov012_dis/`, factory evidence `factory/fleet_ov012_*evidence*.json`,
candidate snapshots/diffs `matching/20261002T154621-*` and
`matching/20261002T154721-*`, and full acceptance log
`factory/fleet_ov012_accept.log` and `factory/fleet_ov012_accept_final.log`.
`factory_diff.py` diagnosed increment ordering
and signed-character reload differences. Original comparison inputs were not
modified; delimiter storage uses an actual two-dimensional array.

Acceptance: `ninja -j2 rom check report sha1` passed, including all ARM9 module
and symbol checks, ARM7 preservation, ROM input/output isolation, and exact USA
SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. The verified original input
was independently rehashed to that SHA-1. `git diff --check` passed.

Measured `work_batch.py` interval: **478.216782 seconds** (7m 58s), including
analysis, candidate compilation and acceptance. Matched coverage increased by
**4 functions, 288 code bytes and 76 data bytes**; denominators did not change.
Code separates into **284 instruction bytes and 4 literal-pool bytes**. Data
separates into **75 delimiter bytes and 1 alignment byte**. Initialized writable
data, BSS, necessary assembly and ARM7 deltas are all zero. The finish snapshot
records the accepted, uncommitted source tree; this note and source travel in the
subsequent worker commit. Snapshots are archived under
`docs/workflow/evidence/fleet_ov012_20261003_0150_{start,finish}.json`.

The larger parsers `02184d80` and `02185684`, resource fixups `0218558c`,
character-encoding lookup, and the rest of ov012 remain required work or
external dependencies. No runtime gameplay test was performed for this batch.
Token usage was not measured.

## Continuation: resource records and encoded pattern interpreter

Batch `fleet_ov012_20261003_resource_fixup`, starting at worker revision
`3f8aa35c96f6c570fe186b3fb13f3b3f0294490e`. The worktree was clean. Previous
experiments were inspected; neither function had a prior variant count. Existing
source and evidence were preserved, and the integrator queue was untouched.

| Range (end exclusive) | Reconstructed behavior | Cumulative variants |
| --- | --- | --- |
| `0218558c..021855f0` | Resolve each record's string offsets against its resource pool | 3 |
| `02185684..021859f4` | Match encoded pattern atoms, sets, inverted sets, ranges and bounded repetitions across candidate positions | 8 |

The resource loader in `02184d80` resolves its record array at blob offset 4,
advances records by 32 bytes, and calls the fixup before setting bit 31 of the
resource flags. Its later evaluation loop establishes five string alternatives
at `00..13`, five signed lengths at `14..18`, five comparison modes at `19..1d`,
and an unsigned count at `1e`. Byte `1f` remains unknown. `PatternState.h` now
models the actual arrays and offset/pointer union; `PatternResource::records`
uses this local record type. No shared headers or storage definitions changed.

The parser calls the new interpreter for modes 4..7, passing encoded pattern and
input bytes plus a candidate-position count. The fourth argument is unused in
the original interpreter. Delimiters are encoding-dependent state bytes, and
repetition digits subtract character code 8. The special zero-to-sixty wildcard
seeks the following literal until encountering that literal, zero, or `ff`.
The original eight-byte temporary set buffer and input assumptions are retained.

Fixup variants tested integer offsets (72%), pointer displacement (76%), then
the observed load/flag/displacement lifetime order (100%). The exact source uses
the pinned MWCC byte-pointer subtraction from null that the original relocation
representation emits; integer subtraction folds the required instruction.
Interpreter variants progressed through 54.55%, 60.91%, 66.82%, 83.18%, 85%,
97.27%, 98.18%, and 100%. Signedness, eager endpoint loads, delimiter-loop form,
and declaration versus initialization order explain the observed differences.
Its set scratch first stores the inversion bit and then the member count,
matching the original register lifetime. No assembly, binary substitutes,
comparison-input changes, or denominator reductions were used.

All eleven candidate comparisons and source snapshots are preserved in
`build/matching/20261002T155352-*` through `20261002T155954-*`, with the cumulative
ledger in `build/matching/attempts.jsonl`. `factory_diff.py` diagnostics are in
`build/factory/fleet_ov012_{resource,interpreter}_diagnosis_*.json`; accepted
`factory_evidence.py` packages are
`build/factory/fleet_ov012_{resource,interpreter}_evidence_accepted.json`.
Original disassembly remains in `build/factory/fleet_ov012_dis/ov012_3.s`.
Full acceptance is recorded in `build/factory/fleet_ov012_resource_accept.log`.

`ninja -j2 rom check report sha1` passed all module and symbol checks, ROM
input/output isolation, ARM7 preservation, and SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The original input was independently
rehashed to the same SHA-1. `git diff --check` passed. No runtime test was performed.

The measured `work_batch.py` interval is **555.763999 seconds** (9m 16s).
The gain is **2 functions and 980 code bytes**, all instructions; literal,
rodata, initialized writable data, BSS, assembly and ARM7 deltas are **zero**.
Denominators are unchanged. Start/finish snapshots are archived as
`docs/workflow/evidence/fleet_ov012_20261003_resource_fixup_{start,finish}.json`.
Tokens were not measured. Neither function reached the ten-unproductive-variant
cap; future work must retain the cumulative counts above.

The outer parser `02184d80`, the first 24 state bytes, resource-header bit fields,
record byte `1f`, character encoding lookup, remaining resource data ownership
and the rest of ov012 remain required work or external dependencies. This batch
does not establish module completion or integration into main.
