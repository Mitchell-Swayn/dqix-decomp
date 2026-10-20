#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_UpdateOptionsMenu(void);
// Original: arm9/ov031 @ 0x02229350; symbol: Unclassified_ClearControlAndInstallHelperSequenceCallbackWhenSharedByteValid_02229350; size: 0x28.
// Returns when the shared signed byte is -2; otherwise clears control byte 0x18 and installs a callback that calls three helpers whose combined behavior is not yet established. Temporary address suffix; naming refinement is pending until those helpers are understood.
extern "C" void WfcUtility_EnableOptionsMenuInput(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(WfcUtility_UpdateOptionsMenu);
    }
}
