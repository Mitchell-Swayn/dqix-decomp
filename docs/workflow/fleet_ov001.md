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

## Continuation: script object bindings

Batch `fleet_ov001_20261003_scriptrecords`, baseline
`464a607536cf0a7ee245fe740bb236b49290c16f`. Verified locally; no integration.
The original clean worktree, previous handoff, queue, factory evidence and attempt
ledger were inspected. No inherited failed variants or ownership conflicts were
found for this family. The prior lookup source and evidence are preserved.

| Range (end exclusive) | Reconstruction | Bytes |
| --- | --- | ---: |
| `0215acb4..0215acd4` | Reset one object binding | 32 |
| `02164194..021641e0` | Bind an Object3D for kinds 0, 1, 4, 5 | 76 |
| `021641e0..02164214` | Bind a field-object handle for kinds 2, 6 | 52 |
| `02164214..02164248` | Bounds-checked Object3D binding | 52 |
| `02164248..0216427c` | Bounds-checked field-object binding | 52 |
| `0216427c..02164320` | Apply position to either bound object kind | 164 |

Delta: **6 functions, 428 code/instruction bytes**; zero literal, initialized
data, BSS, alignment or new assembly bytes. Branch-table entries are ARM branch
instructions. All denominators and ARM7 counters are unchanged.

`ScriptObjectBindings.h` is shared only by the two new ov001 source units.
It describes an actual 32-element array of 16-byte records, each with kind,
object ID, offset-8 flag, and a typed target union. Original allocation at
`0215a850` reserves `0x200` bytes, and consumers index records with shift 4.
`0215ab54` supplies GameState Object3D pointers for kinds 0/1/4/5 and manager
handles returned by `0203dce4` for kinds 2/6. `0215a134` applies positions through
`0216427c`; `02164418` reads the same Object3D position at offset `0x44`.
The existing complete Object3D declaration supplies the position subobject.
Null and invalid-kind behavior is preserved, including storing the kind before
rejecting an unsupported nonnull target. The binding routines leave the flag
unchanged. Its source name `enabled` is inferred; its broader meaning is not
established by this batch.

The main-module field handle remains a forward-declared dependency rather than
an invented partial layout. Original `02040774` dispatches through its offsets
`0x14/0x18/0x1c` to placement or Object3D position setters; this batch neither
accesses those fields nor claims that main-module routine as source coverage.
Recovering its complete shared type and the remaining binding operations is
required future work. No static program data is concealed by the declaration.

Three candidate-object comparisons: binding family variants 1 and 2, reset
variant 1. Four binding functions and reset matched initially. Only `021641e0`
failed variant 1 (38.46%): an `if` generated conditional stores and different
store scheduling. The equivalent two-case `switch` matched variant 2. Thus
one failed hypothesis; no function is at its ten-variant cap. Snapshots and
per-symbol results remain in `build/matching/attempts.jsonl` and:

- `build/matching/20261002T155223-086bd1973a91458fa00bc54f01491db6/`
- `build/matching/20261002T155223-1b30deb1da494f759edc173c1a8641f4/`
- `build/matching/20261002T155248-247121b6d74c45c4ae5baf7c371558df/`

The first delink attempt exposed the tool's rejection of two `.text` ranges in
one unit; reset was separated into its own unit before candidate compilation.
This was a mapping error, not an additional compiler variant. Evidence packages
are `build/factory/ov001-bindings-exact-evidence.json` and
`ov001-binding-reset-evidence.json`; diagnoses include both failed and exact
variants. Original disassembly remains `build/factory/ov001-dis/ov001_5.s` and
`main_57.s`. No pseudocode, binary code, assembly bypass, or target edits used.

`ninja -j2 rom check report sha1` passed (exit 0), including module/symbol checks,
ARM7 preservation, and exact ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Log:
`build/factory/ov001-bindings-acceptance.log`. All reconfigurations used the
explicit assigned-worktree compiler path. `git diff --check` passed.
`tools/work_batch.py` snapshots under
`build/workflow/fleet_ov001_20261003_scriptrecords/` record **317.911014 seconds**,
capturing verified source before its commit. Token usage is unknown; no gameplay
test was performed. Remaining ov001 fallback functions are still required.
