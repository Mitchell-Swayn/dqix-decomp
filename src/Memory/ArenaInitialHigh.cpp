#include "Memory/Arena.h"
#include "System/ConsoleType.h"

// These are absolute linker values, not objects to dereference. Keeping the
// link-time values symbolic preserves the SDK's stack-bound calculation.
// USA values (0 and 0x400) are recorded in config/usa/arm9/linker_symbols.json.
// Refer directly to the system-stack symbol: caching it in a local changes
// MWCC register allocation.
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
extern char data_027e0000[];

// USA: 0x020c8548
void* GetInitialArenaHigh(int arenaId)
{
    switch (arenaId)
    {
    case 0: return (void*)0x023e0000;
    case 2:
        if (g_arenaInitializationState.extendedMemoryEnabled == 0 ||
            (GetConsoleType() & 3) == 1)
            return 0;
        return (void*)0x02700000;
    case 3: return (void*)0x02000000;
    case 4:
    {
        unsigned int irqStackBottom = (unsigned int)data_027e0000 + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE;
        unsigned int systemStackBottom;
        if ((int)SDK_SYS_STACKSIZE == 0)
        {
            systemStackBottom = (unsigned int)data_027e0000;
            if (systemStackBottom < 0x027e0080)
                systemStackBottom = 0x027e0080;
        }
        else if ((int)SDK_SYS_STACKSIZE < 0)
            systemStackBottom = 0x027e0080 - (int)SDK_SYS_STACKSIZE;
        else
            systemStackBottom = irqStackBottom - (int)SDK_SYS_STACKSIZE;
        return (void*)systemStackBottom;
    }
    case 5: return (void*)0x027ff680;
    case 6: return (void*)0x037f8000;
    default: return 0;
    }
}
