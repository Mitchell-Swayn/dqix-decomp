#include <globaldefs.h>
ARM
extern "C" char *BattleMenu_FindPartyCommandRecord(char *records, int index);
extern "C" int BattleHud_ClassifyHealthRatio(void *record);
// Original: arm9/ov000 @ 0x02174E34; symbol: func_ov000_02174e34; size: 0x1C.
extern "C" int GameState_ClassifyIndexedRecord(char *records, int index) {
    char *record = BattleMenu_FindPartyCommandRecord(records, index);
    return record ? BattleHud_ClassifyHealthRatio(record) : -1;
}
