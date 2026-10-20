#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <std_library_functions.h>
ARM
struct ActionDefinition {
 unsigned first;
 unsigned id:12, otherId:20;
 unsigned mpCost:8, resultMode:2, reserved8:17, usable:1, rest8:4;
 unsigned wordC, flags10, word14, word18;
};
struct BattleAIState {
 void* combat;
 short actorId;
 unsigned char mode, unknown7;
 GameObject* actor;
 int phase;
 char unknown10[0x128-0x10];
 unsigned targetHint;
 char unknown12c[8];
 int inactiveCount;
 char unknown138[0x64c-0x138];
 ActionDefinition* action;
};
struct ScoringRequest { char records[196]; float weight; };
struct Modifier21 { unsigned reserved:21; signed value:3; unsigned rest:8; };
extern "C" int BattleAI_ComputeActionMpCost(GameObject*, const ActionDefinition*, int*);
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(BattleAIState*, int);
extern "C" void BattleAI_ScoreActionEffectsAndRankChoices(BattleAIState*, void*, int, unsigned);
extern "C" int BattleAI_GetActorPolicyCategory(GameObject*);
struct ScoredEffect { float magnitude; unsigned char reserved4, flags, targetId, probability, kind, reserved9; };
extern "C" void* GameObject_GetLinkedIndexedState(GameObject*);
extern "C" void* ActionData_GetGlobalTables(void*);
extern "C" int PartySelection_GetMemberMask(void*, unsigned char);
extern "C" bool GameObject_IsDead(GameObject*);
extern "C" void AppendTenByteRecordIfCapacity(unsigned char*, const unsigned char*);
#pragma always_inline on
enum RevivalTargetMode { RevivalSingle = 1, RevivalEach = 2, RevivalAll = 3, RevivalGroup = 4 };
inline RevivalTargetMode ReadRevivalTargetMode(ActionDefinition* action) { return (RevivalTargetMode)(action->word14 >> 28); }
// Original: arm9/ov024 @ 0x021FC068; symbol: BattleAI_ScorePartialRevivalTargets; size: 0x1ec.
// Builds scored revival target records from inactive eligible party members.
extern "C" void BattleAI_ScorePartialRevivalTargets(BattleAIState* self)
{
    GameObject* actor = self->actor;
    ActionData_GetGlobalTables(GameObject_GetLinkedIndexedState(actor));
    ActionDefinition* action = self->action;
    if (action->resultMode == 1) return;
    GetCombatantByID((int)self->combat, (short)self->targetHint);
    float probability = 50.0f;
    unsigned id = action->id;
    if (id == 0x27) probability = 100.0f;
    else if (id == 0x26 || id == 0x54) probability = 50.0f;
    ScoringRequest request;
    memset(&request, 0, sizeof(request));
    memset(&request, 0, sizeof(request));
    for (int member = 0; member < 4; ++member) {
        if (!PartySelection_GetMemberMask(*(void**)((char*)self->combat + 0x8e18), (unsigned char)member)) continue;
        RevivalTargetMode targetMode = ReadRevivalTargetMode(action);
        if (targetMode == 1 && member != self->actorId) continue;
        GameObject* object = GetCombatantByID((int)self->combat, (short)member);
        if (!object || !GameObject_IsDead(object)) continue;
        if ((action->flags10 & 0x400) && (*(unsigned*)((char*)object->currentStats_ + 0x14) & 0x200)) continue;
        ScoredEffect effect;
        effect.magnitude = (float)(object->currentStats_->primaryStats.currHP / 2);
        effect.flags = 0;
        effect.targetId = member;
        effect.probability = (unsigned char)(int)probability;
        effect.kind = 5;
        AppendTenByteRecordIfCapacity((unsigned char*)&request, (const unsigned char*)&effect);
        targetMode = ReadRevivalTargetMode(action);
        if (targetMode != RevivalEach) {
            if (targetMode != RevivalSingle) continue;
        }
        BattleAI_ScoreActionEffectsAndRankChoices(self, &request, 0, *(short*)((char*)object + 4) & 255);
        memset(&request, 0, sizeof(request));
    }
    RevivalTargetMode targetMode = ReadRevivalTargetMode(action);
    if (targetMode != 4 && targetMode != 3) return;
    GetCombatantByID((int)self->combat, 0);
    unsigned mode = action->word14 >> 28;
    unsigned targetId = *(short*)((char*)actor + 4) & 255;
    if (mode == 3) targetId = 255;
    BattleAI_ScoreActionEffectsAndRankChoices(self, &request, 0, targetId);
}
