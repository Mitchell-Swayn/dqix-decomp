#include <globaldefs.h>
struct RecordKind { unsigned unknown0[2]; unsigned kind:4; unsigned variant:5; unsigned rest:23; };
// Original data: arm9/main @ 0x20ee798; symbol: data_020ee798.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000c0002000d0003000e0004000f0005001000060011000700120008001300090013000a0013000b001300ffff1300.
// Observed span: 48 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20ee7c8; symbol: data_020ee7c8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000100010002000200030003000400040005000500060006000700070008000800090009000a000a000b000b00ffff000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" short ZoneSerializedRecordGetKindIconIndex_UnknownRoleInitializedBytes_Variant2[],ZoneSerializedRecordGetKindIconIndex_UnknownRoleInitializedBytes[];
// Original: arm9/main @ 0x020DEE58; symbol: func_020dee58; size: 0x60.
extern "C" int ZoneSerializedRecord_GetKindIconIndex(RecordKind* record)
{
    if(!record)return 19;
    short current;
    short key=record->variant;
    unsigned kind=record->kind;
    short* table=ZoneSerializedRecordGetKindIconIndex_UnknownRoleInitializedBytes_Variant2;
    if(kind){key=(short)kind;table=ZoneSerializedRecordGetKindIconIndex_UnknownRoleInitializedBytes;}
    while((current=*table)>=0){if(current==key)return table[1];table+=2;}
    return 19;
}
