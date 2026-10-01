#include "Memory/Arena.h"

ArenaInitializationState g_arenaInitializationState;

extern "C"
{
    void* func_020c8548(int arenaId);
}

// USA: 0x020c83b0
void InitializeArenas()
{
    if (g_arenaInitializationState.initialized != 0)
        return;
    g_arenaInitializationState.initialized = 1;
    SetArenaHigh(0, func_020c8548(0));
    SetArenaLow(0, GetInitialArenaLow(0));
    SetArenaLow(2, 0);
    SetArenaHigh(2, 0);
    SetArenaHigh(3, func_020c8548(3));
    SetArenaLow(3, GetInitialArenaLow(3));
    SetArenaHigh(4, func_020c8548(4));
    SetArenaLow(4, GetInitialArenaLow(4));
    SetArenaHigh(5, func_020c8548(5));
    SetArenaLow(5, GetInitialArenaLow(5));
    SetArenaHigh(6, func_020c8548(6));
    SetArenaLow(6, GetInitialArenaLow(6));
}
