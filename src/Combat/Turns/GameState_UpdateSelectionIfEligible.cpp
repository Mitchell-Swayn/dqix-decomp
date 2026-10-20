#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void* state, int index);
extern "C" bool GameObject_IsDead(void* object);
extern "C" int Combat_IsCombatantExcludedFromSelection(char* object);
// Original: arm9/ov000 @ 0x02153CC0; symbol: func_ov000_02153cc0; size: 0x50.
extern "C" void GameState_UpdateSelectionIfEligible(void* unused, unsigned value, int* index) {
    int selectedIndex = (short)*index;
    void* state = _ZN9GameState11GetInstanceEv();
    void* combatant = _ZN9GameState19GetCombatantByIndexEi(state, selectedIndex);
    if (combatant != 0 && !GameObject_IsDead(combatant) && !Combat_IsCombatantExcludedFromSelection((char*)combatant))
        return;
    *((unsigned*)index) = value;
}
