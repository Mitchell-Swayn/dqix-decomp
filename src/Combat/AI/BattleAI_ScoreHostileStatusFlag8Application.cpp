#include <globaldefs.h>
ARM
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void *, int);
// Original: arm9/ov024 @ 0x021FC368; symbol: func_ov024_021fc368; size: 0x10.
extern "C" void BattleAI_ScoreHostileStatusFlag8Application(void *p) {
    BattleAI_ScoreHostileAilmentAndDebuffTargets(p, 3);
}
