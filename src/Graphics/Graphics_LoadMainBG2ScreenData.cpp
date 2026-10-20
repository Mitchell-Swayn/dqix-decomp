#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBA80; symbol: func_020bba80; size: 0xC.
    void Graphics_LoadMainBG2ScreenData(const void *p,unsigned int offset,unsigned int len){
        LoadToMainBG2ScreenData(p,offset,len);
    }
}
