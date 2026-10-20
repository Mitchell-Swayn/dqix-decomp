#include <globaldefs.h>
ARM
extern "C" char* Combat_GetCommandActorSnapshot(void*, int);
extern "C" char* Combat_GetIndexedActionTarget(void*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" void Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(void*, int, int);
// Original: arm9/ov025 @ 0x021E45C4; symbol: func_ov025_021e45c4; size: 0x60.
extern "C" int Combat_TurnLinkedCombatantTowardTarget(void* unused, void* owner, unsigned short index, int enable) {
    char* primary = Combat_GetCommandActorSnapshot(owner, 0);
    char* secondary = Combat_GetIndexedActionTarget(owner, 0);
    if (primary == 0 || secondary == 0) return 1;
    char* state = (char*)_ZN9GameState11GetInstanceEv();
    char* combatant = _ZN9GameState19GetCombatantByIndexEi(state, *(unsigned short*)(primary + 0x20));
    if (combatant != 0)
        Object3D_TurnTowardIndexedObjectAndSelectTurnAnimation(combatant, *(short*)(secondary + 0xE), 0);
    return 1;
}
