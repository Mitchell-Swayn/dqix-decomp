#include "Memory/Arena.h"
#include "System/ConsoleType.h"

extern "C"
{
    void OS_SetProtectionRegion1(unsigned int region);
    void OS_SetProtectionRegion2(unsigned int region);
}

// USA: 0x020c84b4
// Original: arm9/main @ 0x020C84B4; symbol: _Z23InitializeExtendedArenav; size: 0x6C.
void InitializeExtendedArena()
{
    SetArenaHigh(2, GetInitialArenaHigh(2));
    SetArenaLow(2, GetInitialArenaLow(2));
    if (g_arenaInitializationState.extendedMemoryEnabled != 0 &&
        (GetConsoleType() & 3) != 1)
        return;
    // MPU region descriptors for normal RAM and its reserved upper region.
    OS_SetProtectionRegion1(0x0200002b);
    OS_SetProtectionRegion2(0x023e0021);
}
