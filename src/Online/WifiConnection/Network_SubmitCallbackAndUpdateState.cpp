#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_SubmitOpcodeOne(void *p);
extern "C" void WirelessHost_SetSystemState(int value);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value);
extern "C" void Network_SetTransitionFromObjectValue(void);
// Original: arm9/ov031 @ 0x02239B34; symbol: func_ov031_02239b34; size: 0x30.
extern "C" int Network_SubmitCallbackAndUpdateState(void) {
    WirelessHost_SetSystemState(3);
    int result = WirelessCommand_SubmitOpcodeOne((void *)Network_SetTransitionFromObjectValue);
    if (result == 2)
        return 1;
    WirelessHost_StoreErrorUnlessTerminal(result);
    return 0;
}
