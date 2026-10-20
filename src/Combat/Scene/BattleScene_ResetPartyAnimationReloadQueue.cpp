#include <globaldefs.h>
ARM

extern "C" void BattleScene_InitializePartyAnimationReloadRecord(void *record);

// Original: arm9/ov000 @ 0x02168230; symbol: func_ov000_02168230; size: 0x38.
extern "C" void BattleScene_ResetPartyAnimationReloadQueue(unsigned char *state) {
    state[0x77ee] = 0;
    for (int i = 0; i < 4; i++) {
        BattleScene_InitializePartyAnimationReloadRecord(state + 0x77d6 + i * 6);
    }
}
