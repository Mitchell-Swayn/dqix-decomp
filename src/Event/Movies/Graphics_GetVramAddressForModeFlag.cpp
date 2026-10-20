#include <globaldefs.h>
ARM
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned int MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov016 @ 0x0218BE5C; symbol: func_ov016_0218be5c; size: 0x20.
extern "C" unsigned int Graphics_GetVramAddressForModeFlag(void) {
    if (MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[6] == 0)
        return 0x06820000;
    return 0x06800000;
}
