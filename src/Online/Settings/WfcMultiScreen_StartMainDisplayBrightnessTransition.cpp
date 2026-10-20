#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned first, unsigned second, unsigned third, unsigned fourth);
extern "C" void WfcUtility_EnableDisplayPlanes(int screen, unsigned planes);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Overlay_InstallCallbackWhenContextByteZero(void);
// Original: arm9/ov031 @ 0x022311FC; symbol: func_ov031_022311fc; size: 0x34.
extern "C" void WfcMultiScreen_StartMainDisplayBrightnessTransition(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(Overlay_InstallCallbackWhenContextByteZero);
}
