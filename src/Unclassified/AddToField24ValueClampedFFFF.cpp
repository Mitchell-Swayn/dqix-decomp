#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
    struct Bits{
        unsigned int value:16;
        unsigned int other:16;
    };
// Original: arm9/main @ 0x020A0608; symbol: func_020a0608; size: 0x3C.
    void AddToField24ValueClampedFFFF(unsigned char *p,unsigned int delta){
        Bits *b=(Bits *)(p+36);
        unsigned int value=delta+b->value;
        if(value>65535)value=65535;
        b->value=value;
    }
}
