#include <globaldefs.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
ARM
struct BattleAIContext { void* combat; };
struct PartyIds { short values[4]; };
extern "C" int Combat_CollectEligiblePartyIds(void*, short*, int, int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*, int*, short*);
extern "C" int CombatEffect_TargetHasFizzle(GameObject*);
extern "C" int CombatEffect_TargetHasConfusion(GameObject*);
// Original data: arm9/ov024 @ 0x021FEA7C; original symbol retained in config symbols.
// Four initialized halfword candidate identifiers; initial bytes ffff000000000000.
extern "C" unsigned char BattleAISelectRandomPartyMemberWithMp_UnknownRoleInitializedBytes[];
// Original: arm9/ov024 @ 0x021F559C; symbol: BattleAI_SelectRandomPartyMemberWithMp; size: 0xe0.
// Filters eligible party candidates, then chooses one candidate at random.
extern "C" int BattleAI_SelectRandomPartyMemberWithMp(BattleAIContext* self, int unusedActor, void* unusedAction, int* count, short* output)
{
    PartyIds candidates = *(const PartyIds*)BattleAISelectRandomPartyMemberWithMp_UnknownRoleInitializedBytes;
    int total = Combat_CollectEligiblePartyIds(self->combat, candidates.values, 4, 1);
    if (total <= 0) return 0;
    *count = 0;
    for (int index = 0; index < total; ++index) {
        GameObject* object = GetCombatantByID((int)self->combat, candidates.values[index]);
        if (object && object->currentStats_->primaryStats.currMP != 0) {
            int destination = (*count)++;
            output[destination] = candidates.values[index];
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectRandomCandidateInPlace(self, count, output);
    return 1;
}
