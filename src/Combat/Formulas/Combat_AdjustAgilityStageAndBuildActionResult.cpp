#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x30]; short delta; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; int appliedCount; char padding[0x75-0x18]; unsigned char effectApplied; };
}
struct Flags;
extern "C" int CombatStatus_CanAdjustAgilityStage(unsigned*,int);
extern "C" int CombatStatus_AdjustAgilityStageAndRefreshTimer(char*,int);
void UpdateCombatantAgility(int,int);
extern "C" int Combat_SelectAgilityStageChangeMessage(char*,int,char*,int,signed char,unsigned char,unsigned char);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DB994; symbol: func_ov024_021db994; size: 0x160.
// Applies an enabled agility stage change and selects its result feedback, suppressing exceptional messages.
extern "C" void* Combat_AdjustAgilityStageAndBuildActionResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    unsigned char applied = 0;
    int stage = applied;
    int lowering = applied;
    int delta = action->delta;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    if (delta < 0) lowering = 1;
    if (enabled) {
        if (CombatStatus_CanAdjustAgilityStage((unsigned*)target->currentStats_, (unsigned char)lowering)) {
            stage = CombatStatus_AdjustAgilityStageAndRefreshTimer((char*)target->currentStats_, (signed char)delta);
            UpdateCombatantAgility((int)self->combat, targetId);
            self->appliedCount++;
            applied = 1;
        } else self->effectApplied = 0;
    } else self->effectApplied = 0;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    unsigned short message = Combat_SelectAgilityStageChangeMessage((char*)self, targetId, (char*)action, (unsigned char)lowering, (signed char)stage, applied, enabled);
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags*)self->flags, &message);
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
