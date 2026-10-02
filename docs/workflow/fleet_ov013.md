# ov013 worker evidence

Batch `fleet_ov013_20261003_early` reconstructed the connected menu text composer,
two buffer refresh paths and widget flag update. Baseline revision:
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. No prior ov013 variant evidence was
present in this worktree. The integrator queue and other modules were not edited.

| Function | Half-open range | Instruction bytes | Behavior |
| --- | --- | ---: | --- |
| `func_ov013_02185be0` | `0x02185be0–0x02185cc0` | 224 | Compose two option labels using catalog entries 10/11 and separator entry 0; mode 2 adds formatting. |
| `func_ov013_02186bd4` | `0x02186bd4–0x02186c1c` | 72 | Clear the borrowed text buffer, compose primary text, install it on widget 0. |
| `func_ov013_02186c1c` | `0x02186c1c–0x02186c64` | 72 | Clear the buffer, compose option text, install it on widget 3. |
| `func_ov013_02186c64` | `0x02186c64–0x02186cac` | 72 | Find a widget by ID, update flag 0x40, refresh primary text when ID is zero. |

Source: `src/Factory/ov013/OptionText.cpp`, `MenuText.cpp` and local `MenuText.h`.
No shared header changes. The local header uses the established `SafeAllocator`
type at menu offsets 0 and 0x60c. Initializer `02184360` establishes the 0xbc-byte
widget group at 0x38, two 0x20-byte resource slots and three 0xe0-byte widgets.
Main functions `0205d5d0` and `0205d81c` establish widget stride, ID at 0xc4 and
flags at 0xc5. `020dfc40`/`020dfe88` establish the 0x18-byte string-catalog state
at 0x620. The buffer at 0x658 is borrowed from `020421a0()->0x5c`; its clearing
size is 0x960. The header describes only the menu prefix through 0x663 and retains
explicit unknown fields. Screen identity, detailed formatting meanings and the
remaining object layout are unresolved.

Original evidence came from `dsd dis` and symbol/relocation maps. Calls to the
refresh family occur in `021847c4`, `02186160`, `021864f0`, `02186590`, `0218678c`
and `0218683c`; the flag update also calls the primary refresh. No generated
pseudocode, assembly substitutions or modified comparison inputs were used.

Each function matched its first source hypothesis. Five `match_unit.py` object
comparisons were run in total: initial MenuText, initial OptionText, MenuText
after layout extension, and both final objects after adopting SafeAllocator.
There were zero failed instruction variants. Final comparisons were 3/3 and 1/1
symbols at 100%. Final evidence and factory_diff diagnoses are under
`build/factory/ov013/*-final-evidence.json` and `*-diagnosis.json`; comparison
snapshots are under `build/matching/20261002T154630-*`, `154800-*`, `154820-*`,
`155020-*` and `155021-*` (all timestamp prefixes include `20261002T`).

`ninja -j2 rom check report sha1` passed twice, including after the final header
change. Final log: `build/factory/ov013/final-validation.log`. ARM9 main, ITCM,
DTCM, all 35 overlays, symbol checks and ARM7 byte checks passed. Both original
input and generated ROM SHA-1 equal
`c7c3014c237900c8281289b8bc76a781969b6278`. No gameplay testing was performed.

`tools/work_batch.py start/finish` recorded 481.594889 seconds, five comparisons,
and deltas of +4 functions, +440 matched code bytes, +0 initialized data bytes.
These ranges contain +440 instruction bytes, +0 literal bytes, +0 BSS bytes and
+0 assembly bytes; corresponding original code fallback is removed only for
these ranges. Denominators remain 14,790 functions, 2,959,478 code bytes and
1,602,476 data bytes. ARM7 deltas are zero. Records are under
`build/workflow/fleet_ov013_20261003_early/`; the finish snapshot precedes this
source commit and records the verified dirty source tree. Tokens were unmeasured.

Required unresolved dependencies remain original fallback: primary composer
`02185424`, widget APIs `0205d5d0`/`0205d81c`, catalog lookup `020e0434`, and text
formatters `02041c08`, `02041ea4`, `02041d9c`, `02042058`, `02041b70` (plus their
callees). The catalog contents and most ov013 code/data remain unreconstructed.
No module-completion claim is made.
