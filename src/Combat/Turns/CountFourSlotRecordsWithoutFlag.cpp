#include <globaldefs.h>
ARM
extern "C" void *BattleMenu_FindPartyCommandRecord(void *, int);

// Original: arm9/ov000 @ 0x02175F80; symbol: func_ov000_02175f80; size: 0x48.
extern "C" int CountFourSlotRecordsWithoutFlag(void *collection) {
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        void *record = BattleMenu_FindPartyCommandRecord(collection, i);
        if (record != 0 && (*(unsigned int *)((unsigned char *)record + 0x28) & 1) == 0)
            ++count;
    }
    return count;
}
