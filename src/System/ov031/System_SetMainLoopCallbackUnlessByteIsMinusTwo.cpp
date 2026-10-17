#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunThreeInitializationHelpers(void);
// Original: arm9/ov031 @ 0x0222ABE8; symbol: func_ov031_0222abe8; size: 0x24.
extern "C" void System_SetMainLoopCallbackUnlessByteIsMinusTwo(void) {
    if (ReadSharedSignedByteAtOffset22() != -2)
        SetMainLoopCallback(System_RunThreeInitializationHelpers);
}
