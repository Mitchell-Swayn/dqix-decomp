#include <globaldefs.h>
extern "C" int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern "C" int Combat_CollectEligiblePartyIds(int, short*, int, int);
extern "C" int Combat_SelectWeightedTargetCountFromPackedMode(void*, int, int, int*, short*);
extern "C" char* _Z16GetCombatantByIDii(int, int);
struct FourCandidates { short ids[4]; };
// Original data: arm9/ov024 @ 0x21febf4; symbol: data_ov024_021febf4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" FourCandidates BattleAISelectTargetsAboveMinimumSpellResistance_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F304C; symbol: Combat_FilterCandidatesByRecordField58AndDispatch; size: 0x11c.
// Filters candidates by the packed field at record offset 0x58 and dispatches the surviving list.
extern "C" ARM int BattleAI_SelectTargetsAboveMinimumSpellResistance(void* self, int kind, int argument, int* count, short* output) {
    FourCandidates candidates = BattleAISelectTargetsAboveMinimumSpellResistance_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, kind, candidates.ids);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(*(int*)self, candidates.ids, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int i = 0; i < total; ++i) {
        char* actor = _Z16GetCombatantByIDii(*(int*)self, candidates.ids[i]);
        if (actor) {
            unsigned char* record = *(unsigned char**)(actor + 0x138);
            int field = (int)(*(unsigned int*)(record + 0x58) << 11) >> 29;
            if (field > -2) {
                int slot = *count;
                *count = slot + 1;
                output[slot] = candidates.ids[i];
            }
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, kind, argument, count, output);
    return 1;
}
