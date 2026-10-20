#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int);
extern "C" int System_IsHardwareStatusBit15Set(void);
extern "C" void WfcUtility_LatchBottomButtonSelection(int);
// Original: arm9/ov031 @ 0x0222B168; symbol: func_ov031_0222b168; size: 0x38.
extern "C" void WfcUtility_QueueSetupCancelFromButtonOrSystemGate(void) {
    if (WfcUtility_AreButtonsPressed(2) != 0) {
        WfcUtility_LatchBottomButtonSelection(0);
        return;
    }
    if (System_IsHardwareStatusBit15Set() != 0) WfcUtility_LatchBottomButtonSelection(0);
}
