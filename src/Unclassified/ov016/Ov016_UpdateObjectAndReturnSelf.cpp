#include <globaldefs.h>
ARM
extern "C" void Memory_ReleaseOwnedResources(void *object);
// Original: arm9/ov016 @ 0x0218E7EC; symbol: func_ov016_0218e7ec; size: 0x14.
extern "C" void *Ov016_UpdateObjectAndReturnSelf(void *object) {
    Memory_ReleaseOwnedResources(object);
    return object;
}
