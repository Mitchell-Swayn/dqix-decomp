#pragma always_inline on
#pragma optimize_for_size on
#pragma opt_unroll_loops off
#include <globaldefs.h>
struct PointRecord { short x, y; unsigned short values[18]; unsigned short tail; unsigned char a,b; };
struct PointRecords { PointRecord* entries; short capacity,count; };
// Original: arm9/main @ 0x02072560; symbol: func_02072560; size: 0x78.
extern "C" void AppendPointRecordWithinCapacity(PointRecords* list, const PointRecord* source) {
    if (list->capacity <= list->count) return;
    PointRecord* dest = list->entries + list->count;
    *dest = *source;
    list->count++;
}
