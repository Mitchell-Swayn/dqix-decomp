#include <globaldefs.h>
#include <System/LoadToVRAM.h>
#pragma optimization_level 4
// Original: arm9/main @ 0x020BBA68; symbol: func_020bba68; size: 0xC.
extern "C" ARM void Object_InvokeLoadToMainBG0ScreenData(const void* data, unsigned offset, unsigned length) { LoadToMainBG0ScreenData(data,offset,length); }
