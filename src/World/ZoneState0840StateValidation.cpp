#include "World/Zone3DEmbeddedState.h"

bool ZoneState0840::IsEntryStateValid(int state)
{
    if (state >= 1 && state <= 63) return true;
    return false;
}
