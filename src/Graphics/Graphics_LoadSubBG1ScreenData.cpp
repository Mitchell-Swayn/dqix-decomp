#include <globaldefs.h>
ARM
#include <System/LoadToVRAM.h>
#pragma optimization_level 4
// Original: arm9/main @ 0x020BBB74; symbol: func_020bbb74; size: 0xC.
extern "C" void Graphics_LoadSubBG1ScreenData(const void* data,unsigned offset,unsigned length){LoadToSubBG1ScreenData(data,offset,length);}
