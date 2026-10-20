#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
#pragma optimization_level 4
// Original: arm9/main @ 0x020BBB98; symbol: func_020bbb98; size: 0xC.
extern "C" void Graphics_LoadSubBG2ScreenData(const void* data,unsigned offset,unsigned length) { LoadToSubBG2ScreenData(data,offset,length); }
