#include <globaldefs.h>
ARM
struct FourIds { short value[4]; };
extern "C" {
// Original data: arm9/ov024 @ 0x21fea4c; symbol: data_ov024_021fea4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern unsigned short CombatFilterPreferredDescriptorTargetsAndDispatch_UnknownRoleInitializedBytes[4];
extern int Combat_TryGetLinkedLivingTargetId(void*, int, short*);
extern int Combat_CollectEligiblePartyIds(int, short*, int, unsigned);

extern int Combat_HasMonsterActivationCondition(unsigned char*);
extern void Combat_SelectWeightedTargetCountFromPackedMode(void*, int, int, int*, short*);
}
// Original: arm9/ov024 @ 0x021F2998; symbol: Combat_FilterPreferredDescriptorTargetsAndDispatch; size: 0x11c.
// Collects the preferred four IDs, filters combatants by descriptor state, and
// dispatches the filtered list when at least one candidate remains.
extern void* GetCombatantByID(int,int);
extern "C" int Combat_FilterPreferredDescriptorTargetsAndDispatch(void* self, int descriptor, int mode, int* count, short* output) {
    FourIds ids = *(const FourIds*)CombatFilterPreferredDescriptorTargetsAndDispatch_UnknownRoleInitializedBytes;
    int total = Combat_TryGetLinkedLivingTargetId(self, descriptor, ids.value);
    if (total <= 0) {
        total = Combat_CollectEligiblePartyIds(*(int*)self, ids.value, 4, 1);
        if (total <= 0) return 0;
    }
    *count = 0;
    for (int i = 0; i < total; ++i) {
        void* combatant = GetCombatantByID(*(int*)self, ids.value[i]);
        if (!combatant) continue;
        if (!Combat_HasMonsterActivationCondition((unsigned char*)combatant)) continue;
        short linked = *(short*)(*(int*)((char*)combatant + 0x138) + 0x2e);
        if (descriptor == linked) continue;
        int n = *count;
        *count = n + 1;
        output[n] = ids.value[i];
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, descriptor, mode, count, output);
    return 1;
}
