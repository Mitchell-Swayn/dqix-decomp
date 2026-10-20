#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);
// Original: arm9/ov031 @ 0x02229D30; symbol: func_ov031_02229d30; size: 0x20.
extern "C" void WfcUtility_ReadMultiReturnNoticeInput(void) {
    if (WfcUtility_AreButtonsPressed(1))
        WfcUtility_LatchBottomButtonSelection(0);
}
