#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f01f8; symbol: data_020f01f8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d85d0c02985e0c02585f.
// Observed span: 10 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsLoadTaggedLayerResource_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0204A5E4; symbol: func_0204a5e4; size: 0x14.
extern "C" unsigned int Graphics_GetCharacterTransferCallback(unsigned int i,unsigned int j) { return ((unsigned int(*)[4])GraphicsLoadTaggedLayerResource_UnknownRoleProcedureReferenceRecords)[i][j]; }
