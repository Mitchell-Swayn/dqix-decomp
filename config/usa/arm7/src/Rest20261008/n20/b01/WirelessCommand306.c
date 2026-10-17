#pragma dont_inline on
#include "../../../Completion20261008/c18/b10/WirelessPackets.h"
/* Native command forwarding; caller owns the packet and reply storage. */
// Original: arm7/mainram @ 0x027E29A0; symbol: ARM7_WirelessCommand306.
volatile unsigned short *ARM7_WirelessCommand306(WirelessPacket *packet) {
    return ARM7_WirelessCommandNoPayload(packet, 0x306, 9);
}
