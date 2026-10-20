#include <globaldefs.h>
#include <System/Memory.h>
ARM
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
extern "C" {extern char NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage[];extern volatile unsigned NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];void ProcessBufferAfterSixByteHeader(void*,int,int,int);}
inline unsigned short Swap16(unsigned short value){return (value>>8)|(value<<8);}
// Original: arm9/ov031 @ 0x022017C4; symbol: func_ov031_022017c4; size: 0xA8.
extern "C" void Network_BuildAndSendArpReply(char* packet){
*(unsigned short*)(packet+6)=0x200;
MI_CpuCopy8(packet+8,packet+0x12,10);
MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,packet+8,6);
*(unsigned short*)(packet+14)=Swap16(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[20]>>16);
*(unsigned short*)(packet+16)=Swap16(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[20]);
MI_CpuCopy8(packet+0x12,packet-14,6);
MI_CpuCopy8(NetworkBroadcastArpRequest_UnknownRoleZeroInitializedStorage,packet-8,6);
ProcessBufferAfterSixByteHeader(packet-14,42,0,0);
}
