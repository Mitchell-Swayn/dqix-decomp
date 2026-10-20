# Smallest-module run — 2026-10-08

Twenty GPT-6.1 Sol low workers launched. Original window: 2026-10-08T11:01:38.920206+00:00 to 2026-10-08T11:31:38.920206+00:00 (30 minutes). Preparation began at 10:58:49 UTC (~2.8 minutes). Account usage limits stopped 19 workers around 11:19 UTC; the integrator continued inside the window. User resumed the coordinator at 11:48 UTC; closure validation finished at 2026-10-08T11:54:57.909209+00:00. This was not a new 30-minute run.

| Accepted phase | ARM9 functions | ARM9 code | Initialized data | BSS |
|---|---:|---:|---:|---:|
| Original window | 142 | 13240 | 3609 | 0 |
| Post-resume closure | 34 | 3192 | 0 | 0 |
| Total | 176 | 16432 | 3609 | 0 |

ARM7 closure separately accepted 2 functions, 108 instruction bytes and 8 literal bytes. No new ARM7 data/BSS or assembly credit.

Final ROM SHA1: `c7c3014c237900c8281289b8bc76a781969b6278`. Full incremental ROM/module/symbol checks and 343 accepted-source hashes pass. No clean-build or gameplay claim; no commits/pushes.

## Activity and tokens

Worker runnable proxy: 262.5 agent-minutes; awaiting tools: 19.8; not running/unlaunched: 317.7. The latter includes 235.0 agent-minutes blocked by terminal usage-limit errors. Runnable time includes provider scheduling/reasoning/generation, not measured model compute.

Original window token usage: 123,133,978 total, 2,545,250 uncached input, 120,079,360 cached input, 509,368 output including reasoning. Standard API-equivalent USD $22.19; Fast $44.38. Published rates: https://developers.openai.com/api/docs/pricing . These are not subscription charges; preparation/post-resume closure tokens excluded.

Accepted ARM9 functions total 4,042 decoded assembly instruction lines and static cyclomatic estimate 399; excludes literal/directive lines. 3 functions have unresolved transfers, so complexity is not exact source-level complexity.

## Assignments

| Worker | Modules in assignment order |
|---|---|
| m01 | arm9/ov007 → arm9/ov009 |
| m02 | arm9/ov018 → arm9/ov012 |
| m03 | arm9/ov022 → arm9/ov008 |
| m04 | arm9/ov032 → arm9/ov015 |
| m05 | arm9/dtcm → arm9/ov005 |
| m06 | arm7/startup → arm9/ov006 |
| m07 | arm9/ov021 |
| m08 | arm9/ov033 → arm9/ov016 |
| m09 | arm9/ov034 → arm7/wram |
| m10 | arm9/ov019 |
| m11 | arm9/ov028 |
| m12 | arm9/ov030 |
| m13 | arm9/itcm |
| m14 | arm9/ov029 |
| m15 | arm9/ov020 |
| m16 | arm9/ov013 |
| m17 | arm9/ov011 |
| m18 | arm9/ov027 |
| m19 | arm9/ov014 |
| m20 | arm9/ov026 |

Seven reassigned workers resumed. m08 completed ov033 constructor recovery; ov016 reassignment could not launch due to the native thread limit before the account usage limit. Retain this idle time; do not imply 20 uninterrupted workers. Ov010 was skipped because prior full code/data completion was already proven. Ranking used initialized module size; BSS size can be much larger (ov032 has 663,552 BSS bytes).

## Unaccepted evidence and support changes

Frozen subsets remain in worker build/ready-*.json; ARM7 candidate manifests use candidate-arm7-*.json. Rejected groups are not credited. Blockers include linker abort/dead stripping, report-generator crashes on ITCM tables/BSS, incomplete source-data ownership, and supplementary symbol dependency schema mismatches. All rejected changing transactions rolled back and revalidated the accepted state. Encrypted ov029 executable ranges remain required work, not ordinary data or new assembly exceptions.

Zero-credit support changes: selected data-symbol addition/refinement capture/rollback, source-bound retained-data provenance for overlays without .text, ITCM/DTCM BSS routing/audit metadata parsing, and preservation of the original unused ov020 entry. 42 focused support tests passed before final validation; final source-symbol transaction tests also pass. BSS candidates remain unaccepted despite routing support. No acceptance checks were weakened.

Full measured records: build/modules-20261008-30min/result.json, token-accounting.json, agent-time-analysis.json, function-metrics.json, group-events.json and closure-events.json.
