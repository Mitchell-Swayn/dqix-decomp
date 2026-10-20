#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5a4; symbol: data_ov031_0224e5a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x02211ACC; symbol: func_ov031_02211acc; size: 0x20.
extern "C" void System_ClearSharedPairUnlessContextStateNine(void) {
    if (OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[0] != 9) {
        OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[0] = 0;
        OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[1] = 0;
    }
}
