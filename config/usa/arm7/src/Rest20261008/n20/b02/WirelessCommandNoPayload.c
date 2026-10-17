#pragma dont_inline on
#include "../../../Completion20261008/c18/b10/WirelessPackets.h"
// Original: arm7/mainram @ 0x027E2A54; symbol: ARM7_WirelessCommandNoPayload.
volatile unsigned short *ARM7_WirelessCommandNoPayload(WirelessPacket *packet, unsigned short command, unsigned short replyWords) {
 WirelessPacket *reply;
 packet->transport[0]=0;
 packet->transport[1]=0;
 packet->transport[2]=0;
 packet->transport[3]=0;
 packet->transport[4]=0;
 packet->transport[5]=0;
 packet->command=command;
 packet->wordCount=0;

 reply=(WirelessPacket*)((unsigned short*)packet+packet->wordCount);
 reply->payload[0]=packet->command;
 reply->payload[1]=replyWords;
 ARM7_SubmitWirelessPacket(packet);
 return reply->payload;
}
