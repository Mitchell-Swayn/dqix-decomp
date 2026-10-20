#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224ced6; symbol: data_ov031_0224ced6.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 342 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSendDhcpRelease_UnknownRoleZeroInitializedStorage[];extern "C" volatile unsigned NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[];extern "C" unsigned char* Network_BuildDhcpMessageHeaderAndOptions(void*,int,int*);extern "C" void* Memory_FillRemainingBytes(int,unsigned,void*,unsigned);extern "C" unsigned Network_ConsumeBufferedSendAndCompactRemainder(void*,unsigned);

// Original: arm9/ov031 @ 0x02204260; symbol: Network_SendOptionalTwoWordParameters; size: 0x108.
extern "C" int Network_SendDhcpRequest(int omit){
unsigned char* base=NetworkSendDhcpRelease_UnknownRoleZeroInitializedStorage;int result;unsigned char *p=Network_BuildDhcpMessageHeaderAndOptions(base,3,&result);
 if(!omit){p[0]=50;p[1]=4;p[2]=((unsigned short)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[13]>>16))>>8;p[3]=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[13]>>16;p[4]=((unsigned short)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[13])>>8;p[5]=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[13];p[6]=54;p[7]=4;p[8]=((unsigned short)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[8]>>16))>>8;p[9]=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[8]>>16;p[10]=((unsigned short)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[8])>>8;p[11]=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage[8];p+=12;}
 *p++=255;p=(unsigned char*)Memory_FillRemainingBytes(0,300,p,p-base);Network_ConsumeBufferedSendAndCompactRemainder(base,p-base);return result;
}
