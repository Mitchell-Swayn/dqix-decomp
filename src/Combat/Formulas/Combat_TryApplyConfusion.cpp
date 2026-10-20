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
extern "C" bool CombatStatus_CanApplyConfusion(unsigned*);
extern "C" void CombatStatus_ApplyConfusion(char*);
extern "C" int Combat_SelectConfusionMessage(char*,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E386C; symbol: func_ov024_021e386c; size: 0x1c8.
// Applies chance-scaled confusion, appends feedback with an empty result mask and
// returns the accumulated replacement/confusion flags to the secondary dispatcher.
extern "C" unsigned long long Combat_TryApplyConfusion(CombatActionState* self,int actorId,int targetId,ActionDefinition* action,int amount)
{
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    if (!((unsigned char*)target->currentStats_)[0x4a]) return 0;
    if (!CombatStatus_CanApplyConfusion((unsigned*)target->currentStats_)) return 0;
    int sample = NextRandomMax((Random*)self->combat, 100);
    float chance = 100.0f;
    if (!self->flags->enabled) {
        if (IsPartyIndex(actorId)) chance = (float)action->partyChance;
        else chance = (float)action->monsterChance;
        chance *= (float)(unsigned)((unsigned char*)target->currentStats_)[0x4a] / 100.0f;
    }
    if ((float)sample >= chance) return 0;
    int message = Combat_SelectConfusionMessage((char*)self, targetId, 1);
    unsigned long long mask = 0;
    if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 0x20))
        Combat_SetResultMaskFlag(self->combat, &mask, 43);
    CombatStatus_ApplyConfusion((char*)target->currentStats_);
    Combat_SetResultMaskFlag(self->combat, &mask, 23);
    void* result = GameState_CreateAndAppendIndexedRecord(self, message);
    if (result) Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, 0);
    return mask;
}
#pragma force_active reset
