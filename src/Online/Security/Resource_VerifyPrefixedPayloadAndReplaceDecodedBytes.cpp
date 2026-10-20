#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f440; symbol: data_ov031_0224f440.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WirelessSetup_SendCompletionRequest_TextMELCO[],WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage[];
extern "C" void System_Copy8WithReversedPointers(void*,const void*,unsigned);
extern "C" unsigned Util_GetStringLength(const void*);
extern "C" int WirelessSetup_TransformRequestToken(void*,unsigned,void*,unsigned);
extern "C" void Aoss_SetLastError(int);
extern "C" int WirelessSetup_DecodeNetworkHalfword(unsigned short);
extern "C" int WirelessSetup_ValidateSessionIdentifier(int,void*);
extern "C" char* Aoss_AllocateBuffer(unsigned);
extern "C" void Aoss_FreeBuffer(void*);
extern "C" int WirelessSetup_DecodeAndVerifyPrefixedPayload(void*,void*,int,int,void*,void*,int);
extern "C" int Aoss_GetLastError();
extern "C" unsigned short WirelessSetup_EncodeNetworkHalfword(unsigned short);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x0221D6A8; symbol: Resource_VerifyPrefixedPayloadAndReplaceDecodedBytes; size: 0xF4.
extern "C" int Resource_VerifyPrefixedPayloadAndReplaceDecodedBytes(char* self){
 char prefix[8];char* payload=self+24;System_Copy8WithReversedPointers(prefix,self+16,8);if(WirelessSetup_TransformRequestToken(prefix,8,WirelessSetup_SendCompletionRequest_TextMELCO,Util_GetStringLength(WirelessSetup_SendCompletionRequest_TextMELCO))==-1){Aoss_SetLastError(2);return -100;}
 int status=WirelessSetup_ValidateSessionIdentifier(WirelessSetup_DecodeNetworkHalfword(H(self,6)),prefix);if(status)return status;
 if(WirelessSetup_DecodeNetworkHalfword(H(self,6))==4096)System_Copy8WithReversedPointers(WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage,prefix,8);
 if(!(WirelessSetup_DecodeNetworkHalfword(H(self,12))&15))return 0;
 int length=WirelessSetup_DecodeNetworkHalfword(H(payload,0));char* temp=Aoss_AllocateBuffer(length);if(!temp){Aoss_SetLastError(2);return 100;}
 if(WirelessSetup_DecodeAndVerifyPrefixedPayload(payload+4,temp,length,B(self,14),payload+2,WirelessSetupSendNegotiationRequest_UnknownRoleZeroInitializedStorage,8)<0){Aoss_FreeBuffer(temp);if(Aoss_GetLastError()==2)return 100;return 200;}
 System_Copy8WithReversedPointers(payload,temp,length);H(self,10)=WirelessSetup_EncodeNetworkHalfword((unsigned short)length);Aoss_FreeBuffer(temp);return 0;
}