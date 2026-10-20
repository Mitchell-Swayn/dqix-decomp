#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void System_SleepTenAndRunStateHandlers(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231674; symbol: System_ClearControlByte18AndSetMainLoopCallback_0223169C; size: 0x28.
// Returns when shared signed byte 0x22 is -2; otherwise clears global control byte 0x18 and installs callback 0x0223169C.
extern "C" void WfcUtility_StartValidatedScreenPollingWhenReady(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2)
        return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(System_SleepTenAndRunStateHandlers);
}
