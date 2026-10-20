#include <globaldefs.h>
ARM
extern "C" void *BattleMenu_FindPartyCommandRecord(void *, int);
// Original: arm9/ov000 @ 0x02176054; symbol: func_ov000_02176054; size: 0x38.
extern "C" void BattleMenu_UnlockPartyCommandUpdates(void *p) {
    for (int i = 0; i < 4; ++i) {
        void *record = BattleMenu_FindPartyCommandRecord(p, i);
        if (record != 0) *((unsigned char *)record + 0x43e) = 0;
    }
}
