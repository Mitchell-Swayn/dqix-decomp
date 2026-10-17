#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov025_021ef988[];
extern "C" void Memory_PushAllocatorState(void *);

// Original: arm9/ov025 @ 0x021E4EAC; symbol: func_ov025_021e4eac; size: 0x1C.
extern "C" int Memory_PushGlobalAllocatorState(void) {
    Memory_PushAllocatorState((void *)data_ov025_021ef988[3]);
    return 1;
}
