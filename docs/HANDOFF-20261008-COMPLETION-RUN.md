# DQIX continuation wrap-up — 2026-10-08

Stopped at the user's request. All 20 Sol 6.1 low workers stopped safely and preserved their evidence. The project remains incomplete. No commits or pushes were made; HEAD remains `4c44373472ce77ac6462d7e082f2611ac56320e9`.

## Accepted progress

| Component | New functions | Code bytes | Literal bytes | Initialized data | BSS |
|---|---:|---:|---:|---:|---:|
| ARM9 | 495 | 82,792 | Included in existing report basis | 867 | 1,984 |
| ARM7 | 45 | 2,636 | 204 | 0 | 0 |

ARM9 totals are 5,239/14,790 matched functions (35.42%), 499,472/2,959,478 matched code bytes (16.88%), and 69,575/1,602,476 matched data bytes (4.34%). Fixed denominators are unchanged. The existing ARM9 data measure includes BSS; the separate initialized/BSS gains above sum to 2,851 bytes.

Ov010 has all three functions, 1,996 code bytes and 68 program-data bytes source-owned, with no local code/data fallback. Ov034 has all five functions, 2,224 code bytes, 28 initialized bytes and 1,952 BSS bytes accepted. Its remaining 12 original bytes comprise eight alignment bytes and a four-byte constructor terminator fallback.

Zero-credit improvements include module-aware and ARM7 transaction gates, frozen-source hashes, data/BSS audits, declarative source-data retention, rollback-safe receipts/dashboard, executable inventory, recovered interfaces, removal of two PatternAnimation assembly barriers, and replacement of three Cache MOV statements with C. No new assembly exception was approved.

Final USA ROM SHA1 is `c7c3014c237900c8281289b8bc76a781969b6278`. Every module/symbol/ROM check passed. All 546 ARM9 source audit entries and 44 ARM7 source entries passed hash checks. This was final incremental verification: no clean-build or gameplay smoke-test claim.

## Comparison with previous runs

| Run | Workers | Recorded wall window | New ARM9 functions | New ARM9 code bytes |
|---|---|---:|---:|---:|
| 02 | 2 Sol | 60.0 min | 591 | 34,580 |
| 03 | 10 Sol + 10 Luna | 55.1 min | 1,026 | 111,656 |
| Current | 20 Sol low | 104.4 min | 495 | 82,792 |

The current run had 90.5 minutes until the wrap-up request, then 13.9 minutes closing already-frozen acceptance and verification. Its first 60 minutes accepted 386 ARM9 functions, 62,948 code bytes and 587 data bytes, plus 12 ARM7 functions with 556 instruction and 40 literal bytes.

Raw code throughput was lower than run 03 despite higher runnable utilization. Remaining functions required more context, and four lanes handled verification, ARM7, data/BSS, and overlays/inventory. This is a comparison of different workloads, not a controlled Sol-versus-Luna benchmark. Run 03's recorded window also excluded initial worktree preparation.

Task division: c01–c16 handled ARM9 reconstruction, later including coherent overlays; c17 handled verification and assembly cleanup; c18 ARM7; c19 program data/BSS; c20 inventory and overlays. All current workers used Sol 6.1 low.

## Agent activity

Times below are summed agent-minutes, excluding the coordinator. Current activity is clipped at the wrap-up request, so closure time is not charged as worker idle time.

| Run | Runnable proxy | Awaiting tools | Not running/unlaunched |
|---|---:|---:|---:|
| 02 | 106.3 | 5.0 | 8.7 |
| 03 | 896.9 | 70.8 | 133.3 |
| Current | 1667.2 | 46.4 | 96.7 |

Current running turns were 97.3% runnable; runnable time occupied 92.1% of all 20 available slots. Of 46.4 agent-minutes awaiting tools, 3.4 were explicit waits and 43.0 other tool execution. Idle/unlaunched time was concentrated in c20, c17, c15 and c18. Earlier reassignment of finished engineering lanes would improve utilization.

| Agent | Runnable proxy | Awaiting tools | Not running/unlaunched |
|---|---:|---:|---:|
| c01 | 88.2 | 1.7 | 0.6 |
| c02 | 87.8 | 2.0 | 0.7 |
| c03 | 87.7 | 1.9 | 0.8 |
| c04 | 87.7 | 1.9 | 0.9 |
| c05 | 86.9 | 2.5 | 1.1 |
| c06 | 87.1 | 2.2 | 1.2 |
| c07 | 85.4 | 2.0 | 3.1 |
| c08 | 86.3 | 2.4 | 1.8 |
| c09 | 85.5 | 2.5 | 2.5 |
| c10 | 86.6 | 2.2 | 1.7 |
| c11 | 85.1 | 3.1 | 2.3 |
| c12 | 86.4 | 2.2 | 1.9 |
| c13 | 86.1 | 2.4 | 2.0 |
| c14 | 85.7 | 2.7 | 2.1 |
| c15 | 74.8 | 2.5 | 13.2 |
| c16 | 85.8 | 2.1 | 2.6 |
| c17 | 73.4 | 1.4 | 15.7 |
| c18 | 76.2 | 3.2 | 11.1 |
| c19 | 84.4 | 3.3 | 2.8 |
| c20 | 60.0 | 2.0 | 28.5 |

Method: task-start/task-complete intervals minus the union of emitted synchronous tool-call-to-output intervals. Runnable time includes provider scheduling, reasoning and generation; it is not measured model compute. Tool execution can be useful while blocking that agent. Worker command durations do not measure editing/reasoning and are not summed as active time. Full records are in `build/completion-20261008/wrapup-agent-time.json`.

## Outstanding work and resume state

Unmatched sources, original evidence, snapshots, ABI/assembly deferrals and timings remain in each `build/completion-20261008/cNN/project/build/` directory. Uncredited work includes eight Ov020 object matches (864 bytes) blocked by linking, Ov019's 3,024-byte body at 97.1%, a bit-shift domain candidate, and overlapping original symbol boundaries. ARM7 function/instruction denominators remain explicitly unknown. Opaque asset/script executable classification, clean-build verification and runtime smoke tests remain required.

Resume using `result.json`, `allocation.json`, `range-reservations.json`, `grouped-attempts.json`, and the support-adoption records under `build/completion-20261008/`. All workers and integrators are stopped. The original handoff remains `docs/HANDOFF-20261008.md`.
