#include <globaldefs.h>
ARM
extern "C" char *BattleMenu_FindPartyCommandRecord(char *p, int id);
// Original: arm9/ov000 @ 0x02174E1C; symbol: func_ov000_02174e1c; size: 0x18.
extern "C" char *BattleMenu_GetPartyNameTextSprite(char *p, int id) {
    char *record = BattleMenu_FindPartyCommandRecord(p, id);
    return record ? record + 0x68 : 0;
}
