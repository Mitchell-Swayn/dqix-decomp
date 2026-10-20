#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(unsigned int value);
extern "C" void WfcUtility_StartValidatedScreenPollingWhenReady(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231648; symbol: func_ov031_02231648; size: 0x2C.
extern "C" void InitializeContextCallbackWhenByte9IsZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_CreateBottomButtonsForDisplayMode(1);
    WfcUtility_SetMainLoopCallback(WfcUtility_StartValidatedScreenPollingWhenReady);
}
