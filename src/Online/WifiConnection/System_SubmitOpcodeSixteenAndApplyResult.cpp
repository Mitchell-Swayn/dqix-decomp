#include <globaldefs.h>
ARM
extern "C" void WirelessHost_SetSystemState(int value);
extern "C" int WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet(void *arg);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value);
extern "C" void WirelessHost_HandleMultiplayerEndBeforeDisconnect(void);
// Original: arm9/ov031 @ 0x02239A74; symbol: func_ov031_02239a74; size: 0x30.
extern "C" int System_SubmitOpcodeSixteenAndApplyResult(void) {
    WirelessHost_SetSystemState(3);
    unsigned int result = WirelessCommand_SubmitOpcodeSixteenIfSharedWordCSet((void *)WirelessHost_HandleMultiplayerEndBeforeDisconnect);
    if (result == 2) return 1;
    WirelessHost_StoreErrorUnlessTerminal(result);
    return 0;
}
