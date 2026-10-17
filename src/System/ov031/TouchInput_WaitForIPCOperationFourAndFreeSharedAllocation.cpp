#include <globaldefs.h>
ARM
extern "C" void TouchInput_RequestIPCOperationFour();
extern "C" void WaitForGlobalMaskBitsToClear(unsigned);
extern "C" unsigned TestFieldBitsAtOffset38(unsigned);
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void**);
extern "C" char data_ov031_02290d44[];
// Original: arm9/ov031 @ 0x0223D06C; symbol: func_ov031_0223d06c; size: 0x38.
extern "C" void TouchInput_WaitForIPCOperationFourAndFreeSharedAllocation(void) {
    do {
        TouchInput_RequestIPCOperationFour();
        WaitForGlobalMaskBitsToClear(4);
    } while (TestFieldBitsAtOffset38(4) != 0);
    FreeSharedAllocationAndClearFlagWithInterruptMask((void**)data_ov031_02290d44);
}
