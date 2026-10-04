#include "World/Zone3DEmbeddedState.h"

bool MatchRecordFirstAttribute(ZoneSerializedRecord* record, int group, int first, int second)
{
    return group == record->attributes.group && first == record->attributes.first;
}

bool MatchRecordSecondAttribute(ZoneSerializedRecord* record, int group, int first, int second)
{
    return group == record->attributes.group && second == record->attributes.second;
}

bool MatchRecordBothAttributes(ZoneSerializedRecord* record, int group, int first, int second)
{
    return group == record->attributes.group && first == record->attributes.first && second == record->attributes.second;
}
