#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
namespace {
struct ActionDefinition { unsigned first; unsigned id:12, rest4:20; char padding[0x24-8]; unsigned message:10, rest24:22; };
struct CombatActionState { char prefix[0x10]; unsigned char* combat; };
struct MonsterObject { char prefix[0x138]; ModifiableCombatStats* stats; char padding[0x188-0x13c]; unsigned short previousHP, previousMP; };
struct TransformResult { char prefix[0xe]; unsigned short currentHP,currentMP,maximumHP,maximumMP; char padding[0x20-0x16]; unsigned tail; };
}
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" void BattleScene_ChangeMonsterSpecies(unsigned,int,int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void* Memory_ZeroThirtyTwoByteBlock(void*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void CombatantState_ResetStatusesForBattleRemoval(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E0D00; symbol: func_ov024_021e0d00; size: 0x138.
// Transforms a self-targeted monster according to the action; other targets lose HP and battle statuses.
extern "C" void* Combat_TransformSelfOrRemoveMonsterAndBuildResult(CombatActionState* self,int actorId,int targetId,ActionDefinition* action)
{
    MonsterObject* target = (MonsterObject*)Combat_FindIndexedMonsterObject(self->combat, targetId);
    if (!target) return 0;
    if (actorId == targetId) {
        int species = -1;
        if (action->id == 0x153) species = 0xb3;
        if (action->id == 0x31a) species = 0x4b;
        BattleScene_ChangeMonsterSpecies(BattleScene_GetActiveInstance(), targetId, species, 1);
        TransformResult* result = (TransformResult*)Combat_ClearCurrentResultNodeSlot(self->combat);
        if (!result) return 0;
        Memory_ZeroThirtyTwoByteBlock(result);
        result->tail = 0;
        result->currentHP = target->previousHP;
        result->currentMP = target->previousMP;
        result->maximumHP = target->previousHP;
        result->maximumMP = target->previousMP;
        Combat_AppendResultMessage(self->combat, result, (unsigned short)action->message);
        return result;
    }
    target->stats->primaryStats.currHP = 0;
    CombatantState_ResetStatusesForBattleRemoval((unsigned char*)target->stats);
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, 0);
    return result;
}
#pragma force_active reset
