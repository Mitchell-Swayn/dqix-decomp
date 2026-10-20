# Ghidra and Wibo workflow: ten exact matches

On 2026-10-08 (Australia/Sydney), ten previously fallback-owned ARM9 functions
were reconstructed using the active DQIX Ghidra MCP. Work was performed in the
detached worktree `build/ghidra-workflow/project`, based on revision `4c44373`.
The main checkout's game source and configuration were not changed.

## Method

1. Obtain pseudocode and ARM disassembly through Ghidra MCP for each function.
2. Convert Ghidra types into compilable C++; recover unsigned byte and halfword
   types from `ldrb` and `ldrh`. Preserve the signed flag extraction.
3. Add `src/GameState/GhidraWorkflowAccessors.cpp` and assign the original range
   `0x02011544–0x020115f4` in `config/usa/arm9/delinks.txt`.
4. Compile with the existing Metrowerks compiler (runtime version 3.0 build 137,
   stored in `2.0/sp2p2`) through Wibo, using the project's existing ARM9 flags.
5. Compare with `tools/match_unit.py --no-build`, independently compare raw ELF
   function bytes, and run `ninja -j 2 rom check report sha1`.

## Results

| Function | Bytes | Raw byte match |
|---|---:|---|
| func_02011544 | 24 | exact |
| func_0201155c | 20 | exact |
| func_02011570 | 20 | exact |
| func_02011584 | 12 | exact |
| func_02011590 | 24 | exact |
| func_020115a8 | 12 | exact |
| func_020115b4 | 12 | exact |
| func_020115c0 | 16 | exact |
| func_020115d0 | 24 | exact |
| func_020115e8 | 12 | exact |

All ten matched on the first compile. Objdiff reported 100% for every function;
independent raw-byte comparisons confirmed all 176 bytes match without relocation
normalization. The linker input list includes the compiled candidate object.
The coverage report increased by ten matched functions and 176 matched code
bytes, with all coverage denominators unchanged.

Module, symbol, ARM7 and final ROM SHA-1 checks passed. The rebuilt USA ROM hash
was `c7c3014c237900c8281289b8bc76a781969b6278`.

The clean build and validation took 16.59 seconds with two jobs. A subsequent
recompile of this single source file took 0.041 seconds; compilation plus object
comparison took 0.087 seconds. These are single measurements on an i7-12700,
using the `factory-dqix:0.1` Linux Docker image with read-only original inputs.
Container startup and tool installation are excluded from those measurements.

## Evidence and limits

Artifacts are under `build/ghidra-workflow/`: `ghidra-evidence.json`,
`byte-comparison.json`, `coverage-delta.json`, `timing.json`,
`iteration-timing.json`, `build.log`, and `project/build/matching/`.
The raw-byte checker is `verify_bytes.py`; candidates are retained in the worktree.

This establishes the workflow for small, adjacent field/flag accessors. It does
not establish a matching rate for large functions, overlay code, or complex
control flow, and no gameplay testing was performed. Other unreconstructed code
still uses the project's existing binary fallback. The ten reconstructed
functions use compiled C++ without assembly or binary substitutions.
