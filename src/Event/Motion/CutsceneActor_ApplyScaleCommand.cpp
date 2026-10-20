// Original identity: CallHelperWithGlobalAndObjectField70AndThreeWords
struct ThreeWords { unsigned x, y, z; };
// Original data: arm9/ov001 @ 0x2165884; symbol: data_ov001_02165884.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void *AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage;
extern "C" void CutsceneActor_SetIndexedScaleFromVector(void *, unsigned, ThreeWords);
// Original: arm9/ov001 @ 0x02159B5C; symbol: func_ov001_02159b5c; size: 0x38.
extern "C" int CutsceneActor_ApplyScaleCommand(const void *positionRecord, const void *object) {
    ThreeWords position = *(const ThreeWords *)((const char *)positionRecord + 4);
    CutsceneActor_SetIndexedScaleFromVector(AdvanceSessionCommandLists_UnknownRoleZeroInitializedStorage, *(const unsigned *)((const char *)object + 0x70), position);
    return 0;
}
