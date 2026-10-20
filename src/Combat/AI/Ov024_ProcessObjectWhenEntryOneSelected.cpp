#include <globaldefs.h>
ARM
extern "C" void *BattleAI_SelectEnabledActionPolicyEntry(void *object, int selector);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void *object, int mode);
// Original: arm9/ov024 @ 0x021FBED4; symbol: func_ov024_021fbed4; size: 0x28.
extern "C" void Ov024_ProcessObjectWhenEntryOneSelected(void *object) {
    if (BattleAI_SelectEnabledActionPolicyEntry(object, 1) != 0)
        BattleAI_ScoreHostileAilmentAndDebuffTargets(object, 4);
}
