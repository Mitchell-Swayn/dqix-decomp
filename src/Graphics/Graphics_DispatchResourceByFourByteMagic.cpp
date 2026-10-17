#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern unsigned char data_020f0238[],data_020f023d[],data_020f0242[];extern unsigned data_020f01f8[][4],data_020f01b0[],data_020f0218[][4];extern "C" void __clear(void*,unsigned);extern "C" void InvokeCallbackWithBlockPayloadAndSize(void*,unsigned,void*),CopyAllOrMaskedThirtyTwoByteBlocks(void*,unsigned,void*),ClearHalfwordPairBytePairAndWordPair(void*),Graphics_CopyPayloadLengthAndInvokeTransferCallback(void*,unsigned,void*);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
struct Nibbles{unsigned char low:4,high:4;};
// Original: arm9/main @ 0x0204B3A0; symbol: func_0204b3a0; size: 0x120.
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char* object,void* data){unsigned char prefix[8],temp[16];if(data){__clear(prefix,5);memcpy(prefix,data,5);if(!RuntimeMemory_CompareByteRanges(prefix,data_020f0238,4)){Nibbles* kind=(Nibbles*)(object+28);InvokeCallbackWithBlockPayloadAndSize(object,data_020f01f8[kind->low][kind->high],data);}else if(!RuntimeMemory_CompareByteRanges(prefix,data_020f023d,4)){Nibbles* kind=(Nibbles*)(object+28);CopyAllOrMaskedThirtyTwoByteBlocks(object+12,data_020f01b0[kind->low],data);}else if(!RuntimeMemory_CompareByteRanges(prefix,data_020f0242,4)){ClearHalfwordPairBytePairAndWordPair(temp);Nibbles* kind=(Nibbles*)(object+28);Graphics_CopyPayloadLengthAndInvokeTransferCallback(temp,data_020f0218[kind->low][kind->high],data);}}}
