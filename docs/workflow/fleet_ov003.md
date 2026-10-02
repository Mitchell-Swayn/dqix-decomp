# ov003 worker: text-entry actions

Batch `fleet_ov003_20261003_family01`, baseline `0ade2646fe7e27eb53d084a9e857334d18b3b47f`.
Worker-only result; not integrated into main and not module completion.

## Accepted ranges

`src/Factory/ov003/TextEntryActions.cpp` owns:

- `.text [0x0215ee44, 0x0215f000)`: ten functions, 444 reported code bytes.
  Separate accounting: 440 ARM instruction bytes and the four-byte table-address
  literal at `0x0215efb4`. No added assembly, BSS, or alignment storage.
- `.rodata [0x0217f3c8, 0x0217f3ec)`: a complete nine-element function-pointer
  array in a typed aggregate, 36 bytes. Its first handler remains original fallback.

| Function | Observed behavior |
| --- | --- |
| `0215ee44` | Toggle mode 1/2, clear alternate selection, return 4 |
| `0215ee68` | Set mode 1, toggle alternate selection, return 5 |
| `0215ee88` | Set mode 1, clear alternate selection, return 6 |
| `0215eea0` | Set mode 4, clear alternate selection, return 7 |
| `0215eeb8` | Decode text to character codes, remove final code, clear and re-encode; return 8 or empty result 9 |
| `0215ef2c` | Return action result 10 |
| `0215ef34` | Set mode 8, clear alternate selection, return 11 |
| `0215ef4c` | Return action result 12 |
| `0215ef54` | Dispatch selected key through a local copy of the nine-handler table; return 0 when no key |
| `0215efb8` | Initialize the text-entry state fields; leave trailing padding untouched |

Symbol names retain their original address labels. Type/member descriptions are
inferences from observed use, not recovered original names. The 40-byte state
allocation is visible in `ov009:021842a0`; initialization is also called from
ov012. `ov003:0215f000` calls both dispatch and backspace. Navigation/setup
establish the 20-byte selected-key record and the buffer/limit fields. Main
`020426bc` returns the decoded character count; `02042764` encodes those codes.
Existing unrelated declarations do not establish the former's return type.

## Attempts and verification

Three candidate compilations, two successful object comparisons:

1. Const-array assignment was rejected by MWCC; source snapshot preserved.
2. A const aggregate copied to a local aggregate produced exact dispatch/table,
   initialization, and seven other handlers. Backspace was 75.86207%, with only
   r4/r5 allocation differences (`factory_diff` category: register).
3. Declaring the text pointer before the encoding byte made backspace exact.
   All eleven compared symbols (ten functions and table) reached 100%.

No function reached the ten-unproductive-variant cap. Other functions used one
successful source hypothesis; backspace used two. The initial compile rejection
did not produce an object comparison. One incorrect unit-name invocation failed
before compilation and is not counted as a candidate variant.

`ninja -j2 rom check report sha1` passed: ARM9 main, autoloads, all 35 overlays,
symbols, ARM7 verification/packaging, and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. Original input SHA-1 was separately
verified. Runtime behavior was not exercised in this batch.

`work_batch.py` measured 375.368958 seconds (6m15s) through acceptance and the
finish snapshot, before the documentation/source commit. Worker report deltas:
code +444, functions +10, data +36; ARM7 and all denominators unchanged.
Token usage was not measured.

Verbose evidence remains under ignored `build/`:

- `factory/ov003_dis/`: original dsd disassembly, including callers/converters.
- `factory/ov003-baseline-evidence.json` and
  `factory/ov003-text-actions-{v1,exact}-evidence.json`.
- `matching/20261002T154633-156a6bcde33c42ec85d50a5598f07208/`: compile rejection.
- `matching/20261002T154658-7c8993b2819a481b924ede7da6ba9c95/`: register mismatch.
- `matching/20261002T154726-5dd22e875aa044cb86d900fa03f57e3f/`: exact comparison.
- `factory/ov003-acceptance.log` and
  `workflow/fleet_ov003_20261003_family01/{start,finish}.json`.

## Remaining dependencies

Character insertion `0215ec90`, state navigation/input processing `0215f000`,
script/layout setup, and both main-module text converters retain fallback.
The layout pointer's target type and state byte `0x21` remain semantically
unresolved. No ownership, attempt cap, or completion claim is assigned to these
dependencies. No shared headers, other modules, or integrator queue were edited.

## Continuation: layout collections and coordinates

Batch `fleet_ov003_20261003_family02`, baseline
`8d1ec161bb076db8ce3aff3d016ea4455a990d8f`. Worker-only result, not integrated
into main. No prior attempts were recorded for this family; prior action-family
counts above remain unchanged.

`src/Factory/ov003/TextEntryLayout.cpp` owns `.text
[0x0215e6d8, 0x0215e9ec)` and `.bss [0x02180cb8, 0x02180cc0)`.
The ten functions total 788 reported code bytes: 780 ARM instruction bytes and
eight literal bytes at `[0x0215e748, 0x0215e750)`. The BSS is a real eight-byte
allocator/layout build context shared with the original opcode handlers.
Initialized data, rodata, alignment storage, and assembly additions are zero.
The report counts the BSS as data: code +788, functions +10, data +8.
ARM7 and all denominators are unchanged.

| Function | Observed behavior |
| --- | --- |
| `0215e6d8` | Initialize the 16-byte layout's two collection descriptors |
| `0215e6f8` | Set build context and initialize/load/execute a layout Script |
| `0215e750` | Allocate an array of 20-byte keys and set capacity/count |
| `0215e790` | Append a key by copying its individual fields within capacity |
| `0215e824` | Find a key by its signed navigation index |
| `0215e85c` | Allocate an array of eight-byte grids and set capacity/count |
| `0215e898` | Append a grid by copying its individual fields within capacity |
| `0215e8f4` | Find the first grid whose mode mask intersects the state mode |
| `0215e930` | Locate a key index and return column/remainder and row/quotient |
| `0215e9a4` | Fetch the signed key index at a valid coordinate, else return -1 |

Types live in the module-local `src/Factory/ov003/TextEntryTypes.h`, also used by
the prior action unit. The former `short unknown12` was split into two unsigned
bytes because the original key insertion reads and writes offsets 0x12 and 0x13
individually. Their meanings remain unknown. Layout capacities/counts and key
indices are signed shorts; grid dimensions and cell count are signed bytes.
Allocation uses actual arrays of those records, and each grid points to its
actual short-index array. No opaque padding substitutes for these dependencies.

Original disassembly establishes the collection layouts through script builders
`0215e510` and `0215e628`. `ov009:021842a0` allocates a 16-byte layout, then calls
initialization at `02184430`; ov012 likewise allocates 16 bytes before its call at
`021848c8`. Script execution callers at `ov009:02186240` and `ov012:02188e00`
pass the layout, allocator, loaded file pointer and length and discard the return
register. The coordinate helpers are called by original navigation `0215e9ec`
and input processing `0215f000`. Names describe inferred use, not recovered
original source names. The evidence tool's automatic caller list is empty;
the explicit relocation maps and original caller disassembly above supply that
evidence without claiming complete indirect-call coverage.

Two new-family candidate compilations/comparisons:

1. Seven functions and the BSS context were exact. Key/grid insertion reached
   94.59459%/91.30435%, differing only in compare operand order and conditional
   return. Coordinate access reached 27.777779%, differing in branch placement
   and combined address calculation. The source and full diff are preserved.
2. Capacity-first comparisons made both insertions exact. A positive bounds
   condition with a row-base pointer followed by column indexing recovered the
   original coordinate-access branches and address calculation. All eleven
   symbols (ten functions and BSS context) became exact.

The other seven functions used one productive source hypothesis. Each insertion
and coordinate accessor used two variants, with one unproductive variant each.
No ten-variant cap was reached. A third comparison rebuilt and verified the prior
action unit after the local header change: all eleven prior symbols remain exact.
One setup attempt with duplicate `.text` sections was rejected by dsd before any
candidate compilation; the continuous accepted range includes the native Script
executor and its real context. No comparison input was patched.

`ninja -j2 rom check report sha1` passed all configured ARM9 module and symbol
checks, ARM7 packaging/verification, and ROM SHA-1
`c7c3014c237900c8281289b8bc76a781969b6278`. The original input SHA-1 was separately
verified. `git diff --check` passed. Runtime behavior was not exercised.
`work_batch.py` measured 310.033678 seconds (5m10s) through acceptance and finish,
before this evidence/source commit. Token usage was not measured.

Verbose evidence remains under ignored `build/`:

- `factory/ov003_dis/`: original layout/script/caller disassembly.
- `matching/20261002T155422-fba0356dd76b4f3dbb2a89431c035ec9/`: first candidate,
  comparison and `factory_diff` diagnosis.
- `matching/20261002T155453-fcb223331db94527a97be63ae2ec3597/`: exact new family.
- `matching/20261002T155453-54060a4068da4ffb8f7c197486e21f51/`: prior-unit regression.
- `factory/ov003-layout-{v1,exact}-evidence.json`, exact diagnosis, configure,
  delink and acceptance logs; `ov003-layout-setup-note.txt` records setup rejection.
- `workflow/fleet_ov003_20261003_family02/{start,finish}.json`.

Remaining required dependencies: original opcode handlers `0215e4e4`, `0215e510`,
`0215e5fc`, `0215e628` and their key/grid initializers; the five-entry opcode
lookup at `[0x0217ff40, 0x0217ff68)`; navigation `0215e9ec`, insertion `0215ec90`,
input processing `0215f000`, presentation/setup helpers and main-module text
converters. These retain fallback, with no new variants or coverage claims.
State byte 0x21 and key bytes 0x12/0x13 remain semantically unresolved. No other
module, shared include directory, main worktree, or integrator queue was edited.
