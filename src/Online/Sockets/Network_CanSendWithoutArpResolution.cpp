#include <globaldefs.h>
ARM
extern "C" unsigned Network_SelectDestinationOrDefaultGateway(unsigned);
extern "C" void* Network_LookupDestinationMacAddress(unsigned);
// Original: arm9/ov031 @ 0x02201EF4; symbol: ProcessValueWhenFirstCheckIsNonzero; size: 0x1C.
// Returns one when the first check yields zero; otherwise returns the follow-up result.
extern "C" int Network_CanSendWithoutArpResolution(unsigned address) {
    if ((address=Network_SelectDestinationOrDefaultGateway(address)) == 0) return 1;
    return (int)Network_LookupDestinationMacAddress(address);
}
