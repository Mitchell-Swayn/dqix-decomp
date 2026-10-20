#include <globaldefs.h>
extern "C" void* BattleAI_SelectEnabledActionPolicyEntry(void*, unsigned);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*, unsigned);
// Original: arm9/ov024 @ 0x021FC698; symbol: func_ov024_021fc698; size: 0x34.
extern "C" ARM void Ov024_UpdateSelectedEntry(void* object) {
    if (!*((unsigned char*)object + 0x71)) return;
    if (!BattleAI_SelectEnabledActionPolicyEntry(object, 12)) return;
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(object, 11);
}
