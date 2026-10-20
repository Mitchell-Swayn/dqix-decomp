#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216265C; symbol: func_ov000_0216265c; size: 0x44.
extern "C" int GameState_IsFieldEa8ValueSupported(void *self) {
    switch (*(unsigned int *)((char *)self + 0xEA8)) {
    case 4:
    case 6:
    case 9:
    case 10:
    case 11:
        return 1;
    default:
        return 0;
    }
}
