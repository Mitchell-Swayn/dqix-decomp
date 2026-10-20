#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*, int*, short*);
extern "C" int CombatEffect_TargetHasFizzle(GameObject*);
extern "C" int CombatEffect_TargetHasConfusion(GameObject*);
// Original data: arm9/ov024 @ 0x021FEB1C; original symbol retained in config symbols.
// Four initialized halfword candidate identifiers; initial bytes ffff000000000000.
extern "C" unsigned char BattleAISelectRandomPartyMemberWithTension_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021F57A8; symbol: BattleAI_SelectRandomPartyMemberWithTension; size: 0xe0.
// Filters eligible party candidates, then chooses one candidate at random.
extern "C" int BattleAI_SelectRandomPartyMemberWithTension(BattleAIContext* self, int unusedActor, void* unusedAction, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)BattleAISelectRandomPartyMemberWithTension_UnknownRoleInitializedBytes;
    int total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
    if (total <= 0) return 0;
    *count = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && *((unsigned char*)object->currentStats_ + 0x24) != 0) {
            int destination = (*count)++;
            output[destination] = candidates.values[index];
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectRandomCandidateInPlace(self, count, output);
    return 1;
}
