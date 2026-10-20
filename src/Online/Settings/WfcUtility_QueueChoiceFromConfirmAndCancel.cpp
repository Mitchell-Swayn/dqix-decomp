#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(unsigned int value);
// Original: arm9/ov031 @ 0x02229FAC; symbol: func_ov031_02229fac; size: 0x38.
extern "C" void WfcUtility_QueueChoiceFromConfirmAndCancel(void) {
    if (WfcUtility_AreButtonsPressed(1)) WfcUtility_LatchBottomButtonSelection(1);
    if (WfcUtility_AreButtonsPressed(2)) WfcUtility_LatchBottomButtonSelection(0);
}
