#include <globaldefs.h>
ARM
struct NetworkState {char prefix[6];unsigned short identifier;char pad[72];unsigned address;};
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" NetworkState NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
extern "C" void Network_FinalizeIpv4FragmentAndTransmit(unsigned char*,int,unsigned,unsigned,unsigned,unsigned);
inline int SwapHalf(int value){return (value>>8)|(value<<8);}
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
#pragma always_inline on
inline void InitializeIPv4Header(unsigned char* packet,unsigned address,unsigned char protocol){
NetworkState* network=&NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
F(unsigned char,packet,-20)=0x45;F(unsigned char,packet,-19)=0;
++network->identifier;
F(unsigned short,packet,-16)=SwapHalf(network->identifier);
F(unsigned char,packet,-12)=128;F(unsigned char,packet,-11)=protocol;
F(unsigned short,packet,-8)=SwapHalf((unsigned short)(network->address>>16));
F(unsigned short,packet,-6)=SwapHalf((unsigned short)network->address);
F(unsigned short,packet,-4)=SwapHalf((unsigned short)(address>>16));
F(unsigned short,packet,-2)=SwapHalf((unsigned short)address);
}
// Original: arm9/ov031 @ 0x0220116C; symbol: func_ov031_0220116c; size: 0x1F8.
// Initializes an IPv4 header and fragments two payload spans at1480 bytes, tracking eight-byte offsets.
extern "C" void Network_FragmentTwoPayloadSpans(unsigned char* packet,unsigned firstLength,unsigned char* second,unsigned secondLength,unsigned address,unsigned char protocol){
unsigned short offset=0;InitializeIPv4Header(packet,address,protocol);
if(firstLength>1480){unsigned char* cursor=packet;
while(firstLength>1480){Network_FinalizeIpv4FragmentAndTransmit(packet,0,(unsigned)cursor,1480,address,offset|0x2000);cursor+=1480;firstLength-=1480;offset+=185;}
if(firstLength){if(secondLength)Network_FinalizeIpv4FragmentAndTransmit(packet,0,(unsigned)cursor,firstLength,address,offset|0x2000);else Network_FinalizeIpv4FragmentAndTransmit(packet,0,(unsigned)cursor,firstLength,address,offset);offset+=firstLength>>3;firstLength=0;}
}
while(firstLength+secondLength>1480){unsigned amount=1480-firstLength;Network_FinalizeIpv4FragmentAndTransmit(packet,firstLength,(unsigned)second,amount,address,offset|0x2000);secondLength-=amount;firstLength=0;second+=amount;offset+=185;}
if(firstLength+secondLength)Network_FinalizeIpv4FragmentAndTransmit(packet,firstLength,(unsigned)second,secondLength,address,offset);
}
