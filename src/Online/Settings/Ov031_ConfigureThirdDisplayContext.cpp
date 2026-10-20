#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_HaltAfterMultiNoticeCompletionFade();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02229B7C; symbol: func_ov031_02229b7c; size: 0x4C.
extern "C" ARM void Ov031_ConfigureThirdDisplayContext() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    WfcUtility_StartScreenBrightnessTransition(3, 1, 0x3f, 0x40);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x3f, 0x40);
    WfcUtility_SetMainLoopCallback(WfcUtility_HaltAfterMultiNoticeCompletionFade);
}
