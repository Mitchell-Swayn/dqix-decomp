# ARM7 touch worker and alarm callback

Baseline: `d936bbc`; independent `work/arm7-power-events` worktree. Main ownership
was checked before choosing TouchTask and its alarm callback. Candidate work
started at 2026-10-02 14:10:52 UTC; verification finished at 14:35:32 UTC
(1,480.220194 seconds). Full-ROM batch accounting remains integrator-owned;
this worker lacks a baseline full ARM9/ROM report and records the interval honestly.

## Accepted source and storage

`TouchAlarmCallback` at `[0x03805550,0x038055b8)` matches all 104 bytes: 100
instruction bytes and four literal bytes. It queues command 0x10 and the alarm's
sample index. A full queue publishes a touch sample with both coordinates marked
invalid, then replies with the low byte of that index. Four candidate variants
were compared. Using the actual shared-memory address `0x027fffaa` rather than a
linked external variable removed the last register allocation differences.

The failure path only initializes the invalid flags. The original instructions
preserve the other bits of the stack word before publishing it; coordinate and
reserved bits are unspecified on this path. The source represents that behavior
with a partly initialized sample union. This deserves review as an original
uninitialized-value behavior, not a claim that all published bits are initialized.

TouchState now owns one contiguous 216-byte allocation at `0x0380b690`.
Its actual request subobject begins at +4 (`0x0380b694`), contains the protocol
slots, operation, thresholds, four 40-byte VerticalAlarm objects, and four signed
scanlines. The alarms begin at `0x0380b6c0`; scanlines occupy
`[0x0380b760,0x0380b768)`. Original TouchTask stores and sign-extending loads
establish this final array. TouchRequest and TouchAlarms remain linker aliases
to their actual declared subobjects. There are no incompatible aggregate externs
or unrelated-struct casts. TouchInitialize owns the complete allocation; its
former separate alarm allocation has become the explicit nested array. Existing
TouchInitialize and TouchIpcReceive instruction/literal bytes remain exact.

## Deferred required function

TouchTask `[0x0380525c,0x03805550)` remains original fallback: 728 instruction
bytes and 28 literal bytes. Ten initial compiler invocations produced nine
objects and one C90 syntax failure. The closest initial object had the correct
756-byte size and seven differing ARM words. Work switched to the callback.
The callback's concrete shared-memory-address evidence justified two followups:
the constant-address sample publication removed five differences; narrowing the
reply prototype did not remove the remaining two. The unmatched draft and
object/disassembly evidence are under ignored `build/arm7-power-events/TouchTask/`.
No TouchTask source credit or extra assembly was accepted.

Remaining words are an instruction scheduling swap with the same operands:

```text
038053fc: and r1, r1, #0xff -> lsr r0, r0, #0x10
03805400: lsr r0, r0, #0x10 -> and r1, r1, #0xff
```

Do not restart blind variants. SPI enqueue remains required and stays at five
documented variants; it was not retried in this batch.

## Verification and local delta

Independent original input SHA-1:
`c7c3014c237900c8281289b8bc76a781969b6278`.
Full ARM7 build, module checks, source symbols and BSS placement pass; all
167,876 payload bytes remain exact, SHA-1
`a662d5c6a78e990244299926cf6862ce910a475d`.
The three pipeline suites pass 28 tests. Verbose logs are ignored under
`build/arm7-power-events/touch-worker-*`.

Delta: +1 C function, +100 instruction bytes, +4 literal bytes, -104 fallback
bytes, +8 BSS bytes; initialized data and necessary assembly unchanged.
Worker totals are 275 C functions, 25,096 instruction bytes, 1,744 literal bytes,
1,332 initialized data bytes, 4,912 BSS bytes, 120 reviewed assembly bytes and
139,584 fallback bytes. These are worker totals, not main headline counts.
Full ROM integration and runtime alarm/sample behavior remain integrator work.

Timing/deltas: [local evidence](evidence/arm7-touch-worker-worker.json).
