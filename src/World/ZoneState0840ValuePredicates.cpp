#include "World/Zone3DEmbeddedState.h"

// Numeric classification boundaries are known; gameplay meaning is unresolved.
bool ZoneState0840::IsValueInRangeC3b5(int value)
{
    if (value >= 0xc3b5 && value <= 0xc55b) return true;
    return false;
}

bool ZoneState0840::IsValueAtHundredBoundary(int value)
{
    return value == 0xc3b5 || value == 0xc419 || value == 0xc47d || value == 0xc4e1;
}

bool ZoneState0840::IsValueInRangeC545(int value)
{
    if (value >= 0xc545 && value <= 0xc55b) return true;
    return false;
}
