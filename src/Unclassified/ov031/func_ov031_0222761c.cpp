#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290c40;
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **p);
// Original: arm9/ov031 @ 0x0222761C; symbol: func_ov031_0222761c; size: 0x14.
extern "C" void func_ov031_0222761c(void) {
    FreeSharedAllocationAndClearFlagWithInterruptMask((void **)&data_ov031_02290c40);
}
