#include <globaldefs.h>
ARM
extern "C" volatile unsigned data_02108ed8[];extern "C" int _ZNK6Script9Parameter5ToIntEv(void*);extern "C" void Object_AllocateTwentyFourByteEntries(unsigned,unsigned,int);
// Original: arm9/main @ 0x0207ED1C; symbol: func_0207ed1c; size: 0x2C.
extern "C" int Script_AppendIndexedHalfwordRecord(void* p){int n=_ZNK6Script9Parameter5ToIntEv(p);Object_AllocateTwentyFourByteEntries(data_02108ed8[1],data_02108ed8[0],(short)n);return 1;}
