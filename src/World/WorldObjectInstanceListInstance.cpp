#include "World/WorldObjectInstanceList.h"

extern "C" {
// Original data: arm9/main @ 0x2109020; symbol: data_02109020.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern WorldObjectInstanceList WorldObjectInstanceListGetInstance_UnknownRoleZeroInitializedStorage;

// Original: arm9/main @ 0x0208E9E8; symbol: func_0208e9e8; size: 0xC.
    WorldObjectInstanceList* WorldObjectInstanceList_GetInstance()
    {
        return &WorldObjectInstanceListGetInstance_UnknownRoleZeroInitializedStorage;
    }
}
