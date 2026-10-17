#include <globaldefs.h>
#include <System/LoadToVRAM.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original: arm9/main @ 0x020BBB20; symbol: func_020bbb20; size: 0xC.
    void Graphics_ForwardMainOAMLoad(const void *p,unsigned int offset,unsigned int len){
        LoadToMainOAM(p,offset,len);
    }
}
