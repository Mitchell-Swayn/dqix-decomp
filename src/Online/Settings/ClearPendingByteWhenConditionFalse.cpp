#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);
extern "C" int WfcStepThreeScreen_TestSharedInputHighBit(void);
// Original: arm9/ov031 @ 0x02231D90; symbol: func_ov031_02231d90; size: 0x38.
extern "C" void ClearPendingByteWhenConditionFalse(void) {
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_LatchBottomButtonSelection(0);
        return;
    }
    if (WfcStepThreeScreen_TestSharedInputHighBit()) WfcUtility_LatchBottomButtonSelection(0);
}
