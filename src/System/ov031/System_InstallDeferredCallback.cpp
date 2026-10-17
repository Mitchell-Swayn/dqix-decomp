#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22();
extern "C" int func_ov031_02236f68();
extern "C" void ClearGlobalControlByte18();
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunNextThreeInitializationHelpers(void);
// Original: arm9/ov031 @ 0x02232810; symbol: func_ov031_02232810; size: 0x34.
extern "C" void System_InstallDeferredCallback(void) {
    if (ReadSharedSignedByteAtOffset22() == -2) return;
    if (func_ov031_02236f68() == 1) return;
    ClearGlobalControlByte18();
    SetMainLoopCallback(System_RunNextThreeInitializationHelpers);
}
