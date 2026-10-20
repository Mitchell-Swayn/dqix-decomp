#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
namespace {
struct ActionDefinition {
    unsigned header;
    unsigned id:12, remaining4:20;
    char padding[0x20-8];
    unsigned reserved20:20, appliedPartyMessage:10, rest20:2;
    unsigned appliedMonsterMessage:10, otherPartyMessage:10, otherMonsterMessage:10, rest24:2;
};
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; int appliedCount; };
struct PartyObjectView {
    char prefix[0x130];
    const char* percentages;
    BaseCombatStats* baseStats;
    ModifiableCombatStats* currentStats;
    char padding[0x150-0x13c];
    char* characterState;
};
}
struct Out;
struct Stats;
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" int GameState_IncrementSelectedPackedAttribute(char*,int);
extern "C" void CharacterState_RecalculateOrPreviewDerivedStats(void*,void*);
extern "C" void CombatantState_RefreshBaseStatsAndPercentageWeights(Out*,const char*,Stats*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
void ApplyCombatantBuffs(int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DE54C; symbol: func_ov024_021de54c; size: 0x12c.
// Applies a permanent attribute increase, refreshes derived battle stats and builds the selected result message.
extern "C" void* Combat_IncreasePermanentAttributeAndBuildActionResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action)
{
    PartyObjectView* target = (PartyObjectView*)GameState_GetObjectWithFlag100(GameState::GetInstance(), targetId);
    if (!target) return 0;
    unsigned short message;
    if (GameState_IncrementSelectedPackedAttribute(target->characterState, action->id) > 0) {
        message = Combat_SelectMessageForPartyOrMonster(targetId, action->appliedPartyMessage, action->appliedMonsterMessage);
        CharacterState_RecalculateOrPreviewDerivedStats(target->characterState, 0);
        CombatantState_RefreshBaseStatsAndPercentageWeights((Out*)target->currentStats, target->percentages, (Stats*)target->baseStats);
        ApplyCombatantBuffs((int)self->combat, targetId);
        self->appliedCount++;
    } else {
        message = Combat_SelectMessageForPartyOrMonster(targetId, action->otherPartyMessage, action->otherMonsterMessage);
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
