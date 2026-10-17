#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_022346d0(void);
// Original: arm9/ov031 @ 0x022346A8; symbol: func_ov031_022346a8; size: 0x28.
extern "C" void System_ClearControlAndInstallCallbackUnlessSentinel(void) {
    if (ReadSharedSignedByteAtOffset22() == -2)
        return;
    ClearGlobalControlByte18();
    SetMainLoopCallback(func_ov031_022346d0);
}
