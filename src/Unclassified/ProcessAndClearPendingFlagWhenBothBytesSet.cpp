#include <globaldefs.h>
extern "C" {
    extern unsigned char data_02108760[],data_02107820[];
    void ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EABC(void *,void *,int);
// Original: arm9/main @ 0x02045688; symbol: func_02045688; size: 0x48.
    void ProcessAndClearPendingFlagWhenBothBytesSet(unsigned char *p){
        if(!p[6579]||!p[6578])return;
        ResourceHandle_SetGlobalOwnerAndApplyHandleValue_Main0205EABC(data_02108760,data_02107820,0);
        p[6579]=0;
    }
}
