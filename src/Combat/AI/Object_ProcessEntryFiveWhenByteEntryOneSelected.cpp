#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void *, int);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void *, int);
// Original: arm9/ov024 @ 0x021FC254; symbol: func_ov024_021fc254; size: 0x28.
extern "C" void Object_ProcessEntryFiveWhenByteEntryOneSelected(void *object) {
    if (BattleAI_SelectEnabledActionPolicyEntry(object, 1))
        BattleAI_ScoreHostileAilmentAndDebuffTargets(object, 5);
}
