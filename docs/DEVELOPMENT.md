# Reconstruction workflow

GOALS.md defines acceptance. Game source lives in src/, include/, and
config/usa/arm7/src/. Regional symbols, relocations, delink maps, ARM7 source
manifests, and linker metadata in config/ are part of the build contract.

## Iteration and acceptance

1. Select a bounded function family and inspect its declarations, instructions,
   relocations, callers, and data ownership.
2. Compile candidate objects and compare unchanged original targets with
   tools/match_unit.py. Detailed comparison logs stay under ignored build/.
3. After ten unproductive variants, record the evidence and switch dependencies.
   Deferred functions remain required work.
4. Run tools/configure.py usa, then ninja rom check report sha1. Preserve all
   coverage denominators and report ARM7 code, literals, data, BSS, necessary
   assembly, and original fallback separately.
5. Use tools/work_batch.py start NAME and finish NAME to record accepted coverage
   deltas and elapsed time. Run tools/verify_clean_build.py --revision HEAD
   --require-sha1 for clean committed milestones. Test relevant gameplay when
   the runtime scope warrants it.

Keep original ROM inputs independent from generated outputs. Shared read-only
inputs can use tools/rom_inputs.py; new bindings live in build/inputs.json.
Existing build/factory/inputs.json bindings remain readable for worktree
compatibility. ROMs, compiler binaries, environments, and generated assets are
local inputs or outputs, never source deliverables.

## Repository boundary

DQIX owns reconstructed source, build configuration, matching tools, technical
analysis, source-coverage baselines, and reproducibility documentation. The
separate Factory project owns orchestration, independent agent review,
scheduling, queues, worker records, dashboards, and token accounting.
Factory's DQIX gates live in adapters/dqix/tools/ and instance records in
projects/dqix/workflow/ within that project. They are not required for a
standalone DQIX build. Upstream GitHub Actions remain repository CI.

Technical inventory, call graphs, function databases, and progress viewers are
optional DQIX development tools. They do not supply game instructions or source
coverage. Verification summaries stay in docs/verification/; verbose logs stay
under ignored build/verification/ (archived logs in its archive/ directory).
