#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void *BattleMenu_FindPartyCommandRecord(void *, unsigned);
extern "C" unsigned BattleMenu_HasUnfinishedPartyCommand(void *);
// Original: arm9/ov000 @ 0x0217FB98; symbol: func_ov000_0217fb98; size: 0x5C.
extern "C" unsigned BattleMenu_HasActivePartyCommandInput(void *owner) {
    unsigned result = 0;
    void *list = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char count = *((unsigned char *)list + 0xf7c);
    for (unsigned char index = 0; index < count; ++index) {
        unsigned char recordIndex = *((unsigned char *)list + 0xf78 + index);
        void *record = BattleMenu_FindPartyCommandRecord(owner, recordIndex);
        if (record != 0) result |= BattleMenu_HasUnfinishedPartyCommand(record);
    }
    return result;
}
