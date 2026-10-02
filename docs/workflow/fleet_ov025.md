# ov025 worker: action queues

Batch `fleet_ov025_20261002t1605`, based on
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. No inherited attempts or source
ownership were found for ov025. No main queue or other module edits.

Reconstructed the reset, FIFO removal, controls and secondary insertion of a
pair of 16-entry queues. `src/Factory/ov025/ActionQueues.h` records the actual
parallel arrays and observed control fields; it is local to this subsystem.
Address-based symbol names remain because gameplay meanings are uncertain.

| Source | Accepted half-open range | Functions | Report code bytes |
| --- | --- | ---: | ---: |
| ActionQueues.cpp | `0x021ed124–0x021ed380` | 10 | 604 |
| SecondaryQueueInsert.cpp | `0x021ed5f0–0x021ed634` | 1 | 68 |

Functions: `021ed124` reset; `021ed1f0` primary removal; `021ed2a0`
secondary removal; `021ed2f4` primary idle predicate; `021ed314` and
`021ed31c` context setters; `021ed324` optional name copy; `021ed344` delay
setter; `021ed350` indexed flags setter; `021ed35c` queue clear;
`021ed5f0` secondary insertion.

Evidence comes from original dsd disassembly and mapped callers, including
`021db7d8`, `021e8988`, `021e918c` (reset), `021ea85c` (clear),
`021eaff0` (secondary insertion), and `021ed6b8`/`021ed7d8` (removal).
Primary insertion at `021ed380`/`021ed444` and processing at `021ed634`
establish the primary array layout. Secondary removal intentionally shifts
payloads and kinds only; its flags array remains in place, as in the original.
Reset likewise leaves the original untouched fields intact.

## Validation and measured delta

- Both candidate objects matched every selected function at 100%; factory
  diagnosis reports zero mismatched symbols. Final comment-only source
  revalidation also matched all ten ActionQueues functions.
- Full `.venv/Scripts/ninja.exe -j2 rom check report sha1` passed twice,
  including final source: main, ITCM, DTCM, all overlays, symbols, ARM7
  baseline, ROM packaging and target SHA-1
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- Original input SHA-1 was independently rechecked against the same target.
  No ROM links or input mutations were made.
- ARM9 report: 1651 to 1662 matched functions; 218816 to 219488 matched code
  bytes. The +672 report bytes comprise 668 instruction bytes and the
  four-byte `750` literal at `0x021ed1ec`. Initialized data, BSS and assembly
  gains are zero. All denominators and ARM7 counters remain unchanged.
- `work_batch.py` start/finish measured 415.070097 seconds (6m 55s).
  Five match invocations: two header-only compilation failures, two first
  exact comparisons, and one comment-only revalidation. Each function matched
  its first successfully compiled source variant. No ten-variant cap reached.
- One initial configure failed because two disjoint `.text` ranges cannot
  share one delink unit; secondary insertion was split into its own source.
  Every configure used the explicitly supplied local compiler directory.
- No runtime/gameplay tests were performed. Token usage is unmeasured.

Verbose evidence is under ignored `build/factory/fleet_ov025/`, including
original `dis/ov025_5.s`, `queues_evidence_exact.json`,
`secondary_evidence_exact.json`, `queues_diagnosis.json` and
`acceptance_final.log`. Candidate snapshots and failed header hypotheses are
under `build/matching/20261002T154644-*`, `20261002T154705-*`,
`20261002T154713-*` and `20261002T154910-*`. Batch snapshots are under
`build/workflow/fleet_ov025_20261002t1605/`.

## Next dependencies

Primary insertion/search (`021ed380`, `021ed444`, `021ed564`) and processing
(`021ed634`) remain required original fallback. Establish payload/context
types and gameplay meanings before extending this family. The local queue
layout's unknown fields remain explicitly named as unknown. Global initialized
data and BSS dependencies of the enclosing owner are not reconstructed here.
This batch does not complete ov025.
