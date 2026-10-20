#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBA5C; symbol: func_020bba5c; size: 0xC.
    void Graphics_LoadMainBG3CharacterData(const void *p,unsigned int offset,unsigned int len){
        LoadToMainBG3CharacterData(p,offset,len);
    }
}
