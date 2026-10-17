#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#include <System/Cache.h>
struct Context{int pad;unsigned char* data;};extern "C" {Context* ReadGlobalOperationContextPointerAt4();int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int);int func_020d40bc(int,int,void*,unsigned int,unsigned short,unsigned short,unsigned short,int,int);
// Original: arm9/main @ 0x020D59BC; symbol: func_020d59bc; size: 0x130.
int ValidateStatusNineOrTenAndReadSharedActiveFlags(int a,int b,void* data,unsigned int size,unsigned short c,unsigned short d,unsigned short e){unsigned short active=1;unsigned char* state=ReadGlobalOperationContextPointerAt4()->data;int result=TestCurrentStatusAgainstVariadicAllowedValues(2,9,10);if(result)return result;InvalidateDataCacheRange(state+0x188,2);if(!*(unsigned short*)(state+0x188)){InvalidateDataCacheRange(state+0x182,2);active=*(unsigned short*)(state+0x182);InvalidateDataCacheRange(state+0x86,2);}if(!data)return 6;if(!active)return 7;InvalidateDataCacheRange(state+0x7c,2);if(data==*(void**)(state+0x7c))return 6;if(size>512)return 6;if(!size)return 6;CleanCacheRange(data,size);result=func_020d40bc(15,7,data,size,c,d,e,a,b);if(!result)result=2;return result;}}
