#include <globaldefs.h>
ARM
extern "C" unsigned int Network_BindSocketPort(void *object, unsigned int value);
// Original: arm9/ov031 @ 0x02207204; symbol: func_ov031_02207204; size: 0x2C.
extern "C" unsigned int Network_BindSocketAddress(void *object, const void *record) {
    int value = *(const unsigned short *)((const char *)record + 2);
    unsigned short swapped = (unsigned short)(((value >> 8) & 0xff) | ((value << 8) & 0xff00));
    return Network_BindSocketPort(object, swapped);
}
