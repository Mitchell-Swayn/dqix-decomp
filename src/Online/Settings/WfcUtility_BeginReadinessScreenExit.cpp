#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback(void);
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_FinishReadinessScreenExit(void);
// Original: arm9/ov031 @ 0x022323A0; symbol: System_ConfigureDisplayMode3Context15AndCallback_022323A0; size: 0x50.
// When context byte 9 is clear, runs display cleanup, configures mode 3 with the 0x15 plane value, and installs callback 0x022323F0. The address suffix is temporary pending semantic distinction of this callback continuation.
extern "C" void WfcUtility_BeginReadinessScreenExit(void) {
 if (WfcUtility_IsScreenTransitionBusy(1)) return;
 System_SetReadyAndScheduleWordCallback();
 WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
 WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
 WfcUtility_SetMainLoopCallback(WfcUtility_FinishReadinessScreenExit);
}
