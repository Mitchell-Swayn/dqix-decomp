#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_ArmWirelessTextEditorInput(void);
// Original: arm9/ov031 @ 0x0222CDD0; symbol: Graphics_ConfigureMode2Masks1And0x15ForContextTransition; size: 0x54.
// Configures two mode-2 records and enables masks 1 and 0x15 before installing a continuation that updates context-dependent display state.
extern "C" void Graphics_ConfigureMode2Masks1And0x15ForContextTransition(void) {
 WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
 WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
 WfcUtility_EnableDisplayPlanes(1, 1);
 WfcUtility_EnableDisplayPlanes(0, 0x15);
 WfcUtility_SetMainLoopCallback(WfcUtility_ArmWirelessTextEditorInput);
}
