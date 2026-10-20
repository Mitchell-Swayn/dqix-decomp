#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct ActionDefinition { char prefix[4]; unsigned kind:12, rest04:20; char pad08[0xc]; unsigned monsterChance:7, partyChance:7, rest14:18; unsigned low18:5, category:7, rest18:20; char padding[0x32 - 0x1c]; short mode; };
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
struct A;
struct LinkedDescriptorView;
extern "C" int LookupModeValueUnlessPackedModeRejected(char*,int,int);
extern "C" int CombatStatus_CanApplyActionRestriction(A*,unsigned,int);
extern "C" void CombatStatus_ApplyActionRestriction(char*,unsigned,unsigned);
extern "C" int Combat_HasOrdinaryTension(LinkedDescriptorView*);
extern "C" int Combat_HasSuperHighTension(void*);
extern "C" void* Combat_QueueTensionLossNotification(char*,void*,unsigned,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E2BD0; symbol: func_ov024_021e2bd0; size: 0x2ec.
// Applies mode-specific action restriction and returns its effect mask, recording
// optional feedback and ordinary or super-high tension loss.
extern "C" unsigned long long Combat_TryApplyActionRestrictionAndReturnEffectMask(CombatActionState* self,int actorId,int targetId,ActionDefinition* action,int amount)
{
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    if (action->category != 10) {
        if (amount <= 0) return 0;
        if (!((unsigned char*)target->currentStats_)[0x4c]) return 0;
        int sample = NextRandomMax((Random*)self->combat, 100);
        float chance = 100.0f;
        if (!self->flags->enabled) {
            if (IsPartyIndex(actorId)) chance = (float)action->partyChance;
            else chance = (float)action->monsterChance;
            unsigned kind = action->kind;
            if (kind != 0x239 && kind != 0x1fc)
                chance *= (float)(unsigned)((unsigned char*)target->currentStats_)[0x4c] / 100.0f;
        }
        if ((float)sample >= chance) return 0;
    }
    int bit = LookupModeValueUnlessPackedModeRejected((char*)self, targetId, action->mode);
    if (!bit) return 0;
    unsigned long long mask = 0;
    Combat_SetResultMaskFlag(self->combat, &mask, (unsigned char)bit);
    if (!CombatStatus_CanApplyActionRestriction((A*)target->currentStats_, (unsigned char)action->mode, (unsigned short)action->kind)) return 0;
    if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 0x80000)) {
        if (bit == 18 || bit == 21 || (unsigned)(bit - 27) <= 1)
            Combat_SetResultMaskFlag(self->combat, &mask, 43);
    }
    int hadSuperHigh = Combat_HasSuperHighTension(target);
    int hadOrdinary = Combat_HasOrdinaryTension((LinkedDescriptorView*)target);
    CombatStatus_ApplyActionRestriction((char*)target->currentStats_, (unsigned char)action->mode, (unsigned short)action->kind);
    if (action->category != 10) {
        unsigned message = 0;
        switch (action->mode) {
        case 2: message = 0x150; break;
        case 5: message = 0x5e; break;
        }
        void* result = GameState_CreateAndAppendIndexedRecord(self, message);
        if (result) Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, 0);
    }
    if (hadOrdinary) Combat_QueueTensionLossNotification((char*)self, target, 0, 0);
    else if (hadSuperHigh && !Combat_HasSuperHighTension(target)) Combat_QueueTensionLossNotification((char*)self, target, 8, 0);
    return mask;
}
#pragma force_active reset
