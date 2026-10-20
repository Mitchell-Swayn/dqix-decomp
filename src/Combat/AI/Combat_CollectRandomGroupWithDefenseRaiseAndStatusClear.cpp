#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
struct EnemyIds { short values[8]; };
struct ThreeGroups { short values[3]; };
struct EncounterState { unsigned char first; unsigned char memberCount:4, groupCount:2, other:2; };
struct Modifier21 { unsigned reserved:21; signed value:3; unsigned rest:8; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*, short*, int, int);
extern "C" int Combat_CollectEligibleIndicesInEnemyGroup(void*, short*, int, unsigned char, int);
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*, int);
extern "C" int Combatant_TestTargetCapabilityBit2(GameObject*);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(GameObject*);
extern "C" int Combat_HasMonsterActivationCondition(GameObject*);
extern "C" bool GameObject_IsDead(GameObject*);
extern "C" int Combat_HasOrdinaryTension(GameObject*);
extern "C" int Combat_HasSuperHighTension(GameObject*);
extern "C" float Combat_GetCurrentHealthFraction(GameObject*);
extern "C" int Combat_SelectRandomCandidateInPlace(void*, int*, short*);
extern "C" int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*, unsigned, void*, int*, short*);
// Original data: arm9/ov024 @ 0x021fed2c; symbol: CombatCollectRandomGroupWithDefenseRaiseAndStatusClear_UnknownRoleInitializedBytes.
// Candidate identifiers retain their initialized values documented in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCollectRandomGroupWithDefenseRaiseAndStatusClear_UnknownRoleInitializedBytes[];
// Original data: arm9/ov024 @ 0x021FEA1C; symbol: BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes.
// Shared group-list initialization records, with operation-specific offsets below.
extern "C" unsigned char BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021EF1F8; symbol: Combat_CollectRandomGroupWithDefenseRaiseAndStatusClear; size: 0x190.
// Filters the eligible combat targets and applies the corresponding group or random target selection rule.
extern "C" int Combat_CollectRandomGroupWithDefenseRaiseAndStatusClear(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    EncounterState* encounter = (EncounterState*)((char*)self->combat + 0x81b0);
    if (!encounter) return 0;
    ThreeGroups groups = *(ThreeGroups*)(BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes + 0x12);
    short groupCount = 0;
    for (int group = 0; group < encounter->groupCount; ++group) {
        EnemyIds candidates = *(const EnemyIds*)CombatCollectRandomGroupWithDefenseRaiseAndStatusClear_UnknownRoleInitializedBytes;
        int total = Combat_CollectEligibleIndicesInEnemyGroup(self->combat, candidates.values, 8, (unsigned char)group, 1);
        if (total <= 0) continue;
        short eligible = 0;
        for (int index = 0; index < total; ++index) {
            GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
            if (object && object->currentStats_->primaryStats.defense < 65535 && object->currentStats_->defenseBuff < 2 && !Combatant_TestPrimaryStatusFlagBit9(object)) ++eligible;
        }
        if (eligible > 0) groups.values[groupCount++] = group;
    }
    if (groupCount <= 0) return 0;
    int selected = NextRandomMax((Random*)self->combat, groupCount);
    *count = Combat_CollectEligibleIndicesInEnemyGroup(self->combat, output, 8, (unsigned char)groups.values[selected], 1);
    return 1;
}
