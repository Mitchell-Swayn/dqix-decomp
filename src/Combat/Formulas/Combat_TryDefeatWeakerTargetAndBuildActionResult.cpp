#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x24]; unsigned successMessage:10, middleMessage:10, failureMessage:10, rest24:2; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; };
}
extern "C" signed char Combat_GetCombatantLevel(void*,int);
// The fourth argument is a mode-dependent opaque 32-bit carrier: this path passes a descriptor address.
// Other callers pass reason tags; the owning tagged interface remains to be recovered. The fifth argument is a byte.
extern "C" void Combat_RecordMonsterDefeatSnapshot(void*,int,int,int,unsigned char,int);
extern "C" void CombatantState_ResetStatusesForBattleRemoval(unsigned char*);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E05FC; symbol: func_ov024_021e05fc; size: 0x1b4.
// Defeats an eligible target at least seven levels below the actor and records its defeat result.
extern "C" void* Combat_TryDefeatWeakerTargetAndBuildActionResult(CombatActionState* self,int actorId,int targetId,ActionDefinition* action)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    GameState::GetInstance();
    int targetLevel = Combat_GetCombatantLevel(self->combat, targetId);
    int actorLevel = Combat_GetCombatantLevel(self->combat, actorId);
    int eligible = 0;
    if (actorLevel > targetLevel && actorLevel - targetLevel >= 7) eligible = 1;
    unsigned char* environment = *(unsigned char**)(self->combat + 0x8e18);
    if (environment && *(int*)(environment + 0xc) >= 0) eligible = 0;
    int targetLimit = ((unsigned char*)target->currentStats_)[0x48];
    unsigned short message = 0;
    unsigned long long mask = 0;
    if (targetLimit >= 1 && eligible) {
        GameObject* defeated = GetCombatantByID((int)self->combat, targetId);
        if (defeated) {
            message = (unsigned short)action->successMessage;
            Combat_RecordMonsterDefeatSnapshot(self->combat, targetId, actorId, (int)action, 0, 4);
            defeated->currentStats_->primaryStats.currHP = 0;
            CombatantState_ResetStatusesForBattleRemoval((unsigned char*)defeated->currentStats_);
            Combat_SetResultMaskFlag(self->combat, &mask, 36);
            self->combat[0x8e15]++;
        }
    } else message = (unsigned short)action->failureMessage;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, mask, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
