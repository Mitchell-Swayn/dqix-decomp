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
