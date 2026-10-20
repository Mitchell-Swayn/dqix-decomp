#include <globaldefs.h>
ARM
// Original data: arm9/ov016 @ 0x219d0c0; symbol: data_ov016_0219d0c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned int MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov016 @ 0x0218C024; symbol: func_ov016_0218c024; size: 0x28.
extern "C" void System_SetGlobalActiveAndCountIfIdle(void) {
    MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[1] = 1;
    if (MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[14] == 0)
        MemoryAllocateSafe_UnknownRoleZeroInitializedStorage[15] += 1;
}
