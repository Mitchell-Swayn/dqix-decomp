#include "World/WorldPlacementSource.h"
#include "std_library_functions.h"

extern "C" {
    int func_02001aec(const void*, const void*, unsigned int);
    extern const char data_020f12b8[];
}

bool WorldPlacementSource::IsMapEligible(const char* name)
{
    if (name[0] == 'F' && strlen(name) <= 3) return true;
    return !func_02001aec(name, data_020f12b8, 6);
}

WorldPlacementSource::WorldPlacementSource() { Reset(); }
