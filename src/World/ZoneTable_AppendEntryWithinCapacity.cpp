#include <globaldefs.h>
#pragma always_inline on
struct ZoneTableAppendEntry {
    unsigned short zoneId;
    unsigned short value_02;
    unsigned char value_04;
    char mapName[7];
    unsigned char value_0c;
    unsigned char flags_0d;
    unsigned char value_0e;

};
struct ZoneTableAppendView {
    ZoneTableAppendEntry* entries;
    int count;
    int capacity;
};
#pragma force_active on
// Original: arm9/main @ 0x020999F0; symbol: func_020999f0; size: 0x78.
// Appends the fifteen meaningful bytes when the table has spare capacity.
extern "C" ARM void ZoneTable_AppendEntryWithinCapacity(ZoneTableAppendView* table, const ZoneTableAppendEntry* source)
{
    if (table->capacity <= table->count) return;
    ZoneTableAppendEntry* output = &table->entries[table->count++];
    *output = *source;
}
#pragma force_active off
