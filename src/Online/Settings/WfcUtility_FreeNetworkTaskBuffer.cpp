#include <globaldefs.h>
ARM
extern "C" void Memory_FreeHPXEAllocatorPointer(void);
// Original: arm9/ov031 @ 0x02227CD8; symbol: func_ov031_02227cd8; size: 0xC.
extern "C" void WfcUtility_FreeNetworkTaskBuffer(void) {
    Memory_FreeHPXEAllocatorPointer();
}
