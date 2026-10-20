#include <globaldefs.h>
ARM
#pragma optimization_level 4
#include <System/LoadToVRAM.h>
// Original: arm9/main @ 0x020BBBBC; symbol: func_020bbbbc; size: 0xC.
extern "C" void Graphics_LoadSubBackgroundStandardPalette(const void* p,unsigned int offset,unsigned int length){LoadToSubBGStandardPalette(p,offset,length);}
