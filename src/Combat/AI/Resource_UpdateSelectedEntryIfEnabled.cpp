#include <globaldefs.h>
ARM
extern "C" void* BattleAI_SelectEnabledActionPolicyEntry(void*, int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*, int);
// Original: arm9/ov024 @ 0x021FCAF0; symbol: func_ov024_021fcaf0; size: 0x34.
extern "C" void Resource_UpdateSelectedEntryIfEnabled(void* object) {
    if (*(unsigned char*)((char*)object + 0x6f) == 0) return;
    if (BattleAI_SelectEnabledActionPolicyEntry(object, 0xb) == 0) return;
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(object, 0xe);
}
