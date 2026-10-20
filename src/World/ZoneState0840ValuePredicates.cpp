#include "World/Zone3DEmbeddedState.h"

// Numeric classification boundaries are known; gameplay meaning is unresolved.
// Original: arm9/main @ 0x020981E4; symbol: _ZN13ZoneState084018IsValueInRangeC3b5Ei; size: 0x2C.
bool ZoneState0840::IsValueInRangeC3b5(int value)
{
    if (value >= 0xc3b5 && value <= 0xc55b) return true;
    return false;
}

// Original: arm9/main @ 0x02098210; symbol: _ZN13ZoneState084024IsValueAtHundredBoundaryEi; size: 0x30.
bool ZoneState0840::IsValueAtHundredBoundary(int value)
{
    return value == 0xc3b5 || value == 0xc419 || value == 0xc47d || value == 0xc4e1;
}

// Original: arm9/main @ 0x02098240; symbol: _ZN13ZoneState084018IsValueInRangeC545Ei; size: 0x28.
bool ZoneState0840::IsValueInRangeC545(int value)
{
    if (value >= 0xc545 && value <= 0xc55b) return true;
    return false;
}
