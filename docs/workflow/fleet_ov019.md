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

## Continuation: resource record and scene driver experiments

Batch `fleet_ov019_20261002t1610_cont`, baseline
`1620c1ef3c2bcf5702987059359ebe27b79d209c`. Measured interval:
2026-10-02 15:50:13.723051 to 16:09:10.591684 UTC,
**1136.868633 seconds** (18 minutes 56.87 seconds). The finish snapshot is
after acceptance and before this source/evidence commit, and records dirty state.
Queue, other modules, shared headers and shared tools were not edited.

Accepted `src/Factory/ov019/SceneResources.cpp` ranges:

| Range | Contents | Gain |
| --- | --- | ---: |
| `[0218b5a0,0218b5a8)` | Original empty initialization and cleanup hooks | 2 functions, 8 instructions bytes |
| `[0218c290,0218c2ac)` | Retained 0x19000 constant and two 20.12 camera vectors | 28 rodata bytes |
| `[0218c2c0,0218c320)` | Packed resource-name record: icon archive, ARC signature, error archive/language member, pen PAC | 79 initialized string bytes +17 trailing alignment bytes |

The dispatcher at `02000e2c` allocates a 0x2e0-byte scene, invokes initialization,
the driver, cleanup and then frees the scene. Its initialization relocation is
ambiguous across same-address scene overlays. `#pragma force_active on` retains
the original empty hook despite this indirect ownership and preserves the
unreferenced constant. The first full build caught dead stripping of the hook
and orphaned rodata prefix; a second caught the prefix's incorrect zero-value
hypothesis. Direct original-section inspection established its value as 0x19000,
the same size used by the driver's allocator. The final full build passed.

The resource names are actual fixed arrays inside one 96-byte source record.
Four module-local `linker_symbols.json` aliases preserve interior addresses
0218c2d4, 0218c2d8, 0218c2ed and 0218c2fe. The final object comparison has 6/10
sized symbols at 100%; the four remaining unpaired symbols are these aliases,
which the final linker/symbol check verifies. Independently concatenating the
candidate's function sections and comparing its .rodata/.data sections gives
exact equality for all 8, 28 and 96 bytes. Original comparison inputs were not
patched. The aggregate data base was accurately typed as byte[96]; no section
denominator changed.

### Required driver: eight cumulative variants, no coverage credit

`func_ov019_0218b5a8`, `[0218b5a8,0218c178)`, remains original fallback.
The source draft covers resource/display setup and its ten-way read-error scene
state machine, with explicit 14-element 0x28-byte pen-resource array, renderer,
animation table, text handle, two independent 0x70-byte VRAM snapshots and camera
vectors. Existing GameState member access avoided an invariant reason-address
spill. The frame and most instructions then aligned with the original.

| Variant | Score | Hypothesis/result |
| --- | ---: | --- |
| 1 | 85.85% | Initial state machine/layout draft, 4 bytes shorter |
| 2 | 87.96% | Typed local reason view, correct two-argument buffer swap, regrouped multiplication |
| 3 | 95.24% | Actual GameState member subobject removes address spill; separate tick product |
| 4 | 95.90% | Unsigned reason access and corrected resource-output declaration order |
| 5 | 89.81% | Inline register helpers; one helper remained out of line, rejected |
| 6 | 95.90% | Direct register operations and constant-left tick intermediate; closest unsigned draft |
| 7 | 96.30% | Flag clear before phase assignment improves scheduling; signed cycle hypothesis incorrectly calls signed division, rejected |
| 8 | 93.78% | Explicit register read/modify/write locals and all-ULL tick expression |

The numerically highest score is not a valid unsigned-time hypothesis. Continue
from the archived **variant 6** and the unsigned arithmetic contract, using
variant 7 only for its flag-store ordering evidence. There are **8 unproductive
variants on this function across all batches; only 2 remain before the cap**.
Do not reset this count. The bound ended before cap exhaustion. Remaining
differences concern MMIO register scheduling, renderer count/table setup and
timestamp multiplication: original uses successive UMULL/MLA products by 64
and 1000, while candidates combine constants or strength-reduce the first
product to shifts. More original SDK/interface evidence is preferable to
retrying the same arithmetic spelling. Layout/type names in drafts are
hypotheses, not fully recovered classes.

### Final validation and local evidence

- 11 candidate compilations: 3 resource/retention variants and 8 driver variants.
  The hooks and camera vectors already matched on resource variant 1.
- Full `.venv/Scripts/ninja.exe -j2 rom check report sha1`: exit 0; all modules
  and symbols passed, ARM7 preservation passed, exact USA ROM SHA-1
  `c7c3014c237900c8281289b8bc76a781969b6278`.
- Measured delta: +2 functions, +8 instruction bytes, +124 data bytes (including
  the separately identified 17 alignment bytes), +0 literals, BSS or assembly.
  ARM7 and all coverage denominators unchanged.
- No runtime tests were performed. Tokens unmeasured. No integration performed.

Verbose evidence: `build/factory/ov019-cont-*.log`,
`build/factory/ov019-cont-*-evidence.json`,
`build/factory/ov019-cont-driver-best-diagnosis.json`, and the matching ledger
`build/matching/attempts.jsonl`. Preserved drafts are in
`build/factory/ov019-cont-drafts/`: `ReadErrorScene-closest-unsigned-v6.cpp`,
`ReadErrorScene-highest-v7.cpp`, and `ReadErrorScene-latest-v8.cpp`.
Every compared variant also has a candidate snapshot and original/candidate
hashes in its `build/matching/<timestamp-id>/` directory. Batch start/finish
snapshots are under `build/workflow/fleet_ov019_20261002t1610_cont/`.

Remaining required work: the driver, its main-module dependencies and unknown
scene fields, and the four-byte ctor sentinel at `[0218c2ac,0218c2b0)`.
ov019 is incomplete.
