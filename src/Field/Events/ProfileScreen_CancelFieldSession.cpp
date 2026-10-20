#include <globaldefs.h>
ARM
extern "C" void Memory_CleanupOverlayContextAllocator(void *);
// Original: arm9/ov017 @ 0x021C1A10; symbol: func_ov017_021c1a10; size: 0x14.
extern "C" void ProfileScreen_CancelFieldSession(void *object) {
    *((unsigned char *)object + 1) = 1;
    Memory_CleanupOverlayContextAllocator(object);
}
