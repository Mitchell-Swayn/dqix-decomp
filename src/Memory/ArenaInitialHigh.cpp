#include "Memory/Arena.h"
#include "System/ConsoleType.h"

// These are absolute linker values, not objects to dereference. Keeping the
// link-time values symbolic preserves the SDK's stack-bound calculation.
// USA values (0 and 0x400) are recorded in config/usa/arm9/linker_symbols.json.
// Refer directly to the system-stack symbol: caching it in a local changes
// MWCC register allocation.
extern char SDK_SYS_STACKSIZE[];
extern char SDK_IRQ_STACKSIZE[];
// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern char Entry_UnknownRoleProcedureReferenceRecords[];

// USA: 0x020c8548
// Original: arm9/main @ 0x020C8548; symbol: _Z19GetInitialArenaHighi; size: 0xE4.
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
        unsigned int irqStackBottom = (unsigned int)Entry_UnknownRoleProcedureReferenceRecords + 0x3f80 - (unsigned int)SDK_IRQ_STACKSIZE;
        unsigned int systemStackBottom;
        if ((int)SDK_SYS_STACKSIZE == 0)
        {
            systemStackBottom = (unsigned int)Entry_UnknownRoleProcedureReferenceRecords;
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
