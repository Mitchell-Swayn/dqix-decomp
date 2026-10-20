#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateCancelInputAndBeginTransition(void);
// Original: arm9/ov031 @ 0x02234A68; symbol: System_ClearControlByte18AndSetMainLoopCallback_02234A90; size: 0x28.
// When shared signed byte 0x22 is not -2, clears global control byte 0x18 and installs callback 0x02234A90.
extern "C" void WfcUtility_EnablePendingInputAfterMessageReady(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(WfcUtility_UpdateCancelInputAndBeginTransition);
    }
}
