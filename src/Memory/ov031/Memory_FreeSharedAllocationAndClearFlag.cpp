#include <globaldefs.h>
ARM
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **p);
extern "C" void *data_ov031_02290cfc;
// Original: arm9/ov031 @ 0x02235C5C; symbol: func_ov031_02235c5c; size: 0x14.
extern "C" void Memory_FreeSharedAllocationAndClearFlag(void) {
    FreeSharedAllocationAndClearFlagWithInterruptMask(&data_ov031_02290cfc);
}
