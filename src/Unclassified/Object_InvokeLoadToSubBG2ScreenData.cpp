#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadToSubBG2ScreenData(const void*,unsigned,unsigned);
// Original: arm9/main @ 0x020BBB80; symbol: func_020bbb80; size: 0xC.
extern "C" void Object_InvokeLoadToSubBG2ScreenData(const void* data,unsigned offset,unsigned length){LoadToSubBG2ScreenData(data,offset,length);}
