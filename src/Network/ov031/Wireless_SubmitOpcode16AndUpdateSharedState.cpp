#include <globaldefs.h>
ARM
extern "C" void SetStateWithTransitionCallbacks(int value);
extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void *arg);
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned int value);
extern "C" void System_TransitionSharedObjectAndInvokeCallback(void);
// Original: arm9/ov031 @ 0x02239954; symbol: func_ov031_02239954; size: 0x30.
extern "C" int Wireless_SubmitOpcode16AndUpdateSharedState(void) {
    SetStateWithTransitionCallbacks(3);
    int result = WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet((void *)System_TransitionSharedObjectAndInvokeCallback);
    if (result == 2)
        return 1;
    SetSharedObjectWord54UnlessStateNineOrTen((unsigned int)result);
    return 0;
}
