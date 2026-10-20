# Four Sol reasoning levels — run stopped at user request

Window: 2026-10-08T12:20:23.873391+00:00 to 2026-10-08T12:48:25.323430+00:00. Default main dependency/context queue; four independent worktrees; one serialized full-ROM integrator.

| Effort | Accepted functions | Code bytes | Assembly instruction lines | Cyclomatic estimate | Runnable agent-min | Awaiting tools min | Total tokens | Standard API-equivalent USD |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| low | 7 | 1776 | 438 | 41 | 26.82 | 0.89 | 13,709,028 | $2.228 |
| medium | 4 | 652 | 159 | 18 | 26.56 | 0.94 | 10,336,347 | $1.834 |
| high | 3 | 1428 | 353 | 46 | 26.17 | 1.14 | 10,729,291 | $1.889 |
| xhigh | 7 | 1756 | 427 | 42 | 26.36 | 0.74 | 8,009,152 | $1.634 |

Total accepted ARM9: {'functions': 21, 'code_bytes': 5612, 'data_bytes': 0, 'bss_bytes': 0, 'assembly_instruction_lines': 1377, 'cyclomatic_complexity_estimate': 147}. ARM7 unchanged. ROM SHA1 `c7c3014c237900c8281289b8bc76a781969b6278`; all incremental module/symbol/ROM checks pass. No clean-build or runtime claim. No commits/pushes.

Total including coordinator: 49,309,340 tokens; $8.512 Standard API-equivalent, $17.024 Fast equivalent. These are rate estimates, not subscription charges. Cached tokens are included in input; reasoning tokens included in output. Source: https://developers.openai.com/api/docs/pricing .

Agent running-turn intervals, minus union of outstanding synchronous tool-call intervals, clipped to recorded run window. This remainder is a runnable-time proxy, not measured model compute. It includes provider scheduling, reasoning, output generation and unrecorded stalls. Tool execution is useful work but blocks this agent while awaiting return. Async work after a yielded return is not charged as blocked until a subsequent wait call. Not-launched and completed intervals are separate from blocked time.

Assembly lines count decoded original instructions, excluding literals/directives. Cyclomatic complexity is a static CFG estimate; indirect transfers and assembly conventions limit precision.

Successive ordered queue batches differ in difficulty; observational throughput, not a controlled reasoning-effort benchmark.

Prior 20-low smallest-module run accepted142 ARM9 functions/13240 code bytes/3609 data bytes within30min, followed by34 functions/3192bytes closure and2ARM7 functions. It had262.5 runnable agent-min,19.9 awaiting tools and235 usage-limit-blocked agent-min;123.134Mtokens/$22.19 API-equivalent. Queues and concurrency differ.

Current project ARM9: 5436/14790 functions; 521516/2959478 code bytes; 73184/1602476 data bytes. Project remains incomplete.

## Prior runs

| Run | Total tokens | Standard API-equivalent USD | Accepted assembly instruction lines | Cyclomatic estimate |
|---|---:|---:|---:|---:|
| 01 | 74,052,885 | $12.89 | 11,223 | 1,732 |
| 02 | 70,526,322 | $12.94 | 8,202 | 1,063 |
| 03 | 683,739,059 | $45.06 | 26,937 | 2,907 |
| completion | 715,203,545 | $115.13 | 20,587 | 2,108 |

Accepted before deadline: {'functions': 20, 'code_bytes': 5464, 'data_bytes': 0, 'bss_bytes': 0}. Any in-flight transaction finished during closing validation: {'functions': 1, 'code_bytes': 148, 'data_bytes': 0, 'bss_bytes': 0}.
