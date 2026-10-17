#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" int System_ResolveGlobalGroupEntry(int mode);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void func_ov031_0222d6dc(void);
// Original: arm9/ov031 @ 0x0222D6B0; symbol: func_ov031_0222d6b0; size: 0x2C.
extern "C" void System_InstallModeCallbackWhenStateIsZero(void) {
    if (ReadSharedObjectSignedByte1B() != 0) return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    SetMainLoopCallback(func_ov031_0222d6dc);
}
