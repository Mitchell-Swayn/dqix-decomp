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

## 2026-10-02 - GPIO control and periodic input polling

- GPIO mask update `0x037fec18`: first compile had the exact 32-byte size but
  six differing register bytes. Reordering the commutative AND operands to
  `~clearMask & *control` reproduced native evaluation/register allocation on
  the second compile; volatile access count and behavior were unchanged.
- Mode wrapper `0x037fec38`: first compile matched all 24 bytes, including
  unsigned-short narrowing of the input before passing it to the mask update.
- Polling initialization/callback `0x037fec50` and `0x037fecec`: first compile
  matched all 220 bytes. Existing alarm types establish the 44-byte layout;
  literal and call analysis establishes interval 2094 and start time now+2094.
  The polling callback maps observed input bits without inventing names for
  unproven controls. Readiness checks precede initialization-state checks.
- BSS source ownership adds the four-byte initialization flag and 44-byte alarm;
  code/literal counts remain separate from the 48-byte zero-fill range.
- First source-owned BSS build revealed that separate globals were emitted alarm
  first, flag second. A typed aggregate explicitly places the flag before the
  alarm and reproduced the native literals and BSS layout on the next build.
  No linker padding or artificial storage was introduced.
- Validation: complete payload, all symbols and 48-byte BSS placement match;
  11 pipeline tests and six verifier tests pass. Totals: 112 C functions,
  9,464 instruction bytes, 732 literals, 880 initialized data bytes, 764 BSS;
  156,680 payload bytes remain fallback. No added assembly exceptions.
- Next candidate: sound-master control and sound power transitions beginning
  at `0x037fed2c`, including the 16-channel stop loop.

## 2026-10-02 - sound master and power sequencing

- Sound-master batch `0x037fed2c` through `0x037fee94`: initial eight-function
  compilation was four bytes long solely because the channel-reset for-loop
  emitted an entry test. Rewriting the naturally fixed 16-channel loop as
  do/while matched all 360 bytes on the second invocation. Other function
  bodies were already structurally exact apart from shifted placement.
- Channel stop `0x037ff0b0`: first ordinary-C compile matched all 40 bytes.
- Names distinguish register-backed master/power behavior from opaque external
  hooks. Thumb helpers at `0x03803eca`/`0x03803ed2` forward the delay into r1,
  set r0 to one/zero and invoke SVC 8; only their C wrappers are reconstructed.
  Channel stop description records bit operations rather than inferring policy
  from the optional bit-15 flag. No source data or BSS ownership is added.
- Validation: full standalone payload and every declared symbol match;
  11 pipeline tests and six verifier tests pass. Totals: 121 C functions,
  9,816 instruction bytes, 780 literals, 880 initialized data bytes, 764 BSS;
  156,280 payload bytes remain fallback. No new assembly exceptions.
- Next candidate: three sound channel configuration functions beginning at
  `0x037fee94`, then parameter setters after `0x037ff0d8`. Preserve unnamed
  software override fields until their broader semantics are demonstrated.

## 2026-10-02 - sound channel setup and parameter controls

- Three channel setups `0x037fee94`, `0x037fef60`, `0x037ff00c`: first draft
  recomputed byte offsets after the optional call and used the wrong operand
  evaluation order for PCM control packing. Explicit channel-byte-offset locals
  plus format-before-repeat evaluation matched all 540 bytes on the second
  invocation. The offset is meaningful address state, not a forced register.
- Six parameter functions `0x037ff0d8` through `0x037ff270`: first combined
  compile was eight bytes short. Snapshotting the hardware pan before calling
  volume adjustment restored the native extra move; using independent loop
  locals in the two pan-override branches restored their separate initialization.
  Second compilation matched all 408 bytes. Other bodies matched from outset.
- Register fields distinguish requested volume/pan from effective hardware
  values. The software adjustment factor and requested arrays remain external;
  no new initialized-data or BSS ownership is included in this batch.
- Validation: full payload and every declared symbol match; 11 pipeline and
  six verifier tests pass. Totals: 130 C functions, 10,664 instruction bytes,
  880 literals, 880 initialized data bytes, 764 BSS; 155,332 fallback bytes.
- Next batch underway: sound adjustment factor setter/helper beginning at
  `0x037ff270`, followed by the fixed-point sound period/pitch helpers.

## 2026-10-02 - sound volume adjustment and math utilities

- Adjustment-factor setter/helper `0x037ff270`/`0x037ff2d0`: first compilation
  matched all 204 bytes. Piecewise formulas, thresholds and 21-bit shifts are
  direct transcriptions of integer operations, without assigning an unproven
  user-facing policy to the factor.
- Attenuation conversion, BIOS-volume wrapper, signed sine lookup and LCG at
  `0x037ff468` through `0x037ff588`: first compilation matched all 288 bytes.
  Unsigned seed arithmetic preserves modulo-2^32 wraparound.
- Factor/requested arrays placed in a typed 36-byte BSS aggregate matched on
  the first storage-owning build. The old per-field externals are numeric aliases
  into the aggregate and claim no duplicate storage.
- Sine table: first integrated inventory assumed 36-byte alignment but compiler
  section inspection proved a 33-byte .rodata output. Corrected ownership to
  exactly 33 bytes; subsequent full payload matched. Three trailing zero bytes
  remain original fallback. This was a size-accounting correction, not a code
  variant or invented padding declaration.
- Validation: full payload, all declared symbols and BSS match; 11 pipeline
  tests and six verifier tests pass. Totals: 136 C functions, 11,112 instruction
  bytes, 924 literals, 913 initialized data bytes, 800 BSS; 154,807 fallback bytes.
- Next batch underway: sound-worker thread initialization, recurring alarm
  control and queue notifications at `0x037ff588` onward. Fixed-point period
  conversion remains a separate unattempted candidate.

## 2026-10-02 - sound-worker lifecycle, alarm and queue notification

- Initialization/start/stop/notify functions `0x037ff588` through `0x037ff674`
  matched all 236 bytes on first compilation. Alarm callback `0x037ff67c`
  matched all 68 bytes on first compilation.
- Typed 1300-byte worker BSS aggregate also matched on first integrated build.
  Original worker main at `0x037ff6c0` passes queue `0x03809284`, slots
  `0x03809264` and count 8 to the source-owned initializer, and alarm
  `0x038092a4` to its initializer. Creator arguments prove context `0x038092d0`,
  stack top `0x03809774`, stack size `0x400`; context stride `0xa4` closes the
  contiguous layout exactly. Thus every aggregate field has access/size evidence.
- Queue-full handling remains a call through the original callback slot to its
  original message; no new error-recovery policy is inferred.
- Validation: complete payload and all symbols/BSS match; 11 pipeline tests
  and six verifier tests pass. Totals: 141 C functions, 11,360 instruction bytes,
  980 literals, 913 initialized data bytes, 2,100 BSS; 154,503 fallback bytes.
- Next candidates: sound capture configuration/status at `0x037ff7b4`, worker
  main dispatch at `0x037ff6c0`, and fixed-point period conversion at `0x037ff33c`.
