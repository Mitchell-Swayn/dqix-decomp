#include <globaldefs.h>
#include <std_library_functions.h>
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short* DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20ef74c; symbol: data_020ef74c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 407d00000800000008000000ffffffff.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char DebugMenuInitialize_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x02028F54; symbol: func_02028f54; size: 0x10C.
extern "C" ARM void Graphics_BuildSequentialTileMapAndUploadScreenData()
{
    void* data=DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;
    if(!data)return;
    if(data)memset(data,0,0x6000);
    unsigned short* out;
    unsigned short tile=0;
    int y=0;
    out=DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;
    for(;y<24;++y)for(int x=0;x<32;++x)
    {
        *out=tile;
        out++;
        tile++;
    }
    int mode=*(int*)(DebugMenuInitialize_UnknownRoleInitializedBytes+12);
    CleanInvalidateCacheRange(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0x600);
    if(mode==3)
    {
        LoadToMainBG1ScreenData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,0x600);
        return;
    }if(mode==4)
    {
        LoadToSubBG0ScreenData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,0x600);
        return;
    }if(mode==5)
    {
        LoadToMainBG1ScreenData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,0x600);
        return;
    }if(mode!=6)return;
    LoadToSubBG0ScreenData(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,0x600);
}
