#include <globaldefs.h>
ARM
extern "C" void *data_ov031_02290d34;
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **);
// Original: arm9/ov031 @ 0x0223C040; symbol: func_ov031_0223c040; size: 0x14.
extern "C" void FreeGlobalSharedAllocationAndClearFlag(void) {
    FreeSharedAllocationAndClearFlagWithInterruptMask(&data_ov031_02290d34);
}
