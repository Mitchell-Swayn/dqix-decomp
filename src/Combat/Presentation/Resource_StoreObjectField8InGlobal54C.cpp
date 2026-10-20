#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" void *CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E628C; symbol: func_ov025_021e628c; size: 0x1C.
extern "C" int Resource_StoreObjectField8InGlobal54C(void *object) {
    *(unsigned int *)((char *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x54c) = *(unsigned int *)((char *)object + 8);
    return 1;
}
