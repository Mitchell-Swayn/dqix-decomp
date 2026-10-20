#include <globaldefs.h>
ARM
struct NetworkState {char prefix[2];unsigned short maximumSegment;char pad[76];unsigned address;};
struct ContextOwner {void* pad;void* current;};
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" ContextOwner OSInitThread_UnknownRoleZeroInitializedStorage_Variant2;
// Original data: arm9/ov031 @ 0x224cbe8; symbol: data_ov031_0224cbe8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 192 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224ce92; symbol: data_ov031_0224ce92.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkStopWorkersAndResetStack_UnknownRoleZeroInitializedStorage[],NetworkBuildTcpChecksumAndAdvanceSequence_UnknownRoleZeroInitializedStorage[];
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
// Original: arm9/ov031 @ 0x02201550; symbol: func_ov031_02201550; size: 0x274.
// Builds TCP pseudo-header, optional SYN MSS option and checksum, transmits and advances sequence state.
extern "C" void Network_BuildTcpChecksumAndAdvanceSequence(unsigned char* payload,unsigned length,char* context,unsigned flags){
if(F(unsigned char,context,8)==0)return;
unsigned char* header;
if(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2.current==NetworkStopWorkersAndResetStack_UnknownRoleZeroInitializedStorage)header=(unsigned char*)NetworkBuildTcpChecksumAndAdvanceSequence_UnknownRoleZeroInitializedStorage;else header=F(unsigned char*,context,0x4c)+34;
unsigned headerLength=(flags&2)?24:20;
F(unsigned short,header,-12)=SwapHalf((unsigned short)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.address>>16));
F(unsigned short,header,-10)=SwapHalf((unsigned short)NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.address);
F(unsigned short,header,-8)=SwapHalf((unsigned short)(F(unsigned,context,0x1c)>>16));
F(unsigned short,header,-6)=SwapHalf((unsigned short)F(unsigned,context,0x1c));
F(unsigned short,header,-4)=0x600;
F(unsigned short,header,-2)=SwapHalf((unsigned short)(headerLength+length));
F(unsigned short,header,0)=SwapHalf(F(unsigned short,context,10));
F(unsigned short,header,2)=SwapHalf(F(unsigned short,context,0x18));
F(unsigned short,header,4)=SwapHalf((unsigned short)(F(unsigned,context,0x28)>>16));
F(unsigned short,header,6)=SwapHalf((unsigned short)F(unsigned,context,0x28));
F(unsigned short,header,8)=SwapHalf((unsigned short)(F(unsigned,context,0x24)>>16));
F(unsigned short,header,10)=SwapHalf((unsigned short)F(unsigned,context,0x24));
F(unsigned char,header,12)=(headerLength>>2)<<4;F(unsigned char,header,13)=flags;
F(unsigned short,header,14)=SwapHalf((unsigned short)(F(unsigned,context,0x3c)-F(unsigned,context,0x44)));
F(unsigned short,header,16)=0;F(unsigned short,header,18)=0;
if(flags&2){F(unsigned short,header,20)=SwapHalf((unsigned short)((NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.maximumSegment+0x2040000u)>>16));F(unsigned short,header,22)=SwapHalf((unsigned short)(NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.maximumSegment+0x2040000u));}
unsigned checksum=Network_AccumulateBigEndianChecksum(header-12,headerLength+12,0);
checksum=Network_AccumulateBigEndianChecksum(payload,length,checksum);checksum=Network_ComplementChecksumWithNonzeroEncoding((unsigned short)checksum);F(unsigned short,header,16)=SwapHalf(checksum);
Network_FragmentTwoPayloadSpans(header,headerLength,payload,length,F(unsigned,context,0x1c),6);
F(unsigned,context,0x28)+=length;if(flags&3)++F(unsigned,context,0x28);
}
