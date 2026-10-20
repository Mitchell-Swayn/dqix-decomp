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
// Original data: arm9/ov024 @ 0x021fecfc; symbol: CombatSelectRandomOtherUnlinkedEnemyBelowHalfHp_UnknownRoleInitializedBytes.
// Candidate identifiers retain their initialized values documented in docs/data-symbols/ov024.md.
extern "C" unsigned char CombatSelectRandomOtherUnlinkedEnemyBelowHalfHp_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021F286C; symbol: Combat_SelectRandomOtherUnlinkedEnemyBelowHalfHp; size: 0x12c.
// Filters the eligible combat targets and applies the corresponding group or random target selection rule.
extern "C" int Combat_SelectRandomOtherUnlinkedEnemyBelowHalfHp(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    GameObject* source = Combat_FindIndexedMonsterObject(self->combat, actor);
    if (!source) return 0;
    if (Combat_GetCurrentHealthFraction(source) < 0.5f) return 0;
    EnemyIds candidates = *(const EnemyIds*)CombatSelectRandomOtherUnlinkedEnemyBelowHalfHp_UnknownRoleInitializedBytes;
    int total = Combat_CollectGroupIndicesByDescriptorFlags(self->combat, candidates.values, 8, 1);
    if (total <= 0) return 0;
    *count = 0;
    for (int index = 0; index < total; ++index) {
        if (actor == candidates.values[index]) continue;
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && *(short*)((char*)object->currentStats_ + 0x2c) < 0 && !(Combat_GetCurrentHealthFraction(object) >= 0.5f)) {
            int destination = (*count)++;
            output[destination] = candidates.values[index];
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectRandomCandidateInPlace(self, count, output);
    return 1;
}
