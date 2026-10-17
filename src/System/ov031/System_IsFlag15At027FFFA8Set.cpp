#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0222AA9C; symbol: func_ov031_0222aa9c; size: 0x20.
extern "C" int System_IsFlag15At027FFFA8Set(void) {
    int value = *(volatile unsigned short *)0x027fffa8;
    return ((value & 0x8000) >> 15) != 0;
}
