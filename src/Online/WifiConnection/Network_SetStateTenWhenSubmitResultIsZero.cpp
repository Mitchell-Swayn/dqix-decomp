#include <globaldefs.h>
ARM
extern "C" int Network_SubmitCallbackAndUpdateState(void);
extern "C" void WirelessHost_SetSystemState(int value);
// Original: arm9/ov031 @ 0x0223A358; symbol: Network_SetStateTenWhenSubmitResultIsZero; size: 0x1C.
// Selects state 10 when the network submission helper returns zero.
extern "C" void Network_SetStateTenWhenSubmitResultIsZero(void) {
    if (Network_SubmitCallbackAndUpdateState() == 0) WirelessHost_SetSystemState(10);
}
