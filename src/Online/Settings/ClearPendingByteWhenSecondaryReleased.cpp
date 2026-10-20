#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);
extern "C" int WfcUtility_IsSystemInputGateClosed(void);
// Original: arm9/ov031 @ 0x0222AC20; symbol: func_ov031_0222ac20; size: 0x38.
extern "C" void ClearPendingByteWhenSecondaryReleased(void) {
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_LatchBottomButtonSelection(0);
        return;
    }
    if (WfcUtility_IsSystemInputGateClosed()) WfcUtility_LatchBottomButtonSelection(0);
}
