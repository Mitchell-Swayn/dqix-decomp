# Luna ARM7 pilot

- Started: `2026-10-02T10:15:56Z`, before inspection.
- Worktree: `../DQIX-Decomp-arm7-batch`, branch `work/arm7-batch`, starting
  revision `968dbf885fd05de30a4326e8f7b419ee2229b97d`.
- Initial status: tracked worktree clean; pre-existing untracked compiler `.d`
  files were left untouched. `docs/workflow/README.md` and
  `tools/work_batch.py` were absent at this revision; the workflow README was
  read from the integrator checkout. The requested `work_batch.py start` could
  not run in this worktree. Elapsed time is recorded manually below.

The selected helper is the short SPI byte-clock routine immediately called by
the touch command path at `0x038056ac`. It writes a zero halfword to the SPI
data register, waits while the control register's busy bit is set, and returns.
The volatile accesses, register addresses, and matching existing
`TouchSpiClock` helper establish the necessary types and behavior. The source
and source-unit manifest add one function and no shared declarations.

An early touch-dispatch candidate set was rejected before source integration.
The first disassembly read omitted the 540-byte startup portion of the ARM7
payload when mapping runtime addresses to file offsets. Candidate boundaries
were therefore wrong; exact object comparison exposed the error. Those trial
sources and manifest edits were removed. With the corrected mapping, the touch
handlers nearby contain substantially larger stateful routines with unresolved
layout questions. The adjacent power sleep helper at `0x038061fc` is also a
large routine with additional hardware and scheduling dependencies, so it was
left untouched.

Coverage delta from the starting manifest:

| Measure | Before | After | Delta |
| --- | ---: | ---: | ---: |
| ARM7 functions | 264 | 265 | +1 |
| Instruction bytes | 22,880 | 22,912 | +32 |
| Literal-pool bytes | 1,584 | 1,588 | +4 |
| Initialized data bytes | 1,332 | 1,332 | 0 |
| BSS bytes owned by source | 3,512 | 3,512 | 0 |
| Binary fallback bytes | 141,960 | 141,924 | -36 |

Validation: `tools/arm7_build.py` passed against the USA base ROM and pinned
MWCC. It compared and linked every configured source unit, verified every
source symbol, and reported the original ARM7 payload SHA-1
`a662d5c6a78e990244299926cf6862ce910a475d`. The ARM7 pipeline tests passed
(11/11). The transitive dependency/header tests passed (10 passed, one skipped
because the test requires pinned Windows MWCC and Ninja). No full ROM build was
run in this worker; the integrator owns that check.

The pilot ended after one exact, small helper. Remaining ARM7 functions and
their code/data denominator are unchanged. Token usage was not measured.

Elapsed wall time: 685 seconds from recorded start to the final validation pass.
