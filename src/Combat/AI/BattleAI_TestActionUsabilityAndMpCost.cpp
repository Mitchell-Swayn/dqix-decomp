#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <std_library_functions.h>
ARM
struct ActionDefinition {
 unsigned first;
 unsigned id:12, otherId:20;
 unsigned mpCost:8, reserved8:19, usable:1, rest8:4;
 unsigned wordC, flags10, word14, word18;
};
struct BattleAIState {
 void* combat;
 short actorId;
 unsigned char mode, unknown7;
 GameObject* actor;
 int phase;
 char unknown10[0x64c-0x10];
 ActionDefinition* action;
};
struct ScoringRequest { char records[196]; float weight; };
struct Modifier21 { unsigned reserved:21; signed value:3; unsigned rest:8; };
extern "C" int BattleAI_ComputeActionMpCost(GameObject*, const ActionDefinition*, int*);
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(BattleAIState*, int);
extern "C" void BattleAI_ScoreActionEffectsAndRankChoices(BattleAIState*, void*, int, unsigned);
extern "C" int BattleAI_GetActorPolicyCategory(GameObject*);
// Original: arm9/ov024 @ 0x021F8874; symbol: BattleAI_TestActionUsabilityAndMpCost; size: 0xc4.
// Checks the descriptor's usability bit, MP affordability, and actor restriction flags.
extern "C" int BattleAI_TestActionUsabilityAndMpCost(BattleAIState* self, const ActionDefinition* action, GameObject* actor, int* cost)
{
    if (!action) return 0;
    if (!action->usable) return 0;
    int partyActor = 0;
    int index = *(short*)((char*)actor + 4);
    if (index >= 0 && index <= 3) partyActor = 1;
    int mpCost;
    if (partyActor) mpCost = BattleAI_ComputeActionMpCost(actor, action, cost);
    else mpCost = action->mpCost;
    if (mpCost > self->actor->currentStats_->primaryStats.currMP) return 0;
    if ((action->flags10 & 1) && (*(unsigned*)((char*)actor->currentStats_ + 0x14) & 0x100)) return 0;
    if ((action->flags10 & 2) && (*(unsigned*)((char*)actor->currentStats_ + 0x14) & 0x80)) return 0;
    return 1;
}
