# ARM7 SPI service initialization and cookie ownership

Worker baseline: `4e10708`, after the power receive/sleep batch. Candidate
iteration began at 2026-10-02T13:30:45Z. The verified independent original ROM
input is unchanged. Complete-ROM reports are absent in this worker, so root
records the main integration deltas with `tools/work_batch.py`.

## Matched source

- `SpiInitialize.c`, `[0x03804a88, 0x03804ba0)`: one C function, 252 instruction
  bytes and 28 literal bytes. It initializes the four service receivers, installs
  channel callbacks, initializes the sixteen-entry queue/tasks and creates the
  SPI worker thread at the caller's priority. Two candidate compiles matched;
  the original task-clear loop is a `do` loop.
- `SpiServiceToken.c`, `[0x03804ba0, 0x03804c5c)`: two C functions, 172 instruction
  bytes and 16 literal bytes. Acquisition blocks while the service is busy,
  then records owner 4 and a caller cookie. Release accepts only the matching
  busy/owner/cookie combination and wakes the shared waiters. The first compile
  of the two-function unit matched completely.

## Complete service storage

The initializer's addresses and its calls to the already matched queue/thread
functions establish a real allocation at `[0x0380b1f0, 0x0380b690)`:

| Offset | Size | Member |
| --- | ---: | --- |
| `0x000` | 4 | Halfword initialized flag and alignment padding |
| `0x004` | 8 | Busy flag and owner |
| `0x00c` | `0xa4` | Worker ProcessorContext |
| `0x0b0` | `0x200` | Worker stack |
| `0x2b0` | 32 | MessageQueue |
| `0x2d0` | 64 | Sixteen message pointers |
| `0x310` | 384 | Sixteen 24-byte SpiTask records |
| `0x490` | 4 | Next task index |
| `0x494` | 8 | Shared blocked-context wait list |
| `0x49c` | 4 | External-client cookie |

`SpiService.h` declares this layout once, with checked `0x4a0` outer and `0x49c`
body sizes. `SpiInitialize.c` defines its 1,184 BSS bytes. Queue/wait-list symbols
denote the typed subobjects at their existing addresses. No second allocation or
placeholder gap is introduced. The whole allocation lies within the startup
WRAM zero-clear range; main's source ownership map showed no existing owner.

`MessageQueue.h` now shares the actual 32-byte queue declaration with both the
queue implementation and SPI service. Existing queue and SPI functions still
compile byte-exact after adopting the shared declarations.

## Unmatched enqueue dependency

The earlier three enqueue variants remain deferred. Two concrete layout
hypotheses were tested in this batch, bringing the total to five:

1. A typed interior service-body symbol made the compiler hoist the index load,
   because it treated the two external objects as independent. The result was
   220 bytes versus 224 required, with 45 differing words.
2. A real union view of command plus argument words produced 212 bytes and
   retained an indexed store instead of the original separate address add.

Neither hypothesis is retained in source or the manifest. The normal task
structure remains unchanged; source reconstruction of enqueue is still required.
Closest earlier evidence remains 220/224 bytes with 42 differing words. The next
experiment should inspect the precise variadic extraction/address expression
used by sibling task producers. Five variants remain before the ten-variant
triage limit; do not repeat these hypotheses without new evidence.

## Verification and delta

All configured ARM7 source units, their transitive headers and linked symbols
were checked against the complete original 167,876-byte payload. Payload SHA-1
remains `a662d5c6a78e990244299926cf6862ce910a475d`. The 11 build-pipeline, six
original-payload verification and 11 dependency tests pass, including the real
pinned-compiler/Ninja nested-header rebuild test.

Delta from this worker baseline: three C functions, 424 instruction bytes,
44 literal bytes, 468 fewer payload fallback bytes and 1,184 BSS bytes. No
initialized data or reviewed assembly credit was added. Logs are under ignored
`build/arm7-power-events/`; the accepted report is
`build/arm7-spi-storage-accepted/report.json`. Full ROM acceptance belongs to
root. No runtime service test was performed; token usage is unmeasured.
