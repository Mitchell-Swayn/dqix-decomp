#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBB8C; symbol: func_020bbb8c; size: 0xC.
    void Graphics_ForwardSubBG3ScreenLoad(const void *p,unsigned int offset,unsigned int len){
        LoadToSubBG3ScreenData(p,offset,len);
    }
}
