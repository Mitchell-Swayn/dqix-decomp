#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned InvertLower16BitsOfComputedValue(...);
extern "C" unsigned Network_ValidateUnicastEndpointAddressPair(...);
extern "C" unsigned Network_SendIcmpEchoReply(...);
extern "C" unsigned Network_DeliverIcmpEchoReplyToSocket(...);
// Original: arm9/ov031 @ 0x02201bb4; symbol: Network_DispatchValidatedEchoPacket; size: 0xd0.
extern "C" void Network_DispatchValidatedEchoPacket(unsigned header,unsigned packet,int length){
if(InvertLower16BitsOfComputedValue(packet,length)!=65535)return;
unsigned short last=U16(header+0x12),second=U16(header+0x10),third=U16(header+14),first=U16(header+12);
unsigned short a=(first>>8)|(first<<8),b=(third>>8)|(third<<8),c=(second>>8)|(second<<8),d=(last>>8)|(last<<8);
if(!Network_ValidateUnicastEndpointAddressPair(((unsigned)a<<16)|b,((unsigned)c<<16)|d))return;
switch(U8(packet)){case 0:Network_DeliverIcmpEchoReplyToSocket(header,packet,length);break;case 8:Network_SendIcmpEchoReply(header,packet,length);break;}
}