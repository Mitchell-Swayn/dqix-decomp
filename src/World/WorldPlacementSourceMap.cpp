#include "World/WorldPlacementSource.h"
#include "World/WorldPlacementPaths.h"
#include "std_library_functions.h"

extern "C" {
    int RuntimeMemory_CompareByteRanges(const void*, const void*, unsigned int);
}

// Original: arm9/main @ 0x0208E824; symbol: _ZN20WorldPlacementSource13IsMapEligibleEPKc; size: 0x4C.
bool WorldPlacementSource::IsMapEligible(const char* name)
{
    if (name[0] == 'F' && strlen(name) <= 3) return true;
    return !RuntimeMemory_CompareByteRanges(name, gWorldPlacementPaths.specialMap, 6);
}

// Original: arm9/main @ 0x0208E870; symbol: _ZN20WorldPlacementSourceC1Ev; size: 0x14.
WorldPlacementSource::WorldPlacementSource() { Reset(); }
