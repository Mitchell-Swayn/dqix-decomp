#include "World/Zone3DEmbeddedState.h"

extern const int gZoneEntryKindThresholds[11];
extern const int gZoneEntryRemainderValues[12];

int ZoneState0840::GetMappedValueRemainder(int value)
{
    return gZoneEntryRemainderValues[value % 100];
}

int ZoneState0840::GetKindThreshold(int kind)
{
    return gZoneEntryKindThresholds[kind];
}
