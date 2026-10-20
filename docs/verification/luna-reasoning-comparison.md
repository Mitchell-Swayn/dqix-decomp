# GPT-6-Luna reasoning comparison — 100 DQIX functions

All five completed the same final 100 ARM9 functions: 1,608 bytes (17 x 12, 64 x 16, 19 x 20). Raw-function bytes, objdiff, linked addresses/sizes, full modules/symbols/ARM7 and ROM SHA-1 passed. Denominators unchanged. These are short accessors, setters, bit operations and conversions, not representative large gameplay functions. Each worker started from the same prior accepted source baseline. The five runs are alternate implementations of the same batch, not 300 new functions. Sources remain uncommitted in independent worktrees.

| Reasoning | Recorded active seconds | Compile/compare invocations | Behaviour |
|---|---:|---:|---|
| Low | 1078.913 | 10 | Premature screening stop required parent intervention; selected/replaced candidates; codegen/type iterations; ultimately 100 matches |
| Medium | 196.932 | 2 | Missing C linkage on first attempt; all 100 passed after correction |
| High | 180.560 | 2 | Undefined type alias caused first build failure; added width aliases/linkage/ARM mode; all 100 passed |
| Xhigh | 516.040 | 4 | Two type-name build failures, then C++ mangling mismatch; fourth attempt passed |
| Max | 873.618 | 2 | First attempt 99/100; removed a redundant narrowing cast to reach 100/100; extensive reporting |

High was 16.372 seconds (8.3%) faster than medium in this single run. This is an observation, not a statistically established model ranking. Low is not directly comparable: it screened/selected candidates, fetched evidence and replaced unsuitable functions; medium/high received its final inspection selection. Low excluded initial guide reading and a 153.951-second gap; its total includes a 139.655-second abandoned screening attempt and a 939.258-second resumed interval. Parent worktree setup and baseline builds are excluded in all runs. Prompts were refined to improve timing compliance. No token/cost comparison was measured.

## Timing breakdown

High, xhigh and max recorded every phase boundary. Its nonoverlapping active wall phases sum to 180.560 seconds:

| High phase | Seconds |
|---|---:|
| Startup/read | 8.755 |
| Evidence review | 24.396 |
| Source reconstruction | 16.589 |
| Configure/delink | 5.134 |
| Compile/comparison iteration | 46.619 |
| Final validation/layout | 28.564 |
| Reporting | 50.503 |

These phase times include agent/tool interaction; actual configure/delink command wall time was 0.85 seconds, compile attempts 0.44 and 2.12 seconds, and integrated validation/layout 9.96 seconds. Final timing/report serialization followed timer end and is excluded.

Low measured evidence commands at 27.913 seconds and ten compile/comparison script invocations at 12.148 seconds, but left 1036.313 seconds unassigned to phases. Its replay validation/configure timings are not substitutes for original phase costs. Medium measured compile/comparison scripts at 1.954 and 1.879 seconds, but did not timestamp phase boundaries despite instructions. A complete retrospective phase breakdown cannot be recovered reliably.

High reported viewing opening lines of a pre-existing baseline source during linkage troubleshooting, with no code copied; this was not another worker solution, but is disclosed as a process deviation. The worker guide referenced RECONSTRUCTION_TOOLS.md, which was not copied into medium/high checkouts: this preparation omission was corrected for xhigh/max.

## Xhigh and max measured phases

| Phase | High seconds | Xhigh seconds | Max seconds |
|---|---:|---:|---:|
| Startup/read | 8.755 | 24.519 | 20.940 |
| Evidence review | 24.396 | 41.944 | 58.964 |
| Source reconstruction | 16.589 | 107.342 | 145.387 |
| Configure/delink | 5.134 | 20.379 | 16.347 |
| Compile/comparison iteration | 46.619 | 88.534 | 72.365 |
| Final validation/layout | 28.564 | 73.384 | 75.149 |
| Reporting | 50.503 | 159.939 | 484.467 |
| Total | 180.560 | 516.040 | 873.618 |

Before reporting, high took 130.057 seconds, xhigh 356.101 seconds, and max 389.151 seconds. Max spent 55.5% of its total interval reporting and reconciling records; xhigh spent 31.0%, high 28.0%. Max handled source correctness better on the first comparison (99/100) but took longer overall. Higher reasoning did not improve completion time for these small routines in this single trial. High was the fastest recorded run; medium was close. Timing includes inference, tool orchestration and command execution, so it does not isolate reasoning compute or compiler time.

Xhigh actual compiler/comparison command wall times were 0.470, 0.440, 1.840 and 2.210 seconds; integrated validation plus layout was 9.490 seconds. Max compiler/comparison wall times were 2.350 and 0.440 seconds; integrated validation plus layout was 9.880 seconds. These commands account for only a small portion of elapsed time. Extra reporting and orchestration explain much of the observed difference.

## Evidence

- Low: build/luna100-reset/project/docs/verification/luna-100-functions.md and build/luna-timings.json.
- Medium: build/luna100-medium/project/docs/verification/luna-medium-100.md and build/benchmark-timings.json.
- High: build/luna100-high/project/docs/verification/luna-high-100.md and build/benchmark-timings.json.
- Xhigh: build/luna100-xhigh/project/docs/verification/luna-xhigh-100.md and build/benchmark-timings.json.
- Max: build/luna100-max/project/docs/verification/luna-max-100.md and build/benchmark-timings.json.

The final 100 module/address IDs were independently checked identical across all five inspection manifests. Successful binary matching establishes this batch's build identity; gameplay testing was not performed.
