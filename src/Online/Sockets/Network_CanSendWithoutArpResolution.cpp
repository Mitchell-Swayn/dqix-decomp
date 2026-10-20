#include <globaldefs.h>
ARM
extern "C" int Network_SelectDestinationOrDefaultGateway(void);
extern "C" int Network_LookupDestinationMacAddress(void);
// Original: arm9/ov031 @ 0x02201EF4; symbol: ProcessValueWhenFirstCheckIsNonzero; size: 0x1C.
// Returns one when the first check yields zero; otherwise returns the follow-up result.
extern "C" int Network_CanSendWithoutArpResolution(void) {
    if (Network_SelectDestinationOrDefaultGateway() == 0) return 1;
    return Network_LookupDestinationMacAddress();
}
