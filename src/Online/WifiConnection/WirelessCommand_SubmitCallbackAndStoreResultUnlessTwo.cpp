#include <globaldefs.h>
ARM
extern "C" int WirelessCommand_SubmitOpcodeNineAfterStateValidation(unsigned value);
extern "C" void WirelessHost_StoreErrorUnlessTerminal(unsigned value);
extern "C" void System_ApplySharedStateOrTransitionFallback(void);
// Original: arm9/ov031 @ 0x022399D8; symbol: WirelessCommand_SubmitCallbackAndStoreResultUnlessTwo; size: 0x28.
// Submits callback 0x02239A00 through the opcode-nine command; returns 1 for result 2, otherwise stores the result in shared word 0x54 and returns 0.
extern "C" unsigned WirelessCommand_SubmitCallbackAndStoreResultUnlessTwo(void) {
    unsigned result = WirelessCommand_SubmitOpcodeNineAfterStateValidation((unsigned)System_ApplySharedStateOrTransitionFallback);
    if (result == 2)
        return 1;
    WirelessHost_StoreErrorUnlessTerminal(result);
    return 0;
}
