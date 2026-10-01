#include "Memory/Arena.h"
#include "System/ConsoleType.h"

extern "C"
{
    void* func_020c8548(int arenaId);
    void func_020c8a2c(unsigned int region);
    void func_020c8a34(unsigned int region);
}

// USA: 0x020c84b4
void InitializeExtendedArena()
{
    SetArenaHigh(2, func_020c8548(2));
    SetArenaLow(2, GetInitialArenaLow(2));
    if (g_arenaInitializationState.extendedMemoryEnabled != 0 &&
        (GetConsoleType() & 3) != 1)
        return;
    // MPU region descriptors for normal RAM and its reserved upper region.
    func_020c8a2c(0x0200002b);
    func_020c8a34(0x023e0021);
}
