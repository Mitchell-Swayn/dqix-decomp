#include <globaldefs.h>
#include <System/DMA.h>
#include <System/LoadToVRAM.h>
// Original data: arm9/main @ 0x21052b4; symbol: data_021052b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant5[];
// Original data: arm9/main @ 0x21056b4; symbol: data_021056b4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1024 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsGetSubOamStagingBuffer_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0203BDB0; symbol: func_0203bdb0; size: 0x90.
extern "C" void Graphics_LoadAndClearEnabledOamScreens(unsigned char* state) {
    if (state[0xc] != 0) {
        LoadToMainOAM(MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant5, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)MoviePlayDualScreenFiles_UnknownRoleZeroInitializedStorage_Variant5, 0xc0, 0x400);
    }
    if (state[0xd] != 0) {
        LoadToSubOAM(GraphicsGetSubOamStagingBuffer_UnknownRoleZeroInitializedStorage, 0, 0x400);
        DMAMemsetSynchronous(3, (unsigned int)GraphicsGetSubOamStagingBuffer_UnknownRoleZeroInitializedStorage, 0xc0, 0x400);
    }
    if (state[0xc] != 0 || state[0xd] != 0) *(unsigned short*)(state + 0x520) = 4;
}
