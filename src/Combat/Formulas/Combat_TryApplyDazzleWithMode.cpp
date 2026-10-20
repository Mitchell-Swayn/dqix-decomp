#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
namespace {
struct ActionDefinition { char prefix[0x14]; unsigned monsterChance:7, partyChance:7, rest14:18; char padding[0x32 - 0x18]; short mode; };
struct ModeField { unsigned short low:6, mode:3, high:7; };
struct CombatActionState { char prefix[0x10]; unsigned char* combat; };
#pragma always_inline on
inline bool IsPartyIndex(int index) {
    bool party;
    if (index >= 0 && index <= 3) party = true;
    else party = false;
    return party;
}
}
extern "C" bool CombatStatus_CanApplyDazzle(unsigned*);
extern "C" void CombatStatus_ApplyDazzle(char*);
extern "C" int Combat_SelectTimedConditionModeMessage(void*,int,int,int);
extern "C" int Combat_CanReplaceAilmentFlags(void*,unsigned,unsigned);
extern "C" void Combat_SetResultMaskFlag(void*,unsigned long long*,unsigned);
extern "C" void* GameState_CreateAndAppendIndexedRecord(void*,unsigned);
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void*,void*,void*,int,unsigned long long,unsigned char);
#pragma force_active on
// Original: arm9/ov024 @ 0x021E43E0; symbol: func_ov024_021e43e0; size: 0x1a8.
// Attempts resistance-scaled dazzle and records feedback. The original local mask
// is updated on replacement, but the appended result and return value both use zero.
extern "C" unsigned long long Combat_TryApplyDazzleWithMode(CombatActionState* self,int actorId,int targetId,ActionDefinition* action,int amount)
{
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->combat, targetId);
    if (!target) return 0;
    int sample = NextRandomMax((Random*)self->combat, 100);
    float chance;
    if (IsPartyIndex(actorId)) chance = (float)action->partyChance;
    else chance = (float)action->monsterChance;
    chance *= (float)(unsigned)((unsigned char*)target->currentStats_)[0x46] / 100.0f;
    int message = 0;
    unsigned long long mask = 0;
    int mode = action->mode;
    if (CombatStatus_CanApplyDazzle((unsigned*)target->currentStats_) && (float)sample < chance) {
        message = Combat_SelectTimedConditionModeMessage(self, targetId, (short)mode, 1);
        if (!message) message = 0xf5;
        if (Combat_CanReplaceAilmentFlags(self, *(unsigned*)((unsigned char*)target->currentStats_ + 0x14), 0x40))
            Combat_SetResultMaskFlag(self->combat, &mask, 43);
        CombatStatus_ApplyDazzle((char*)target->currentStats_);
        ((ModeField*)((unsigned char*)target->currentStats_ + 0x22))->mode = (unsigned char)mode;
    }
    void* result = GameState_CreateAndAppendIndexedRecord(self, message);
    if (result) Combat_PopulateResultWithCurrentHealthAndMagic(self->combat, result, target, 0, 0, 0);
    return 0;
}
#pragma force_active reset
