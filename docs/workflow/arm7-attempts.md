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

## 2026-10-02 - sound period conversion and worker loop

- Period conversion/wrapper `0x037ff33c` through `0x037ff468`: first compile
  matched 300-byte size with register/scheduling differences. Reversing multiply
  operands and reusing octave for the shift count did not change those bytes.
  Declaring octave before the normalized remainder and snapshotting the BIOS
  fractional lookup before 64-bit multiplication matched on the third compile.
- Worker main `0x037ff6c0`: first compile matched all 244 bytes, including the
  two-message switch and endless blocking-receive loop. Subsystem callees keep
  opaque names where the routine body has not yet established semantics.
- Capture configuration `0x037ff7b4`: stopped after eight variants. Initial
  inline boolean packing had many register differences; naming the inverted
  repeat flag and reordering commutative packing matched size/registers except
  for two reversed conditional moves (four bytes). Parameter assignment via
  if/else or comparison introduced a spill. Ternary, local logical negation,
  local if/else and default-one initialization failed to reproduce ordering.
  No forced-register or assembly workaround was used; this function stays binary.
- Capture-active getter `0x037ff804` matched its original body from the initial
  compile and is selected independently from the unsuccessful configuration.
- Validation: complete standalone payload and every declared symbol match;
  11 pipeline and six verifier tests pass. Totals: 145 C functions, 11,900
  instruction bytes, 1,008 literals, 913 initialized data bytes, 2,100 BSS;
  153,935 fallback bytes. No data, BSS, or assembly credit added by this batch.
- Next candidates: queued sound-channel state initialization and update dispatch
  at `0x037ff81c`/`0x037ff878`, with subsequent channel-state setters considered
  as one coherent bounded batch.

## 2026-10-02 - queued sound-voice state and hardware update dispatch

- Voice initialization `0x037ff81c`: first compile matched 92 bytes. Byte-sized
  bitfields reproduce the low-three/high-five split and merged active/pending
  clearing. The 16-record array has an independently checked 0x54-byte stride.
- Update dispatcher `0x037ff878`: first compile matched size/control flow, with
  index and voice-pointer registers swapped. Moving the first-pass voice pointer
  to outer scope before the index declaration reproduced all 492 bytes on the
  second compile. Two-pass configure-then-enable ordering is preserved.
- PCM/PSG/noise staging `0x037ffe18` through `0x037ffee4`: PCM matched initially;
  the grouped invalid-channel conditions merged return paths in PSG/noise.
  Separate lower/upper rejection checks matched the original 204-byte batch on
  the second compile. Waveform-copy structure is 12 bytes and keeps the original
  load/store multiple sequence.
- The 1344-byte voice array becomes BSS source; the adjacent list header and
  unexplained gap are deliberately left outside this storage definition.
- Integration initially missed the extern list symbol because its anonymous
  struct declaration contains an internal semicolon; the inventory was corrected
  to retain the observed `0x03809774` address. No code variant was needed.
- Validation: full payload, symbols and 1344-byte BSS placement match; 11 pipeline
  tests and six verifier tests pass. Totals: 150 C functions, 12,668 instruction
  bytes, 1,028 literals, 913 initialized data bytes, 3,444 BSS; 153,147 fallback.
- Next batch underway: voice-envelope update and attack/decay/sustain/release
  setters at `0x037ffee4` through `0x03800008`.

## 2026-10-02 - sound voice ADSR envelope and start helpers

- Seven-function envelope batch at 0x037ffee4: first compile matched all but
  attack setter conditional instruction ordering. Inverting the source condition
  to express the low-value linear case first reproduced the original scheduling
  on the second effective variant. One intervening compile repeated the old source
  because a CRLF-sensitive replacement did not apply; no new hypothesis was tested.
- Fall-rate conversion and voice start at 0x0380051c matched all 140 bytes on
  their first compile, including the division helper call and special rates.
- Nine functions add 416 instruction bytes and 16 literal bytes. No table data
  or BSS is counted in this batch; both lookup tables remain binary dependencies.
- Shared SoundVoice/Waveform declarations should be consolidated after the source
  build tracks transitive header hashes. At present arm7_build.py hashes only the
  declared source file, so introducing a shared header would omit layout changes
  from per-unit provenance. Keep the 0x54-byte compile-time checks meanwhile.
- Validation: full 167,876-byte payload and declared symbols pass; SHA-1 remains a662d5c6a78e990244299926cf6862ce910a475d. All 11 pipeline and six verifier tests pass.

## 2026-10-02 - delayed sound modulation

- Initialization at 0x03800448 matched its first compile. Update/read at
  0x0380046c/0x038004cc matched size first, but unsigned shifts and multiplication
  operand order differed. Explicit unsigned phase snapshots and depth-first
  multiplication fixed these on variant two; a separate phase snapshot before
  adding speed matched the update load ordering on variant three.
- Three functions add 212 instruction bytes, with no literal, data or BSS claim.
  The wrap loop and staged halfword phase updates are preserved by ordinary C.
  The parameter byte at offset zero remains unknown; delay counter/phase are
  established at relative offsets six/eight, or voice offsets 0x2e/0x30.
- Validation: full payload equality and all declared symbols pass; all 11 pipeline and six verifier tests pass. Payload SHA-1 remains a662d5c6a78e990244299926cf6862ce910a475d.

## 2026-10-02 - sound callback cleanup and reservation controls

- Callback cleanup and reservation-mask getter matched on their first compile.
- Release-mask helper required an ordinary if/else instead of early return to
  preserve conditional block order. Range stop required start <= source operand
  order to combine the two bounds checks. Both matched on their second variant.
- Four functions add 216 instruction bytes and 12 literals. No BSS is claimed.
- New mask consumers disprove the previous tentative list-header interpretation
  at 0x03809774. Corrected SoundVoiceInit's type, alias and documentation to two
  unsigned masks, without inventing policy labels for flag-zero/flag-one cases.
- Validation: complete payload, linked symbols, 11 pipeline tests and six verifier tests pass; payload SHA-1 remains a662d5c6a78e990244299926cf6862ce910a475d.

## 2026-10-02 - sound reservation cleanup and sequence initialization

- Stop/reserve pair: initial 400-byte result had channel/pointer registers swapped.
  Giving the voice pointer function scope fixed stop on variant two; placing the
  remaining-mask declaration before the channel index fixed reserve on variant
  three. Hardware calls and callback timing were already exact.
- Sequence initialization: initial 104-byte result duplicated the sequence-array
  base for its index member. A local record pointer and distinct track-loop index
  matched the original 100 bytes on variant two. Arrays remain external BSS.
- Voice allocator 0x03800008 is deferred after nine compiler invocations, including
  two failed source edits (PowerShell replacement and C89 declaration ordering).
  Initial for-loop source was four bytes long; do/while and separate initialization
  recovered exact 460-byte size and all control flow. Volume snapshots altered
  register assignment but left 51 differing bytes. An explicit inline comparator
  did not inline with the current compiler settings. Moving channel declaration,
  updating volume snapshots in place, and caching the shift table pointer gave no
  improvement (last result 52 differing bytes). No allocator draft is integrated.
  Literal inspection corrected its lookup addresses to 0x038084cc/0x038084d0.
- Three integrated functions add 476 instruction and 24 literal bytes. Allocation
  needs new compiler/inlining evidence before another attempt; retain its unknown
  parameter bytes by offset instead of assigning speculative policy semantics.
- Validation: complete payload and declared symbols pass, as do all 11 pipeline and six verifier tests. SHA-1 remains a662d5c6a78e990244299926cf6862ce910a475d.

## 2026-10-02 - shared sound record layouts after header provenance support

- Imported the four verified tooling files from main commit c4cda3a as local
  tooling-only commit 9dc506d. Direct cherry-pick met an unrelated modify/delete
  conflict in docs/workflow/README.md; aborted it and copied only the authorized
  tools files. This tooling import earns no source coverage and need not be
  cherry-picked back into main, where its originating commit already exists.
- Consolidated Waveform, SoundModulation and SoundVoice into SoundVoice.h for nine
  source units. The 12-/10-/84-byte size assertions and explicit unknown bytes
  preserve observed layout. Voice offset 0x30 now has the established phase name,
  with modulation embedded as the recovered ten-byte record at offset 0x28.
- Full payload and linked symbols match immediately after consolidation. All nine
  consumers report the same actual header SHA-1 in compiler dependency records.
  Eleven pipeline and six verifier tests pass; dependency tests pass (10 passing,
  one environment-gated integration test skipped). No coverage totals change.

## 2026-10-02 - cached sequence byte and 24-bit readers

- Cached byte read at 0x03800948, aligned four-word cache fill at 0x03800e3c,
  and little-endian 24-bit read at 0x03800e78 all matched their first compile.
- Shared SoundSequence.h records sequence/track/cache layouts with 36-/64-/28-byte
  size assertions. Initialization and both reader units include the tracked header.
  Cursor offset 0x28 and cache buffer at state+0x0c are proven by these consumers.
  The cache's first word remains unknown; no external storage is claimed as BSS.
- Three functions add 192 instruction bytes and 12 literal bytes.
- Validation: full payload and all symbols match; all 11 pipeline and six verifier tests pass. Header dependencies are recorded by the compiler-backed provenance path.

## 2026-10-02 - sequence start flags and sized parameter writes

- Start-prepared and prepare/start wrappers matched their first compile (80 bytes).
  The final preparation argument remains generic; no new policy meaning is claimed.
- Sized sequence writes matched first compile. Track writes initially matched size
  and behavior with five setup instructions scheduled differently; a named sequence
  pointer initialized before traversal matched on variant two (224-byte pair).
- Four functions add 288 instructions and 16 literal bytes, no data or BSS.
  Shared sequence flags now identify running/paused bits from start and update
  consumers; all remaining flag bits stay unknown.
- Validation: full payload and symbols match; all 11 pipeline and six verifier tests pass, with shared-header hashes included in affected unit records.

## 2026-10-02 - sequence track lookup and voice lifecycle

- Track data setter, clear-voices, lookup, stop-track, stop-sequence and callback
  unlink matched their first compile. Release-voices initially had the voice and
  truncated-release registers swapped; an explicit unsigned-byte release local
  after the voice declaration matched on variant two.
- Combined the seven contiguous functions at 0x03801088..0x03801250 into one unit:
  448 instruction bytes and eight literal bytes, with no data/BSS additions.
- Shared sequence layout now identifies trackIds[16] at offset eight and track
  voice-list head at 0x3c. The lookup retains its signed >15 rejection and 255
  sentinel; callback unlink retains the observed list preconditions. No defensive
  checks or inferred event meanings were introduced into matching source.
- Validation: complete payload and all symbols match; all 11 pipeline and six verifier tests pass, with the transitive sequence/voice header graph tracked.

## 2026-10-02 - sequence stop, pause and range invalidation

- All four functions matched their first compile: public stop/pause at 0x038009f8
  and cursor/argument range invalidation at 0x03800c74. Pausing releases existing
  track voices with rate 127, then detaches their callbacks; stopping clears the
  optional shared-work active mask after teardown.
- The shared sequence layout now exposes offset 0x20 as argument, matching the
  fourth preparation argument and range comparisons. Its policy remains unknown.
- Adds 424 instruction bytes and 20 literal bytes; no storage coverage is added.
- Validation: full payload and linked symbols match; all 11 pipeline and six verifier tests pass, including all prior shared-header consumers in the payload build.

## 2026-10-02 - track allocation, mute modes and mask setters

- Mute mode and mask dispatch matched first compile. Allocation's array base and
  scaled-offset registers initially differed; a local track pointer matched on
  variant two. Parameter1E's flag originally used a compound operation on an
  unknown multi-bit field, which emitted extraction/reinsertion; splitting the
  proven bit-seven flag into its own bitfield matched on variant two.
- Four functions add 404 instruction bytes and 12 literals. Offset 0x1e remains
  an unidentified parameter; its changed flag is named only by that association.
  Allocation preserves the first-free scan and -1 failure return.
- Validation: full payload and declared symbols match; all 11 pipeline and six verifier tests pass, with all header consumers recompiled.

## 2026-10-02 - track defaults, sequence advancement and variables

- Track initialization and sequence advancement matched first compile. Variable
  lookup initially if-converted its local case, producing four fewer bytes. Writing
  the local (<16) case first with explicit else matched on variant two.
- Track initialization proves the shared six-byte modulation parameter prefix;
  split SoundModulationParameters from the voice-only counter/phase tail and use
  it directly for track initialization. This removes an opaque byte-array cast
  without assigning meanings to unrelated track fields. Candidate stayed exact.
- Shared work now has a typed 0x260-byte prefix: 0x20 header plus 16 records of
  16 signed variables and a tick counter. Global-variable count remains unknown;
  lookup addresses the trailing storage without inventing a fixed array bound.
- Three functions add 484 instruction and 12 literal bytes. No BSS claim changes.
- Validation: complete payload and symbols match after the shared-layout refinement; all 11 pipeline and six verifier tests pass.

## 2026-10-02 - shared sound variables/status; larger updater attempts

- All three shared-variable/status functions at 0x03802328 matched first compile:
  200 instruction bytes and 12 literals. Shared offsets 8/10 are channel/capture
  active masks. Global-variable count and other prefix fields remain unknown.
- Sequence updater 0x0380060c deferred after four variants. Scope/declaration
  changes fixed sequence/index/mask and processed-tick register assignment;
  explicit multiplication snapshot fixed tempo scheduling. Remaining blocker is
  one extra ADD in typed shared->sequences[index].ticks addressing: original uses
  base+index*36 with a final +0x40 load/store offset, while C uses base+0x40 with
  indexed accesses. Named record/counter pointers and expanded assignment did not
  remove it. Avoid shifted fake-struct overlays solely for instruction selection.
- Track updater 0x03801250 deferred after four invocations (one duplicate-edit
  error). First source matches 344-byte size and logic, with scheduling/register
  differences. Ordering explicit truncated locals and separating pitch calculation
  reduced mismatch to 110 bytes; changing integer declaration order regressed to
  143. No candidate is integrated, and experimental layout expansions were restored
  before this batch. Future work needs original inline-helper/compiler evidence.
- Validation: full payload and symbols match; all 11 pipeline and six verifier tests pass. Deferred updaters contribute no source credit.
