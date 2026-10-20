#include <globaldefs.h>
ARM
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned int);
extern "C" void WirelessHost_FinalizeConnectionByMode(void);
extern "C" int System_ValidateGlobalSlotOrFallbackTransition(void);
extern "C" void WirelessHost_SetSystemState(int);
// Original: arm9/ov031 @ 0x02239AA4; symbol: func_ov031_02239aa4; size: 0x34.
extern "C" void WirelessHost_HandleMultiplayerEndBeforeDisconnect(void *state) {
    unsigned short value = *(unsigned short *)((char *)state + 2);
    if (value != 0) {
        WirelessHost_StoreErrorUnlessTerminal(value);
        WirelessHost_FinalizeConnectionByMode();
        return;
    }
    if (System_ValidateGlobalSlotOrFallbackTransition() == 0) WirelessHost_SetSystemState(9);
}
