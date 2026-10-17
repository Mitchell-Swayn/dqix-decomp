#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021761C8; symbol: func_ov000_021761c8; size: 0x24.
extern "C" void *Unclassified_GetPointerAtIndexOrDefaultZero(void *object, int index) {
    if (index < 0 || index >= 8)
        index = 0;
    return *(void **)((unsigned char *)object + 0x1d1c + index * 4);
}
