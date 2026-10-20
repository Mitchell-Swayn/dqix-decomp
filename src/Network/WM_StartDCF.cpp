#include <globaldefs.h>
ARM
extern "C" unsigned* WMi_GetSystemWork();extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,...);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);extern "C" void WMi_SetCallbackTable(int,void*);extern "C" int WMi_SendCommand(int,int,...);
// Original: arm9/main @ 0x020D5B5C; symbol: func_020d5b5c; size: 0xA0.
extern "C" int WM_StartDCF(void* p,const void* data,unsigned size){unsigned* ctx=WMi_GetSystemWork();int status=TestCurrentStatusAgainstVariadicAllowedValues(1,8);if(status)return status;_Z24InvalidateDataCacheRangePKvj((unsigned char*)ctx[1]+16,4);if(*(unsigned*)((unsigned char*)ctx[1]+16)==1)return 3;if(size<16)return 6;if(!data)return 6;_Z15CleanCacheRangePKvj(data,size);WMi_SetCallbackTable(17,p);status=WMi_SendCommand(17,2,data,size);if(!status)return 2;return status;}
