# ov001 worker evidence

Batch `fleet_ov001_20261002t1548`, baseline `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
Worktree: `C:\Users\swayn\Projects\DQIX-Decomp-fleet-ov001`.

## Accepted family

`src/Factory/ov001/ScriptResourceLookup.cpp` reconstructs the two-pass opcode-100
resource lookup loader. Entries contain an integer key and allocated string;
the lookup contains an entry-array pointer and signed count. A global parser
state contains the current index, allocator, and lookup pointer. Both opcode
tables are actual two-element arrays including their terminators.

| Range (end exclusive) | Reconstruction | Bytes |
| --- | --- | ---: |
| `021536e0..021536fc` | Count opcode callback | 28 |
| `021536fc..021537a0` | Populate key and copy path callback | 164 |
| `021537a0..021537b0` | Empty lookup initialization | 16 |
| `021537b0..02153884` | Two-pass loading and entry allocation | 212 |
| `02153884..021538c8` | Key lookup, rejecting null paths | 68 |
| `02164b80..02164ba0` | Count/populate opcode tables | 32 |
| `02165800..0216580c` | Parser state BSS | 12 |

The 488-byte text range contains 468 instruction bytes and 20 literal bytes
(one pointer each at `021536f8` and `0215379c`, three at `02153878..02153884`).
Initialized data: 32 bytes; BSS: 12 bytes; new assembly/alignment ranges: zero.
Report delta: +5 functions, +488 code bytes, +44 data bytes (including BSS).
All code/data/function denominators and ARM7 counters are unchanged.

## Evidence and verification

- Read module symbol/delink/relocation maps, existing `Script` and `SafeAllocator`
  declarations, and original `dsd dis` output. No generated pseudocode used.
- Call relocations at `0215ad10` and `0215e248` invoke the loader. Lookup callers
  at `0215e2e0`, `0215e468`, and `0215e880` use returned resource strings; the
  first passes the string at entry offset 4 into `func_0204500c`.
- One candidate compilation; each of the five functions matched on variant 1.
  Eight of eight sized symbols matched exactly. Zero failed hypotheses and no
  inherited caps found. No special compiler pragmas, assembly, or binary code.
- `tools/match_unit.py ... --worker fleet_ov001 --hypothesis ...` evidence:
  `build/matching/20261002T154605-29097e0ef3834708a853030776b479e8/`.
- `tools/factory_evidence.py` package:
  `build/factory/ov001-lookup-initial.json`. `tools/factory_diff.py` diagnosed zero
  mismatched symbols: `build/factory/ov001-lookup-diagnosis.json`.
- `ninja -j2 rom check report sha1`: exit 0. ARM9, autoloads, all overlays, symbols,
  and ARM7 preservation passed. ROM SHA-1:
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- Full log: `build/factory/ov001-acceptance.log`; original disassembly:
  `build/factory/ov001-dis/ov001_5.s`. Original comparison inputs were unchanged.
- `tools/work_batch.py start/finish` snapshots:
  `build/workflow/fleet_ov001_20261002t1548/`; elapsed **271.644251 seconds**.
  Finish captured the verified working tree before the source/evidence commit.
  Token usage is unknown. No gameplay/runtime test was run.

## Remaining work

This family has no unresolved layout dependency. It uses existing main-module
`Script`, `Script::Parameter`, `SafeAllocator`, `strlen`, and `strcpy` interfaces;
their module ownership is unchanged. Allocation failure and partial population
behavior, first-key selection, and global non-reentrant parser state are preserved.
Semantic source names are inferred; original exported symbol names are retained.
Caller subsystems and the rest of ov001 remain original fallback and required
future work. No shared headers, other modules, or integrator queue were edited.
