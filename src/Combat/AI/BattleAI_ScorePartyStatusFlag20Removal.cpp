#include <globaldefs.h>
ARM
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void *, int);
// Original: arm9/ov024 @ 0x021FC4AC; symbol: func_ov024_021fc4ac; size: 0x10.
extern "C" void BattleAI_ScorePartyStatusFlag20Removal(void *p) { BattleAI_ScorePartyStatusRemovalAndBuffTargets(p, 7); }
