#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Overlay_InitializeCallbackWhenContextByteZero();
// Original: arm9/ov031 @ 0x022342A4; symbol: System_ConfigureMode3AndPlaneMask0x14WhenNoSharedObject; size: 0x34.
// When no shared object is active, configures mode (3, 0, 0x14, 8) and installs the context callback.
extern "C" void System_ConfigureMode3AndPlaneMask0x14WhenNoSharedObject() {
    if (WfcUtility_IsDialogActive()) return;
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x14, 8);
    WfcUtility_SetMainLoopCallback(Overlay_InitializeCallbackWhenContextByteZero);
}
