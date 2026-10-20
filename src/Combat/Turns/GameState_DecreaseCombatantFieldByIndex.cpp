#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *_ZN9GameState19GetCombatantByIndexEi(void *state, int index);

// Original: arm9/ov000 @ 0x0215A124; symbol: func_ov000_0215a124; size: 0x48.
extern "C" short GameState_DecreaseCombatantFieldByIndex(void *unused, int index, int amount) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *combatant = _ZN9GameState19GetCombatantByIndexEi(state, index);
    if (combatant == 0) return 0;
    int value = *(unsigned short *)(*(unsigned char **)((char *)combatant + 0x138) + 2) - amount;
    if (value <= 0) value = 0;
    *(unsigned short *)(*(unsigned char **)((char *)combatant + 0x138) + 2) = value;
    return (short)value;
}
