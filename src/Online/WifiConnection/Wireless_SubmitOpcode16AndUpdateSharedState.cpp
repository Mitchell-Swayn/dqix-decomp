#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int value);
extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void *arg);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned int value);
extern "C" void System_TransitionSharedObjectAndInvokeCallback(void);
// Original: arm9/ov031 @ 0x02239954; symbol: func_ov031_02239954; size: 0x30.
extern "C" int Wireless_SubmitOpcode16AndUpdateSharedState(void) {
    WirelessHost_SetSystemState(3);
    int result = WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet((void *)System_TransitionSharedObjectAndInvokeCallback);
    if (result == 2)
        return 1;
    WirelessHost_StoreErrorUnlessTerminal((unsigned int)result);
    return 0;
}
