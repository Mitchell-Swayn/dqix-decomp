#include <globaldefs.h>
#include <std_library_functions.h>
struct Mode{unsigned char a:4,b:4;};struct Owner{char pad[16];char*array;char more[8];Mode mode;unsigned char count,capacity;};
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
extern "C" {void __clear(void*,unsigned);int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);int ParsePackedImageHeaderAndDispatchFlushedData(Owner*,unsigned,const void*,unsigned);int FlushAndTransferSelectedThirtyTwoByteBlocks(void*,unsigned,const void*,unsigned);int AllocateAndCopySerializedPayload(void*,unsigned,const void*,unsigned);extern char Graphics_LoadTaggedLayerResource_TextCHAR[],Graphics_LoadTaggedLayerResource_TextPALT[],Graphics_LoadTaggedLayerResource_TextSCRN[];extern unsigned GraphicsLoadTaggedLayerResource_UnknownRoleProcedureReferenceRecords[][4],GraphicsTransferScreenBuffer_UnknownRoleProcedureReferenceRecords[][4],GraphicsTransferPaletteRange_UnknownRoleProcedureReferenceRecords[];}
// Original: arm9/main @ 0x0204B174; symbol: func_0204b174; size: 0x16C.
extern "C" ARM int Graphics_LoadTaggedLayerResource(void*object,const void*data,unsigned arg,unsigned ignoredLength){Owner*p=(Owner*)object;char tag[5];if(!data)return 1;__clear(tag,5);memcpy(tag,data,5);if(!RuntimeMemory_CompareByteRanges(tag,Graphics_LoadTaggedLayerResource_TextCHAR,4))return ParsePackedImageHeaderAndDispatchFlushedData(p,GraphicsLoadTaggedLayerResource_UnknownRoleProcedureReferenceRecords[p->mode.a][p->mode.b],data,arg);if(!RuntimeMemory_CompareByteRanges(tag,Graphics_LoadTaggedLayerResource_TextPALT,4))return FlushAndTransferSelectedThirtyTwoByteBlocks((char*)p+12,GraphicsTransferPaletteRange_UnknownRoleProcedureReferenceRecords[p->mode.a],data,arg);if(!RuntimeMemory_CompareByteRanges(tag,Graphics_LoadTaggedLayerResource_TextSCRN,4)&&p->array){if(p->capacity<=p->count)return 1;int result=AllocateAndCopySerializedPayload(p->array+p->count*16,GraphicsTransferScreenBuffer_UnknownRoleProcedureReferenceRecords[p->mode.a][p->mode.b],data,arg);if(result)result=1;else{p->count++;result=0;}return result;}return 1;}
