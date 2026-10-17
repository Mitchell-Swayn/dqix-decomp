#include <globaldefs.h>
ARM
extern "C" void *_Z16GetCombatantByIDii(int id, int category);
// Original: arm9/ov024 @ 0x021E57C0; symbol: func_ov024_021e57c0; size: 0x20.
extern "C" void Combat_SetCombatantNestedFlag21ByID(void *object, int category) {
    void *combatant = _Z16GetCombatantByIDii(*(int *)((unsigned char *)object + 0x10), category);
    if (combatant != 0)
        *(unsigned char *)(*(unsigned char **)((unsigned char *)combatant + 0x138) + 0x21) = 1;
}
