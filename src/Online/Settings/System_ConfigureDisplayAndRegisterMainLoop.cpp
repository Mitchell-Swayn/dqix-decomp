#include <globaldefs.h>
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void Overlay_SetMainLoopCallbackWhenContextByteZero();
// Original: arm9/ov031 @ 0x0222A210; symbol: func_ov031_0222a210; size: 0x34.
extern "C" void System_ConfigureDisplayAndRegisterMainLoop() {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(Overlay_SetMainLoopCallbackWhenContextByteZero);
}
