#include <globaldefs.h>
ARM
extern "C" unsigned* ReadGlobalOperationContextPointerAt4();extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,...);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);extern "C" void _Z15CleanCacheRangePKvj(const void*,unsigned);extern "C" void SetGlobalIndexedWordAtOffset18(int,void*);extern "C" int func_020d40bc(int,int,...);
// Original: arm9/main @ 0x020D5B5C; symbol: func_020d5b5c; size: 0xA0.
extern "C" int ValidateCacheAndSubmitPayloadOperation17(void* p,const void* data,unsigned size){unsigned* ctx=ReadGlobalOperationContextPointerAt4();int status=TestCurrentStatusAgainstVariadicAllowedValues(1,8);if(status)return status;_Z24InvalidateDataCacheRangePKvj((unsigned char*)ctx[1]+16,4);if(*(unsigned*)((unsigned char*)ctx[1]+16)==1)return 3;if(size<16)return 6;if(!data)return 6;_Z15CleanCacheRangePKvj(data,size);SetGlobalIndexedWordAtOffset18(17,p);status=func_020d40bc(17,2,data,size);if(!status)return 2;return status;}
