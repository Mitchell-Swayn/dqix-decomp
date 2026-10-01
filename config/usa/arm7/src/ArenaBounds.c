/* Shared arena boundary arrays. Arena identifiers are passed through unchanged;
 * this layer intentionally performs no bounds check, matching the original.
 * Initial-boundary selection remains an explicitly linked binary dependency. */
extern void *ARM7_GetInitialArenaLow(int arena);
extern void *ARM7_GetInitialArenaHigh(int arena);

void ARM7_InitializeArena(int arena) {
    ((void *volatile *)0x027ffdc4)[arena] = ARM7_GetInitialArenaLow(arena);
    ((void *volatile *)0x027ffda0)[arena] = ARM7_GetInitialArenaHigh(arena);
}

void *ARM7_GetArenaLow(int arena) {
    return ((void *volatile *)0x027ffdc4)[arena];
}

void *ARM7_GetArenaHigh(int arena) {
    return ((void *volatile *)0x027ffda0)[arena];
}
