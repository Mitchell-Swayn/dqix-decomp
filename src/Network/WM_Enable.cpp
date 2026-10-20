#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int WirelessCommand_EnableWithMode(void *,int);
// Original: arm9/main @ 0x020D4E48; symbol: func_020d4e48; size: 0x10.
    int WM_Enable(void *p){
        return WirelessCommand_EnableWithMode(p,0);
    }
}
