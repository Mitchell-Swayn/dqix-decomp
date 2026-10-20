#include <globaldefs.h>
ARM
extern "C" void BattleAI_ScoreHealingActionTargets(void);
// Original: arm9/ov024 @ 0x021FBFF8; symbol: func_ov024_021fbff8; size: 0xC.
extern "C" void BattleAI_EvaluateHealingAction(void) {
    BattleAI_ScoreHealingActionTargets();
}
