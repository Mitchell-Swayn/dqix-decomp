#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E292C; symbol: ARM7_WirelessCommand301.
volatile unsigned short *ARM7_WirelessCommand301(WirelessPacket *packet) {
 return ARM7_WirelessCommandNoPayload(packet,0x301,1);
}
