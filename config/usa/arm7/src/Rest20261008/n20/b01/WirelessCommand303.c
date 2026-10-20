#pragma dont_inline on
#include "../../../Completion20261008/c18/b10/WirelessPackets.h"
/* Native command forwarding; caller owns the packet and reply storage. */
// Original: arm7/mainram @ 0x027E295C; symbol: ARM7_WirelessCommand303.
volatile unsigned short *ARM7_WirelessCommand303(WirelessPacket *packet) {
    return ARM7_WirelessCommandNoPayload(packet, 0x303, 1);
}
