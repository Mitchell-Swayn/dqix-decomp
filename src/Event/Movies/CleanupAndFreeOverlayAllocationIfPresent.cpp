#include <globaldefs.h>
ARM
extern "C" void ModsDecoder_Destroy(void);
extern "C" void Memory_FreeOverlayAllocation(void *);
// Original: arm9/ov016 @ 0x0218E640; symbol: func_ov016_0218e640; size: 0x20.
extern "C" void CleanupAndFreeOverlayAllocationIfPresent(void *allocation) {
    if (allocation == 0) return;
    if (allocation != 0) {
        ModsDecoder_Destroy();
        Memory_FreeOverlayAllocation(allocation);
    }
}
