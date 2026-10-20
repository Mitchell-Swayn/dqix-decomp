#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <std_library_functions.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
struct EnemyIds { short values[8]; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*, short*, int, int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(GameObject*);
extern "C" int CombatEffect_TargetHasConfusion(GameObject*);
extern "C" float Combat_GetCurrentHealthFraction(GameObject*);
extern "C" int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*, unsigned, void*, int*, short*);
// Original data: arm9/ov024 @ 0x021feb34; symbol: CombatCopyPartyIdsWhenFlaggedCountBelowOneThird_UnknownRoleInitializedBytes.
// Initial candidate identifier array; values and byte extent are recorded in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCopyPartyIdsWhenFlaggedCountBelowOneThird_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021EE20C; symbol: Combat_CopyPartyIdsWhenFlaggedCountBelowOneThird; size: 0xf0.
// Collects candidate identifiers and applies the status/stage eligibility rule described by this operation.
extern "C" int Combat_CopyPartyIdsWhenFlaggedCountBelowOneThird(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)CombatCopyPartyIdsWhenFlaggedCountBelowOneThird_UnknownRoleInitializedBytes;
    int total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
    if (total <= 0) return 0;
    short flagged[4] = {0};
    unsigned short flaggedCount = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && Combatant_TestPrimaryStatusFlagBit9(object)) flagged[flaggedCount++] = candidates.values[index];
    }
    if (flaggedCount * 3 >= total) return 0;
    *count = total;
    memcpy(output, candidates.values, 8);
    return 1;
}
