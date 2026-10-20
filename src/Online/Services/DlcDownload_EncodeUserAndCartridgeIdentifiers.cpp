#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {void Memory_ZeroBytes(void*,unsigned);void WfcUtility_DecodePersistentIdentifierFields(void*);int NasAuth_FormatPaddedUnsignedLongLong(void*,unsigned,unsigned,int);void DlcDownload_EncodeBase64String(void*,const void*,int);}
// Original: arm9/ov031 @ 0x0223E9D4; symbol: CopyDecodedIdentifierAndCartridgeCode; size: 0x8c.
// Decodes global identifier, formats13 bytes and copies cartridge code4 bytes.
extern "C" int DlcDownload_EncodeUserAndCartridgeIdentifiers(void* code,void* identifier){unsigned fields[5];unsigned char encoded[16];Memory_ZeroBytes(fields,20);WfcUtility_DecodePersistentIdentifierFields(fields);if((*(unsigned long long*)fields)==0)return 0;if(NasAuth_FormatPaddedUnsignedLongLong(encoded,fields[0],fields[1],13)<0)return 0;DlcDownload_EncodeBase64String(identifier,encoded,13);DlcDownload_EncodeBase64String(code,(void*)0x027ffe0c,4);return 1;}
