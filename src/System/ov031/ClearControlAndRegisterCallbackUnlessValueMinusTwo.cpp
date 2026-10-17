#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void func_ov031_02228244(void);
extern "C" void SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x0222821C; symbol: func_ov031_0222821c; size: 0x28.
extern "C" void ClearControlAndRegisterCallbackUnlessValueMinusTwo(void) {
    if (ReadSharedSignedByteAtOffset22() != -2) {
        ClearGlobalControlByte18();
        SetMainLoopCallback(func_ov031_02228244);
    }
}
