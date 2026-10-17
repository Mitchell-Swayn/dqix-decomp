#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_ReadInitializedStatus();extern "C" unsigned char* data_021142e0[];extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
// Original: arm9/main @ 0x020D4204; symbol: func_020d4204; size: 0x48.
extern "C" int ReadCachedStatusHalfwordAndClassify(){int result=WirelessCommand_ReadInitializedStatus();if(result)return result;_Z24InvalidateDataCacheRangePKvj(*(void**)(data_021142e0[1]+4),2);unsigned short value=**(unsigned short**)(data_021142e0[1]+4);return value<=1?3:0;}
