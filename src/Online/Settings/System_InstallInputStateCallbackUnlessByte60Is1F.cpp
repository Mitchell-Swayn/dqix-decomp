#include <globaldefs.h>
ARM
extern "C" unsigned int WfcNumberPad_GetInputCode(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_ProcessInputState(void);
// Original: arm9/ov031 @ 0x0222DA30; symbol: func_ov031_0222da30; size: 0x20.
extern "C" void System_InstallInputStateCallbackUnlessByte60Is1F(void) {
    if (WfcNumberPad_GetInputCode() != 0x1f) WfcUtility_SetMainLoopCallback(System_ProcessInputState);
}
