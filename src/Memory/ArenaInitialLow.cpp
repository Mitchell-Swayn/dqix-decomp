#include "Memory/Arena.h"

extern "C" unsigned int func_020c7dcc();

// USA: 0x020c862c
// Bounds are those of the original linked USA image. Arena 1 belongs to ARM7;
// arena 2 is only exposed when extended memory is enabled and available.
void* GetInitialArenaLow(int arenaId)
{
    switch (arenaId)
    {
    case 0: return (void*)0x022a3200;
    case 2:
        if (g_arenaInitializationState.extendedMemoryEnabled == 0 ||
            (func_020c7dcc() & 3) == 1)
            return 0;
        return (void*)0x023e0000;
    case 3: return (void*)0x01fff280;
    case 4: return (void*)0x027e0080;
    case 5: return (void*)0x027ff000;
    case 6: return (void*)0x037f8000;
    default: return 0;
    }
}
