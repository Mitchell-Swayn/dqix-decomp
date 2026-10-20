#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
// Original: arm9/ov000 @ 0x0215A1D4; symbol: func_ov000_0215a1d4; size: 0x68.
extern "C" int GameState_AddCombatantValueUpToMaximum(void* unused, int index, unsigned short amount, unsigned short* applied) {
    char* combatant = (char*)_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (!combatant) return 0;
    int next = *(unsigned short*)(*(char**)(combatant + 0x138) + 2) + amount;
    *applied = amount;
    if (next > *(unsigned short*)(*(char**)(combatant + 0x138) + 6)) {
        *applied = *(unsigned short*)(*(char**)(combatant + 0x138) + 6) - *(unsigned short*)(*(char**)(combatant + 0x138) + 2);
        next = *(unsigned short*)(*(char**)(combatant + 0x138) + 6);
    }
    *(unsigned short*)(*(char**)(combatant + 0x138) + 2) = (unsigned short)next;
    return (short)next;
}
