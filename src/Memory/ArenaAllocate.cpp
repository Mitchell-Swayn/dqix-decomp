#include "Memory/Arena.h"

// Kept separate from the setters: compiling together makes MWCC inline
// SetArenaLow, while the original contains a call.

// USA: 0x020c86fc
void* AllocateArenaLow(int arenaId, unsigned int size, unsigned int alignment)
{
    unsigned int low = (unsigned int)GetArenaLow(arenaId);
    if (low == 0)
        return 0;
    unsigned int alignedLow = (low + alignment - 1) & ~(alignment - 1);
    unsigned int newLow = alignedLow + size;
    newLow = (newLow + alignment - 1) & ~(alignment - 1);
    if (newLow > (unsigned int)GetArenaHigh(arenaId))
        return 0;
    SetArenaLow(arenaId, (void*)newLow);
    return (void*)alignedLow;
}
