# Project work rules

Read GOALS.md for acceptance and docs/DEVELOPMENT.md for reconstruction workflow.
Factory orchestration and queue state belong to the separate Factory project.
Preserve existing user changes.

- Follow `docs/NAMING.md`: reconstructed functions need evidence-based descriptive
  names and original processor/module/address/symbol comments at their definitions.
  Address-only function names remain required naming work. Preserve established
  library/SDK and ABI names; do not invent semantics. Rename source references and
  owning symbol maps together and verify the full ROM after naming migrations.

- Organize integrated sources by the subsystem and descriptive filename rules in
  `docs/NAMING.md`. Keep run/worker/batch provenance in `build/`; place new
  sources in the chunk folder from `docs/subsystem-map-usa.json`, not
  `src/Unclassified/`.

- `src/AssemblyFallback/*.inc` (recursively) contains unreconstructed assembly
  references, not compiled replacements. Keep these functions eligible for C/C++
  reconstruction; do not count their presence as decompilation or runtime acceptance.

- Runtime helpers listed in `config/usa/arm9/runtime_support.json` are accepted
  library support. Do not assign or attempt C/C++ reconstruction of them.
  Keep their labelled matching inline assembly in `.cpp` files (or already
  matched C) and provenance. Assembly functions do not earn C/C++ credit.
  Runtime assembly counts separately from C/C++ source reconstruction.

- Use independent worktrees for reconstruction workers. One integrator owns main.
- Give agents bounded subsystem tasks and compact handoffs, not full histories.
- Compare candidate objects during iteration; run full ROM/module/symbol/SHA1
  checks before accepting integrated batches. Never lower coverage denominators.
- For stubborn matches, consider searching original instructions for already-matched
  siblings before expanding source variants. See the instruction-pattern search
  procedure in `docs/RECONSTRUCTION_TOOLS.md`.
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

- Integrate verified uncommitted worker subsets only through `tools/integrate_verified_subset.py`. Its project-wide process lock must be acquired before reading main state; it holds ownership through validation, rollback and publication. Never use a run-specific lock or mutate main concurrently.
