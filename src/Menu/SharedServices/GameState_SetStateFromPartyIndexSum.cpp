#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" short SumIndexedValuesAcrossPresentPartyIds(void *, int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x02168074; symbol: func_ov004_02168074; size: 0x44.
extern "C" int GameState_SetStateFromPartyIndexSum(void *state) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    void *indexList = GameState_GetIndexList(gameState);
    short sum = SumIndexedValuesAcrossPresentPartyIds(indexList, 0x5617);
    if (sum > 0) Menu_QueueScriptEntry(state, 0x78);
    else Menu_QueueScriptEntry(state, 0x97);
    return 0;
}
