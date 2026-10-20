#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f2adc; symbol: data_020f2adc.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 54e10d025ce10d0268e10d0274e10d0284e10d02.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
typedef unsigned (*Convert)(unsigned);extern "C" Convert ZoneSerializedRecordResolveEncodedValue_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x020DE194; symbol: func_020de194; size: 0x40.
extern "C" unsigned ZoneSerializedRecord_ResolveEncodedValue(unsigned short* p){unsigned value=p[14];if(value>=0xfffb)value=ZoneSerializedRecordResolveEncodedValue_UnknownRoleProcedureReferenceRecords[0xffff-value](p[13]);return value;}
