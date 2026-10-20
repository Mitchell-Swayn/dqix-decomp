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
// Original: arm9/main @ 0x020C86D4; symbol: _Z12SetArenaHighiPv; size: 0x14.
void SetArenaHigh(int arenaId, void* end)
{
    ARENA_BOUNDS.high[arenaId] = end;
}

// USA: 0x020c86e8
// Original: arm9/main @ 0x020C86E8; symbol: _Z11SetArenaLowiPv; size: 0x14.
void SetArenaLow(int arenaId, void* begin)
{
    ARENA_BOUNDS.low[arenaId] = begin;
}

