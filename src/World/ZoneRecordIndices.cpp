#include "World/ZoneRecordIndices.h"
extern const signed char gExceptionalZoneRecordIndices[];
extern const short gExceptionalZoneRecordIDs[];
extern const signed char gOutdoorZoneRecordRemap[];

// Original: arm9/main @ 0x02012F24; symbol: _Z29GetExceptionalZoneRecordIndexi; size: 0x44.
int GetExceptionalZoneRecordIndex(int zoneID)
{
    const short* id = gExceptionalZoneRecordIDs;
    const signed char* index = gExceptionalZoneRecordIndices;
    for (unsigned int i = 0; i < 1; ++i, ++id, ++index)
        if (*id == zoneID) return *index;
    return -1;
}

// Original: arm9/main @ 0x02012F68; symbol: _Z25GetOutdoorZoneRecordIndexi; size: 0x3C.
int GetOutdoorZoneRecordIndex(int zoneID)
{
    int index = zoneID - 20000;
    if (index < 0) return -1;
    if (index >= 60 && index <= 63) index = gOutdoorZoneRecordRemap[index - 60];
    if (index >= 60) return -1;
    return index;
}
