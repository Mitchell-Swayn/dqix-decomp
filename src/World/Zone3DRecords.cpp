#include "World/Zone3D.h"
#include "World/ZoneRecordIndices.h"
#include "World/ZonePredicates.h"

extern "C" void* Object_GetGlobalConnectionState();
extern "C" bool TestActiveWordAndGlobalStateNonzero(void*);
extern "C" char* ReadGlobalValueAt02108844();
extern "C" void BitArray_SetIndexedBoolean(void*, void*, int, int);
extern "C" int ReadNonnegativeIndexedBit(void*, void*, int);

// These numeric record IDs and their backing store are still only partially
// understood. Preserve the asymmetric grotto and fallback cases below.
// Original: arm9/main @ 0x0201BA68; symbol: _ZN6Zone3D21RecordCurrentZoneFlagEv; size: 0x110.
void Zone3D::RecordCurrentZoneFlag()
{
    if (TestActiveWordAndGlobalStateNonzero(Object_GetGlobalConnectionState()) || unknown_2820_) return;
    char* state = ReadGlobalValueAt02108844();
    int zoneID = currentZoneID_;
    if ((unsigned int)zoneID >= 20000 && (unsigned int)zoneID <= 29999)
    {
        int index = GetOutdoorZoneRecordIndex(zoneID);
        if (index < 0) return;
        BitArray_SetIndexedBoolean(state, state + 0x8c, index + 0xa5a, 1);
        return;
    }
    if ((unsigned int)zoneID >= 100 && (unsigned int)zoneID <= 9999)
    {
        int index = zoneID / 100;
        if (index >= 100) return;
        BitArray_SetIndexedBoolean(state, state + 0x8c, index + 0xa96, 1);
        return;
    }
    if (IsGrottoZone(zoneID))
    {
        BitArray_SetIndexedBoolean(state, state + 0x8c, 0x79d, 1);
        return;
    }
    int index = GetExceptionalZoneRecordIndex(currentZoneID_);
    if (index < 0) return;
    BitArray_SetIndexedBoolean(state, state + 0x8c, index + 0xa5a, 1);
}

// Original: arm9/main @ 0x0201BB78; symbol: _ZN6Zone3D17GetZoneRecordFlagEi; size: 0x104.
int Zone3D::GetZoneRecordFlag(int zoneID)
{
    char* state = ReadGlobalValueAt02108844();
    int result = 0;
    if ((unsigned int)zoneID >= 20000 && (unsigned int)zoneID <= 29999)
    {
        int index = GetOutdoorZoneRecordIndex(zoneID);
        if (index >= 0) result = ReadNonnegativeIndexedBit(state, state + 0x8c, index + 0xa5a);
    }
    else if ((unsigned int)zoneID >= 100 && (unsigned int)zoneID <= 9999)
    {
        int index = zoneID / 100;
        if (index < 100) result = ReadNonnegativeIndexedBit(state, state + 0x8c, index + 0xa96);
    }
    else if (zoneID == 10000)
        result = ReadNonnegativeIndexedBit(state, state + 0x8c, 0x2b);
    else
    {
        int index = GetExceptionalZoneRecordIndex(currentZoneID_);
        if (index >= 0) result = ReadNonnegativeIndexedBit(state, state + 0x8c, index + 0xa5a);
    }
    return result;
}
