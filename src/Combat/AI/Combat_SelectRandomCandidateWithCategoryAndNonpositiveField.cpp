#include <globaldefs.h>
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*, short*, int, int);
extern "C" void* Combat_FindIndexedMonsterObject(void*, int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*, int*, short*);
struct IdList { short values[8]; };
// Original data: arm9/ov024 @ 0x21fedbc; symbol: data_ov024_021fedbc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" IdList CombatSelectRandomCandidateWithCategoryAndNonpositiveField_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F6500; symbol: Combat_SelectRandomCandidateWithCategoryAndNonpositiveField; size: 0xFC.
// Filters eligible combatant ids from a fixed candidate list and selects one at random.
extern "C" ARM int Combat_SelectRandomCandidateWithCategoryAndNonpositiveField(void** self, int unused1, int unused2, int* outputCount, short* output) {
    IdList ids = CombatSelectRandomCandidateWithCategoryAndNonpositiveField_UnknownRoleInitializedBytes;
    int count = Combat_CollectGroupIndicesByDescriptorFlags(*self, ids.values, 8, 1);
    if (count <= 0) return 0;
    *outputCount = 0;
    for (int i = 0; i < count; ++i) {
        void* object = Combat_FindIndexedMonsterObject(*self, ids.values[i]);
        if (object && *(short*)((char*)object + 2) == 0x13a && *(short*)(*(char**)((char*)object + 0x138) + 0x2c) <= 0) {
            output[*outputCount] = ids.values[i];
            *outputCount = *outputCount + 1;
        }
    }
    if (*outputCount <= 0) return 0;
    Combat_SelectRandomCandidateInPlace(self, outputCount, output);
    return 1;
}
