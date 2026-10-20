#include <globaldefs.h>
ARM
// Original: arm9/ov017:021cbe50; Validates the record halfword against nested state +0x8e28, then stores eight record bytes in word slots at state +0x8de0 with four-byte stride.
extern "C" void *FieldBattle_GetCombatContext(void *);
extern "C" void Combat_ApplyEncounterBattleSlotAssignments(void *unused, const unsigned char *record, int unused2, unsigned char *resources) {
    void *value = FieldBattle_GetCombatContext(*(void **)(resources + 0x3718));
    if (value == 0)
        return;
    unsigned char *state = (unsigned char *)value;
    unsigned short *nested = (unsigned short *)*(void **)(state + 0x8e18);
    if (*(const unsigned short *)(record + 4) != nested[4])
        return;
    const unsigned char *source = record + 6;
    for (int i = 0; i < 8; ++i, ++source)
        *(unsigned *)(state + 0x8de0 + i * 4) = *source;
}
