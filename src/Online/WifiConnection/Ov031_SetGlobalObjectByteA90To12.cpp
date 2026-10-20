#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d20; symbol: data_ov031_02290d20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223AFF8; symbol: func_ov031_0223aff8; size: 0x18.
extern "C" void Ov031_SetGlobalObjectByteA90To12(void) {
    Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90] = 0x0c;
}
