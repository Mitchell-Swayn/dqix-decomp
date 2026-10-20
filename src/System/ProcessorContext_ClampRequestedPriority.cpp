#pragma optimization_level 4
#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020D9808; symbol: func_020d9808; size: 0x20.
    int ProcessorContext_ClampRequestedPriority(int *a,int *b,int *c){
        int lo=*b;
        int value=*a;
        if(value<=lo)value=lo;
        int hi=*c;
        if(value>=hi)value=hi;
        return value;
    }
}
