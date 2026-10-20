#include <globaldefs.h>
ARM
extern "C" int Network_ConnectSocketAddress(int,void*);
// Original: arm9/ov031 @ 0x02241404; symbol: SendByteSwappedHalfwordPacket; size: 0x7c.
extern "C" int Http_ConnectSocketToServer(int* self,int channel,int payload,int value){
struct Packet{unsigned char kind,version;unsigned short value;int payload;} packet;packet.kind=8;packet.version=2;value=(unsigned short)value;packet.value=((value>>8)&255)|((value<<8)&0xff00);packet.payload=payload;if(Network_ConnectSocketAddress(channel,&packet)<0)return self[1]?-1002:-1001;return 0;
}
