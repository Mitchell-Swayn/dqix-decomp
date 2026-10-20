#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x20]; unsigned reserved20:20, appliedPartyMessage:10, rest20:2; unsigned appliedMonsterMessage:10, otherPartyMessage:10, otherMonsterMessage:10, rest24:2; char padding[0x30-0x28]; short mode; };
struct ModeField { unsigned short low:6, mode:3, high:7; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; char padding[0x75-0x14]; unsigned char effectApplied; };
}
struct Flags;
extern "C" bool CombatStatus_CanApplyDazzle(unsigned*);
extern "C" void CombatStatus_ApplyDazzle(char*);
extern "C" int Combat_SelectTimedConditionModeMessage(void*,int,int,int);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DD534; symbol: func_ov024_021dd534; size: 0x1bc.
// Applies an enabled dazzle mode, selects mode-specific or descriptor feedback and builds the target result.
extern "C" void* Combat_ApplyDazzleAndBuildResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    unsigned short message = 0;
    unsigned long long mask = 0;
    int mode = action->mode;
    if (CombatStatus_CanApplyDazzle((unsigned*)target->currentStats_) && enabled) {
        message = Combat_SelectTimedConditionModeMessage(self, targetId, (short)mode, 1);
        if (!message) message = Combat_SelectMessageForPartyOrMonster(targetId, action->appliedPartyMessage, action->appliedMonsterMessage);
        if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 0x40))
            Combat_SetResultMaskFlag(self->combat, &mask, 43);
        CombatStatus_ApplyDazzle((char*)target->currentStats_);
        ((ModeField*)((unsigned char*)target->currentStats_ + 0x22))->mode = (unsigned char)mode;
    } else {
        message = Combat_SelectTimedConditionModeMessage(self, targetId, (short)mode, 0);
        if (!message) message = Combat_SelectMessageForPartyOrMonster(targetId, action->otherPartyMessage, action->otherMonsterMessage);
        self->effectApplied = 0;
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags*)self->flags, &message);
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, mask, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
