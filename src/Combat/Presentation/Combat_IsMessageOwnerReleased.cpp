#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021EE438; symbol: func_ov025_021ee438; size: 0x50.
extern "C" int Combat_IsMessageOwnerReleased(void* object, void* candidate) {
    if (!candidate) return 1;
    if (candidate == *(void**)((char*)object + 0x158)) return 0;
    for (int i = 0; i < *(volatile unsigned char*)((char*)object + 0x150); ++i) {
        if (*(void**)((char*)object + 0xb0 + i * 4) == candidate) return 0;
    }
    return 1;
}
