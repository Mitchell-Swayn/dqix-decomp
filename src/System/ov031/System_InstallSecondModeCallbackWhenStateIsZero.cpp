#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" int System_ResolveGlobalGroupEntry(int mode);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void SetMainLoopCallback(void (*callback)());
extern "C" void System_SetAlternateMainLoopCallbackWhenNoSharedObject(void);
// Original: arm9/ov031 @ 0x02234D98; symbol: func_ov031_02234d98; size: 0x2C.
extern "C" void System_InstallSecondModeCallbackWhenStateIsZero(void) {
    if (ReadSharedObjectSignedByte1B() != 0) return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    SetMainLoopCallback(System_SetAlternateMainLoopCallbackWhenNoSharedObject);
}
