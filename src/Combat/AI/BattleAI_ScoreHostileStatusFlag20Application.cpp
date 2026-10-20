#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void *object, int index);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void *object, int value);
// Original: arm9/ov024 @ 0x021FC28C; symbol: func_ov024_021fc28c; size: 0x28.
extern "C" void BattleAI_ScoreHostileStatusFlag20Application(void *object) {
    if (BattleAI_SelectEnabledActionPolicyEntry(object, 1) != 0)
        BattleAI_ScoreHostileAilmentAndDebuffTargets(object, 7);
}
