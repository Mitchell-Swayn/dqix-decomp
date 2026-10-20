#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);
// Original: arm9/ov031 @ 0x02228AC0; symbol: func_ov031_02228ac0; size: 0x20.
extern "C" void System_ClearPendingByteIfInputMask1Held(void) {
    if (WfcUtility_AreButtonsPressed(1))
        WfcUtility_LatchBottomButtonSelection(0);
}
