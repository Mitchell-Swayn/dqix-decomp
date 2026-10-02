# ARM7 power receive and sleep

Worker: `work/arm7-power-events`, baseline `6c28cf4`. Sol 6.1 continuation
started at 2026-10-02T13:12:10Z. The independent original ROM copy verified
SHA-1 `c7c3014c237900c8281289b8bc76a781969b6278`. The worktree had no
ARM9 report or generated ROM, so a valid `work_batch.py start` snapshot could
not be taken. This worker records UTC time honestly; the integrator owns the
complete-ROM batch measurements and acceptance.

## Source reconstruction

- `PowerSleep.c`: `[0x038061fc, 0x038063a0)`, 404 instruction bytes and
  16 literal bytes. Four candidate compiles reached the exact original bytes.
  It saves interrupt and power state, configures the selected wake sources,
  invokes the existing BIOS sleep veneer, restores power/GPIO state, clears
  the operation flag and sends the wake notification. Both observed IME reads
  before restoring the register are retained. The two consecutive LED-mode
  calls are also retained. The veneer at `0x038063a0` remains outside this unit.
- `PowerIpcReceive.c`: `[0x03805b0c, 0x03805c4c)`, 304 instruction bytes and
  16 literal bytes. Bit 25 clears the sixteen halfword slots; bits 16..19 select
  a destination slot; bit 24 dispatches commands from slot zero. Reset commands
  retry IPC transmission; other commands enqueue type-3 SPI tasks and report
  queue failure. This continuation matched in one compile after new evidence
  from the sleep function justified a typed interior state view.

The inherited Luna IPC attempt had reached ten variants and was deferred with
seven register-allocation differences. It was not blindly repeated. The sleep
reconstruction established that the slots and operation have an independently
addressed view beginning at `0x0380b770`, four bytes into `PowerState` at
`0x0380b76c`. `PowerState.h` now declares `PowerRequestState` once and embeds
that same type as `PowerState.request`. The linker symbol `ARM7_PowerRequest`
denotes this real subobject; it is not a second storage allocation. The IPC
handler uses the subobject for clearing/writing slots and the enclosing state
for dispatch reads, preserving the original two base-address lifetimes.
Existing `PowerStateInit.c` and `PowerTask.c` access the explicit member and
still compile byte-exact. The 40-byte outer and 36-byte inner sizes are checked.

## Deferred dependency

SPI enqueue `[0x03804d90, 0x03804e70)` was compiled in three variants. The
closest was 220 bytes against the original 224, with 42 differing words.
The original loop uses a separate address add and an interior base literal;
the candidate instead uses an indexed store into the typed task array. The
variadic count and 24-byte task layout remain established by callers. The
unmatched draft and verbose diffs remain under ignored
`build/arm7-power-events/SpiEnqueue/`; no manifest range or source credit was
retained. Recover the full service-storage layout before trying a new model.

The two sound power candidates were already owned by `SoundMaster.c`.
Manifest overlap validation caught the duplication before acceptance; those
candidates were removed and add no coverage.

## Verification

The complete ARM7 build compiles every configured unit, checks all declared
linked symbols and compares the entire 167,876-byte payload against the verified
original. Worker logs are under ignored `build/arm7-power-events/` and the
verified report is `build/arm7-power-events-accepted/report.json`.
The 11 ARM7 pipeline, six original-payload verification and 11 dependency tests
all pass, including the real pinned-compiler/Ninja nested-header rebuild test.
The resulting report records 269 C functions, 23,892 instruction bytes, 1,652
literal bytes, 1,332 initialized data bytes, 3,512 BSS bytes and 120 reviewed
assembly bytes. The payload SHA-1 remains
`a662d5c6a78e990244299926cf6862ce910a475d`.
Full ROM/module/SHA-1 acceptance remains the integrator's responsibility.
No runtime sleep/wake test was performed in this worker.

New coverage: two C functions, 708 instruction bytes, 32 literal bytes,
740 fewer fallback bytes. No data, BSS or assembly credit was added.
Token usage is unmeasured.
