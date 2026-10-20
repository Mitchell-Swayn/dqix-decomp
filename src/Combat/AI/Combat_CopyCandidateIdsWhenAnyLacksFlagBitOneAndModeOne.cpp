#include <globaldefs.h>
ARM
extern "C" int Combat_CollectEligiblePartyIds(int, short*, int, int);
extern "C" char* _Z16GetCombatantByIDii(int, int);
extern "C" int Combat_TestFlaggedCandidatesBelowOneThird(int*);
extern "C" int CombatStatus_HasAilmentModeOne(void*);
extern "C" void* memcpy(void*, const void*, unsigned);
struct FourCandidates { short ids[4]; };
// Original data: arm9/ov024 @ 0x21fec3c; symbol: data_ov024_021fec3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" FourCandidates CombatCopyCandidateIdsWhenAnyLacksFlagBitOneAndModeOne_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F43B0; symbol: Combat_CopyCandidateIdsWhenAnyLacksFlagBitOneAndModeOne; size: 0xFC.
// Copies the candidate IDs when the descriptor threshold passes and at least one candidate lacks the combined record flag/mode predicate.
extern "C" int Combat_CopyCandidateIdsWhenAnyLacksFlagBitOneAndModeOne(int* self, int unused1, int unused2, int* outputCount, short* output) {
    FourCandidates candidates = CombatCopyCandidateIdsWhenAnyLacksFlagBitOneAndModeOne_UnknownRoleInitializedBytes;
    int count = Combat_CollectEligiblePartyIds(*self, candidates.ids, 4, 1);
    if (count <= 0) return 0;
    if (!Combat_TestFlaggedCandidatesBelowOneThird(self)) return 0;
    *outputCount = 0;
    for (int i = 0; i < count; ++i) {
        char* object = _Z16GetCombatantByIDii(*self, candidates.ids[i]);
        if (object && !CombatStatus_HasAilmentModeOne(*(void**)(object + 0x138)))
            output[(*outputCount)++] = candidates.ids[i];
    }
    if (*outputCount <= 0) return 0;
    *outputCount = count;
    memcpy(output, candidates.ids, 8);
    return 1;
}
