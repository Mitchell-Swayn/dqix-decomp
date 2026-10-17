#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void System_SleepAndRunContextSteps(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0223125C; symbol: func_ov031_0223125c; size: 0x28.
extern "C" void System_InstallFourthMainLoopCallbackUnlessSharedByteIsMinus2(void) {
    if (ReadSharedSignedByteAtOffset22() != -2) {
        ClearGlobalControlByte18();
        SetMainLoopCallback((void *)System_SleepAndRunContextSteps);
    }
}
