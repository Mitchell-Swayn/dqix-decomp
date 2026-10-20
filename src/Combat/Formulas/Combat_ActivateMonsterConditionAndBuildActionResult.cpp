#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
namespace {
struct MonsterStats { char prefix[0x2e]; short activationActor; };
struct MonsterObject { char prefix[0x138]; MonsterStats* stats; char padding[0x182-0x13c]; unsigned char activationQueued; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; int appliedCount; };
}
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
extern "C" int Combat_HasMonsterActivationCondition(unsigned char*);
extern "C" void GameObject_SetCombatActivationMarker(unsigned char*,int);
extern "C" void Combat_QueueForcedTargetReaction(void*,int);
extern "C" int Combat_TryActivateMonsterReactionByActionType(char*,int,int,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E04E0; symbol: func_ov024_021e04e0; size: 0x104.
// Activates an eligible monster reaction, queues its target and builds the action result.
extern "C" void* Combat_ActivateMonsterConditionAndBuildActionResult(CombatActionState* self, int actorId, int targetId)
{
    MonsterObject* target = (MonsterObject*)Combat_FindIndexedMonsterObject(self->combat, targetId);
    if (!target) return 0;
    if (Combat_HasMonsterActivationCondition((unsigned char*)target)) {
        target->stats->activationActor = actorId;
        GameObject_SetCombatActivationMarker((unsigned char*)target, 1);
        Combat_QueueForcedTargetReaction(self->combat, targetId);
        target->activationQueued = 1;
        self->appliedCount++;
    } else if (Combat_TryActivateMonsterReactionByActionType((char*)self, actorId, targetId, 0x12)) {
        Combat_QueueForcedTargetReaction(self->combat, targetId);
        target->activationQueued = 1;
        self->appliedCount++;
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
