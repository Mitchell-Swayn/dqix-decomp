#include <globaldefs.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);extern "C" void RecordArray_AllocateTwentyByteEntriesAndResetCount(void*,void*,int);extern "C" void* data_021536c4[2];
// Original: arm9/main @ 0x020E5728; symbol: func_020e5728; size: 0x28.
extern "C" int Script_DispatchConvertedIntegerToTwoGlobalOwners(const void* p){int n=_ZNK6Script9Parameter5ToIntEv(p);RecordArray_AllocateTwentyByteEntriesAndResetCount(data_021536c4[1],data_021536c4[0],n);return 1;}
