#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToMainBG1ScreenData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBA74; symbol: func_020bba74; size: 0xC.
extern "C" void Graphics_ForwardMainBG1ScreenLoad(const void* data,unsigned offset,unsigned length){LoadToMainBG1ScreenData(data,offset,length);}
