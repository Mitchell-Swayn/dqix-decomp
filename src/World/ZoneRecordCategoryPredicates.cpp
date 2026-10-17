#include "World/Zone3DEmbeddedState.h"

// Original: arm9/main @ 0x020DE31C; symbol: _Z19MatchRecordCategoryP20ZoneSerializedRecordiii; size: 0x18.
bool MatchRecordCategory(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    return minimum == record->category.category;
}

// Original: arm9/main @ 0x020DE334; symbol: _Z18MatchRecordSubtypeP20ZoneSerializedRecordiii; size: 0x18.
bool MatchRecordSubtype(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    return subtype == record->category.subtype;
}

// Original: arm9/main @ 0x020DE34C; symbol: _Z24MatchRecordCategoryRangeP20ZoneSerializedRecordiii; size: 0x20.
bool MatchRecordCategoryRange(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    bool result = false;
    int category = record->category.category;
    if (minimum <= category && category <= maximum) result = true;
    return result;
}

// Original: arm9/main @ 0x020DE36C; symbol: _Z29MatchRecordCategoryAndSubtypeP20ZoneSerializedRecordiii; size: 0x20.
bool MatchRecordCategoryAndSubtype(ZoneSerializedRecord* record, int minimum, int maximum, int subtype)
{
    return minimum == record->category.category && subtype == record->category.subtype;
}
