#include "World/Zone3DEmbeddedState.h"

extern const int gZoneEntryKindThresholds[11];
extern const int gZoneEntryRemainderValues[12];

// Original: arm9/main @ 0x02098284; symbol: _ZN13ZoneState084023GetMappedValueRemainderEi; size: 0x20.
int ZoneState0840::GetMappedValueRemainder(int value)
{
    return gZoneEntryRemainderValues[value % 100];
}

// Original: arm9/main @ 0x020982A4; symbol: _ZN13ZoneState084016GetKindThresholdEi; size: 0x10.
int ZoneState0840::GetKindThreshold(int kind)
{
    return gZoneEntryKindThresholds[kind];
}
