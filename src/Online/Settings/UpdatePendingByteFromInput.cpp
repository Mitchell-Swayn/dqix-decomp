#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);
// Original: arm9/ov031 @ 0x0222A504; symbol: func_ov031_0222a504; size: 0x38.
extern "C" void UpdatePendingByteFromInput(void) {
    if (WfcUtility_AreButtonsPressed(1)) {
        WfcUtility_LatchBottomButtonSelection(1);
    }
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_LatchBottomButtonSelection(0);
    }
}
