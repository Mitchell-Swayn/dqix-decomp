#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov025_021ef988[];
extern "C" void World_ResetIndexedAllocatorAndSnapshot(void *);
// Original: arm9/ov025 @ 0x021E4EE4; symbol: func_ov025_021e4ee4; size: 0x1C.
extern "C" unsigned int Unclassified_InitializeFromGlobalContextField(void) {
    World_ResetIndexedAllocatorAndSnapshot(*(void **)(data_ov025_021ef988 + 0xC));
    return 1;
}
