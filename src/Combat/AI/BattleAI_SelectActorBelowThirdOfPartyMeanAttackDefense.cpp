#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
// Original data: arm9/ov024 @ 0x021FEC54; symbol: BattleAISelectActorBelowThirdOfPartyMeanAttackDefense_UnknownRoleInitializedBytes.
extern "C" unsigned char BattleAISelectActorBelowThirdOfPartyMeanAttackDefense_UnknownRoleInitializedBytes[];
inline unsigned ReadBaseAttack(GameObject* object)
{
    return object->baseStats_->primaryStats.attack;
}
inline unsigned ReadBaseDefense(GameObject* object)
{
    return object->baseStats_->primaryStats.defense;
}
inline int ReadBaseAttackDefenseSum(GameObject* object)
{
    unsigned defense = ReadBaseDefense(object);
    unsigned attack = ReadBaseAttack(object);
    return attack + defense;
}
#pragma force_active on
// Original: arm9/ov024 @ 0x021F418C; symbol: func_ov024_021f418c; size: 0x108.
// Selects the actor when three times its base attack-plus-defense does not exceed the party mean.
extern "C" int BattleAI_SelectActorBelowThirdOfPartyMeanAttackDefense(BattleAIContext* self, int actor, void* action, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)BattleAISelectActorBelowThirdOfPartyMeanAttackDefense_UnknownRoleInitializedBytes;
    int total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 0);
    if (total <= 0) return 0;
    GameObject* source = GetCombatantByID((int)self->combat, actor);
    if (!source) return 0;
    unsigned short sourceStrength = ReadBaseAttackDefenseSum(source);
    unsigned short sum = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object) sum += ReadBaseAttackDefenseSum(object);
    }
    if (sum / total < sourceStrength * 3) return 0;
    *count = 1;
    output[0] = actor;
    return 1;
}

#pragma force_active reset
