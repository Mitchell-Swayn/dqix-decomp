#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_LatchBottomButtonSelection(int value);
// Original: arm9/ov031 @ 0x0223232C; symbol: func_ov031_0223232c; size: 0x24.
extern "C" void System_HandleHeldInputMaskBit2(void) {
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_StopSequenceImmediately();
        WfcUtility_LatchBottomButtonSelection(0);
    }
}
