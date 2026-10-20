#include <globaldefs.h>
ARM
extern "C" int WfcUtility_HasValidIpv4HostBits(...);
extern "C" int WfcUtility_IsValidIpv4LeadingOctet(...);
extern "C" int RuntimeMemory_CompareByteRanges(...);
extern "C" int WfcUtility_HasNonemptySsid(...);
extern "C" int Util_WriteLeadingBitMaskBytes(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov031 @ 0x22460c0; symbol: data_ov031_022460c0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityValidateConnectionProfile_UnknownRoleInitializedBytes[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0221BCB8; symbol: ValidateObservedNetworkConfigurationRanges.
extern "C" int WfcUtility_ValidateConnectionProfile(char*self){
unsigned mode=B(self,231);if(mode==255)return 1;if(mode>2)return 0;if(!WfcUtility_HasNonemptySsid((unsigned char*)self+64))return 0;if(RuntimeMemory_CompareByteRanges(self+192,WfcUtilityValidateConnectionProfile_UnknownRoleInitializedBytes,4)){if(!WfcUtility_IsValidIpv4LeadingOctet(self+196))return 0;unsigned bits=B(self,208);if(bits>32)return 0;unsigned char mask[4];Util_WriteLeadingBitMaskBytes(bits,mask);if(!WfcUtility_HasValidIpv4HostBits(self+192,mask))return 0;}if(RuntimeMemory_CompareByteRanges(self+200,WfcUtilityValidateConnectionProfile_UnknownRoleInitializedBytes,4)){if(!WfcUtility_IsValidIpv4LeadingOctet(self+200)&&!WfcUtility_IsValidIpv4LeadingOctet(self+204))return 0;}return 1;
}
