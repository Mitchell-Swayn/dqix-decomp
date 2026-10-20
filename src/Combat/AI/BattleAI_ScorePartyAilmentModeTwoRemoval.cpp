#include <globaldefs.h>
ARM
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(int, int);

// Original: arm9/ov024 @ 0x021FBEC4; symbol: func_ov024_021fbec4; size: 0x10.
extern "C" void BattleAI_ScorePartyAilmentModeTwoRemoval(int value) {
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(value, 2);
}
