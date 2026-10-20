#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_FindPartyCommandRecord(void*, int);
// Original: arm9/ov000 @ 0x02181694; symbol: func_ov000_02181694; size: 0x54.
extern "C" void GameState_SetReadyFlagOnSlots(void* owner, int index) {
    if (index < 0) {
        for (int i = 0; i < 4; ++i) {
            unsigned char* record = (unsigned char*)BattleMenu_FindPartyCommandRecord(owner, i);
            if (record) record[0x445] = 1;
        }
    } else {
        unsigned char* record = (unsigned char*)BattleMenu_FindPartyCommandRecord(owner, index);
        if (record) record[0x445] = 1;
    }
}
