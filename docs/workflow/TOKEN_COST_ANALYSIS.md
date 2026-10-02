# Measured token cost versus accepted progress

Window: 2026-10-02 12:07:00?12:37:00 UTC. Source: local Codex per-response
`token_usage_record` entries for this project, deduplicated by response ID.
Raw conversations and account credentials are not copied. The sanitized
[evidence](evidence/luna-token-cost-window.json) includes counts and assumptions.

## Token use

| Work | Fresh input | Cached input | Output including reasoning | Total tokens |
|---|---:|---:|---:|---:|
| Six Luna workers | 1,823,313 | 62,605,312 | 324,562 | 64,753,187 |
| Astra root/integrator | 151,133 | 11,424,512 | 22,354 | 11,597,999 |

97.17% of worker input was cached. Cached tokens are still tokens, but have a
lower rate; total-token counts alone are a poor cost comparison. Every measured
request had fewer than 272,000 input tokens. Reasoning output is already included
in output tokens and must not be charged again.

## Rate-card equivalents, not actual subscription charges

Official Standard short-context API rates per million fresh/cached/output tokens
are Luna $0.10/$0.01/$0.50 and Astra $10/$1/$50. Standard Codex credit rates
are respectively 2.5/0.25/12.5 and 250/25/1250 credits per million tokens.

| Work | Standard API equivalent, USD | Standard credit equivalent |
|---|---:|---:|
| Six Luna workers | $0.9707 | 24.27 |
| Astra integrator | $14.0535 | 351.34 |
| Combined | $15.0242 | 375.61 |

These are normalized estimates from measured tokens. They are not an invoice or
a conversion of the user's Pro allowance. Per-response tier billing is absent
from these usage records. Published Fast API/purchased-credit rates would double
these estimates where applicable; included subscription rules differ. The root
accounts for 93.54% of this normalized combined cost.

Sources checked 2026-10-02: [API pricing](https://developers.openai.com/api/docs/pricing)
and [Codex credit pricing](https://learn.chatgpt.com/docs/pricing).

## Accepted progress within the window

Luna contributed 24 ARM9 functions / 972 report-code bytes, two ARM7 C functions /
272 instruction bytes / 32 literal bytes, and 356 initialized-data bytes. Root
separately recovered 36 callback-data bytes and performed integration, review,
source-correctness fixes, unsuccessful compiler trials, reporting and clean-build
verification. Inventory/tooling gains are not counted as reconstructed bytes.

The worker-only equivalent is $0.78 per 1,000 accepted code bytes when combining
ARM9 report code with ARM7 instruction bytes (1,244 bytes total). Including root
work gives $12.08 per 1,000 such bytes. Both ratios include data and inventory
work in the numerator, and neither weights task difficulty or forecasts the cost
of finishing the game. ARM9 report code can include literal bytes; ARM7 literals
and data are kept separate here. Workers' failed and in-progress attempts remain
included in the measured cost.

There is no matched-task Astra baseline. The evidence establishes that Luna is
much cheaper per token and delivered accepted work, not that it needs fewer
tokens or less time for the same task. At the same token mix, its listed rate is
100 times lower. A claim of a measured 100-times project saving would be false.

## Workflow implication

Keep Luna on bounded reconstruction and evidence tasks, with required exact-object
and combined ROM verification. Reduce expensive integrator prompt cycles by
reviewing compact, complete handoffs and integrating related batches together.
A Sol 6.1 reviewer/integrator is worth a controlled trial: its Standard rate is
$2 fresh / $0.10 cached / $10 output per million tokens. Applying that rate to this
root token mix gives $1.67 instead of $14.05, but equal token use and equal review
quality are hypothetical, not measured. Source acceptance must stay unchanged.

## Historical ARM7 worker comparison

The [separate evidence](evidence/arm7-model-progress-cost.json) links the Astra
ARM7 worker's first batch parent through `968dbf8` to its local per-response token
history, and Luna's three accepted ARM7 source commits through 12:37 UTC to its
history. These are unequal task histories, not a controlled benchmark.

| Worker | C functions added | Instruction bytes added | Total recorded tokens | Standard API equivalent |
|---|---:|---:|---:|---:|
| Astra ARM7 | 186 | 15,308 | 54,607,424 | $73.5731 |
| Luna ARM7 | 3 | 304 | 17,529,787 | $0.2810 |

Astra also added 1,064 literal bytes and 468 initialized-data bytes; Luna added 36
literal bytes. Neither literals nor data are included in the instruction metric.
The historical Astra branch produced 16.16 times more instruction bytes per
recorded token. Luna's lower listed rate nevertheless yields 5.20 times more
instruction bytes per normalized dollar: $0.924 versus $4.806 per 1,000 instruction
bytes. Root review/integration is excluded, and Luna's disassembly tooling and
layout investigations are included in its token costs but have no source-byte
credit. These caveats prohibit interpreting the ratios as model-only causation
or equal-task speed. They support testing a mixed workflow rather than assuming
that the cheapest model also maximizes progress per token or elapsed time.


## First Sol 6.1 window after the requested switch

Six Sol 6.1 workers replaced the stopped Luna workers on October 2. The new
[evidence](evidence/sol61-token-cost-window.json) covers 13:11-13:41 UTC, the same
30-minute duration as the earlier Luna window. Historical model metadata, unique
response IDs and accounting checks passed; no request exceeded 272,000 inputs.

| Observed measure | Earlier Luna window | First Sol 6.1 window |
|---|---:|---:|
| Worker tokens including cached input | 64,753,187 | 34,782,901 |
| Worker Standard API equivalent | $0.97 | $7.04 |
| Root Standard API equivalent | $14.05 | $8.67 |
| Combined equivalent | $15.02 | $15.71 |
| Accepted ARM9 + ARM7 functions | 26 | 30 |
| Accepted ARM9 report-code + ARM7 instructions | 1,244 bytes | 2,104 bytes |
| Combined equivalent per 1,000 accepted code bytes | $12.08 | $7.47 |

Sol's column includes eight already-matching Luna functions / 180 code bytes.
Excluding those leaves 22 functions / 1,924 newly matched code bytes and $8.16
combined equivalent per 1,000 bytes, about 32% below the earlier window. This
still includes finishing an unmatched Luna IPC-handler draft; it is not a claim
of exclusively Sol-authored source. Worker-only equivalents are $3.66 versus
$0.78 per 1,000 such bytes: the saving appears in overall integration output,
not in the worker-only rate.

Sol also repaired inherited graphics table drafts, accepting 16,496 data bytes,
and added 128 initialized-data bytes and 60 BSS bytes. These remain separate from
the code comparison. Tooling, type corrections, failed attempts, pending work,
idle time and review delays are included in token costs. Smaller new contexts,
root compaction and batching also affect the comparison. Therefore these are
observed workflow results, not a controlled model benchmark or a completion-cost
forecast. Neither dollar figure represents actual Pro-plan charges or allowances.
