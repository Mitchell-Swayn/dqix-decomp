# ov005 rectangle animation batch

Batch: `fleet_ov005_20261002t154700`, worker `fleet_ov005`, baseline
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. No prior ov005 source units or
variant-count notes were present. Queue and other modules were untouched.

Seven C++ functions reconstruct the connected rectangle reset, base-relative
bounds, per-tick advancement and rounded fixed-point interpolation family.
The local `AnimatedRectangle` type records all observed fields of its 0x3c-byte
state. Names describe inferred roles, not recovered original identifiers.

| Source | Half-open original range | Functions | Instruction bytes | Literal bytes | Variants/function |
| --- | --- | ---: | ---: | ---: | ---: |
| RectangleReset.cpp | 0x021536e0–0x02153728 | 1 | 72 | 0 | 1 |
| RectangleAdvance.cpp | 0x02153728–0x021537bc | 1 | 140 | 8 | 1 |
| RectangleInterpolate.cpp | 0x021538fc–0x02153954 | 1 | 88 | 0 | 6 |
| RectangleBounds.cpp | 0x02154d18–0x02154da8 | 4 | 144 | 0 | 1 each |

All seven functions and four objects compare at 100%. Nine candidate compilation
and comparison runs were recorded (twelve per-function variants including the
four setters). No function reached the ten-unproductive-variant cap.

Interpolation v1/v2/v4/v5 matched 72.73%; a separate step-first addition (v3)
matched 95.45% with only reversed final ADD operands. Reassigning the difference
local to its rounded fixed-point step (v6) reproduced the original allocation and
instruction order without assembly or compiler-setting changes. All candidates,
diffs, diagnoses and hashes remain under ignored `build/matching/`.

Original evidence came from `dsd dis` and ov005's symbol/relocation maps. Reset is
called at 0x02153d44 on the embedded state at +0x1a34; advancement is called at
0x02154e14. The stack-local rectangle in 0x0215c058 calls reset at 0x0215c288,
all four setters, then the renderer at 0x0215c340. The renderer 0x021537bc reads
current left/top/width/height, applies the inset to obtain four corners, and uses
depth for its geometry path. `factory_evidence.py` packages for all four units
are in `build/factory/ov005_*evidence.json`; their automatic mapped-caller lists
are empty, so the caller observations here come directly from original maps and
disassembly, not from that list.

Acceptance: `.venv/Scripts/ninja.exe -j2 rom check report sha1` passed, including
ARM9 main/autoloads/all overlays, symbol checks, ARM7 baseline and final USA ROM
SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. The independent original input
retains that SHA-1. `git diff --check` passed. Logs: `build/factory/ov005_accept.log`.
Both reconfigurations supplied the explicitly assigned read-only compiler path.

ARM9 report delta: matched functions 1651 → 1658; matched code 218816 → 219268
(+452, including the eight literal bytes above); matched initialized data remains
66724. BSS, alignment and necessary assembly gains are zero. Denominators remain
14790 functions, 2959478 code bytes and 1602476 data bytes. ARM7 coverage is unchanged.
Batch elapsed time is recorded by `tools/work_batch.py finish` in the local
`build/workflow/fleet_ov005_20261002t154700/finish.json`; token usage is unmeasured.

Remaining dependencies: renderer 0x021537bc–0x021538fc remains original fallback;
its three mode-specific pointee layouts require further reconstruction. The
render-parts pointer is explicitly opaque in this bounded state interface.
The matched interpolation calls the existing shared `fix32abs` declaration and
source. Parent overlay state, renderer setup, data tables and the rest of ov005
remain required work. No gameplay testing or module-completion claim is made.

## Continuation: allocator pools and texture reservations

Batch `fleet_ov005_20261002t162500`, baseline
`e6335afa68ddb7b1888895eb65fa1f8fd3c00c96`. The tracked worktree was clean;
prior matching ledgers and the archived handoff were inspected and preserved.
These two functions had no prior variants or ownership claims in local evidence.
The renderer was inspected but received no candidate variants in this batch.

| Function | Half-open range | Instruction bytes | Literal bytes | Variants |
| --- | --- | ---: | ---: | ---: |
| Allocator pool setup | 0x02153954-0x02153b20 | 460 | 0 | 1 |
| Texture reservation setup | 0x02153b20-0x02153ba4 | 132 | 0 | 1 |

`OverlayResources.cpp` reconstructs the connected resource setup family with
the existing shared `SafeAllocator` type, actual arrays of eight and sixteen
allocators, and twenty-four 0x70-byte texture reservation records. Each record
contains two ten-word image pool snapshots, two shared palette snapshots,
allocation keys and sizes. The additional large and single texture reservations
are separate subobjects. The unused allocator at +0x230 is retained in the layout.
Unknown intervening overlay state and the four allocated buffer payloads remain
explicitly unresolved; the header does not claim the complete parent layout.

Original instructions and calls establish the layout: `0207de48` saves image
and palette state and reserves their VRAM; `0207df50` resets the current snapshots
from the saved initial snapshots; `0207df90` restores those current snapshots.
The original ov023 caller invokes parent initialization at 0x021e3564 before
allocation setup at 0x021e3574, passes the allocators stored at +0x10 and +0x0c, and later calls
texture reservation setup at 0x021e37dc. These observations came from original
`dsd dis` output and relocation maps, not generated pseudocode.

One candidate compilation/comparison matched both functions at 100%; there were
no failed variants, assembly additions or compiler-setting changes. The attempt,
source snapshot and unchanged target hashes are archived under
`build/matching/20261002T155330-969b6f3f9973400088603f6ec560888e/`.
`factory_diff.py` reported zero mismatched symbols. Read-only evidence package:
`build/factory/ov005_resources_evidence.json`. No earlier variant counts reset.

Acceptance log: `build/factory/ov005_resources_accept.log` for
`.venv/Scripts/ninja.exe -j2 rom check report sha1`. Full ARM9 module and symbol,
ARM7 baseline, and final ROM checks passed with USA SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`; the independent original input
retains that hash. `git diff --check` passed. Both reconfigurations explicitly
used this worktree's assigned read-only compiler path.

Delta: +2 functions and +592 instruction/code bytes; literals, initialized data,
BSS, alignment and necessary assembly gains are zero. ARM9 matched counts are
1660 functions and 219860 code bytes; initialized data remains 66724 bytes.
Denominators remain 14790 functions, 2959478 code bytes and 1602476 data bytes;
ARM7 coverage is unchanged. Elapsed time is measured by `tools/work_batch.py`
in `build/workflow/fleet_ov005_20261002t162500/finish.json`; tokens are unmeasured.

Remaining required work includes resource destruction at 0x02154198, parent
initialization at 0x02153ba4, backing buffer payloads and overlay state, the
rectangle renderer and its other modes. All nonexact functions remain fallback.
No gameplay testing, main integration or module-completion claim is made.
