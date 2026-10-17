#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020BC210; symbol: func_020bc210; size: 0x2C.
    void ResourceHandle_SetOptionalModeAndHalfwordPair(unsigned char * volatile *p,short a,short b){
        if(!*p)return;
        *(short *)(*p+52)=2;
        *(short *)(*p+56)=a;
        *(short *)(*p+58)=b;
    }
}
