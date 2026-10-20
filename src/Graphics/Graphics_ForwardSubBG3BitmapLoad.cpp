#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToSubBG3ScreenData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBBA4; symbol: func_020bbba4; size: 0xC.
extern "C" void Graphics_ForwardSubBG3BitmapLoad(const void* data,unsigned offset,unsigned length){LoadToSubBG3ScreenData(data,offset,length);}
