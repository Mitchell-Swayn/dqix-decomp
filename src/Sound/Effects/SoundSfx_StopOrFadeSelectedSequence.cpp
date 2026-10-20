#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void Resource_DispatchValueToAlternateOrEmbeddedResource(void *,void *,int);
// Original: arm9/main @ 0x0205EB48; symbol: func_0205eb48; size: 0xC.
    void SoundSfx_StopOrFadeSelectedSequence(void *p,void *a,int b){
        Resource_DispatchValueToAlternateOrEmbeddedResource(p,a,b);
    }
}
