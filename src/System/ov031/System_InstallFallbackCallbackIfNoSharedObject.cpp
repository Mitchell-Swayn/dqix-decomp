#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222b1f0(void);
// Original: arm9/ov031 @ 0x0222B3B4; symbol: func_ov031_0222b3b4; size: 0x20.
extern "C" void System_InstallFallbackCallbackIfNoSharedObject(void) {
    if (!HasSharedObjectPointer())
        SetMainLoopCallback(func_ov031_0222b1f0);
}
