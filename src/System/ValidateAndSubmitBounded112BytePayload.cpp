#include <globaldefs.h>
#pragma optimize_for_size off
#include "System/Cache.h"
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int,unsigned);
extern "C" void MIi_CpuCopy16(void*,void*,unsigned);
// Original data: arm9/main @ 0x2114d80; symbol: data_02114d80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char ValidateAndSubmitBounded112BytePayload_UnknownRoleZeroInitializedStorage[];
extern "C" void WMi_SetCallbackTable(int,unsigned);
extern "C" int WMi_SendCommand(int,int,void*,unsigned,unsigned,unsigned short,unsigned char);
// Original: arm9/main @ 0x020D69CC; symbol: func_020d69cc; size: 0xB8.
extern "C" ARM int ValidateAndSubmitBounded112BytePayload(unsigned owner,void* data,unsigned size,unsigned callback,unsigned short a,unsigned char b)
{
    int status=TestCurrentStatusAgainstVariadicAllowedValues(2,7,9,callback);
    if(status)return status;
    if(!data)return 6;
    if(size>112)return 6;
    {
        MIi_CpuCopy16(data,ValidateAndSubmitBounded112BytePayload_UnknownRoleZeroInitializedStorage,size);
        CleanCacheRange(ValidateAndSubmitBounded112BytePayload_UnknownRoleZeroInitializedStorage,size);
        WMi_SetCallbackTable(24,owner);
        status=WMi_SendCommand(24,5,ValidateAndSubmitBounded112BytePayload_UnknownRoleZeroInitializedStorage,size,callback,a,b);
        if(!status)status=2;
        return status;
    }return 6;
}
