#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x24]; unsigned appliedMonster:10, otherParty:10, otherMonster:10, rest24:2; char padding[0x30-0x28]; short delta; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; int appliedCount; };
}
struct Flags;
extern "C" int CombatStatus_CanAdjustMagicalMendingModifier(unsigned*,int);
struct State;
extern "C" int CombatStatus_AdjustMagicalMendingModifierAndRefreshDuration(State*,int);
void UpdateCombatantMagicalMending(int,int);
extern "C" int Ov024_GetActionForMissingCombatant(void*,int,int,int,signed char);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DEE84; symbol: func_ov024_021dee84; size: 0x174.
// Applies an enabled magical-mending stage change and builds success or descriptor fallback feedback.
extern "C" void* Combat_AdjustMagicalMendingStageAndBuildActionResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int applied = 0;
    int stage = applied;
    int lowering = applied;
    if (enabled) {
        int delta = action->delta;
        if (delta < -2) delta = -2;
        if (delta > 2) delta = 2;
        if (delta < 0) lowering = 1;
        if (CombatStatus_CanAdjustMagicalMendingModifier((unsigned*)target->currentStats_, (unsigned char)lowering)) {
            stage = CombatStatus_AdjustMagicalMendingModifierAndRefreshDuration((State*)target->currentStats_, (signed char)delta);
            UpdateCombatantMagicalMending((int)self->combat, targetId);
            self->appliedCount++;
            applied = 1;
        }
    }
    unsigned short message = 0;
    int selected;
    if (applied) selected = Ov024_GetActionForMissingCombatant(self, targetId, (int)action, (unsigned char)lowering, (signed char)stage);
    else selected = Combat_SelectMessageForPartyOrMonster(targetId, action->otherParty, action->otherMonster);
    message = selected;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags*)self->flags, &message);
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
