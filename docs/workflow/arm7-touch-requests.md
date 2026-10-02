# ARM7 touch initialization and IPC requests

Worker baseline: `66374fa`. Candidate iteration began at
2026-10-02T13:53:13Z. The independent original ROM input remains verified.
The main ownership map showed no existing owner for either new code range or
the touch-state/vertical-alarm BSS allocation. Root owns main queue state,
headline totals and complete-ROM `work_batch.py` snapshots.

## Source reconstruction

- `TouchIpcReceive.c`: `[0x03805074, 0x0380525c)`, one C function with
  476 instruction bytes and 12 literal bytes. It matched on its first compile.
  The sixteen-slot IPC protocol preserves the clear/slot-write/dispatch flags
  already established for power IPC. Commands 0 and 2 enqueue requests;
  command 1 validates idle state, an alarm count in 1..4 and scanline below 263;
  command 3 validates and updates the two threshold words. Queue-success state
  changes and replies for state, argument and enqueue errors are preserved.
- `TouchInitialize.c`: `[0x03804f64, 0x03805050)`, one C function with
  204 instruction bytes and 32 literal bytes. Six object variants reached an
  exact match. Separate slot/alarm counters and the cached alarm byte offset
  preserve the original loop lifetimes; declaration order controls the two
  saved cached registers. The initializer clears requests, sets both thresholds
  to 20, initializes/tags four vertical alarms and performs the original SPI
  clock sequence. Both calls to the existing zero-byte clock helper are retained.

`TouchState.h` declares the 48-byte state and its real 32-byte request subobject
at offset four. The IPC clear/write path uses that typed interior view; dispatch
reads use the enclosing state. The sample counters and unknown halfword retain
their observed layout without claiming their full semantics are recovered.

## Source-owned BSS and shared alarm interface

`TouchInitialize.c` defines `ARM7_TouchState` at `[0x0380b690, 0x0380b6c0)` and
four `ARM7_TouchAlarms` at `[0x0380b6c0, 0x0380b760)`: 208 BSS bytes in total.
MWCC emitted the two declarations in reverse order; reversing their source
declaration order gives both original addresses. The symbol/BSS placement check
verified each address and the complete 208-byte allocation. Bytes following
`0x0380b760` remain unowned and are not padded into this batch.

`VerticalAlarm.h` shares the existing 40-byte alarm and 20-byte list-state
definitions among the touch initializer and four existing vertical-alarm source
files. No member layout or behavior changed. Existing units compile byte-exact
with the shared declaration and recorded transitive-header dependency hashes.

## Verification and limits

The complete ARM7 source build and every linked-symbol check pass. The entire
167,876-byte payload retains SHA-1
`a662d5c6a78e990244299926cf6862ce910a475d`. All 28 tests pass: 11 build-pipeline,
six original-payload verification and 11 dependency tests, including the real
pinned-compiler/Ninja nested-header rebuild test. Logs are under ignored
`build/arm7-power-events/touch-*.log`; the accepted report is
`build/arm7-touch-request-accepted/report.json`.

Local delta: two C functions, 680 instruction bytes, 44 literal bytes,
724 fewer payload fallback bytes and 208 BSS bytes. No initialized data or
reviewed assembly credit was added. Main's accepted counters include other
workers' commits and must be measured independently. Full ROM acceptance remains
root-owned; no touch runtime test was performed in this worker. Token usage is
unmeasured. SPI enqueue remains required at five documented variants; its budget
was not used in this batch.
