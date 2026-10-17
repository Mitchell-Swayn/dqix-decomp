#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void func_ov031_02229d1c(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x02229CF4; symbol: func_ov031_02229cf4; size: 0x28.
extern "C" void System_InstallAlternateMainLoopCallbackUnlessSharedByteIsMinus2(void) {
    if (ReadSharedSignedByteAtOffset22() != -2) {
        ClearGlobalControlByte18();
        SetMainLoopCallback((void *)func_ov031_02229d1c);
    }
}
