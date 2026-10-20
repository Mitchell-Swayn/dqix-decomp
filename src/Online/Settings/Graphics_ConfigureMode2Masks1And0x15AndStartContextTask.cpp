#include <globaldefs.h>
ARM
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_EnableDisplayPlanes(int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcStepThreeScreen_StartTaskWhenDisplaysIdle();
// Original: arm9/ov031 @ 0x02231CB4; symbol: Graphics_ConfigureMode2Masks1And0x15AndStartContextTask; size: 0x54.
// Configures two mode-2 records, enables masks 1 and 0x15, then installs a continuation that starts the context task.
extern "C" void Graphics_ConfigureMode2Masks1And0x15AndStartContextTask(void) {
    WfcUtility_StartScreenBrightnessTransition(2, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(2, 0, 0x15, 8);
    WfcUtility_EnableDisplayPlanes(1, 1);
    WfcUtility_EnableDisplayPlanes(0, 0x15);
    WfcUtility_SetMainLoopCallback(WfcStepThreeScreen_StartTaskWhenDisplaysIdle);
}
