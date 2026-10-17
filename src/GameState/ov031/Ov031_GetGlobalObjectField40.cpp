#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d18[];
// Original: arm9/ov031 @ 0x02239BE8; symbol: func_ov031_02239be8; size: 0x14.
extern "C" unsigned int Ov031_GetGlobalObjectField40(void) {
    return *(unsigned int *)((char *)data_ov031_02290d18[1] + 0x40);
}
