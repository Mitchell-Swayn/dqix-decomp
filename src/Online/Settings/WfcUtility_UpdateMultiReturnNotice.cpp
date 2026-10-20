#include <globaldefs.h>
ARM
extern "C" void WfcUtility_ReadMultiReturnNoticeInput(void);
extern "C" void WfcUtility_RunMultiReturnNoticeInputHook(void);
extern "C" void WfcUtility_AcceptMultiReturnNotice(void);
// Original: arm9/ov031 @ 0x02229D1C; symbol: HandleInputBit1AndInstallCallback6_02229D1C; size: 0x14.
// Handles input mask 1, then when the shared signed byte is zero selects 6 and installs the next callback; suffix disambiguates similar handlers pending refinement.
extern "C" void WfcUtility_UpdateMultiReturnNotice(void) {
    WfcUtility_ReadMultiReturnNoticeInput();
    WfcUtility_RunMultiReturnNoticeInputHook();
    WfcUtility_AcceptMultiReturnNotice();
}
