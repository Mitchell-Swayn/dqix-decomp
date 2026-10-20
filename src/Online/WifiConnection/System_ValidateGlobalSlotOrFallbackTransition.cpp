#include <globaldefs.h>
extern "C" void WirelessHost_SetSystemState(int);
extern "C" int ValidateSlotAgainstSharedMaskAndSubmit(int, unsigned);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned);
extern "C" void Network_SetStateTenWhenSubmitResultIsZero();
extern "C" unsigned char System_SetStateFromHalfword2[];
// Original: arm9/ov031 @ 0x02239AD8; symbol: func_ov031_02239ad8; size: 0x38.
extern "C" int System_ValidateGlobalSlotOrFallbackTransition() {
    WirelessHost_SetSystemState(3);
    int result = ValidateSlotAgainstSharedMaskAndSubmit((int)System_SetStateFromHalfword2, 0);
    if (result == 2) return 1;
    WirelessHost_StoreErrorUnlessTerminal((unsigned)result);
    Network_SetStateTenWhenSubmitResultIsZero();
    return 0;
}
