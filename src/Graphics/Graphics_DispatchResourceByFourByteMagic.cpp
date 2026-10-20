#include <globaldefs.h>
ARM
#include <std_library_functions.h>
// Original data: arm9/main @ 0x20f01b0; symbol: data_020f01b0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 20580c0274580c02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f01f8; symbol: data_020f01f8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d85d0c02985e0c02585f.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f0218; symbol: data_020f0218.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d85a0c02985b0c02585c0c02185d0c02385b0c02f85b0c02b85c0c02785d0c02.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Graphics_LoadTaggedLayerResource_TextCHAR[],Graphics_LoadTaggedLayerResource_TextPALT[],Graphics_LoadTaggedLayerResource_TextSCRN[];extern unsigned GraphicsLoadTaggedLayerResource_UnknownRoleProcedureReferenceRecords[][4],GraphicsTransferPaletteRange_UnknownRoleProcedureReferenceRecords[],GraphicsTransferScreenBuffer_UnknownRoleProcedureReferenceRecords[][4];extern "C" void __clear(void*,unsigned);extern "C" void Graphics_TransferSerializedCharacterPayload(void*,unsigned,void*),Graphics_TransferSelectedPaletteBlocks(void*,unsigned,void*),Tilemap_ResetResourceDescriptor(void*),Graphics_CopyPayloadLengthAndInvokeTransferCallback(void*,unsigned,void*);
extern "C" int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
struct Nibbles{unsigned char low:4,high:4;};
// Original: arm9/main @ 0x0204B3A0; symbol: func_0204b3a0; size: 0x120.
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char* object,void* data){unsigned char prefix[8],temp[16];if(data){__clear(prefix,5);memcpy(prefix,data,5);if(!RuntimeMemory_CompareByteRanges(prefix,Graphics_LoadTaggedLayerResource_TextCHAR,4)){Nibbles* kind=(Nibbles*)(object+28);Graphics_TransferSerializedCharacterPayload(object,GraphicsLoadTaggedLayerResource_UnknownRoleProcedureReferenceRecords[kind->low][kind->high],data);}else if(!RuntimeMemory_CompareByteRanges(prefix,Graphics_LoadTaggedLayerResource_TextPALT,4)){Nibbles* kind=(Nibbles*)(object+28);Graphics_TransferSelectedPaletteBlocks(object+12,GraphicsTransferPaletteRange_UnknownRoleProcedureReferenceRecords[kind->low],data);}else if(!RuntimeMemory_CompareByteRanges(prefix,Graphics_LoadTaggedLayerResource_TextSCRN,4)){Tilemap_ResetResourceDescriptor(temp);Nibbles* kind=(Nibbles*)(object+28);Graphics_CopyPayloadLengthAndInvokeTransferCallback(temp,GraphicsTransferScreenBuffer_UnknownRoleProcedureReferenceRecords[kind->low][kind->high],data);}}}
