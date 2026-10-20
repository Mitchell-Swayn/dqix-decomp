#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);

// Original: arm9/ov031 @ 0x0222E8A4; symbol: func_ov031_0222e8a4; size: 0x20.
extern "C" void WfcUtility_QueueConnectionErrorAcknowledgement(void) {
    if (WfcUtility_AreButtonsPressed(1))
        WfcUtility_LatchBottomButtonSelection(0);
}
