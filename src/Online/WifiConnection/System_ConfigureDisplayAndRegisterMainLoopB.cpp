#include <globaldefs.h>
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InstallCallback0223442CIfScreenContextClear();
// Original: arm9/ov031 @ 0x022343D4; symbol: func_ov031_022343d4; size: 0x34.
extern "C" void System_ConfigureDisplayAndRegisterMainLoopB() {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(System_InstallCallback0223442CIfScreenContextClear);
}
