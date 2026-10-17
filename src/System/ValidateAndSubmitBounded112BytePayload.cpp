#include <globaldefs.h>
#pragma optimize_for_size off
#include "System/Cache.h"
extern "C" int TestCurrentStatusAgainstVariadicAllowedValues(int,int,int,unsigned);
extern "C" void MIi_CpuCopy16(void*,void*,unsigned);
extern "C" unsigned char data_02114d80[];
extern "C" void SetGlobalIndexedWordAtOffset18(int,unsigned);
extern "C" int func_020d40bc(int,int,void*,unsigned,unsigned,unsigned short,unsigned char);
// Original: arm9/main @ 0x020D69CC; symbol: func_020d69cc; size: 0xB8.
extern "C" ARM int ValidateAndSubmitBounded112BytePayload(unsigned owner,void* data,unsigned size,unsigned callback,unsigned short a,unsigned char b)
{
    int status=TestCurrentStatusAgainstVariadicAllowedValues(2,7,9,callback);
    if(status)return status;
    if(!data)return 6;
    if(size>112)return 6;
    {
        MIi_CpuCopy16(data,data_02114d80,size);
        CleanCacheRange(data_02114d80,size);
        SetGlobalIndexedWordAtOffset18(24,owner);
        status=func_020d40bc(24,5,data_02114d80,size,callback,a,b);
        if(!status)status=2;
        return status;
    }return 6;
}
