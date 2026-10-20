#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int);
extern "C" int WfcMultiScreen_TestSharedInputHighBit(void);
extern "C" void WfcUtility_LatchBottomButtonSelection(int);
// Original: arm9/ov031 @ 0x022312A4; symbol: func_ov031_022312a4; size: 0x38.
extern "C" void WfcMultiScreen_RequestCancelFromInput(void) {
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_LatchBottomButtonSelection(0);
        return;
    }
    if (WfcMultiScreen_TestSharedInputHighBit()) WfcUtility_LatchBottomButtonSelection(0);
}
