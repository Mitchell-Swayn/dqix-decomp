#include <globaldefs.h>
ARM
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(int, short*, int, int);
extern "C" char* _Z16GetCombatantByIDii(int, int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
extern "C" int CombatEffect_TargetHasParalysis(void*);
extern "C" void* memcpy(void*, const void*, unsigned);
struct EightCandidates { short ids[8]; };
// Original data: arm9/ov024 @ 0x21feedc; symbol: data_ov024_021feedc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" EightCandidates CombatCopyEightCandidateIdsWhenAtLeastOneThirdPassFlags_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021EE9B4; symbol: Combat_CopyEightCandidateIdsWhenAtLeastOneThirdPassFlags; size: 0x104.
// Copies the eight candidate IDs when at least one third pass the record and linked-descriptor tests.
extern "C" int Combat_CopyEightCandidateIdsWhenAtLeastOneThirdPassFlags(int* self, int unused1, int unused2, int* outputCount, short* output) {
    EightCandidates candidates = CombatCopyEightCandidateIdsWhenAtLeastOneThirdPassFlags_UnknownRoleInitializedBytes;
    int count = Combat_CollectGroupIndicesByDescriptorFlags(*self, candidates.ids, 8, 1);
    if (count <= 0) return 0;
    *outputCount = 0;
    for (int i = 0; i < count; ++i) {
        char* object = _Z16GetCombatantByIDii(*self, candidates.ids[i]);
        if (object && !Combatant_TestPrimaryStatusFlagBit9(object) && CombatEffect_TargetHasParalysis(object))
            output[(*outputCount)++] = candidates.ids[i];
    }
    if (*outputCount <= 0) return 0;
    if (*outputCount * 3 < count) return 0;
    *outputCount = count;
    memcpy(output, candidates.ids, 16);
    return 1;
}
