#pragma dont_inline on
#include "WirelessPackets.h"
// Original: arm7/mainram @ 0x027E25BC; symbol: ARM7_WirelessCommand20D.
volatile unsigned short *ARM7_WirelessCommand20D(WirelessPacket *packet,const void *values) {
 WirelessPacket *reply;
 packet->transport[0]=0;
 packet->transport[1]=0;
 packet->transport[2]=0;
 packet->transport[3]=0;
 packet->transport[4]=0;
 packet->transport[5]=0;
 packet->command=0x20d;
 packet->wordCount=16;
 ARM7_CopyBytes(values,(void*)packet->payload,32);
 reply=(WirelessPacket*)((unsigned short*)packet+*(volatile unsigned short*)&packet->wordCount);
 reply->payload[0]=packet->command;
 reply->payload[1]=1;
 ARM7_SubmitWirelessPacket(packet);
 return reply->payload;
}
