#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E28E8; symbol: ARM7_WirelessCommand281.
volatile unsigned short *ARM7_WirelessCommand281(WirelessPacket *packet) {
 return ARM7_WirelessCommandNoPayload(packet,0x281,4);
}
