# Project work rules

Read GOALS.md for acceptance and docs/DEVELOPMENT.md for reconstruction workflow.
Factory orchestration and queue state belong to the separate Factory project.
Preserve existing user changes.

- Use independent worktrees for reconstruction workers. One integrator owns main.
- Give agents bounded subsystem tasks and compact handoffs, not full histories.
- Compare candidate objects during iteration; run full ROM/module/symbol/SHA1
  checks before accepting integrated batches. Never lower coverage denominators.
- After ten unproductive variants, record evidence and switch dependencies.
  Deferred functions remain required work; no fake matching or binary substitutes.
- Store verbose logs under ignored build/. Return concise differences and results.
- Record batch deltas and elapsed time with tools/work_batch.py. Report token
  usage only when measured; do not invent cost/plan conversion.
- Keep ARM7 instructions, literals, initialized data, BSS and necessary assembly
  separate. A byte-perfect ROM with original fallback is not full decompilation.

- ROM inputs and generated outputs must be independent files. Never hard-link a
  generated output, or use another worktree's output as an input link. Workers may
  share hash-bound read-only original ROM/compiler inputs via tools/rom_inputs.py.
  Verify the original ROM SHA-1; keep every generated output workspace-local.
- Worker edits must use absolute paths inside the assigned worktree. Setting
  exec_command workdir does not change apply_patch's working directory.
