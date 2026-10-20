#include "Graphics/VRAMImagePool.h"

// Paired allocations search pools 0 and 3; ordinary allocations initially
// search pools 4, 3, 0, 2, 1. Initialization can change the latter order.
Struct_020f1f14* NNSGfdAllocFrmTexVram_UnknownRoleDataReferences[7] =
{
    &ResetTextureImageVRAM_UnknownRoleInitializedBytes[0], &ResetTextureImageVRAM_UnknownRoleInitializedBytes[3],
    &ResetTextureImageVRAM_UnknownRoleInitializedBytes[4], &ResetTextureImageVRAM_UnknownRoleInitializedBytes[3], &ResetTextureImageVRAM_UnknownRoleInitializedBytes[0],
    &ResetTextureImageVRAM_UnknownRoleInitializedBytes[2], &ResetTextureImageVRAM_UnknownRoleInitializedBytes[1]
};

// The two-byte field following the bank index retains its original 0xffff
// initializer; its purpose has not yet been recovered.
Struct_020f1f14 ResetTextureImageVRAM_UnknownRoleInitializedBytes[5] =
{
    { ~0u, ~0u, 0, 0, 0, { -1, -1 }, 0x00000 },
    { ~0u, ~0u, 0, 1, 1, { -1, -1 }, 0x20000 },
    { ~0u, ~0u, 0, 1, 2, { -1, -1 }, 0x30000 },
    { ~0u, ~0u, 0, 0, 3, { -1, -1 }, 0x40000 },
    { ~0u, ~0u, 0, 0, 4, { -1, -1 }, 0x60000 }
};

TextureImageVRAMConfig ResetTextureImageVRAM_UnknownRoleZeroInitializedStorage;
