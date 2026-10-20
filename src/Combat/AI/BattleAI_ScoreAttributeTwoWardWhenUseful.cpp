#include <globaldefs.h>
ARM
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(void *, int);
extern "C" void BattleAI_ScorePartyStatusRemovalAndBuffTargets(void *, int);
// Original: arm9/ov024 @ 0x021FCB24; symbol: Object_ApplyMode0x0FWhenByteField70SetAndEntry11Nonzero; size: 0x34.
// Applies mode 15 only when object byte +0x70 and selected entry 11 are nonzero.
extern "C" void BattleAI_ScoreAttributeTwoWardWhenUseful(unsigned char *state) {
    if (state[0x70] == 0)
        return;
    if (BattleAI_SelectEnabledActionPolicyEntry(state, 0xb) == 0)
        return;
    BattleAI_ScorePartyStatusRemovalAndBuffTargets(state, 0xf);
}
