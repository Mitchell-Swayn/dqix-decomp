#include <globaldefs.h>
ARM
extern "C" void Runtime_ReleaseNonNullPointerIndirect(void *);

// Original: arm9/ov016 @ 0x0218E790; symbol: func_ov016_0218e790; size: 0x14.
extern "C" void *Memory_ReleaseNonNullPointerIndirectAndReturn(void *pointer) {
    Runtime_ReleaseNonNullPointerIndirect(pointer);
    return pointer;
}
