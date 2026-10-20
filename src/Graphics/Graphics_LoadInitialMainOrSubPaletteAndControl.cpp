#include <globaldefs.h>
ARM
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
// Original data: arm9/main @ 0x20fe9a4; symbol: data_020fe9a4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage;
// Original data: arm9/main @ 0x20e7390; symbol: data_020e7390.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000000000000000e07f1f7cff03007ce0031f00ef3dff7f204e0000.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsLoadInitialMainOrSubPaletteAndControl_UnknownRoleInitializedBytes[];
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void Graphics_ClearBufferAndUploadCharacterDataByMode();extern "C" void Graphics_BuildSequentialTileMapAndUploadScreenData();
// Original: arm9/main @ 0x02028DEC; symbol: func_02028dec; size: 0xA4.
extern "C" void Graphics_LoadInitialMainOrSubPaletteAndControl(int sub) {
    if(!DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage)return;memcpy(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,GraphicsLoadInitialMainOrSubPaletteAndControl_UnknownRoleInitializedBytes,32);CleanInvalidateCacheRange(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,32);
    if(!sub){volatile unsigned short* control=(volatile unsigned short*)0x0400000a;*control=(*control&0x43)|4;LoadToMainBGStandardPalette(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,32);}
    else {volatile unsigned short* control=(volatile unsigned short*)0x04001008;*control=(*control&0x43)|4;LoadToSubBGStandardPalette(DebugMenuUpdateAndRender_UnknownRoleZeroInitializedStorage,0,32);}
    Graphics_ClearBufferAndUploadCharacterDataByMode();Graphics_BuildSequentialTileMapAndUploadScreenData();
}
