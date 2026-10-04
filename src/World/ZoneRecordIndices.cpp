#include "World/ZoneRecordIndices.h"
extern const signed char gExceptionalZoneRecordIndices[];
extern const short gExceptionalZoneRecordIDs[];
extern const signed char gOutdoorZoneRecordRemap[];

int GetExceptionalZoneRecordIndex(int zoneID)
{
    const short* id = gExceptionalZoneRecordIDs;
    const signed char* index = gExceptionalZoneRecordIndices;
    for (unsigned int i = 0; i < 1; ++i, ++id, ++index)
        if (*id == zoneID) return *index;
    return -1;
}

int GetOutdoorZoneRecordIndex(int zoneID)
{
    int index = zoneID - 20000;
    if (index < 0) return -1;
    if (index >= 60 && index <= 63) index = gOutdoorZoneRecordRemap[index - 60];
    if (index >= 60) return -1;
    return index;
}
