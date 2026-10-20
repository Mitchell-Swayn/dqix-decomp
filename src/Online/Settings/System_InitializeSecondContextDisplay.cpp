#include <globaldefs.h>
ARM

extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void System_SetReadyAndScheduleWordCallback(void);
extern "C" void WfcUtility_StartScreenBrightnessTransition(unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallCallbackWhenContextReady(void);

// Original: arm9/ov031 @ 0x02229D9C; symbol: func_ov031_02229d9c; size: 0x3C.
extern "C" void System_InitializeSecondContextDisplay(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) {
        return;
    }
    System_SetReadyAndScheduleWordCallback();
    WfcUtility_StartScreenBrightnessTransition(3, 0, 0x15, 8);
    WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenContextReady);
}
