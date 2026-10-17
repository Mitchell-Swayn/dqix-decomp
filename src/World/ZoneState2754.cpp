#include "World/Zone3DEmbeddedState.h"
#include "std_library_functions.h"
// Original: arm9/main @ 0x020DE824; symbol: _ZN13ZoneState2754C1Ev; size: 0x24.
ZoneState2754::ZoneState2754()
{
    memset(&data, 0, sizeof(data));
    unknown_14 = 0;
}
// Original: arm9/main @ 0x020DE848; symbol: _ZN13ZoneState27545ResetEv; size: 0x20.
void ZoneState2754::Reset()
{
    memset(&data, 0, sizeof(data));
    unknown_14 = 0;
}
