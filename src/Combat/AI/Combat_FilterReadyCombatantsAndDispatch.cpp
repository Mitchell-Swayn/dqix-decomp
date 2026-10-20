#include <globaldefs.h>
ARM
extern "C" int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern "C" int Combat_CollectEligiblePartyIds(int, short*, int, int);
extern "C" void* _Z16GetCombatantByIDii(int, int);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void*, unsigned, void*, int*, short*);
// Original data: arm9/ov024 @ 0x21feac4; symbol: data_ov024_021feac4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned short CombatFilterReadyCombatantsAndDispatch_UnknownRoleInitializedBytes[4];
struct FourIds { short value[4]; };
// Original: arm9/ov024 @ 0x021EFCD8; symbol: Combat_FilterReadyCombatantsAndDispatch; size: 0x124.
// Filters the preferred four combatant IDs by nested record readiness and packed field 0x58.
extern "C" int Combat_FilterReadyCombatantsAndDispatch(void* self, int filter, void* descriptor, int* count, short* output) {
    FourIds ids = *(FourIds*)CombatFilterReadyCombatantsAndDispatch_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, filter, ids.value);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(*(int*)self, ids.value, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int i = 0; i < total; ++i) {
        void* actor = _Z16GetCombatantByIDii(*(int*)self, ids.value[i]);
        if (!actor) continue;
        void* record = *(void**)((char*)actor + 0x138);
        if (*(unsigned short*)((char*)record + 0x0C) == 0) continue;
        int field = (*(int*)((char*)record + 0x58) << 23) >> 29;
        if (field <= -2) continue;
        int slot = *count;
        *count = slot + 1;
        output[slot] = ids.value[i];
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, (unsigned)filter, descriptor, count, output);
    return 1;
}
