#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x0215A734; symbol: func_ov001_0215a734; size: 0x1C.
extern "C" void *func_ov001_0215a734(void (*callback)(void)) {
    if (callback != 0)
        callback();
    return (void *)0x001beb10;
}
