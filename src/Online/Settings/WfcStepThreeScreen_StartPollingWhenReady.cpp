#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void System_Sleep10TicksAndRunAdjacentHelpers(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231D48; symbol: System_ClearControlByte18AndSetMainLoopCallback_02231D70; size: 0x28.
// Returns when shared signed byte 0x22 is -2; otherwise clears global control byte 0x18 and installs callback 0x02231D70.
extern "C" void WfcStepThreeScreen_StartPollingWhenReady(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2)
        return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(System_Sleep10TicksAndRunAdjacentHelpers);
}
