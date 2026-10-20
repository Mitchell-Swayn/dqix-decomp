#include <globaldefs.h>
#include "World/ZonePredicates.h"

// usa: func_0201b588
// Original: arm9/main @ 0x0201B588; symbol: _Z12IsGrottoZonei; size: 0x28.
bool IsGrottoZone(int zoneID)
{
    return zoneID >= 40001 && zoneID <= 41505;
}

// usa: func_0201b5b0
// Original: arm9/main @ 0x0201B5B0; symbol: _Z21IsMainGrottoFloorZonei; size: 0x28.
bool IsMainGrottoFloorZone(int zoneID)
{
    // grotto floor n in environ E has id
    // 40000 + 20*E + n (0 <= E <= 4)
    return zoneID >= 40001 && zoneID <= 40096;
}

// usa: func_0201b5d8
// Original: arm9/main @ 0x0201B5D8; symbol: _Z21IsGrottoBossFloorZonei; size: 0x28.
bool IsGrottoBossFloorZone(int zoneID)
{
    return zoneID >= 41101 && zoneID <= 41505;
}
