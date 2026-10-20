# Decompilation run wrap-up — 2026-10-08 UTC

Accepted **341 ARM9 functions + 8 ARM7 functions**. Added 60,156 ARM9 code bytes, 71,043 initialized data bytes and 20,717 BSS bytes. ARM7 added 184 instruction bytes and 48 literal bytes.

Work interval: 2026-10-08T12:50:00.364748+00:00 to 2026-10-08T13:35:03.989000+00:00 (45.06 minutes). Closing validation ended 2026-10-08T14:17:08.307451+00:00. Native workers wrapped; remaining T3 tasks received cancellation at 2026-10-08T13:44:48.026Z. Closing results are included in accepted totals, with 214 ARM9 functions accepted before the user cutoff and 127 afterward.

Final ARM9 coverage: 5,777/14,790 functions, 19.655% code and 10.293% report data (including BSS). Full decompilation remains incomplete.

Full ROM/module/symbol checks pass; ROM SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. 1,851 frozen source hashes checked. Fourteen relocation support tests pass. This closure did not perform a fresh clean build or runtime gameplay tests.

## Run comparison

| Run | Recorded elapsed minutes | ARM9 functions | Code bytes | Tokens | Standard API-equivalent USD | Estimated total CC | Assembly instruction lines |
|---|---:|---:|---:|---:|---:|---:|---:|
| 01 | 60.15 | 1,058 | 46,068 | 74,052,885 | $12.89 | 1,732 | 11,223 |
| 02 | 59.99 | 591 | 34,580 | 70,526,322 | $12.94 | 1,063 | 8,202 |
| 03 | 54.16 | 1,026 | 111,656 | 683,739,059 | $45.06 | 2,907 | 26,937 |
| completion | 104.40 | 495 | 82,792 | 715,203,545 | $115.13 | 2,108 | 20,587 |
| 20 Sol modules | 30.00 work; closure extra | 176 | 16,432 | 123,133,978 | $22.19 | 399 | 4,042 |
| 4 Sol efforts | 28.02 work; closure extra | 21 | 5,612 | 49,309,340 | $8.51 | 147 | 1,377 |
| This run | 87.13 total (45.06 work + 42.07 closure) | 341 | 60,156 | 412,377,880 | $73.14 | 1,411 | 14,343 |

Comparison totals include accepted closure functions where available; historical token windows differ. Completion also added 45 ARM7 functions, module run added 2, this run added 8. Queues, concurrency, data focus and difficulty varied; these are not controlled model/effort benchmarks. CC is an assembly CFG estimate (E−N+2), not measured source complexity; unresolved indirect transfers are recorded in the detailed metrics. Instruction lines exclude literals/directives.

Current work-window tokens: Sol 386,191,525; Claude 26,186,355. Standard API-equivalent cost: Sol $65.029343, Claude $8.106549, total $73.135892. Sol closure adds $11.411207; total through accounting snapshot 2026-10-08T14:17:20.917420+00:00 is $84.547099 (487,523,938 tokens). These estimates are not subscription charges. Sol service tier is unrecorded, so standard rates are used. All ten Claude tasks did real requests before failing; native request IDs and cache TTLs reconcile their measured usage.

[OpenAI rates](https://developers.openai.com/api/docs/pricing): Sol input $2/M, cached input $0.10/M, output $10/M. [Claude rates](https://platform.claude.com/docs/en/about-claude/pricing): Sonnet 5.5 input $2/M, cached input $0.10/M, output $10/M, 1-hour cache writes $4/M. Measured Claude writes used 1-hour TTL; Sol cache writes were zero.

Worker timing within the work interval: 940.57 agent-minutes with open turns, 29.68 awaiting visible tool calls, 910.88 residual. These are overlapping concurrent agent times. Residual includes model/provider scheduling and asynchronous waits that logs cannot separate; it is a proxy for availability, not a direct measurement of active inference. Completed-turn idle gaps are excluded. Per-session/worker records are in run-accounting.json.

## Accepted by worker

| Worker | ARM9 functions | Code bytes | Initialized data | BSS | Estimated CC | Assembly lines |
|---|---:|---:|---:|---:|---:|---:|
| n01 | 1 | 1,204 | 0 | 0 | 4 | 297 |
| n02 | 4 | 1,620 | 0 | 0 | 40 | 315 |
| n03 | 3 | 772 | 0 | 0 | 20 | 191 |
| n04 | 5 | 1,072 | 0 | 0 | 24 | 251 |
| n05 | 8 | 3,628 | 0 | 0 | 89 | 851 |
| n06 | 2 | 912 | 0 | 0 | 30 | 223 |
| n07 | 4 | 1,780 | 0 | 0 | 44 | 393 |
| n08 | 9 | 1,028 | 0 | 0 | 25 | 250 |
| n09 | 8 | 1,052 | 0 | 0 | 30 | 255 |
| n10 | 10 | 2,572 | 0 | 0 | 50 | 629 |
| n11 | 7 | 1,640 | 0 | 0 | 45 | 382 |
| n12 | 0 | 0 | 25,336 | 0 | 0 | 0 |
| n13 | 0 | 0 | 26,421 | 3,093 | 0 | 0 |
| n14 | 0 | 0 | 9,449 | 0 | 0 | 0 |
| n15 | 0 | 0 | 6,191 | 0 | 0 | 0 |
| n16 | 0 | 0 | 3,142 | 0 | 0 | 0 |
| n17 | 19 | 4,172 | 504 | 0 | 91 | 1,029 |
| n18 | 175 | 16,216 | 0 | 0 | 386 | 3,996 |
| n19 | 8 | 864 | 0 | 17,624 | 18 | 209 |
| n20 | 0 | 0 | 0 | 0 | 0 | 0 |
| v01 | 3 | 4,844 | 0 | 0 | 137 | 1,114 |
| v02 | 11 | 536 | 0 | 0 | 16 | 113 |
| v03 | 8 | 2,044 | 0 | 0 | 42 | 502 |
| v04 | 8 | 880 | 0 | 0 | 20 | 208 |
| v05 | 12 | 2,104 | 0 | 0 | 47 | 511 |
| v06 | 5 | 1,444 | 0 | 0 | 42 | 355 |
| v07 | 3 | 1,204 | 0 | 0 | 25 | 295 |
| v08 | 5 | 3,248 | 0 | 0 | 61 | 800 |
| v09 | 12 | 2,316 | 0 | 0 | 51 | 530 |
| v10 | 11 | 3,004 | 0 | 0 | 74 | 644 |

n20 ARM7 is accounted separately above. Initial 20 Sol lanes comprised 11 main code, five data and four closure/ARM7 workers. Ten Claude lanes later resumed with Sol low; two received another bounded allocation before wrap-up. No new decompilation was assigned after the wrap instruction; two native workers only helped prepare accounting reports.

21 failed/preflight attempts were not credited. Some were superseded by successful corrected manifests; see result.json. One candidate duplicated a previous run and was excluded. n16 final data groups failed full checks; remaining individual candidates were preserved for layout isolation rather than all retried during closure. ITCM tables (356 bytes) remain blocked by report classification and are uncredited; unresolved candidates retain worker evidence. Five data lanes covered ov016/ov000/ov025, ov031/ov002, main, ov023/ov024/ov003/ov004/ov006 and ov017/ov001/ov015.

Source-bound relocation handling now permits only explained numeric false loads in selected initialized data. It verifies original extents and hashes, preserves unrelated maps, and rolls back failed transactions. Coverage denominators remain unchanged. All acceptance ran through the project-wide integration lock and mandatory gates.

Artifacts: result.json, integration-events.json, final-verification.json, n11/project/build/accepted-arm9-report.json, n09/project/build/run-accounting.json and accounting-provenance-audit.json. Worker worktrees and immutable ready manifests are preserved. No commits or pushes were made.

## Agent activity comparison

| Run | Work minutes | Worker non-tool proxy, agent-min | Visible tool wait, agent-min | Usage-limit blocked, agent-min |
|---|---:|---:|---:|---:|
| 20 Sol modules | 30.00 | 262.49 | 19.85 | 235.01 |
| 4 Sol efforts | 28.02 | 105.91 | 3.72 | 0.00 |
| This run (Sol) | 45.06 | 910.88 | 29.68 | Not measured separately |

Timing covers Sol workers; Claude failure/usage evidence is separate. Historical runs used similar turn/tool proxies but different blocked/idle classification. The module run lost most workers to quota errors partway through. This run used 30 distinct Sol worker lanes, with staggered starts and completed-worker idle periods excluded; two additional rounds reused lanes. Native reading/preparation outside the recorded interval and exact provider-scheduling/inference time are not recoverable. Current work interval lasted 45.06 minutes; closing integration/validation lasted 42.07 minutes, total 87.13 minutes from recorded start.
