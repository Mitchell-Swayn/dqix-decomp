#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E2504; symbol: ARM7_WirelessCommand207.
volatile unsigned short *ARM7_WirelessCommand207(WirelessPacket *packet,unsigned short value) {
 WirelessPacket *reply;
 packet->transport[0]=0;
 packet->transport[1]=0;
 packet->transport[2]=0;
 packet->transport[3]=0;
 packet->transport[4]=0;
 packet->transport[5]=0;
 packet->command=0x207;
 packet->wordCount=1;
 packet->payload[0]=value;
 reply=(WirelessPacket*)((unsigned short*)packet+*(volatile unsigned short*)&packet->wordCount);
 reply->payload[0]=packet->command;
 reply->payload[1]=1;
 ARM7_SubmitWirelessPacket(packet);
 return reply->payload;
}
