#include "World/Zone3DEmbeddedState.h"

bool MatchRecordCategory(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    return minimum == record->category.category;
}

bool MatchRecordSubtype(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    return subtype == record->category.subtype;
}

bool MatchRecordCategoryRange(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    bool result = false;
    int category = record->category.category;
    if (minimum <= category && category <= maximum) result = true;
    return result;
}

bool MatchRecordCategoryAndSubtype(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    return minimum == record->category.category && subtype == record->category.subtype;
}
