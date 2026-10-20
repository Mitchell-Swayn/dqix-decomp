#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*, int*, short*);
extern "C" int CombatEffect_TargetHasFizzle(GameObject*);
extern "C" int CombatEffect_TargetHasConfusion(GameObject*);
struct ActionDescriptor {
 unsigned first;
 unsigned id:12, otherIdBits:20;
 unsigned padding[4];
 unsigned beforeKind:5, kind:7, otherKindBits:20;
};
struct EncounterState { unsigned char first; unsigned char count:4, other:4; };
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" void* CombatScene_FindAuxiliaryObjectByIdentifier(unsigned char*, int);
extern "C" int Combat_GetActionSummonedSpecies(int, int, int*);
// Original data: arm9/ov024 @ 0x021FEA1C; symbol retained in config symbols.
// Table includes two-word temporary species buffers at offsets 0xf0 and 0x128.
extern "C" unsigned char BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021F58DC; symbol: BattleAI_SelectActorWhenEncounterCountBelowTwo; size: 0xe0.
// Selects the actor when encounter capacity allows the action and summoned species are available.
extern "C" int BattleAI_SelectActorWhenEncounterCountBelowTwo(BattleAIContext* self, short actor, ActionDescriptor* action, int* count, short* output)
{
    unsigned scene;
    EncounterState* encounter = (EncounterState*)((char*)self->combat + 0x81b0);
    if (!encounter) return 0;
    scene = BattleScene_GetActiveInstance();
    if (!scene) return 0;
    if (action->kind == 12) {
        struct SpeciesPair { int values[2]; };
        SpeciesPair pair;
        pair.values[1] = *(int*)(BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes + 0xf0 + 4);
        pair.values[0] = *(int*)(BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes + 0xf0);
        int total = Combat_GetActionSummonedSpecies((int)self->combat, action->id, pair.values);
        for (int index = 0; index < total; ++index) {
            if (!CombatScene_FindAuxiliaryObjectByIdentifier((unsigned char*)scene, pair.values[index])) return 0;
        }
    }
    if (encounter->count >= 2) return 0;
    *count = 1;
    *output = actor;
    return 1;
}
