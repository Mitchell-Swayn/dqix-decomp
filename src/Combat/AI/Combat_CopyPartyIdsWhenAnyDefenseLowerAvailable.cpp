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
// Original data: arm9/ov024 @ 0x021feb6c; symbol: CombatCopyPartyIdsWhenAnyDefenseLowerAvailable_UnknownRoleInitializedBytes.
// Initial candidate identifier array; values and byte extent are recorded in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCopyPartyIdsWhenAnyDefenseLowerAvailable_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021EF5EC; symbol: Combat_CopyPartyIdsWhenAnyDefenseLowerAvailable; size: 0xd8.
// Collects candidate identifiers and applies the status/stage eligibility rule described by this operation.
extern "C" int Combat_CopyPartyIdsWhenAnyDefenseLowerAvailable(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)CombatCopyPartyIdsWhenAnyDefenseLowerAvailable_UnknownRoleInitializedBytes;
    int total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
    if (total <= 0) return 0;
    int found = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && object->currentStats_->primaryStats.defense != 0 && object->currentStats_->defenseBuff > -2) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *count = total;
    memcpy(output, candidates.values, 8);
    return 1;
}
