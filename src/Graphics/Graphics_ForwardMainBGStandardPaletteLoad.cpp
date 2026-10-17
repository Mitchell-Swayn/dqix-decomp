#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToMainBGStandardPalette(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBABC; symbol: func_020bbabc; size: 0xC.
extern "C" void Graphics_ForwardMainBGStandardPaletteLoad(const void* data,unsigned offset,unsigned length){LoadToMainBGStandardPalette(data,offset,length);}
