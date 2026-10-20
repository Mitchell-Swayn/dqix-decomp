#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallCallbackWhenBothContextBytesClear(void);
// Original: arm9/ov031 @ 0x0222E7F8; symbol: System_ConfigureDisplayAndInstallBothContextBytesCallback; size: 0x34.
// Configures display mode and plane mask 0x15, then installs the callback that checks context byte 9 on both screens.
extern "C" void System_ConfigureDisplayAndInstallBothContextBytesCallback(void) {
 WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
 WfcUtility_EnableDisplayPlanes(0, 0x15);
 WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenBothContextBytesClear);
}
