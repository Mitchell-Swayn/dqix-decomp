#include "Memory/Arena.h"

// Shared system work area: the low/high bounds each contain nine addresses.
// The ARM9 accesses these at fixed addresses, not through program-owned data.
struct ArenaBounds
{
    void* low[9];
    void* high[9];
};

#define ARENA_BOUNDS (*(ArenaBounds*)0x027ffda0)

// USA: 0x020c86d4
void SetArenaHigh(int arenaId, void* end)
{
    ARENA_BOUNDS.high[arenaId] = end;
}

// USA: 0x020c86e8
void SetArenaLow(int arenaId, void* begin)
{
    ARENA_BOUNDS.low[arenaId] = begin;
}

