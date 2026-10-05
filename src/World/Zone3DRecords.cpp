#include "World/Zone3D.h"
#include "World/ZoneRecordIndices.h"
#include "World/ZonePredicates.h"

extern "C" void* func_0202ae18();
extern "C" bool func_0202c540(void*);
extern "C" char* func_0205ec34();
extern "C" void func_0206df6c(void*, void*, int, int);
extern "C" int func_0206dfb0(void*, void*, int);

// These numeric record IDs and their backing store are still only partially
// understood. Preserve the asymmetric grotto and fallback cases below.
void Zone3D::RecordCurrentZoneFlag()
{
    if (func_0202c540(func_0202ae18()) || unknown_2820_) return;
    char* state = func_0205ec34();
    int zoneID = currentZoneID_;
    if ((unsigned int)zoneID >= 20000 && (unsigned int)zoneID <= 29999)
    {
        int index = GetOutdoorZoneRecordIndex(zoneID);
        if (index < 0) return;
        func_0206df6c(state, state + 0x8c, index + 0xa5a, 1);
        return;
    }
    if ((unsigned int)zoneID >= 100 && (unsigned int)zoneID <= 9999)
    {
        int index = zoneID / 100;
        if (index >= 100) return;
        func_0206df6c(state, state + 0x8c, index + 0xa96, 1);
        return;
    }
    if (IsGrottoZone(zoneID))
    {
        func_0206df6c(state, state + 0x8c, 0x79d, 1);
        return;
    }
    int index = GetExceptionalZoneRecordIndex(currentZoneID_);
    if (index < 0) return;
    func_0206df6c(state, state + 0x8c, index + 0xa5a, 1);
}

int Zone3D::GetZoneRecordFlag(int zoneID)
{
    char* state = func_0205ec34();
    int result = 0;
    if ((unsigned int)zoneID >= 20000 && (unsigned int)zoneID <= 29999)
    {
        int index = GetOutdoorZoneRecordIndex(zoneID);
        if (index >= 0) result = func_0206dfb0(state, state + 0x8c, index + 0xa5a);
    }
    else if ((unsigned int)zoneID >= 100 && (unsigned int)zoneID <= 9999)
    {
        int index = zoneID / 100;
        if (index < 100) result = func_0206dfb0(state, state + 0x8c, index + 0xa96);
    }
    else if (zoneID == 10000)
        result = func_0206dfb0(state, state + 0x8c, 0x2b);
    else
    {
        int index = GetExceptionalZoneRecordIndex(currentZoneID_);
        if (index >= 0) result = func_0206dfb0(state, state + 0x8c, index + 0xa5a);
    }
    return result;
}
