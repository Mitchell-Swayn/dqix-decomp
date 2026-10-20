#include <globaldefs.h>
ARM
extern "C" void *_Z16GetCombatantByIDii(int unused, int id);
// Original: arm9/ov024 @ 0x021EE33C; symbol: func_ov024_021ee33c; size: 0x3C.
extern "C" int Combat_ClearSelectionWhenHpAtMostHalf(const int *unusedId, int id, void *unused, unsigned *output) {
    void *combatant = _Z16GetCombatantByIDii(*unusedId, id);
    if (!combatant) return 0;
    volatile unsigned char *values = *(unsigned char **)((char *)combatant + 0x138);
    unsigned short threshold = *(volatile unsigned short *)values;
    unsigned short current = *(volatile unsigned short *)(values + 4);
    if (current >= threshold * 2) {
        *output = 0;
        return 1;
    }
    return 0;
}
