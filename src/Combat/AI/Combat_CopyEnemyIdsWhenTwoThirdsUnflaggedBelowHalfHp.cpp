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
// Original data: arm9/ov024 @ 0x021fecac; symbol: CombatCopyEnemyIdsWhenTwoThirdsUnflaggedBelowHalfHp_UnknownRoleInitializedBytes.
// Initial candidate identifier array; values and byte extent are recorded in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCopyEnemyIdsWhenTwoThirdsUnflaggedBelowHalfHp_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021EE7A4; symbol: Combat_CopyEnemyIdsWhenTwoThirdsUnflaggedBelowHalfHp; size: 0x110.
// Collects candidate identifiers and applies the status/stage eligibility rule described by this operation.
extern "C" int Combat_CopyEnemyIdsWhenTwoThirdsUnflaggedBelowHalfHp(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    EnemyIds candidates = *(const EnemyIds*)CombatCopyEnemyIdsWhenTwoThirdsUnflaggedBelowHalfHp_UnknownRoleInitializedBytes;
    int total = Combat_CollectGroupIndicesByDescriptorFlags(self->combat, candidates.values, 8, 1);
    if (total <= 0) return 0;
    *count = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && !Combatant_TestPrimaryStatusFlagBit9(object) && !(Combat_GetCurrentHealthFraction(object) >= 0.5f)) {
            output[*count] = candidates.values[index];
            ++*count;
        }
    }
    if (*count <= 0) return 0;
    if (*count * 3 < total * 2) return 0;
    *count = total;
    memcpy(output, candidates.values, 16);
    return 1;
}
