#pragma optimize_for_size off
#include <globaldefs.h>
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);
// Original: arm9/main @ 0x020C0290; symbol: func_020c0290; size: 0x98.
extern "C" ARM int Object_TestCachedFourHalfwordSignature(char* object){if(!object)return 0;if(!*(unsigned short*)(object+0x3c))return 0;volatile unsigned short values[4];MI_CpuCopy8(object+0x50,(void*)values,8);_Z15CleanCacheRangePKvj((const void*)values,8);if(!*(unsigned*)(object+0x44))if((values[0]==0x2348||values[0]==0xbd8a)&&values[3]==4)return 1;return 0;}
