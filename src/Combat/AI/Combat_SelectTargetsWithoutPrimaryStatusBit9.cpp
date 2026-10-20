#include <globaldefs.h>
extern "C" int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern "C" int Combat_CollectEligiblePartyIds(int, short*, int, int);
extern "C" int Combat_SelectWeightedTargetCountFromPackedMode(void*, int, int, int*, short*);
extern "C" char* _Z16GetCombatantByIDii(int, int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
struct FourCandidates { short ids[4]; };
// Original data: arm9/ov024 @ 0x21fea84; symbol: data_ov024_021fea84.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" FourCandidates CombatSelectTargetsWithoutPrimaryStatusBit9_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021EE0F0; symbol: Combat_FilterTargetsWithoutRecordFlag200AndApplySelection; size: 0x11c.
// Filters candidate combatants by record flag 0x200 and dispatches the surviving target list.
extern "C" ARM int Combat_SelectTargetsWithoutPrimaryStatusBit9(void* self, int kind, int argument, int* count, short* output) {
    FourCandidates candidates = CombatSelectTargetsWithoutPrimaryStatusBit9_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, kind, candidates.ids);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(*(int*)self, candidates.ids, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int i = 0; i < total; ++i) {
        char* actor = _Z16GetCombatantByIDii(*(int*)self, candidates.ids[i]);
        if (actor && !Combatant_TestPrimaryStatusFlagBit9(actor)) {
            output[*count] = candidates.ids[i];
            ++*count;
        }
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, kind, argument, count, output);
    return output[0] >= 0;
}
