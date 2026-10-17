#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBA38; symbol: func_020bba38; size: 0xC.
    void Graphics_LoadMainBG0CharacterData(const void *p,unsigned int offset,unsigned int len){
        LoadToMainBG0CharacterData(p,offset,len);
    }
}
