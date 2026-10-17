#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021A85D4; symbol: func_ov017_021a85d4; size: 0x14.
extern "C" void func_ov017_021a85d4(void *object, unsigned value) {
    *(unsigned *)((char *)object + 0x24) = value;
    if (value == 5)
        *(unsigned short *)((char *)object + 0x38) = 0x3c;
}
