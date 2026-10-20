#include <globaldefs.h>
ARM
// Original data: arm9/ov016 @ 0x219d144; symbol: data_ov016_0219d144.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned int MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[];

// Original: arm9/ov016 @ 0x0218D294; symbol: func_ov016_0218d294; size: 0x28.
extern "C" void Resource_SetGlobalFlagAndAdvanceCounterIfReady(void) {
    MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[0] = 1;
    if (MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[5] == 0)
        MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant2[6] += 1;
}
