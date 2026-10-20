#include <globaldefs.h>
ARM
extern "C" void Memory_FreeHPXEAllocatorPointer(void *);
// Original: arm9/ov031 @ 0x02233E3C; symbol: func_ov031_02233e3c; size: 0x10.
extern "C" void WfcUtility_FreeCallbackMemory(void *unused, void *p) { Memory_FreeHPXEAllocatorPointer(p); }
