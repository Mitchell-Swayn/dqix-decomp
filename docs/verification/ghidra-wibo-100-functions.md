# Ghidra and Wibo: 100 additional matching functions

Completed on 2026-10-08 Australia/Sydney in the isolated worktree
`build/ghidra-100/project`, based on revision `4c44373`.

The timed interval ran from 2026-10-07 17:34:24 UTC to 17:44:19 UTC:
**9 minutes 55 seconds**, including selection, MCP inspection, source adaptation,
compiler iterations, build-configuration fixes, and integrated validation.
This is agent workflow time, not just compiler execution time.

## Outcome

- 100 additional previously fallback-owned functions reconstructed as C++.
- All 1,544 instruction bytes match their original target objects exactly.
- Objdiff reports all 100 candidate units/functions at 100%.
- Matched coverage increased by 100 functions and 1,544 code bytes; total code,
  data, and function denominators remained unchanged.
- Module, symbol, ARM7 and ROM SHA-1 checks passed. Final USA ROM SHA-1:
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- The final incremental integrated validation run took 8.08 seconds. Earlier
  build and reconstruction attempts are included in the overall elapsed time.

## Scope and iteration

This speed-focused sample contains short ARM9 functions (8–24 bytes): field
accessors, constant returns, flag operations, boolean setters, and record updates.
It is not representative of complex functions or overlays. The earlier ten
functions at `0x02011544–0x020115f4` were excluded from this batch.

Ghidra MCP pseudocode and disassembly were collected for 160 candidates. Initial
inspection excluded unresolved jumps, calls, interrupt routines, and incomplete
decompilations. Of the first 100 selected candidates, 84 matched on the first
compile. One apparent function, `func_0200e828`, was found to be a shared epilogue;
it was excluded and replaced by the inspected standalone function
`func_020340d4`. The remaining candidate set stayed fixed.

Source adaptations recovered unsigned load types, removed redundant decompiler
temporaries/casts, expressed bitfield operations with C++ bitfields, and adjusted
expression grouping to reproduce register allocation. No inline assembly or
binary substitutions were used for these functions.

Each original range was assigned to its own source object because the project's
delink format allows only one `.text` range per object. Integrated validation
initially exposed dead stripping of the unused `func_0200bbd8`. The isolated
worktree's linker configuration now explicitly preserves that original symbol
alongside the pre-existing preserved overlay symbol. No validation checks were
relaxed. The main checkout's source/configuration was not changed by this batch.

## Evidence

Artifacts are under `build/ghidra-100/`:

- `selected.json`: all selected functions, sizes, Ghidra pseudocode/disassembly.
- `byte-comparison.json`: per-function independent raw-byte comparisons/hashes.
- `coverage-delta.json`: before/after coverage snapshots and unchanged totals.
- `project/src/GhidraWorkflow100/`: the 100 candidate source files.
- `project/config/usa/arm9/delinks.txt`: original range assignments.
- `project/build/usa/report.json`: objdiff coverage and per-function matches.
- `build8.log`: passing integrated validation, including final ROM hash.
- `build-timing.json`: final incremental build timing.
- `verify_bytes.py`: independent ELF32 byte-comparison script.

The complete initial MCP evidence remains at
`build/ghidra-workflow/evidence100.json`. Other unreconstructed project code still
uses binary fallback. This batch establishes source reconstruction and matching,
not full project decompilation or gameplay validation.
