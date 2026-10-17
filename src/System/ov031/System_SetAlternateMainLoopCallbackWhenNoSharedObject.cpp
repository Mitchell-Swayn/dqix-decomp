#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02234b2c(void);

// Original: arm9/ov031 @ 0x02234DC4; symbol: func_ov031_02234dc4; size: 0x20.
extern "C" void System_SetAlternateMainLoopCallbackWhenNoSharedObject(void) {
    if (HasSharedObjectPointer())
        return;
    SetMainLoopCallback(func_ov031_02234b2c);
}
