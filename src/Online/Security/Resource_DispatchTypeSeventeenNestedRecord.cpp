#include <globaldefs.h>
THUMB
extern "C" unsigned WirelessSetup_DecodeNetworkHalfword(unsigned);
extern "C" int Resource_VerifyPrefixedPayloadAndReplaceDecodedBytes(void*);
extern "C" void* WirelessSetup_ProcessNegotiationReply(void*,void*,unsigned*,void*);
extern "C" void* WirelessSetup_ProcessConfigurationReply(void*,void*,unsigned*,void*);
extern "C" void* WirelessSetup_ProcessCompletionReply(void*,void*,unsigned*,void*);
// Original: arm9/ov031 @ 0x0221D3B0; symbol: Resource_DispatchTypeSeventeenNestedRecord; size: 0xa0.
// Validates nested type17 record and dispatches converted subtype1010/2010/3010, counting rejected records.
extern "C" void* Resource_DispatchTypeSeventeenNestedRecord(void* value,unsigned char* record,unsigned* skipped,void* argument) {
 unsigned char* nested=record+12;
 if(WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)nested)<1){++*skipped;return value;}
 if(nested[15]!=17){++*skipped;return value;}
 if(Resource_VerifyPrefixedPayloadAndReplaceDecodedBytes(record+12)>0){++*skipped;return value;}
 switch(WirelessSetup_DecodeNetworkHalfword(*(unsigned short*)(nested+6))){case 0x1010:value=WirelessSetup_ProcessNegotiationReply(value,record,skipped,argument);break;case 0x2010:value=WirelessSetup_ProcessConfigurationReply(value,record,skipped,argument);break;case 0x3010:value=WirelessSetup_ProcessCompletionReply(value,record,skipped,argument);break;}return value;
}
