#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma optimize_for_size off
#pragma always_inline on
#define F(T,p,o) (*(T*)((unsigned char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x0224C980; symbol: data_ov031_0224c980.
// Mutable zero-initialized stack state: release callback at +0x40, IPv4 address at +0x50.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
extern "C" int Network_IsLocalOrAcceptedAddress(unsigned);
extern "C" unsigned short InvertLower16BitsOfComputedValue(int,int);
extern "C" void Network_UpdateAddressCache(const void*,unsigned,int);
extern "C" unsigned char* Network_ReassembleIpv4Fragments(unsigned char*,int*);
extern "C" void Network_DeliverUdpDatagramToSocket(void*,void*,unsigned);
extern "C" void Network_DispatchValidatedEchoPacket(unsigned,unsigned,int);
extern "C" void Network_DispatchValidatedTcpSegment(char*,char*,int);
inline int SwapHalf(int x){return (x>>8)|(x<<8);}
inline unsigned ReadAddress(void* p,int offset){
 int low=F(unsigned short,p,offset+2),high=F(unsigned short,p,offset);
 return ((unsigned)(unsigned short)SwapHalf(high)<<16)|(unsigned short)SwapHalf(low);
}
inline unsigned ConfiguredAddress(){return F(unsigned,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x50);}
// Original: arm9/ov031 @ 0x02202E44; symbol: func_ov031_02202e44; size: 0x1C4.
// Checks IPv4 destination, length and checksum, learns the sender, reassembles
// fragments, dispatches transport data, and frees an assembled frame afterwards.
extern "C" void Network_ValidateAndDispatchIpv4Packet(unsigned char* packet,unsigned receivedLength)
{
 int lowSource=F(unsigned short,packet,14),highSource=F(unsigned short,packet,12),lowDestination=F(unsigned short,packet,18),highDestination=F(unsigned short,packet,16);
 unsigned short a=SwapHalf(lowSource),b=SwapHalf(highSource),c=SwapHalf(lowDestination),d=SwapHalf(highDestination);
 unsigned sender=((unsigned)b<<16)|a;
 unsigned destination=((unsigned)d<<16)|c;
 if(destination!=sender) {
  if(!Network_IsLocalOrAcceptedAddress(ReadAddress(packet,16)))return;
  if(receivedLength<(unsigned short)SwapHalf(F(unsigned short,packet,2)))return;
  if(InvertLower16BitsOfComputedValue((int)packet,(packet[0]&15)*4)!=0xffff)return;
  if(ConfiguredAddress()==ReadAddress(packet,16))
   Network_UpdateAddressCache(packet-8,ReadAddress(packet,12),1);
 }
 int assembled;
 packet=Network_ReassembleIpv4Fragments(packet,&assembled);
 if(!packet)return;
 unsigned header=(packet[0]&15)*4;
 unsigned char* payload=packet+header;
 unsigned length=(unsigned short)SwapHalf(F(unsigned short,packet,2))-header;
 unsigned protocol=packet[9];
 if(protocol==17)Network_DeliverUdpDatagramToSocket(packet,payload,length);
 else if(F(unsigned,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x50)){
  if(protocol==1)Network_DispatchValidatedEchoPacket((unsigned)packet,(unsigned)payload,(int)length);
  else if(protocol==6)Network_DispatchValidatedTcpSegment((char*)packet,(char*)payload,(int)length);
 }
 if(assembled){
  typedef void (*ReleaseCallback)(void*);
  F(ReleaseCallback,NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x40)(packet-14);
 }
}
