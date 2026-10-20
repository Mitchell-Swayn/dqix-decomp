#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e700; symbol: data_ov031_0224e700.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
extern "C" void System_Copy8WithReversedPointers(void*,const void*,unsigned);extern "C" unsigned short WirelessSetup_EncodeNetworkHalfword(unsigned short);extern "C" unsigned WirelessSetup_EncodeNetworkWord(unsigned);
// Original: arm9/ov031 @ 0x0221DF48; symbol: BuildPayloadAndOpcode60Records; size: 0x8C.
// Builds a padded payload record followed by opcode60 and a four-byte value14 record.
extern "C" short BuildPayloadAndOpcode60Records(char* out) {
short total=0;out[0]=AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage_Variant3[0x1d];out[1]=1;
short length=(short)*(unsigned*)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage+0x28);
System_Copy8WithReversedPointers(out+6,*(void**)(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage+0x24),length);
*(unsigned short*)(out+2)=WirelessSetup_EncodeNetworkHalfword(length);
short padded=((short)(length+6)+1)/2*2;
*(unsigned short*)(out+4)=WirelessSetup_EncodeNetworkHalfword(padded);
total+=padded;out[padded]=0x60;char* next=out+padded;next[1]=0;
*(unsigned short*)(next+4)=WirelessSetup_EncodeNetworkHalfword(0);
unsigned value=WirelessSetup_EncodeNetworkWord(14);
System_Copy8WithReversedPointers(next+6,&value,4);
*(unsigned short*)(next+2)=WirelessSetup_EncodeNetworkHalfword(4);
total+=10;return total;
}