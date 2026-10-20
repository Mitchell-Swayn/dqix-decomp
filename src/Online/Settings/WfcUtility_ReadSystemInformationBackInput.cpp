#include <globaldefs.h>
ARM
extern "C" int WfcUtility_AreButtonsPressed(unsigned int mask);
extern "C" void WfcUtility_LatchBottomButtonSelection(signed char value);

// Original: arm9/ov031 @ 0x02228F30; symbol: func_ov031_02228f30; size: 0x20.
extern "C" void WfcUtility_ReadSystemInformationBackInput(void) {
    if (WfcUtility_AreButtonsPressed(2))
        WfcUtility_LatchBottomButtonSelection(0);
}
