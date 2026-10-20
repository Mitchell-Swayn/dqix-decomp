#include <globaldefs.h>
ARM
extern "C" void ReleaseResourceAndAllocator(void);
// Original: arm9/ov017 @ 0x021C0568; symbol: func_ov017_021c0568; size: 0x18.
extern "C" int Resource_ReleaseResourceAndMarkObjectActive(void *p) {
    ReleaseResourceAndAllocator();
    *((unsigned char *)p + 1) = 1;
    return 1;
}
