#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToMainBG2ScreenData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBA98; symbol: func_020bba98; size: 0xC.
extern "C" void Graphics_ForwardMainBG2ScreenLoad(const void* data,unsigned offset,unsigned length){LoadToMainBG2ScreenData(data,offset,length);}
