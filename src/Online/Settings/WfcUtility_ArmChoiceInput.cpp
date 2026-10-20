#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_EnableBottomButtonTouch(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_RunInputStateHelpers(void);
// Original: arm9/ov031 @ 0x02229F70; symbol: Unclassified_ClearControlAndInstallMask1Or2HandlerWhenSharedByteValid; size: 0x28.
// Returns when the shared signed byte is -2; otherwise clears control byte 0x18 and installs a handler sequence whose first helper updates pending input from masks 1 and 2.
extern "C" void WfcUtility_ArmChoiceInput(void) {
    if (WfcUtility_GetBottomButtonSelection() != -2) {
        WfcUtility_EnableBottomButtonTouch();
        WfcUtility_SetMainLoopCallback(System_RunInputStateHelpers);
    }
}
