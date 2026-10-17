#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E24B0; symbol: ARM7_WirelessCommand200.
volatile unsigned short *ARM7_WirelessCommand200(WirelessPacket *packet) {
 WirelessPacket *reply;
 packet->transport[0]=0;
 packet->transport[1]=0;
 packet->transport[2]=0;
 packet->transport[3]=0;
 packet->transport[4]=0;
 packet->transport[5]=0;
 packet->command=0x200;
 packet->wordCount=72;
 reply=(WirelessPacket*)((unsigned short*)packet+packet->wordCount);
 reply->payload[0]=packet->command;
 reply->payload[1]=1;
 ARM7_SubmitWirelessPacket(packet);
 return reply->payload;
}
