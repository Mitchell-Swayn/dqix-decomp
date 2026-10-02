# ARM7 reconstruction attempts

## 2026-10-02 — thread creation and exit lifecycle

- Creator at `0x037fc460`: two compiler experiments. The inherited draft had
  the exact 264-byte size but 18 differing bytes across ten instructions near
  the ID/state stores. Replacing the chained zero assignment with separate
  state and unknown-word stores reproduced native register allocation and
  scheduling. All 248 instruction bytes and 16 literal bytes then matched.
- Exit quartet at `0x037fc568`, `0x037fc58c`, `0x037fc5ec`, and `0x037fc62c`:
  first compilation matched all 308 bytes (288 instructions, 20 literals).
  Clear-before-call callback behavior and scheduler-lock teardown were derived
  directly from original ARM instructions; no opaque instruction arrays,
  assembly, or matching-only conditionals were added.
- Register initializer at `0x037fc9d4` was inspected but not attempted. Its
  redundant conditional branches warrant separate provenance analysis.
- New source owns no BSS. Existing `0xa4` context-size evidence is checked in
  both units. External aliases use existing source names where available.
- Validation: standalone payload and every declared symbol matched with pinned
  MWCC ARM 2.0 SP2p2. Payload SHA-1 remains
  `a662d5c6a78e990244299926cf6862ce910a475d`. All 11 pipeline regression
  tests and six baseline-verifier tests passed. Totals: 83 C functions,
  8,108 instruction bytes, 556 literal bytes, 158,228 fallback bytes.

## 2026-10-02 - thread priority, callbacks and scheduler unlocking

- Priority setter `0x037fc7cc`: first ordinary-C compile matched 168 bytes.
  Splitting into its own unit retained equality. Idle context address is
  `0x03808fe0`, inside the already source-owned scheduler BSS.
- Wake callback `0x037fc918` and switch-callback setter `0x037fc938`:
  initial bodies matched apart from placement displaced by the sleep draft;
  separate-unit validation matched all 76 bytes on its first compile.
- Unlock `0x037fc99c`: first compile matched all 56 bytes. Lock increment was
  inspected but not attempted: saturation leaves the return register unchanged,
  requiring care before representing its behavior in ordinary C.
- Sleep `0x037fc874` deferred after eight compiler invocations including two
  editing errors and one initial linker-liveness mistake. Baseline conversion
  `((u64)milliseconds * 33514) >> 6` emitted a 152-byte function versus native
  164 bytes: native retains zero high-word multiply-accumulates. A named 64-bit
  temporary and reversed multiply operands each produced identical short code.
  An inline conversion helper with inlining disabled at the caller emitted an
  extra out-of-line helper; enabling inlining with a generic 64-bit multiply
  helper restored the same short code. None justified introducing opaque
  arithmetic or changing compiler flags, so the exact three neighboring bodies
  were split into separate units and sleep remained original binary.
- Validation: complete standalone payload and all declared symbols match;
  SHA-1 remains `a662d5c6a78e990244299926cf6862ce910a475d`. All 11 pipeline
  tests and six verifier tests pass. Four functions add 280 instruction bytes
  and 20 literal bytes, with no new storage or assembly exceptions. Totals:
  87 C functions, 8,388 instruction bytes, 576 literals, 157,928 fallback bytes.

## 2026-10-02 - DMA and timer interrupt response dispatch

- Dispatcher `0x037fb670`: first compilation matched all 140 bytes. The
  existing ARM9 handler suggested callback semantics; ARM7 disassembly established
  clear-before-call, fired-bit recording, and reloading the continue-enabled flag
  after the callback. Field-base pointer arithmetic matches the existing response
  setters and preserves separate native literal addresses.
- Eight wrappers `0x037fb6fc` through `0x037fb76c`: first compilation matched
  all 128 bytes. They remain a separate translation unit because native vectors
  perform interworking tail calls to the dispatcher.
- Mapping table `0x0380881c`: original eight little-endian halfwords are
  `(8,9,10,11,3,4,5,6)`, corresponding to the four DMA and four timer IRQ IDs.
  Reconstructed as a typed constant array with 16 data bytes, no code credit.
- Validation: standalone payload and declared symbols all match, including the
  first compiled mapping table. Payload SHA-1 remains
  `a662d5c6a78e990244299926cf6862ce910a475d`; 11 pipeline and six verifier
  tests pass. Totals: 96 C functions, 8,604 instruction bytes, 628 literals,
  880 initialized data bytes, 157,644 fallback bytes. BSS and assembly unchanged.
- Next coherent candidate batch: VBlank dispatch, interrupt wait-list
  initialization, and interrupt-handler registration at `0x037fb77c` onward.

## 2026-10-02 - VBlank dispatch and interrupt initialization

- Wait-list initializer `0x037fb7cc` matched on the first combined compilation.
- VBlank handler `0x037fb77c`: initial callback-with-count hypothesis caused an
  extra volatile count read. Second invocation used a no-argument handler and
  recovered the size; third explicitly snapshotted the callback before advancing
  the count, matching native scheduling and all 80 bytes. The no-argument call
  preserves the observed interface; the value left in r0 is incidental.
- Handler registration `0x037fb7f0`: stopped after ten compiler invocations.
  Initial branch structure recovered the body shape; a named VBlank pointer
  corrected literal order but left register differences. Explicit response-index
  scopes, a separate VBlank symbol, inverted final selection, size-optimization
  pragma, response variable scope, removal of index shadowing, and moving null
  initialization before the mask test did not match. Best: exact 156-byte size
  and literal order, 13 differing bytes across eleven register selections.
  Kept out of inventory; no further variants without new evidence.
- Default no-op handler `0x037fb66c` was translated as an empty C function.
- Added separate BSS ownership for the eight-byte IRQ-waiter queue and 12-byte
  VBlank response. The response-prefix access is an external layout view; it
  does not duplicate ownership of the existing 96-byte DMA/timer response array.
- Validation: all three units, both BSS placements and the full standalone
  payload match on the first integrated build. SHA-1 remains
  `a662d5c6a78e990244299926cf6862ce910a475d`; 11 pipeline and six verifier
  tests pass. Totals: 99 C functions, 8,704 instruction bytes, 648 literals,
  880 initialized data bytes, 716 BSS bytes; 157,524 payload bytes remain fallback.
- Next candidate batch: shared cartridge-bus lock release/acquire functions
  beginning at `0x037fba50`, with ARM9 GamecardBusOwnership as semantic reference.

## 2026-10-02 - shared cartridge-bus locks

- Generic unlock/try-lock and GBA blocking acquire/internal release at
  `0x037fba50` through `0x037fbbe4`: four functions matched on first compilation.
  ARM9 GamecardBusOwnership supplied shared-lock semantics; ARM7 instructions
  independently established strict masking, volatile atomic accesses, callback
  ordering, retries and the extra platform-hook gating.
- GBA try-acquire `0x037fbbf0`, NDS release/try-acquire `0x037fbc38`/`0x037fbc58`,
  and owner getter `0x037fbc80`: first compilation of each unit matched exactly.
- Shared boot-halfword getter `0x037fcac0`: one compile matched all 28 bytes.
  Disassembly reads `0x027ffffa` and tests bit 2, so the initial speculative
  processor-mode name was replaced with the evidence-only TestSharedBootFlag4.
- Public GBA release trampoline `0x037fbbe4` uses r1 for an indirect tail jump;
  left binary-owned without attempting to force ordinary C to select a register.
  Owner-ID allocation/release at `0x037fbc88`/`0x037fbd30` shows redundant branch
  patterns similar to deferred register initialization and remains unattempted.
- Validation: complete standalone payload and every declared symbol match;
  11 pipeline tests and six verifier tests pass. Totals: 108 C functions,
  9,220 instruction bytes, 700 literals, 880 initialized data bytes, 716 BSS;
  156,956 payload bytes remain fallback. No new storage or assembly exceptions.
- Next candidate: input/GPIO polling and periodic-alarm initialization beginning
  at `0x037fec18`, which connects already source-owned timing and alarm APIs.
