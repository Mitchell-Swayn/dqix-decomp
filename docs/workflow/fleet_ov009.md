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
