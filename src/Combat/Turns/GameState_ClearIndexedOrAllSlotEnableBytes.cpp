#include <globaldefs.h>
ARM
extern "C" char *BattleMenu_FindPartyCommandRecord(char *, int);
// Original: arm9/ov000 @ 0x021816E8; symbol: func_ov000_021816e8; size: 0x54.
// Clears record byte 0x445 for one indexed slot, or all four slots when the index is negative.
extern "C" void GameState_ClearIndexedOrAllSlotEnableBytes(char *obj, int index) {
    if (index < 0) {
        for (int i = 0; i < 4; ++i) {
            char *record = BattleMenu_FindPartyCommandRecord(obj, i);
            if (record != 0) *(unsigned char *)(record + 0x445) = 0;
        }
    } else {
        char *record = BattleMenu_FindPartyCommandRecord(obj, index);
        if (record != 0) *(unsigned char *)(record + 0x445) = 0;
    }
}
