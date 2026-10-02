# ov019 worker evidence

Batch `fleet_ov019_20261002t1605`, baseline
`0ade2646fe7e27eb53d084a9e857334d18b3b47f`. The batch snapshots recorded
2026-10-02 15:43:33 to 15:48:35 UTC: **302.442433 seconds** through acceptance,
excluding subsequent handoff/commit preparation. No earlier ov019 attempts or
caps were present. Queue and other modules were not edited.

## Accepted family

`src/Factory/ov019/SceneHelpers.cpp`, `.text [0x0218c178,0x0218c290)`:

| Function | Range | Instructions | Literals | Variants |
| --- | --- | ---: | ---: | ---: |
| `func_ov019_0218c178` | 0218c178–0218c240 | 200 | 0 | 1 |
| `func_ov019_0218c240` | 0218c240–0218c290 | 64 | 16 | 1 |

One object compilation tested both functions; both were exact on that variant.
No failed source hypotheses. An initial incorrect unit-name invocation failed
before compilation and is not a source variant.

The large scene routine loads `data/ani/pen.pac`, initializes a renderer at
scene +0x54, and points its table field (+0x3c) to the embedded table at scene
+0x2d8. The first helper selects animation identifier 1, sets bit 8 in its flags,
advances it by `GameState::GetTickCount()`, writes signed coordinates (215,150),
sets layer 0x24, and applies the renderer. With scene flag 1 clear it clears
animation flag 8. `0205addc` checks that bit before applying animation
coordinates/layer, supporting the visibility interpretation.

The second helper tests new button presses with mask 0x7f3 or a nonzero touch
byte (+0x55), plays sound 1 through `0205eaa0`, and returns 1; otherwise returns
0. Its scene argument is unused. Original direct callers are `0218c058` and
`0218bf04`, respectively, inside `func_ov019_0218b5a8`.

Local structures retain the observed 0x18-byte animation record, 8-byte table,
0x54-byte renderer and embedded scene renderer. Unknown fields remain explicit;
the declarations describe the accessed portions, not fully recovered classes.
No shared headers or symbol names changed.

## Validation and accounting

- `tools/match_unit.py src/Factory/ov019/SceneHelpers --worker fleet_ov019
  --hypothesis ...`: 2/2 symbols at 100%.
- `tools/factory_diff.py`: zero mismatched symbols.
- Full `.venv/Scripts/ninja.exe -j2 rom check report sha1`: exit 0; all ARM9
  modules and symbols passed, ARM7 preservation passed, ROM SHA-1
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- `tools/work_batch.py start/finish`: +2 matched functions, +280 reported code
  bytes (**264 instructions +16 literals**); +0 initialized data, +0 BSS,
  +0 assembly. ARM7 unchanged. All denominators unchanged (ARM9: 14,790
  functions, 2,959,478 code bytes, 1,602,476 data bytes).
- No runtime/gameplay tests were performed for this batch. Tokens unmeasured.

Ignored local evidence: `build/factory/fleet_ov019_dis/` (original dsd
disassembly, including main dependencies), `build/factory/ov019-*-evidence.json`,
`build/factory/ov019-final-diagnosis.json`,
`build/matching/20261002T154614-b8a06e76b9454cbbb32dd6ac3ab75bbf/`,
`build/factory/ov019-acceptance.log`, and
`build/workflow/fleet_ov019_20261002t1605/{start,finish}.json`.
The finish snapshot precedes the source commit and explicitly records dirty state.

## Remaining required work

The large scene routine `[0218b5a8,0218c178)`, the two entry no-ops, all overlay
rodata/ctor/initialized data, and the other scene fields remain original fallback.
This batch does not complete ov019. The main animation operations `0205a370`,
`0205a3d0`, `0205a330`, `0205a42c`, `0205ae8c`, button query `02012444`, sound
operation `0205eaa0`, and global owners `02114e30`, `02114e54`, `02108760`
remain external dependencies. Their inspected instructions establish the helper
interfaces, but their source/data ownership has not been reconstructed here.
Next work can recover the scene's resource/display setup and packed strings,
with the renderer/table layout as established evidence. No cap was exhausted.
