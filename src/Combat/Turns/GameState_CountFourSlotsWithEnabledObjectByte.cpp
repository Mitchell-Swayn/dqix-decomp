#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_FindPartyCommandRecord(void*, int);
extern "C" unsigned int BattleMenu_IsPartyPanelEnabled(void*);
// Original: arm9/ov000 @ 0x0217608C; symbol: func_ov000_0217608c; size: 0x48.
// Counts existing slot records whose byte at 0x445 is nonzero.
extern "C" int GameState_CountFourSlotsWithEnabledObjectByte(void* records) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        void* record = BattleMenu_FindPartyCommandRecord(records, i);
        if (record && BattleMenu_IsPartyPanelEnabled(record)) ++count;
    }
    return count;
}
