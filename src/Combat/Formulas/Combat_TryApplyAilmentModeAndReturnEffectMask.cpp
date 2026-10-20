#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x14]; unsigned monsterChance:7, partyChance:7, rest14:18; char padding[0x32 - 0x18]; short mode; };
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
extern "C" bool CombatStatus_CanApplyAilmentModeTwo(unsigned*);
extern "C" int CombatStatus_CanApplyAilmentModeOne(A*);
extern "C" void CombatStatus_ApplyAilmentModeTwo(char*);
extern "C" void CombatStatus_ApplyAilmentModeOne(unsigned char*);
extern "C" int Combat_SelectAilmentModeMessage(char*,int,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E303C; symbol: func_ov024_021e303c; size: 0x210.
// Applies chance-scaled ailment mode, appends feedback with an empty result mask and
// returns the accumulated replacement/ailment flags to the secondary dispatcher.
extern "C" unsigned long long Combat_TryApplyAilmentModeAndReturnEffectMask(CombatActionState* self,int actorId,int targetId,ActionDefinition* action,int amount)
{
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    if (!((unsigned char*)target->currentStats_)[0x4d]) return 0;
    if (action->mode > 0) {
        if (!CombatStatus_CanApplyAilmentModeTwo((unsigned*)target->currentStats_)) return 0;
    } else {
        if (!CombatStatus_CanApplyAilmentModeOne((A*)target->currentStats_)) return 0;
    }
    int sample = NextRandomMax((Random*)self->combat, 100);
    float chance = 100.0f;
    if (!self->flags->enabled) {
        if (IsPartyIndex(actorId)) chance = (float)action->partyChance;
        else chance = (float)action->monsterChance;
        chance *= (float)(unsigned)((unsigned char*)target->currentStats_)[0x4d] / 100.0f;
    }
    int modeTwo = 0;
    if (action->mode > 0) modeTwo = 1;
    if ((float)sample >= chance) return 0;
    int message = Combat_SelectAilmentModeMessage((char*)self, targetId, modeTwo, 1);
    unsigned long long mask = 0;
    if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 2))
        Combat_SetResultMaskFlag(self->combat, &mask, 43);
    if (modeTwo) CombatStatus_ApplyAilmentModeTwo((char*)target->currentStats_);
    else CombatStatus_ApplyAilmentModeOne((unsigned char*)target->currentStats_);
    Combat_SetResultMaskFlag(self->combat, &mask, 15);
    void* result = GameState_CreateAndAppendIndexedRecord(self, message);
    if (result) Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, 0);
    return mask;
}
#pragma force_active reset
