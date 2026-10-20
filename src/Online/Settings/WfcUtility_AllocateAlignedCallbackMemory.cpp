#include <globaldefs.h>
ARM
extern "C" void Memory_AllocateZeroedBlock(void *object, unsigned value, unsigned extra);
// Original: arm9/ov031 @ 0x02233E28; symbol: func_ov031_02233e28; size: 0x14.
extern "C" void WfcUtility_AllocateAlignedCallbackMemory(void *unused, void *object, unsigned extra) {
    Memory_AllocateZeroedBlock(object, 0x20, extra);
}
