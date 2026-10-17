#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void DispatchGlobalPointerOffset94WithZero(void);
extern "C" void System_ResolveGlobalGroupEntry(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByteAndInstallMode8Callback(void);
// Original: arm9/ov031 @ 0x02231DCC; symbol: func_ov031_02231dcc; size: 0x2C.
extern "C" void System_InitializeAndSetMainLoopCallbackIfSharedByteZero(void) {
    if (ReadSharedSignedByteAtOffset22() != 0)
        return;
    DispatchGlobalPointerOffset94WithZero();
    System_ResolveGlobalGroupEntry(7);
    SetMainLoopCallback(System_SetSharedByteAndInstallMode8Callback);
}
