#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FD00C; symbol: func_ov023_021fd00c; size: 0x1C.
extern "C" void MenuModel_SetPosition(void *object, unsigned *source) {
    *(unsigned *)((char *)object + 0x64) = source[0];
    *(unsigned *)((char *)object + 0x68) = source[1];
    *(unsigned *)((char *)object + 0x6c) = source[2];
}
