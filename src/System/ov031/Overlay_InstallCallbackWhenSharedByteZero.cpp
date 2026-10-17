#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallFallbackCallbackIfNoSharedObject(void);
// Original: arm9/ov031 @ 0x0222B388; symbol: func_ov031_0222b388; size: 0x2C.
extern "C" void Overlay_InstallCallbackWhenSharedByteZero(void) {
    if (ReadSharedObjectSignedByte1B() != 0)
        return;
    System_ResolveGlobalGroupEntry(6);
    CreateSharedDisplayResource();
    SetMainLoopCallback(System_InstallFallbackCallbackIfNoSharedObject);
}
