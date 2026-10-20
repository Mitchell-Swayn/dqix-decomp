#include <globaldefs.h>
// Original data: arm9/main @ 0x20f2bdc; symbol: data_020f2bdc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c42b0e02ac2b0e02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20f2bec; symbol: data_020f2bec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 942b0e02782b0e02.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
typedef unsigned(*Getter)();typedef void(*Setter)(unsigned);extern "C" Getter WindowControlSetEnabled_UnknownRoleProcedureReferenceRecords[];extern "C" Setter WindowControlSetEnabled_UnknownRoleProcedureReferenceRecords_Variant2[];
struct Flag {unsigned char value,bank,bit;};
// Original: arm9/main @ 0x020E2CC4; symbol: func_020e2cc4; size: 0x60.
extern "C" ARM void WindowControl_SetEnabled(Flag* p,unsigned value){if(p->value==value)return;p->value=value;unsigned word=WindowControlSetEnabled_UnknownRoleProcedureReferenceRecords[p->bank]();if(value)word|=1<<p->bit;else word&=~(1<<p->bit);WindowControlSetEnabled_UnknownRoleProcedureReferenceRecords_Variant2[p->bank](word);}
