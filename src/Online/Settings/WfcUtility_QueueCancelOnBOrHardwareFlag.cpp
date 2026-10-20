#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int);
extern "C" void WfcUtility_LatchBottomButtonSelection(unsigned int);
extern "C" int System_ReadHardwareStatusBit15Flag(void);
// Original: arm9/ov031 @ 0x02234AA4; symbol: func_ov031_02234aa4; size: 0x38.
extern "C" void WfcUtility_QueueCancelOnBOrHardwareFlag(void) {
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_LatchBottomButtonSelection(0);
        return;
    }
    if (System_ReadHardwareStatusBit15Flag()) WfcUtility_LatchBottomButtonSelection(0);
}
