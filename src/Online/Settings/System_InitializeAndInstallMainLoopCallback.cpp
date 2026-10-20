#include <globaldefs.h>
ARM
extern "C" void Graphics_LoadMainBG2DataAndSetBackgroundPriorities(void);
extern "C" void WfcUtility_DrawConnectionErrorDetails(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ConfigureDisplayAndInstallBothContextBytesCallback(void);
// Original: arm9/ov031 @ 0x0222E3E8; symbol: func_ov031_0222e3e8; size: 0x1C.
extern "C" void System_InitializeAndInstallMainLoopCallback(void) {
    Graphics_LoadMainBG2DataAndSetBackgroundPriorities();
    WfcUtility_DrawConnectionErrorDetails();
    WfcUtility_SetMainLoopCallback(System_ConfigureDisplayAndInstallBothContextBytesCallback);
}
