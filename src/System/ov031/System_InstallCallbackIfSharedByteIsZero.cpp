#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void System_ConfigureSharedByteAndAlternateCallback(void);
extern "C" void SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x022312E0; symbol: func_ov031_022312e0; size: 0x2C.
extern "C" void System_InstallCallbackIfSharedByteIsZero(void) {
    if (ReadSharedSignedByteAtOffset22() != 0)
        return;
    DispatchGlobalPointerOffset94WithZero();
    System_ResolveGlobalGroupEntry(7);
    SetMainLoopCallback((void *)System_ConfigureSharedByteAndAlternateCallback);
}
