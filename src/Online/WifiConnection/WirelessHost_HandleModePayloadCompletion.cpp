#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned int);
extern "C" int WirelessHost_StartParentAndResetConnectedPeers(void);
extern "C" void WirelessHost_SetSystemState(int);
// Original: arm9/ov031 @ 0x02239518; symbol: func_ov031_02239518; size: 0x38.
extern "C" void WirelessHost_HandleModePayloadCompletion(void *state) {
    unsigned short value = *(unsigned short *)((char *)state + 2);
    if (value != 0) {
        WirelessHost_StoreErrorUnlessTerminal(value);
        WirelessHost_SetSystemState(9);
        return;
    }
    if (WirelessHost_StartParentAndResetConnectedPeers() == 0) WirelessHost_SetSystemState(9);
}
