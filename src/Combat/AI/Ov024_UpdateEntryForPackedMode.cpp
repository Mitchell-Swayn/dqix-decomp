#include <globaldefs.h>
extern "C" void* BattleAI_SelectEnabledActionPolicyEntry(void*, unsigned);
extern "C" void BattleAI_ScoreHostileAilmentAndDebuffTargets(void*, unsigned);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*, unsigned);
// Original: arm9/ov024 @ 0x021FC2B4; symbol: func_ov024_021fc2b4; size: 0x6C.
extern "C" ARM void Ov024_UpdateEntryForPackedMode(void* object) {
    unsigned mode = (*(unsigned*)((char*)*(void**)((char*)object + 0x64c) + 8) << 22) >> 30;
    if (mode == 1) {
        if (BattleAI_SelectEnabledActionPolicyEntry(object, 0x10))
            BattleAI_ScoreHostileAilmentAndDebuffTargets(object, 0x16);
        return;
    }
    if (!*((unsigned char*)object + 0x6b)) return;
    if (BattleAI_SelectEnabledActionPolicyEntry(object, 0xa))
        BattleAI_ScorePartyStatusRemovalAndBuffTargets(object, 0x16);
}
