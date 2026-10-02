# Model pilot record

The user authorized a Luna trial on 2026-10-02. Earlier recommendations were
hypotheses: no previous batch was a Luna benchmark. Historical batch intervals
include integration and already-running workers, so they cannot establish a
controlled Astra throughput baseline.

## Initial pilots

- `luna_vram_pilot`: GPT-6 Luna, high reasoning, compact task packet and isolated
  worktree. Reconstruct four default VRAM callback globals (16 initialized data
  bytes), preserving caller ABI and matching code. Shared-header investigation
  and setup time count toward the pilot. Root reviews and integrates separately.
- `luna_build_review`: GPT-6 Luna, high reasoning, independent read-only review
  and focused tests of the existing incremental delink patch `043fe8e`.
  This measures review usefulness, not new decompiled code.

Record elapsed time, attempts, accepted bytes/functions, issues found, and root
corrections. Leave token usage and financial cost unknown unless measured. Do not
equate API list pricing with subscription consumption. One successful small
batch does not establish suitability for difficult compiler matching.

## Local runtime preparation

The user configuration was backed up before setting
`agents.max_concurrent_threads_per_session = 6`, default subagent model
`gpt-6-luna`, and high subagent reasoning. This is a requested configuration,
not proof that this already-running session acquired additional slots.

The separately installed npm Codex CLI was updated from 0.155.1 to 0.160.0;
version and configuration parsing were checked. The desktop app's bundled
executable still reports 0.155.0-alpha.9.2. Updating the npm CLI does not update
that bundled executable or the active session's exposed model list. GPT-6.1 Sol
is documented but is not an available model override in this session.

## First review result

The Luna build reviewer ran from 09:41:28 to 09:42:49 UTC (81 seconds),
reported no findings, and passed all five focused tests. An initial unittest
module invocation failed due to import path; direct script invocation passed.
It independently checked the existing clean-build and recovery evidence and
left the worktree unchanged. Root acceptance remains a separate step.

Root subsequently integrated the reviewed patch, reran all five tests and full
acceptance, and completed a fresh locked-toolchain build of `c4da8d4`. All passed.
The repeat acceptance invocation ran verification checks without rebuilding the
ROM. Clean-build evidence is archived in `docs/verification/delink-outputs-clean-build.*`.

## First reconstruction result

The VRAM pilot was integrated and passed combined module, symbol, ARM7 and exact
ROM SHA-1 checks on main. Gain: 16 initialized data bytes, zero functions/code.
All 47 affected symbols matched in the worker comparisons. The measured batch
window was 479.478333 seconds, excluding initial setup and root integration.
One root review correction required consistent allocator flag types and shared
declarations. Compiler/setup failures are recorded in `luna-vram-pilot.md`.

This establishes useful bounded work, not a controlled speed/cost advantage over
Astra. Token usage remains unknown. The next trial should reconstruct a small
function family, with setup prepared before dispatch and whole-task timing.

## Runtime setup incident

The second reconstruction pilot linked its writable ROM output and input to the
main generated ROM. Its build temporarily overwrote that shared output. The
worker reported the error and restored matching bytes before root inspection.
Root confirmed the original extract/baserom_dqix_usa.nds was intact, then replaced
all four linked paths with independent copies of the verified original input.
The old VRAM pilot input was also linked to that generated output and was fixed.
All repaired files have one link, distinct identities, and the target SHA-1.
The runtime worker was stopped during repair and resumed afterward. This is a
material setup failure and root intervention, not successful autonomous recovery.

The world reviewer inspected eight historical commits without changing the dirty
worker tree. It flagged the grotto coordinate-to-vector cast and a persistent
GameState table at an incompletely mapped offset. Root pinned those commits by
integrating them and rerunning full acceptance on main; all module/symbol/ROM
checks passed. This is review/integration of earlier Astra work, not Luna source
reconstruction credit. The two source-layout caveats remain follow-up work.
