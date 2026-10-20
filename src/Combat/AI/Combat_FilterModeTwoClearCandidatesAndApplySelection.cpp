#include <globaldefs.h>
ARM
extern "C" int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern "C" int Combat_CollectEligiblePartyIds(int, short*, int, int);
extern "C" int Combat_SelectWeightedTargetCountFromPackedMode(void*, int, int, int*, short*);
extern "C" char* _Z16GetCombatantByIDii(int, int);
extern "C" int CombatStatus_HasAilmentModeTwo(void*);
struct FourCandidates { short ids[4]; };
// Original data: arm9/ov024 @ 0x21fec2c; symbol: data_ov024_021fec2c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" FourCandidates CombatFilterModeTwoClearCandidatesAndApplySelection_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F18FC; symbol: Combat_FilterModeTwoClearCandidatesAndApplySelection; size: 0x110.
// Filters preferred or fallback candidate IDs by the mode-two predicate, then applies the selection request.
extern "C" int Combat_FilterModeTwoClearCandidatesAndApplySelection(void* self, int kind, int argument, int* count, short* output) {
    FourCandidates ids = CombatFilterModeTwoClearCandidatesAndApplySelection_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, kind, ids.ids);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(*(int*)self, ids.ids, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int i = 0; i < total; ++i) {
        char* object = _Z16GetCombatantByIDii(*(int*)self, ids.ids[i]);
        if (object && !CombatStatus_HasAilmentModeTwo(*(void**)(object + 0x138)))
            output[(*count)++] = ids.ids[i];
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, kind, argument, count, output);
    return 1;
}
