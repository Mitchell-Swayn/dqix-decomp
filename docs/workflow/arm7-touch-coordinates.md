# ARM7 filtered touch coordinate reader

Baseline: `b32eae3`; independent `work/arm7-power-events` worktree. Main ownership
was checked before choosing the filter, coordinate reader, controller-status
storage and diagnostic strings. Dashboard heartbeat records activity only.
Local work started 2026-10-02 15:15:56 UTC and verification finished 15:28:29 UTC:
753.641566 seconds. The worker has no baseline full ARM9/ROM reports; main
`work_batch.py` accounting remains integrator-owned.

## Exact source and program data

`TouchCoordinates` matches `[0x038058c0,0x03805ad0)`: 496 instruction bytes and
32 literal bytes. It normalizes the filter threshold, reads initial controller
status, samples both axes, drains twelve SPI bytes, and reconciles the final
status. The result retains the original 12-bit coordinate fields, touch flag
and two invalid-axis bits. For a stable touch, it reports the larger axis spread.
Three source variants were compared; the final strict conditional selection
uses `xSpread >= ySpread ? xSpread : ySpread`, preserving the original equality
branch as well as register allocation. Defining its real BSS status variable
was checked in a fourth object comparison and full placement verification.

The reader owns the two-byte `unsigned short ARM7_TouchControllerStatus` at
`[0x0380b768,0x0380b76a)`. The existing main controller-status reader declares
the same type. This lies immediately after the declared TouchState scanline
array, and is a separate scalar allocation, not an incompatible state view.

`TouchSourceFile` owns the fourteen-byte `tp_sampling.c` string at `0x03808d20`.
`TouchStateError` owns the twenty-five-byte `Illegal Touch Parameter\n` string
at `0x03808d30`. The intervening two alignment bytes and trailing three bytes
remain fallback. A combined candidate linked exactly, but the current pipeline
requires input section sizes to equal owned bytes and rejected the combined
alignment gap. Splitting the two actual string objects into separate units
resolved that without modifying the verifier or counting linker padding as data.

## Deferred required dependency

`TouchFilterAxis` `[0x038056d0,0x038058c0)` remains fallback: 476 instruction
bytes and twenty literal bytes. Ten candidates were compared. The nearest had
the correct 496-byte size with 21 differing words; the final scope experiment
had 26 differing words. In the last three candidates the five-measurement SPI
sequence matched exactly. Remaining differences concern registers for the
pairwise spread loops and weighted-triple selection. Tested choices included
MMIO conversion widths, command-byte lifetime, do/for forms, scoped loop
counters and conditional-expression absolute values. At the cap, work switched
to the coordinate reader. The final draft, object and disassembly comparison
are under ignored `build/arm7-power-events/TouchFilterAxis/`.

A retry needs new source-level lifetime or compiler allocation evidence. Neither
an instruction/register substitution nor another loop-spelling sweep is accepted.
TouchTask remains deferred with the previous two scheduling-word differences;
SPI enqueue remains at five variants. Neither was retried here.

## Verification and local delta

All candidate accepted units are exact. The full ARM7 module/source-symbol/BSS
placement checks pass; 167,876 payload bytes have unchanged SHA-1
`a662d5c6a78e990244299926cf6862ce910a475d`. The independent original ROM input
was reverified as `c7c3014c237900c8281289b8bc76a781969b6278`. All 28 pipeline
tests pass. Logs remain under ignored `build/arm7-power-events/touch-coordinates-*`.

Local delta: +1 C function, +496 instruction bytes, +32 literal bytes, +39
initialized data bytes, +2 BSS bytes, -567 fallback bytes; assembly unchanged.
Worker totals: 276 C functions, 25,592 instruction bytes, 1,776 literals, 1,371
initialized data bytes, 4,914 BSS bytes, 120 reviewed assembly bytes, and 139,017
fallback bytes. Main totals and full ROM acceptance remain integrator-owned.
Matching verifies the build, not runtime touch behavior.

Timing/deltas: [local evidence](evidence/arm7-touch-coordinates-worker.json).
