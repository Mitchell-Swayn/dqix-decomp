#include <globaldefs.h>
ARM
extern "C" void *func_ov031_022123d4(void);
extern "C" void func_ov031_02211138(void);
// Original: arm9/ov031 @ 0x0221188C; symbol: func_ov031_0221188c; size: 0x1C.
extern "C" void *System_GetPrimaryObjectOrInitializeFallback(void) {
    void *object = func_ov031_022123d4();
    if (!object)
        func_ov031_02211138();
    return object;
}
