#include <globaldefs.h>
ARM
extern "C" void SetStateWithTransitionCallbacks(int value);
extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void *arg);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned value);
extern "C" void UpdateContextTransitionFromPendingState(void);
// Original: arm9/ov031 @ 0x02239A74; symbol: func_ov031_02239a74; size: 0x30.
extern "C" int System_SubmitOpcodeSixteenAndApplyResult(void) {
    SetStateWithTransitionCallbacks(3);
    unsigned int result = WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet((void *)UpdateContextTransitionFromPendingState);
    if (result == 2) return 1;
    SetSharedObjectWord54UnlessStateNineOrTen(result);
    return 0;
}
