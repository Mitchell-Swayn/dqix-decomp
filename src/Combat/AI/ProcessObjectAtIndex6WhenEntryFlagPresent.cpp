#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void *object, int index);
extern "C" int BattleAI_ScoreHostileAilmentAndDebuffTargets(void *object, int index);
// Original: arm9/ov024 @ 0x021FC018; symbol: func_ov024_021fc018; size: 0x28.
extern "C" int ProcessObjectAtIndex6WhenEntryFlagPresent(void *object) {
    if (BattleAI_SelectEnabledActionPolicyEntry(object, 1))
        return BattleAI_ScoreHostileAilmentAndDebuffTargets(object, 6);
}
