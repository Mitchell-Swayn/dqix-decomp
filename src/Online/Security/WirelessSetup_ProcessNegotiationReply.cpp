#include <globaldefs.h>
THUMB
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned Aoss_SetLastError(...);
extern "C" unsigned WirelessSetup_ParseNegotiationFields(...);
extern "C" unsigned WirelessSetup_DecodeNetworkWord(...);
extern "C" unsigned System_CompareEncodedSequenceProgression(...);
extern "C" unsigned WirelessSetup_TestPayloadCipherCapability(...);
extern "C" unsigned WirelessSetup_DecodeNetworkHalfword(...);
// Original data: arm9/ov031 @ 0x224e6e0; symbol: data_ov031_0224e6e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov031 @ 0x224e720; symbol: data_ov031_0224e720.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 640 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupProcessNegotiationReply_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221d450; symbol: ValidateTaggedReplyAndUpdateSharedContext.
extern "C" int WirelessSetup_ProcessNegotiationReply(int status,unsigned char* packet,unsigned* failures,const char* expected){if(status){(*failures)++;return status;}unsigned char* header=packet+12;unsigned char* record=packet+0x24;if((int)System_CompareEncodedSequenceProgression(expected,(const char*)header+16)<0){(*failures)++;return status;}if(!WirelessSetup_DecodeNetworkHalfword(H(record,2))){(*failures)++;return status;}if(B(record,0)==7){if((int)WirelessSetup_DecodeNetworkWord(U(record,4))==-2)Aoss_SetLastError(20);else if((int)WirelessSetup_DecodeNetworkWord(U(record,4))==-3)Aoss_SetLastError(21);else Aoss_SetLastError(24);return -1;}if(B(record,0)!=1){(*failures)++;return status;}int parsed=WirelessSetup_ParseNegotiationFields((char*)record+4,(char*)WirelessSetupProcessNegotiationReply_UnknownRoleZeroInitializedStorage);if(parsed<0){if(parsed==-2){Aoss_SetLastError(22);return -1;}(*failures)++;return status;}unsigned value=WirelessSetup_DecodeNetworkHalfword(H(header,12));U(AossRunSetupNegotiation_UnknownRoleZeroInitializedStorage,0)=WirelessSetup_TestPayloadCipherCapability(value);*failures=0;return 1;}
