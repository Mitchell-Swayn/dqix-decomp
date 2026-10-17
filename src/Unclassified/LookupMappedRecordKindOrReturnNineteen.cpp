#include <globaldefs.h>
struct RecordKind { unsigned unknown0[2]; unsigned kind:4; unsigned variant:5; unsigned rest:23; };
extern "C" short data_020ee7c8[],data_020ee798[];
// Original: arm9/main @ 0x020DEE58; symbol: func_020dee58; size: 0x60.
extern "C" int LookupMappedRecordKindOrReturnNineteen(RecordKind* record)
{
    if(!record)return 19;
    short current;
    short key=record->variant;
    unsigned kind=record->kind;
    short* table=data_020ee7c8;
    if(kind){key=(short)kind;table=data_020ee798;}
    while((current=*table)>=0){if(current==key)return table[1];table+=2;}
    return 19;
}
