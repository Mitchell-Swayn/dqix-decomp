#include "Memory/Arena.h"

// Shared system work area: the low/high bounds each contain nine addresses.
// The ARM9 accesses these at fixed addresses, not through program-owned data.
struct ArenaBounds
{
    void* low[9];
    void* high[9];
};

#define ARENA_BOUNDS (*(ArenaBounds*)0x027ffda0)

// USA: 0x020c8520
void* GetArenaHigh(int arenaId)
{
    return ARENA_BOUNDS.high[arenaId];
}

// USA: 0x020c8534
void* GetArenaLow(int arenaId)
{
    return ARENA_BOUNDS.low[arenaId];
}

