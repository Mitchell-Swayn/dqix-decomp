#include <globaldefs.h>
THUMB
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original data: arm9/ov031 @ 0x224b06c; symbol: data_ov031_0224b06c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 09080000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkParseSelectedNestedRecordSections_UnknownRoleInitializedBytes[];struct Shared{char pad[48];int flags;};extern "C" Shared AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage;extern "C" int WirelessSetup_DecodeNetworkHalfword(unsigned short);extern "C" int WirelessSetup_ParseShortKeyConfiguration(void*,void*),WirelessSetup_ParseLongKeyConfiguration(void*,void*),WirelessSetup_CopyTaggedConfigurationPayload(void*,void*);
// Original: arm9/ov031 @ 0x0221db48; symbol: Network_ParseSelectedNestedRecordSections; size 0x110.
extern "C" int Network_ParseSelectedNestedRecordSections(int section,unsigned char* data,int length,char* output,char* auxiliary){int flags=0;if(length<=0)return -2;for(;;){unsigned char* candidate=data;if(candidate[0]==NetworkParseSelectedNestedRecordSections_UnknownRoleInitializedBytes[section]){data=candidate;break;}int stride=WirelessSetup_DecodeNetworkHalfword(H(data,2))+4;length-=stride;data+=stride;if(length<=0)return -4;}unsigned short payloadLength=H(data,2);data+=4;int remaining=WirelessSetup_DecodeNetworkHalfword(payloadLength);char* destination=output+section*0x350;do{int result;switch(data[0]){case 3:result=WirelessSetup_ParseShortKeyConfiguration(data,destination+8);flags|=1;break;case 4:result=WirelessSetup_ParseShortKeyConfiguration(data,destination+0x138);flags|=2;break;case 5:result=WirelessSetup_ParseLongKeyConfiguration(data,destination+0x268);flags|=4;break;case 6:result=WirelessSetup_ParseLongKeyConfiguration(data,destination+0x2d8);flags|=8;break;case 10:result=WirelessSetup_CopyTaggedConfigurationPayload(data,auxiliary+((section+3)<<7));break;default:result=-3;break;}if(result)return result;int stride=WirelessSetup_DecodeNetworkHalfword(H(data,2))+4;remaining-=stride;data+=stride;}while(remaining>0);AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage.flags|=flags;return 0;}
