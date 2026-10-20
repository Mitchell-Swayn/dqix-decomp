#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBB44; symbol: func_020bbb44; size: 0xC.
    void Graphics_ForwardSubBG1CharacterLoad(const void *p,unsigned int offset,unsigned int len){
        LoadToSubBG1CharacterData(p,offset,len);
    }
}
