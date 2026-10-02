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

## Measurement

`tools/work_batch.py start NAME` records current reports and revision under
`build/workflow/NAME/`. `finish NAME` records elapsed wall time, changed coverage,
and revision after acceptance. It rejects denominator changes or regressions.
Elapsed time includes any idle period and is not CPU time or a delivery forecast.
Add `--attempts N` for known experiment counts and `--notes ...` for limitations.
Token usage is explicitly unknown unless separately measured by the runtime;
do not infer it from account-plan limits or equate aggregate tokens with billing.

Archive selected batch JSON in `docs/workflow/evidence/` at milestones. Keep
attempt details and large diffs in ignored build files, not in conversation.
Track both instruction/code gains and removed fallback dependencies. Preserve
separate accounting for literals, data, BSS, and reviewed assembly.

Generate progress images at accepted milestones using `tools/progress_image.ps1`.
Images show coverage, not effort completion. Never count unintegrated worker
results in the main-worktree dashboard.

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
