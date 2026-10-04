#include "World/Zone3DEmbeddedState.h"

ZoneSerializedRecord* ZoneState2754::Data::FindByAttributes(int group, int first, int second)
{
    ZoneRecordMatchFunction match = 0;
    SelectRecordAttributeMatcher(first, second, &match);
    if (!match) return 0;
    int count = primaryCount;
    ZoneSerializedRecord* record = (ZoneSerializedRecord*)records;
    for (int i = 0; i < count; ++i, ++record)
        if (match(record, group, first, second)) return record;
    return 0;
}

ZoneSerializedRecord* ZoneState2754::Data::FindRelatedRecord(int group, const ZoneSerializedRecord* record)
{
    if (!record) return 0;
    return FindByAttributes(group, record->attributes.first, record->attributes.second);
}
