#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x30]; short mode; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; };
}
struct A;
struct Flags;
extern "C" bool CombatStatus_CanApplyAilmentModeTwo(unsigned*);
extern "C" int CombatStatus_CanApplyAilmentModeOne(A*);
extern "C" void CombatStatus_ApplyAilmentModeTwo(char*);
extern "C" void CombatStatus_ApplyAilmentModeOne(unsigned char*);
extern "C" int Combat_SelectAilmentModeMessage(char*,int,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DBAF4; symbol: func_ov024_021dbaf4; size: 0x170.
// Applies an enabled ailment mode and records its result mask and selected feedback.
extern "C" void* Combat_ApplyAilmentModeAndBuildActionResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int mode = action->mode;
    int applied = 0;
    int modeTwo = applied;
    if (mode > 0) {
        if (CombatStatus_CanApplyAilmentModeTwo((unsigned*)target->currentStats_) && enabled) {
            applied = 1;
            modeTwo = applied;
        }
    } else {
        if (CombatStatus_CanApplyAilmentModeOne((A*)target->currentStats_) && enabled) applied = 1;
    }
    unsigned short message = Combat_SelectAilmentModeMessage((char*)self, targetId, modeTwo, applied);
    unsigned long long mask = 0;
    if (applied) {
        if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 2))
            Combat_SetResultMaskFlag(self->combat, &mask, 43);
        if (modeTwo) CombatStatus_ApplyAilmentModeTwo((char*)target->currentStats_);
        else CombatStatus_ApplyAilmentModeOne((unsigned char*)target->currentStats_);
        Combat_SetResultMaskFlag(self->combat, &mask, 15);
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags*)self->flags, &message);
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, mask, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
