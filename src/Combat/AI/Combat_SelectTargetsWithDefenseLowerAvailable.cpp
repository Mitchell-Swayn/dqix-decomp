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
// Original data: arm9/ov024 @ 0x021febbc; symbol: CombatSelectTargetsWithDefenseLowerAvailable_UnknownRoleInitializedBytes.
// Initial candidate identifier array; values and byte extent are recorded in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatSelectTargetsWithDefenseLowerAvailable_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021EF388; symbol: Combat_SelectTargetsWithDefenseLowerAvailable; size: 0x124.
// Collects candidate identifiers and applies the status/stage eligibility rule described by this operation.
extern "C" int Combat_SelectTargetsWithDefenseLowerAvailable(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)CombatSelectTargetsWithDefenseLowerAvailable_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, actor, candidates.values);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && object->currentStats_->primaryStats.defense != 0 && object->currentStats_->defenseBuff > -2) {
            int destination = (*count)++;
            output[destination] = candidates.values[index];
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, actor, action, count, output);
    return 1;
}
