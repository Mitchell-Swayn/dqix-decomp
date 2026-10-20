#include <globaldefs.h>
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void Overlay_InitializeCallbacksWhenContextByteZero();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x0222982C; symbol: func_ov031_0222982c; size: 0x34.
extern "C" ARM void Ov031_SetDisplayPlaneAndCallback() {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(Overlay_InitializeCallbacksWhenContextByteZero);
}
