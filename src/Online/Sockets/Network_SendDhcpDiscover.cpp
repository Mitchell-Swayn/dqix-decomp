#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned Memory_FillRemainingBytes(...);
extern "C" unsigned Network_ConsumeBufferedSendAndCompactRemainder(...);
extern "C" unsigned Network_BuildDhcpMessageHeaderAndOptions(...);
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224ced6; symbol: data_ov031_0224ced6.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 342 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSendDhcpRelease_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031:0220419c
extern "C" unsigned Network_SendDhcpDiscover(){unsigned result;char* start=(char*)NetworkSendDhcpRelease_UnknownRoleZeroInitializedStorage;char* out=(char*)Network_BuildDhcpMessageHeaderAndOptions(start,1,&result);if(U(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x34)){B(out,0)=0x32;B(out,1)=4;B(out,2)=((unsigned short)(U(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x34)>>16))>>8;B(out,3)=U(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x34)>>16;B(out,4)=((unsigned short)U(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x34))>>8;B(out,5)=U(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage,0x34);out+=6;}B(out++,0)=255;out=(char*)Memory_FillRemainingBytes(0,300,out,out-start);Network_ConsumeBufferedSendAndCompactRemainder(start,out-start);return result;}
