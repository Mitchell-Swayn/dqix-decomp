#include "World/WorldPlacementSource.h"
#include "World/WorldPlacementPaths.h"
#include "std_library_functions.h"

extern "C" {
    int func_02001aec(const void*, const void*, unsigned int);
}

bool WorldPlacementSource::IsMapEligible(const char* name)
{
    if (name[0] == 'F' && strlen(name) <= 3) return true;
    return !func_02001aec(name, gWorldPlacementPaths.specialMap, 6);
}

WorldPlacementSource::WorldPlacementSource() { Reset(); }
