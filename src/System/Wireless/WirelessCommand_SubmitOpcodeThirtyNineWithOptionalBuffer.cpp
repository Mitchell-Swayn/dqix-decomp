#include <globaldefs.h>
#include <System/Cache.h>
extern "C" {
    int ReadCachedStatusHalfwordAndClassify();
    void SetGlobalIndexedWordAtOffset18(int,int);
    int func_020d40bc(int,int,unsigned int,void *,int);
// Original: arm9/main @ 0x020D6950; symbol: func_020d6950; size: 0x7C.
    int WirelessCommand_SubmitOpcodeThirtyNineWithOptionalBuffer(int a,unsigned int mode,int b,void *buffer){
        int result=ReadCachedStatusHalfwordAndClassify();
        if(result)return result;
        if(mode>3)return 6;
        if(mode){
            if(!buffer)return 6;
            CleanCacheRange(buffer,80);
        }SetGlobalIndexedWordAtOffset18(39,a);
        result=func_020d40bc(39,3,mode,buffer,b);
        return result?result:2;
    }
}
