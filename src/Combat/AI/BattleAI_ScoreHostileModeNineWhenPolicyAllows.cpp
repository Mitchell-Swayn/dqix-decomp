#include <globaldefs.h>
ARM
class EntryState;
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(EntryState *, int);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void *, unsigned int);
// Original: arm9/ov024 @ 0x021FC040; symbol: Unclassified_InvokeSelector9WhenEntry4Nonzero; size: 0x28.
// Runs selector 9 on the original state only when SelectNonzeroByteEntry reports a nonzero result for index 4.
extern "C" void BattleAI_ScoreHostileModeNineWhenPolicyAllows(EntryState *p) {
    if (BattleAI_SelectEnabledActionPolicyEntry(p, 4) == 0) return;
    BattleAI_ScoreHostileAilmentAndDebuffTargets(p, 9);
}
