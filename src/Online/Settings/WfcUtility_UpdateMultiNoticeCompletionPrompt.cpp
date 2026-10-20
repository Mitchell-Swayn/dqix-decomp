#include <globaldefs.h>
ARM
extern "C" void WfcUtility_ReadMultiNoticeCompletionInput(void);
extern "C" void WfcUtility_RunMultiNoticeCompletionInputHook(void);
extern "C" void System_SetCallbackWhenSharedByte22IsZero(void);

// Original: arm9/ov031 @ 0x02229AFC; symbol: HandleInputBit1AndInstallCallback6_02229AFC; size: 0x14.
// Handles input mask 1, then when the shared signed byte is zero selects 6 and installs the next callback; suffix disambiguates similar handlers pending refinement.
extern "C" void WfcUtility_UpdateMultiNoticeCompletionPrompt(void) {
    WfcUtility_ReadMultiNoticeCompletionInput();
    WfcUtility_RunMultiNoticeCompletionInputHook();
    System_SetCallbackWhenSharedByte22IsZero();
}
