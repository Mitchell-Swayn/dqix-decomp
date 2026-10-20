#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBAA4; symbol: func_020bbaa4; size: 0xC.
    void Graphics_LoadMainBG3ScreenData(const void *p,unsigned int offset,unsigned int len){
        LoadToMainBG3ScreenData(p,offset,len);
    }
}
