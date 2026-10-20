#include <globaldefs.h>
THUMB
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned System_Copy8WithReversedPointers(...);
extern "C" unsigned WirelessSetup_ReadLittleEndianFieldValue(...);
extern "C" unsigned Memory_FillBufferWithLowByteUsingVectorizedMemset(...);
extern "C" unsigned WirelessSetup_DecodeNetworkWord(...);
extern "C" unsigned WirelessSetup_DecodeNetworkHalfword(...);
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221D82C; symbol: ParseLinkedTaggedFieldsIntoRecord; size: 0xbc.
// Follows offset-linked tagged fields, copies three payload types, validates lengths and stores decoded fields34/38.
extern "C" int WirelessSetup_ParseNegotiationFields(char* source,char* destination){
 char* record;Memory_FillBufferWithLowByteUsingVectorizedMemset(destination,0,260);char* second=destination;record=source;second+=128;
 for(;;){int length=WirelessSetup_DecodeNetworkHalfword(H(record,2));if(length<=0)return -1;
 switch(B(record,0)){case 0:System_Copy8WithReversedPointers(destination,record+6,length);break;case 1:System_Copy8WithReversedPointers(second,record+6,length);break;case 2:System_Copy8WithReversedPointers(destination+256,record+6,length);break;
 case 3:case 4:if((int)WirelessSetup_DecodeNetworkHalfword(B(record,6))<=0)return -2;break;
 case 5:U(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage,0x34)=WirelessSetup_DecodeNetworkWord(WirelessSetup_ReadLittleEndianFieldValue(record+6,length));break;
 case 6:U(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage,0x38)=WirelessSetup_DecodeNetworkWord(WirelessSetup_ReadLittleEndianFieldValue(record+6,length));break;default:return -1;}
 unsigned next=H(record,4);if(next)record=source+WirelessSetup_DecodeNetworkHalfword(next);else return 0;}
}
