#include <globaldefs.h>
ARM
extern "C" void FreeWithGlobalSafeAllocator(void *ptr);
// Original: arm9/ov016 @ 0x0218E7B0; symbol: func_ov016_0218e7b0; size: 0xC.
extern "C" void Memory_FreeOverlayAllocation(void *ptr) { FreeWithGlobalSafeAllocator(ptr); }
