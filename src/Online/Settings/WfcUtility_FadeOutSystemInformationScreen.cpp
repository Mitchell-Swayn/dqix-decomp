#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int, int, int, int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void System_InitializeDisplaySequence();
// Original: arm9/ov031 @ 0x02228F9C; symbol: Unclassified_ConfigureDisplayMode3Context15AndCallback_02228F9C; size: 0x50.
// When selected context byte 9 is clear, runs display cleanup, configures mode 3 with the 0x15 plane value, and installs callback 0x02228FEC. The address suffix is temporary pending semantic distinction of this callback continuation.
extern "C" void WfcUtility_FadeOutSystemInformationScreen() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    System_SetReadyAndScheduleWordCallback();
    WfcUtility_StartScreenBrightnessTransition(3, 1, 1, 8);
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(System_InitializeDisplaySequence);
}
