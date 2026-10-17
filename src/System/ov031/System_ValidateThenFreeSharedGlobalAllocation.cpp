#include <globaldefs.h>
ARM
extern "C" int func_ov031_02222a10(void);
extern "C" void DisableInterruptsAndHaltForever(void);
extern "C" unsigned char data_ov031_02290c48[];
extern "C" void FreeSharedAllocationAndClearFlagWithInterruptMask(void **);
// Original: arm9/ov031 @ 0x02227BA4; symbol: func_ov031_02227ba4; size: 0x24.
extern "C" void System_ValidateThenFreeSharedGlobalAllocation(void) {
    if (func_ov031_02222a10() != 1)
        DisableInterruptsAndHaltForever();
    FreeSharedAllocationAndClearFlagWithInterruptMask((void **)data_ov031_02290c48);
}
