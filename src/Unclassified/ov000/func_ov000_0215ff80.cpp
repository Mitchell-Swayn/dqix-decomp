#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FF80; symbol: func_ov000_0215ff80; size: 0x20.
extern "C" int func_ov000_0215ff80(void *object, int index) {
    if (index >= 3)
        return -1;
    if (index < 0)
        return -1;
    return *((short *)object + index + 7);
}
