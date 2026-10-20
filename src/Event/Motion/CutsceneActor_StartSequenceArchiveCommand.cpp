#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x216587c; symbol: data_ov001_0216587c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char ResourceDispatchGlobalPairAndReturnZero_UnknownRoleZeroInitializedStorage[];
extern "C" int ResourceHandle_StartOrDeferSequenceArchiveEntry(char *p, int a, int b, void *file);
// Original: arm9/ov001 @ 0x02159990; symbol: func_ov001_02159990; size: 0x28.
extern "C" int CutsceneActor_StartSequenceArchiveCommand(void *object) {
    ResourceHandle_StartOrDeferSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, *(int *)((char *)object + 0x10), 0, ResourceDispatchGlobalPairAndReturnZero_UnknownRoleZeroInitializedStorage);
    return 0;
}
