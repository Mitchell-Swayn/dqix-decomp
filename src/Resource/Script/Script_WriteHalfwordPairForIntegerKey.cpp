#include <globaldefs.h>
ARM
extern "C" void* data_02109ba8;extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);extern "C" void PointList_AppendXYWithinTwentyEntryLimit(void*,int,void*);
// Original: arm9/main @ 0x0209A7BC; symbol: func_0209a7bc; size: 0x48.
extern "C" int Script_WriteHalfwordPairForIntegerKey(char* p){int n=_ZNK6Script9Parameter5ToIntEv(p);unsigned short pair[2];pair[0]=_ZNK6Script9Parameter5ToIntEv(p+8);pair[1]=_ZNK6Script9Parameter5ToIntEv(p+16);PointList_AppendXYWithinTwentyEntryLimit(data_02109ba8,n,pair);return 1;}
