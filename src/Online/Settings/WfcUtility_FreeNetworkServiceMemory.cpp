#include <globaldefs.h>
ARM
extern "C" void Memory_FreeHPXEAllocatorPointer(void);
// Original: arm9/ov031 @ 0x02226FD8; symbol: func_ov031_02226fd8; size: 0xC.
extern "C" void WfcUtility_FreeNetworkServiceMemory(void) {
    Memory_FreeHPXEAllocatorPointer();
}
