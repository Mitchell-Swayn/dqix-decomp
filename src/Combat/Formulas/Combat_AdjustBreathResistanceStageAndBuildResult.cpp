#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x20]; unsigned reserved20:20, appliedPartyMessage:10, rest20:2; unsigned appliedMonsterMessage:10, otherPartyMessage:10, otherMonsterMessage:10, rest24:2; char padding[0x30-0x28]; short delta; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; };
}
struct Motion;
struct Flags;
extern "C" int CombatStatus_CanAdjustBreathResistanceStage(unsigned char*,int);
extern "C" int CombatStatus_AdjustBreathResistanceStageAndRefreshDuration(Motion*,int);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DDAA0; symbol: func_ov024_021ddaa0; size: 0x1e0.
// Applies an enabled breath-resistance stage change and emits the stage and descriptor messages.
extern "C" void* Combat_AdjustBreathResistanceStageAndBuildResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int applied = 0;
    int stage = applied;
    if (enabled) {
        int delta = action->delta;
        if (delta < -2) delta = -2;
        if (delta > 2) delta = 2;
        int lowering = 0;
        if (delta < 0) lowering = 1;
        if (CombatStatus_CanAdjustBreathResistanceStage((unsigned char*)target->currentStats_, (unsigned char)lowering)) {
            stage = CombatStatus_AdjustBreathResistanceStageAndRefreshDuration((Motion*)target->currentStats_, (signed char)delta);
            applied = 1;
        }
    }
    unsigned short message = 0;
    if (applied) {
        if (action->delta > 0) {
            switch (stage) {
            case 2: message = 0x1b0; break;
            case 0: message = 0x1af; break;
            default: message = 0x1b1; break;
            }
        } else {
            switch (stage) {
            case 0: message = 0x1af; break;
            default: message = 0x1ae; break;
            }
        }
    } else message = Combat_SelectMessageForPartyOrMonster(targetId, action->otherPartyMessage, action->otherMonsterMessage);
    unsigned short descriptorMessage = Combat_SelectMessageForPartyOrMonster(targetId, action->appliedPartyMessage, action->appliedMonsterMessage);
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    if (descriptorMessage) Combat_AppendResultMessage(self->combat, result, descriptorMessage);
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags*)self->flags, &message);
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
