# Luna small World batch

Started 2026-10-02 10:41:30 UTC from `work/full-decomp` revision `b36eed6cbdaf53c7250f91294ce59d560da72a96`. Finished 2026-10-02 10:47:58 UTC (work-batch elapsed measurement: 387 seconds). Three target-object comparisons were run, one candidate compile each; no variant tuning was needed. Token usage was not measured.

Reconstructed three previously unowned ARM9 main functions while leaving `data_02109020` BSS under existing fallback accounting:

- `func_0208e884` (`0x0208e884`, 8 bytes): C-linkage script callback, always returns 1.
- `func_0208e88c` (`0x0208e88c`, 8 bytes): C-linkage script callback, always returns 1.
- `func_0208e9e8` (`0x0208e9e8`, 12 bytes): returns the existing `WorldObjectInstanceList` storage at `data_02109020`.

All three units compare at 100%. They contain 24 matched ARM instruction bytes plus 4 matched literal-pool bytes embedded in the accessor's `.text`; no separate program data or BSS was added. The full build's report moved by +4,984 code bytes, +500 data bytes, and +43 functions against the work-batch start snapshot, with unchanged denominators and no regressions. The work-batch ARM7 snapshot also moved by +43 source functions, +4,232 source-code bytes, +256 literal-pool bytes, +144 source-data bytes, and -4,632 fallback bytes, with unchanged payload/BSS. No ARM7 source was changed in this batch. These ARM9/ARM7 snapshot-to-report movements cannot be attributed to these three functions: their exact unit reports account for 28 text bytes and 3 functions, so the broader report deltas reflect pre-existing build/report reconciliation in this worktree. No denominator was changed.

`ninja rom check report sha1` completed successfully (135 tasks): ARM9 main, ITCM, DTCM and overlays checked; exact USA SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`; ARM7 baseline passed. Full output is in ignored `build/workflow/luna-world-small/ninja.log`; per-unit comparison artifacts are under ignored `build/matching/`.

During the first edit attempt, `apply_patch` resolved against the main worktree even though the shell command named the worker worktree. The root agent relocated the three intended source files and delink ranges into this branch and restored main; I verified this branch contained only those four intended pending files before continuing. The full build ran only after that verification. No other worktree was edited by this batch afterward.