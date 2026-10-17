#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBB68; symbol: func_020bbb68; size: 0xC.
    void Graphics_ForwardSubBG0ScreenLoad(const void *p,unsigned int offset,unsigned int len){
        LoadToSubBG0ScreenData(p,offset,len);
    }
}
