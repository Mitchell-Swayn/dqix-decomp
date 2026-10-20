#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
namespace {
struct ActionDefinition {
    char prefix[0x32];
    short goldCost;
};
struct CombatActionState {
    char prefix[0x10];
    unsigned char* combat;
};
}
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" GameObject* GameState_FindIndexedObjectWithFlag1000(GameState*, int);
extern "C" int GameState_IsProtagonistOrLinkedToProtagonist(void*, int);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E5BE4; symbol: func_ov024_021e5be4; size: 0x98.
// Subtracts the signed action gold cost from party funds or the selected combatant's gold balance.
extern "C" void Combat_DeductActionGoldCost(CombatActionState* self, int actorId, ActionDefinition* action)
{
    GameState* state = GameState::GetInstance();
    unsigned char* inventory = (unsigned char*)GameState_GetIndexList(state);
    if (GameState_IsProtagonistOrLinkedToProtagonist(self->combat, actorId)) {
        *(int*)(inventory + 0xf6c) -= action->goldCost;
        return;
    }
    int balance;
    int* balances;
    if (GameState_FindIndexedObjectWithFlag1000(state, actorId)) {
        actorId = 0;
        balances = (int*)(self->combat + 0x8e84);
        balance = balances[0];
    } else {
        balances = (int*)(self->combat + 0x8e84);
        balance = balances[actorId];
    }
    balances[(short)actorId] = balance - action->goldCost;
}
#pragma force_active reset
