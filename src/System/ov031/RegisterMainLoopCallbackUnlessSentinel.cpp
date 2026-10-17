#include <globaldefs.h>
ARM
extern "C" unsigned int func_ov031_02223fa0(void);
extern "C" void func_ov031_0222cec0(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222CEA0; symbol: func_ov031_0222cea0; size: 0x20.
extern "C" void RegisterMainLoopCallbackUnlessSentinel(void) {
    if (func_ov031_02223fa0() != 0xff)
        SetMainLoopCallback(func_ov031_0222cec0);
}
