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
