#include <globaldefs.h>
ARM
extern "C" void SetDisplayRegisterLowBits(void);
extern "C" void Graphics_SubmitIndexedConfiguredBuffer(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_ConfigurePlane15AndScheduleCallback(void);
// Original: arm9/ov031 @ 0x02229BFC; symbol: func_ov031_02229bfc; size: 0x20.
extern "C" void Overlay_InitializeAndInstallCallback(void) {
    SetDisplayRegisterLowBits();
    Graphics_SubmitIndexedConfiguredBuffer(0x1a);
    SetMainLoopCallback(Overlay_ConfigurePlane15AndScheduleCallback);
}
