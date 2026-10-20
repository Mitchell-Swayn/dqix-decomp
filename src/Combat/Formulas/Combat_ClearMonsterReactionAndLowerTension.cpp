#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
#pragma always_inline on
namespace {
struct CombatActionState { char prefix[0xc]; void* results; unsigned char* combat; };
inline bool IsPartyIndex(int index) { bool party; if (index >= 0 && index <= 3) party = true; else party = false; return party; }
}
struct LinkedDescriptorView;
struct Lists;
struct Node;
extern "C" int Combat_HasMonsterActivationCondition(unsigned char*);
extern "C" void GameObject_SetCombatRecoveryMarker(char*,int);
extern "C" void CombatantState_ClearLinkedCombatEffect(unsigned char*);
extern "C" int Combat_HasOrdinaryTension(LinkedDescriptorView*);
extern "C" int Combat_HasSuperHighTension(void*);
extern "C" void CombatStatus_DecrementTensionStage(unsigned char*);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
extern "C" void Combat_AppendTargetResultToCategoryList(Lists*,Node*,int);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E3F14; symbol: func_ov024_021e3f14; size: 0x1c4.
// Clears a linked monster reaction and lowers tension, queues transition feedback, and returns an empty mask.
extern "C" unsigned long long Combat_ClearMonsterReactionAndLowerTension(CombatActionState* self,int unusedActor,int targetId,void* unusedAction,int amount)
{
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    void* result = Combat_ClearCurrentResultNodeSlot(self->combat);
    if (!result) return 0;
    int queued = 0;
    if (Combat_HasMonsterActivationCondition((unsigned char*)target)) {
        if (!IsPartyIndex(targetId)) GameObject_SetCombatRecoveryMarker((char*)target, 1);
        CombatantState_ClearLinkedCombatEffect((unsigned char*)target->currentStats_);
        Combat_AppendResultMessage(self->combat, result, 0x164);
        queued = 1;
    }
    unsigned long long mask = 0;
    if (Combat_HasOrdinaryTension((LinkedDescriptorView*)target) || Combat_HasSuperHighTension(target)) {
        CombatStatus_DecrementTensionStage((unsigned char*)target->currentStats_);
        unsigned short message = 0;
        unsigned mode = ((unsigned char*)target->currentStats_)[0x24];
        switch (mode) {
        case 0: message = 0x17f; break;
        case 1: message = 0x180; break;
        case 2: message = 0x181; break;
        case 3: message = 0x259; break;
        }
        if (mode == 3) Combat_SetResultMaskFlag(self->combat, &mask, 8);
        Combat_AppendResultMessage(self->combat, result, message);
        queued = 1;
    }
    if (queued) {
        Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, mask, 0);
        Combat_AppendTargetResultToCategoryList((Lists*)self->results, (Node*)result, 1);
        self->combat[0x8e02]++;
    }
    return 0;
}
#pragma force_active reset
