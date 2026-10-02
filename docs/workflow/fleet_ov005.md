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
