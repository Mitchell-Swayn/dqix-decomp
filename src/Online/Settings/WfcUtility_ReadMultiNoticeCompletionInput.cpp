#include <globaldefs.h>
ARM
extern "C" ARM int WfcUtility_AreButtonsPressed(unsigned int);
extern "C" void WfcUtility_LatchBottomButtonSelection(unsigned int);
// Original: arm9/ov031 @ 0x02229B10; symbol: func_ov031_02229b10; size: 0x20.
extern "C" void WfcUtility_ReadMultiNoticeCompletionInput(void) {
    if (WfcUtility_AreButtonsPressed(1)) WfcUtility_LatchBottomButtonSelection(0);
}
