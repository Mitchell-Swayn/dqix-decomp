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
// Original data: arm9/ov024 @ 0x021fea54; symbol: BattleAISelectTargetsWithAttackStageAboveMinimum_UnknownRoleInitializedBytes.
// Initial candidate identifier array; values and byte extent are recorded in docs/data-symbols/ov024.md.
extern "C" unsigned char BattleAISelectTargetsWithAttackStageAboveMinimum_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021F2C30; symbol: BattleAI_SelectTargetsWithAttackStageAboveMinimum; size: 0x11c.
// Collects candidate identifiers and applies the status/stage eligibility rule described by this operation.
extern "C" int BattleAI_SelectTargetsWithAttackStageAboveMinimum(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)BattleAISelectTargetsWithAttackStageAboveMinimum_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, actor, candidates.values);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && object->currentStats_->attackBuff > -2) {
            int destination = (*count)++;
            output[destination] = candidates.values[index];
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, actor, action, count, output);
    return 1;
}
