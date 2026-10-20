#include <globaldefs.h>
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void InitializeContextCallbackWhenByte9IsZero();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02231614; symbol: func_ov031_02231614; size: 0x34.
extern "C" ARM void Ov031_SetDisplayPlaneAndNextCallback() {
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(InitializeContextCallbackWhenByte9IsZero);
}
