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
