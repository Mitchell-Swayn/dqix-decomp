#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
namespace {
struct ActionDefinition {
    unsigned header;
    unsigned id:12, rest4:20;
    char padding[0x20-8];
    unsigned reserved20:20, appliedPartyMessage:10, rest20:2;
    unsigned appliedMonsterMessage:10, otherPartyMessage:10, otherMonsterMessage:10, rest24:2;
};
struct ResultFlags {
    char prefix[0x1c];
    unsigned char low:7, enabled:1;
};
struct CombatActionState {
    char prefix[0xc];
    ResultFlags* flags;
    unsigned char* battle;
    char padding[0x6e - 0x14];
    unsigned char messageQueued;
};
}
extern "C" int CombatantState_CanApplyZeroZone(char*);
extern "C" void CombatantState_ActivateZeroZone(char*);
extern "C" unsigned short Combat_SelectMessageForPartyOrMonster(int,int,int);
extern "C" void* Combat_ClearCurrentResultNodeSlot(unsigned char*);
extern "C" void Combat_AppendResultMessage(void*,void*,unsigned short);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,int,int,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E1580; symbol: func_ov024_021e1580; size: 0x124.
// Applies eligible Zero Zone status, selects the descriptor message and builds the target result while suppressing repeated messages.
extern "C" void* Combat_ApplyMPCostExemptionAndBuildResult(CombatActionState* self, int unused, int targetId, ActionDefinition* action, int unused4, int unused5, unsigned char apply)
{
    GameObject* target = GetCombatantByID((int)self->battle, targetId);
    if (!target) return 0;
    unsigned short message;
    if (CombatantState_CanApplyZeroZone((char*)target->currentStats_) && apply) {
        CombatantState_ActivateZeroZone((char*)target->currentStats_);
        message = Combat_SelectMessageForPartyOrMonster(targetId, action->appliedPartyMessage, action->appliedMonsterMessage);
    } else {
        message = Combat_SelectMessageForPartyOrMonster(targetId, action->otherPartyMessage, action->otherMonsterMessage);
    }
    void* result = Combat_ClearCurrentResultNodeSlot(self->battle);
    if (!result) return 0;
    if (action->id == 0x1fb || !self->messageQueued) {
        Combat_AppendResultMessage(self->battle, result, message);
        self->messageQueued = 1;
    }
    Combat_PopulateResultWithCurrentHealthAndMagic(self->battle, result, target, 0, 0, 0, self->flags->enabled != 0);
    return result;
}
#pragma force_active reset
