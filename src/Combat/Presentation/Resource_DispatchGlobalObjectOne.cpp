#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" void Combat_PlayActionCategorySoundOnce(void *object, int value);
// Original: arm9/ov025 @ 0x021E85C8; symbol: func_ov025_021e85c8; size: 0x20.
extern "C" int Resource_DispatchGlobalObjectOne(void) {
    Combat_PlayActionCategorySoundOnce(*(void **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc), 1);
    return 1;
}
