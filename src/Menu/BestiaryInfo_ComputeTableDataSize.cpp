#include <globaldefs.h>
ARM
#pragma optimization_level 2
#pragma opt_propagation off
// Retain the original size calculation without folding its alignment delta.
// Original: arm9/main @ 0x02096FD8; symbol: func_02096fd8; size: 0x28.
extern "C" int BestiaryInfo_ComputeTableDataSize(unsigned short* header) {
    int fixedBytes=header[0]*0x30;
    unsigned alignedEnd=(fixedBytes+header[1]*4+3)&~3u;
    int tailBytes=(int)alignedEnd-fixedBytes;
    return fixedBytes+tailBytes;
}
