#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct ActionDefinition { char prefix[4]; unsigned kind:12, rest04:20; char pad08[0xc]; unsigned monsterChance:7, partyChance:7, rest14:18; char padding[0x32 - 0x18]; short mode; };
struct ResultFlags { char prefix[0x1c]; unsigned char low:7, enabled:1; };
struct CombatActionState { char prefix[0xc]; ResultFlags* flags; unsigned char* combat; };
#pragma always_inline on
inline bool IsPartyIndex(int index) {
    bool party;
    if (index >= 0 && index <= 3) party = true;
    else party = false;
    return party;
}
}
extern "C" bool CombatStatus_CanApplyParalysis(unsigned*);
extern "C" void ClearTransitionFlagsAndSetStateThree(unsigned char*);
extern "C" int Combatant_GetPartyStateValue(void*,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
struct LinkedDescriptorView;
extern "C" int Combat_HasOrdinaryTension(LinkedDescriptorView*);
extern "C" void* Combat_QueueTensionLossNotification(char*,void*,unsigned,int);
extern "C" int Combat_TestMonsterDescriptorMode(void*,int,int,int);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E3A34; symbol: func_ov024_021e3a34; size: 0x2b8.
// Applies chance-scaled paralysis, appends feedback with an empty result mask and
// returns the accumulated replacement/paralysis flags to the secondary dispatcher.
extern "C" unsigned long long Combat_TryApplyParalysis(CombatActionState* self,int actorId,int targetId,ActionDefinition* action,int amount)
{
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    unsigned kind = action->kind;
    if (kind == 0x52) {
        if (!Combat_TestMonsterDescriptorMode(self->combat, targetId, 9, 0)) return 0;
    } else if (kind == 0x58) {
        if (!Combat_TestMonsterDescriptorMode(self->combat, targetId, 0, 1) && !((unsigned char*)target->currentStats_)[0x4e]) return 0;
    } else {
        if (!((unsigned char*)target->currentStats_)[0x4e]) return 0;
    }
    if (!CombatStatus_CanApplyParalysis((unsigned*)target->currentStats_)) return 0;
    int sample = NextRandomMax((Random*)self->combat, 100);
    float chance = 100.0f;
    if (!self->flags->enabled) {
        if (IsPartyIndex(actorId)) chance = (float)action->partyChance;
        else chance = (float)action->monsterChance;
        chance *= (float)(unsigned)((unsigned char*)target->currentStats_)[0x4e] / 100.0f;
        switch (action->kind) {
        case 0x52: chance = 25.0f; break;
        case 0x58:
            if (Combat_TestMonsterDescriptorMode(self->combat, targetId, 0, 1)) chance = 12.5f;
            break;
        }
    }
    if ((float)sample >= chance) return 0;
    int message = Combatant_GetPartyStateValue(self, targetId, 1);
    unsigned long long mask = 0;
    if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 0x8))
        Combat_SetResultMaskFlag(self->combat, &mask, 43);
    int hadTension = Combat_HasOrdinaryTension((LinkedDescriptorView*)target);
    ClearTransitionFlagsAndSetStateThree((unsigned char*)target->currentStats_);
    Combat_SetResultMaskFlag(self->combat, &mask, 24);
    void* result = GameState_CreateAndAppendIndexedRecord(self, message);
    if (result) Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, 0);
    if (hadTension) Combat_QueueTensionLossNotification((char*)self, target, 0, 0);
    return mask;
}
#pragma force_active reset
