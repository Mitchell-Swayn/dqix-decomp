# ov009 worker: text table and search helpers

Batch `fleet_ov009_20261003_0200`, source commit
`f825174ac4202f2e9cbfc2ba0d6286bfaefc2af1`.
Measured batch interval: 2026-10-02 15:43:35.210103 to
15:51:12.110290 UTC, **456.900187 seconds** (7m 36.9s).
No prior ov009 variants or source ownership were present in this worktree.

| Function | Range (end exclusive) | Instructions | Variants |
|---|---|---:|---:|
| Table reference relocation `0218a420` | `0218a420–0218a484` | 100 bytes | 2 |
| Uppercase copy `0218a484` | `0218a484–0218a4c8` | 68 bytes | 3 |
| Fixed-length substring search `0218a4c8` | `0218a4c8–0218a518` | 80 bytes | 1 |
| Byte-set membership `0218a888` | `0218a888–0218a8b8` | 48 bytes | 1 |

Six candidate-object comparisons: TextSearch three, TextTableReferences two,
TextByteSet one. The unchanged substring function was compared in all three
TextSearch objects. All four functions are exact; no function reached its
ten-variant cap. New source is under `src/Factory/ov009/`; only ov009's delink
map changed. No shared headers, symbols, queue state or other modules changed.

## Evidence and compiler findings

Original instructions came from `dsd dis` using the unchanged USA config.
Caller `02189a4c` walks table records at `02189b98–02189bac`: the header is at
context + `0x114`, records advance by `0x20`, and the callback reads reference
count at record + `0x1e`. The header's reference base is at +8. The source models
seven reference slots as an offset/pointer union and checks the record size.
Metadata bytes at `0x1c`, `0x1d` and `0x1f` remain semantically unknown.

The relocation's unsigned sentinel is `0xffffffff`; missing offsets or a null
base produce null pointers. Integer subtraction of zero matched 92%; MWCC's
pointer-origin subtraction idiom, already present in
`src/World/ZoneState2754Relocate.cpp`, reproduced the original `sub ..., #0`.

Uppercase-copy callers at `02189c70` and `02189e30` clear temporary buffers
before calling; the helper copies no terminator. Separate assignments matched
64.71%, a single assignment of a conditional value matched 52.94%, and
branch-local assignment expressions matched 100%, preserving signed-byte
reloads. The search uses the existing byte comparator `func_02001aec`
(originally inspected in `RuntimeMemory.s`). Byte-set membership is called at
`0218a6f8` and `0218a750` by the remaining pattern matcher.

Verbose disassembly, source snapshots, diffs and diagnoses remain under ignored
`build/fleet_ov009/` and `build/matching/`. `factory_evidence.py` packages are
`text-search-exact.json`, `text-table-exact.json`, and `text-set-exact.json`.
Its caller discovery returned no records for overlay targets, so caller evidence
above was checked directly against disassembly and ov009's relocation map.

## Acceptance and remaining work

`ninja -j2 rom check report sha1` passed after final source edits: all configured
ARM9 modules and symbols, ARM7 baseline, and USA ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`.
Original input SHA-1 was checked independently and matched the same target.
`git diff --check` passed. No gameplay test was performed.

`tools/work_batch.py` start/finish records are under
`build/workflow/fleet_ov009_20261003_0200/`. Report deltas: **+4 functions,
+296 instruction bytes, +0 literals, +0 initialized/readonly data, +0 BSS**;
all denominators and all ARM7 counters are unchanged. The three source units
have no literal pools. No assembly or binary substitutes were added.

Required fallback work remains: caller `02189a4c`, pattern matcher `0218a518`,
the broader text context layout, loaded table metadata and other ov009 code/data.
The matcher reads syntax bytes at context + `0x2a–0x31`; its byte-set helper now
has exact source. These are next dependencies, not deferred completed work.
This batch does not establish module completion. Token usage was not measured.

## Continuation: matcher and syntax initialization

Batch `fleet_ov009_20261003_cont_01`, source commit
`978ab67bb2e76d31d1e10a788edf47f4d39d2f5a`.
Measured interval: 2026-10-02 15:52:55.038038 to 16:03:16.524414 UTC,
**621.486376 seconds** (10m 21.5s). The previous source and experiment ledger
were preserved. Neither new function had previous attempts or ownership.

| New range (end exclusive) | Instructions | Literals | Readonly table | Alignment |
|---|---:|---:|---:|---:|
| Initializer `021847ec–02184848` | 88 | 4 | 0 | 0 |
| Matcher `0218a518–0218a888` | 880 | 0 | 0 | 0 |
| Syntax source `0218aafc–0218ab48` | 0 | 0 | 75 | 1 |

Gain: **2 functions, 968 instruction bytes, 4 literal bytes, 75 readonly
table bytes, 1 alignment byte, 0 initialized writable data and 0 BSS**.
The report includes the initializer's literal in code: its recorded deltas are
**+972 matched_code, +76 matched_data, +2 matched_functions**. All coverage
denominators and ARM7 counters are unchanged. No assembly or binary substitutes
were introduced; remaining functions continue to use original fallback.

### Reconstruction evidence

The original ov009 disassembly and relocation map establish four calls from
`02189a4c` to the matcher, at `0218a2d4`, `0218a308`, `0218a348`, and `0218a378`.
The context argument is owner + `0xfc`; the fourth argument is unused, and the
fifth bounds the number of text positions attempted. The matcher implements
byte categories, bracket sets, negated sets/ranges, repetition and a delimiter
scan for its special zero-to-sixty repetition case. Its eight-byte set buffer
and repeat parsing retain the observed original behavior.

Initializer `021847ec` converts all fifteen five-byte strings using
`020424e4(..., 1)`, whose original instructions search the selected encoding
table. The syntax source is a real `entries[15][5]` array plus the observed
one-byte alignment padding. The prior pattern table/record types now live in
the shared local `TextPattern.h`; the initializer and matcher use the same
context. `020dfc40`, `020e0280`, and the ov009 caller establish the separate
resource-table subobject before the pattern table. Unused trailing resource
fields remain explicitly named unknown. Size and syntax-offset checks compile.
The existing relocation function remains exact after moving its types.

Matcher variants: **57.47%, 67.73%, 85.45%, 98.18%, 100%**. Explicit sentinel
loops, eager endpoint loads, declaring set length before repetition bounds,
sharing the negation temporary with the later length, and preserving marker
declaration/load order reproduced MWCC's instructions and register assignment.
The first compiling initializer matched 65.22%; declaring its counter before
the destination gave 100%. Its table initially lacked the final padding byte
(99.34%); explicit alignment storage gave 100% without changing target inputs.

There were **12 match_unit invocations: nine completed object comparisons and
three compilation failures**. The common header initially requested unavailable
`stddef.h`; switching to the repository's standard declarations fixed all three
units. Counts including this failure: matcher 7 invocations (5 unproductive,
2 exact); initializer 3 (2 unproductive, 1 exact); existing relocation 2
header verification invocations (1 failure, 1 exact). Previous helper counts
above remain in force. No function reached the ten-unproductive-variant cap.

Candidate snapshots and failed hypotheses remain in `build/matching/`.
Final factory evidence is under `build/fleet_ov009/`:
`pattern-final-exact.json`, `initialize-final-exact.json`, and
`relocation-common-header-exact.json`; mismatch diagnosis is
`pattern-v4-diagnosis.json`. The original disassembly remains in its `dis/`
subdirectory. Logs and start/finish snapshots remain ignored build artifacts.

### Verification and next dependencies

`ninja -j2 rom check report sha1` passed: ARM9 main, ITCM, DTCM, all 35
overlays, symbols, ARM7 baseline and target USA ROM SHA-1. The original input
SHA-1 was independently rechecked and matched
`c7c3014c237900c8281289b8bc76a781969b6278`. `git diff --cached --check` passed.
Acceptance log: `build/fleet_ov009/acceptance-cont.log`. Batch snapshots:
`build/workflow/fleet_ov009_20261003_cont_01/`. No gameplay test was performed.

Required fallback work still includes caller `02189a4c`, text selection helper
`0218a8b8`, resource/table metadata semantics, broader owner layout and other
ov009 code/data. The matcher listed as required work in the earlier handoff is
now reconstructed; its caller remains required. Only ov009 source, its map and
this evidence document changed. Queue and other modules were not edited.
No integration or merge into main occurred. Module completion and measured
token usage are not claimed.
