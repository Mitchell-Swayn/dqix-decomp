#include <globaldefs.h>
ARM
extern "C" void* BattleAI_SelectEnabledActionPolicyEntry(void*, unsigned);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void*, unsigned);
// Original: arm9/ov024 @ 0x021FC4C0; symbol: Object_ApplyMode0x10WhenByteField6DSetAndEntry11Nonzero; size: 0x34.
// Applies mode 16 only when object byte +0x6d and selected entry 11 are nonzero.
extern "C" void BattleAI_ScoreFlagFourWardWhenUseful(void* self) {
    if (*(unsigned char*)((char*)self + 0x6D) == 0) return;
    if (BattleAI_SelectEnabledActionPolicyEntry(self, 11) == 0) return;
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(self, 16);
}
