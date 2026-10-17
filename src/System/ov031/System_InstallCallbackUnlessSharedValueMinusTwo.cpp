#include <globaldefs.h>
ARM
extern "C" int ReadSharedObjectSignedByte1B(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_ConfigureModeFromSharedSignedByte(void);
// Original: arm9/ov031 @ 0x0222A86C; symbol: func_ov031_0222a86c; size: 0x24.
extern "C" void System_InstallCallbackUnlessSharedValueMinusTwo(void) {
    if (ReadSharedObjectSignedByte1B() != -2)
        SetMainLoopCallback(Overlay_ConfigureModeFromSharedSignedByte);
}
