#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void System_InstallCallbackUnlessSharedValueMinusTwo(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0222A848; symbol: func_ov031_0222a848; size: 0x24.
extern "C" void System_SetMainLoopCallbackIfContextByte9IsZero(void) {
    if (!ReadSelectedContextByte9(0))
        SetMainLoopCallback((void *)System_InstallCallbackUnlessSharedValueMinusTwo);
}
