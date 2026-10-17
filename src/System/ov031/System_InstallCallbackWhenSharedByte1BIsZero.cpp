#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void Overlay_ClearSharedFlagAndSetCallback(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0222E378; symbol: func_ov031_0222e378; size: 0x2C.
extern "C" void System_InstallCallbackWhenSharedByte1BIsZero(void) {
    if (ReadSharedObjectSignedByte1B() != 0)
        return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    SetMainLoopCallback((void *)Overlay_ClearSharedFlagAndSetCallback);
}
