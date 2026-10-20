#include <globaldefs.h>
ARM
extern "C" int Combat_TryGetLinkedLivingTargetId(void *, unsigned, short *);
extern "C" int Combat_CollectEligiblePartyIds(unsigned, short *, unsigned, unsigned);
extern "C" void *_Z16GetCombatantByIDii(int, int);
extern "C" void Combat_SelectWeightedTargetCountFromPackedMode(void *, unsigned, unsigned, int *, short *);
// Original data: arm9/ov024 @ 0x21fea9c; symbol: data_ov024_021fea9c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned short CombatFilterAndDispatchEligibleCombatants_UnknownRoleInitializedBytes[4];
// Original: arm9/ov024 @ 0x021F23E0; symbol: Combat_FilterAndDispatchEligibleCombatants; size: 0x11C.
extern "C" int Combat_FilterAndDispatchEligibleCombatants(void *self, unsigned filter, unsigned mode, int *count, short *output) {
    short ids[4];
    short *destination = ids;
    unsigned short *source = CombatFilterAndDispatchEligibleCombatants_UnknownRoleInitializedBytes;
    int remaining = 4;
    do { unsigned short value = *source; *destination = value; ++source; ++destination; --remaining; } while (remaining != 0);
    int candidateCount = Combat_TryGetLinkedLivingTargetId(self, filter, ids);
    if (candidateCount > 0) {
    } else {
        candidateCount = Combat_CollectEligiblePartyIds(*(unsigned *)self, ids, 4, 1);
        if (candidateCount <= 0) return 0;
    }
    *count = 0;
    for (int i = 0; i < candidateCount; ++i) {
        void *combatant = _Z16GetCombatantByIDii(*(int *)self, ids[i]);
        if (!combatant) continue;
        int value = *(int *)(*(char **)((char *)combatant + 0x138) + 0x58);
        if (-2 >= ((value << 11) >> 29)) continue;
        int oldCount = *count;
        *count = oldCount + 1;
        output[oldCount] = ids[i];
    }
    if (*count <= 0) return 0;
    Combat_SelectWeightedTargetCountFromPackedMode(self, filter, mode, count, output);
    return 1;
}
