#include <globaldefs.h>
ARM
// Original: arm9/ov024 @ 0x021F6AE8; symbol: func_ov024_021f6ae8; size: 0x40.
extern "C" int CoordinateScale_ApplyNestedFlagDefaults(void* object) {
    void* nested = *(void**)((char*)object + 8);
    if (nested != 0 && ((((unsigned)*(unsigned short*)((char*)nested + 0xa) << 19) >> 31) != 0)) {
        *(unsigned*)((char*)object + 0x1c) = 0x40000000;
        *(unsigned*)((char*)object + 0x20) = 0x3f800000;
    } else {
        *(unsigned*)((char*)object + 0x1c) = 0;
        *(unsigned*)((char*)object + 0x20) = 0;
    }
    return 1;
}
