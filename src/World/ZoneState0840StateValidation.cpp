#include "World/Zone3DEmbeddedState.h"

// Original: arm9/main @ 0x02098268; symbol: _ZN13ZoneState084017IsEntryStateValidEi; size: 0x1C.
bool ZoneState0840::IsEntryStateValid(int state)
{
    if (state >= 1 && state <= 63) return true;
    return false;
}
