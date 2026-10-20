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
// Original data: arm9/ov024 @ 0x021febcc; symbol: CombatCopyPartyIdsWhenTwoThirdsStatusBit5ClearReady_UnknownRoleInitializedBytes.
// Initial candidate identifier array; values and byte extent are recorded in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCopyPartyIdsWhenTwoThirdsStatusBit5ClearReady_UnknownRoleInitializedBytes[];
#pragma always_inline on
inline int ReadReadinessCounter(GameObject* object)
{
    return *((unsigned char*)object->currentStats_ + 0x4a);
}
// Original: arm9/ov024 @ 0x021F063C; symbol: Combat_CopyPartyIdsWhenTwoThirdsStatusBit5ClearReady; size: 0xe4.
// Collects candidate identifiers and applies the status/stage eligibility rule described by this operation.
extern "C" int Combat_CopyPartyIdsWhenTwoThirdsStatusBit5ClearReady(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)CombatCopyPartyIdsWhenTwoThirdsStatusBit5ClearReady_UnknownRoleInitializedBytes;
    int total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
    if (total <= 0) return 0;
    int ready = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && !CombatEffect_TargetHasConfusion(object) && !Combatant_TestPrimaryStatusFlagBit9(object) && ReadReadinessCounter(object) > 0) ++ready;
    }
    if (ready * 3 < total * 2) return 0;
    *count = total;
    memcpy(output, candidates.values, 8);
    return 1;
}
