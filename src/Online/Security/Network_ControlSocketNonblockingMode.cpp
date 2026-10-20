#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022075A4; symbol: func_ov031_022075a4; size: 0x50.
extern "C" int Network_ControlSocketNonblockingMode(void *obj, int action, unsigned int flags) {
    if (obj == 0) return -1;
    switch (action) {
    case 3:
        if (*(signed char *)((char *)obj + 0x72) == 1) return 0;
        return 4;
    case 4:
        if ((flags & 4) != 0) *(unsigned char *)((char *)obj + 0x72) = 0;
        else *(unsigned char *)((char *)obj + 0x72) = 1;
        goto done;
    default:
        goto done;
    }
done:
    return 0;
}
