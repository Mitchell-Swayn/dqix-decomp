#include <globaldefs.h>
ARM
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(int, int, int, int);
// Original: arm9/ov024 @ 0x021FC27C; symbol: func_ov024_021fc27c; size: 0x10.
extern "C" void BattleAI_ScorePartyStatusFlag8Removal(int a0, int a1, int a2, int a3) {
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(a0, 3, a2, a3);
}
