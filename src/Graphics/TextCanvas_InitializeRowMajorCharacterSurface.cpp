#include <globaldefs.h>
// Original data: arm9/main @ 0x20e91c8; symbol: data_020e91c8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 40150b02e8180b02b8190b02.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextCanvasInitializeRowMajorCharacterSurface_UnknownRoleProcedureReferenceRecords[];extern "C" void TextCanvas_InitializeCharacterSurface(unsigned,unsigned,unsigned,unsigned,unsigned,void*,unsigned);
// Original: arm9/main @ 0x020B1E94; symbol: func_020b1e94; size: 0x2C.
extern "C" ARM void TextCanvas_InitializeRowMajorCharacterSurface(unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){TextCanvas_InitializeCharacterSurface(a,b,c,d,e,TextCanvasInitializeRowMajorCharacterSurface_UnknownRoleProcedureReferenceRecords,c);}
