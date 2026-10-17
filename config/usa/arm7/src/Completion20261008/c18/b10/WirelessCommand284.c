#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E2918; symbol: ARM7_WirelessCommand284.
volatile unsigned short *ARM7_WirelessCommand284(WirelessPacket *packet) {
 return ARM7_WirelessCommandNoPayload(packet,0x284,2);
}
