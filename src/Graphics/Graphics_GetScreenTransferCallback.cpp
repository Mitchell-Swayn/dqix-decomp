#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f0218; symbol: data_020f0218.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex d85a0c02985b0c02585c0c02185d0c02385b0c02f85b0c02b85c0c02785d0c02.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char GraphicsTransferScreenBuffer_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x0204A5F8; symbol: func_0204a5f8; size: 0x14.
extern "C" unsigned int Graphics_GetScreenTransferCallback(unsigned int i,unsigned int j) { return ((unsigned int(*)[4])GraphicsTransferScreenBuffer_UnknownRoleProcedureReferenceRecords)[i][j]; }
