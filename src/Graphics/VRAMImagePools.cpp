#include "Graphics/VRAMImagePool.h"

// Paired allocations search pools 0 and 3; ordinary allocations initially
// search pools 4, 3, 0, 2, 1. Initialization can change the latter order.
Struct_020f1f14* data_020f1ef8[7] =
{
    &data_020f1f14[0], &data_020f1f14[3],
    &data_020f1f14[4], &data_020f1f14[3], &data_020f1f14[0],
    &data_020f1f14[2], &data_020f1f14[1]
};

// The two-byte field following the bank index retains its original 0xffff
// initializer; its purpose has not yet been recovered.
Struct_020f1f14 data_020f1f14[5] =
{
    { ~0u, ~0u, 0, 0, 0, { -1, -1 }, 0x00000 },
    { ~0u, ~0u, 0, 1, 1, { -1, -1 }, 0x20000 },
    { ~0u, ~0u, 0, 1, 2, { -1, -1 }, 0x30000 },
    { ~0u, ~0u, 0, 0, 3, { -1, -1 }, 0x40000 },
    { ~0u, ~0u, 0, 0, 4, { -1, -1 }, 0x60000 }
};

TextureImageVRAMConfig data_0210cf84;
