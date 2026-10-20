#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState19GetCombatantByIndexEi(void *, int);
// Original: arm9/ov024 @ 0x021D8C10; symbol: func_ov024_021d8c10; size: 0x60.
extern "C" int AdjustRecordValueForCombatant(void *owner, int index, int unused2, int unused3, int unused4, int fallback) {
    void *combatant = _ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (combatant == 0) return fallback;
    unsigned *flags = *(unsigned **)((unsigned char *)combatant + 0x138);
    if (flags[0x18 / 4] & 0x200)
        return *(short *)((unsigned char *)*(void **)owner + 0x8e54);
    short value = *(short *)((unsigned char *)*(void **)owner + 0x8e54);
    return (int)((float)value * 1.5f);
}
