#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void *, int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void *, int);
// Original: arm9/ov024 @ 0x021FC6DC; symbol: World_ApplySelectedEntryThresholdAction; size: 0x70.
// Requires nonzero selections for entries 2 and 5, validates the signed index in the referenced object (1..5), checks indexed thresholds 0x5a and 0x7d, stores the accepted value at state+0x16c, and runs selector 0xd.
extern "C" void World_ApplySelectedEntryThresholdAction(unsigned char *state) {
    if (!BattleAI_SelectEnabledActionPolicyEntry(state, 2))
        return;
    if (!BattleAI_SelectEnabledActionPolicyEntry(state, 5))
        return;
    int index = *(signed short *)((unsigned char *)*(void **)(state + 0x64c) + 0x30);
    if (index <= 0 || index > 5)
        return;
    unsigned char *record = state + index * 4;
    if (*(int *)(record + 0x154) < 0x5a)
        return;
    int value = *(int *)(record + 0x13c);
    if (value < 0x7d)
        return;
    *(int *)(state + 0x16c) = value;
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(state, 0xd);
}
