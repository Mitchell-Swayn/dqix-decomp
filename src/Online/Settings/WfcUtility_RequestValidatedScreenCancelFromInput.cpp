#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);
extern "C" int System_ReadHardwareStatusRegisterBit15(void);
// Original: arm9/ov031 @ 0x022316BC; symbol: func_ov031_022316bc; size: 0x38.
extern "C" void WfcUtility_RequestValidatedScreenCancelFromInput(void) {
    if (WfcUtility_AreButtonsPressed(2)) {
        WfcUtility_LatchBottomButtonSelection(0);
        return;
    }
    if (!System_ReadHardwareStatusRegisterBit15()) return;
    WfcUtility_LatchBottomButtonSelection(0);
}
