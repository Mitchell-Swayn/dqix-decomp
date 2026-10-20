#include <globaldefs.h>
ARM
extern "C" void GameState_ComputeNextThresholdAndPartyContribution(void *a, void *b, void *c, void *d, void *e);
extern "C" void PopulateOwnerThresholdSlotsAndResourceText(void *state, int value);
extern "C" void MiniMedalMenu_ExchangeMedalsThroughNextReward(void *state);
extern "C" void Menu_QueueScriptEntry(void *state, unsigned value);
// Original: arm9/ov004 @ 0x02167EB0; symbol: func_ov004_02167eb0; size: 0x6C.
extern "C" int MiniMedalMenu_ExchangeAndChooseRewardOrContinue(void *state) {
    unsigned char values[0x0c];
    GameState_ComputeNextThresholdAndPartyContribution(values + 6, values + 4, values + 2, values, values + 8);
    PopulateOwnerThresholdSlotsAndResourceText(state, 0);
    MiniMedalMenu_ExchangeMedalsThroughNextReward(state);
    if (values[0]) Menu_QueueScriptEntry(state, 0x28);
    else Menu_QueueScriptEntry(state, 0x33);
    return 0;
}
