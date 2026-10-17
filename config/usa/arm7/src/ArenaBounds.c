/* Shared arena boundary arrays. Arena identifiers are passed through unchanged;
 * this layer intentionally performs no bounds check, matching the original.
 * These absolute linker symbols describe layout, not byte arrays to dereference.
 * The stack-size symbols are signed: a negative system-stack size reserves
 * space upward from the WRAM arena's lower bound. */
extern char ARM7_IrqStackSize[];
extern char ARM7_SystemStackSize[];
extern char ARM7_WramBssEnd[];
extern char ARM7_MainRamBssEnd[];

extern void *ARM7_GetInitialArenaLow(int arena);
extern void *ARM7_GetInitialArenaHigh(int arena);

// Original: arm7/wram @ 0x037FCE88; symbol: ARM7_InitializeArena.
void ARM7_InitializeArena(int arena) {
    ((void *volatile *)0x027ffdc4)[arena] = ARM7_GetInitialArenaHigh(arena);
    ((void *volatile *)0x027ffda0)[arena] = ARM7_GetInitialArenaLow(arena);
}

// Original: arm7/wram @ 0x037FCEC4; symbol: ARM7_GetArenaHigh.
void *ARM7_GetArenaHigh(int arena) {
    return ((void *volatile *)0x027ffdc4)[arena];
}

// Original: arm7/wram @ 0x037FCED8; symbol: ARM7_GetArenaLow.
void *ARM7_GetArenaLow(int arena) {
    return ((void *volatile *)0x027ffda0)[arena];
}

// Original: arm7/wram @ 0x037FCEEC; symbol: ARM7_GetInitialArenaHigh.
void *ARM7_GetInitialArenaHigh(int arena) {
    switch (arena) {
    case 1:
        return (void *)0x027ff000;
    case 7:
        return (void *)0x03800000;
    case 8: {
        unsigned int stackTop = 0x0380ff80 - (unsigned int)ARM7_IrqStackSize;
        unsigned int start = 0x03800000;
        if ((unsigned int)ARM7_WramBssEnd > start) {
            start = (unsigned int)ARM7_WramBssEnd;
        }
        if ((int)ARM7_SystemStackSize == 0) {
            return (void *)start;
        }
        if ((int)ARM7_SystemStackSize < 0) {
            return (void *)(start - (int)ARM7_SystemStackSize);
        }
        return (void *)(stackTop - (int)ARM7_SystemStackSize);
    }
    default:
        return 0;
    }
}

// Original: arm7/wram @ 0x037FCF68; symbol: ARM7_GetInitialArenaLow.
void *ARM7_GetInitialArenaLow(int arena) {
    switch (arena) {
    case 1:
        return ARM7_MainRamBssEnd;
    case 7:
        return (unsigned int)ARM7_WramBssEnd > 0x03800000
            ? (void *)0x03800000 : ARM7_WramBssEnd;
    case 8: {
        unsigned int start = 0x03800000;
        if ((unsigned int)ARM7_WramBssEnd > start) {
            start = (unsigned int)ARM7_WramBssEnd;
        }
        return (void *)start;
    }
    default:
        return 0;
    }
}

// Original: arm7/wram @ 0x037FCFC0; symbol: ARM7_SetArenaLow.
void ARM7_SetArenaLow(int arena, void *low) {
    ((void *volatile *)0x027ffda0)[arena] = low;
}
