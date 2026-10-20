# Cached evidence: 100 additional matching functions

Completed 2026-10-08 Australia/Sydney in isolated worktree
`build/ghidra-cached100/project`. This worktree includes the preceding two
100-function batches plus this batch in `src/GhidraCached100/`.

- Preparation, including tool implementation, tests and Ghidra prefetch:
  **552.05 seconds**. This reuses the existing original inventory;
  it does not include the historical cost of generating that inventory.
- Original evidence: **15,067 functions, 41 modules, 64,012 relationships**.
  Every stored original function byte length/hash and SQLite integrity checked.
- Cached Ghidra analysis: **479 functions** in the active ARM9 program.
  Prefetch added 304 records in **68.94 seconds**, reusing 75 cache hits.
  Whole-project Ghidra pseudocode is not yet prepared.
- New batch, from worktree setup/selection through full integrated acceptance
  and coverage capture: **149.28 seconds**.
- Evidence retrieval: **0.02783 seconds**, 100 cache hits, zero decompiler requests.
- **100 new functions, 1,016 new source code bytes**, distinct from earlier samples.
  46 functions are eight bytes; 54 are twelve bytes.
- Initial compile plus objdiff and independent raw-function-byte comparison:
  **1.699 seconds**, 98 matches. Two type corrections brought all 100 to exact
  matching on the second attempt (**0.373 seconds**, only two objects recompiled).
- Forced rebuild of all 100 final candidate objects plus verification:
  **1.742 seconds** (1.530 compile,
  0.191 comparison). Docker startup is outside the script
  phase measurement; batch elapsed time includes its build container launches.
- Full module, symbol, ARM7 and final ROM checks passed, plus all 100 linked
  addresses/sizes. ROM SHA-1: `c7c3014c237900c8281289b8bc76a781969b6278`.
- Coverage delta: +100 matched functions, +1,016 matched code bytes. ARM9 and
  ARM7 denominators unchanged. No assembly wrappers or binary substitutions.

The two corrections replace a byte-typed mask parameter/return with unsigned
word types to avoid an extra mask, and use a signed halfword store of -1 to
recover the original `mvn` constant encoding. These remain equivalent operations
for the stored/accessed fields. Candidates include small accessors, constant
returns, record stores, masks and setters; this is not a representative benchmark
of large gameplay functions. Cache speed and total workflow time are separate
measurements; earlier batches have different function complexity.

Preparation reused an October 3 inventory snapshot. Its source completion
flags are historical and are never used to select new work: selection is checked
against the latest worktree coverage report. Ghidra analysis is kept separately
from verified source and keyed by module-qualified function ID, original-byte
hash and layout/symbol fingerprint. This fingerprint cannot prove unchanged
Ghidra memory/types; keep the active program fixed and refresh after edits.

Evidence: `build/evidence/preparation-timing.json`, `build/evidence/functions.sqlite`,
`build/evidence/prefetched.json`, and `build/ghidra-cached100/` inspection,
verification, recompile-verification, coverage-delta and integration logs.
One initial container preparation used a host-only input symlink; correcting it
to the container read-only input mount is included in batch elapsed time.
Source is isolated and uncommitted. Original fallback remains elsewhere;
ROM equality does not establish full decompilation or gameplay validation.
