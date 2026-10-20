#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void NNSi_SndPlayerPause(void *,unsigned char);
// Original: arm9/main @ 0x020BC068; symbol: func_020bc068; size: 0x10.
    void ResourceHandle_SetSequencePaused(void **p,unsigned char value){
        NNSi_SndPlayerPause(*p,value);
    }
}
