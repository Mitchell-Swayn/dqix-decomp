#include "World/Zone3DEmbeddedState.h"

// Original: arm9/main @ 0x020DE38C; symbol: _Z25MatchRecordFirstAttributeP20ZoneSerializedRecordiii; size: 0x20.
bool MatchRecordFirstAttribute(ZoneSerializedRecord* record, int group, int first, int second)
{
    return group == record->attributes.group && first == record->attributes.first;
}

// Original: arm9/main @ 0x020DE3AC; symbol: _Z26MatchRecordSecondAttributeP20ZoneSerializedRecordiii; size: 0x20.
bool MatchRecordSecondAttribute(ZoneSerializedRecord* record, int group, int first, int second)
{
    return group == record->attributes.group && second == record->attributes.second;
}

// Original: arm9/main @ 0x020DE3CC; symbol: _Z25MatchRecordBothAttributesP20ZoneSerializedRecordiii; size: 0x28.
bool MatchRecordBothAttributes(ZoneSerializedRecord* record, int group, int first, int second)
{
    return group == record->attributes.group && first == record->attributes.first && second == record->attributes.second;
}
