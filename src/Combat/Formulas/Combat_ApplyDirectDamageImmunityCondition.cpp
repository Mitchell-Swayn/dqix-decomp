#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(int, int);
extern "C" int CombatantState_CanApplyKnightWatch(unsigned*);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void CombatantState_ActivateKnightWatch(unsigned char*);
// Original: arm9/ov024 @ 0x021E5E80; symbol: func_ov024_021e5e80; size: 0x44.
extern "C" void Combat_ApplyDirectDamageImmunityCondition(unsigned char* state, int index) {
    void* combatant = _Z16GetCombatantByIDii(*(int*)(state + 0x10), index);
    if (combatant == 0) return;
    if (!CombatantState_CanApplyKnightWatch(*(unsigned**)((char*)combatant + 0x138))) return;
    if (Combat_ClearCurrentResultNodeSlot(*(unsigned char**)(state + 0x10)) == 0) return;
    CombatantState_ActivateKnightWatch(*(unsigned char**)((char*)combatant + 0x138));
}
