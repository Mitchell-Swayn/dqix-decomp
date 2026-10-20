#include <globaldefs.h>
ARM
struct NetworkState {char prefix[6];unsigned short identifier;char pad[72];unsigned address;};
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" NetworkState NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
extern "C" unsigned short Network_AccumulateBigEndianChecksum(unsigned char*,unsigned,unsigned);
extern "C" unsigned Network_ComplementChecksumWithNonzeroEncoding(unsigned);
extern "C" void Network_FragmentTwoPayloadSpans(unsigned char*,unsigned,unsigned char*,unsigned,unsigned,unsigned char);
inline int SwapHalf(int value){return (value>>8)|(value<<8);}
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02201414; symbol: func_ov031_02201414; size: 0x13C.
// Constructs UDP header and pseudo-header checksum, then fragments the header and payload as IPv4.
extern "C" void Network_BuildUdpChecksumAndTransmit(unsigned char* payload,unsigned length,char* context){
unsigned char* base=F(unsigned char*,context,0x4c);unsigned char* header=base+34;
F(unsigned short,header,-12)=SwapHalf((unsigned short)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.address>>16));
F(unsigned short,header,-10)=SwapHalf((unsigned short)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.address);
F(unsigned short,header,-8)=SwapHalf((unsigned short)(F(unsigned,context,0x1c)>>16));
F(unsigned short,header,-6)=SwapHalf((unsigned short)F(unsigned,context,0x1c));
F(unsigned short,header,-4)=0x1100;
F(unsigned short,header,4)=SwapHalf((unsigned short)(length+8));
F(unsigned short,header,-2)=F(unsigned short,header,4);
F(unsigned short,header,2)=SwapHalf(F(unsigned short,context,0x18));
F(unsigned short,base,34)=SwapHalf(F(unsigned short,context,10));
F(unsigned short,header,6)=0;
unsigned checksum=Network_AccumulateBigEndianChecksum(header-12,20,0);
checksum=Network_AccumulateBigEndianChecksum(payload,length,checksum);
checksum=Network_ComplementChecksumWithNonzeroEncoding((unsigned short)checksum);
F(unsigned short,header,6)=SwapHalf(checksum);
Network_FragmentTwoPayloadSpans(header,8,payload,length,F(unsigned,context,0x1c),17);
}
