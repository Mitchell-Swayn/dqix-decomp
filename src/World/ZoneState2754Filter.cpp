#include "World/Zone3DEmbeddedState.h"

// Selector meanings and packed filter-category semantics remain unresolved.
typedef bool (*RecordMatchFunction)(ZoneSerializedRecord*, int, int, int);
extern "C" void func_020de3f4(int, unsigned int, int, int, signed char*, signed char*, signed char*, RecordMatchFunction*);

short ZoneState2754::Data::GetRecordCountBound()
{
    int count = primaryCount;
    int other = unknownCount4;
    return count > other ? count : other;
}

ZoneSerializedRecord* ZoneState2754::Data::GetRecordAtIndex(int index)
{
    int count = GetRecordCountBound();
    if (index < 0 || index >= count) return 0;
    return (ZoneSerializedRecord*)(records + index * 32);
}

short ZoneState2754::Data::CountMatchingRecords(int alternate, unsigned int kind, int first, signed char second)
{
    RecordMatchFunction match;
    signed char a = -1, b = -1, c = -1;
    match = 0;
    func_020de3f4(alternate, kind, first, second, &a, &b, &c, &match);
    if (!match) return 0;
    int count;
    short result = 0;
    count = primaryCount;
    ZoneSerializedRecord* record = (ZoneSerializedRecord*)records;
    for (int i = 0; i < count; ++i, ++record)
    {
        if ((unsigned short)record->filter.category && match(record, a, b, c)) ++result;
    }
    return result;
}

ZoneSerializedRecord* ZoneState2754::Data::FindMatchingRecord(int index, int alternate, unsigned int kind, signed char first, signed char second)
{
    RecordMatchFunction match;
    signed char a = -1, b = -1, c = -1;
    match = 0;
    func_020de3f4(alternate, kind, first, second, &a, &b, &c, &match);
    if (!match) return 0;
    int count;
    short result = 0;
    count = primaryCount;
    ZoneSerializedRecord* record = (ZoneSerializedRecord*)records;
    for (int i = 0; i < count; ++i, ++record)
    {
        if ((unsigned short)record->filter.category && match(record, a, b, c))
        {
            if (result == index) return record;
            ++result;
        }
    }
    return 0;
}
