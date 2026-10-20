# Second batch: 100 additional exact matches

Completed 2026-10-08 Australia/Sydney using the reusable reconstruction scripts.
Elapsed agent workflow time: **4 minutes 24 seconds**, from 2026-10-07
18:14:21 UTC through verified completion at 18:18:45 UTC. Documentation and
cleanup follow that interval.

- 100 new functions, distinct from both earlier batches.
- Every function is eight bytes: **800 additional reconstructed code bytes**.
- All 100 matched on the first compile, with independent ELF raw-byte comparison
  and objdiff both passing.
- Compilation plus batch verification: **1.68 seconds** (1.54 build, 0.12 compare).
- 175 candidates inspected through the Ghidra MCP HTTP backend in **39.43 seconds**.
- The final linked-layout audit passed for every selected address and size.
- Module, symbol, ARM7, report and final ROM SHA-1 checks passed. ROM SHA-1:
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- Coverage increased by 100 matched functions and 800 matched code bytes against
  the previous 100-function worktree; denominators remain unchanged.

The isolated worktree `build/ghidra-next100/project` contains the prior 100-function
batch plus this batch in `src/GhidraNext100/`. The earlier ten-function sample
was excluded from selection and remains in its separate worktree. Game source in
the main checkout was not modified.

This speed-focused sample consists mostly of field accessors, including signed
halfword loads, simple record stores and 40 constant-return methods. Source was
adapted from inspected Ghidra pseudocode with explicit width/sign typedefs and
ARM compilation mode. No assembly wrappers or binary substitutions were used.
The batch is simpler than the preceding 100-function sample, so elapsed times
are not a controlled comparison of script efficiency.

One integration attempt supplied all selected names as one linker preservation
argument; MWLD aborted without a detailed diagnostic. Retrying with only the
previously established required preserved symbol (`func_0200bbd8`) passed all
checks. None of the new functions needed explicit preservation. That retry is
included in the elapsed time. The supported scripts and matching checks were
not changed or weakened during this batch.

Evidence is under `build/ghidra-next100/`: `inspection.json`, `selected.json`,
`verification.json`, `coverage-delta.json`, `integration-timing.json`,
`integration2.log`, and `project/build/layout-audit.json`. Detailed per-function
raw-byte evidence and objdiff results are in the artifact directory named in
`verification.json`. Other unreconstructed code still uses original fallback;
this is not full project decompilation or gameplay validation.
