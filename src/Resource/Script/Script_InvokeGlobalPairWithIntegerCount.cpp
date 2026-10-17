#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);extern "C" void* data_020fdd30[];extern "C" void AllocateAndInitializeSixteenByteEntries(void*,void*,int);
// Original: arm9/main @ 0x02027F90; symbol: func_02027f90; size: 0x24.
extern "C" bool Script_InvokeGlobalPairWithIntegerCount(void* parameter){int count=_ZNK6Script9Parameter5ToIntEv(parameter);AllocateAndInitializeSixteenByteEntries(data_020fdd30[0],data_020fdd30[1],count);return true;}
