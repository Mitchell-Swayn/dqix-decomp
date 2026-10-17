#include <globaldefs.h>
ARM
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **);

// Original: arm9/ov031 @ 0x0223D884; symbol: func_ov031_0223d884; size: 0x1C.
extern "C" void Memory_FreeSharedAllocationFromFirstArgument(void *allocation, int second, int third, int fourth) {
    FreeSharedAllocationAndClearFlagWithInterruptMask(&allocation);
}
