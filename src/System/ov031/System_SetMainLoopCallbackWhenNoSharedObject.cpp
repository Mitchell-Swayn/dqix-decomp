#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222eef8(void);

// Original: arm9/ov031 @ 0x02230ED0; symbol: func_ov031_02230ed0; size: 0x20.
extern "C" void System_SetMainLoopCallbackWhenNoSharedObject(void) {
    if (HasSharedObjectPointer())
        return;
    SetMainLoopCallback(func_ov031_0222eef8);
}
