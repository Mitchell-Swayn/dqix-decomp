#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ResolveGlobalGroupEntry(unsigned int value);
extern "C" void Overlay_InitializeSharedByteAndCallback(void);

// Original: arm9/ov031 @ 0x02229B34; symbol: func_ov031_02229b34; size: 0x28.
extern "C" void System_SetCallbackWhenSharedByte22IsZero(void) {
    if (ReadSharedSignedByteAtOffset22() != 0)
        return;
    System_ResolveGlobalGroupEntry(6);
    SetMainLoopCallback(Overlay_InitializeSharedByteAndCallback);
}
