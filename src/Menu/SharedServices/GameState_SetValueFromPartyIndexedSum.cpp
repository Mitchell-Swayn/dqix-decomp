#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetIndexList(void *state);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(void *owner, int index);
extern "C" void Menu_QueueScriptEntry(void *state, unsigned value);

// Original: arm9/ov004 @ 0x02167E28; symbol: func_ov004_02167e28; size: 0x44.
extern "C" int GameState_SetValueFromPartyIndexedSum(void *state) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    void *indexList = GameState_GetIndexList(gameState);
    short total = SumIndexedValuesAcrossPresentPartyIds(indexList, 0x5617);
    if (total > 0) Menu_QueueScriptEntry(state, 0x14);
    else Menu_QueueScriptEntry(state, 3);
    return 0;
}
