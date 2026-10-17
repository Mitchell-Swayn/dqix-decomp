#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int InitializeRequestAndDispatchCommandZero(void *,void *,int,int);
// Original: arm9/main @ 0x020D4F8C; symbol: func_020d4f8c; size: 0x18.
    int InvokeOperationWithFlagSelectedMode(void *p,void *a,int b,bool flag){
        int mode=1;
        if(!flag)mode|=2;
        return InitializeRequestAndDispatchCommandZero(p,a,b,mode);
    }
}
