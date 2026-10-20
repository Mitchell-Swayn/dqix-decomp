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
// Original: arm9/ov024 @ 0x021FCFA0; symbol: BattleAI_ScoreDefaultActionUnlessCoreStagesBoosted; size: 0xd8.
// Scores the enabled default action unless at least two core attribute stages already reach the cap.
extern "C" void BattleAI_ScoreDefaultActionUnlessCoreStagesBoosted(BattleAIState* self)
{
    int enabled = 0;
    if (self->mode == 2) enabled = 1;
    if (!self->mode) return;
    if (self->phase >= 3) enabled = 1;
    if (!enabled) return;
    if (!BattleAI_SelectEnabledActionPolicyEntry(self, 18)) return;
    int capped = 0;
    ModifiableCombatStats* stats = self->actor->currentStats_;
    if (stats->defenseBuff >= 2) ++capped;
    if (((Modifier21*)((char*)stats + 0x58))->value >= 2) ++capped;
    if (stats->attackBuff >= 2) ++capped;
    if (capped >= 2) return;
    ScoringRequest request;
    memset(&request, 0, sizeof(request));
    request.weight = 1000.0f;
    BattleAI_ScoreActionEffectsAndRankChoices(self, &request, 0, self->actorId & 255);
}
