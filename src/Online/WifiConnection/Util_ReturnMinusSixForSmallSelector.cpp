#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022143EC; symbol: Util_ReturnMinusSixForSmallSelector; size: 0x8.
// Returns -6; its caller uses this result for values below selector 5.
extern "C" int Util_ReturnMinusSixForSmallSelector(void) {
    return -6;
}
