#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
struct EnemyIds { short values[8]; };
struct ActionDescriptor { unsigned first; unsigned id:12, otherId:20; unsigned pad[4]; unsigned beforeKind:5, kind:7, otherKind:20; };
struct EncounterState { unsigned char first; unsigned char memberCount:4, groupCount:2, other:2; };
struct EnemyGroup { char first[4]; unsigned short species; unsigned char indices[8]; unsigned char memberCount:4, deadCount:4; char rest[9]; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
extern "C" int Combat_CollectMonsterTargetsInGroup(void*, short*, int, int, int);
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*, int);
extern "C" bool GameObject_IsDead(GameObject*);
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" void* CombatScene_FindAuxiliaryObjectByIdentifier(unsigned char*, int);
extern "C" int Combat_GetActionSummonedSpecies(int, int, int*);
// Original data: arm9/ov024 @ 0x021FECEC; symbol: CombatCollectEnemyTargetsWithDeadMemberQuota_UnknownRoleInitializedBytes.
extern "C" unsigned char CombatCollectEnemyTargetsWithDeadMemberQuota_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021EECC8; symbol: Combat_CollectEnemyTargetsWithDeadMemberQuota; size: 0x1a0.
// Applies the named encounter or party-strength eligibility rule to the candidate list.
extern "C" int Combat_CollectEnemyTargetsWithDeadMemberQuota(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    EncounterState* encounter = (EncounterState*)((char*)self->combat + 0x81b0);
    if (!encounter) return 0;
    int dead = 0;
    int available = 0;
    for (int group = 0; group < encounter->groupCount; ++group) {
        EnemyGroup* record = &((EnemyGroup*)encounter)[group];
        dead += record->deadCount;
        EnemyIds candidates = *(const EnemyIds*)CombatCollectEnemyTargetsWithDeadMemberQuota_UnknownRoleInitializedBytes;
        available += Combat_CollectMonsterTargetsInGroup(self->combat, candidates.values, 8, group, 0);
    }
    if (dead >= 5) return 0;
    if (available > 5) available = 5;
    if (available < dead * 2) return 0;
    *count = 0;
    int quota = available - dead;
    for (int group = 0; group < encounter->groupCount; ++group) {
        EnemyGroup* record = &((EnemyGroup*)encounter)[group];
        for (int index = 0; index < record->memberCount; ++index) {
            int id = record->indices[index] + 0xc0;
            GameObject* object = GetCombatantByID((int)self->combat, (short)id);
            if (!object || (*(unsigned*)((char*)object->currentStats_ + 0x18) & 0x2000)) continue;
            if (GameObject_IsDead(object)) {
                if (quota > 0) {
                    --quota;
                    output[(*count)++] = id;
                }
            } else output[(*count)++] = id;
            if (*count >= 5) break;
        }
    }
    return 1;
}
