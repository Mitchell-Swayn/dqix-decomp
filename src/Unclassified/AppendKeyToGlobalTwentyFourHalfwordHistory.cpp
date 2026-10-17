#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" unsigned short data_021098f4[];extern "C" void Object_AppendKeyToTwentyFourEntryHistory(unsigned short*,unsigned);
// Original: arm9/main @ 0x0209953C; symbol: func_0209953c; size: 0x18.
extern "C" void AppendKeyToGlobalTwentyFourHalfwordHistory(unsigned value){Object_AppendKeyToTwentyFourEntryHistory(data_021098f4,value);}
