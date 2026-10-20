#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x021734DC; symbol: Unclassified_IsValuePairWithinInclusiveBounds; size: 0x2C.
// Returns one when the second argument is in 0x43–0xBD and the third argument is in 0x5F–0x6F, inclusive.
extern "C" int TagMode_IsCancelButtonTouched(void *unused, int x, int y) {
    return x >= 0x43 && x <= 0xbd && y >= 0x5f && y <= 0x6f;
}
