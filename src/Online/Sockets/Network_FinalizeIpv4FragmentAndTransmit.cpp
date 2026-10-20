#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
// Original data: arm9/ov031 @ 0x224968c; symbol: data_ov031_0224968c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex aaaa03000000080000000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224ce68; symbol: data_ov031_0224ce68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 42 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[],ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes[],NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned short InvertLower16BitsOfComputedValue(int,int);extern "C" unsigned Network_IsMulticastAddress(unsigned);extern "C" void Network_PrependEthernetHeaderAndSend(unsigned,int,unsigned,unsigned,unsigned,unsigned short);extern "C" void MI_CpuCopy8(const void*,void*,unsigned);extern "C" int _Z20DisableIRQInterruptsv();extern "C" int _Z20SetIRQInterruptStatei(int);extern "C" void Network_AppendValidatedFrameToRing(const void*,const void*,const unsigned char*,unsigned,const void*,unsigned);
// Original: arm9/ov031 @ 0x02201044; symbol: Network_FinalizePacketHeaderAndTransmit.
extern "C" void Network_FinalizeIpv4FragmentAndTransmit(unsigned char* packet,int length,unsigned arg,unsigned flags,unsigned address,unsigned protocol){
unsigned short total=length+20+flags;unsigned short port=protocol;U(packet,-18)=((int)total>>8)|((int)total<<8);U(packet,-14)=((int)port>>8)|((int)port<<8);U(packet,-10)=0;int checksum=InvertLower16BitsOfComputedValue((int)(packet-20),20);U(packet,-10)=(checksum>>8)|(checksum<<8);
if(address!=0x7f000001 && address!=W(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x50))Network_PrependEthernetHeaderAndSend((unsigned)(packet-20),length+20,arg,flags,address,0x800);
if(address!=0x7f000001 && address!=W(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x50)){if(!Network_IsMulticastAddress(address))return;}
MI_CpuCopy8(ProcessBufferAfterSixByteHeader_UnknownRoleInitializedBytes,packet-28,8);int irq=_Z20DisableIRQInterruptsv();Network_AppendValidatedFrameToRing(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,packet-28,length+28,(void*)arg,flags);_Z20SetIRQInterruptStatei(irq);
}
