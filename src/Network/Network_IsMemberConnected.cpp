#include <globaldefs.h>
extern "C" unsigned int Network_FindWirelessSlotByMemberId();
extern "C" unsigned int Network_GetConnectionPeerMask(unsigned int);
// Original: arm9/main @ 0x0202BD34; symbol: func_0202bd34; size: 0x34.
extern "C" int Network_IsMemberConnected(unsigned int value) {
    unsigned int bit = Network_FindWirelessSlotByMemberId();
    int result;
    if ((int)bit < 0) {
        result = 0;
    } else {
        unsigned int flags = Network_GetConnectionPeerMask(value);
        result = 1;
        if ((flags & (1u << bit)) == 0) result = 0;
    }
    return result;
}
