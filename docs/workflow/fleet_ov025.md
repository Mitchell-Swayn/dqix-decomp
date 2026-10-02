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

## Continuation: primary insertion and lookup

Batch `fleet_ov025_20261003t0145`, based on
`ec1dc9e366a96edeaf18c306172ded7de6a36423`. The batch name is an identifier;
actual UTC timing is recorded in its work_batch snapshots. Inspected prior
handoff, matching ledger, module maps and original disassembly before editing.
No inherited variants were recorded for these three functions. No queue,
shared tooling, other module or existing source changes.

`src/Factory/ov025/PrimaryQueueInsert.cpp` reconstructs the contiguous range
`[0x021ed380, 0x021ed5f0)`: append (`021ed380`), insert at the owner's current
insertion index (`021ed444`), and five-field lookup (`021ed564`). Both insertion
paths reject zero IDs, kinds >= 6 and full queues, assign a signed 16-bit serial
with the observed 32767 rollover, and retain all seven parallel arrays.
Lookup compares ID, parameter, payload identity, auxiliary value and kind;
flags and serial are not search keys. The existing actual array layout in
ActionQueues.h suffices; no new shared types or header edits were needed.
Payloads are pointer identities here; their contents are not read by this family.
Address-based names remain because gameplay meanings are still uncertain.

Original dsd output `build/factory/fleet_ov025/dis/ov025_5.s` establishes the
instructions and literal boundary. Callers include `021d8c30` (both insertion
paths) and `021de124` (lookup followed by insertion when lookup returns negative).
The factory evidence caller list is empty because these direct local calls are
not explicit call relocations in the maps; the disassembly supplies this evidence.

- Exact final object comparison: 3/3 functions, zero factory_diff mismatches.
- Three match invocations, each after `ninja -j2` candidate compilation. Append
  and indexed insertion matched their first substantive variants. Lookup variant
  1 used indexed IDs and an unsigned-short ID argument (8.57% match); variant 2
  uses a pointer walk over the ID array and an int argument (100%). The third
  invocation validates final comments. Failed candidate and diagnosis preserved.
  Lifetime unproductive counts: append 0, indexed insertion 0, lookup 1. No cap
  reached; processing has not been tried in either recorded batch.
- Final `.venv/Scripts/ninja.exe -j2 rom check report sha1` exited 0: module and
  symbol checks, ARM7 baseline, packaging and target SHA-1
  `c7c3014c237900c8281289b8bc76a781969b6278`. Independently rechecked original
  input SHA-1. All reconfigures used the explicitly supplied compiler path.
- ARM9 report: 1662 to 1665 matched functions; 219488 to 220112 matched code
  bytes. Gain: 620 instructions plus the 4-byte 32767 literal at `0x021ed560`.
  Initialized data, BSS, alignment and assembly gains: zero. Denominators and
  ARM7 counters unchanged. Original fallback remains for all other functions.
- Timing/deltas: `build/workflow/fleet_ov025_20261003t0145/{start,finish}.json`;
  finish records measured elapsed time against the committed source revision.
  Token usage unmeasured. No runtime/gameplay tests performed.

Verbose evidence: `build/factory/fleet_ov025/primary_evidence_v1.json`,
`primary_evidence_exact.json`, `primary_diagnosis_v1.json`,
`primary_diagnosis_exact.json`, `primary_build*.log`, `primary_acceptance.log`;
candidate/diff snapshots in `build/matching/20261002T155327-*`,
`20261002T155401-*`, `20261002T155424-*`.

Next required dependency: primary processing at `021ed634`, including enclosing
owner, payload/context types and its constant tables. Its original fallback and
global initialized-data/BSS dependencies remain unresolved. The earlier insertion
and search deferrals above are resolved by this batch; ov025 remains incomplete.
