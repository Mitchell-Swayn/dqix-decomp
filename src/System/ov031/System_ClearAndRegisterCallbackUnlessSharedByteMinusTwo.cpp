#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222e890(void);
// Original: arm9/ov031 @ 0x0222E868; symbol: func_ov031_0222e868; size: 0x28.
extern "C" void System_ClearAndRegisterCallbackUnlessSharedByteMinusTwo(void) { if (ReadSharedSignedByteAtOffset22() != -2) { ClearGlobalControlByte18(); SetMainLoopCallback(func_ov031_0222e890); } }
