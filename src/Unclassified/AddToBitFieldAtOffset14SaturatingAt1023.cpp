#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
    struct Bits{
        unsigned int value:10;
        unsigned int other:22;
    };
// Original: arm9/main @ 0x020A0140; symbol: func_020a0140; size: 0x3C.
    void AddToBitFieldAtOffset14SaturatingAt1023(unsigned char *p,unsigned int delta){
        Bits *b=(Bits *)(p+20);
        unsigned int value=delta+b->value;
        if(value>1023)value=1023;
        b->value=value;
    }
}
