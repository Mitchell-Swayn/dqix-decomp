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
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void ProcessBufferAfterSixByteHeader(void*,int,int,int);
extern "C" unsigned Network_SelectDestinationOrDefaultGateway(unsigned);
extern "C" unsigned Network_IsMulticastAddress(unsigned);
extern "C" void* Network_LookupDestinationMacAddress(unsigned);
extern "C" void* Network_ResolveMacAddressWithArpRetries(unsigned);
// Original data: arm9/ov031 @ 0x224ce68; symbol: data_ov031_0224ce68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 42 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02200f74; symbol: Network_PrependEthernetHeaderAndSend; size: 0xd0.
extern "C" void Network_PrependEthernetHeaderAndSend(unsigned buffer,int length,unsigned argument,unsigned flags,unsigned address,unsigned short protocol){
U16(buffer-2)=(protocol>>8)|(protocol<<8);
if(!Network_IsMulticastAddress(address)){
 address=Network_SelectDestinationOrDefaultGateway(address);if(!address)return;void* hardware=Network_LookupDestinationMacAddress(address);if(!hardware)hardware=Network_ResolveMacAddressWithArpRetries(address);if(!hardware)return;MI_CpuCopy8(hardware,(void*)(buffer-14),6);
}else{U8(buffer-14)=1;U8(buffer-13)=0;U8(buffer-12)=0x5e;U8(buffer-11)=(address>>16)&127;U8(buffer-10)=address>>8;U8(buffer-9)=address;}
MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,(void*)(buffer-8),6);ProcessBufferAfterSixByteHeader((void*)(buffer-14),length+14,(int)argument,(int)flags);
}
