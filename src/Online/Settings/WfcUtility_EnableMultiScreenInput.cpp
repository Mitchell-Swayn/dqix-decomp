#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void Overlay_UpdatePendingInputState(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x022286F4; symbol: System_ClearControlAndStartPendingInputCallbackWhenSharedByteValid; size: 0x28.
// Returns when the shared signed byte is -2; otherwise clears control byte 0x18 and installs the callback that runs the pending-input update sequence.
extern "C" void WfcUtility_EnableMultiScreenInput(void) {
    if (WfcUtility_GetBottomButtonSelection() == -2)
        return;
    WfcUtility_EnableBottomButtonTouch();
    WfcUtility_SetMainLoopCallback(Overlay_UpdatePendingInputState);
}
