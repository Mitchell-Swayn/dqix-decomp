#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" void *CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E8724; symbol: func_ov025_021e8724; size: 0x1C.
extern "C" int Resource_StoreObjectByte8InGlobal5D0(void *object) {
    *((unsigned char *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3] + 0x5d0) = *((unsigned char *)object + 8);
    return 1;
}
