#pragma once

void* GetArenaHigh(int arenaId);
void* GetArenaLow(int arenaId);
void SetArenaHigh(int arenaId, void* end);
void SetArenaLow(int arenaId, void* begin);
// Alignment must be a power of two. Both the returned address and the new
// low bound are rounded up, leaving the high bound unchanged.
void* AllocateArenaLow(int arenaId, unsigned int size, unsigned int alignment);

struct ArenaInitializationState
{
    int initialized;
    int extendedMemoryEnabled;
};
extern ArenaInitializationState g_arenaInitializationState;
void InitializeArenas();

void* GetInitialArenaLow(int arenaId);
void InitializeExtendedArena();
