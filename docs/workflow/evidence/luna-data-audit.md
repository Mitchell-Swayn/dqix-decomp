# ARM9 initialized-data audit: graphics candidates

Read-only triage against baseline `1fd54b4eec8bc0c47973c168e89980953f4f1748`.
Acceptance and scope follow `GOALS.md` and `docs/workflow/README.md`. No source,
symbol, delink, queue, ROM, or build artifact was changed. The six ranges below
are holes in `config/usa/arm9/delinks.txt`'s source-owned `.data` ranges. The
address map still has symbols and source references for them, so these are
fallback-backed candidates, not newly discovered code/data coverage. They are
all ARM9 graphics/middleware data; none is GameState, World, or ARM7.

## Candidate ranges

| USA ARM9 range | Size | Current source owner | Evidence that type/value/callers are recoverable |
|---|---:|---|---|
| `0x020f1c6c-0x020f1c84` | `0x18` | No `.data` owner in delinks; fallback gap. Neighboring source owner starts at `0x020f1ce0`. | `src/Graphics/NSBXX/Animation.cpp` declares a count (`data_020f1c6c`, comment says 5) and five typed callback pointers at `0x1c70..0x1c80`. `VAV.cpp`, `JACSetup.cpp`, `MAT.cpp`, `MPT.cpp`, and `MAM.cpp` assign those callbacks into animation instances; the format-specific callback implementations are present in those files. |
| `0x020f1c84-0x020f1c90` | `0x0c` | No `.data` owner; same fallback gap. | `Animation.cpp` declares three typed visibility/joint/material processing callbacks. `PopulateModelRenderContext` copies them into its corresponding callback fields. The callback functions are present in `AnimationProcessing.cpp`. |
| `0x020f1c90-0x020f1ce0` | `0x50` | No `.data` owner; ends exactly where `src/Graphics/NSBXX/RenderModelCallbacks.cpp` begins owning data (`0x1ce0-0x1cec`). | `Animation.cpp` declares `AnimationTypeDescription data_020f1c90[]` as `{NSBXXAnimationSignature, initializer}` and indexes it from `InitializeModelAnimation`; the five format-specific initializers are present. `NSBXXAnimationSignature` is declared in `include/Graphics/NSBXX/NSBXX.h`. Check the first word/padding before fixing the initializer table's exact start: the map also labels `data_020f1c94`. |
| `0x020f1e88-0x020f1ea8` | `0x20` | No `.data` owner; fallback gap. The next owned range resumes at `0x020f1ee8` (`VRAMDefaults`). | `RenderCommandProcs.cpp` declares an eight-entry function-pointer table typed `(Matrix4x4*, MaterialRenderData*)`; `BoneMatrixDataSubmissionProc_Type0` indexes it with `renderData->flags_ & 7`. The eight matrix-operation implementations are in the same translation unit. |
| `0x020f1ea8-0x020f1ec8` | `0x20` | No `.data` owner; fallback gap. | Same table type in `RenderCommandProcs.cpp`; `BoneMatrixDataSubmissionProc_Type1` indexes it using the same three-bit mode. The target operation functions are present in the translation unit. |
| `0x020f1ec8-0x020f1ee8` | `0x20` | No `.data` owner; ends at `VRAMDefaults`' explicit owner boundary `0x020f1ee8-0x020f1ef8`. | Same table type in `RenderCommandProcs.cpp`; `BoneMatrixDataSubmissionProc_Type2` indexes it using the same mode. The target operation functions are present in the translation unit. |

For all six, `config/usa/arm9/symbols.txt` has address labels at the table starts
and nearby boundaries, but those labels have generic `kind:data(any)` types. The
delink map has no source-owned `.data` entry covering these addresses. Exact
fallback extents were cross-checked against surrounding data owners; keep each
candidate at the listed boundary rather than extending into the next owner's
bytes.

## Integration hazards and useful next step

- Function-pointer tables require ARM relocations to the exact compiled targets;
  an initializer that merely resembles the original pointer bytes is not enough.
- The animation-description table's start/packing needs confirmation from target
  bytes and relocations, especially `0x1c90` versus the symbol at `0x1c94`.
- The repository has JPN address/name remaps for several of these globals. Keep
  any source names/macros consistent with existing USA/JPN conditional mapping.
- Source call sites prove the signatures and consumers, but do not alone prove
  each stored target/value. Compare each candidate object with the original and
  preserve all unselected gaps as fallback; do not count this note as source
  credit or a coverage delta.

Best bounded follow-up is the three 32-byte mode-dispatch tables (`0x1e88-0x1ee8`)
or the animation callback globals (`0x1c6c–0x1c90`); their types and consumers
are clearest. Treat `0x1c90–0x1ce0` as a separate follow-up after checking its
record layout and relocation targets.
