#include <globaldefs.h>
ARM
extern "C" void WfcUtility_FreeAllocationAndClearPointer(void **);
// Original: arm9/ov031 @ 0x0223BF2C; symbol: func_ov031_0223bf2c; size: 0x1C.
extern "C" void Memory_FreeSharedAllocation(void *p, int a, int b, int c) {
    WfcUtility_FreeAllocationAndClearPointer(&p);
}
