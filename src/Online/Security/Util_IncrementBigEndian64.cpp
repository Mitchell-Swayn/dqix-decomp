#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022093D0; symbol: func_ov031_022093d0; size: 0x24.
extern "C" void Util_IncrementBigEndian64(unsigned char *end) {
    int remaining = 8;
    do {
        --end;
        unsigned int value = ((unsigned int)*end + 1) & 0xff;
        *end = (unsigned char)value;
        if (value != 0)
            break;
    } while (--remaining != 0);
}
