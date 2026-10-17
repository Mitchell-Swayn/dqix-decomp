#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void DispatchValueToAlternateOrEmbeddedResource(void *,void *,int);
// Original: arm9/main @ 0x0205EB48; symbol: func_0205eb48; size: 0xC.
    void ForwardValueToAlternateOrEmbeddedResource(void *p,void *a,int b){
        DispatchValueToAlternateOrEmbeddedResource(p,a,b);
    }
}
