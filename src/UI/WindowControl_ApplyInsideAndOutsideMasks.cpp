#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f2be4; symbol: data_020f2be4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 502b0e02282b0e02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2c04; symbol: data_020f2c04.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 002b0e02d82a0e02b02a0e02882a0e02.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
typedef void (*Apply)(unsigned,unsigned);extern "C" Apply WindowControlApplyInsideAndOutsideMasks_UnknownRoleProcedureReferenceRecords_Variant2[][2];extern "C" Apply WindowControlApplyInsideAndOutsideMasks_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020E2C7C; symbol: func_020e2c7c; size: 0x48.
extern "C" void WindowControl_ApplyInsideAndOutsideMasks(unsigned char* p){WindowControlApplyInsideAndOutsideMasks_UnknownRoleProcedureReferenceRecords_Variant2[p[1]][p[2]](*(unsigned*)(p+4),*(unsigned*)(p+8));WindowControlApplyInsideAndOutsideMasks_UnknownRoleProcedureReferenceRecords[p[1]](*(unsigned*)(p+12),*(unsigned*)(p+16));}
