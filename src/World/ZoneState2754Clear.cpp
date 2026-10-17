#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"

// Original: arm9/main @ 0x020DE868; symbol: _ZN13ZoneState27545ClearEv; size: 0x20.
void ZoneState2754::Clear()
{
    memset(&data, 0, sizeof(data));
    unknown_14 = 0;
}
