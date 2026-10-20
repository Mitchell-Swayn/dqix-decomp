#include <globaldefs.h>
#include <Util/Random.h>

ARM
// Original data: arm9/ov024 @ 0x21fea1c; symbol: data_ov024_021fea1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff00000000ffff00000000ffff00000000ffff00000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes[];
// Original data: arm9/ov024 @ 0x21fed6c; symbol: data_ov024_021fed6c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCollectMembersFromRandomQualifiedGroupByModeField_UnknownRoleInitializedBytes[];
extern "C" char *_Z16GetCombatantByIDii(int, int);
extern "C" int Combat_CollectEligibleIndicesInEnemyGroup(void *, short *, int, unsigned char, int);
extern "C" int _Z13NextRandomMaxP6Randomi(void *, int);
// Original: arm9/ov024 @ 0x021EF9C4; symbol: func_ov024_021ef9c4; size: 0x184.
// Selects a group containing an eligible combatant and collects that group's members.
int Combat_CollectMembersFromRandomQualifiedGroupByModeField(void **self, int unused1,
                                                   int unused2, int *countOut,
                                                   short *output)
{
    volatile unsigned char *groupState =
        (volatile unsigned char *)((char *)*self + 0x81b0);
    if (!groupState)
        return 0;

    unsigned short groupCandidates[3];
    groupCandidates[0] = *(unsigned short *)(BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes + 0);
    groupCandidates[1] = *(unsigned short *)(BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes + 2);
    groupCandidates[2] = *(unsigned short *)(BattleAISelectActorWhenEncounterCountBelowTwo_UnknownRoleInitializedBytes + 4);
    short memberIds[8];
    short qualifiedCount = 0;
    int group = qualifiedCount;
    while (group < (int)(((unsigned)(unsigned char)groupState[1] << 26) >> 30)) {
        int copyCount = 8;
        unsigned short *destination = (unsigned short *)memberIds;
        unsigned short *source = (unsigned short *)CombatCollectMembersFromRandomQualifiedGroupByModeField_UnknownRoleInitializedBytes;
        do {
            *destination = *source;
            ++destination;
            ++source;
            --copyCount;
        } while (copyCount != 0);
        int count = Combat_CollectEligibleIndicesInEnemyGroup(*self, memberIds, 8,
                                        (unsigned char)group, 1);
        if (count > 0) {
            short eligibleCount = 0;
            for (int i = 0; i < count; ++i) {
                char *combatant = _Z16GetCombatantByIDii((int)*self, memberIds[i]);
                if (combatant) {
                    char *object = *(char **)(combatant + 0x138);
                    if (*(unsigned short *)(object + 0xc) < 0x3e7 &&
                        ((*(int *)(object + 0x58) << 23) >> 29) < 2)
                        ++eligibleCount;
                }
            }
            if (eligibleCount > 0) {
                groupCandidates[qualifiedCount++] = (short)group;
            }
        }
        ++group;
    }

    if (qualifiedCount <= 0)
        return 0;
    int selectedIndex = _Z13NextRandomMaxP6Randomi(*self, qualifiedCount);
    short selectedGroup = groupCandidates[selectedIndex];
    *countOut = Combat_CollectEligibleIndicesInEnemyGroup(*self, output, 8, selectedGroup, 1);
    return 1;
}
