#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition { unsigned first; unsigned id:12, rest4:20; char padding[0x20-8]; unsigned reserved20:20, partyMessage:10, rest20:2; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; int appliedCount; char padding[0x75-0x18]; unsigned char effectApplied; };
}
struct Flags;
struct LinkedDescriptorView;
extern "C" int CombatStatus_CanApplySleep(char*);
extern "C" void CombatStatus_ApplySleep(unsigned char*);
extern "C" unsigned Combat_SelectPartyHalfwordForDescriptorMode(char*,int,int);
extern "C" int Combat_HasOrdinaryTension(LinkedDescriptorView*);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_QueueTensionLossNotification(char*,void*,unsigned,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_SuppressMessageForExceptionalOutcome(void*,Flags*,unsigned short*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021DBD84; symbol: func_ov024_021dbd84; size: 0x194.
// Applies eligible sleep, records replaced ailments and tension loss, then builds the selected result.
extern "C" void* Combat_ApplySleepAndBuildResult(CombatActionState* self,int unusedActor,int targetId,ActionDefinition* action,int unused4,int unused5,unsigned char enabled)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int applied = 0;
    int eligible = CombatStatus_CanApplySleep((char*)target->currentStats_);
    if (eligible && enabled) applied = 1;
    unsigned long long mask = 0;
    unsigned short message = Combat_SelectPartyHalfwordForDescriptorMode((char*)self, targetId, applied);
    int hadTension = Combat_HasOrdinaryTension((LinkedDescriptorView*)target);
    if (applied) {
        if (action->id == 0x233) message = action->partyMessage;
        if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 0x10))
            Combat_SetResultMaskFlag(self->combat, &mask, 43);
        CombatStatus_ApplySleep((unsigned char*)target->currentStats_);
        Combat_SetResultMaskFlag(self->combat, &mask, 14);
        self->appliedCount++;
        if (hadTension) Combat_QueueTensionLossNotification((char*)self, target, 0, 0);
    } else self->effectApplied = 0;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    Combat_SuppressMessageForExceptionalOutcome(self, (Flags*)self->flags, &message);
    Combat_AppendResultMessage(self->combat, result, message);
    Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, mask, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
