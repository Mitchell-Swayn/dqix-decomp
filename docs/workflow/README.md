# Reconstruction workflow

GOALS.md remains the acceptance contract. This workflow changes iteration cost,
not what qualifies as reconstructed source. Queue: [queue.json](queue.json).

## Roles and batches

The integrator owns the main worktree, merges verified commits, resolves shared
configuration, and runs final acceptance. Workers use independent worktrees and
own coherent function families. Shared headers/configuration changes travel with
their source commit; workers never edit another worktree. New workers receive
the task scope, relevant paths, commands, acceptance, and a short evidence note,
not the entire conversation. No routine commit-window messaging is needed.

A batch normally covers 3–10 related functions, but a single hard dependency or
verified data range may be useful. After ten unproductive compiler variants on
a function, record the closest result, tested hypotheses, and next experiment;
move to another dependency rather than retrying without new evidence. This is a
triage limit, not permission to abandon the function or relax acceptance.

## Fast iteration and acceptance

1. Read only the relevant declarations, disassembly, relocations and callers.
2. Compile the candidate object and compare it against unchanged target objects.
   Use `tools/match_unit.py` when available. Full details stay in ignored build
   logs; normal replies contain the mismatch summary and decision.
3. Once the batch matches, run `ninja rom check report sha1` and required tests.
   ARM7 workers run `tools/arm7_build.py` plus its pipeline tests; the integrator
   verifies packaging in the full ROM. A matching object alone is not acceptance.
4. Integrate the batch, rerun combined acceptance, and record coverage deltas.
   Run fresh archive/extraction builds for pipeline changes and meaningful
   milestones. Repeat gameplay tests when runtime scope warrants them.

`tools/integrate_batch.py COMMIT...` applies explicit commit hashes in order from
a clean tracked worktree. Its only automatic conflict resolution merges disjoint
ARM9 delink blocks with unchanged section boundaries and nonoverlapping ranges.
Other conflicts stop and preserve Git state for review. Logs stay under ignored
`build/integration/`. Twenty synthetic Git/parser tests cover accepted merges and
rejected conflicts; full ROM acceptance is still a separate mandatory step.

ARM7 builds now use MWCC's `-MD` output to record every transitive source/header
hash per unit and feed an aggregate dependency file to Ninja. Shared declarations
can therefore move into headers without bypassing rebuilds or provenance.
Missing/outside inputs and assembly in headers are rejected; reviewed assembly
exceptions remain bound to their source files. Eleven dependency tests cover
native Windows and Wine/WSL paths, nested-header hashes and a real pinned
compiler/Ninja rebuild after changing a nested header in a path containing spaces.

ARM9 delink uses Ninja 1.10 dynamic outputs: objdiff's original-object inventory
declares every generated source target and fallback ELF. `ninja delink` creates
`build/usa/delinks/completion.json` only after dsd succeeds and every expected
object is a newly written ELF; the record includes sizes and SHA-256 hashes.
Pinned dsd does not produce `delink.yaml`, and no placeholder YAML is created.
Deleted generated objects rerun delink; deleted compiled candidates rebuild
through their existing compiler edges. Configurations, tools and extracted ARM9
program/module metadata are dependencies. Unchanged `ninja rom report` is a
no-op; explicit check/SHA-1 targets still run their verification commands.
Five focused tests exercise real Ninja graphs in temporary paths with spaces,
including deleted objects, changed inputs and failed/partial/invalid delink
results. The 121-test tool suite passes (two existing skips). A fresh archive
from source tree `2a9400a6b34a3290b9a61f0801a7aa5adb08ad46` passed all 320
build/check steps, exact USA ROM SHA-1 and an immediate no-op `rom report`.
Worker evidence: `build/verification/delink-outputs-3vhbfgc5/`; real pinned-tool
deletion/change recovery checks: `build/delink-real-tests.json`. No source
coverage or comparison rules changed. Only this validation note was added after
the verified tree.

## Measurement

`tools/work_batch.py start NAME` records current reports and revision under
`build/workflow/NAME/`. `finish NAME` records elapsed wall time, changed coverage,
and revision after acceptance. It rejects denominator changes or regressions.
Elapsed time includes any idle period and is not CPU time or a delivery forecast.
Add `--attempts N` for known experiment counts and `--notes ...` for limitations.
Token usage is explicitly unknown unless separately measured by the runtime;
do not infer it from account-plan limits or equate aggregate tokens with billing.

`tools/measure_agent_tokens.py --project-root ABSOLUTE_PATH --start START --end END`
aggregates local Codex per-response telemetry for an explicit UTC interval
(inclusive start, exclusive end). Use an absolute project path: database cwd
matching is literal after Windows path normalization. An exact `--agent-path`
or explicit `--rollout` files may replace project selection. The database is
opened read-only; conversation events and account data are not exported.
Response IDs are deduplicated, thread identities checked, and model attribution
comes from historical turn metadata. Diagnostics return a nonzero exit status;
never silently use partial totals. Fourteen focused tests cover this accounting.
Cached input is a subset of input, and reasoning is a subset of output. Report
accepted batch deltas alongside measured tokens; price equivalents and plan
allowance usage are different quantities. See [the measured comparison](TOKEN_COST_ANALYSIS.md).

Archive selected batch JSON in `docs/workflow/evidence/` at milestones. Keep
attempt details and large diffs in ignored build files, not in conversation.
Track both instruction/code gains and removed fallback dependencies. Preserve
separate accounting for literals, data, BSS, and reviewed assembly.

Generate progress images at accepted milestones using `tools/progress_image.ps1`.
Images show coverage, not effort completion. Never count unintegrated worker
results in the main-worktree dashboard.

The first pilot's snapshot interval measures integration only: its workers had
already started before the baseline snapshot. Do not use its elapsed seconds as
end-to-end reconstruction throughput. World reported about six minutes on
inherited matching drafts; ARM7 reported about ten minutes and six per-function
candidate compilations. Start subsequent batch clocks before dispatching work.

## Reusable compiler findings

- MWCC named code section: `#pragma define_section init ".init" RX` followed by
  `__declspec(section "init")` on a function. Verified by GPCStartup.cpp. Other
  tested section pragmas were ignored; inspect the resulting ELF section names.
- `#pragma dont_inline on` prevents observed local helper inlining when
  `-inline noauto` alone did not. Verified by FileCacheCRC.cpp.
- Copying a restored source file can preserve an older mtime; touch it or rebuild
  explicitly before trusting candidate objects.
- Never modify original objdiff inputs to make the report pass. The existing
  allowlisted linker-only metadata copies carry no source credit.

## ROM input/output isolation

Copy the verified original ROM from `extract/baserom_dqix_usa.nds` when setting
up a worker. Generated ROMs must never be hard-linked to inputs or other worker
outputs. `guard_rom_files.py` runs before the ROM builder and the finalizer
checks the same rule: output aliases and multiply-linked files are rejected
before writing. Seven tests include rejection before a writer can change the
original input. Read-only tool junctions do not require copying compiler files.

Before a worker coverage snapshot, configure and build the checked-out baseline
so reports correspond to that revision, especially after switching branches.
Record dispatch time separately when measuring setup-inclusive task duration.
Only integrated main snapshots establish accepted batch coverage deltas.
