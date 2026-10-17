#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E2900; symbol: ARM7_WirelessCommand283.
volatile unsigned short *ARM7_WirelessCommand283(WirelessPacket *packet) {
 return ARM7_WirelessCommandNoPayload(packet,0x283,3);
}
