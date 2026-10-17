#include <globaldefs.h>
ARM
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
extern "C" void* data_020fe9a4;
extern "C" char data_020e7390[];
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" void Graphics_ClearBufferAndUploadCharacterDataByMode();extern "C" void Graphics_BuildSequentialTileMapAndUploadScreenData();
// Original: arm9/main @ 0x02028DEC; symbol: func_02028dec; size: 0xA4.
extern "C" void Graphics_LoadInitialMainOrSubPaletteAndControl(int sub) {
    if(!data_020fe9a4)return;memcpy(data_020fe9a4,data_020e7390,32);CleanInvalidateCacheRange(data_020fe9a4,32);
    if(!sub){volatile unsigned short* control=(volatile unsigned short*)0x0400000a;*control=(*control&0x43)|4;LoadToMainBGStandardPalette(data_020fe9a4,0,32);}
    else {volatile unsigned short* control=(volatile unsigned short*)0x04001008;*control=(*control&0x43)|4;LoadToSubBGStandardPalette(data_020fe9a4,0,32);}
    Graphics_ClearBufferAndUploadCharacterDataByMode();Graphics_BuildSequentialTileMapAndUploadScreenData();
}
