#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int WirelessCommand_InitializeWithMode(void *,void *,int,int);
// Original: arm9/main @ 0x020D4F8C; symbol: func_020d4f8c; size: 0x18.
    int WM_InitializeForListening(void *p,void *a,int b,bool flag){
        int mode=1;
        if(!flag)mode|=2;
        return WirelessCommand_InitializeWithMode(p,a,b,mode);
    }
}
