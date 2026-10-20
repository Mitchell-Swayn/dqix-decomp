#include <globaldefs.h>
ARM
extern "C" char* WMi_GetSystemWork();extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);
// Original: arm9/main @ 0x020D4900; symbol: func_020d4900; size: 0xC4.
extern "C" int WM_GetMPReceiveBufferSize(){char* p=WMi_GetSystemWork();if(TestCurrentStatusAgainstVariadicAllowedValues(2,7,8))return 0;_Z24InvalidateDataCacheRangePKvj(*(char**)(p+4)+12,4);if(*(int*)(*(char**)(p+4)+12)==1)return 0;_Z24InvalidateDataCacheRangePKvj(*(char**)(p+4)+392,2);int zero=*(unsigned short*)(*(char**)(p+4)+392)==0;_Z24InvalidateDataCacheRangePKvj(*(char**)(p+4)+62,2);unsigned count=*(unsigned short*)(*(char**)(p+4)+62);if(zero!=1)return ((count+81)&~31)<<1;{_Z24InvalidateDataCacheRangePKvj(*(char**)(p+4)+248,2);return (((count+12)* *(unsigned short*)(*(char**)(p+4)+248)+41)&~31)<<1;}return ((count+81)&~31)<<1;}
