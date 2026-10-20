#include <globaldefs.h>
ARM
extern "C" void System_ClearPendingByteIfInputMask1Held(void);
extern "C" void WfcUtility_RunMultiCompletionInputHook(void);
extern "C" void InitializeAndRegisterCallbackWhenSharedByteZero(void);
// Original: arm9/ov031 @ 0x02228AAC; symbol: HandleInputBit1AndInstallCallback6_02228AAC; size: 0x14.
// Handles input mask 1, then when the shared signed byte is zero selects 6 and installs the next callback; suffix disambiguates similar handlers pending refinement.
extern "C" void WfcUtility_UpdateMultiScreenCompletionPrompt(void) {
    System_ClearPendingByteIfInputMask1Held();
    WfcUtility_RunMultiCompletionInputHook();
    InitializeAndRegisterCallbackWhenSharedByteZero();
}
