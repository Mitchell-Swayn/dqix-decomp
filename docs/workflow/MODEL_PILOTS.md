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

Root resolved the grotto coordinate alias concern by representing the existing
12-byte coordinate region as an actual Vector3i field. Both affected functions
remain100% object matches and full combined ROM/module/symbol checks passed.
The persistent GameState table offset remains a documented mapping limitation.

## First function pilots accepted

Root integrated both function pilots and passed combined module/symbol/ARM7/ROM
SHA-1 checks. ARM7 e00046d adds one function,32 instruction bytes,4 literal bytes
after685 seconds including investigation. An initial runtime-to-payload mapping
omitted the540-byte startup prefix; exact comparison rejected those drafts.
The GameState pilot9c2d576 adds four functions/32 instruction bytes; all four
first candidates match. Its616.72-second whole-task interval includes setup and
the hardlink incident. Neither interval includes root integration/review cost.
These small samples do not establish a cost/speed advantage over Astra.

Next trials deliberately reduce discovery/setup work: six preselected GameState
helpers with established boundaries, plus a manifest-driven ARM7 disassembly
utility. The latter provides tooling rather than source coverage.

The prepared second GameState batch809e1f3 added six functions/96 report code
bytes (84 instructions,12 literals). All six matched on their first candidates.
Whole-task time330seconds includes setup/checks; root integration is additional.
Root reviewed it, used existing field names instead of raw-offset arithmetic,
and passed combined acceptance. This is encouraging for preselected small
functions, but the tasks differ from the earlier trials.

## Prepared world task isolation correction

The world worker used relative apply_patch paths after an absolute-path patch
failed to match context. The relative writes landed in main (three new candidate
files and three delink blocks). The clean-worktree integration guard stopped
subsequent integration. Root halted the worker, verified the exact delta, moved
only those candidates into the intended worker checkout, and restored main.
No unrelated source was changed. The worker resumed with absolute write paths.
This is a second material orchestration failure in the Luna trials.

The ARM7 disassembly helper also required root correction: aggregate instruction
and literal byte counts cannot locate bytes inside multi-function units. The
corrected tool reports raw decoding for mixed units and passed15 tests on main,
including an interleaved-literal regression. No source coverage comes from it.
