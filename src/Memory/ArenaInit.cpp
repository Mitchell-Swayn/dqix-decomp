#include "Memory/Arena.h"

ArenaInitializationState g_arenaInitializationState;

// USA: 0x020c83b0
void InitializeArenas()
{
    if (g_arenaInitializationState.initialized != 0)
        return;
    g_arenaInitializationState.initialized = 1;
    SetArenaHigh(0, GetInitialArenaHigh(0));
    SetArenaLow(0, GetInitialArenaLow(0));
    SetArenaLow(2, 0);
    SetArenaHigh(2, 0);
    SetArenaHigh(3, GetInitialArenaHigh(3));
    SetArenaLow(3, GetInitialArenaLow(3));
    SetArenaHigh(4, GetInitialArenaHigh(4));
    SetArenaLow(4, GetInitialArenaLow(4));
    SetArenaHigh(5, GetInitialArenaHigh(5));
    SetArenaLow(5, GetInitialArenaLow(5));
    SetArenaHigh(6, GetInitialArenaHigh(6));
    SetArenaLow(6, GetInitialArenaLow(6));
}
